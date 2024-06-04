#ifndef __GLOBAL_HEADER
#define __GLOBAL_HEADER

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 600
#define ASPECT 1200/600

#define _CRT_SECURE_NO_WARNINGS

#define RGB(R,G,B) (float)R/255.0f,(float)G/255.0f,(float)B/255.0f
#define RGBH(HEX) (HEX >> 0x10)/255.0f, (0xff&(HEX >> 0x08))/255.0f, (0xff&HEX)/255.0f

#define M_PI 3.14159265358979323846

#include <freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#endif