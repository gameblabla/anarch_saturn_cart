/**
  @file main_sdl.c

  This is an SDL implementation of the game front end. It can be used to
  compile a native executable or a transpiled JS browser version with
  emscripten.

  This frontend is not strictly minimal, it could be reduced a lot. If you want
  a learning example of frontend, look at another, simpler one, e.g. terminal.

  by Miloslav Ciz (drummyfish), 2019

  Released under CC0 1.0 (https://creativecommons.org/publicdomain/zero/1.0/)
  plus a waiver of all other intellectual property. The goal of this work is to
  be and remain completely in the public domain forever, available for any use
  whatsoever.
*/



#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__APPLE__)
  #define SFG_OS_IS_MALWARE 1
#endif

// #define SFG_START_LEVEL 1
// #define SFG_QUICK_WIN 1
// #define SFG_IMMORTAL 1
// #define SFG_ALL_LEVELS 1
// #define SFG_UNLOCK_DOOR 1
// #define SFG_REVEAL_MAP 1
// #define SFG_INFINITE_AMMO 1
// #define SFG_TIME_MULTIPLIER 512
// #define SFG_CPU_LOAD(percent) printf("CPU load: %d%\n",percent);
// #define GAME_LQ


// lower quality
#define SFG_FPS 30
#define SFG_SCREEN_RESOLUTION_X 320
#define SFG_SCREEN_RESOLUTION_Y 192
#define SFG_RAYCASTING_SUBSAMPLE 2
#define SFG_RESOLUTION_SCALEDOWN 2
#define SFG_DIMINISH_SPRITES 0
#define SFG_DITHERED_SHADOW 0
#define SFG_BACKGROUND_BLUR 0
#define SFG_RAYCASTING_MAX_STEPS 15
#define SFG_RAYCASTING_MAX_HITS 5

#include <stdio.h>
#include <string.h>
#include <iapetus.h>
#include "main.h"
#include "pcm_driver.h"
#include "palette_anarch.h"

/*
  SDL is easier to play thanks to nice controls so make the player take full
  damage to make it a bit harder.
*/
#define SFG_PLAYER_DAMAGE_MULTIPLIER 1024

uint32_t ticks = 0;

#include <stdio.h>
#include <unistd.h>

#include "game.h"
#include "sounds.h"

//volatile uint8_t *vram = (volatile uint8_t *)0x25E00000 + ( ((224-192)/2) * 512);

font_struct main_font;
#define EIGHTBPP 1

// now implement the Anarch API functions (SFG_*)

#ifdef EIGHTBPP
#warning "8bpp version !"
uint8_t sdlScreen[512 * 192]; // RGB565
extern uint16_t palette[];
extern u32 palette_length;
void SFG_setPixel(uint16_t x, uint16_t y, uint8_t colorIndex)
{
	volatile uint8_t *vram = (volatile uint8_t *)sdlScreen;
	int offset = (y  * 512) + x;
	uint8_t *pixel = vram + offset;
	*pixel = colorIndex;
}
#else
#warning "15bpp version !"
uint16_t sdlScreen[512 * 192]; // RGB565
extern uint16_t palette[];
extern u32 palette_length;
void SFG_setPixel(uint16_t x, uint16_t y, uint8_t colorIndex)
{
	volatile uint16_t *vram = (volatile uint16_t *)sdlScreen;
	int offset = (y  * 512) + x;
	uint16_t *pixel = vram + offset;
	*pixel = palette[colorIndex];
}
#endif

uint32_t SFG_getTimeMs()
{
	return ticks * 100;
}

void SFG_save(uint8_t data[SFG_SAVE_SIZE])
{

}

uint8_t SFG_load(uint8_t data[SFG_SAVE_SIZE])
{
  // no saving for web version
  return 0;
}

void SFG_sleepMs(uint16_t timeMs)
{
}


void SFG_getMouseOffset(int16_t *x, int16_t *y)
{
}

void SFG_processEvent(uint8_t event, uint8_t data)
{
}
int8_t SFG_keyPressed(uint8_t key)
{
	
  #define b(x) ((per[0].but_push & PAD_ ## x) > 0)

  switch (key)
  {
    case SFG_KEY_UP: return b(UP); break;
    case SFG_KEY_RIGHT: 
      return b(RIGHT); break;
    case SFG_KEY_DOWN: 
      return b(DOWN); break;
    case SFG_KEY_LEFT: return b(LEFT); break;
    case SFG_KEY_A: return b(A); break;
    case SFG_KEY_B: return b(B); break;
    case SFG_KEY_C: return b(C); break;
    case SFG_KEY_JUMP: return b(X); break;
    case SFG_KEY_STRAFE_LEFT: return b(L); break;
    case SFG_KEY_STRAFE_RIGHT: return b(R); break;
    case SFG_KEY_MAP: return b(Y); break;
    case SFG_KEY_CYCLE_WEAPON: return b(Z); break;
    case SFG_KEY_MENU: return b(START); break;
   /* case SFG_KEY_NEXT_WEAPON:
      if (b(ZR))
        return 1;
      else
      return 0;
      break;*/

    default: return 0; break;
  }

  #undef b
}
  
int running = 1;
int flip = 0;

void mainLoopIteration()
{
#ifdef EIGHTBPP
	volatile uint8_t *vram = (volatile uint8_t *)0x25E00000;
	memcpy(vram + ( ((224-192)/2) * 512), sdlScreen, (512 * 192) * 1);
#else
	volatile uint8_t *vram = (volatile uint8_t *)0x25E00000;
	memcpy(vram + ( ((224-192)/2) * 512), sdlScreen, (512 * 192) * 2);
#endif

	if (!SFG_mainLoopBody())
		running = 0;

	ticks++;
	
	vdp_vsync();
}


uint8_t musicOn = 0;
// ^ this has to be init to 0 (not 1), else a few samples get played at start

void SFG_setMusic(uint8_t value)
{
  switch (value)
  {
    case SFG_MUSIC_TURN_ON: musicOn = 1; break;
    case SFG_MUSIC_TURN_OFF: musicOn = 0; break;
    case SFG_MUSIC_NEXT: SFG_nextMusicTrack(); break;
    default: break;
  }
}

void SFG_playSound(uint8_t soundIndex, uint8_t volume)
{
}

void handleSignal(int signal)
{
  running = 0;
}

#define COLOR(r,g,b)    (((r)&0x1F)|((g)&0x1F)<<5|((b)&0x1F)<<10|0x8000)

int main(int argc, char *argv[])
{
	int i, ret;
	screen_settings_struct settings;

	init_iapetus(RES_320x224);

	// Setup a screen for us draw on
	settings.is_bitmap = TRUE;
	settings.bitmap_size = BG_BITMAP512x256;
	settings.transparent_bit = 0;
#ifdef EIGHTBPP
	settings.color = BG_256COLOR;
#else
	settings.color = BG_32786COLOR;
#endif
	settings.special_priority = 0;
	
	settings.special_color_calc = 0;
	settings.extra_palette_num = 0;
	settings.map_offset = 0;
	settings.rotation_mode = 0;
	settings.parameter_addr = 0x25E60000;
	vdp_rbg0_init(&settings);

	// Use the default palette
	vdp_set_default_palette();

	vdp_disp_on();
	vdp_set_palette(CRM5_1024, palette, 256);
	
	main_font.data = font_8x8;
	main_font.width = 8;
	main_font.height = 8;
	main_font.bpp = 1;
	main_font.out = (u8 *)0x25E00000;
	vdp_set_font(SCREEN_RBG0, &main_font, 1);

	running = 1;

	SFG_init();
	
	while (running)
		mainLoopIteration();


	return 0;
}
