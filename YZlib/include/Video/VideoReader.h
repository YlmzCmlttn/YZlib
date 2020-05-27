#ifndef YZLIB_VIDEO_VIDEOREADER_H
#define YZLIB_VIDEO_VIDEOREADER_H
#include <string>
#include "Image/Image.h"
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
namespace YZlib{
    class VideoReader
    {
    private:
        int videoStreamIndex;
        int frameFinished;
        struct AV{
            
            AVFormatContext* format_ctx_=NULL;
            AVCodecParameters* codec_params_=NULL;
            AVCodec* codec_=NULL;
            AVCodecContext* codec_ctx_=NULL;
            AVDictionary* optionsDict_=NULL;
            AVFrame* frame_=NULL;
            AVPacket *packet=NULL;
            AVFrame* frameRGB_=NULL;            
            uint numBytes_;
            uint8_t *buffer = NULL;
        }av;

    private:
        void init();

        //
                
    public:
        VideoReader(/* args */);
        VideoReader(const std::string&);

        bool open(const std::string&);
        bool close();

        void operator >> (Image&);
        

        Image read();
        ~VideoReader();
    };
}
#endif