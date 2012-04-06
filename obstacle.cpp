class Obstacle{
public:
vector<points>CUSTOM_OBSTACLE;
int minY;int i;
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
				fill();
			}
        	}
	}
	void clear(){
		CUSTOM_OBSTACLE.clear();
	}
	void fill(){
	}
	bool isCollision(){
		int j,k;
		for(j=0;j<CUSTOM_OBSTACLE.size()-1;i++)
			for(k=0;k<FACE_COORDINATES.size()-1;i++)
				if((CUSTOM_OBSTACLE[j].x==FACE_COORDINATES[k].x)&&(CUSTOM_OBSTACLE[j].y==FACE_COORDINATES[k].y))
					return 1;
				else
					return 0;
	}
};


