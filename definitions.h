//characters.cpp
void draw_character(int x,int y,char key,int size,float R,float G,float B);
void print_sentence(int x,int y,char* sentence, int size,float R,float G,float B);
void print_thick_sentence(int x,int y,char* sentence, int size,int thickness,float R,float G,float B);
//basicfunctions.cpp
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
void linedda(int,int,int,int,float,float,float);
//main
void display(void);

