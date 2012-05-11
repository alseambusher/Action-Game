class Obstacle{
public:
vector<points>CUSTOM_OBSTACLE;//stores points of obstacle
int minY,maxY,minX,maxX;unsigned int i;
Color obstacleColor;
        void addPixel(int x,int y){
                struct points p;
                p.x=x;p.y=height-y;
                CUSTOM_OBSTACLE.push_back(p);
                if(height-y<minY)
                        minY=height-y;
		if(x>maxX)
			maxX=x;
                if(height-y>maxY)
                        maxY=height-y;
		if(x<minX)
			minX=x;
        }
        void drawObstacle(int xinc,int yinc,bool isFinal){
	        if(CUSTOM_OBSTACLE.size()>1){
			if(isFinal){
        	        	for(i=0;i<CUSTOM_OBSTACLE.size()-1;i++)
                	        	linedda(CUSTOM_OBSTACLE[i].x+xinc,CUSTOM_OBSTACLE[i].y+yinc,CUSTOM_OBSTACLE[i+1].x+xinc,CUSTOM_OBSTACLE[i+1].y+yinc,obstacleColor.red,obstacleColor.green,obstacleColor.blue);
                	        linedda(CUSTOM_OBSTACLE[0].x+xinc,CUSTOM_OBSTACLE[0].y+yinc,CUSTOM_OBSTACLE[i].x+xinc,CUSTOM_OBSTACLE[i].y+yinc,obstacleColor.red,obstacleColor.green,obstacleColor.blue);
				//fill(xinc,yinc);
			}
			else{
        	        	for(i=0;i<CUSTOM_OBSTACLE.size()-1;i++)
                	        	linedda(CUSTOM_OBSTACLE[i].x+xinc,CUSTOM_OBSTACLE[i].y+yinc,CUSTOM_OBSTACLE[i+1].x+xinc,CUSTOM_OBSTACLE[i+1].y+yinc,1,1,1);
			}
        	}
	}
	//clears vector 
	void clear(){
                minY=1000000;
                minX=1000000;
                maxX=0;
                maxY=0;
		CUSTOM_OBSTACLE.clear();
	}
	//fills obstacle
	void fill(int xinc,int yinc){
		int sort[50],m,temp;
		for(int i=0;i<CUSTOM_OBSTACLE.size();i++){
			m=0;
			for(int j=0;j<CUSTOM_OBSTACLE.size();j++)
				//if((i!=j)&&(CUSTOM_OBSTACLE[i].y==CUSTOM_OBSTACLE[j].y)){
				if(abs(CUSTOM_OBSTACLE[i].y-CUSTOM_OBSTACLE[j].y)<5){
					sort[m++]=CUSTOM_OBSTACLE[j].x;
				}
			//sorting
			for(int k=0;k<m;k++)
				for(int l=k;l<m;l++){
					if(sort[k]>sort[l]){
						temp=sort[k];
						sort[k]=sort[l];
						sort[l]=sort[k];
					}
				}
			for(int k=0;k<m-1;k+=2)
                	       	linedda(sort[k]+xinc,CUSTOM_OBSTACLE[i].y+yinc,sort[k+1]+xinc,CUSTOM_OBSTACLE[i].y+yinc,obstacleColor.red,obstacleColor.green,obstacleColor.blue);
		}
	}
	//checks if face coordinates and obstacle coordinates overlap
	bool isCollision(int xinc,int yinc){
		unsigned int j,k;
	        if(CUSTOM_OBSTACLE.size()>1)
			for(j=0;j<CUSTOM_OBSTACLE.size()-1;j++)
				for(k=0;k<FACE_COORDINATES.size()-1;k++)
					if((abs(CUSTOM_OBSTACLE[j].x+xinc-FACE_COORDINATES[k].x)<5)&&(abs(CUSTOM_OBSTACLE[j].y+yinc-FACE_COORDINATES[k].y)<5))
						return 1;
		return 0;
	}
	void storeToFile(){
		system("rm DYNAMIC");
		char command[100];
		if(CUSTOM_OBSTACLE.size()>1){
		for(int i=0;i<CUSTOM_OBSTACLE.size()-1;i++){
			//if((CUSTOM_OBSTACLE[i].x==0)&&(CUSTOM_OBSTACLE[i].y==0)
				//return;
			//sprintf(command,"echo '%d %d'>>~/.glutrix/DYNAMIC",CUSTOM_OBSTACLE[i].x,CUSTOM_OBSTACLE[i].y);
			sprintf(command,"echo '%d %d'>>DYNAMIC",CUSTOM_OBSTACLE[i].x,CUSTOM_OBSTACLE[i].y);
			system(command);
		}
		}
	}
	void getFromFile(){
		clear();
		FILE *f;
		f=fopen("DYNAMIC","r");
		int x,y;
		if(f!=NULL){
		while(fscanf(f,"%d %d",&x,&y)!=EOF){
			addPixel(x,height-y);
		}
		fclose(f);
	}
	}
};


