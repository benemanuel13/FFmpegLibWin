#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <libavcodec/avcodec.h>

#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/frame.h>
#include <libavutil/samplefmt.h>

#include "ffmpeglib.h"

//Callback Code Ready To Use------------------------------------------------------------
callback_function gCBF;

extern __declspec(dllexport) void SetCallback(callback_function aCallback)
{
    gCBF = aCallback;
}

extern __declspec(dllexport) void GetData()
{
    gCBF(0, 2);
}

bytes_callback byteC;
extern __declspec(dllexport) void SetByteCallback(bytes_callback aCallback)
{
    byteC = aCallback;
}

 extern __declspec(dllexport) void GetByteData()
 {
     char bytes[] = {10, 2, 3, 4, 5};
     byteC(bytes, 5);
 }

//---------------------------------------------------------------------------------------

extern __declspec(dllexport) int audioconvert(char* infilename, char* outfilename)
{
    return -1;
}

extern __declspec(dllexport) int videoconvert(char* infilename, char* outfilename)
{
    return -1;
}

data_callback capD;

extern __declspec(dllexport) int setcapturecallback(data_callback aCallback)
{
    capD = aCallback;

    return -1;
}

extern __declspec(dllexport) int freecapturecallback()
{
    free(capD);

    return -1;
}

extern __declspec(dllexport) int startcapture(int fmt)
{
    ProcessCapturedBytes();
    return -1;
}

extern __declspec(dllexport) int stopcapture()
{
    return -1;
}

void ProcessCapturedBytes()
{
    char bytes[] = {10, 2, 3, 4, 5};

    //Last Item Is 0= Video, 1= Audio
     capD(bytes, 5, 1);
}

extern __declspec(dllexport) int startfilecapture(char* filename)
{
    return -1;
}

extern __declspec(dllexport) int stopfilecapture()
{
    return -1;
}

extern __declspec(dllexport) int setcapturecallbackaudio(data_callback aCallback)
{
    capD = aCallback;

    return -1;
}

extern __declspec(dllexport) int freecaptureaudiocallback()
{
    free(capD);

    return -1;
}

extern __declspec(dllexport) int startcaptureaudio(char* filename)
{
    return -1;
}

extern __declspec(dllexport) int stopcaptureaudio()
{
    return -1;
}

extern __declspec(dllexport) int startfilecaptureaudio(char* filename)
{
    return -1;
}

extern __declspec(dllexport) int stopfilecaptureaudio()
{
    return -1;
}

extern __declspec(dllexport) int setcapturecallbackvideo(data_callback aCallback)
{
    capD = aCallback;

    return -1;
}

extern __declspec(dllexport) int freecapturevideocallback()
{
    free(capD);

    return -1;
}

extern __declspec(dllexport) int startcapturevideo()
{
    return -1;
}

extern __declspec(dllexport) int stopcapturevideo()
{
    return -1;
}

extern __declspec(dllexport) int startfilecapturevideo(char* filename)
{
    return -1;
}

extern __declspec(dllexport) int stopfilecapturevideo()
{
    return -1;
}