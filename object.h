// loadobj.h: headers for loadobj
//
// 
//
//////////////////////////////////////////////////////////////////////
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string.h>
#include <oslib/oslib.h>

using namespace std;

class Object{

public: 
	int x;
	int y;
	int imgX;
	int imgY;
	int health;
	OSL_IMAGE *image;
	bool isalive;	
	int pctr;

	

	Object(int, int, int, int, int, char*, bool, int);

	void blitObject();
	void setBackground();

};
#endif