//
//用于保存音频属性和数据
//

#ifndef FFMPEGPLAYER_FFAUDIO_H
#define FFMPEGPLAYER_FFAUDIO_H

#include "FfQueue.h"
#define STATUS_PLAYING 1
#define STATUS_STOP 2;
extern "C"{
#include "libavformat/avformat.h"
#include "libswresample/swresample.h"
};

class FfAudio {
public:
    //解码器上下文
    AVCodecContext* avCodecContext = NULL;
    //音频流角标
    int streamIndex;
    //音频流属性
    AVCodecParameters* codecpar = NULL;
    //播放状态
    int ffPlayStatus;
    //数据队列
    FfQueue* ffQueue = NULL;
    //播放线程
    pthread_t pthreadPlay;
    //存放AVPacket
    AVPacket* avPacket = NULL;
    //解码出的音频帧
    AVFrame* avFrame = NULL;
    //重采样输出数据
    uint8_t *outBuffer = NULL;
    //数据大小
    int dataSize;
public:
    FfAudio();
    ~FfAudio();

    void play();
    void resample();

};


#endif //FFMPEGPLAYER_FFAUDIO_H
