#define MATRIX_DEBUG
#define PARALLEL_MATRIX
#include<iostream>
#include<iomanip>
#include<cmath>
#include"Linear_Algebra/Matrix.h"
#include"Image/Image.h"
#include"GUI/Window.h"
#include "Core/Timer.h"
#include "unistd.h"
using namespace YZlib;
#define LOG(x) std::cout<<x<<std::endl;
std::pair<double,std::pair<Matrixd,double>> propogate(Matrixd &w, double &b, Matrixd &X,Matrixd &Y);

void model(Matrixd &X_train,Matrixd &Y_train,Matrixd &X_test,Matrixd &Y_test,const uint& num_iteration,const double& learning_rate,const bool print);
Matrixd predict(Matrixd &w,double &b,Matrixd &X);
std::pair<Matrixd,double> optimize(Matrixd &w, double &b, Matrixd &X,Matrixd &Y,const uint& num_iteration,const double& learning_rate,const bool print);
void load_frame(Image_& frame,std::string filename,int _frame_number){
    std::string path = std::string("../cat_or_not/")+filename;
    std::ostringstream oss;
    oss <<_frame_number;
    path = path + oss.str() + std::string(".png");
    LOG(path);
    frame = imread(path);
    std::cout<<path<<std::endl;
}
int main(void)
{

    // Image frame;
    // Matrixd X_train(64*64*3,209);   
    // Matrixd X_train2(64*64*3,209);   
    // Matrixd Y_train(1,209);
    // Matrixd X_test(64*64*3,50); 
    // Matrixd Y_test(1,50);
    // for(uint j=0;j<137;j++){
    //     load_frame(frame,"cat_",j);
    //     usleep(1);
    //     Y_train(0,j)=0;
    //     for(uint i=0;i<uint(frame.getSize())*3;i++){
    //         X_train(i,j)=(double)frame[i]/255.0;
    //     }
    // }
    // for(uint j=0;j<72;j++){
    //     load_frame(frame,"notcat_",j);
    //     usleep(1);
    //     Y_train(0,j+137)=1;
    //     for(uint i=0;i<uint(frame.getSize())*3;i++){
    //         X_train(i,j+137)=(double)frame[i]/255.0;
    //     }
    // }
    // for(uint j=0;j<17;j++){
    //     load_frame(frame,"cat_test_",j);
    //     usleep(1);
    //     Y_test(0,j)=0;
    //     for(uint i=0;i<uint(frame.getSize())*3;i++){
    //         X_test(i,j)=(double)frame[i]/255.0;
    //     }
    // }
    // for(uint j=0;j<33;j++){
    //     load_frame(frame,"notcat_test_",j);
    //     usleep(1);
    //     Y_test(0,j+17)=1;
    //     for(uint i=0;i<uint(frame.getSize())*3;i++){
    //         X_test(i,j+17)=(double)frame[i]/255.0;
    //     }
    // }
    {
        

        Matrixd a = {{1,0},{0,1}};
        Matrixd b = {{4,1},{2,2}};

        
        std::cout<<"hes"<<std::endl;
        {
            Timer t("h");
        Matrixd xx(10240,10240);
        
        xx=xx+xx;
        }

    }
    
    //model(X_train,Y_train,X_test,Y_test,2000,0.005,true);

    // Matrixd w = {{1.0},{2.0}};
    // double b = 2.0;
    // Matrixd X = {{1.0,2.0,-1.0},{3.0,4.0,-3.2}};
    // Matrixd Y = {{1.0,0.0,1.0}};
    // auto tmp = propogate(w,b,X,Y);
    // std::cout<<tmp.first<<std::endl;
    // std::cout<<tmp.second.first<<std::endl;
    // std::cout<<tmp.second.second<<std::endl;

    // auto tmp2 = optimize(w,b,X,Y,100,0.009,true);
    // std::cout<<tmp2.first<<std::endl;
    // std::cout<<tmp2.second<<std::endl;


    // Matrixd w2 = {{0.1124579},{0.23106775}};
    // double b2 = -0.3;
    // Matrixd X2 = {{1.0,-1.1,-3.2},{1.2,2.0,0.1}};
    // std::cout<<predict(w2,b2,X2)<<std::endl;

    return 0;
}
void model(Matrixd &X_train,Matrixd &Y_train,Matrixd &X_test,Matrixd &Y_test,const uint& num_iteration,const double& learning_rate,const bool print){
    Matrixd w(X_train.rows(),1);
    w.fill(0);
    double b = 0.0;
    auto ret = optimize(w,b,X_train,Y_train,num_iteration,learning_rate,print);
    auto Y_prediction_test = predict(ret.first, ret.second, X_test);
    auto Y_prediction_train = predict(ret.first, ret.second, X_train);

    std::cout<<"train accuracy: "<<(100 - mean(abs(Y_prediction_train - Y_train)) * 100)<<std::endl;
    std::cout<<"test accuracy: "<<(100 - mean(abs(Y_prediction_test - Y_test)) * 100)<<std::endl;

}
Matrixd predict(Matrixd &w,double &b,Matrixd &X){
    auto m = X.cols();
    Matrixd Y_prediction(1,m);
    //
    auto A = sigmoid(mult(w.transpose(),X)+b);
    for(uint i=0;i<A.cols();i++){
        if(A.get(i)>0.5){
            Y_prediction[i]=1;
        }else{
            Y_prediction[i]=0;
        }
    }
    return Y_prediction;
}
std::pair<Matrixd,double> optimize(Matrixd &w, double &b, Matrixd &X,Matrixd &Y,const uint& num_iteration,const double& learning_rate,const bool print){
    std::vector<Matrixd> costs;
    std::pair<Matrixd,double> ret_;
    for (uint i=0; i<num_iteration;i++){
        auto ret = propogate(w,b,X,Y);
        w = w - learning_rate*ret.second.first;
        b = b - learning_rate*ret.second.second;
        if(i%100==0){
            costs.push_back(ret.first);
            if(print){
                std::cout<<"Cost after iteration "<<i<<": "<<ret.first<<std::endl;
            }
        }
    }
    ret_.first=w;
    ret_.second=b;
    return ret_;
}
std::pair<double,std::pair<Matrixd,double>> propogate(Matrixd &w, double &b, Matrixd &X,Matrixd &Y){
    std::pair<double,std::pair<Matrixd,double>> ret;
    auto m = X.cols();
    auto tmp = mult(w.transpose(),X);
    
    auto A = sigmoid(tmp+b);    
    ret.first = sum(-1.0*(mult(Y,log(A).transpose())+mult((1.0-Y),log(1.0-A).transpose())))/m;
    ret.second.first = mult(X,(A-Y).transpose())/m;
    ret.second.second = sum(A-Y)/m;
    return ret;
}
