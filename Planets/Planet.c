#include "Planet.h"
/*
 *  Draw Planets
 */
//{orbit, radius, speed, angle, x_r, y_r, z_r, distance, slices, stacks, r, g, b}
Planet sun = { 2, SUN_RADIUS, 0, 0, SUN_POSITION, 0, 50, 100, RGBH(0xffff00)};
Planet p1 = { 0, .8, 2,  45, Y_AXIS, SUN_RADIUS + 5, 50, 100, RGBH(0x4f6f52)};
Planet p2 = { 0, .5, 1.8, 0, Y_AXIS, SUN_RADIUS + 5 + 2, 50, 100, RGBH(0xA60F96)};
Planet p3 = { 0, .9, 1.5, 0, Y_AXIS, SUN_RADIUS + 5 + 2 + 3, 50, 100, RGBH(0xe1c78f)};
Planet p4 = { 0, 1.2,  1, 0, Y_AXIS, SUN_RADIUS + 5 + 2 + 3 + 4, 50, 100,  RGBH(0xF8FF95)};
Planet p5 = { 0, .6,   2, 0, Y_AXIS, SUN_RADIUS + 5 + 2 + 3 + 4 + 5 ,50, 100, RGBH(0xd005B41)};
Planet p6 = { 0, 2.1,1.4, 0, Y_AXIS, SUN_RADIUS + 5 + 2 + 3 + 4 + 5 + 6, 50, 100, RGBH(0x9A3B3B) };
Planet p7 = { 9, 5, 1.4, 0, Y_AXIS,   SUN_RADIUS + 5 + 2 + 3 + 4 + 5 + 6 + 6, 50, 100, RGBH(0xFFFFFF) };

Planet m14 = {0, .4, 3, 0, Y_AXIS, 1.2 + .8, 20, 100, RGBH(0xFFA1F5)};
Planet m24 = {0, .5, 1, 0, Y_AXIS, 1.2 + 1.8, 50, 100, RGBH(0XA6FF96)};

Planet m16 = { 0, .4, 3, 0, Y_AXIS, 2.1 + .8, 50, 100, RGBH(0XC08261) };
Planet m26 = { 0, .5,  1, 0, Y_AXIS, 2.1 + 1.8, 50, 100, RGBH(0XE2C799)};

void draw_planets(int o, int c) {
	draw_sun(c);

	draw_p1(o);
	draw_p2(o);
	draw_p3(o);
	draw_p4(o);
	draw_p5(o);
	draw_p6(o);
	draw_p7(o);
}

void update_planets() {
	update_sun();
	update_individual_planets();
}

void draw_sun(int c) {
	glPushMatrix();
	glColor3f(sun.r, sun.g, sun.b);
	gluSphere(gluNewQuadric(), sun.radius, sun.slices, sun.stacks);
	if (c) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		for (int i = 0; i < LINES; i++) {
			float y = RANDOM_LINE((int)sun.radius + LINES_MAX_OFFSET, (int)sun.radius + LINES_MIN_OFFSET);
			glPushMatrix();
			glRotatef(i, 0, 0, 1);
			glBegin(GL_LINES);
			glColor4f(1, 1, 0, 1);
			glVertex3f(0, 0, 0);
			glColor4f(RGBH(0xfffa500), .5);
			glVertex3f(0, y, 0);
			glEnd();
			glPopMatrix();
		}
	}

	glPopMatrix();
}

void draw_p1(int o) {
	if (o) {
		draw_orbit(p1);
	}
	glPushMatrix();
	glRotatef(p1.angle, p1.x_rotate, p1.y_rotate, p1.z_rotate);
	glTranslatef(p1.distance, 0, 0);
	glColor3f(p1.r, p1.g, p1.b);
	gluSphere(gluNewQuadric(), p1.radius, p1.slices, p1.stacks);
	
	glPopMatrix();
}

void draw_p2 (int o) {
	if (o) {
		draw_orbit(p2);
	}

	glPushMatrix();
	glRotatef(p2.angle, p2.x_rotate, p2.y_rotate, p2.z_rotate);
	glTranslatef(p2.distance, 0, 0);
	glColor3f(p2.r, p2.g, p2.b);
	gluSphere(gluNewQuadric(), p2.radius, p2.slices, p2.stacks);
	glPopMatrix();
}

void draw_p3(int o) {
	if (o) {
		draw_orbit(p3);
	}
	glPushMatrix();
	glRotatef(p3.angle, p3.x_rotate, p3.y_rotate, p3.z_rotate);
	glTranslatef(p3.distance, 0, 0);
	glColor3f(p3.r, p3.g, p3.b);
	gluSphere(gluNewQuadric(), p3.radius, p3.slices, p3.stacks);
	glPopMatrix();

}

void draw_p4(int o) {
	if (o) {
		draw_orbit(p4);
	}
	glPushMatrix();
	glRotatef(p4.angle, p4.x_rotate, p4.y_rotate, p4.z_rotate);
	glTranslatef(p4.distance, 0, 0);
	glColor3f(p4.r, p4.g, p4.b);
	gluSphere(gluNewQuadric(), p4.radius, p4.slices, p4.stacks);

	// Moons:
	if (o) {
		draw_orbit(m14);
		draw_orbit(m24);
	}
	glPushMatrix();
	glRotatef(m14.angle, m14.x_rotate, m14.y_rotate, m14.z_rotate);
	glTranslatef(0, 0, m14.distance);
	glColor3f(m14.r, m14.g, m14.b);
	gluSphere(gluNewQuadric(), m14.radius, m14.slices, m14.stacks);
	glPopMatrix();
	glPushMatrix();
	glRotatef(m24.angle, m24.x_rotate, m24.y_rotate, m24.z_rotate);
	glTranslatef(0, 0, m24.distance);
	glColor3f(m24.r, m24.g, m24.b);
	gluSphere(gluNewQuadric(), m24.radius, m24.slices, m24.stacks);
	glPopMatrix();

	glPopMatrix();
}

void draw_p5(int o) {
	if (o) {
		draw_orbit(p5);
	}
	glPushMatrix();
	glRotatef(p5.angle, p5.x_rotate, p5.y_rotate, p5.z_rotate);
	glTranslatef(0, 0, p5.distance);
	glColor3f(p5.r, p5.g, p5.b);
	gluSphere(gluNewQuadric(), p5.radius, p5.slices, p5.stacks);
	glPopMatrix();
}

void draw_p6(int o) {
	if (o) {
		draw_orbit(p6);
	}
	glPushMatrix();
	
	glRotatef(p6.angle, p6.x_rotate, p6.y_rotate, p6.z_rotate);
	glTranslatef(0, 0, p6.distance);
	glColor3f(p6.r, p6.g, p6.b);
	gluSphere(gluNewQuadric(), p6.radius, p6.slices, p6.stacks);

	// Moons:
	if (o) {
		draw_orbit(m16);
		draw_orbit(m26);
	}
	glPushMatrix();
	glRotatef(m16.angle, m16.x_rotate, m16.y_rotate, m16.z_rotate);
	glTranslatef(0, 0, m16.distance);
	glColor3f(m16.r, m16.g, m16.b);
	gluSphere(gluNewQuadric(), m16.radius, m16.slices, m16.stacks);
	glPopMatrix();
	glPushMatrix();
	glRotatef(m26.angle, m26.x_rotate, m26.y_rotate, m26.z_rotate);
	glTranslatef(0, 0, m26.distance);
	glColor3f(m26.r, m26.g, m26.b);
	gluSphere(gluNewQuadric(), m26.radius, m26.slices, m26.stacks);
	glPopMatrix();

	glPopMatrix();
}

void draw_p7(int o) {
	if (o) {
		glBegin(GL_LINE_STRIP);
		glLineWidth(2);
		glColor3f(1, 1, 1);
		for (float i = -3.1416; i < 3.1416; i += DEGREE) {
			float y = sin(i) * ((float)p7.radius) * 7;
			float x = cos(i) * ((float)p7.orbit_type) * 7;
			glVertex3f(x, 0, y);
		}
		glEnd();
	}
	glPushMatrix();
	float x = cos(RADIANS(p7.angle)) * p7.orbit_type * 7;
	float y = sin(RADIANS(p7.angle)) * p7.radius * 7;
	glTranslatef(x, 0, y);
	glColor3f(p7.r, p7.g, p7.b);
	gluSphere(gluNewQuadric(), p6.radius, p7.slices, p7.stacks);
	glPopMatrix();
}
void update_sun() {
	sun.angle += DEGREE;
}

void update_individual_planets() {
	p1.angle += p1.speed;
	p2.angle += p2.speed;
	p3.angle += p3.speed;
	p4.angle += p4.speed;
	p5.angle += p5.speed;
	p6.angle += p6.speed;
	p7.angle -= p7.speed;

	m16.angle += m16.speed;
	m26.angle += m26.speed;

	m14.angle += m14.speed;
	m24.angle += m24.speed;
}

void draw_orbit(Planet p) {
	glBegin(GL_LINE_STRIP);
	glLineWidth(2);
	glColor3f(1, 1, 1);
	for (float i = -3.1416; i < 3.1416; i += DEGREE) {
		float y = sin(i) * ((float)p.distance);
		float x = cos(i) * ((float)p.distance);
		glVertex3f(x, 0, y);
	}
	glEnd();
}