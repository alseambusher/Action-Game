#include<iostream>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<time.h>
#include"common.h"
#include"basicfunctions.h"
#include"pixel.h"
#include"extras.h"
using namespace std;
vector<int>OBSTACLE;
vector<int>BACKGROUND;
vector<points>CUSTOM_OBSTACLE;
void initialize(){
	int i=10;
	OBSTACLE.clear();
	OBSTACLE.push_back(-1);
	for(i=0;i<10;i++)
		OBSTACLE.push_back(rand()%6);
}
//initialize background
void initBg(){
	int i=10;
	BACKGROUND.push_back(-1);
	for(i=0;i<10;i++)
		BACKGROUND.push_back(rand()%2);
}
void display(void);
//globals
int height,width;
int face_y=0;
bool face_dir=1;//1 for up 0 for down
bool face_dir_override=0;
int face_bounce=0;
int mov=0;int mov1=0;
//enables drawing
bool drawEnable=1;
//screen modes START
int mode=4;//for game; 0 for main menu
//screen modes END
void keyboard(unsigned char key,int m,int n){
	switch(key){
		case 27: exit(0);break;
		case 32:face_dir=1;if(face_y<370)face_y=350;face_dir_override=1;break;
	}
}
void mouse(int button,int state,int x,int y){
	switch(button){
		case GLUT_LEFT_BUTTON:
			//if((state==GLUT_DOWN)&&(drawEnable==1)&&(mode==4)){
			if((state==GLUT_DOWN)&&(mode==4)){
				drawEnable=1;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			printf("right button");
			if(mode==4){
				drawEnable=0;
				CUSTOM_OBSTACLE.clear();
			}
			break;
		default:break;
	}
	glutSwapBuffers();
	fflush(stdout);
}
void draw (int x,int y){
	if(drawEnable==1){
		struct points p;
		p.x=x;p.y=height-y-30;
		CUSTOM_OBSTACLE.push_back(p);
	}
}
void special(int key,int x,int y){
		switch(key){
			//case GLUT_KEY_UP:face_dir=1;if(face_y<20)face_y+=150;break;
		//	case GLUT_KEY_DOWN:trans_y-=0.05;break;
		//	case GLUT_KEY_LEFT:trans_x-=0.05;break;
		//	case GLUT_KEY_RIGHT:trans_x+=0.05;break;
		}
}
void stars(){
        srand(time(NULL));
        glBegin(GL_POINTS);
        glPointSize(0.1);
        glColor3f(1.0,1.0,1.0);
        int i;
        float j,k;
        for(i=0;i<400;i++){
                j=(float)(rand()%width);
                k=(float)(rand()%height);
                glVertex2f(j,k);
                glVertex2f(-j,k);
                glVertex2f(j,-k);
                glVertex2f(-j,-k);
        }
        glEnd();
}
void cube (void) {
//    glTranslatef(trans_x,trans_y,trans_z);
 //   glScalef( 0.01*x, 0.01*x, 0.01*x ); 
  //  glRotatef(angle, axis_x, axis_y, axis_z);
}

void display (void) {
	int i;
	glClearColor (0.0,0.6,1.0,1.0);
	glClear (GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); 
	vector<int>::iterator itr=OBSTACLE.end(); 
	vector<int>::iterator itr1=BACKGROUND.end(); 
//	stars();
	for(i=0;i<150;i++)
//		linedda(i,100,i,250+abs(50*sin(i/rand()%100)),154.0/255,205.0/255,50.0/255);
		linedda(0,100+i,width,100+i,154.0/255,205.0/255,50.0/255);
	for(i=0;i<100;i++)
		linebre(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
	//this is for grass
	linedda(i,100,i,250+abs(50*sin(i/rand()%100)),154.0/255,205.0/255,50.0/255);
	linebre_junk(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
	linebre_junk(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
	linebre_junk(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
	linebre_junk(0,i-1,width,i,0.0,0.90+(i*0.002),0.0+(i*0.002));
	linebre_junk(0,i-1,width,i,0.5,0.90+(i*0.002),0.0+(i*0.002));
	linebre_junk(0,i-1,width,i,0.5,0.90+(i*0.002),0.0+(i*0.002));
	linebre_junk(0,i-1,width,i,0.0,0.90+(i*0.002),0.0+(i*0.002));
	//grass ends here
	background(mov1,200,*itr);
	if(mov1>width){
		BACKGROUND.pop_back();
		mov1=0;
	}
	if(itr1==BACKGROUND.begin())
		initBg();
	if(face_dir_override==1)
		face_y-=9;
	if(face_dir==1){
		if(face_y<20){
			face_y+=5;
			face_dir_override=0;
		}
		else
			face_dir=0;
	}
	else{
		if(face_y>0)
			face_y-=5;
		else
			face_dir=1;
	}
	if(face_y<5)
		face_bounce=10;
	else
		face_bounce=0;
	face(1100,140+face_y-face_bounce,50+face_bounce,40-face_bounce,0.8,0.0,0.0);
	circle(1000,500,50,1,0.6,0.2);
	mov+=15;mov1+=5;
	obstacle(mov,100,*itr);
	if(mov>width){
		OBSTACLE.pop_back();
		mov=0;
	}
	if(itr==OBSTACLE.begin())
		initialize();
	Color inner,boundary;
	inner.red=0.1;
	inner.green=1.0;
	inner.blue=0.1;
	boundary.red=0.0;
	boundary.green=0.6;
	boundary.blue=1.0;
	//Color temp=getPixel(500,400);
	//cout<<temp.red<<temp.green<<temp.blue;
	//Boundary_fill(1000,500,inner,boundary);
	//floodfill(1000,500,inner);
	if(CUSTOM_OBSTACLE.size()>1){
	for(i=0;i<CUSTOM_OBSTACLE.size()-1;i++){
		linedda(CUSTOM_OBSTACLE[i].x,CUSTOM_OBSTACLE[i].y,CUSTOM_OBSTACLE[i+1].x,CUSTOM_OBSTACLE[i+1].y,1,1,1);
	}
}
	glutSwapBuffers();
}

void reshape (int w, int h) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,width,0,height,-10.0,10.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

int main (int argc, char* argv[]) {
	width=atoi(argv[1]);
	height=atoi(argv[2]);
	initialize();
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize (width, height);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Glutle skater");
	glutFullScreen();
	glutDisplayFunc(display);
	//init();
	glutIdleFunc (display);
	glutReshapeFunc (reshape);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(draw);
	glutMainLoop();
	return 0;
}
