#include <GL/glut.h>
#include <cmath>

// Room dimensions
const int roomWidth = 800;
const int roomHeight = 600;

// Player position and direction
float playerX = 400.0f;
float playerY = 300.0f;
float playerAngle = 0.0f;

// Define walls
const int numWalls = 4;
float walls[numWalls][4] = {
    {100.0f, 100.0f, 200.0f, 100.0f},  // Wall 1: (x1, y1, x2, y2)
    {200.0f, 100.0f, 200.0f, 300.0f},  // Wall 2
    {200.0f, 300.0f, 500.0f, 300.0f},  // Wall 3
    {500.0f, 300.0f, 500.0f, 100.0f}   // Wall 4
};

// Function to draw a line segment
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to render the scene
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw walls
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < numWalls; ++i) {
        drawLine(walls[i][0], walls[i][1], walls[i][2], walls[i][3]);
    }

    // Draw player
    glColor3f(1.0f, 0.0f, 0.0f); // Red player marker
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(playerX, playerY);
    glEnd();

    glutSwapBuffers();
}

// Function to handle keyboard input
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'a') {
        playerAngle -= 0.1f; // Rotate left
    }
    else if (key == 'd') {
        playerAngle += 0.1f; // Rotate right
    }
    else if (key == 'w') {
        // Move forward
        playerX += cos(playerAngle) * 5.0f;
        playerY += sin(playerAngle) * 5.0f;
    }
    else if (key == 's') {
        // Move backward
        playerX -= cos(playerAngle) * 5.0f;
        playerY -= sin(playerAngle) * 5.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(roomWidth, roomHeight);
    glutCreateWindow("Simple Ray Caster");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, roomWidth, roomHeight, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(renderScene);
    glutKeyboardFunc(handleKeypress);

    glutMainLoop();
    return 0;
}#include <GL/glut.h>
#include <cmath>

// Room dimensions
const int roomWidth = 800;
const int roomHeight = 600;

// Player position and direction
float playerX = 400.0f;
float playerY = 300.0f;
float playerAngle = 0.0f;

// Define walls
const int numWalls = 4;
float walls[numWalls][4] = {
    {100.0f, 100.0f, 200.0f, 100.0f},  // Wall 1: (x1, y1, x2, y2)
    {200.0f, 100.0f, 200.0f, 300.0f},  // Wall 2
    {200.0f, 300.0f, 500.0f, 300.0f},  // Wall 3
    {500.0f, 300.0f, 500.0f, 100.0f}   // Wall 4
};

// Function to draw a line segment
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to render the scene
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw walls
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < numWalls; ++i) {
        drawLine(walls[i][0], walls[i][1], walls[i][2], walls[i][3]);
    }

    // Draw player
    glColor3f(1.0f, 0.0f, 0.0f); // Red player marker
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(playerX, playerY);
    glEnd();

    glutSwapBuffers();
}

// Function to handle keyboard input
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'a') {
        playerAngle -= 0.1f; // Rotate left
    }
    else if (key == 'd') {
        playerAngle += 0.1f; // Rotate right
    }
    else if (key == 'w') {
        // Move forward
        playerX += cos(playerAngle) * 5.0f;
        playerY += sin(playerAngle) * 5.0f;
    }
    else if (key == 's') {
        // Move backward
        playerX -= cos(playerAngle) * 5.0f;
        playerY -= sin(playerAngle) * 5.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(roomWidth, roomHeight);
    glutCreateWindow("Simple Ray Caster");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, roomWidth, roomHeight, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(renderScene);
    glutKeyboardFunc(handleKeypress);

    glutMainLoop();
    return 0;
}