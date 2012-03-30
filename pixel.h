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
