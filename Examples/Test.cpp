#define MATRIX_DEBUG
#define PARALLEL_MATRIX
#include<iostream>
#include<iomanip>
#include<cmath>
#include"Linear_Algebra/Matrix.h"
using namespace YZlib;
#define LOG(x) std::cout<<x<<std::endl;

Matrix_<double> ref_ret(){   
   return Matrix_<double>(10,10,50);
}
struct _cas{
   uint a;
   uint b;
   _cas()=delete;
   _cas(uint _a,uint& _b):a(_a),b(_b){
   };
};
int main()
{
   typedef Matrix_<double> Matrixd;
   Matrixd estMat(5,6);
    estMat[0]= -0.35566704795378600856281536835;
    estMat[1]= -0.0603600650108432543183845098156;
    estMat[2]= -0.0152822261836814618507496277289;
    estMat[3]= 0.344249865480678818308035715745;
    estMat[4]= 0.0763651566870882370086093260397;
    estMat[5]= 0.0346454664690241456725949831252;
    estMat[6]= 0.0123785211586495361851811836118;
    estMat[7]= 0.303323174890634872369332697417;
    estMat[8]= 0.00371651171857158030970014195304; 
    estMat[9]= 0.00115615629280392258164400498544; 
    estMat[10]= -0.294414756394538568162744240908; 
    estMat[11]= -0.00215615143206959736232875002315;
    estMat[12]= -0.0792963119161478324770087056095;
    estMat[13]= 0.0497236754133044273062935758389;
    estMat[14]= -0.102633888369659975747794078416;
    estMat[15]= -0.00292168910055001004172359202471;
    estMat[16]= 0.00168362736539884663700128442088;
    estMat[17]= -0.0106828102654445249164449904811;
    estMat[18]= 0.000598688116744810648259256247172;
    estMat[19]= -0.0307769672152994368252709733724;
    estMat[20]= 0.00184846912264584263725641921638;
    estMat[21]= 0.00485747815713569695839080253563;
    estMat[22]= 0.0015501941755100688991736435085;
    estMat[23]= -0.000966439271956418574464897641718;
    estMat[24]= -0.00184551084489901324157956619132;
    estMat[25]= 0.00691031906534820324766732468902;
    estMat[26]= -0.00247517781617614344297217954249; 
    estMat[27]= -0.0321043394141955207299332641924;
    estMat[28]= -0.00820628223313698591800946502417;
    estMat[29]= 0.000276543541170710808260041480011;


    double xL=-32.5;
    double yL=0.0;
    double zL=100.0;
    double xR=32.5;
    double yR=0.0;
    double zR=100.0;
    Matrixd estVec(6,1);
    estVec[0]=xL-(-32.5);
    estVec[1]=yL;
    estVec[2]=zL;
    estVec[3]=xR-(32.5);
    estVec[4]=yR;
    estVec[5]=zR;
    Matrixd ret(1,6);
    {
        ret = mult(estMat,estVec);    
    }
    std::cout<<(ret)<<std::endl;  
   
   return 0;
}