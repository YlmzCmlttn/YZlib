#include "Video/VideoReader.h"
namespace YZlib{
    VideoReader::VideoReader(/* args */)
    {
        init();
    }
    VideoReader::VideoReader(const std::string& filename)
    {
        init();
        open(filename);
    }
    void VideoReader::init(){
        av.format_ctx = avformat_alloc_context();
        if(!av.format_ctx){
            printf("Couldn't created AVFormatContext\n");
            return;
        }
    }
    bool VideoReader::open(const std::string& filename){
        if(avformat_open_input(&av.format_ctx,filename.c_str(),NULL,NULL)!=0){
            printf("Couldn't open video file\n");
            return false;
        }
        if(avformat_find_stream_info(av.format_ctx, NULL)<0)
            return false;

        av_dump_format(av.format_ctx, 0, filename.c_str(), 0); //I don't know what is this.

        int videoStreamIndex=-1;
        for(uint i=0; i<av.format_ctx->nb_streams; i++){
            if(av.format_ctx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO) {
                videoStreamIndex=i;
                break;
            }
        }
        if(videoStreamIndex==-1){
            printf("Didn't find a video stream!\n");
            return false;
        }
        av.codec_ctx=av.format_ctx->streams[videoStreamIndex]->codec;
        av.codec=avcodec_find_decoder(av.codec_ctx->codec_id);
        if(av.codec==NULL){
            printf("Unsupported codec!\n");
            return false;
        }
        if(avcodec_open2(av.codec_ctx,av.codec,&av.optionsDict)<0){
            printf("Couldn't open codec");
            return false;
        }

        av.frame = av_frame_alloc();

    }
    VideoReader::~VideoReader()
    {
    }
    
}
#endif