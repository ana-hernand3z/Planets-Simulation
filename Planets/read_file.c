#include "read_file.h"
/*
 * Read Enterprise 
 */
GLfloat enterprise_v[ENTERPRISE_V][3];
GLint enterprise_f[ENTERPRISE_F][3];

void read_enterprise() {
	FILE* ptr = fopen("enterprise.txt", "r");

	if (ptr == NULL) {
		printf("[-] Could not read enterprize.txt\n");
		return;
	}

	char* in = malloc(sizeof(char) * 500);
	for (int i = 0; i < ENTERPRISE_V; i++) {
		fgets(in, 500, ptr);
		sscanf_s(in, "v %f %f %f", &enterprise_v[i][0], &enterprise_v[i][1], &enterprise_v[i][2]);
	}
	int fcout = 0;
	while (fgets(in, 500, ptr) != NULL) {
		sscanf_s(in, "f %d %d %d", &enterprise_f[fcout][0], &enterprise_f[fcout][1], &enterprise_f[fcout][2]);
		fcout++;
	}

	fclose(ptr);
}

void draw_enterprise(int c) {
	for (int i = 0; i < ENTERPRISE_F; i++) {
		switch (c) {
		case 0:
			glColor3f((float)i / 1989, (float)i / 1989, (float)i / 1989);
			break;
		case 1:
			glColor3f((float)i /1989, 0, 0);
			break;
		case 2:
			glColor3f(0, (float)i / 1989, 0);
			break;
		case 3:
			glColor3f(0, 0, (float)i / 1989);
			break;
		case 4:
			glColor3f(0, (float)i / 1989, (float)i / 1989);
			break;
		case 5:
			glColor3f((float)i / 1989, (float)i / 1989, 0);
			break;
		case 6:
			glColor3f((float)i / 1989, 0, (float)i / 1989);
			break;
		}
		glBegin(GL_TRIANGLES);
		for (int j = 0; j < 3; j++) {
			glVertex3fv(enterprise_v[enterprise_f[i][j]-1]);
		}
		glEnd();
	}
}