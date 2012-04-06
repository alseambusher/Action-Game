#include"pixel.h"
using namespace std;
Color getPixel(int x,int y){
        Color c;
        float pixels[4];
	float temp;
        //glReadPixels(0,100,1,1,GL_RGB,GL_UNSIGNED_BYTE,(void*)pixels);
        glReadPixels(x,y,1,1,GL_RGBA,GL_FLOAT,pixels);
	temp=round(pixels[0]*100);
	c.red=(float)temp/100;
	temp=round(pixels[1]*100);
	c.green=(float)temp/100;
	temp=round(pixels[2]*100);
	c.blue=(float)temp/100;
        return c;
}
void setPixel(int x, int y, Color c){
    glutSwapBuffers();
    glColor3f(c.red, c.green, c.blue);
	printf("%d,%d ",x,y);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    //glFlush();
}
int iscolor(Color one,Color two){
	if((one.red==two.red)&&(one.green=two.green)&&(one.blue==two.blue))
		return 1;
	else
		return 0;
}
vector<points>FILL_PIXEL;
void Boundary_fill_inner(int x,int y,Color thisColor,Color boundary){
    glutSwapBuffers();
    	Color nextpixel=getPixel(x,y);
	if((!iscolor(nextpixel,thisColor))&&(!iscolor(nextpixel,boundary))){
//    if((!((nextpixel.red==boundary.red)&&(nextpixel.blue==boundary.blue)&&(nextpixel.green==boundary.green))) && (!((nextpixel.red==thisColor.red)&& (nextpixel.blue==thisColor.blue)&& (nextpixel.green==thisColor.green)))){
	setPixel(x,y,thisColor);
	//glVertex2f(x,y);
    	//glBegin(GL_POINTS);
    	//glVertex2f(x,y);
    	//glEnd();
	//struct points p;
	//p.x=x;p.y=y;
	//FILL_PIXEL.push_back(p);
        Boundary_fill_inner((x+1),y,thisColor,boundary);
        Boundary_fill_inner((x-1),y,thisColor,boundary);
        Boundary_fill_inner(x,(y+1),thisColor,boundary);
        Boundary_fill_inner(x,(y-1),thisColor,boundary);
    }
	else
		printf("boundary reached\n");

}
void Boundary_fill(int x,int y,Color thisColor,Color boundary){
	Boundary_fill_inner(x,y,thisColor,boundary);
	//int m;
	//glBegin(GL_POINTS);
	//for(m=0;m<FILL_PIXEL.size();m++)
	//	glVertex2f(FILL_PIXEL[m].x,FILL_PIXEL[m].y);
	//glEnd();
	//FILL_PIXEL.clear();
}
void floodfill_inner(int x,int y,Color fillColor){
	Color c=getPixel(x,y);
	if((c.red==0.0)&&(c.green==0.6)&&(c.blue==1.0)){
		struct points p;
		p.x=x;p.y=y;
		printf("%f,%f,%f ",c.red,c.green,c.blue);
		//printf("%d,%d ",p.x,p.y);
		FILL_PIXEL.push_back(p);
//		setPixel(x,y,fillColor);
		floodfill_inner(x+1,y,fillColor);	
		floodfill_inner(x-1,y,fillColor);	
		floodfill_inner(x,y+1,fillColor);	
		floodfill_inner(x,y-1,fillColor);	
		
	}
}
void floodfill(int x,int y,Color fillColor){
	floodfill_inner(x,y,fillColor);
	int m=0;
	glBegin(GL_POINTS);
	//for(m=0;m<FILL_PIXEL.size()-1;m++){
		//glVertex2f(FILL_PIXEL[m].x,FILL_PIXEL[m].y);
		//printf("%d,%d ",FILL_PIXEL[m].x,FILL_PIXEL[m].y);
	//}
	glEnd();
	FILL_PIXEL.clear();
	glutSwapBuffers();
}
