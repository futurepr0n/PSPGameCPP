#include <oslib/oslib.h>
#include "control.h"
#include "object.h"

void control(Object& obj)
{
     oslReadKeys();
        if (osl_keys->held.circle){/**shootChain();playBullet();*/}   
        if((osl_keys->held.right)&&obj.x <= 150){obj.x = obj.x + 1;}      
        if((osl_keys->held.left)&&obj.x > 60){obj.x = obj.x - 1;} 
        if((osl_keys->held.up)&&obj.y > -10){obj.y = obj.y - 5;}  
        if((osl_keys->held.down)&&obj.y < 262){obj.y = obj.y + 5;}
}