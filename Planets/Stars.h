#ifndef __STARS_HEADERx
#define __STARS_HEADER

#include "Global.h"
#include <stdio.h>
#include <stdlib.h>

#define RANDOM_STAR (float)(220*(rand()/(float)RAND_MAX)-110)
#define RANDOM_COLOR (GLfloat)((rand())/(GLfloat)RAND_MAX)
#define STARS 10000
#define Z -5

void init_stars();
void draw_stars();




#endif
