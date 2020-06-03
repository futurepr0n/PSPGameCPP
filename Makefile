TARGET = battlestarcpp
OBJS = main.o

#To build for custom firmware:
BUILD_PRX = 1
PSP_FW_VERSION=371

CFLAGS = -O2 -g -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
LIBDIR =

MYLIBS=
STDLIBS= -lmikmod -losl -lpng -lz \
         -lpsphprm -lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgu -lpspgum -lmad -lpspaudiolib -lpspaudio -lpspaudiocodec -lpsphttp -lpspssl -lpspwlan \
         -lpspnet_adhocmatching -lpspnet_adhoc -lpspnet_adhocctl -lm -ljpeg
LIBS=$(STDLIBS) $(MYLIBS)

LDFLAGS =
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = BattleStar CPP
#PSP_EBOOT_ICON = bsg_eboot_icon.png
#PSP_EBOOT_PIC1 = bsg_eboot_bg.png
PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
