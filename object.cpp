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
	image->angle = 45;
	oslDrawImageXY(image, x, y);
	
	//oslDrawImage(image);
}

void Object::setBackground(){
	
}

