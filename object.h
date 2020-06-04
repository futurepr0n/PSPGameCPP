// loadobj.h: headers for loadobj
//
// 
//
//////////////////////////////////////////////////////////////////////
#ifndef _OBJECT_H_
#define _OBJECT_H_

//#include <iostream>
#include <string>
#include <oslib/oslib.h>

#define bgimg "bsg_title.png"
#define playerimg "vipersm.png"


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

	//char *bgimg = "bsg_title.png";
	//char *playerimg = "vipersm.png";

	

	Object(int, int, int, int, int, char*, bool, int);

	void blitObject();
	void setBackground();

};
#endif