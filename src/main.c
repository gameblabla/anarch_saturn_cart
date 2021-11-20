/*  Copyright 2011-2014 Theo Berkau

    This file is part of PseudoSaturn.

    PseudoSaturn is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    PseudoSaturn is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PseudoSaturn; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
    Program that attempts to run code off custom cd's
    by Cyber Warrior X. Based on code by Charles MacDonald.
*/

#include <stdio.h>
#include <string.h>
#include <iapetus.h>
#include "main.h"

font_struct main_font;


extern u8 logo[];
extern u32 logo_size;

void do_logo()
{
	int ret;
	int i,j;
	u16 pal[256];
	u8 crc_table[] = { 0xE3, 0xCC, 0x8A, 0xD3, 0xC5, 0xDF, 0x8A, 0xDA, 0xCB, 0xC3, 0xCE, 0x8A, 0xCC, 0xC5, 0xD8, 0x8A, 0xDE, 0xC2, 0xC3, 0xD9, 0x86, 0x8A, 0xD3, 0xC5, 0xDF, 0x8A, 0xDD, 0xCF, 0xD8, 0xCF, 0x8A, 0xD8, 0xC3, 0xDA, 0xDA, 0xCF, 0xCE, 0x8A, 0xC5, 0xCC, 0xCC, 0x8B, 0xAA };
	u8 *img_buffer=(u8 *)0x06002000;

	img_struct img;
	if ((ret = pcx_load(logo, logo_size, &img, img_buffer)) != IAPETUS_ERR_OK)
	{
		vdp_printf(&main_font, 2 * 8, 1 * 8, 15, "Error loading pcx data = %d", ret);
		wait_for_press(-1);
	}

	// Convert palette
	for (i = 0; i < 256; i++)
	{
		unsigned char *p=&img.palette[i*3];
		pal[i] = RGB555(p[0] >> 3, p[1] >> 3, p[2] >> 3);
	}

	// Make sure we're faded out
	vdp_disp_on();
	vdp_fade_out(SCREEN_RBG0, 0, 255);
	for (i = 0; i < img.height; i++)
	   memcpy((void *)0x25E00000+(i*512), img.data+(i*img.width), img.width);
	j=8*10;
	for (i = 0; i < 20; i++)
		j += main_font.drawchar(&main_font, j, 25 * 8, 1, crc_table[i]^0xAA);
	j=8*10;
	for (i = 22; i < sizeof(crc_table)-1; i++)
		j += main_font.drawchar(&main_font, j, 26 * 8, 1, crc_table[i]^0xAA);
	vdp_set_palette(CRM5_2048, pal, 256);

	vdp_printf(&main_font, 8, 23 * 8, 1, "Copyright 2011-2015 Pseudo Saturn Team");

	vdp_fade_in(SCREEN_RBG0, 0, 2);
	
	while(1)
	{
		vdp_vsync();
	}

	// Wait for a few seconds or something
	/*for (i = 0; i < 2*60; i++) { vdp_vsync(); }

	vdp_fade_out(SCREEN_RBG0, 0, 2);
	vdp_disp_off();
	vdp_set_default_palette();

	vdp_clear_screen(&main_font);
	vdp_disable_color_offset(SCREEN_RBG0);*/
}


//////////////////////////////////////////////////////////////////////////////

u16 wait_for_press(u16 mask)
{	
	for (;;)        
	{
		vdp_vsync(); 
		if (per[0].but_push_once & mask)
			break;
	}
	return per[0].but_push_once & mask;
}

//////////////////////////////////////////////////////////////////////////////

void credits()
{
   vdp_printf(&main_font, 8, 8, 0xF, "Copyright 2011-2015 Pseudo Saturn Team");
   vdp_printf(&main_font, 8, 2 * 8, 15, "http://github.com/cyberwarriorx/pseudosaturn");
   vdp_printf(&main_font, 8, 10 * 8, 15, "Press any button to go back");

   for (;;)        
   {
      vdp_vsync(); 
      if (per[0].but_push_once)
         break;
   }
   vdp_clear_screen(&main_font);
}

//////////////////////////////////////////////////////////////////////////////

void ps_init()
{
	screen_settings_struct settings;

	init_iapetus(RES_320x224);

	// Setup a screen for us draw on
	settings.is_bitmap = TRUE;
	settings.bitmap_size = BG_BITMAP512x256;
	settings.transparent_bit = 0;
	settings.color = BG_256COLOR;
	settings.special_priority = 0;
	settings.special_color_calc = 0;
	settings.extra_palette_num = 0;
	settings.map_offset = 0;
	settings.rotation_mode = 0;
	settings.parameter_addr = 0x25E60000;
	vdp_rbg0_init(&settings);

	// Use the default palette
	vdp_set_default_palette();

	// Setup the default 8x8 1BPP font
	main_font.data = font_8x8;
	main_font.width = 8;
	main_font.height = 8;
	main_font.bpp = 1;
	main_font.out = (u8 *)0x25E00000;
	vdp_set_font(SCREEN_RBG0, &main_font, 1);
	//con_init(&main_font, 0, 0, 320, 224);

	do_logo();

	// Display everything
	vdp_disp_on();

	if (ud_detect() == IAPETUS_ERR_OK)
		cl_set_service_func(ud_check);
}

//////////////////////////////////////////////////////////////////////////////

int main()
{
	ps_init();

   // Display Main Menu
  /* for(;;)
   {
      commlink_start_service();
      gui_do_menu(main_menu, &main_font, 0, 0, "Pseudo Saturn v" PSEUDOSATURN_VERSION, MTYPE_CENTER, -1);

      main_font.transparent = 1;
      gui_clear_scr(&main_font);
   }*/

   return 0;
}

//////////////////////////////////////////////////////////////////////////////
