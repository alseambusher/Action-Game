void draw_character(int x,int y,char key,int size,float R,float G,float B){
	switch(key){
		case 'A':
			linedda(x,y,x,y+(4*size),R,G,B);
			linedda(x+(4*size),y,x+(4*size),y+(4*size),R,G,B);
			linedda(x,y+(4*size),x+(4*size),y+(4*size),R,G,B);
			linedda(x,y+(2*size),x+(4*size),y+(2*size),R,G,B);
		break;
	}
}
void print_sentence(int x,int y,char* sentence, int size,float R,float G,float B){
	int i;
	for(i=0;i<strlen(sentence);i++){
		draw_character(x,y,sentence[i],size,R,G,B);
		x+=5*size;
	}
}
