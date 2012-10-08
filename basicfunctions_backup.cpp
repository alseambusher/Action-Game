#include"basicfunctions.h"
using namespace std;
//dda line 
void linedda(int xa,int ya,int xb,int yb,float colorR,float colorG,float colorB){
	glColor4f(colorR,colorG,colorB,0.8);
	glBegin(GL_POINTS);
	int dx=xb-xa;
	int dy=yb-ya;
	float xinc,yinc,x,y,steps;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc=dx/steps;
	yinc=dy/steps;
	x=xa;
	y=ya;
	glVertex3f(x,y,1);
	int k;
	for(k=1;k<=steps;k++){
		x+=xinc;
		y+=yinc;
		glVertex3f(round(x),round(y),1);
	}
	glEnd();
}
// bresenham line
void linebre(int xa,int ya,int xb,int yb,float colorR,float colorG,float colorB){
	glColor3f(colorR,colorG,colorB);
	glBegin(GL_POINTS);
	int x,y;
	int dx=xb-xa;
	int dy=yb-ya;
	int p=2*dy-dx;
	int xEnd;
	if(xa>xb){
		x=xb;y=yb;
		xEnd=xa;
	}
	else{
		x=xa;y=ya;
		xEnd=xb;
	}
	glVertex3f(x,y,1);
	while(x<xEnd){
		x++;
		if(p<0)
			p+=2*dy;
		else{
			y++;
			p+=2*(dy-dx);
		}
		glVertex3f(x,y,1);
	}
	glEnd();
}
//mid point circle algo
void circle(int xcenter,int ycenter,int radius,float colorR,float colorG,float colorB){
	glColor3f(colorR,colorG,colorB);
	glBegin(GL_POINTS);
	int p,x,y;
	x=0;y=radius;

	if(circledraw){
		obstacleBuffer.addPixel(xcenter+x,height-(ycenter+y));
		obstacleBuffer.addPixel(xcenter+x,height-(ycenter-y));
		obstacleBuffer.addPixel(xcenter-x,height-(ycenter+y));
		obstacleBuffer.addPixel(xcenter-x,height-(ycenter-y));
		obstacleBuffer.addPixel(xcenter+y,height-(ycenter+x));
		obstacleBuffer.addPixel(xcenter+y,height-(ycenter-x));
		obstacleBuffer.addPixel(xcenter-y,height-(ycenter+x));
		obstacleBuffer.addPixel(xcenter-y,height-(ycenter-x));
	}
	else{
		glVertex3f(xcenter+x,ycenter+y,1);
		glVertex3f(xcenter+x,ycenter-y,1);
		glVertex3f(xcenter-x,ycenter+y,1);
		glVertex3f(xcenter-x,ycenter-y,1);
		glVertex3f(xcenter+y,ycenter+x,1);
		glVertex3f(xcenter+y,ycenter-x,1);
		glVertex3f(xcenter-y,ycenter+x,1);
		glVertex3f(xcenter-y,ycenter-x,1);
	}
	p=1-radius;
	while(x<y){
		x++;
		if(p<0)
			p+=2*x+1;
		else{
			y--;
			p+=2*(x-y)+1;
		}
		if(circledraw){
			obstacleBuffer.addPixel(xcenter+x,height-(ycenter+y));
			obstacleBuffer.addPixel(xcenter+x,height-(ycenter-y));
			obstacleBuffer.addPixel(xcenter-x,height-(ycenter+y));
			obstacleBuffer.addPixel(xcenter-x,height-(ycenter-y));
			obstacleBuffer.addPixel(xcenter+y,height-(ycenter+x));
			obstacleBuffer.addPixel(xcenter+y,height-(ycenter-x));
			obstacleBuffer.addPixel(xcenter-y,height-(ycenter+x));
			obstacleBuffer.addPixel(xcenter-y,height-(ycenter-x));
		}
		else{
			glVertex3f(xcenter+x,ycenter+y,1);
			glVertex3f(xcenter+x,ycenter-y,1);
			glVertex3f(xcenter-x,ycenter+y,1);
			glVertex3f(xcenter-x,ycenter-y,1);
			glVertex3f(xcenter+y,ycenter+x,1);
			glVertex3f(xcenter+y,ycenter-x,1);
			glVertex3f(xcenter-y,ycenter+x,1);
			glVertex3f(xcenter-y,ycenter-x,1);
		}
	}
	if(obstacleBuffer.CUSTOM_OBSTACLE.size()-1>0){
		for(int i=0;i<obstacleBuffer.CUSTOM_OBSTACLE.size();i++){
			if(width/10>obstacleBuffer.CUSTOM_OBSTACLE[i].x){//point to the left
				obstacleBuffer.CUSTOM_OBSTACLE[i].x=width/10;
				if(obstacleBuffer.minX<width/10)
					obstacleBuffer.minX=width/10;
			}
			if(width/3<obstacleBuffer.CUSTOM_OBSTACLE[i].x){//point to the right
				obstacleBuffer.CUSTOM_OBSTACLE[i].x=width/3;
				if(obstacleBuffer.maxX>width/3)
					obstacleBuffer.maxX=width/3;
			}
			if(300>obstacleBuffer.CUSTOM_OBSTACLE[i].y){//point bottom
				obstacleBuffer.CUSTOM_OBSTACLE[i].y=300;
				if(obstacleBuffer.minY<300)
					obstacleBuffer.minY=300;
			}
			if(600<obstacleBuffer.CUSTOM_OBSTACLE[i].y){//point top
				obstacleBuffer.CUSTOM_OBSTACLE[i].y=600;
				if(obstacleBuffer.maxY>600)
					obstacleBuffer.maxY=600;
			}
		}
	}
	glEnd();
}
//midpoint ellipse algorithm
void ellipse(int xcenter,int ycenter,int Rx,int Ry,float colorR,float colorG,float colorB,bool isFilled){
	glColor3f(colorR,colorG,colorB);
	glBegin(GL_POINTS);
	int p,px,py,x,y;
	int Rx2=Rx*Rx;
	int Ry2=Ry*Ry;
	int twoRx2=2*Rx2;
	int twoRy2=2*Ry2;
	x=0;y=Ry;
	if(!isFilled){//filled?
		glVertex3f(xcenter+x,ycenter+y,1);
		glVertex3f(xcenter+x,ycenter-y,1);
		glVertex3f(xcenter-x,ycenter+y,1);
		glVertex3f(xcenter-x,ycenter-y,1);
	}
	else{
		linedda(xcenter-x,ycenter+y,xcenter+x,ycenter+y,colorR,colorG,colorB);
		linedda(xcenter-x,ycenter-y,xcenter+x,ycenter-y,colorR,colorG,colorB);
	}
	p=round(Ry2-Rx2*Ry+(0.25*Rx2));
	px=0;
	py=twoRx2*y;
	while(px<py){
		x++;
		px+=twoRy2;
		if(p>=0){
			y--;
			py=py-twoRx2;
		}
		if(p<0)
			p+=Ry2+px;
		else
			p+=Ry2+px-py;
		if(isFilled){
			linedda(xcenter-x,ycenter+y,xcenter+x,ycenter+y,colorR,colorG,colorB);
			linedda(xcenter-x,ycenter-y,xcenter+x,ycenter-y,colorR,colorG,colorB);
		}
		else{
			glVertex3f(xcenter+x,ycenter+y,1);
			glVertex3f(xcenter+x,ycenter-y,1);
			glVertex3f(xcenter-x,ycenter+y,1);
			glVertex3f(xcenter-x,ycenter-y,1);
		}
	}
	//region2
	//p=round(Ry2*(x+0.5)+(x+0.5)+Ry2*(y-1)*(y-1)-Rx2*Ry2);
	p=round(Ry2*(x+0.5)*(x+0.5)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
	while(y>0){
		y--;
		py=py-twoRx2;
		if(p<=0){
			x++;
			px+=twoRy2;
		}
		if(p>0)
			p+=Rx2-py;
		else
			p+=Rx2-py+px;
		if(isFilled){
			linedda(xcenter-x,ycenter+y,xcenter+x,ycenter+y,colorR,colorG,colorB);
			linedda(xcenter-x,ycenter-y,xcenter+x,ycenter-y,colorR,colorG,colorB);
		}
		else{
			glVertex3f(xcenter+x,ycenter+y,1);
			glVertex3f(xcenter+x,ycenter-y,1);
			glVertex3f(xcenter-x,ycenter+y,1);
			glVertex3f(xcenter-x,ycenter-y,1);
		}
	}
	glEnd();
}
int face_rotate(int xc,int yc,int coordinate1,int coordinate2,int type,float angle){
//xc=0;yc=0;	
	if(type==1){
		if(face_dir_override==1){
			return round(xc+(coordinate1-xc)*cos(angle)-(coordinate2-yc)*sin(angle));
			//return coordinate1+40*cos(angle)-50*sin(angle);
			//return coordinate1;
		}
		else
			return coordinate1;
	}
	else{
		if(face_dir_override==1){
			return round(yc+sin(angle)*(coordinate1-xc)+cos(angle)*(coordinate2-yc));
			//return coordinate2+sin(angle)*(coordinate1)+cos(angle)*(coordinate2);
			//return coordinate2+sin(angle)*40+cos(angle)*50;
			//return coordinate2;
		}
		else
			return coordinate2;
	}
}
void face(int xcenter,int ycenter,int Rx,int Ry,float colorR,float colorG,float colorB,float angle){//our hero
	FACE_COORDINATES.clear();//clear points in the face 
	face_coordinates FACE;
	glColor3f(colorR,colorG,colorB);
	int p,px,py,x,y;
	int Rx2=Rx*Rx;
	int Ry2=Ry*Ry;
	int twoRx2=2*Rx2;
	int twoRy2=2*Ry2;
	x=0;y=Ry;
	//angle=0.5;
	//linebre(xcenter-x,ycenter+y,xcenter+x,ycenter+y,colorR,colorG,colorB);
	//linebre(xcenter-x,ycenter-y,xcenter+x,ycenter-y,colorR,colorG,colorB);
	FACE.add(xcenter-x,ycenter+y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter+x,ycenter+y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter-x,ycenter-y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter+x,ycenter-y);FACE_COORDINATES.push_back(FACE);
	linedda(face_rotate(xcenter,ycenter,xcenter-x,ycenter+y,1,angle),face_rotate(xcenter,ycenter,xcenter-x,ycenter+y,2,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter+y,1,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter+y,2,angle),colorR,colorG,colorB);
	linedda(face_rotate(xcenter,ycenter,xcenter-x,ycenter-y,1,angle),face_rotate(xcenter,ycenter,xcenter-x,ycenter-y,2,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter-y,1,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter-y,2,angle),colorR,colorG,colorB);
	colorR+=0.005;colorG+=0.005;colorB+=0.000;
	p=round(Ry2-Rx2*Ry+(0.25*Rx2));
	px=0;
	py=twoRx2*y;
	while(px<py){
		x++;
		px+=twoRy2;
		if(p>=0){
			y--;
			py=py-twoRx2;
		}
		if(p<0)
			p+=Ry2+px;
		else
			p+=Ry2+px-py;
	//linebre(xcenter-x,ycenter+y,xcenter+x,ycenter+y,colorR,colorG,colorB);
	//linebre(xcenter-x,ycenter-y,xcenter+x,ycenter-y,colorR,colorG,colorB);
	FACE.add(xcenter-x,ycenter+y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter+x,ycenter+y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter-x,ycenter-y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter+x,ycenter-y);FACE_COORDINATES.push_back(FACE);
	linedda(face_rotate(xcenter,ycenter,xcenter-x,ycenter+y,1,angle),face_rotate(xcenter,ycenter,xcenter-x,ycenter+y,2,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter+y,1,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter+y,2,angle),colorR,colorG,colorB);
	linedda(face_rotate(xcenter,ycenter,xcenter-x,ycenter-y,1,angle),face_rotate(xcenter,ycenter,xcenter-x,ycenter-y,2,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter-y,1,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter-y,2,angle),colorR,colorG,colorB);
	colorR+=0.005;colorG+=0.005;colorB+=0.000;
	}
	//region2
	p=round(Ry2*(x+0.5)*(x+0.5)+Ry2*(y-1)*(y-1)-Rx2*Ry2);
	while(y>0){
		y--;
		py=py-twoRx2;
		if(p<=0){
			x++;
			px+=twoRy2;
		}
		if(p>0)
			p+=Rx2-py;
		else
			p+=Rx2-py+px;
	//linebre(xcenter-x,ycenter+y,xcenter+x,ycenter+y,colorR,colorG,colorB);
	//linebre(xcenter-x,ycenter-y,xcenter+x,ycenter-y,colorR,colorG,colorB);
	FACE.add(xcenter-x,ycenter+y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter+x,ycenter+y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter-x,ycenter-y);FACE_COORDINATES.push_back(FACE);
	FACE.add(xcenter+x,ycenter-y);FACE_COORDINATES.push_back(FACE);
	linedda(face_rotate(xcenter,ycenter,xcenter-x,ycenter+y,1,angle),face_rotate(xcenter,ycenter,xcenter-x,ycenter+y,2,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter+y,1,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter+y,2,angle),colorR,colorG,colorB);
	linedda(face_rotate(xcenter,ycenter,xcenter-x,ycenter-y,1,angle),face_rotate(xcenter,ycenter,xcenter-x,ycenter-y,2,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter-y,1,angle),face_rotate(xcenter,ycenter,xcenter+x,ycenter-y,2,angle),colorR,colorG,colorB);
	colorR+=0.005;colorG+=0.005;colorB+=0.000;
	}
}
points rotate(int xc,int yc,int x_cord,int y_cord,float angle){
	points p;
	p.x=round(xc+(x_cord-xc)*cos(angle)-(y_cord-yc)*sin(angle));
	p.y=round(yc+sin(angle)*(x_cord-xc)+cos(angle)*(y_cord-yc));
	return p;
}
//obstacles are written here
void obstacle(int x,int y,int type){
	int i;
	if(type==0){
		for(i=0;i<160;i++)
			linebre(x,y+i,x+100,y+i,0.7,0.35+(i*0.001),0.1+(i*0.001));	
	}
	if(type==1){
		for(i=0;i<60;i++)
			linebre(x,y+i,x+300,y+i,1.0,0.7+(i*0.005),0.5+(i*0.002));	
	}
	if(type==2){
		for(i=0;i<60;i++)
			linebre(x,y+i,x+100,y+i,1.0,0.7+(i*0.005),0.5+(i*0.002));	
		for(i=0;i<130;i++)
			linebre(x+110,y+i,x+200,y+i,1.0,0.7+(i*0.005),0.5+(i*0.002));	
		for(i=0;i<80;i++)
			linebre(x+220,y+i,x+300,y+i,1.0,0.7+(i*0.005),0.5+(i*0.002));	
	}
//tree
	if(type==3){
		for(i=0;i<35;i++)
			linedda(x+i,y,x+i,y+70,139.0/255,69.0/255+(i*0.01),19.0/255+(i*0.01));
		face(x-25,y+70+30,50,50,0.0,1.0,0.0,0);
		face(x+35+25,y+70+30,50,50,0.0,1.0,0.0,0);
		face(x+17,y+70+70,50,50,0.0,1.0,0.0,0);
	
	}
//building
	if(type==4){
		for(i=0;i<190;i++)
		linebre(x,y+i,x+125,y+i,1.0,0.7+(i*0.002),0.5+(i*0.002));

		for(i=0;i<20;i++)
		{
		linebre(x+25,y+i+160,x+25+25,y+i+160,139.0/255,(69-2*i)/255.0,19.0/255);
		linebre(x+25+25+25,y+i+160,x+25+25+25+25,y+i+160,139.0/255,(69-2*i)/255.0,19.0/255);
		linebre(x+25,y+i+40,x+25+25,y+i+40,139.0/255,(69-2*i)/255.0,19.0/255);
		linebre(x+25+25+25,y+i+40,x+25+25+25+25,y+i+40,139.0/255,(69-2*i)/255.0,19.0/255);
		
		linebre(x+25,y+i+80,x+25+25,y+i+80,139.0/255,(69-3*i)/255.0,19.0/255);
		linebre(x+25+25+25,y+i+80,x+25+25+25+25,y+i+80,139.0/255,(69-3*i)/255.0,19.0/255);
		linebre(x+25,y+i+120,x+25+25,y+i+120,139.0/255,(69-3*i)/255.0,19.0/255);
		linebre(x+25+25+25,y+i+120,x+25+25+25+25,y+i+120,139.0/255,(69-3*i)/255.0,19.0/255);
		}
	}
	//coniferous tree
	if(type==5){
		for(i=0;i<35;i++)
			linedda(x+i,y,x+i,y+40,139.0/255,69.0/255+(i*0.01),19.0/255+(i*0.01));
		for(i=0;i<140;i++)
			linebre(x-30+1.0/3*i,y+i+40,x+35+30-1.0/3*i,y+i+40,0.0,0.5+(i*0.004),0.0);
	}
}
void background(int x,int y,int type)//backgrounds are written here
{
	int i,angle;
	switch(type)
	{
	case 0:case 1: //coniferous tree
		for(i=0;i<35/2;i++)
			linedda(x+i,y,x+i,y+40/2,139.0/255,69.0/255+(i*0.01),19.0/255+(i*0.01));
		for(i=0;i<140/2;i++)
			linebre(x-30/2+1.0/3*i,y+i+40/2,x+35/2+30/2-1.0/3*i,y+i+40/2,0.0,0.5+(i*0.004),0.0);
		for(i=0;i<35/2;i++)
			linedda(x+i-30,y,x+i-30,y+40/2,139.0/255,69.0/255+(i*0.01),19.0/255+(i*0.01));
		for(i=0;i<140/2;i++)
			linebre(x-30/2+1.0/3*i-30,y+i+40/2,x+35/2+30/2-1.0/3*i-30,y+i+40/2,0.0,0.5+(i*0.004),0.0);
		for(i=0;i<35/2;i++)
			linedda(x+i-60,y,x+i-60,y+40/2,139.0/255,69.0/255+(i*0.01),19.0/255+(i*0.01));
		for(i=0;i<140/2;i++)
			linebre(x-30/2+1.0/3*i-60,y+i+40/2,x+35/2+30/2-1.0/3*i-60,y+i+40/2,0.0,0.5+(i*0.004),0.0);
		for(i=0;i<35/2;i++)
			linedda(x+i-300,y,x+i-300,y+40/2,139.0/255,69.0/255+(i*0.01),19.0/255+(i*0.01));
		for(i=0;i<140/2;i++)
			linebre(x-30/2+1.0/3*i-300,y+i+40/2,x+35/2+30/2-1.0/3*i-300,y+i+40/2,0.0,0.5+(i*0.004),0.0);
		break;
	
	case 4:case 2://mountains
		for(i=0;i<300;i++)
			linedda(x-300+i,y+50,x-300+i,y+50+abs(40*sin(i*3.14159/150)),0.45,0.28,0.15);
		break;
		
	case 3://wind mill
		for(i=0;i<50;i++)
			linedda(x-300+0.3*i,y+20+i,x-300-0.3*i+30,y+20+i,0.4+i*0.01,0.4+i*0.01,0.4);
		linedda(rotate(x-285,y+70,x-285-30,y+70-30,angle).x,rotate(x-285,y+70,x-285-30,y+70-30,angle).y,rotate(x-285,y+70,x-285+30,y+70+30,angle).x,rotate(x-285,y+70,x-285+30,y+70+30,angle).y,1,1,1);
		linedda(rotate(x-285,y+70,x-285-30,y+70+30,angle).x,rotate(x-285,y+70,x-285-30,y+70+30,angle).y,rotate(x-285,y+70,x-285+30,y+70-30,angle).x,rotate(x-285,y+70,x-285+30,y+70-30,angle).y,1,1,1);
		angle+=0.03;
		break;
		
	
	}

}
class normalObjects{
public:
	int points1,points2,health,missileInc,fuel1,fuel2,gameTime;
	bool shieldEnable;
	Color healthColor;
	float faceAngle;
	int missileEnableX,missileEnableY;//positions of missile
	void reset(){//resets all the parameters in the instance
		points1=0;points2=0;health=100;
		healthColor.red=0;healthColor.blue=0;healthColor.green=1;
		shieldEnable=0;
		missileInc=0;
		fuel1=32767;
		fuel2=32767;
		faceAngle=0;
		gameTime=0;
		missileInc=0;
		missileEnableX=0;
		missileEnableY=0;
	}
	void ground(int h){
		gameTime++;//increase gameTime
		for(int i=0;i<h;i++)
                	linebre(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
        //this is for grass
		for(int i=0;i<width;i++)
       			linedda(i,h,i,h+abs(50*sin(i/(rand()%50+1))),0,0.7,0);
       	for(int i=0;i<width;i++)
       			linedda(i,0,i,abs(60*sin(i/(rand()%30+1))),0.0/255,205.0/255,50.0/255);
	}
	void grassField(int h){
        	for(int i=0;i<h;i++)
                	linedda(0,100+i,width,100+i,154.0/255-i*0.001,205.0/255-i*0.001,50.0/255-i*0.001);
	}
	void Face(){
		if(face_dir_override==1)//commin down faster frm a greater height
                	face_y-=9;
		 if(face_dir==1){//going up
                	if(face_y<20){//20 is the max bouncing height
                        	face_y+=5;
                        	face_dir_override=0;//comming down slower
                	}
                	else
	                        face_dir=0;
        	}
        	else{//goin down
                	if(face_y>0)
                        	face_y-=5;
                	else
                        	face_dir=1;
        	}
        	if(face_y<5)
                	face_bounce=10;//to enable squeezing effect
        	else
                	face_bounce=0;

		//this is for dust behind the face
		if(face_y<=0)
                {
                        for(int i=0;i<15;i++)
                        {
                                ellipse(1060+rand()%30,100+rand()%15,3,3,0.7,0.4,0.2,1);
                                ellipse(1150-rand()%30,100+rand()%15,3,3,0.7,0.4,0.2,1);
                        }
                }
	        face(1100,140+face_y-face_bounce,50+face_bounce+missileInc,40-face_bounce-(missileInc/2),0.8,0.0,0.0,faceAngle);
		//this is for dust infront of the face
                if(face_y<=0)
                {
                        for(int i=0;i<15;i++)
                        {
                                ellipse(1090+rand()%20,100+rand()%10,3,3,0.75,0.45,0.25,1);
                        }
                }
		
		faceAngle+=0.0;
	        //face(1100,140+face_y-face_bounce,50+face_bounce+missileInc,40-face_bounce-(missileInc/2),0.8,0.0,0.0,faceAngle);
		if(shieldEnable)//draw shield
			for(int i=1;i<30;i=i+2)
				//circle(1100,140+face_y-face_bounce,55+i,(255-2*i)/255.0,(210-4*i)/255.0,(100-8*i)/255.0);
				circle(1100,140+face_y-face_bounce,55+i,0/255.0,0/255.0,(255-8*i)/255.0);
		if(missileInc>0)//this is to reset after missile launch
			missileInc-=5;
		if(missileEnableX>0){
			ellipse(missileEnableX,missileEnableY,10,5,0.8,0,0,1);//our missile
			missileEnableX-=50;//mov missile to the left
		}
	}
	void missileLaunch(){
		if((missileInc==0)&&(fuel1>0)){
			system("mplayer ~/.glutrix/hittree.ogg&");
			fuel1-=1600;
			missileInc+=30;
			missileEnableX=1100-50-face_bounce-missileInc;//xcenter of the missile
			missileEnableY=140+face_y-face_bounce;//ycenter of the missile
		}
	}
	void healthPoints(){//displays health and fuel
        	char a[50];
		//player1 health
		for(int i=0;i<(350*health)/100;i++)
			linedda(width-i,height-60,width-10-i,height-90,healthColor.red,healthColor.green,healthColor.blue);
		sprintf(a,"%d",health);	
		print_sentence(width-60,height-80,a,3,0,0,0);
		//player1 fuel
		for(int i=0;i<(300*fuel1)/32767;i++)
			linedda(width-i,height-100,width-10-i,height-130,0.4,0.4,0.4);
		sprintf(a,"%d",fuel1);	
		print_sentence(width-90,height-120,a,3,1,1,1);
		//player2 fuel
		for(int i=0;i<(300*fuel2)/32767;i++)
			linedda(i,height-60,i+10,height-90,0.4,0.4,0.4);
		sprintf(a,"%d",fuel2);	
		print_sentence(20,height-80,a,3,1,1,1);
		//gameTime
		sprintf(a,"%d",gameTime);	
        	print_thick_sentence(width/2-40,height-30,a,5,5,1,1,1);
	}
	void checkpoint(){
		if(!(199-gameTime%200)&&(gameTime!=0))//for every 200 game time he gets a shield
			shieldEnable=1;
	}
	class drawingBoard{
	public:
		int x,y,h,w;//dimensions of drawing board
		Color pickColor;//colour picking
		points pickColorIndicatorR,pickColorIndicatorG,pickColorIndicatorB;
		int drawFromMenuPreview;
		int distortEnable;//inbuilt objs or not?
		float mouseclick[2],mousedrag[2];//stores x and y values of click and drag
		void draw(){//drawing board
			for(int i=0;i<h;i++)
                        	linedda(x,y+i,w,y+i,0,0+(i*0.003),0);
               		linedda(x,y,x,y+h,0,0,0);
                	linedda(x-1,y,x-1,y+h,0,1,0);
                	linedda(x,y+h,w,y+h,0,0,0);
                	linedda(x,y+h+1,w,y+h+1,0,1,0);
			for(int i=x;i<=w;i++)
				linedda(i,y+h,i+10,y+h+50,0.001*i,0.002*i,0.0005*i);
			for(int i=y;i<y+h;i++)
				linedda(w,i,w+10,i+50,0.0005*i,0.001*i,0.00025*i);
			//countdown
			char a[2];
			sprintf(a,"%d",(width-mov)*6/width);
			print_sentence((x+w)/2,y+h/2,a,50,0,1,0);
			colorPick();
			}
			void onMouseOver(){
				//for all inbuilt objs
				if(distortEnable!=0&&mousedrag[0]>x&&mousedrag[0]<w&&mousedrag[1]>y&&mousedrag[0]<y+h)
					if((mouseX>x)&&(mouseX<w)&&(mouseY>y)&&(mouseY<y+h))//if within box
						addInbuiltObject();
			//NOTE that width of the menu is 50
				if((mouseX<x)&&(mouseX>x-50)&&(mouseY>y)&&(mouseY<y+h))
					showMenu();
				//for rectange
				if(mouseclick[0]<x-50+45&&mouseclick[0]>x-50-5&&mouseclick[1]>y+h-10-30&&mouseclick[0]<y+h-10){
					obstacleBuffer.clear();
					if((mouseX>x)&&(mouseX<w)&&(mouseY>y)&&(mouseY<y+h))//if within box
						distortEnable=1;
				}
				//for circle
				else if(mouseclick[0]<x-50+45&&mouseclick[0]>x-50-5&&mouseclick[1]>y+h-10-30-60&&mouseclick[0]<y+h-10-40){
					obstacleBuffer.clear();
					if((mouseX>x)&&(mouseX<w)&&(mouseY>y)&&(mouseY<y+h))//if within box
						distortEnable=2;
				}
				//this stores to a file
				else if(mouseclick[0]<x-50+45&&mouseclick[0]>x-50-5&&mouseclick[1]>y+h-10-30-60-30&&mouseclick[0]<y+h-10-40){
					obstacleBuffer.storeToFile();
					//change some parameters to prevent it from repeating
					mouseclick[0]=-1;
				}
				//this gets from a file
				else if(mouseclick[0]<x-50+45&&mouseclick[0]>x-50-5&&mouseclick[1]>y+h-10-30-60-30-30&&mouseclick[0]<y+h-10-40){
					obstacleBuffer.getFromFile();
					//change some parameters to prevent it from repeating
					mouseclick[0]=-1;
				}
			}
			void showMenu(){
				//main panel
				for(int i=0;i<h+2;i++)
                        		linedda(x-50,y+i,x-2,y+i,0.7+i*0.001,0.35+i*0.001,0.1+i*0.001);
				//for rectangle
				for(int i=y+h-10-30;i<y+h-10;i++)
					linedda(x-50+5,i,x-50+45,i,0.01*(i-y-h+10+30),0.01*(i-y-h+10+30),0.01*(i-y-h+10+30));
				//for circle
				circle(x-50/2,y+h-10-30-40,20,0,0,0);
				//this if for S
				print_thick_sentence(x-50+20,y+h-10-30-40-20-30,"S",4,5,0,0,0);
				//this is for R
				print_thick_sentence(x-50+20,y+h-10-30-40-20-30-30,"R",4,5,0,0,0);
			}
			void addInbuiltObject(){
				obstacleBuffer.clear();
				switch(distortEnable){
					case 1:;//for rectangle
						obstacleBuffer.addPixel(mouseclick[0],height-mouseclick[1]);
						//top left to right
						for(int i=mouseclick[0];i<mousedrag[0];i++)
							obstacleBuffer.addPixel(i,height-mouseclick[1]);
						//top right to bottom
						//this has to be done twice coz we dont know whether mouseclick or mousedrag is larger
						for(int i=mouseclick[1];i<mousedrag[1];i++)
							obstacleBuffer.addPixel(mousedrag[0],height-i);
						for(int i=mouseclick[1];i>mousedrag[1];i--)
							obstacleBuffer.addPixel(mousedrag[0],height-i);
						//right bottom to left
						for(int i=mousedrag[0];i>mouseclick[0];i--)
							obstacleBuffer.addPixel(i,height-mousedrag[1]);
						//bottom left to top
						//this has to be done twice coz we dont know whether mouseclick or mousedrag is larger
						for(int i=mousedrag[1];i>mouseclick[1];i--)
							obstacleBuffer.addPixel(mouseclick[0],height-i);
						for(int i=mousedrag[1];i<mouseclick[1];i++)
							obstacleBuffer.addPixel(mouseclick[0],height-i);
						if(mouseclick[0]!=obstacleBuffer.CUSTOM_OBSTACLE[0].x&&mouseclick[1]!=obstacleBuffer.CUSTOM_OBSTACLE[1].y)
							distortEnable=0;
						break;
					case 2://for circle
						obstacleBuffer.addPixel(mouseclick[0],height-mouseclick[1]);
						circledraw=1;
						circle((mouseclick[0]+mousedrag[0])/2,(mouseclick[1]+mousedrag[1])/2,sqrt((mouseclick[0]-mousedrag[0])*(mouseclick[0]-mousedrag[0])+(mouseclick[1]-mousedrag[1])*(mouseclick[1]-mousedrag[1])),1,1,1);
						circledraw=0;
						break;
				}
			}
			void colorPick(){
				//red panel
				obstaclE.obstacleColor=pickColor;
				for(int i=x;i<w-30;i++){
					if((mousedrag[0]==i)&&(mousedrag[1]<y-5)&&(mousedrag[1]>y-15)){
						pickColor.red=1.0*i/(w-30);
						pickColorIndicatorR.x=i;
						pickColorIndicatorR.y=y-10;
					}
					linedda(i,y,i,y-20,1.0*i/(w-30),0,0);
				}
				//green panel
				for(int i=x;i<w-30;i++){
					if((mousedrag[0]==i)&&(mousedrag[1]<y-25)&&(mousedrag[1]>y-35)){
						pickColor.green=1.0*i/(w-30);
						pickColorIndicatorG.x=i;
						pickColorIndicatorG.y=y-30;
					}
					linedda(i,y-20,i,y-40,0,1.0*i/(w-30),0);
				}
				//blue panel
				for(int i=x;i<w-30;i++){
					if((mousedrag[0]==i)&&(mousedrag[1]<y-45)&&(mousedrag[1]>y-55)){
						pickColor.blue=1.0*i/(w-30);
						pickColorIndicatorB.x=i;
						pickColorIndicatorB.y=y-50;
					}
					linedda(i,y-40,i,y-60,0,0,1.0*i/(w-30));
				}
				//draw color indicators
					circle(pickColorIndicatorR.x,pickColorIndicatorR.y,2,1,1,1);
					circle(pickColorIndicatorG.x,pickColorIndicatorG.y,2,1,1,1);
					circle(pickColorIndicatorB.x,pickColorIndicatorB.y,2,1,1,1);
				//output panel
				for(int i=w-30;i<w;i++)
					linedda(i,y,i,y-60,pickColor.red-0.001*i,pickColor.green-0.001*i,pickColor.blue-0.001*i);
				for(int i=y-60;i<y;i++)
					linedda(w,i,w+10,i+50,pickColor.red,pickColor.green,pickColor.blue);
			}
	};
};
//parse from  DISPLAY
void displayparser(){
	FILE *fp;
	char ch;
	int a,b,c,d,e;
	float fa,fb,fc;
	//fp=fopen("~/.glutrix/DISPLAY","r");
	fp=fopen("DISPLAY","r");
	//char int int int int float float float int
	while(fscanf(fp,"%c %d %d %d %d %f %f %f %d",&ch,&a,&b,&c,&d,&fa,&fb,&fc,&e)!=EOF){
		switch(ch){
			case 'l':
			linedda(a,b,c,d,fa,fb,fc);break;
			case 'c':
			circle(a,b,c,fa,fb,fc);break;
			case 102:
			face(a,b,c,d,fa,fb,fc,0.0);break;
	
		}
	}
	fclose(fp);
}
//this function gets from segment file SEGMENT
void segmentparser(){
	FILE *f;
	char ch;
	int tx,ty;
	float sx,sy,angle;
	//f=fopen("~/.glutrix/SEGMENT","r");
	f=fopen("SEGMENT","r");
	fscanf(f,"%d %d %f %f %f",&tx,&ty,&sx,&sy,&angle);
	//draw here
	
	linedda((tx-sx*6),(ty-sy*1),(tx-sx*6),(ty+sy*1),1,1,1);
	linedda((tx-sx*6),(ty-sy*1),(tx+sx*6),(ty-sy*1),1,1,1);
	linedda((tx-sx*6),(ty+sy*1),(tx+sx*6),(ty+sy*1),1,1,1);
	linedda((tx+sx*6),(ty-sy*1),(tx+sx*6),(ty+sy*1),1,1,1);
	fclose(f);
}
//this executes segment file and updates segment file SEGMENT
void segmentupdater(int tx,int ty,float sx,float sy,float angle){
	char string[100];
	sprintf(string,"echo '%d %d %f %f %f'>SEGMENT",tx,ty,sx,sy,angle);
	system(string);
}
