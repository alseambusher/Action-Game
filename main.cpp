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
#include<stdlib.h>
//****************globals*********************************
int height,width;//screen height and width
int face_y=0;//height inc of face
bool face_dir=1;//1 for up 0 for down
bool face_dir_override=0;//to enable jumping in mid air
int face_bounce=0;//provides bouncing effect
int mov=0;int mov1=0;//obstacle and background movement
int movinc=0;//to speed up the game
int mouseX;int mouseY;//gives mouse coordinates
bool drawEnable=1;//enables drawing
bool circledraw=0;
//screen modes START
int mode=1;//for game; 1 for main menu
//screen modes END
#include"definitions.h"//has function definitions
#include"common.h"//has super globals
#include"pixel.cpp"//pixel functions
#include"obstacle.cpp"
Obstacle obstacleBuffer;//obstacle on the drawing board
Obstacle obstaclE;//obstacle i the real world
#include"basicfunctions.cpp"
#include"characters.cpp"
vector<int>OBSTACLE;//stores obstacle index
vector<int>BACKGROUND;//stores background index
//**************global objects*******************
normalObjects normalObj;
normalObjects::drawingBoard board;//drawingBoard is an inner class of normalObjects
#include"inputControl.cpp"
//this is for segment file
float sx=0.0;float sy=0.0;float angle=0.0;
//initializes obstacle index
void initialize(){
	int i=10;
	OBSTACLE.clear();
	OBSTACLE.push_back(-1);
	for(i=0;i<10;i++)
		OBSTACLE.push_back(rand()%6);
}
//initialize background index
void initBg(){
	int i=10;
	BACKGROUND.clear();
	BACKGROUND.push_back(-1);
	for(i=0;i<10;i++)
		BACKGROUND.push_back(rand()%5);
}
void display (void) {
	int i;
	glClearColor (0.0,0.6,1.0,1.0);
	glClear (GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); 
	segmentupdater(1,2,0.3,0.3,0.3);//this initiates the segment file
	//this parses display file
	if(mode==0){
		if(normalObj.health<=0||normalObj.fuel1<=0){
			print_thick_sentence(width/2,height/2,"GAME OVER",9,5,1,0,0);
			print_thick_sentence(width/2,height/2-50,"PLAYER 1 WINS",5,5,1,1,1);
		}
		else if(normalObj.fuel2<=0){
			print_thick_sentence(width/2,height/2,"GAME OVER",9,5,1,0,0);
			print_thick_sentence(width/2,height/2-50,"PLAYER 2 WINS",5,5,1,1,1);
		}
	}
	if(mode==1){//main screen
		displayparser();int tx,ty;
		print_thick_sentence(100,100,"MAIN MENU",10,10,1,1,1);
		print_thick_sentence(595,620,"AATA",4,5,0,0,0);
		print_thick_sentence(585,520,"HEGE ??",4,5,0,0,0);
		print_thick_sentence(585,420,"ABOUT",4,5,0,0,0);
		print_thick_sentence(585,320,"CLOSE",4,5,0,0,0);
		if(mouseX>435&&mouseX<915 && mouseY>600&&mouseY<650)
		{
			ty=625;tx=675;
		if(sx<40.0)sx+=10.0;
		if(sy<40.0)sy+=10.0;
	
		}
		else if(mouseX>435&&mouseX<915 && mouseY>500&&mouseY<550)
		{
			ty=525;tx=675;
		if(sx<40.0)sx+=10.0;
		if(sy<40.0)sy+=10.0;

		}
		else if(mouseX>435&&mouseX<915 && mouseY>400&&mouseY<450)
		{
			ty=425;tx=675;
		if(sx<40.0)sx+=10.0;
		if(sy<40.0)sy+=10.0;
		}
		else if(mouseX>435&&mouseX<915 && mouseY>300&&mouseY<350)
		{
			ty=325;tx=675;
		if(sx<40.0)sx+=10.0;
		if(sy<40.0)sy+=10.0;
		}
		else{
			sx=0;sy=0;angle=0;tx=0;ty=0;//reset the values
		}
		
		segmentupdater(tx,ty,sx,sy,angle);
		segmentparser();
		
	}
	else if(mode==2){//hege mode
		displayparser();
 		int i,j;
 		print_thick_sentence(100,100,"INSTRUCTIONS",10,10,1,1,1);
		for(i=0;i<225;i++)
			linedda(370,250+i,955,250+i,0.05+i*0.004,0,0);
		for(i=0;i<225;i++)
			linedda(370,475+i,955,475+i,0.95-i*0.004,0.0,0.0);
		print_thick_sentence(402,640,"THE RATE OF DECREASE OF FUEL FROM PLAYER1 IS ",2,3,1,1,1);
        	print_thick_sentence(402,610,"PROPORTIONAL TO THE AREA OF THE CREATED ",2,3,1,1,1);
		print_thick_sentence(402,580,"OBSTACLE",2,3,1,1,1);
		print_thick_sentence(402,540,"THE RATE OF DECREASE OF FUEL FROM PLAYER2 IS",2,3,1,1,1);
		print_thick_sentence(402,510,"PROPORTIONAL TO THE NUMBER OF JUMPS MADE",2,3,1,1,1);
		print_thick_sentence(402,470,"PLAYER1 CONTROLS .......",2,3,0,0,1);
		print_thick_sentence(402,430,"  PRESS LEFT MOUSE BUTTON AND CREATE OBSTACLES",2,3,1,1,1);
		print_thick_sentence(402,390, "  PRESS RIGHT MOUSE BUTTON TO CLEAR THE BOARD",2,3,1,1,1);
		print_thick_sentence(402,350,"PLAYER2 CONTROLS",2,3,0,0,1);
		print_thick_sentence(402,310,"  PRESS SPACE TO JUMP",2,3,1,1,1);
		print_thick_sentence(402,270,"  PRESS X TO SHOOT AT OBSTACLES",2,3,1,1,1); 
	}
	else if(mode==3){//about mode
		displayparser();
 		int i,j;
 		print_thick_sentence(100,100,"ABOUT",10,10,1,1,1);
		for(i=0;i<225;i++)
			linedda(380,250+i,945,250+i,0.05+i*0.004,0,0);
		for(i=0;i<225;i++)
			linedda(380,475+i,945,475+i,0.95-i*0.004,0.0,0.0);
		print_thick_sentence(402,640,"THIS GAME IS DEVELOPED BY ALSE PRP AND ABHAY",2,3,1,1,1);
        	print_thick_sentence(402,600,"GLUTLE IS A 2 PLAYER GAME IN WHICH .....",2,3,1,1,1);
		print_thick_sentence(402,560,"PLAYER1 - CREATES OBSTACLES",2,3,1,1,1);
		print_thick_sentence(402,520,"PLAYER2 - EVADES THE CREATED OBSTACLES",2,3,1,1,1);
		print_thick_sentence(402,480,"OBJECTIVE",3,5,0.0,0.0,1.0);
		print_thick_sentence(402,440,"THE GAME IS BASICALLY A RACE AGAINST FUEL",2,3,1,1,1);
		print_thick_sentence(402,400,"EACH PLAYER HAS TO USE HIS FUEL WISELY",2,3,1,1,1);
		print_thick_sentence(402,360,"PLAYER1 ASO WINS IF THE HEALTH OF PLAYER2",2,3,1,1,1);
		print_thick_sentence(402,330,"GOES BELOW ZERO",2,3,1,1,1);
	}
	else if(mode==4){//aadu mode
		if(normalObj.health<=0||normalObj.fuel1<=0||normalObj.fuel2<=0)//check for health,fuel
			mode=0;
			vector<int>::iterator itr=OBSTACLE.end(); 
		vector<int>::iterator itr1=BACKGROUND.end(); //iterator for bg
		normalObj.grassField(150);
		normalObj.ground(115);
		normalObj.healthPoints();
		background(mov1,200,*itr1);
		if(mov1>width+300){//if bg goes out of the boundary
			BACKGROUND.pop_back();
			mov1=0;
		}
		if(itr1==BACKGROUND.begin())//reinitiate bg
			initBg();
		mov+=25+0.01*(++movinc);//obstacle speed
		mov1+=5;//bg speed
		board.x=width/10;board.y=300+face_y%9,board.h=300;board.w=width/3;//set board dimensions
		board.draw();//draw board
		//to control onmouseover of drawing board
		board.onMouseOver();//control onmouseover features
		normalObj.Face();//draw and control face
		obstaclE.drawObstacle(mov,-obstaclE.minY+100,1);//draw obstacle in the real world
		if(obstaclE.isCollision(mov,-obstaclE.minY+100)){//check for collision
			if(normalObj.shieldEnable)//if shield is on?
				normalObj.shieldEnable=0;
			else{//hit
				system("mplayer ~/.glutrix/hit.wav&");
				normalObj.health-=10;
				normalObj.healthColor.red+=0.08;
				normalObj.healthColor.green-=0.02;
			}
		}
		//chekpoint
		normalObj.checkpoint();
		//for missile collision
		if((normalObj.missileEnableY>0)&&(normalObj.missileEnableX>0))
			if((obstaclE.maxY-obstaclE.minY>=normalObj.missileEnableY)&&(obstaclE.maxX+mov>normalObj.missileEnableX)){//check for collision
				obstaclE.clear();
				normalObj.missileEnableX=0;
				normalObj.missileEnableY=0;
			}
		if(mov>width){//when obstacle goes beyond the width
			obstaclE=obstacleBuffer;//Buffer->real obstacle
			normalObj.fuel2-=obstaclE.CUSTOM_OBSTACLE.size()*4;//reduce fuel2
			board.distortEnable=0;//reset drawing mode to normal mode
			obstacleBuffer.clear();//clear buffer
			mov=0;//restart mov
		}
		if(itr==OBSTACLE.begin())
			initialize();
		obstacleBuffer.drawObstacle(0,0,0);//draw on board from buffer
	}
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
int main (int argc, char* argv[]) {
	width=atoi(argv[1]);
	height=atoi(argv[2]);
	initialize();
	initBg();
	obstacleBuffer.clear();//clear buffer
	normalObj.reset();//reset the normal objects
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize (width, height);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Glutle");
	glutFullScreen();
	glutDisplayFunc(display);
	glutIdleFunc (display);
	glutReshapeFunc (reshape);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);//for click
	glutPassiveMotionFunc(hover);//this is for hover
	glutMotionFunc(draw);//for drag
	system("mplayer ~/.glutrix/ambient.ogg -loop 0&");//bg music
	glutMainLoop();
	return 0;
}
