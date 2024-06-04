#include "Stars.h"


float starsx[STARS];
float starsy[STARS];

void init_stars() {
	for (int i = 0; i < STARS; i++) {
		starsx[i] = RANDOM_STAR;
		starsy[i] = RANDOM_STAR;
	}
}

void draw_stars() {
	glBegin(GL_POINTS);
	glPointSize(10);
	for (int i = 0; i < STARS; i++) {
		GLfloat r = RANDOM_COLOR;
		GLfloat g = RANDOM_COLOR;
		GLfloat b = RANDOM_COLOR;
		glColor3f(r, g, b);
		glVertex3f(starsx[i], starsy[i], Z);
	}
	glEnd();
}

