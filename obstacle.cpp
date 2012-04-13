class Obstacle{
public:
vector<points>CUSTOM_OBSTACLE;
int minY;unsigned int i;
        void addPixel(int x,int y){
                struct points p;
                p.x=x;p.y=height-y;
                CUSTOM_OBSTACLE.push_back(p);
                if(height-y<minY)
                        minY=height-y;
        }
        void drawObstacle(int xinc,int yinc,bool isFinal){
	        if(CUSTOM_OBSTACLE.size()>1){
        	        for(i=0;i<CUSTOM_OBSTACLE.size()-1;i++)
                	        linedda(CUSTOM_OBSTACLE[i].x+xinc,CUSTOM_OBSTACLE[i].y+yinc,CUSTOM_OBSTACLE[i+1].x+xinc,CUSTOM_OBSTACLE[i+1].y+yinc,1,1,1);
			if(isFinal){
                	        linedda(CUSTOM_OBSTACLE[0].x+xinc,CUSTOM_OBSTACLE[0].y+yinc,CUSTOM_OBSTACLE[i].x+xinc,CUSTOM_OBSTACLE[i].y+yinc,1,1,1);
				fill(xinc,yinc);
			}
        	}
	}
	void clear(){
		CUSTOM_OBSTACLE.clear();
	}
	void fill(int xinc,int yinc){
	}
	bool isCollision(int xinc,int yinc){
		unsigned int j,k;
	        if(CUSTOM_OBSTACLE.size()>1)
			for(j=0;j<CUSTOM_OBSTACLE.size()-1;j++)
				for(k=0;k<FACE_COORDINATES.size()-1;k++)
					if((abs(CUSTOM_OBSTACLE[j].x+xinc-FACE_COORDINATES[k].x)<5)&&(abs(CUSTOM_OBSTACLE[j].y+yinc-FACE_COORDINATES[k].y)<5))
						return 1;
		return 0;
	}
};


