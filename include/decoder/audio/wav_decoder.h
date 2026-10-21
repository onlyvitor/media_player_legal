#ifndef wav_decoder

#include <iostream>
#include <stdint.h>

typedef struct RIFFChunckDescriptor{
    uint32_t chunkID;
    uint32_t chunckSize;
    char *format;
} riff_chunck_descriptor;

namespace audio {
    class WavAudio {

    };
}

#endif