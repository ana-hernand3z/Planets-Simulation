#ifndef __PLANET_HEADER
#define __PLANET_HEADER

#include "Global.h"

#include <stdio.h>
#include <math.h>

#define DEGREE 0.0174533
#define SUN_POSITION 0,0,0
#define Y_AXIS 0, 1, 0
#define DIAGIS 1, 1, 0
#define NEGDIS 0, 1, 1
#define RADIANS(degree) (float)degree*(M_PI/180)

#define SUN_RADIUS 5
#define RANDOM_LINE(max, min) (rand()%(max - min + 1)) + min
#define LINES 360
#define LINES_MAX_OFFSET 1
#define LINES_MIN_OFFSET 1

/*
 * Orbit type:
 * - 0 == circle
 * - 1 == elipse
 * - 2 == still
 */
typedef struct _Planet {
	int orbit_type;
	float radius;
	float speed;
	float angle;
	
	int x_rotate;
	int y_rotate;
	int z_rotate;

	float distance;

	float slices;
	float stacks;

	float r;
	float g;
	float b;
}Planet;


void draw_planets(int o, int c);
void update_planets();

void draw_sun(int c);
void draw_p1(int o);
void draw_p2(int o);
void draw_p3(int o);
void draw_p4(int o);
void draw_p5(int o);
void draw_p6(int o);
void draw_p7(int o);

void update_sun();
void update_individual_planets();

void draw_orbit(Planet p);

#endif