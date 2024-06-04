#include "Global.h"
#include "Stars.h"
#include "Planet.h"
#include "read_file.h"

// Ana Hernandez
//B00858520

// ---------- GLOBAL VARIABLES -----------

float speed = .25;							// moving speed

GLfloat cameraPosition[] = { 0, 15, 80};	// camera

int s = 1;									// stars on/off
int o = 1;									// orbits on/off
int c = 1;									// enterprise color

int color = 0;								// color of enterprise

// Initializing some stuff
void init() {
	time_t t;
	srand((unsigned)time(&t));

	init_stars();
	read_enterprise();
}

// Drawing function
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// set the camera position
	gluLookAt(cameraPosition[0], cameraPosition[1], cameraPosition[2],
		cameraPosition[0], cameraPosition[1]-5, cameraPosition[2]-10.0,
		0, 1, 0);

	if (s) {
		draw_stars();
	}

	draw_planets(o, c);
	
	glPushMatrix();
	glTranslatef(cameraPosition[0], cameraPosition[1]-1, cameraPosition[2]-1);
	
	draw_enterprise(color);
	glPopMatrix();

	
	glutSwapBuffers();
}

// Update function
void myIdle() {
	update_planets();
	glutPostRedisplay();
}

// Keyboard function
void keyboard(unsigned char key, int x, int y) {
	if (key == 'r') o = !o;
	if (key == 's') s = !s;
	if (key == 'c') c = !c;
	if (key == '0') color = 0;
	if (key == '1') color = 1;
	if (key == '2') color = 2;
	if (key == '3') color = 3;
	if (key == '4') color = 4;
	if (key == '5') color = 5;
	if (key == '6') color = 6;
}

//Special keyboard
void specialKeys(unsigned char key, int x, int y) {
	if (key == GLUT_KEY_UP) cameraPosition[1] += speed;
	if (key == GLUT_KEY_DOWN) cameraPosition[1] -= speed;
	if (key == GLUT_KEY_RIGHT) cameraPosition[0] += speed;
	if (key == GLUT_KEY_LEFT) cameraPosition[0] -= speed;
	if (key == GLUT_KEY_PAGE_UP) cameraPosition[2] += speed;
	if (key == GLUT_KEY_PAGE_DOWN) cameraPosition[2] -= speed;
}

// Init gl function
void initializeGL(void) {
	
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 1.0);

	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ASPECT, 0.1, 200);

	
	glMatrixMode(GL_MODELVIEW);

}

void print_instructions() {
	printf("Scene Controls\n----------------\ns:\tdraw stars\nr:\ttoggle rings\nc:\ttoggle corona\n0-6:\ttoggle color\n\n");
	printf("Camera Controls\n-----------------\nUp\tArrow:\tmove up\nDown\tArrow:\tmove down\nRight\tArrow:\tmove right\nLeft\tArrow:\tmove left\nPage\tUp:\tforwards\nPage\tDown:\tbackwards\n");
}
void main(int argc, char** argv) {
	init();
	print_instructions();
	glutInit(&argc, argv);
	/*
	 * RGB : select RGBA mode window
	 * DOUBLE : double buffered window
	 * DEPTH : Window with depth buffer
	 */
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("plAnEts");

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdle);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	initializeGL();
	glutMainLoop();
}