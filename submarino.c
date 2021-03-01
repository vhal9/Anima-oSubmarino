#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static  int horizontal = 90, vertical = 0, helice = 0, periscopio = 0, zoom = 0;
static bool aceso = false;

void init(void) {
   //define o fundo azul escuro da cor do mar
   glClearColor (0.0, 0.0, 0.2, 1.0);
   glShadeModel (GL_FLAT);
}


void DefinirLuz(){
   GLfloat luzAmbiente[4] = {0.1, 0.1, 0.1, 0.1};
   GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};
   GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0};

   GLfloat posicaoLuz0[4] = {-300.0, 500.0, 50.0, 1.0};

   GLfloat especularidade[4] = {0.5, 0.5, 0.5, 0.1};

   GLint especMaterial = 1;
 
   glMaterialfv(GL_FRONT, GL_SPECULAR,especularidade);
   glMateriali(GL_FRONT, GL_SPECULAR, especMaterial);

   glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
   glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
   glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz0);

   glEnable(GL_COLOR_MATERIAL);

   glEnable(GL_LIGHTING);

   glEnable(GL_LIGHT0);
   
   glEnable(GL_DEPTH_TEST);

}

void display(void){
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
      //definir distancia e posicao vertical e horizontal do objeto
      glTranslatef(0.0, 0.0, zoom);
      glRotatef((GLfloat) horizontal, 0, 1, 0);
      glRotatef((GLfloat) vertical, 1, 0, 0);
      //desenho do sumarino em si, transladando para o centro ser o meio do submarino
      glPushMatrix();
         glTranslatef(0.0, 0.0, -2.0);
         // submarino
         glPushMatrix();
            //meio do submarino
            glColor3f(1.0f,1.0f,1.0f);
            GLUquadricObj *quadratic = gluNewQuadric();
            gluCylinder(quadratic, 1.0, 1.0, 4, 200, 100);

            //extremo/frente
            glPushMatrix();
               glColor3f(1.0f,1.0f,1.0f);
               glutSolidSphere(1, 150, 100);
            glPopMatrix();
            //extremo/calda
            glPushMatrix();
               glColor3f(1.0f,1.0f,1.0f);
               glTranslatef(0.0, 0.0, 4.0);
               glutSolidSphere(1, 150, 100);
            glPopMatrix();

            //cabine 
            glPushMatrix();
               //define se esta aceso
               if(aceso){
                  glColor3f(0.0f,1.0f,0.0f);
               }
               else{
                  glColor3f(1.0f,1.0f,1.0f);
               }
               //definimos a esfera na posicao superior do submarino
               glTranslatef(0.0, 0.8, 1.7);
               glutSolidSphere(0.6, 150, 100);
               //inserir todo o periscopio
               //suporte do periscopio
               glPushMatrix();

                  glColor3f(1.0f,1.0f,1.0f);
                  glTranslatef(0.0, 0.8, 0.0);
                  glScalef (0.1, 1.0, 0.1);
                  glutSolidCube(1.0);
                  glRotatef(periscopio, 0.0,1.0,0.0);
               // visor do periscopio
                  glPushMatrix();
                     glColor3f(0.0f,0.0f,0.2f);
                     glTranslatef(0.0, 0.7, -1.0);
                     glScalef (0.5,0.2, 1.8);
                     glutSolidCube(2.0);

                  glPopMatrix();
               glPopMatrix();
            glPopMatrix();

            // helices do submarino
            glPushMatrix();
               //esfera que liga a helice com o submarino
               glColor3f(0.0f,1.0f,0.0f);
               glTranslatef(0.0, 0.0, 5);
               glRotatef(helice, 0.0, 0.0,1.0);
               glutSolidSphere(0.2, 100, 50);
               //helices em si, são dois cubos longos
               glPushMatrix();
                  glRotatef(90.0, 1.0, 0.0,0.0);
                  glScalef (0.2,0.1, 1.8);
                  glutSolidCube(1.0);
               glPopMatrix();
               glPushMatrix();
                  glRotatef(90.0, 0.0, 1.0,0.0);
                  glScalef (0.1,0.2, 1.8);
                  glutSolidCube(1.0);
               glPopMatrix();
            glPopMatrix();
            // inserir as janelas
            glPushMatrix();
               //define se esta aceso
               if(aceso){
                  glColor3f(0.0f,1.0f,0.0f);
               }
               else{
                  glColor3f(1.0f,1.0f,1.0f);
               }
               //define esferas e suas posições
               glPushMatrix();
                  glTranslatef(0.7, 0.0, 1.0);
                  glutSolidSphere(0.5, 150, 100);
               glPopMatrix();
               glPushMatrix();
                  glTranslatef(0.7, 0.0, 2.0);
                  glutSolidSphere(0.5, 150, 100);
               glPopMatrix();
               glPushMatrix();
                  glTranslatef(0.7, 0.0, 3.0);
                  glutSolidSphere(0.5, 150, 100);
               glPopMatrix();
               glPushMatrix();
                  glTranslatef(-0.7, 0.0, 1.0);
                  glutSolidSphere(0.5, 150, 100);
               glPopMatrix();
               glPushMatrix();
                  glTranslatef(-0.7, 0.0, 2.0);
                  glutSolidSphere(0.5, 150, 100);
               glPopMatrix();
               glPushMatrix();
                  glTranslatef(-0.7, 0.0, 3.0);
                  glutSolidSphere(0.5, 150, 100);
               glPopMatrix();
            glPopMatrix();

         glPopMatrix();
      glPopMatrix();
   glPopMatrix();
   
   

   glutSwapBuffers();
}

void reshape (int w, int h){
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   gluPerspective(100.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

void MouseOptions(int button, int state, int x, int y){
   //inserir 
   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
      aceso = !(aceso);
   }

   glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y){
   switch (key) {
      case 'd':
         horizontal = (horizontal - 5) % 360;
         glutPostRedisplay();
         break;
      case 'a':
         horizontal = (horizontal + 5) % 360;
         glutPostRedisplay();
         break;
      case 'w':
         vertical = (vertical + 5) % 360;
         glutPostRedisplay();
         break;
      case 's':
         vertical = (vertical - 5) % 360;
         glutPostRedisplay();
         break;
      case 'h':
         helice = (helice - 20) % 360;
         glutPostRedisplay();
         break;
      case 'H':
         helice = (helice + 20) % 360;
         glutPostRedisplay();
         break;
      case 'p':
         periscopio = (periscopio - 5) % 360;
         glutPostRedisplay();
         break; 
      case 'P':
         periscopio = (periscopio + 5) % 360;
         glutPostRedisplay();
         break;
      case 'l':
         periscopio = (periscopio + 5) % 360;
         helice = (helice - 20) % 360;
         horizontal = (horizontal + 5) % 360;
         glutPostRedisplay();
         break;
      case '+':
         if(zoom < 0){
            zoom += 1;
         }
         glutPostRedisplay();
         break;
      case '-':
         if(zoom > -10){
            zoom -= 1;
         }
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   DefinirLuz();
   glutMouseFunc(MouseOptions);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
   return 0;
}