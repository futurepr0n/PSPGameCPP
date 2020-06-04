// loadobj.c: Blitting a player
//
////////////////////////////////////////////////////////////////////////////
#include <oslib/oslib.h>
#include "object.h"



using namespace std;

Object::Object(int x_coor, int y_coor, int x_len, int y_len, int h, char *imgname, bool ia, int ctr, int a){
	x = x_coor;
	y = y_coor;
	imgX = x_len;
	imgY = y_len;
	health = h;
	isalive = ia;
	pctr = ctr;
	angle = a;
	
	OSL_IMAGE *img = oslLoadImageFilePNG(imgname, OSL_IN_RAM | OSL_SWIZZLED, OSL_PF_8888);
	image = img;

}

void Object::blitObject(){
	image->angle;
	//Object::control();
	oslDrawImageXY(image, x, y);
	
	//oslDrawImage(image);
}

void Object::setBackground(){
	
}

void Object::control(){
	    oslReadKeys();
        //if (osl_keys->held.circle){/**shootChain();playBullet();*/}   
        if((osl_keys->held.right)&&x <= 150){x = x + 1;}      
        if((osl_keys->held.left)&&x > 60){x = x - 1;} 
        if((osl_keys->held.up)&&y > -10){
			y = y - 5;
			if(angle < 45)
				angle= angle + 5;	
		}  
        if((osl_keys->held.down)&&y < 262){
			y = y + 5;
			if(angle > -45)
				angle = angle - 5;
		}
		if (osl_keys->released.cross){

			quit = true;
            //return quit; //oslQuit();
		}
		//return quit;
}