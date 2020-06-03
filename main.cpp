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
#include <string.h>
#include <vector>
#include <unistd.h>
#include <mikmod.h>
#include <psputility_sysparam.h>
#include "object.cpp"

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
//#define MAX_NUM_BULLETS 100
//#define MAX_NUM_ENEMIES 100

PSP_MODULE_INFO("BattleStar C++", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(12*1024);

char playerName[128];
//string playerName;

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
    pspAudioInit();
    
    //Build in CPP
    //initMusic();
    //fontInit();
 
    oslIntraFontInit(INTRAFONT_CACHE_ALL | INTRAFONT_STRING_UTF8); // All fonts loaded with oslLoadIntraFontFile will have UTF8 support

    //Loads image:
    //OSL_IMAGE *bkg = oslLoadImageFilePNG("bsg_title.png", OSL_IN_RAM | OSL_SWIZZLED, OSL_PF_8888);
    Object obj = Object(0, 0, 480, 272, 100, "bsg_title", true,0);
    //obj.setBackground();
    //Build in CPP
    //loadCharacterData();
    
  

    //Starts to play MP3    
    //MP3_Play();

/////////////////////////////////
// Splash Screen
/////////////////////////////////
    //drawSplashText();

    while(!osl_quit){
        if (!skip){
            oslStartDrawing();

            obj.blitObject();

            //drawSplashText();

            oslEndDrawing();
        }
        oslEndFrame();
        skip = oslSyncFrame();

		//if(MP3_EndOfStream() == 1)
		//	MP3_Stop();

        oslReadKeys();
        if (osl_keys->released.cross)
            break; //oslQuit();

    }
	//MP3_Stop(1);
   	//MP3_FreeTune(1);
    
	//setupMikMod();


///////////////////////////////////////
// Main Game Loop
///////////////////////////////////////
    
    //gameScreenFontSetup();
/**
    while(!osl_quit){
        if (!skip){
            oslStartDrawing();
 	        moveStuff();

            blitEnemies();		

            control();

            if(MP3_EndOfStream() == 1)
		        MP3_Stop();


            blitObj(player);
            if(battlestar.isalive==1){
                blitObj(battlestar);
            }
            blitObj(hs_bar);
            blitObj(status_bar);

            //oslIntraFontSetStyle(pgfFont, 0.65f,WHITE,BLACK,0);
            oslDrawString(2,230,playerName);
            //drawStatusInfo();
            printScore();
            oslEndDrawing();      
       
        }
         
        oslEndFrame();
        skip = oslSyncFrame();

	    // if(MP3_EndOfStream() == 1)
		//     MP3_Stop();

       
    }*/
	//MP3_Stop(1);
   	//MP3_FreeTune(1);
        
    //Quit OSL:
    oslEndGfx();

    // Quit MikMod
    // quitMikMod();

    // Kernel Exit
    sceKernelExitGame();
    return 0;

}
