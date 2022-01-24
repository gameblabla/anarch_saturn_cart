#ifndef PCM_DRIVER
#define PCM_DRIVER

extern void LoadDriver(void);
extern void LoadSamples(void);
extern void TestADPCMVoice(void);
extern void TestADPCMDCBias(void);
extern void TestADPCMLong(void);
extern void TestADPCMLoop(void);
extern void TestSquare(void);
extern void TestNoise(void);
extern void TestSawVroom(void);
extern void TestNightmare(void);
extern void Wait(uint32 t);

#endif
