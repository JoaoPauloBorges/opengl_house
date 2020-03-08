#include <gl/glut.h>

//GLfloat angle, fAspect;
GLfloat ASPECTO, ANGULO;
int x_ini, y_ini, bot;
int slices;
static double deg = 0.0;
GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;
#define SENS_ROT 10.0
#define SENS_OBS 10.0
constexpr auto SENS_TRANS = 10.0;
static bool fp = false;
static bool fj = false;
static double a = 0;
static double b = 0;

// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClear(GL_COLOR_BUFFER_BIT);

	/*
	   glPushMatrix();
		   glColor3f(0.9, 0.9, 0.9);
		   glBegin(GL_LINES);
		   glVertex3f(0.0, 0.0, 0.0);
		   glVertex3f(0.0, 300.0, 0.0);
		   glEnd();
	   glPopMatrix();

	   glPushMatrix();
		   glColor3f(0.9, 0.9, 0.9);
		   glBegin(GL_LINES);
		   glVertex3f(0.0, 0.0, 0.0);
		   glVertex3f(300.0, 0.0, 0.0);
		   glEnd();
	   glPopMatrix();

	   glPushMatrix();
		   glColor3f(0.9, 0.9, 0.9);
		   glBegin(GL_LINES);
		   glVertex3f(0.0, 0.0, 0.0);
		   glVertex3f(0.0, 0.0, 300.0);
		   glEnd();
	   glPopMatrix();
	   */
	   // DESENHANDO O CH�O

	glPushMatrix();
	glColor3f(0.3, 0.0, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(-10.0, -0.01, -10.0);  //DESENHAR O PONTO D
	glVertex3f(50.0, -0.01, -10.0);  // DESENHAR O PONTO B
	glVertex3f(50.0, -0.01, 50.0);  // DESENHAR O PONTO C
	glVertex3f(-10.0, -0.01, 50.0);  // DESENHAR O PONTO A
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 1
	glColor3f(0.0, 0.0, 0.0);  //LINHA D --- B
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(3.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 2
	glColor3f(0.0, 0.0, 0.0); //LINHA  B --- C
	glBegin(GL_LINES);
	glVertex3f(3.0, 0.0, 0.0);
	glVertex3f(3.0, 0.0, 3.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 3
	glColor3f(0.0, 0.0, 0.0); //LINHA  C --- A
	glBegin(GL_LINES);
	glVertex3f(3.0, 0.0, 3.0);
	glVertex3f(0.0, 0.0, 3.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 4
	glColor3f(0.0, 0.0, 0.0);  //LINHA  A --- D
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 3.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	// DESENHANDO O CH�O TOTAL - C , E , F, A , G , B

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);  // DESENHAR O PONTO A
	glVertex3f(20.0, 0.0, 0.0);  // DESENHAR O PONTO B
	glVertex3f(20.0, 0.0, 8.0);  // DESENHAR O PONTO G
	glVertex3f(8.0, 0.0, 8.0);  // DESENHAR O PONTO F
	glVertex3f(8.0, 0.0, 15.0);  // DESENHAR O PONTO E
	glVertex3f(0.0, 0.0, 15.0);  //DESENHAR O PONTO C
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 1
	glColor3f(0.0, 0.0, 0.0);  //LINHA A --- B
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 2
	glColor3f(0.0, 0.0, 0.0);  //LINHA B --- G
	glBegin(GL_LINES);
	glVertex3f(20.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, 8.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 3
	glColor3f(0.0, 0.0, 0.0);  //LINHA G --- F
	glBegin(GL_LINES);
	glVertex3f(20.0, 0.0, 8.0);
	glVertex3f(8.0, 0.0, 8.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 4
	glColor3f(0.0, 0.0, 0.0);  //LINHA F --- E
	glBegin(GL_LINES);
	glVertex3f(8.0, 0.0, 8.0);
	glVertex3f(8.0, 0.0, 15.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 5
	glColor3f(0.0, 0.0, 0.0);  //LINHA E ---
	glBegin(GL_LINES);
	glVertex3f(8.0, 0.0, 15.0);
	glVertex3f(0.0, 0.0, 15.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 6
	glColor3f(0.0, 0.0, 0.0);  //LINHA F --- B
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	// CH�O 2 ANDAR

	glPushMatrix();
	glColor3f(3.0, 3.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 10.0, 0.0);  // DESENHAR O PONTO
	glVertex3f(20.0, 10.0, 0.0);  // DESENHAR O PONTO
	glVertex3f(20.0, 10.0, 8.0);  // DESENHAR O PONTO
	glVertex3f(8.0, 10.0, 8.0);  // DESENHAR O PONTO ''
	glVertex3f(8.0, 10.0, 15.0);  // DESENHAR O PONTO
	glVertex3f(0.0, 10.0, 15.0);  // DESENHAR O PONTO
	glEnd();
	glPopMatrix();

	// DESENHANDO A PAREDE TOTAL - C A D N

	glPushMatrix();
	glColor3f(0.5, 1.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);  //DESENHAR O PONTO A
	glVertex3f(20.0, 0.0, 0.0);  // DESENHAR O PONTO B
	glVertex3f(20.0, 20.0, 0.0);  // DESENHAR O PONTO P
	glVertex3f(0.0, 20.0, 0.0);  // DESENHAR O PONTO D
	glVertex3f(0.0, 20.0, 15.0);  // DESENHAR O PONTO N
	glVertex3f(0.0, 0.0, 15.0);  // DESENHAR O PONTO C
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 6
	glColor3f(0.0, 0.0, 0.0);  //LINHA F --- B
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 6
	glColor3f(0.0, 0.0, 0.0);  //LINHA B --- P
	glBegin(GL_LINES);
	glVertex3f(20.0, 0.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 6
	glColor3f(0.0, 0.0, 0.0);  //LINHA P --- D
	glBegin(GL_LINES);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 6
	glColor3f(0.0, 0.0, 0.0);  //LINHA D --- N
	glBegin(GL_LINES);
	glVertex3f(0.0, 20.0, 0.0);
	glVertex3f(0.0, 20.0, 15.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 6
	glColor3f(0.0, 0.0, 0.0);  //LINHA N --- C
	glBegin(GL_LINES);
	glVertex3f(0.0, 20.0, 15.0);
	glVertex3f(0.0, 0.0, 15.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA 6
	glColor3f(0.0, 0.0, 0.0);  //LINHA C --- A
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 15.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	// PAREDE LATERAL - L , P , K , O , G , B

	glPushMatrix();
	glColor3f(0.8, 0.0, 1.1);
	glBegin(GL_QUADS);
	glVertex3f(20.0, 0.0, 0.0);  // DESENHAR O PONTO B
	glVertex3f(20.0, 10.0, 0.0);  // DESENHAR O PONTO P
	glVertex3f(20.0, 10.0, 8.0);  // DESENHAR O PONTO L
	glVertex3f(20.0, 0.0, 8.0);  // DESENHAR O PONTO G
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0.0, 1.1);
	glBegin(GL_QUADS);
	glVertex3f(20.0, 10.0, 3.0);  // DESENHAR O PONTO B
	glVertex3f(20.0, 20.0, 3.0);  // DESENHAR O PONTO P
	glVertex3f(20.0, 20.0, 0.0);  // DESENHAR O PONTO L
	glVertex3f(20.0, 10.0, 0.0);  // DESENHAR O PONTO G
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0.0, 1.1);
	glBegin(GL_QUADS);
	glVertex3f(20.0, 10.0, 5.0);  // DESENHAR O PONTO B
	glVertex3f(20.0, 20.0, 5.0);  // DESENHAR O PONTO P
	glVertex3f(20.0, 20.0, 8.0);  // DESENHAR O PONTO L
	glVertex3f(20.0, 10.0, 8.0);  // DESENHAR O PONTO G
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0.0, 1.1);
	glBegin(GL_QUADS);
	glVertex3f(20.0, 15.0, 3.0);  // DESENHAR O PONTO B
	glVertex3f(20.0, 20.0, 3.0);  // DESENHAR O PONTO P
	glVertex3f(20.0, 20.0, 5.0);  // DESENHAR O PONTO L
	glVertex3f(20.0, 15.0, 5.0);  // DESENHAR O PONTO G
	glEnd();
	glPopMatrix();

	// PAREDE TODA + PORTA - M , C , ... , K ,

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(8.0, 10.0, 8.0);  // DESENHAR O PONTO F'
	glVertex3f(8.0, 0.0, 8.0);  // DESENHAR O PONTO F
	glVertex3f(8.0, 0.0, 10.0);  // DESENHAR O PONTO E''
	glVertex3f(8.0, 7.0, 10.0);  // DESENHAR O PONTO E'''
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(8.0, 10.0, 15.0);  // DESENHAR O PONTO I
	glVertex3f(8.0, 10.0, 8.0);  // DESENHAR O PONTO F'
	glVertex3f(8.0, 7.0, 10.0);  // DESENHAR O PONTO E'''
	glVertex3f(8.0, 7.0, 13.0);  // DESENHAR O PONTO E''''
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(8.0, 0.0, 15.0);  // DESENHAR O PONTO E
	glVertex3f(8.0, 10.0, 15.0);  // DESENHAR O PONTO I
	glVertex3f(8.0, 7.0, 13.0);  // DESENHAR O PONTO E''''
	glVertex3f(8.0, 0.0, 13.0);  // DESENHAR O PONTO E'
	glEnd();
	glPopMatrix();

	// PAREDE EM CIMA DA PORTA

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(8.0, 10.0, 15.0);  // DESENHAR O PONTO I
	glVertex3f(8.0, 20.0, 15.0);  // DESENHAR O PONTO J
	glVertex3f(8.0, 20.0, 8.0);  //DESENHAR O PONTO F''
	glVertex3f(8.0, 10.0, 8.0);  // DESENHAR O PONTO F'
	glEnd();
	glPopMatrix();

	// PAREDE LADO 2 - C M , I , E

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 15.0);  //DESENHAR O PONTO C
	glVertex3f(0.0, 10.0, 15.0);  // DESENHAR O PONTO M
	glVertex3f(8.0, 10.0, 15.0);  // DESENHAR O PONTO I
	glVertex3f(8.0, 0.0, 15.0);  // DESENHAR O PONTO E
	glEnd();
	glPopMatrix();

	// falta as linhas

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 10.0, 15.0);  // DESENHAR O PONTO M
	glVertex3f(0.0, 20.0, 15.0);  // DESENHAR O PONTO N
	glVertex3f(2.0, 18.0, 15.0);  // DESENHAR O PONTO M'''
	glVertex3f(2.0, 14.0, 15.0);  // DESENHAR O PONTO M'
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 20.0, 15.0);  // DESENHAR O PONTO N
	glVertex3f(8.0, 20.0, 15.0);  // DESENHAR O PONTO J
	glVertex3f(6.0, 18.0, 15.0);  // DESENHAR O PONTO M''''
	glVertex3f(2.0, 18.0, 15.0);  // DESENHAR O PONTO M'''
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(8.0, 20.0, 15.0);  // DESENHAR O PONTO J
	glVertex3f(8.0, 10.0, 15.0);  // DESENHAR O PONTO I
	glVertex3f(6.0, 14.0, 15.0);  // DESENHAR O PONTO M''
	glVertex3f(6.0, 18.0, 15.0);  // DESENHAR O PONTO M''''
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(8.0, 10.0, 15.0);  // DESENHAR O PONTO I
	glVertex3f(0.0, 10.0, 15.0);  // DESENHAR O PONTO M
	glVertex3f(2.0, 14.0, 15.0);  // DESENHAR O PONTO M'
	glVertex3f(6.0, 14.0, 15.0);  // DESENHAR O PONTO M''
	glEnd();
	glPopMatrix();

	// PAREDE ABAIXO DA JANELA 2

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(8.0, 0.0, 8.0);  // DESENHAR O PONTO F
	glVertex3f(8.0, 10.0, 8.0);  // DESENHAR O PONTO F'
	glVertex3f(20.0, 10.0, 8.0);  // DESENHAR O PONTO K
	glVertex3f(20.0, 0.0, 8.0);  // DESENHAR O PONTO G
	glEnd();
	glPopMatrix();

	// JANELA 2

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(8.0, 10.0, 8.0);  // DESENHAR O PONTO F'
	glVertex3f(8.0, 20.0, 8.0);  //DESENHAR O PONTO F''
	glVertex3f(10.0, 17.0, 8.0);  // DESENHAR O PONTO T
	glVertex3f(10.0, 13.0, 8.0);  // DESENHAR O PONTO Q
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(8.0, 20.0, 8.0);  //DESENHAR O PONTO F''
	glVertex3f(20.0, 20.0, 8.0);  // DESENHAR O PONTO L
	glVertex3f(17.0, 17.0, 8.0);  // DESENHAR O PONTO S
	glVertex3f(10.0, 17.0, 8.0);  // DESENHAR O PONTO T
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 20.0, 8.0);  // DESENHAR O PONTO L
	glVertex3f(20.0, 10.0, 8.0);  // DESENHAR O PONTO K
	glVertex3f(17.0, 13.0, 8.0);  // DESENHAR O PONTO R
	glVertex3f(17.0, 17.0, 8.0);  // DESENHAR O PONTO S
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 10.0, 8.0);  // DESENHAR O PONTO K
	glVertex3f(8.0, 10.0, 8.0);  // DESENHAR O PONTO F'
	glVertex3f(10.0, 13.0, 8.0);  // DESENHAR O PONTO Q
	glVertex3f(17.0, 13.0, 8.0);  // DESENHAR O PONTO R
	glEnd();
	glPopMatrix();

	// TELHADO - N , D , P , L , K'' , J , V , U , X

	glPushMatrix();
	glColor3f(0.6470, 0.1647, 0.1647);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 20.0, 0.0);  // DESENHAR O PONTO D
	glVertex3f(20.0, 20.0, 0.0);  // DESENHAR O PONTO P
	glVertex3f(20.0, 20.0, 8.0);  // DESENHAR O PONTO L
	glVertex3f(8.0, 20.0, 8.0);  // DESENHAR O PONTO F''
	glVertex3f(8.0, 20.0, 15.0);  // DESENHAR O PONTO J
	glVertex3f(0.0, 20.0, 15.0);  // DESENHAR O PONTO N
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.0, 20.0, 0.0);  // DESENHAR O PONTO D
	glVertex3f(20.0, 20.0, 0.0);  // DESENHAR O PONTO P
	glVertex3f(20.0, 25.0, 4.0);  // DESENHAR O PONTO X
	glVertex3f(4.0, 25.0, 4.1);  // DESENHAR O PONTO U
	glVertex3f(4.0, 25.0, 15.0);  // DESENHAR O PONTO V
	glVertex3f(0.0, 20.0, 15.0);  // DESENHAR O PONTO N
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.0, 20.0, 8.0);  // DESENHAR O PONTO F''
	glVertex3f(20.0, 20.0, 8.0);  // DESENHAR O PONTO L
	glVertex3f(20.0, 25.0, 4.0);  // DESENHAR O PONTO X
	glVertex3f(4.0, 25.0, 4.1);  // DESENHAR O PONTO U
	glVertex3f(4.0, 25.0, 15.0);  // DESENHAR O PONTO V
	glVertex3f(8.0, 20.0, 15.0);  // DESENHAR O PONTO J
	glEnd();
	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA , TETO PARTE "BAIXO"
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES); //LINHA D --- P
	glVertex3f(0.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();

	glBegin(GL_LINES); //LINHA P --- L
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 8.0);
	glEnd();

	glBegin(GL_LINES); //LINHA L --- F''
	glVertex3f(20.0, 20.0, 8.0);
	glVertex3f(8.0, 20.0, 8.0);
	glEnd();

	glBegin(GL_LINES); //LINHA F'' --- J
	glVertex3f(8.0, 20.0, 8.0);
	glVertex3f(8.0, 20.0, 15.0);
	glEnd();

	glBegin(GL_LINES); //LINHA J --- N
	glVertex3f(8.0, 20.0, 15.0);
	glVertex3f(0.0, 20.0, 15.0);
	glEnd();

	glPopMatrix();

	glPushMatrix(); // FAZER A LINHA
	glBegin(GL_LINES); //LINHA N --- V
	glVertex3f(0.0, 20.0, 15.0);
	glVertex3f(4.0, 25.0, 15.0);
	glEnd();

	glBegin(GL_LINES); //LINHA V --- J
	glVertex3f(4.0, 25.0, 15.0);
	glVertex3f(8.0, 20.0, 15.0);
	glEnd();

	glBegin(GL_LINES); //LINHA V --- U
	glVertex3f(4.0, 25.0, 15.0);
	glVertex3f(4.0, 25.0, 4.1);
	glEnd();

	glBegin(GL_LINES); //LINHA U --- X
	glVertex3f(4.0, 25.0, 4.1);
	glVertex3f(20.0, 25.0, 4.0);
	glEnd();

	glBegin(GL_LINES); //LINHA L --- X
	glVertex3f(20.0, 20.0, 8.0);
	glVertex3f(20.0, 25.0, 4.0);

	glBegin(GL_LINES); //LINHA X --- P
	glVertex3f(20.0, 25.0, 4.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();

	glPopMatrix();

	// GARAGEM

	glPushMatrix(); // TETO DE GARAGEM
	glColor3f(3.8, 0.0, 1.1);
	glBegin(GL_QUADS);
	glVertex3f(20.0, 10.0, 8.0);  // DESENHAR O PONTO K
	glVertex3f(20.0, 10.0, 0.0);  // DESENHAR O PONTO O
	glVertex3f(33.0, 10.0, 0.0);  // DESENHAR O PONTO 0' Pilastra vai aqui
	glVertex3f(33.0, 10.0, 8.0);  // DESENHAR O PONTO K' pilastra vai aqui
	glEnd();
	glPopMatrix();

	/*
	  glMatrixMode(GL_MODELVIEW);
	  glLoadIdentity ( );
	  glTranslatef (....);
	  glRotatef (...);
	  glScalef(..);
	  GLUquadricObj *quadratic;
	  quadratic = gluNewQuadric();
	  glRotatef(-90.0f, 33.0f, 10.0f, 8.0f);
	  gluCylinder(quadratic,3.1f,3.1f,8.0f,32,32);

	  */

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix(); // FAZER CILINDRO
	glTranslatef(33.0, 0.0, 0.0);
	glColor3f(2.0, 1.9, 0.0);
	glMatrixMode(GL_MODELVIEW);
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	glRotatef(-90.0f, 8.0f, 0.0f, 0.0f);

	gluCylinder(quadratic, 0.2f, 0.2f, 10.0f, 32, 32);
	glPopMatrix();

	glPushMatrix(); // FAZER CILINDRO2
	glTranslatef(33.0, 0.0, 8.0);
	glColor3f(2.0, 1.9, 0.0);
	glMatrixMode(GL_MODELVIEW);
	quadratic = gluNewQuadric();
	glRotatef(-90.0f, 8.0f, 0.0f, 0.0f);
	gluCylinder(quadratic, 0.2f, 0.2f, 10.0f, 32, 32);

	glPopMatrix();
	glPushMatrix(); // FAZER CILINDRO3
	glTranslatef(20.2, 0.0, 0.0);
	glColor3f(2.0, 1.9, 0.0);
	glMatrixMode(GL_MODELVIEW);
	quadratic = gluNewQuadric();
	glRotatef(-90.0f, 8.0f, 0.0f, 0.0f);
	gluCylinder(quadratic, 0.2f, 0.2f, 10.0f, 32, 32);

	glPopMatrix();

	glPushMatrix(); // FAZER CILINDRO4
	glTranslatef(20.2, 0.0, 8.0);
	glColor3f(2.0, 1.9, 0.0);
	glMatrixMode(GL_MODELVIEW);
	quadratic = gluNewQuadric();
	glRotatef(-90.0f, 8.0f, 0.0f, 0.0f);
	gluCylinder(quadratic, 0.2f, 0.2f, 10.0f, 32, 32);

	glPopMatrix();

	//FAZER TEAPOT "IF YOU PUT WATER INTO A TEAPOT, IT BECOME A TEAPOT, BE WATER MY FRIEND"

	glPushMatrix();
	glColor3f(0.9, 1.9, 3.0);
	glTranslatef(30.0, 10.4, 5.0);
	glutSolidTeapot(.5);
	glPopMatrix();

	//PORTAS////////////////////////////////////////////////////////

	glPushMatrix();	    //porta1
	glTranslatef(8.0, 0.0, 13.0);
	glPushMatrix();
	glRotatef(-a, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(-8.0, 0.0, -13.0);
	glColor3f(0.8, 0.9, 1.1);
	glBegin(GL_QUADS);
	glVertex3f(8.0, 7.0, 13.0);  // DESENHAR O PONTO B
	glVertex3f(8.0, 7.0, 10.0);  // DESENHAR O PONTO P
	glVertex3f(8.0, 0.0, 10.0);  // DESENHAR O PONTO G
	glVertex3f(8.0, 0.0, 13.0);  // DESENHAR O PONTO L
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();	    //porta2
	glTranslatef(20.0, 10.0, 5.0);
	glPushMatrix();
	glRotatef(-a, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(-20.0, -10.0, -5.0);
	glColor3f(0.8, 0.9, 1.1);
	glBegin(GL_QUADS);
	glVertex3f(20.0, 10.0, 3.0);  // DESENHAR O PONTO B
	glVertex3f(20.0, 10.0, 5.0);  // DESENHAR O PONTO P
	glVertex3f(20.0, 15.0, 5.0);  // DESENHAR O PONTO L
	glVertex3f(20.0, 15.0, 3.0);  // DESENHAR O PONTO G
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//COISAS TRANSPARENTES //////////////////////////////////////////
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();	    //janela1
	glColor4f(0.8, 0.9, 1.1, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(2.0, 18.0, 15.0);  // DESENHAR O PONTO B
	glVertex3f(4.0, 18.0, 15.0);  // DESENHAR O PONTO P
	glVertex3f(4.0, 14.0, 15.0);  // DESENHAR O PONTO G
	glVertex3f(2.0, 14.0, 15.0);  // DESENHAR O PONTO L
	glEnd();
	glPopMatrix();

	glPushMatrix();	    //janela1/slide
	glTranslatef(-(6 - 4) * (b / 100), 0.0, 0.0);
	glColor4f(0.8, 0.9, 1.1, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(4.0, 18.0, 15.0);  // DESENHAR O PONTO B
	glVertex3f(6.0, 18.0, 15.0);  // DESENHAR O PONTO P
	glVertex3f(6.0, 14.0, 15.0);  // DESENHAR O PONTO G
	glVertex3f(4.0, 14.0, 15.0);  // DESENHAR O PONTO L
	glEnd();
	glPopMatrix();

	glPushMatrix();	    //janela2
	glColor4f(0.8, 0.9, 1.1, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(10.0, 17.0, 8.0);  // DESENHAR O PONTO B
	glVertex3f(14.0, 17.0, 8.0);  // DESENHAR O PONTO P
	glVertex3f(14.0, 13.0, 8.0);  // DESENHAR O PONTO G
	glVertex3f(10.0, 13.0, 8.0);  // DESENHAR O PONTO L
	glEnd();
	glPopMatrix();

	glPushMatrix();	    //janela2/slide
	glTranslatef(-(17 - 13) * (b / 100), 0.0, 0.0);
	glColor4f(0.8, 0.9, 1.1, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(14.0, 17.0, 8.0);  // DESENHAR O PONTO B
	glVertex3f(17.0, 17.0, 8.0);  // DESENHAR O PONTO P
	glVertex3f(17.0, 13.0, 8.0);  // DESENHAR O PONTO G
	glVertex3f(14.0, 13.0, 8.0);  // DESENHAR O PONTO L
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

// Inicializa par�metros de rendering
void Inicializa(void)
{
	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.7,0.7,1.0 };		 // "cor"
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho"
	GLfloat posicaoLuz[4] = { 0.0, 20.0, 20.0, 1.0 };

	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;

	// Especifica que a cor de fundo da janela ser� preta
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita a luz de n�mero 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	//angle=45;
	ANGULO = 45;
	rotX = rotY = 0;
	obsX = obsY = 0;
	obsZ = 60;//Voltar para 10
	escalaX = escalaY = escalaZ = 1;
}

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void) //equivalente ao posiciona observador
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva
	//gluPerspective(angle,fAspect,0.4,500);
	gluPerspective(ANGULO, ASPECTO, 0.4, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posi��o do observador e do alvo
	//gluLookAt(0,80,200, 0,0,0, 0,1,0);
	//gluLookAt(obsX, obsY, obsZ, 0,0,0, 0,1,0);
	glTranslatef(-obsX, -obsY, -obsZ);/*Translata a câmera para essas variáveis*/
	glRotatef(rotX, 1, 0, 0);/*Rotacionar a câmera para essas coordenadas*/
	glRotatef(rotY, 0, 1, 0);
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre��o de aspecto
	//fAspect = (GLfloat)w/(GLfloat)h;
	ASPECTO = (GLfloat)w / (GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	/*if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}*/
	if (state == GLUT_DOWN) {
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void motion(int x, int y) {
	if (bot == GLUT_LEFT_BUTTON) {//Rotação
		int deltaX = x_ini - x;
		int deltaY = y_ini - y;
		rotX = rotX_ini - deltaY / SENS_ROT;
		rotY = rotY_ini - deltaX / SENS_ROT;
	}
	else if (bot == GLUT_RIGHT_BUTTON) {//Zoom
		int deltaZ = y_ini - y;
		obsZ = obsZ_ini + deltaZ / SENS_OBS;
	}
	else if (bot == GLUT_MIDDLE_BUTTON) {//Correr
		int deltaX = x_ini - x;
		int deltaY = y_ini - y;
		obsX = obsX_ini + deltaX / SENS_TRANS;
		obsY = obsY_ini + deltaY / SENS_TRANS;
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'x':
		fp = !fp;
		break;
	case 'c':
		fj = !fj;
		break;
	}
}

static void idle(void) {
	//portas
	if (!fp && a > 0) { //fechar porta
		a = a - 1;
	}
	else
	{
		if (fp && a < 90) { //abrir porta
			a = a + 1;
		}
	}
	//janelas
	if (!fj && b > 0) { //
		b = b - 1;
	}
	else
	{
		if (fj && b < 100) {
			b = b + 1;
		}
	}
	glutPostRedisplay();
	//janelas
}
// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Teste 2017");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutMotionFunc(motion);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	Inicializa();
	glutMainLoop();
}