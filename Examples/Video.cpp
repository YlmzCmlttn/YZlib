#define PARALLEL_MATRIX
#include<iostream>
#include<iomanip>
#include<cmath>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
#include"GUI/Window.h"
#include"Video/VideoReader.h"
using namespace YZlib;
#define LOG(x) std::cout<<x<<std::endl;

bool load_frame(const std::string& filename);
int main(){
    //av_register_all();
    //load_frame("/home/cemo/YZlib/Examples/out.mp4");
    VideoReader cap("/home/cemo/CYVision/Back/Workspace/Media/Video/Test.AVI");

   auto png_image = cap.read();
    Window window;
   Window_Event e;
   window.setWindowBounds(Rectangle<int>(100,100,png_image.getWidth(),png_image.getHeight()));
   window.createWindow("Test");
   window.createRenderer();
   window.showWindow();
   bool running = true;
   while(running){    

       png_image = cap.read();
        window.RGB2Texture((void*)png_image.getData().getData(),png_image.getWidth(),png_image.getHeight(),24,png_image.getWidth()*png_image.getChannel());     
        window.render();
      auto ret = Event_Handler(e);
        if (auto c = std::get_if<char>(&ret)){
            LOG(*c);
        }else{
            running = std::get<bool>(ret);
        }
   }
    return 0;
}
bool load_frame(const std::string& filename){
    AVFormatContext* av_format_ctx = avformat_alloc_context();
    if(!av_format_ctx){
        printf("Couldn't created AVFormatContext\n");
        return false;        
    }    
    if(avformat_open_input(&av_format_ctx,filename.c_str(),NULL,NULL)!=0){
        printf("Couldn't open video file\n");
        return false;
    }
    int video_stream_index = -1;
    AVCodecParameters* av_codec_params;
    AVCodec* av_codec;
    for (int i = 0; i < av_format_ctx->nb_streams; i++)
    {
        
        auto stream = av_format_ctx->streams[i];
        av_codec_params = stream->codecpar;
        av_codec = avcodec_find_decoder(av_codec_params->codec_id);
        if(!av_codec)
            continue;
        if(av_codec_params->codec_type==AVMEDIA_TYPE_VIDEO){
            video_stream_index=i;
            break;
        }
    }
    if(video_stream_index==-1){
        printf("Couldn't find valid video stream inside file\n");
    }

    AVCodecContext* av_codec_ctx = avcodec_alloc_context3(av_codec);
    if(!av_codec_ctx){
        printf("Couldn't create AVCodecContext\n");
    }
    if(!avcodec_parameters_to_context(av_codec_ctx,av_codec_params)){
        printf("Couldn't initialize AVCodecContext\n");
    }
    if(avcodec_open2(av_codec_ctx,av_codec,NULL)<0){
        printf("Couldn't open codec\n");
    }

    avformat_close_input(&av_format_ctx);
    avformat_free_context(av_format_ctx);
    avcodec_free_context(&av_codec_ctx);
}