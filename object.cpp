// loadobj.c: Blitting a player
//
////////////////////////////////////////////////////////////////////////////
#include <oslib/oslib.h>
#include "object.h"



using namespace std;

Object::Object(int x_coor, int y_coor, int x_len, int y_len, int h, char *imgname, bool ia, int ctr){
	x = x_coor;
	y = y_coor;
	imgX = x_len;
	imgY = y_len;
	health = h;
	isalive = ia;
	pctr = ctr;
	
	OSL_IMAGE *img = oslLoadImageFilePNG(imgname, OSL_IN_RAM | OSL_SWIZZLED, OSL_PF_8888);
	image = img;

}

void Object::blitObject(){
	//image->angle = 45;
	//Object::control();
	oslDrawImageXY(image, x, y);
	
	//oslDrawImage(image);
}

void Object::setBackground(){
	
}

bool Object::control(Object obj){
		quit = false;
	    oslReadKeys();
        //if (osl_keys->held.circle){/**shootChain();playBullet();*/}   
        if((osl_keys->held.right)&&obj.x <= 150){obj.x = obj.x + 1;}      
        if((osl_keys->held.left)&&obj.x > 60){obj.x = obj.x - 1;} 
        if((osl_keys->held.up)&&obj.y > -10){obj.y = obj.y - 5;}  
        if((osl_keys->held.down)&&obj.y < 262){obj.y = obj.y + 5;}
		if (osl_keys->released.cross){

			quit = true;
            //return quit; //oslQuit();
		}
		return quit;
}