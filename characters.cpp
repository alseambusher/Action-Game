void draw_character(int x,int y,char key,int size,float R,float G,float B){
	switch(key){
		case 'A':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			break;

		case 'B':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			break;

		case 'C':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			break;

		case 'D':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x,y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x,y-(2*size),R,G,B);
			linedda(x,y+(2*size),x+(2*size),y,R,G,B);
			linedda(x,y-(2*size),x+(2*size),y,R,G,B);			
			break;

		case 'E':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(1*size),y,R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			break;

		case 'F':
			
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x,y,R,G,B);
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			break;

		case 'G':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x,y,x+(2*size),y,R,G,B);
			linedda(x+(2*size),y,x+(2*size),y-(2*size),R,G,B);
			break;

		
		case 'H':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			break;
	
		case 'I':
			linedda(x,y-(2*size),x,y+(2*size),R,G,B);
			linedda(x-(1*size),y-(2*size),x+(1*size),y-(2*size),R,G,B);
			linedda(x-(1*size),y+(2*size),x+(1*size),y+(2*size),R,G,B);
			break;

		case 'J':
			linedda(x,y-(2*size),x,y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x,y-(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x-(2*size),y,R,G,B);
			break;
		
		case 'K':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(1*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(1*size),y-(2*size),R,G,B);
			break;
	
		case 'L':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(1*size),y-(2*size),R,G,B);
			break;

		case 'M':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x,y,R,G,B);
			linedda(x+(2*size),y+(2*size),x,y,R,G,B);
			break;

		case 'N':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y-(2*size),R,G,B);
			break;
		
		case 'O':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			break;

		case 'P':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y,x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);		
			break;

		case 'Q':
			circle(x,y,2*size,R,G,B);
			linedda(x,y,x+(2*size),y-(2*size),R,G,B);
			break;

		case 'R':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y,x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x,y,x+(2*size),y-(2*size),R,G,B);		
			break;	
	
		case 'S':
			linedda(x-(2*size),y,x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x+(2*size),y,x+(2*size),y-(2*size),R,G,B);
			break;

		case 'T':
			linedda(x,y-(2*size),x,y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			break;

		case 'U':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			break;

		case 'V':
			linedda(x-(2*size),y+(2*size),x,y-(2*size),R,G,B);
			linedda(x+(2*size),y+(2*size),x,y-(2*size),R,G,B);
			break;

		case 'W':
			linedda(x-(2*size),y+(2*size),x-(1*size),y-(2*size),R,G,B);
			linedda(x+(2*size),y+(2*size),x+(1*size),y-(2*size),R,G,B);
			linedda(x,y,x-(1*size),y-(2*size),R,G,B);
			linedda(x,y,x+(1*size),y-(2*size),R,G,B);
			break;

		case 'X':
			linedda(x-(2*size),y+(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x+(2*size),y+(2*size),x-(2*size),y-(2*size),R,G,B);
			break;

		case 'Y':
			linedda(x-(2*size),y+(2*size),x,y,R,G,B);
			linedda(x+(2*size),y+(2*size),x,y,R,G,B);
			linedda(x,y-(2*size),x,y,R,G,B);
			break;

		case 'Z':
			linedda(x-(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			break;

		case '0':
			ellipse(x,y,2*size,2*size,R,G,B,0);
			linedda(x-(1*size),y-(1*size),x+(1*size),y+(1*size),R,G,B);
			break;

		case '1':
			linedda(x,y-(2*size),x,y+(2*size),R,G,B);
			break;

		case '2':
			linedda(x+(2*size),y,x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x-(2*size),y,x-(2*size),y-(2*size),R,G,B);
			break;

		case '3':
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			break;

		case '4':
			linedda(x-(2*size),y,x+1*size,y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x+1*size,y-(2*size),x+size,y+(2*size),R,G,B);
			break;

		case '5':
			linedda(x-(2*size),y,x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(1*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x+(2*size),y,x+(2*size),y-(2*size),R,G,B);
			break;

		case '6':
			linedda(x-(2*size),y-(2*size),x-(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x+(2*size),y,x+(2*size),y-(2*size),R,G,B);
			break;

		case '7':
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x+(2*size),y+(2*size),x-(1*size),y-(2*size),R,G,B);
			break;
	
		case '8':
			ellipse(x,y-(1*size),2*size,size,R,G,B,0);
			ellipse(x,y+(1*size),2*size,size,R,G,B,0);
			break;
		
		case '9':
			linedda(x+(2*size),y-(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x-(2*size),y-(2*size),x+(2*size),y-(2*size),R,G,B);
			linedda(x-(2*size),y,x+(2*size),y,R,G,B);
			linedda(x-(2*size),y,x-(2*size),y+(2*size),R,G,B);
			break;
		case '?':
			linedda(x-(2*size),y+(2*size),x+(2*size),y+(2*size),R,G,B);
			linedda(x,y-(1.25*size),x,y,R,G,B);
			//linedda(x,y-(2.5*size),x,y-(3*size),R,G,B);
			ellipse(x,y-(3*size),size/2,size/2,R,G,B,1);
			linedda(x+(2*size),y,x+(2*size),y+(2*size),R,G,B);
			linedda(x-(0.5*size),y,x+(2*size),y,R,G,B);
			break;
	
		default:
			break;


	}
}
void print_sentence(int x,int y,char* sentence, int size,float R,float G,float B){
	int i;
	for(i=0;i<strlen(sentence);i++){
		draw_character(x,y,sentence[i],size,R,G,B);
		x+=6*size;
	}
}
void print_thick_sentence(int x,int y,char* sentence, int size,int thickness,float R,float G,float B){
	while(thickness>0){
		print_sentence(x+thickness,y+thickness,sentence, size,R,G,B);
		thickness--;
	}
}
