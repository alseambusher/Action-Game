//pixel.h
//color definition
struct Color{
    float red, green, blue;
};
Color getPixel(int,int);
void setPixel(int,int,Color);
void Boundary_fill(int,int,Color,Color);
void Boundary_fill_main(int,int,Color,Color);
int iscolor(Color, Color);
void floodfill(int,int,Color);
class screenFilter{
public:
	vector<Color>PIXELS;
	void getAll(){
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
				PIXELS.push_back(getPixel(j,i));
	}
	void plotAll(float Rinc,float Ginc,float Binc){
		glBegin(GL_POINTS);
		int k=0;
		for(int i=0;i<height;i++,k++)
			for(int j=0;j<width;j++,k++){
				if(k<PIXELS.size()){
					glColor3f(PIXELS[k].red+Rinc,PIXELS[k].green+Ginc,PIXELS[k].blue+Binc);
					glVertex2f(j,i);
				}
			}
		glEnd();
		glutSwapBuffers();
	}
	void getAndPlot(float Rinc,float Ginc,float Binc){
		getAll();
		plotAll(Rinc,Ginc,Binc);
	}
	void plotOnly(float Rinc,float Ginc,float Binc){
		Color temp;
		glBegin(GL_POINTS);
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++){
				temp=getPixel(j,i);
				glColor3f(temp.red,temp.green,temp.blue);
				//glColor3f(temp.red+Rinc,temp.green+Ginc,temp.blue+Binc);
				glVertex2f(j,i);
			}
		glEnd();
		glutSwapBuffers();
	}
	void writeToFile(char* fileName){
	}
	void clear(){
		PIXELS.clear();
	}
	void makeConstantColor(float R,float G,float B){
		for(int i=0;i<height;i++)
			linedda(0,i,width,i,R,G,B);
	}
};
