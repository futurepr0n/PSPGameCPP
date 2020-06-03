// loadobj.c: Blitting a player
//
////////////////////////////////////////////////////////////////////////////
#include <oslib/oslib.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include "object.h"



Object::Object(int x_coor, int y_coor, int x_len, int y_len, int h, char cha[14], bool ia, int ctr){
	x = x_coor;
	y = y_coor;
	imgX = x_len;
	imgY = y_len;
	health = h;
	isalive = ia;
	pctr = ctr;


	OSL_IMAGE *img = oslLoadImageFilePNG(cha, OSL_IN_RAM | OSL_SWIZZLED, OSL_PF_8888);
	image = img;

}

void Object::blitObject(){
	oslDrawImageXY(image, x, y);
}

void Object::setBackground(){
	
}

