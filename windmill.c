#include <GL/glut.h>
#include <math.h>

float angle = 0.0f;  // Initial rotation angle of the windmill blades

int speed=1;




void drawHill() {
    glColor3f(0.0f, 0.5f, 0.0f);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    
    glVertex2f(-350.0f, -400.0f);
    glVertex2f(350.0f, -400.0f);
    glVertex2f(0.0f, -150.0f);
    
    glColor3f(0.2f,0.8f,0.0f);
    glVertex2f(-100.0f, -420.0f);
    glVertex2f(600.0f, -420.0f);
    glVertex2f(320.0f, -100.0f);
    
    glColor3f(0.0f,0.6f,0.0f);
    glVertex2f(-600.0f, -430.0f);
    glVertex2f(80.0f, -430.0f);
    glVertex2f(-320.0f, -50.0f);
    //glEnd();
    
    //glBegin(GL_TRIANGLES);
    
    //glEnd();
    glEnd();
    //glBegin(GL_TRIANGLES);
    
    glPopMatrix();
}

void drawBlades() {
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(50.0f, 90.0f);
    glVertex2f(50.0f, 60.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();
}

void drawWindmill() {
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(45.0f, -60.0f);
    glVertex2f(40.0f, -200.0f);
    glVertex2f(50.0f, -200.0f);
    glVertex2f(50.0f, -60.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(50.0f, -60.0f, 1.0f);

    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Rotate the blades around the z-axis

    for (int i = 0; i < 4; ++i) {
        glRotatef(90.0f * i, 0.0f, 0.0f, 1.0f);
        drawBlades();
    }

    glPopMatrix();
    
    glLoadIdentity();
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(-250.0f, 50.0f);
    glVertex2f(-250.0f, -150.0f);
    glVertex2f(-235.0f, -150.0f);
    glVertex2f(-245.0f, 50.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(-250.0f, 50.0f, 1.0f);

    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Rotate the blades around the z-axis

    for (int i = 0; i < 4; ++i) {
        glRotatef(90.0f * i, 0.0f, 0.0f, 1.0f);
        drawBlades();
    }

    glPopMatrix();
    
    glLoadIdentity();
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(370.0f, 100.0f);
    glVertex2f(365.0f, -200.0f);
    glVertex2f(380.0f, -200.0f);
    glVertex2f(375.0f, 100.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(370.0f, 100.0f, 1.0f);

    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Rotate the blades around the z-axis

    for (int i = 0; i < 4; ++i) {
        glRotatef(90.0f * i, 0.0f, 0.0f, 1.0f);
        drawBlades();
    }

    glPopMatrix();
}

void update(int value) {
    if(speed==1) angle += 5.0f;
    else if(speed==2) angle += 15.0f;
    else if(speed==3) angle += 25.0f;// Increment the rotation angle
    
    if (angle > 360.0f) {
        angle -= 360.0f;
    }

    glutPostRedisplay();  // Mark the current window as needing to be redisplayed
    glutTimerFunc(100, update, 0);  // Call the update function after 100 milliseconds
}




void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glBegin(GL_QUADS);
    glColor3f(0.8, 1.0, 1.0);
    glVertex2f(-400.0f, -400.0f);
    glVertex2f(400.0f, -400.0f);
    glVertex2f(400.0f, 400.0f);
    glVertex2f(-400.0f, 400.0f);
    glEnd();
    
    glTranslatef(0.0f, -0.3f, 0.0f);
    
    // Draw Hill
    
    drawHill();
    
    glPushMatrix();
    glTranslatef(0.0f, 0.9f, 0.0f);
    
    // Draw Windmill
    drawWindmill();
    
    glPopMatrix();
    
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
}
void menuFunc(int item){
	switch(item){
		case 1: speed=1;
		break;
		case 2: speed=2;
		break;
		case 3: speed=3;
		break;
	}
} 





int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL Windmill on Hill");
    glutDisplayFunc(display);
    glutCreateMenu(menuFunc);
    	glutAddMenuEntry("Slow",1);
    	glutAddMenuEntry("Medium",2);
    	glutAddMenuEntry("Fast",3);
    	glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutReshapeFunc(reshape);
    glutTimerFunc(100, update, 0);  // Start the timer to update the rotation
    glutMainLoop();
}

/*cmd to run the code in terminal: cc windmill.c -lglut -lGLU -lGL -lm
                                   ./a.out */