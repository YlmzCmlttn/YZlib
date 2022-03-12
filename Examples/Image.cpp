#define PARALLEL_MATRIX
#include<iostream>
#include<iomanip>
#include<cmath>

#include"Linear_Algebra/Matrix.h"
#include"Image/Png_Operations.h"
#include"Image/Image.h"
#include"Core/Timer.h"
#include"GUI/Window.h"
using namespace YZlib;
#define LOG(x) std::cout<<x<<std::endl;
int main(){
   
/*
   Timer t("t");
   Image_ png_image = imread("../1.png"); 
   imwrite("../2.jpg",png_image);
   Image_ png_image2 = imread("../2.jpg");    
   Image_ a(std::move(png_image2));
   Image_ b = std::move(a);
   imwrite("../3.jpeg",b);
   Image_ c = imread("../3.jpeg"); 
   imwrite("../4.bmp",c);
   Image_ d = imread("../4.bmp"); 
   imwrite("../5.bmp",d);
   d[0]=0;
   d.set(0,10);
   LOG((int)d[0]);
   LOG((int)d[1]);
   LOG((int)d[2]);

   LOG((int)d(0,0,0));
   LOG((int)d(0,0,1));
   LOG((int)d(0,0,2));
   */
   Image_ png_image = imread("../1.png"); 
   Window window;
   Window_Event e;
   window.setWindowBounds(Rectangle<int>(100,100,png_image.getWidth(),png_image.getHeight()));
   window.createWindow("Test");
   window.createRenderer();
   window.showWindow();
   window.RGB2Texture((void*)png_image.getData().getData(),png_image.getWidth(),png_image.getHeight(),24,png_image.getWidth()*png_image.getChannel());
     
      window.render();
   bool running = true;
   while(running){    
      auto ret = Event_Handler(e);
        if (auto c = std::get_if<char>(&ret)){
            LOG(*c);
        }else{
            running = std::get<bool>(ret);
        }
   }
   return 0;
}