#include "Video/VideoReader.h"
extern "C"{
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}
#include "Image/Image.h"

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
        av.format_ctx_ = avformat_alloc_context();
        if(!av.format_ctx_){
            printf("Couldn't created AVFormatContext\n");
            return;
        }
    }
    bool VideoReader::open(const std::string& filename){
        if(avformat_open_input(&av.format_ctx_,filename.c_str(),NULL,NULL)!=0){
            printf("Couldn't open video file\n");
            return false;
        }
        //printf("format %s, duration %lld us, bit_rate %lld\n", av.format_ctx_->iformat->name, av.format_ctx_->duration, av.format_ctx_->bit_rate);
        if(avformat_find_stream_info(av.format_ctx_, NULL)<0){
            printf("ERROR could not get the stream info\n");
            return false;
        }
        //av_dump_format(av.format_ctx_, 0, filename.c_str(), 0); //I don't know what is this.        
        videoStreamIndex=-1;
        for(uint i=0; i<av.format_ctx_->nb_streams; i++){
            //printf("AVStream->time_base before open coded %d/%d\n", av.format_ctx_->streams[i]->time_base.num, av.format_ctx_->streams[i]->time_base.den);
            //printf("AVStream->r_frame_rate before open coded %d/%d\n", av.format_ctx_->streams[i]->r_frame_rate.num, av.format_ctx_->streams[i]->r_frame_rate.den);
            //printf("AVStream->start_time %d\n" , av.format_ctx_->streams[i]->start_time);
            //printf("AVStream->duration %d\n", av.format_ctx_->streams[i]->duration);            
            if(avcodec_find_decoder(av.format_ctx_->streams[i]->codecpar->codec_id)->type == AVMEDIA_TYPE_VIDEO) {
                videoStreamIndex=i;
                break;
            }
        }        
        if(videoStreamIndex==-1){
            printf("Didn't find a video stream!\n");
            return false;
        }
        av.codec_params_=av.format_ctx_->streams[videoStreamIndex]->codecpar;
        av.codec_=avcodec_find_decoder(av.format_ctx_->streams[videoStreamIndex]->codecpar->codec_id);
        if(av.codec_==NULL){
            printf("Unsupported codec!\n");
            return false;
        }
        av.codec_ctx_ = avcodec_alloc_context3(av.codec_);
        //ERRORR Handler needed;
        
        if (avcodec_parameters_to_context(av.codec_ctx_, av.codec_params_) < 0)
        {
            printf("failed to copy codec params to codec context");
            return false;
        }
        //https://github.com/leandromoreira/ffmpeg-libav-tutorial
        if(avcodec_open2(av.codec_ctx_,av.codec_,&av.optionsDict_)<0){
            printf("Couldn't open codec");
            return false;
        }
        
        av.frame_ = av_frame_alloc();
        av.packet = av_packet_alloc();
        av.frameRGB_=av_frame_alloc();
        if(av.frameRGB_==NULL)
            return false;
        
        av.numBytes_=av_image_get_buffer_size(AV_PIX_FMT_RGB24, av.codec_ctx_->width,av.codec_ctx_->height,1);

        printf("Number of Bytes%d\n",av.numBytes_);
        av.buffer=(uint8_t *)av_malloc(av.numBytes_*sizeof(uint8_t));       

        return true;
    }

    void VideoReader::operator >>(Image& img){
        img = read();
    }
    Image VideoReader::read(){
        struct SwsContext *sws_ctx_ = NULL;
        sws_ctx_ = sws_getContext
        (
            av.codec_ctx_->width,
            av.codec_ctx_->height,
            av.codec_ctx_->pix_fmt,
            av.codec_ctx_->width,
            av.codec_ctx_->height,
            AV_PIX_FMT_BGR24,
            SWS_BILINEAR,
            NULL,
            NULL,
            NULL
        );
        avpicture_fill((AVPicture *)av.frameRGB_, av.buffer, AV_PIX_FMT_RGB24,
		 av.codec_ctx_->width, av.codec_ctx_->height);
        
        if(av_read_frame(av.format_ctx_, av.packet)>=0){
            if(av.packet->stream_index==videoStreamIndex){
                avcodec_decode_video2(av.codec_ctx_, av.frame_, &frameFinished, av.packet);
                
                
                if(frameFinished) {
                    printf("frameFinished\n");
                // Convert the image from its native format to RGB
                    sws_scale
                    (
                        sws_ctx_,
                        (uint8_t const * const *)av.frame_->data,
                        av.frame_->linesize,
                        0,
                        av.codec_ctx_->height,
                        av.frameRGB_->data,
                        av.frameRGB_->linesize
                    );
                    Matrix_<unsigned char> data(av.codec_ctx_->height,av.frameRGB_->linesize[0]);                    
                    for (size_t i = 0; i < av.numBytes_; i++)
                    {                    
                        data[i]=av.frameRGB_->data[0][i];
                    }
                    sws_freeContext(sws_ctx_);
                    return Image((size_t)av.codec_ctx_->width,(size_t)av.codec_ctx_->height,Color_Type::RGB,std::move(data));
                }                
            }            
        }else{
            printf("Errorrr\n");
            exit(-1);
        }
        sws_freeContext(sws_ctx_);
        return Image((size_t)av.codec_ctx_->width,(size_t)av.codec_ctx_->height);
    }
    VideoReader::~VideoReader()
    {
        av_free(av.buffer);
        av_free(av.frameRGB_);
        
        // Free the YUV frame
        av_free(av.frame_);
        
        // Close the codec
        
        
        // Close the video file
        av_free_packet(av.packet);

        avcodec_close(av.codec_ctx_);
        av_dict_free(&av.optionsDict_);
        avformat_close_input(&av.format_ctx_);
    }
    
}