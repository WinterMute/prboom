#include <stdio.h>
#include <string.h>

#include <3ds/services/hid.h>

#include "keyboard.h"

char keyboard_string[MAX_KEYBOARD_STRING+1];

#define KEYBOARD_NUMCHARS 47
const char * kb_lc_string = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
const char * kb_uc_string = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
const char * kb_cl_string = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

const char * kb_template_lines[4] =  {
	"\xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3\x1b-\xb3",
	"\xb3-\x1a\xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3",
	"\xb3""CL \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3  \xb3",
	"\xb3SHFT\xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3 \xb3   \xb3",
};
const int kb_char_y[KEYBOARD_NUMCHARS] = {
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,2,2,2,2, 2,2,2,2,2, 2,2,3,3,3, 3,3,3,3,3, 3,3
};
const int kb_char_x[KEYBOARD_NUMCHARS] = {
	1,3,5,7,9,11,13,15,17,19,21,23,25,
	4,6,8,10,12,14,16,18,20,22,24,26,28,
	5,7,9,11,13,15,17,19,21,23,25,
	6,8,10,12,14,16,18,20,22,24
};

static int displayed = 0;

void drawKeyboard() {
    printf("\x1b[2J");
    // draw::keyboard
    printf("\x1b[2;1H\xda\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xbf");
    printf("\x1b[3;1H\xb3 \xb3                                \xb3 \xb3");
    printf("\x1b[4;1H\xc0\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xd9");

    printf("\x1b[6;5H\xda\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc2\xc4\xc4\xbf");

	printf("\x1b[8;5H\xc3\xc4\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc4\xb4");
	printf("\x1b[10;5H\xc3\xc4\xc4\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc4\xb4");
    printf("\x1b[12;5H\xc3\xc4\xc4\xc4\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xc1\xc2\xd9\x4f\x4b\xb3");
    printf("\x1b[14;5H\xc0\xc4\xc4\xc4\xc4\xc1\xc4\xc1\xc2\xc1\xc4\xc1\xc4\xc1\xc4\xc1\xc4\xc1\xc4\xc1\xc4\xc1\xc2\xc1\xc4\xc1\xc4\xc4\xc4\xd9");
    printf("\x1b[15;5H        \xb3             \xb3         ");
    printf("\x1b[16;5H        \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9         ");

    displayed = 1;

}


int updateKeyboard() {
    char kbline[4][33];
    int  keys, cursorpos, linelen, firstdrawchar = 0;
    const char * srckb = kb_lc_string;
    static int keystate = 0, blinkcount = 0;
    touchPosition touch;

    int key = 0;
    static int need_gen_keys = 1, i;

    if (!displayed) {
        drawKeyboard();
        printf("\x1b[3;4H%s",keyboard_string);
        need_gen_keys = 1;
    }

    linelen=cursorpos=strlen(keyboard_string);

    switch(keystate) {

    default:
    case 0: // lowercase
        srckb=kb_lc_string;
        break;

    case 1: // shift
    case 3: // caps+shift
        srckb=kb_uc_string;
        break;

    case 2: // caps
        srckb=kb_cl_string;
        break;
    }

    if(need_gen_keys) {

        need_gen_keys=0;

        for(i=0; i<4; i++) strcpy(kbline[i],kb_template_lines[i]);

        for(i=0; i<KEYBOARD_NUMCHARS; i++) kbline[kb_char_y[i]][kb_char_x[i]]=srckb[i];

        printf("\x1b[7;5H%s",kbline[0]);
        printf("\x1b[9;5H%s",kbline[1]);
        printf("\x1b[11;5H%s",kbline[2]);
        printf("\x1b[13;5H%s",kbline[3]);
    }

    printf("\x1b[3;%dH ",4+cursorpos-firstdrawchar);

    if (hidKeysDown() & KEY_TOUCH) {

        hidTouchRead(&touch);

        // "capslock" - center of (5,10) to center of (10,12)
		if(touch.px>=(5*8+4) && touch.px<(10*8+4) && touch.py>=(10*8+4) && touch.py<(12*8+4)) {

			keystate ^=2; need_gen_keys=1;
		}

        // "lshft" - center of (5,12) to center of (11,14)
		if(touch.px>=(5*8+4) && touch.px<(11*8+4) && touch.py>=(12*8+4) && touch.py<(14*8+4)) {

			keystate ^=1; need_gen_keys=1;
		}

        // OK
		if( (touch.px>=(31*8+4) && touch.px<(34*8+4) && touch.py>=(10*8+4) && touch.py<(12*8+4)) ||
            (touch.px>=(30*8+4) && touch.px<(34*8+4) && touch.py>=(12*8+4) && touch.py<(14*8+4)) ) {

            key = 13;
        }

        // "space" - center of (14,14) to center of (26,16)
		if(touch.px>=(13*8+4) && touch.px<(27*8+4) && touch.py>=(14*8+4) && touch.py<(16*8+4)) {

			key = 32;
		}

		// "backspace" - center of (27,6) to center of (30,8)
		if(touch.px>=(31*8+4) && touch.px<(34*8+4) && touch.py>=(6*8+4) && touch.py<(8*8+4)) {

			if(cursorpos>0) {
				for(i=cursorpos;i<linelen;i++) {
					keyboard_string[i-1]=keyboard_string[i];
				}
				cursorpos--;
				linelen--;
				keyboard_string[linelen]=0;
			}
			key = 127;
		}

		// process "key" regions (keyboard starts at (8,48) technically)
		for(i=0;i<KEYBOARD_NUMCHARS;i++) {
			if(touch.px>=(12-8+((kb_char_x[i]+4)*8)) && touch.px<(12+8+((kb_char_x[i]+4)*8)) && touch.py>=(60-8+kb_char_y[i]*16) && touch.py<(60+8+kb_char_y[i]*16)) {
				key=srckb[i]; break;
			}
		}
    }

	if((cursorpos-1)<firstdrawchar) firstdrawchar=cursorpos-1;
    if(cursorpos>(firstdrawchar+22)) firstdrawchar=cursorpos-22;
	if(firstdrawchar<0) firstdrawchar=0;

	if (key >= 32 && key != 127 && cursorpos < MAX_KEYBOARD_STRING) {
        keyboard_string[cursorpos++] = key;
        keyboard_string[cursorpos] = 0;
        printf("\x1b[3;4H%s",keyboard_string);
        if (keystate & 1) {
            keystate &= ~1;
            need_gen_keys = 1;
        }
	}

    if(blinkcount&32) {
        printf("\x1b[3;%dH_",4+cursorpos-firstdrawchar);
    } else {
        printf("\x1b[3;%dH ",4+cursorpos-firstdrawchar);
    }

    blinkcount++;

    keys = hidKeysDown();

    if (keys & KEY_A) key = 13;
    if (keys & KEY_B) key = 27;

    if (key == 13 || key == 27) {
        printf("\x1b[2J");
        displayed = 0;
    }
    return key;

}
