#include<iostream>
#include<stdio.h>
#include<math.h>
#include"basicfunctions.h"
void crust(int xa,int ya,int xb,int yb,int layers,float R,float G,float B){
	while(layers>0){
		linebre_junk(xa,ya,xb,yb,R,G,B);
		layers--;
	}
}
