void keyboard(unsigned char key,int m,int n){
	switch(mode){
		case 0://in game over mode reset all the instances and globals
			switch(key){
			case 27:face_y=0;face_dir=1;face_dir_override=0;face_bounce=0;mov=0;mov1=0;movinc=0;drawEnable=1;circledraw=0;mode=1;
			obstacleBuffer.clear();
			obstaclE.clear();
			//reset the normal objects
			normalObj.reset();break;
			}break;
		case 1://aata menu
			break;
		case 2://hege mode
			switch(key){
			case 27: mode=1;break;
			}
		case 3://about mode
			switch(key){
			//exit from the game
			 case 27: mode=1;break;
			}
		case 4://game play mode
			switch(key){
			//esc switches the game to main menu
			 case 27:mode=1;break;
			 //space jump
			 case 32:face_dir=1;if(face_y<350)face_y=350;face_dir_override=1;normalObj.fuel1-=400;break;
			 //case 32:face_dir=0;if(face_y+50<400)face_y+=50;face_dir_override=1;normalObj.fuel1-=400;break;
			 //x missile launch
			 case 120:normalObj.missileLaunch();break;

			}break;
	}
}
void mouse(int button,int state,int x,int y){
	switch(mode){
		case 1:
		switch(button){
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_DOWN){
				printf("%d,%d ",x,y);
				//aata mode
				if(x<800 &&x>500 &&y>height-650 &&y<height-600 )
					mode=4;
				//hege mode
				if(x<800&&x>500&&y>height-550&&y<height-500 )
					mode=2;	
				//about mode
				if(x<800&&x>500 &&y>height-450 &&y<height-400 )
					mode=3;
				//close
				if(x<800&&x>500 &&y>height-350 &&y<height-300 ){
					system("killall mplayer");exit(0);
				}
			}
			break;
		default:break;
		}
		case 4://game screen
		switch(button){
			case GLUT_LEFT_BUTTON:
				//if((state==GLUT_DOWN)&&(drawEnable==1)&&(mode==4)){
				if((state==GLUT_DOWN)&&(mode==4)){
					board.mouseclick[0]=x;
					board.mouseclick[1]=height-y;
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
	}
	glutSwapBuffers();
	fflush(stdout);
}
//stores coordinates of mouse
void hover(int x,int y){
	mouseX=x;mouseY=height-y;
}
//motion function
void draw (int x,int y){
	mouseX=x;mouseY=height-y;
	switch(mode){
		case 4:
		if((drawEnable==1)&&(x>width/10)&&(x<width/3)&&(y<height-300-20)&&(y>height-600)&&(!board.distortEnable))
			obstacleBuffer.addPixel(x,y);
		//for color pick
		board.mousedrag[0]=x;
		board.mousedrag[1]=height-y;
		break;
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
