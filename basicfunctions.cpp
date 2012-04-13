#include"basicfunctions.h"
using namespace std;
//this contains all the end points of the face
class face_coordinates{
public:
	int x,y;
	void add(int a,int b){
		x=a;y=b;
	}
	void rotate(float angle){
	}
};
vector<face_coordinates>FACE_COORDINATES;
//dda line 
void linedda(int xa,int ya,int xb,int yb,float colorR,float colorG,float colorB){
	glColor3f(colorR,colorG,colorB);
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
void linebre_junk(int xa,int ya,int xb,int yb,float colorR,float colorG,float colorB){
	//srand(time(NULL));
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
	glVertex3f(x,y+(rand()%5),1);
	while(x<xEnd){
		x++;
		if(p<0)
			p+=2*dy;
		else{
			y++;
			p+=2*(dy-dx);
		}
		glVertex3f(x,y+(rand()%5),1);
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
	glVertex3f(xcenter+x,ycenter+y,1);
	glVertex3f(xcenter+x,ycenter-y,1);
	glVertex3f(xcenter-x,ycenter+y,1);
	glVertex3f(xcenter-x,ycenter-y,1);
	glVertex3f(xcenter+y,ycenter+x,1);
	glVertex3f(xcenter+y,ycenter-x,1);
	glVertex3f(xcenter-y,ycenter+x,1);
	glVertex3f(xcenter-y,ycenter-x,1);
	p=1-radius;
	while(x<y){
		x++;
		if(p<0)
			p+=2*x+1;
		else{
			y--;
			p+=2*(x-y)+1;
		}
		glVertex3f(xcenter+x,ycenter+y,1);
		glVertex3f(xcenter+x,ycenter-y,1);
		glVertex3f(xcenter-x,ycenter+y,1);
		glVertex3f(xcenter-x,ycenter-y,1);
		glVertex3f(xcenter+y,ycenter+x,1);
		glVertex3f(xcenter+y,ycenter-x,1);
		glVertex3f(xcenter-y,ycenter+x,1);
		glVertex3f(xcenter-y,ycenter-x,1);
	}
	glEnd();
}
//midpoint ellipse algorithm
void ellipse(int xcenter,int ycenter,int Rx,int Ry,float colorR,float colorG,float colorB){
	glColor3f(colorR,colorG,colorB);
	glBegin(GL_POINTS);
	int p,px,py,x,y;
	int Rx2=Rx*Rx;
	int Ry2=Ry*Ry;
	int twoRx2=2*Rx2;
	int twoRy2=2*Ry2;
	x=0;y=Ry;
	glVertex3f(xcenter+x,ycenter+y,1);
	glVertex3f(xcenter+x,ycenter-y,1);
	glVertex3f(xcenter-x,ycenter+y,1);
	glVertex3f(xcenter-x,ycenter-y,1);
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
		glVertex3f(xcenter+x,ycenter+y,1);
		glVertex3f(xcenter+x,ycenter-y,1);
		glVertex3f(xcenter-x,ycenter+y,1);
		glVertex3f(xcenter-x,ycenter-y,1);
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
		glVertex3f(xcenter+x,ycenter+y,1);
		glVertex3f(xcenter+x,ycenter-y,1);
		glVertex3f(xcenter-x,ycenter+y,1);
		glVertex3f(xcenter-x,ycenter-y,1);
	}
	glEnd();
}
int face_rotate(int xc,int yc,int coordinate1,int coordinate2,int type,float angle){
//xc=0;yc=0;	
	if(type==1){
		if(face_dir_override==1){
			//return round(xc+(coordinate1-xc)*cos(angle)-(coordinate2-yc)*sin(angle));
	//		return coordinate1+40*cos(angle)-50*sin(angle);
			return coordinate1;
		}
		else
			return coordinate1;
	}
	else{
		if(face_dir_override==1){
			//return round(yc+sin(angle)*(coordinate1-xc)+cos(angle)*(coordinate2-yc));
			//return coordinate2+sin(angle)*(coordinate1)+cos(angle)*(coordinate2);
	//		return coordinate2+sin(angle)*40+cos(angle)*50;
			return coordinate2;
		}
		else
			return coordinate2;
	}
}
void face(int xcenter,int ycenter,int Rx,int Ry,float colorR,float colorG,float colorB){
	FACE_COORDINATES.clear();
	face_coordinates FACE;
	glColor3f(colorR,colorG,colorB);
	int p,px,py,x,y;
	int Rx2=Rx*Rx;
	int Ry2=Ry*Ry;
	int twoRx2=2*Rx2;
	int twoRy2=2*Ry2;
	x=0;y=Ry;
	float angle=0;
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
//obstacles are written here
void obstacle(int x,int y,int type){
	int i;
	if(type==0){
		for(i=0;i<160;i++)
			linebre(x,y+i,x+100,y+i,0.7,0.35+(i*0.001),0.1+(i*0.001));	
		//this is for upper part	
		linebre_junk(x,y+i,x+100,y+i,0.5,0.35+(i*0.001),0.1+(i*0.001));	
		linebre_junk(x,y+i,x+100,y+i,0.5,0.35+(i*0.001),0.1+(i*0.001));	
			//linebre(x,y+i,x+100,y+i,1.0,0.7+(i*0.005),0.5+(i*0.002));	
	}
	if(type==1){
		for(i=0;i<60;i++)
			linebre(x,y+i,x+300,y+i,1.0,0.7+(i*0.005),0.5+(i*0.002));	
		linebre_junk(x,y+i,x+300,y+i,1.0,0.7+(i*0.001),0.5+(i*0.001));	
		linebre_junk(x,y+i,x+300,y+i,1.0,0.7+(i*0.001),0.5+(i*0.001));	
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
		face(x-25,y+70+30,50,50,0.0,1.0,0.0);
		face(x+35+25,y+70+30,50,50,0.0,1.0,0.0);
		face(x+17,y+70+70,50,50,0.0,1.0,0.0);
	
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
void background(int x,int y,int type)
{
	int i;
	switch(type)
	{
	default: //coniferous tree
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
	
	}

}
class normalObjects{
public:
	int points1,points2,health;
	bool shieldEnable;
	Color healthColor;
	void reset(){
		points1=0;points2=0;health=100;
		healthColor.red=0;healthColor.blue=0;healthColor.green=1;
		shieldEnable=1;
	}
	void ground(int h){
		for(int i=0;i<h;i++)
                	linebre(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
        //this is for grass
       	//linedda(i,100,i,250+abs(50*sin(i/rand()%100)),154.0/255,205.0/255,50.0/255);
        //linebre_junk(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
        //linebre_junk(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
        //linebre_junk(0,i,width,i,0.7,0.35+(i*0.002),0.1+(i*0.002));
        //linebre_junk(0,i-1,width,i,0.0,0.90+(i*0.002),0.0+(i*0.002));
        //linebre_junk(0,i-1,width,i,0.5,0.90+(i*0.002),0.0+(i*0.002));
        //linebre_junk(0,i-1,width,i,0.5,0.90+(i*0.002),0.0+(i*0.002));
        //linebre_junk(0,i-1,width,i,0.0,0.90+(i*0.002),0.0+(i*0.002));
        //grass ends here
	}
	void grassField(int h){
        	for(int i=0;i<h;i++)
                	linedda(0,100+i,width,100+i,154.0/255,205.0/255,50.0/255);
	}
	void Face(){
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
		if(shieldEnable){
			circle(1100,140+face_y-face_bounce,100,33/255,99/255,181/255);
			circle(1100,140+face_y-face_bounce,90,33/255,99/255,181/255);
			circle(1100,140+face_y-face_bounce,70,33/255,99/255,181/255);
		}
	}
	//TODO implement faceblast
	void FaceBlast(){
	}
	void simpleSetup(){
		ground(100);
		grassField(150);
	}
	void healthPoints(){
		for(int i=width-10;i>(health-170*health)/100+width-180;i--)
			linedda(i,height-60,i,height-90,healthColor.red,healthColor.green,healthColor.blue);
		//TODO print_sentence(width-180,height-60,itoa(health),5,1,1,1);
        	char a[10];
        	strcpy(a,"AAAAAAA");
        	print_sentence(10,height-30,a,5,1,1,1);
        	print_sentence(width-180,height-30,a,5,1,1,1);
        	print_sentence(width/2-40,height-30,a,5,1,1,1);
	}
	//TODO make countdown,speed level
	void clock(){
        	//print_sentence(width/2-40,height-30,itoa(width-mov),5,1,1,1);
	}
	class drawingBoard{
	public:
		int x,y,h,w;
		void draw(){
			for(int i=0;i<h;i++)
                        	linedda(x,y+i,w,y+i,0,0+(i*0.003),0);
               			linedda(x,y,x,y+h,0,0,0);
                		linedda(x-1,y,x-1,y+h,0,1,0);
                		linedda(x,y+h,w,y+h,0,0,0);
                		linedda(x,y+h+1,w,y+h+1,0,1,0);
			}
			bool onMouseOver(){
		//NOTE that width of the menu is 20
				if((mouseX<x)&&(mouseX>x-50)&&(mouseY>y)&&(mouseY<y+h))
					return 1;
				else
					return 0;
			}
			void showMenu(){
				for(int i=0;i<h+2;i++)
                        		linedda(x-50,y+i,x-2,y+i,0.7+i*0.001,0.35+i*0.001,0.1+i*0.001);
			}
	};
};
