// loadobj.c: Blitting a player
//
////////////////////////////////////////////////////////////////////////////
#include <oslib/oslib.h>
#include "object.h"

#define KEYUP 0
#define KEYDOWN 1

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
	oslSetImageRotCenter(image);
	image->angle = angle;
	//Object::control();
	oslDrawImageXY(image, x, y);
	
	//oslDrawImage(image);
}

void Object::setBackground(){
	
}

int Object::control(){
	    oslReadKeys();
		int c = KEYUP;
        //if (osl_keys->held.circle){/**shootChain();playBullet();*/}   
        if((osl_keys->held.right)&&x <= 150){
			x = x + 1;
			c = KEYDOWN;
			}      
        if((osl_keys->held.left)&&x > 60){
			x = x - 1;
			c = KEYDOWN;
			} 
        if((osl_keys->held.up)&&y > 10){
			y--;
			if(angle > -23)
				angle--;	
			c = KEYDOWN;
		}  			
        if((osl_keys->held.down)&&y < 262){
			y++;
			if(angle<23)
				angle++;
			c = KEYDOWN;
		}

	/**	if((osl_keys->released.up)&&angle < 0)
			angle++;		
		if((osl_keys->released.down)&& angle > 0)
				angle--;
 */
		if (osl_keys->released.cross){

			quit = true;
            //return quit; //oslQuit();
		}
		return c;
}