/////////////////////////////////////////////////////         
// Official Name: Benjamin Elliott Canfield
// E-mail: becanfie@syr.edu
// Assignment: Assignment 2
// Envrionment/Compiler: Visual Studio Community 2022
// Date Submitted: 27 February, 2023
// Refrences: None
// Interactions: Press g to enter the menu
//               press the key next to each name to select
//               click the box to select
//               right click the plate to view extra options
///////////////////////////////////////////////////// 

#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;


static int menuWindow, plateWindow; 
static float plateColor[3] = {0.69, 0.87, 0.75};
int degree = 0;
int radio;
int cont = 0;
bool check1, check2, check3, check4, check5, fail;
static long font = (long)GLUT_BITMAP_TIMES_ROMAN_24;
int checkCount = 0;
static int M = 10;
int plateShape = 50;


void writeMenuLabel(void *font, const char *string)
{
    const char* c;
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void drawSquareBoxes(void)
{
    //check box one
    glColor3f(0, 0, 0);
    glRasterPos3f(50, 482, 0);
    writeMenuLabel((void*)font, "French Toast (f)");

    glPushMatrix();
    glLineWidth(4);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(310, 475, 0.0);
    glVertex3f(360, 475, 0.0);
    glVertex3f(360, 425, 0.0);
    glVertex3f(310, 425, 0.0);
    glEnd();
    glPopMatrix();

    //check box two
    glColor3f(0, 0, 0);
    glRasterPos3f(50, 385, 0);
    writeMenuLabel((void*)font, "Eggs (e)");

    glPushMatrix();
    glTranslatef(0, -100, 0);
    glLineWidth(4);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(310, 475, 0.0);
    glVertex3f(360, 475, 0.0);
    glVertex3f(360, 425, 0.0);
    glVertex3f(310, 425, 0.0);
    glEnd();
    glPopMatrix();

    //check box three
    glColor3f(0, 0, 0);
    glRasterPos3f(50, 285, 0);
    writeMenuLabel((void*)font, "Waffle (w)");

    glPushMatrix();
    glTranslatef(0, -200, 0);
    glLineWidth(4);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(310, 475, 0.0);
    glVertex3f(360, 475, 0.0);
    glVertex3f(360, 425, 0.0);
    glVertex3f(310, 425, 0.0);
    glEnd();
    glPopMatrix();

    //check box four
    glColor3f(0, 0, 0);
    glRasterPos3f(50, 185, 0);
    writeMenuLabel((void*)font, "Pancakes (p)");

    glPushMatrix();
    glTranslatef(0, -300, 0);
    glLineWidth(4);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(310, 475, 0.0);
    glVertex3f(360, 475, 0.0);
    glVertex3f(360, 425, 0.0);
    glVertex3f(310, 425, 0.0);
    glEnd();
    glPopMatrix();

    //check box five
    glColor3f(0, 0, 0);
    glRasterPos3f(50, 85, 0);
    writeMenuLabel((void*)font, "Cereal (c)");

    glPushMatrix();
    glTranslatef(0, -400, 0);
    glLineWidth(4);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(310, 475, 0.0);
    glVertex3f(360, 475, 0.0);
    glVertex3f(360, 425, 0.0);
    glVertex3f(310, 425, 0.0);
    glEnd();
    glPopMatrix();
}

void drawCircles(void)
{
    int i;
    float t = 0;
    int x = 75;
    int y = 450;
    int r = 25;
    int numVert = 50;
    
    glColor3f(0, 0, 0);
    glLineWidth(2);

    // circle 1
    glRasterPos3f(300, 482, 0);
    writeMenuLabel((void*)font, "Bacon (b)");
 
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVert; ++i)
    {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVert;
    }
    glEnd();
    glPopMatrix();


    // circle 2
    glRasterPos3f(300, 382, 0);
    writeMenuLabel((void*)font, "Toast (t)");

    glPushMatrix();
    glTranslatef(0, -100, 0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVert; ++i)
    {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVert;
    }
    glEnd();
    glPopMatrix();


    // circle 3
    glRasterPos3f(300, 282, 0);
    writeMenuLabel((void*)font, "Hashbrowns (h)");

    glPushMatrix();
    glTranslatef(0, -200, 0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVert; ++i)
    {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVert;
    }
    glEnd();
    glPopMatrix();


    // circle 4
    glRasterPos3f(300, 182, 0);
    writeMenuLabel((void*)font, "Sausage (s)");

    glPushMatrix();
    glTranslatef(0, -300, 0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVert; ++i)
    {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVert;
    }
    glEnd();
    glPopMatrix();


    // circle 5
    glRasterPos3f(300, 82, 0);
    writeMenuLabel((void*)font, "Orange (o)");

    glPushMatrix();
    glTranslatef(0, -400, 0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVert; ++i)
    {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVert;
    }
    glEnd();
    glPopMatrix();
}

void drawRadio(void)
{
    int i;
    float t = 0;
    int x = 75;
    int y = 450;
    int r = 22;
    int numVert = 25;

    glColor3f(0, 0, 0);
    

    // radio 1
    if (radio == 1)
    {
        glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();
    }
    
    
    //radio 2
    if (radio == 2)
    {
        glPushMatrix();
        glTranslatef(0, -100, 0);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();
    }

    //radio 3
    if (radio == 3)
    {
        glPushMatrix();
        glTranslatef(0, -200, 0);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();
    }

    //radio 4
    if (radio == 4)
    {
        glPushMatrix();
        glTranslatef(0, -300, 0);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();
    }

    //radio 5
    if (radio == 5)
    {
        glPushMatrix();
        glTranslatef(0, -400, 0);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();
    }

}

void drawCheckMarks(void)
{
    glColor3f(0.0, 1.0, 0.0);

    bool checkList[5] = {check1, check2, check3, check4, check5};
    checkCount = 0;
    for (int i = 0; i < 5; i++)
    {
        if (checkList[i])
        {
            checkCount += 1;

            if (checkCount >= 3)
            {
                fail = true;
            }
            else
                fail = false;
        }
    }
    //printf("%d\n", checkCount);
    //printf("fail: %d\n", fail);
    //printf("%d\n", checkCount);

    // check mark 1
    if (check1) 
    {
        glPushMatrix();
        glBegin(GL_LINES);
        glVertex3f(305, 465, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(370, 495, 0);
        glEnd();
        glPopMatrix();
    }
    //check mark 2
    if(check2)
    {
        glPushMatrix();
        glTranslatef(0, -100, 0);
        glBegin(GL_LINES);
        glVertex3f(305, 465, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(370, 495, 0);
        glEnd();
        glPopMatrix();
    }

    //check mark 3
    if (check3)
    {
        glPushMatrix();
        glTranslatef(0, -200, 0);
        glBegin(GL_LINES);
        glVertex3f(305, 465, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(370, 495, 0);
        glEnd();
        glPopMatrix();
    }
    
    // check mark 4
    if (check4)
    {
        glPushMatrix();
        glTranslatef(0, -300, 0);
        glBegin(GL_LINES);
        glVertex3f(305, 465, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(370, 495, 0);
        glEnd();
        glPopMatrix();
    }

    // check mark 5
    if (check5)
    {
        glPushMatrix();
        glTranslatef(0, -400, 0);
        glBegin(GL_LINES);
        glVertex3f(305, 465, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(335, 435, 0);
        glVertex3f(370, 495, 0);
        glEnd();
        glPopMatrix();
    }

}

void welcomePage(void)
{
    glColor3f(0, 0, 0);
    glRasterPos3f(90, 250, 0);
    writeMenuLabel((void*)font, "Welcome To Ben's Diner ");
    glRasterPos3f(5, 200, 0);
    writeMenuLabel((void*)font, "Pick Your Breakfast and Three Sides (one meat)");
    glRasterPos3f(120, 150, 0);
    writeMenuLabel((void*)font, "Press g to Continue");

}


void drawSceneMenuWindow(void)
{
   glutSetWindow(menuWindow);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   if (cont == 0) 
   {
       welcomePage();
   }
       

   if (cont == 1)
   {
       drawSquareBoxes();
       drawCheckMarks();
       drawRadio();
       drawCircles();
   }
   glFlush();
}


void drawPlate(void)
{

    int i;
    int x = 250;
    int y = 250;
    int r = 250;
    int numVert = plateShape;
    float t = 0;
    
    glPushMatrix();
    
    glTranslatef(250, 250, 0);
    glRotatef(degree, 0, 0, 1);
    glTranslatef(-250, -250, 0);
   
    glPushMatrix();
    glTranslatef(0, 0, -10);
    glColor3fv(plateColor);
    glLineWidth(3);
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0; i < numVert; ++i)
    {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVert;
    }
    glEnd();
    glColor3f(0.49, 0.67, 0.55);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVert; ++i)
    {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVert;
    }
    glEnd();
    glPopMatrix();
    
    glPopMatrix();
}



void drawMainCourse(void)
{
    glPushMatrix();
    glTranslatef(250, 250, 0);
    glRotatef(degree, 0, 0, 1);
    glTranslatef(-250, -250, 0);



    // French Toast
    if (radio == 1)
    {
        glPushMatrix();

        glTranslatef(-80, 0, 0);

        glColor3f(1.0, 0.85, 0.6);
        glBegin(GL_POLYGON);
        glVertex3f(150, 400, 0);
        glVertex3f(350, 400, 0);
        glVertex3f(350, 100, 0);
        glVertex3f(150, 100, 0);
        glEnd();

        glColor3f(0.6, 0.3, 0.0);
        glLineWidth(3.0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(150, 400, 0);
        glVertex3f(350, 400, 0);
        glVertex3f(350, 100, 0);
        glVertex3f(150, 100, 0);
        glEnd();
        glPopMatrix();
    }

    // Eggs
    if (radio == 2)
    {
        int i;
        float t = 0;
        int x = 250;
        int y = 250;
        int r = 120;
        int numVert = 100;

        glColor3f(1, 1, 1);
        glLineWidth(2);
        glPushMatrix();
        
        glTranslatef(-90, 0, -9);
        
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        r = 70;
        glPushMatrix();
        glTranslatef(-30, 0, -9);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        r = 70;
        glPushMatrix();
        
        glTranslatef(-40, -50, -9);

        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        r = 70;
        glPushMatrix();
        glTranslatef(-150, -50, -9);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        r = 70;
        glPushMatrix();
        glTranslatef(-130, 60, -9);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        r = 40;
        glColor3f(1.0, 0.85, 0.0);
        glPushMatrix();
       
        glTranslatef(-50, -50, 0);

        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();
    }

    // waffle

    if (radio == 3)
    {
        glPushMatrix();

        glTranslatef(-80, 0, -9);
        
        glColor3f(0.9, 0.5, 0.2);

        glBegin(GL_QUADS); 
        glVertex3f(150, 400, 0);
        glVertex3f(350, 400, 0);
        glVertex3f(350, 100, 0);
        glVertex3f(150, 100, 0);
        glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslatef(-80, 0, 0);
        glColor3f(0.8, 0.5, 0.2);
        float x = 160;
        float y = 360;
        float width = 25;
        for (int i = 0; i < 40; i++) {
            glBegin(GL_POLYGON);
            glVertex3f(x, y + width, 0);
            glVertex3f(x + width, y + width, 0);
            glVertex3f(x + width, y, 0);
            glVertex3f(x, y, 0);
            glEnd();
            x += (width + 14);
            if (x > 350 or (x + width) > 350) {
                x = 160;
                y -= (width + 10);
            }
        }
        glEnd();
        glPopMatrix();
    }
    

    // Pancakes

    if (radio == 4)
    {
        int i;
        float t = 0;
        int x = 250;
        int y = 250;
        int r = 120;
        int numVert = 100;

        


        glColor3f(1.0, 0.85, 0.6);
        glLineWidth(2);
        glPushMatrix();

        glTranslatef(-90, 0, -9);

        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        glColor3f(0.6, 0.3, 0.0);
        glLineWidth(2);
        glPushMatrix();
        
        glTranslatef(-90, 0, -9);
        
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();


        glColor3f(1.0, 0.85, 0.6);
        glLineWidth(2);
        glPushMatrix();

        glTranslatef(-75, 30, -9);

        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        glColor3f(0.6, 0.3, 0.0);
        glLineWidth(2);
        glPushMatrix();

        glTranslatef(-75, 30, -9);

        glBegin(GL_LINE_LOOP);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-40, -60, 0);
        glColor3ub(246, 235, 97);

        glBegin(GL_QUADS);
        glVertex3f(150, 400, 0);
        glVertex3f(200, 400, 0);
        glVertex3f(200, 350, 0);
        glVertex3f(150, 350, 0);
        glEnd();

       

    }


    // Cereal
    if (radio == 5)
    {
        int i;
        float t = 0;
        int x = 250;
        int y = 250;
        int r = 120;
        int numVert = 100;




        glColor3f(.9, .9, .9);
        glLineWidth(2);
        glPushMatrix();

        glTranslatef(-90, 0, -9);

        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        glColor3f(.5, .5, .5);
        glLineWidth(7);
        glPushMatrix();

        glTranslatef(-90, 0, 0);

        glBegin(GL_LINE_LOOP);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();
    
        glPushMatrix();
        glTranslatef(100, 250, 5);
        float R = 30;

        glPointSize(1.5);
        glColor3f(1.0, 0.65, 0.3);

        glBegin(GL_POINTS);
        for (t = -5 * PI; t <= 5 * PI; t += PI / 115)
               glVertex3f(R * cos(t), t - 0.0, R * sin(t) - 0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(150, 300, 0);

        glPointSize(1.5);

        glBegin(GL_POINTS);
        for (t = -5 * PI; t <= 5 * PI; t += PI / 115)
            glVertex3f(R * cos(t), t - 0.0, R * sin(t) - 0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(230, 210, 0);

        glPointSize(1.5);

        glBegin(GL_POINTS);
        for (t = -5 * PI; t <= 5 * PI; t += PI / 115)
            glVertex3f(R * cos(t), t - 0.0, R * sin(t) - 0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(150, 190, 0);

        glPointSize(1.5);

        glBegin(GL_POINTS);
        for (t = -5 * PI; t <= 5 * PI; t += PI / 115)
            glVertex3f(R * cos(t), t - 0.0, R * sin(t) - 0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(200, 275, 0);

        glPointSize(1.5);

        glBegin(GL_POINTS);
        for (t = -5 * PI; t <= 5 * PI; t += PI / 115)
            glVertex3f(R * cos(t), t - 0.0, R * sin(t) - 0);
        glEnd();
        glPopMatrix();
    }

    
    glPopMatrix();
}

void drawSides()
{
    glPushMatrix();
    glTranslatef(250, 250, 0);
    glRotatef(degree, 0, 0, 1);
    glTranslatef(-250, -250, 0);
    
    // sausage link
    if (check4)
    {
        glColor3f(0.9, 0.8, 0.3);
        glLineWidth(3);
        
        glPushMatrix();
        glTranslatef(250, 470, -9);
        glScalef(11, 1.5, 0);
        glutSolidSphere(10, 20, 5);
        glPopMatrix();
       
        glPushMatrix();
        glTranslatef(250, 430, -9);
        glScalef(11, 1.5, 0);
        glutSolidSphere(10, 20, 5);
        glPopMatrix();
        
        
        glColor3f(0.8, 0.7, 0.3);
        glLineWidth(1);
        
        glPushMatrix();
        glTranslatef(250, 470, 0);
        glScalef(11, 1.5, 0);
        glutWireSphere(10, 20, 5);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(250, 430, 0);
        glScalef(11, 1.5, 0);
        glutWireSphere(10, 20, 5);
        glPopMatrix();
        
    }


    // orange
    if (check5)
    {
        int i;
        float t = 0;
        int x = 250;
        int y = 50;
        int r = 45;
        int numVert = 100;

        glColor3f(0.8, 0.7, 0.2);
        glPushMatrix();
        glTranslatef(0, 0, -9);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
        glPopMatrix();

        glColor3f(0.9, 0.8, 0.3);
        glLineWidth(3);
        glPushMatrix();
        glTranslatef(250, 50, 10);
        glutWireSphere(45, 10, 2);
        glPopMatrix();
    }

    // bacon
    if (check1)
    {
        glColor3f(0.6, 0.3, 0.0);
        glPushMatrix();
        glTranslatef(250, 430, -9);
        glScalef(11, 1.5, 0);
        glutSolidCube(15);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(250, 460, -9);
        glScalef(11, 1.5, 0);
        glutSolidCube(15);
        glPopMatrix();


        glColor3f(1, .8, .8);
        glPushMatrix();
        glTranslatef(250, 460, 0);
        glScalef(14, 1.5, 0);
        glutSolidCube(10);
        glPopMatrix();

        glColor3f(1, .8, .8);
        glPushMatrix();
        glTranslatef(250, 430, 0);
        glScalef(14, 1.5, 0);
        glutSolidCube(10);
        glPopMatrix();
    }



    // toast
    if (check2)
    {
        int i;

        glPushMatrix();

        glTranslatef(150, -80, -9);
        glColor3f(1.0, 0.85, 0.6);
        glBegin(GL_POLYGON);
        glVertex3f(200, 350, 0);
        glVertex3f(300, 350, 0);
        glVertex3f(300, 200, 0);
        glVertex3f(200, 200, 0);
        glEnd();

        glColor3f(0.6, 0.3, 0.0);
        glLineWidth(3.0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(200, 350, 0);
        glVertex3f(300, 350, 0);
        glVertex3f(300, 200, 0);
        glVertex3f(200, 200, 0);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glColor3f(1, 0, 0);
        glLineWidth(25);
        glTranslatef(420, 135, 0);
        glBegin(GL_LINE_STRIP);
        for (int x = 0; x <= 290; x++)
        {
            int y = x * x / 25;
            glVertex3f(x / 25, y / 25, 0);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(1, 0, 0);
        glLineWidth(25);
        glTranslatef(375, 135, 0);
        glBegin(GL_LINE_STRIP);
        for (int x = 0; x <= 290; x++)
        {
            int y = x * x / 25;
            glVertex3f(x / 25, y / 25, 0);
        }
        glEnd();
        glPopMatrix();
    }

    // hashbrowns
    if (check3)
    {
        int i;
        float t = 0;
        int x = 350;
        int y = 340;
        int r = 50;
        int numVert = 10;


        glColor3f(0.69, 0.40, 0.25);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();


        x = 380;
        y = 350;
        glColor3f(0.69, 0.40, 0.25);
        glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < numVert; ++i)
        {
            glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
            t += 2 * PI / numVert;
        }
        glEnd();
    }

    glPopMatrix();
}

void home_menu(int id)
{
    //printf("%d\n", id);
    
    if (id == 1)
        exit(0);

    if (id == 15);
    {
        radio = 0;
        check1 = false;
        check2 = false;
        check3 = false;
        check4 = false;
        check5 = false;
        checkCount = 0;
        fail = false;
    }
       

    glutSetWindow(plateWindow);
    glutPostRedisplay();
    glutSetWindow(menuWindow);
    glutPostRedisplay();
}

void color_menu(int id)
{
    if (id == 2)
    {
        plateColor[0] = 1.0; plateColor[1] = 0.0; plateColor[2] = 0.0;
    }
    if (id == 3)
    {
        plateColor[0] = 0.0; plateColor[1] = 0.0; plateColor[2] = 1.0;
    }
    if (id == 6)
    {
        plateColor[0] = 0.69; plateColor[1] = 0.87; plateColor[2] = 0.75;
    }
    if (id == 4)
    {
        plateColor[0] = 0.5; plateColor[1] = 0.5; plateColor[2] = 0.5;
    }
    if (id == 5)
    {
        plateColor[0] = 0; plateColor[1] = 0; plateColor[2] = 0;
    }

    glutPostRedisplay();
}

void rotate_menu(int id)
{
    if (id == 7)
    {
        if (degree >= 360)
            degree = 0;
        else
            degree += 90;
    }

    if (id == 8)
    {
        if (degree >= 360)
            degree = 0;
        else
            degree += 180;
    }
    glutPostRedisplay();

}

void shape_menu(int id)
{
    if (id == 9)
    {
        plateShape = 4;

    }

    if (id == 10)
    {
        plateShape = 6;
    }

    if (id == 11)
    {
        plateShape = 8;
    }

    if (id == 12)
    {
        plateShape = 50;
    } 
    glutPostRedisplay();
}


void menuMain(void)
{
    int sub_color_menu;
    sub_color_menu = glutCreateMenu(color_menu);
    glutAddMenuEntry("Red", 2);
    glutAddMenuEntry("Blue", 3);
    glutAddMenuEntry("Gray", 4);
    glutAddMenuEntry("Black", 5);
    glutAddMenuEntry("Originial", 6);

    int sub_rotate_menu;
    sub_rotate_menu = glutCreateMenu(rotate_menu);
    glutAddMenuEntry("90", 7);
    glutAddMenuEntry("180", 8);

    int sub_shape_menu;
    sub_shape_menu = glutCreateMenu(shape_menu);
    glutAddMenuEntry("Square", 9);
    glutAddMenuEntry("Hexigon", 10);
    glutAddMenuEntry("Octagon", 11);
    glutAddMenuEntry("Circle", 12);

    glutCreateMenu(home_menu);
    glutAddSubMenu("Color", sub_color_menu);
    glutAddSubMenu("Rotate", sub_rotate_menu);
    glutAddSubMenu("Shape", sub_shape_menu);
    glutAddMenuEntry("Clear Plate", 15);
    glutAddMenuEntry("Quit", 1);
    

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void drawScenePlateWindow(void)
{
   
   glutSetWindow(plateWindow);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glEnable(GL_DEPTH_TEST);
   drawPlate();
   drawMainCourse();
   drawSides();

   glFlush();
}


void setupMenuWindow(void)
{
   glClearColor(0.67, 0.84, 0.89, 0.0);
}


void setupPlateMenu(void)
{
   glClearColor(0.9, 0.9, 0.9, 0.0);
}


void resizeMenuWindow(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glOrtho(0.0, 500, 0.0, 500, -50, 100);

   glMatrixMode(GL_MODELVIEW);
}


void resizePlateWindow(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
  
   glOrtho(0.0, 500, 0.0, 500, 0, 100);
   glMatrixMode(GL_MODELVIEW);
}


void keyInput(unsigned char key, int x, int y)
{
   switch(key) 
   {
       case 27:
           exit(0);
           break;
       case 'f':
           if (radio == 1)
               radio = 0;
           else
               radio = 1;
           glutSetWindow(menuWindow);
           glutPostRedisplay(); 
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'e':
           if (radio == 2)
               radio = 0;
           else
               radio = 2;
           glutSetWindow(menuWindow);
           glutPostRedisplay(); 
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'w':
           if (radio == 3)
               radio = 0;
           else
               radio = 3;
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'p':
           if (radio == 4)
               radio = 0;
           else
               radio = 4;
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'c':
           if (radio == 5)
               radio = 0;
           else
               radio = 5;
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'g':
           cont = 1;
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'b':
           if (!check4)
           {
               if (!fail)
                   check1 = !check1;
               else if (fail && check1)
                   check1 = !check1;
           }
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 't':
           if (!fail)
               check2 = !check2;
           else if (fail && check2)
               check2 = !check2;
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'h':
           if (!fail)
               check3 = !check3;
           else if (fail && check3)
               check3 = !check3;
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 's':
           if (!check1)
           {
               if (!fail)
                   check4 = !check4;
               else if (fail && check4)
                   check4 = !check4;
           }
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       case 'o':
           if (!fail)
               check5 = !check5;
           else if (fail && check5)
               check5 = !check5;
           glutSetWindow(menuWindow);
           glutPostRedisplay();
           glutSetWindow(plateWindow);
           glutPostRedisplay();
           break;
       default:
         break;
   }
}

void menuMouseControl(int button, int state, int x, int y)
{
    int xWorld, yWorld;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        xWorld = x / 5;
        yWorld = (500 - y) / 5;
        //printf("%d, %d\n", xWorld*5, yWorld * 5);

        // radio 1
        if (xWorld >= 10 && xWorld <= 20 && yWorld >= 85 && yWorld <= 95)
        {
            if (radio == 1)
                radio = 0;
            else
                radio = 1;
        }

        //radio  2
        if (xWorld >= 10 && xWorld <= 20 && yWorld >= 65 && yWorld <= 75)
        {
            if (radio == 2)
                radio = 0;
            else
                radio = 2;
        }

        //radio 3
        if (xWorld >= 10 && xWorld <= 20 && yWorld >= 45 && yWorld <= 55)
        {
            if (radio == 3)
                radio = 0;
            else
                radio = 3;
        }

        //radio 4
        if (xWorld >= 10 && xWorld <= 20 && yWorld >= 25 && yWorld <= 35)
        {
            if (radio == 4)
                radio = 0;
            else
                radio = 4;
        }

        //radio 5
        if (xWorld >= 10 && xWorld <= 20 && yWorld >= 5 && yWorld <= 15 && !check4)
        {
            if (radio == 5)
                radio = 0;
            else
                radio = 5;
        }

        //check 1
        if (xWorld >= 60 && xWorld <= 70 && yWorld >= 85 && yWorld <= 95 && !check4)
        {
            if (!fail)
                check1 = !check1;
            else if (fail && check1)
                check1 = !check1;
        }
        //check 2
        if (xWorld >= 60 && xWorld <= 70 && yWorld >= 65 && yWorld <= 75)
        {
            if (!fail)
                check2 = !check2;
            else if (fail && check2)
                check2 = !check2;
        }

        //check 3
        if (xWorld >= 60 && xWorld <= 70 && yWorld >= 45 && yWorld <= 55)
        {
            if (!fail)
                check3 = !check3;
            else if (fail && check3)
                check3 = !check3;
        }

        //check 4
        if (xWorld >= 60 && xWorld <= 70 && yWorld >= 25 && yWorld <= 35 && !check1)
        {
            if (!fail)
                check4 = !check4;
            else if (fail && check4)
                check4 = !check4;
        }

        //check 5
        if (xWorld >= 60 && xWorld <= 70 && yWorld >= 5 && yWorld <= 15)
        {
            if (!fail)
                check5 = !check5;
            else if (fail && check5)
                check5 = !check5;
        }

        glutSetWindow(plateWindow);
        glutPostRedisplay();
        glutSetWindow(menuWindow);
        glutPostRedisplay();
    }
}


void printInteraction(void)
{
    printf("Interactions:\n");
    printf("Select one main course and up to 3 sides (only one meat can be selected)\n");
    printf("Try the keys next to food names or click the boxes/circles\n");
    printf("Right Click the plate for more options...\n");
    
}


int main(int argc, char **argv) 
{
   printInteraction();
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH);
   
   
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(0, 0);

   menuWindow = glutCreateWindow("Menu");
   
   setupMenuWindow();
   glutDisplayFunc(drawSceneMenuWindow);
   glutReshapeFunc(resizeMenuWindow);
   glutKeyboardFunc(keyInput); 
   glutMouseFunc(menuMouseControl);

   
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(500, 0);  
   plateWindow = glutCreateWindow("Plate");

   
   setupPlateMenu();
   glutDisplayFunc(drawScenePlateWindow);
   glutReshapeFunc(resizePlateWindow);
   glutKeyboardFunc(keyInput); 
   
   menuMain();

   glutMainLoop();

   return 0;   
}
