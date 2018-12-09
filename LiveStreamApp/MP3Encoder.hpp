//
//  MP3Encoder.hpp
//  LiveStreamApp
//
//  Created by Sihang Huang on 12/8/18.
//  Copyright © 2018 Sihang Huang. All rights reserved.
//

#ifndef MP3Encoder_hpp
#define MP3Encoder_hpp

#include <stdio.h>
#include <lame/lame.h>

class MP3Encoder {
private:
    FILE *pcmFile;
    FILE *mp3File;
    lame_t lameClient;
public:
    void Encode();
    void Destroy();
//    MP3Encoder();
//    ~MP3Encoder();
    int Init(const char *pcmFilePath, const char *mp3FilePath, int sampleRate, int channels, int bitRate);
};


#endif /* MP3Encoder_hpp */

void MP3Encoder::Encode() {
    int bufferSize = 1024 * 256;
    short* buffer = new short[bufferSize / 2];
    short* leftBuffer = new short[bufferSize / 4];
    short* rightBuffer = new short[bufferSize / 4];
    unsigned char* mp3_buffer = new unsigned char[bufferSize];
    size_t readBufferSize = 0;
    
    while((readBufferSize = fread(buffer, 2, bufferSize / 2, pcmFile)) > 0) {
        for (int i = 0; i < readBufferSize; i++) {
            if (i % 2 == 0) {
                leftBuffer[i / 2] = buffer[i];
            } else {
                rightBuffer[i / 2] = buffer[i];
            }
        }
        size_t wroteSize = lame_encode_buffer(lameClient, (short int *)leftBuffer, (short int *)rightBuffer, (int)(readBufferSize / 2), mp3_buffer, bufferSize);
        fwrite(mp3_buffer, 1, wroteSize, mp3File);
    }
    delete[] buffer;
    delete[] leftBuffer;
    delete[] rightBuffer;
    delete[] mp3_buffer;
}

int MP3Encoder::Init(const char *pcmFilePath, const char *mp3FilePath, int sampleRate, int channels, int bitRate) {
    int ret = -1;
    pcmFile = fopen(pcmFilePath, "rb");
    if(pcmFile) {
        mp3File = fopen(mp3FilePath, "wb");
        
        if(mp3File) {
            lameClient = lame_init();
            lame_set_in_samplerate(lameClient, sampleRate);
            lame_set_out_samplerate(lameClient, sampleRate);
            lame_set_num_channels(lameClient, channels);
            lame_set_brate(lameClient, bitRate / 1000);
            lame_init_params(lameClient);
            ret = 0;
        }
    }
    
    return ret;
}

void MP3Encoder::Destroy() {
    if (pcmFile) {
        fclose(pcmFile);
    }
    if (mp3File) {
        fclose(mp3File);
        lame_close(lameClient);
    }
}
