
#include <stdint.h>
#include "screen.h"

#define VIDEO_BUF	(uint16_t *) 0xB8000

#define MAKE_ENTRY(d, c)   (( d << 8) | (c))

uint8_t current_color = DEFAULT_ATTR;


void screen_putchar(screen_t *scr, char c){

	console_process(scr, c);
	
    scr->dirty = 1;
}

void console_process(screen_t *scr, char c){

	//TODO add ANSI escape code support
	
	console_append(scr, c);
	
}

void console_append(screen_t *scr, char c){

	if (c == '\n'){
		console_newline(scr);
	}else if (c == '\r'){
		scr->pos_x = 0;
	}else if (c == '\t'){
		int n = 8 - (scr->pos_x % 8);
		for (int i = 0; i < n; i++){
			console_append(scr, ' ');
		}
	}else if (c == '\b'){
		if (scr->pos_x > 0){
			scr->pos_x--;
		}else{
			scr->pos_y--;
			scr->pos_x = SCREEN_WIDTH - 1;			
		}
	}else{
		if (scr->pos_x >= SCREEN_WIDTH){
			console_newline(scr);
		}		//TODO check if it need to be current color
		scr->attr[scr->pos_x + scr->pos_y * SCREEN_WIDTH] = current_color;
		scr->buf[scr->pos_x + scr->pos_y * SCREEN_WIDTH] = c;
		scr->pos_x++;
	}
}

void console_newline(screen_t *scr){

	scr->pos_x = 0;
	scr->pos_y++;

	if (scr->pos_y == SCREEN_HEIGHT){
		console_scroll(scr, 1);
	}

}

void console_scroll(screen_t *scr, int lines){

	if (lines == 0){
		return;
	}

	lines = lines > SCREEN_HEIGHT ? SCREEN_HEIGHT : lines;

	for (int i = 0; i < ((SCREEN_WIDTH*SCREEN_HEIGHT)-(SCREEN_WIDTH*lines)); i++){
		scr->buf[i] = scr->buf[i + (SCREEN_WIDTH * lines)];
		scr->attr[i] = scr->attr[i + (SCREEN_WIDTH * lines)];
	}

	for (int i = ((SCREEN_WIDTH*SCREEN_HEIGHT) - (SCREEN_WIDTH*lines)); i < SCREEN_WIDTH * SCREEN_HEIGHT; i++){
		scr->attr[i] = DEFAULT_ATTR;//TODO check if it need to be current color
		scr->buf[i] = ' ';
	}

	if (scr->pos_y > 0){
		scr->pos_y -= lines;
		if (scr->pos_y < 0){
			scr->pos_y = 0;
		}
	}

}


void screen_update(screen_t *scr){

	uint16_t pos = scr->pos_y * SCREEN_WIDTH + scr->pos_x;
	uint16_t *buf = (uint16_t *)VIDEO_BUF;
	
	for (uint32_t i = 0; i < sizeof(scr->buf); i++){
		buf[i] = MAKE_ENTRY(scr->attr[i], scr->buf[i]);
	}
	
	//TODO update hardware cursor
	pos = pos + 0;
	
	scr->dirty = 0;
	
}

