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
        struct AV{
            AVFormatContext* format_ctx=NULL;
            AVCodecParameters* codec_params=NULL;
            AVCodec* codec=NULL;
            AVCodecContext* codec_ctx=NULL;
            AVDictionary* optionsDict=NULL;
            AVFrame* frame=NULL;
        }av;

    private:
        void init();        
    public:
        VideoReader(/* args */);
        VideoReader(const std::string&);

        bool open(const std::string&);
        bool close();

        void operator >> (Image&);
        

        Image& read();
        ~VideoReader();
    };
}
#endif