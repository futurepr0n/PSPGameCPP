#include <pspkernel.h>
#include <oslib/oslib.h>
#include <pspctrl.h>
#include <pspdebug.h>
#include <pspaudio.h>
#include <pspaudiolib.h>
#include <psppower.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <mikmod.h>
#include <psputility_sysparam.h>
#include "object.h"



using namespace std;



int initOSLib(){
    oslInit(0);
    oslInitGfx(OSL_PF_8888, 1);
    oslInitAudio();
    oslSetQuitOnLoadFailure(1);
    oslSetKeyAutorepeatInit(40);
    oslSetKeyAutorepeatInterval(10);
    return 0;
}

PSP_MODULE_INFO("BattleStar C++", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(12*1024);

char playerName[128];

bool quit = false;
// EXIT CALLBACK
/* Exit callback */
//int exit_callback(int arg1, int arg2, void *common) {
//    osl_quit = 1;
//    return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    int skip = 0;

    //Get player name
    sceUtilityGetSystemParamString(PSP_SYSTEMPARAM_ID_STRING_NICKNAME, playerName, 127);

    initOSLib();
 
    oslIntraFontInit(INTRAFONT_CACHE_ALL | INTRAFONT_STRING_UTF8); // All fonts loaded with oslLoadIntraFontFile will have UTF8 support

    //Object background = Object(0, 0, 480, 272, 100, bgimg, true,0);
    Object player = Object(100,80,46,24,1000,playerimg,true,0,0);

    while(!quit){
        if (!skip){
            oslStartDrawing();

            //background.blitObject();
            player.blitObject();
            player.control();
            
            oslEndDrawing();
        }
        oslEndFrame();
        skip = oslSyncFrame();
        oslReadKeys();
        
    }
	
        
    //Quit OSL:
    oslEndGfx();

    // Kernel Exit
    sceKernelExitGame();
    return 0;

}
