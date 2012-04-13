#include<iostream>
using namespace std;
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<time.h>
#include<unistd.h>
#include<string.h>
//globals
int height,width;
int face_y=0;
bool face_dir=1;//1 for up 0 for down
bool face_dir_override=0;
int face_bounce=0;
int mov=0;int mov1=0;
int mouseX;int mouseY;
//enables drawing
bool drawEnable=1;
//screen modes START
int mode=4;//for game; 0 for main menu
//screen modes END
#include"definitions.h"
#include"common.h"
#include"pixel.cpp"
#include"basicfunctions.cpp"
#include"characters.cpp"
#include"obstacle.cpp"
vector<int>OBSTACLE;
vector<int>BACKGROUND;
//global objects
Obstacle obstacleBuffer;
Obstacle obstaclE;
normalObjects normalObj;
normalObjects::drawingBoard board;
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
void keyboard(unsigned char key,int m,int n){
	switch(key){
		case 27: system("killall mplayer");exit(0);break;
		case 32:face_dir=1;if(face_y<370)face_y=350;face_dir_override=1;break;
	}
}
void mouse(int button,int state,int x,int y){
	switch(button){
		case GLUT_LEFT_BUTTON:
			//if((state==GLUT_DOWN)&&(drawEnable==1)&&(mode==4)){
			if((state==GLUT_DOWN)&&(mode==4)){
				obstacleBuffer.minY=1000000;
				drawEnable=1;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if(mode==4){
				drawEnable=0;
				obstacleBuffer.clear();
			}
			break;
		default:break;
	}
	glutSwapBuffers();
	fflush(stdout);
}
void hover(int x,int y){
	mouseX=x;mouseY=height-y;
}
void draw (int x,int y){
	mouseX=x;mouseY=height-y;
	if((drawEnable==1)&&(x>width/10)&&(x<width/3)&&(y<height-300)&&(y>height-600)){
		obstacleBuffer.addPixel(x,y);
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
void display (void) {
	int i;
	glClearColor (0.0,0.6,1.0,1.0);
	glClear (GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); 
	vector<int>::iterator itr=OBSTACLE.end(); 
	vector<int>::iterator itr1=BACKGROUND.end(); 
        char a[10];
        strcpy(a,"AAAAAAA");
	normalObj.ground(100);
	normalObj.grassField(150);
	normalObj.healthPoints();
	background(mov1,200,*itr);
	if(mov1>width){
		BACKGROUND.pop_back();
		mov1=0;
	}
	if(itr1==BACKGROUND.begin())
		initBg();
	circle(1000,500,50,1,0.6,0.2);
	//TODO increase mov with increase in points
	mov+=25;mov1+=5;
	//normalObjects::drawingBoard draw(width/10,300+face_y%9,300,width/3);

	board.x=width/10;board.y=300+face_y%9,board.h=300;board.w=width/3;
	board.draw();
	if(board.onMouseOver())
		board.showMenu();

	normalObj.Face();
	obstaclE.drawObstacle(mov,-obstaclE.minY+100,1);
	if(obstaclE.isCollision(mov,-obstaclE.minY+100)){
 		print_sentence(width/2,height/2,a,5,1,1,1);
		if(normalObj.shieldEnable)
			normalObj.shieldEnable=0;
		else{
			screenFilter filter;
			//filter.getAll();
			//filter.makeConstantColor(1,0,0);
			filter.getAndPlot(1,0,0);
			//filter.clear();
			//filter.plotOnly(0.1,0,0);
			normalObj.health-=10;
			normalObj.healthColor.red+=0.08;
			normalObj.healthColor.green-=0.02;
		}
	}
	if(mov>width){
		//OBSTACLE.pop_back();
		obstaclE=obstacleBuffer;
		obstacleBuffer.clear();
		obstacleBuffer.minY=1000000;
		mov=0;
	}
	if(itr==OBSTACLE.begin())
		initialize();
	//Color inner,boundary;
	//inner.red=0.5;inner.green=1.0;inner.blue=0.1;
	//boundary.red=1.0;boundary.green=0.6;boundary.blue=0.2;
//	Boundary_fill(1000,500,inner,boundary);
	//floodfill(1000,500,inner);
	obstacleBuffer.drawObstacle(0,0,0);
	glutSwapBuffers();
}

void reshape (int w, int h) {
	width=w;
	height=h;
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,width,0,height,-10.0,10.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}
int playEnable=1;
int main (int argc, char* argv[]) {
	width=atoi(argv[1]);
	height=atoi(argv[2]);
	initialize();
	//reset the normal objects
	normalObj.reset();
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
//this is for hover
	glutPassiveMotionFunc(hover);
	glutMotionFunc(draw);
	if(playEnable==1){
//		system("mplayer ../catalyst.mp3&");
//		play(argc,argv);
	}
	glutMainLoop();
	return 0;
}
