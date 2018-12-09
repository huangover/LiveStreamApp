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

    void encode();
    void destroy();
//    MP3Encoder();
//    ~MP3Encoder();
//    init Init(const char *pcmFilePath, const char *mp3FilePath, int sampleRate, int channels, int bitRate);
};


#endif /* MP3Encoder_hpp */

void MP3Encoder::encode() {
    printf("lalalalala");
    
    int array[2] = {1,2};
    int *p;
    p = array;
    p = &array[0];
}
