#include <stdio.h>
#include <string.h>

#include "types.h"
#include "sh2.h"
#include "smpc.h"
#include "scsp.h"

#include "adp68k.h"

#include "samples.h"

static const uint8 driver_data[0x2000] =
{
 #include "adp68k.bin.inc"
};

static const uint8 sample_data[] =
{
 #include "samples.ladp.inc"
};


void LoadDriver(void)
{
	//WriteSR(0xF0); // Gameblabla, for whatever reason, this disables controls !!
	
	SMPC_SoundOff();
	SCSP_Init();
	SCSP_MCIRE = 0xFFFF;
	SCSP_SCIRE = 0xFFFF;
	//
	for(unsigned i = 0; i < sizeof(driver_data); i++)
		SCSP8(i) = driver_data[i];
	//
	SMPC_SoundOn();
	while(!(SCSP_MCIPD & 0x20));
	SCSP_MCIRE_LO = 0x20;
}

void LoadSamples(void)
{
	while(SCSP_SCIPD & 0x20);

	for(unsigned i = 0; i < 8; i++)
		adp68k_scblock->adpcm[i].action = ADP68K_ACTION_STOP;

	SCSP_SCIPD_LO = 0x20;
	while(SCSP_SCIPD & 0x20);

	for(unsigned i = 0; i < sizeof(sample_data); i++)
		adp68k_sdbase[i] = sample_data[i];
}
