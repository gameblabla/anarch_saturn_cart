/*
  @file palette.h

  General purpose HSV-based 256 color palette.

  by Miloslav Ciz (drummyfish), 2019

  Released under CC0 1.0 (https://creativecommons.org/publicdomain/zero/1.0/)
  plus a waiver of all other intellectual property. The goal of this work is
  be and remain completely in the public domain forever, available for any use
  whatsoever.
*/

#ifndef PALETTE_256_H
#define PALETTE_256_H

SFG_PROGRAM_MEMORY

#if defined(ARGB_BUFFER) || defined(RGBX_BUFFER)
uint32_t 
#else
uint16_t 
#endif
paletteRGB565[256] = {
#if defined(ARGB_BUFFER)
0xff000000, 0xff181c18, 0xff384038, 0xff686460, 0xff909490, 
0xffb8bcb8, 0xffe0e8e0, 0xfff8fcf8, 0xff180c08, 0xff381c18, 
0xff603030, 0xff804440, 0xffa85c58, 0xffc87470, 0xfff08c88, 
0xfff8aca8, 0xff181808, 0xff403020, 0xff604c30, 0xff886c48, 
0xffa88c58, 0xffc8a878, 0xfff0c890, 0xfff8e4a8, 0xff182010, 
0xff384018, 0xff586430, 0xff788840, 0xff98a860, 0xffc0d070, 
0xffe0f490, 0xfff8fcb0, 0xff102010, 0xff284018, 0xff386830, 
0xff508840, 0xff70a858, 0xff88cc70, 0xffa0f488, 0xffc0fcb0, 
0xff082010, 0xff204028, 0xff306440, 0xff488860, 0xff60a878, 
0xff70cc98, 0xff88f4b0, 0xffb0fcd0, 0xff102020, 0xff204038, 
0xff386058, 0xff488880, 0xff68a4a0, 0xff78ccc8, 0xff90f4f0, 
0xffb0fcf8, 0xff101018, 0xff202838, 0xff304060, 0xff405c80, 
0xff607ca0, 0xff7898c8, 0xff90b4f0, 0xffb0d0f8, 0xff080818, 
0xff201c40, 0xff383060, 0xff504480, 0xff685ca0, 0xff8074c8, 
0xff9888f0, 0xffb8acf8, 0xff180c20, 0xff301c40, 0xff583060, 
0xff784480, 0xff985ca8, 0xffb878c8, 0xffd88ce8, 0xfff8b0f8, 
0xff200c10, 0xff401c30, 0xff603048, 0xff804468, 0xffa85c88, 
0xffc874a0, 0xfff08cc8, 0xfff8ace0, 0xff280000, 0xff480400, 
0xff680408, 0xff980410, 0xffb80c10, 0xffd81c20, 0xfff82428, 
0xfff84850, 0xff281400, 0xff482808, 0xff684410, 0xff905c08, 
0xffb87410, 0xffd88c28, 0xfff8a828, 0xfff8bc50, 0xff182c00, 
0xff384c00, 0xff587008, 0xff789808, 0xff98bc10, 0xffb8dc28, 
0xffd8fc28, 0xffe8fc50, 0xff002c00, 0xff104c00, 0xff187008, 
0xff189810, 0xff38bc10, 0xff48dc20, 0xff58fc30, 0xff70fc48, 
0xff002c10, 0xff004c18, 0xff087028, 0xff109440, 0xff18bc50, 
0xff28dc68, 0xff18fc78, 0xff48fc98, 0xff002c28, 0xff004c48, 
0xff007070, 0xff109490, 0xff20b8b0, 0xff18dcd8, 0xff30fcf8, 
0xff58fcf8, 0xff000828, 0xff001c48, 0xff102c68, 0xff103c90, 
0xff2058b0, 0xff0868d8, 0xff307cf8, 0xff4898f8, 0xff100428, 
0xff080448, 0xff100868, 0xff200c90, 0xff2818b8, 0xff4020d8, 
0xff502cf8, 0xff684cf8, 0xff180028, 0xff380448, 0xff580470, 
0xff701098, 0xff9810b8, 0xffb024d8, 0xffd02cf8, 0xffe04cf8, 
0xff280010, 0xff480428, 0xff680440, 0xff980858, 0xffb81078, 
0xffd81c88, 0xfff824a8, 0xfff84cb8, 0xff280400, 0xff480000, 
0xff680000, 0xff880400, 0xffb00000, 0xffd00800, 0xfff00800, 
0xfff80400, 0xff280c00, 0xff481800, 0xff682c00, 0xff883c00, 
0xffb05400, 0xffd06400, 0xfff07800, 0xfff88c08, 0xff202c00, 
0xff404c00, 0xff606c00, 0xff789000, 0xffa0b400, 0xffc0d800, 
0xffe0f800, 0xfff8fc00, 0xff102c00, 0xff084c00, 0xff186c00, 
0xff289000, 0xff30b400, 0xff30d800, 0xff48f800, 0xff60fc08, 
0xff082c00, 0xff004c00, 0xff006c00, 0xff089000, 0xff10b000, 
0xff00d410, 0xff00f808, 0xff00fc18, 0xff002c08, 0xff004c30, 
0xff006c40, 0xff009058, 0xff00b070, 0xff00d488, 0xff00f8a8, 
0xff00fcb8, 0xff001828, 0xff002c48, 0xff004468, 0xff005c88, 
0xff0074b0, 0xff1090c8, 0xff00acf0, 0xff20c0f8, 0xff000028, 
0xff000048, 0xff080468, 0xff000888, 0xff100cb0, 0xff0014d0, 
0xff0818f0, 0xff0028f8, 0xff080020, 0xff100048, 0xff100068, 
0xff200088, 0xff2008b0, 0xff3000d0, 0xff4000f0, 0xff4808f8, 
0xff280028, 0xff380450, 0xff580068, 0xff780090, 0xff9800b0, 
0xffb800d0, 0xffd800f0, 0xfff000f8, 0xff280008, 0xff480018, 
0xff680030, 0xff880040, 0xffb00050, 0xffd00468, 0xfff00878, 
0xfff80c88 
#elif defined(RGBX_BUFFER)
#warning "RGBX BUFFER for Wii U"

#if 0
0xff000000, 0xff181c18, 0xff384038, 0xff686460, 0xff909490, 
0xffb8bcb8, 0xffe0e8e0, 0xfff8fcf8, 0xff180c08, 0xff381c18, 
0xff603030, 0xff804440, 0xffa85c58, 0xffc87470, 0xfff08c88, 
0xfff8aca8, 0xff181808, 0xff403020, 0xff604c30, 0xff886c48, 
0xffa88c58, 0xffc8a878, 0xfff0c890, 0xfff8e4a8, 0xff182010, 
0xff384018, 0xff586430, 0xff788840, 0xff98a860, 0xffc0d070, 
0xffe0f490, 0xfff8fcb0, 0xff102010, 0xff284018, 0xff386830, 
0xff508840, 0xff70a858, 0xff88cc70, 0xffa0f488, 0xffc0fcb0, 
0xff082010, 0xff204028, 0xff306440, 0xff488860, 0xff60a878, 
0xff70cc98, 0xff88f4b0, 0xffb0fcd0, 0xff102020, 0xff204038, 
0xff386058, 0xff488880, 0xff68a4a0, 0xff78ccc8, 0xff90f4f0, 
0xffb0fcf8, 0xff101018, 0xff202838, 0xff304060, 0xff405c80, 
0xff607ca0, 0xff7898c8, 0xff90b4f0, 0xffb0d0f8, 0xff080818, 
0xff201c40, 0xff383060, 0xff504480, 0xff685ca0, 0xff8074c8, 
0xff9888f0, 0xffb8acf8, 0xff180c20, 0xff301c40, 0xff583060, 
0xff784480, 0xff985ca8, 0xffb878c8, 0xffd88ce8, 0xfff8b0f8, 
0xff200c10, 0xff401c30, 0xff603048, 0xff804468, 0xffa85c88, 
0xffc874a0, 0xfff08cc8, 0xfff8ace0, 0xff280000, 0xff480400, 
0xff680408, 0xff980410, 0xffb80c10, 0xffd81c20, 0xfff82428, 
0xfff84850, 0xff281400, 0xff482808, 0xff684410, 0xff905c08, 
0xffb87410, 0xffd88c28, 0xfff8a828, 0xfff8bc50, 0xff182c00, 
0xff384c00, 0xff587008, 0xff789808, 0xff98bc10, 0xffb8dc28, 
0xffd8fc28, 0xffe8fc50, 0xff002c00, 0xff104c00, 0xff187008, 
0xff189810, 0xff38bc10, 0xff48dc20, 0xff58fc30, 0xff70fc48, 
0xff002c10, 0xff004c18, 0xff087028, 0xff109440, 0xff18bc50, 
0xff28dc68, 0xff18fc78, 0xff48fc98, 0xff002c28, 0xff004c48, 
0xff007070, 0xff109490, 0xff20b8b0, 0xff18dcd8, 0xff30fcf8, 
0xff58fcf8, 0xff000828, 0xff001c48, 0xff102c68, 0xff103c90, 
0xff2058b0, 0xff0868d8, 0xff307cf8, 0xff4898f8, 0xff100428, 
0xff080448, 0xff100868, 0xff200c90, 0xff2818b8, 0xff4020d8, 
0xff502cf8, 0xff684cf8, 0xff180028, 0xff380448, 0xff580470, 
0xff701098, 0xff9810b8, 0xffb024d8, 0xffd02cf8, 0xffe04cf8, 
0xff280010, 0xff480428, 0xff680440, 0xff980858, 0xffb81078, 
0xffd81c88, 0xfff824a8, 0xfff84cb8, 0xff280400, 0xff480000, 
0xff680000, 0xff880400, 0xffb00000, 0xffd00800, 0xfff00800, 
0xfff80400, 0xff280c00, 0xff481800, 0xff682c00, 0xff883c00, 
0xffb05400, 0xffd06400, 0xfff07800, 0xfff88c08, 0xff202c00, 
0xff404c00, 0xff606c00, 0xff789000, 0xffa0b400, 0xffc0d800, 
0xffe0f800, 0xfff8fc00, 0xff102c00, 0xff084c00, 0xff186c00, 
0xff289000, 0xff30b400, 0xff30d800, 0xff48f800, 0xff60fc08, 
0xff082c00, 0xff004c00, 0xff006c00, 0xff089000, 0xff10b000, 
0xff00d410, 0xff00f808, 0xff00fc18, 0xff002c08, 0xff004c30, 
0xff006c40, 0xff009058, 0xff00b070, 0xff00d488, 0xff00f8a8, 
0xff00fcb8, 0xff001828, 0xff002c48, 0xff004468, 0xff005c88, 
0xff0074b0, 0xff1090c8, 0xff00acf0, 0xff20c0f8, 0xff000028, 
0xff000048, 0xff080468, 0xff000888, 0xff100cb0, 0xff0014d0, 
0xff0818f0, 0xff0028f8, 0xff080020, 0xff100048, 0xff100068, 
0xff200088, 0xff2008b0, 0xff3000d0, 0xff4000f0, 0xff4808f8, 
0xff280028, 0xff380450, 0xff580068, 0xff780090, 0xff9800b0, 
0xffb800d0, 0xffd800f0, 0xfff000f8, 0xff280008, 0xff480018, 
0xff680030, 0xff880040, 0xffb00050, 0xffd00468, 0xfff00878, 
0xfff80c88 
#else
0xff, 0x181c18ff, 0x384038ff, 0x686460ff, 0x909490ff, 
0xb8bcb8ff, 0xe0e8e0ff, 0xf8fcf8ff, 0x180c08ff, 0x381c18ff, 
0x603030ff, 0x804440ff, 0xa85c58ff, 0xc87470ff, 0xf08c88ff, 
0xf8aca8ff, 0x181808ff, 0x403020ff, 0x604c30ff, 0x886c48ff, 
0xa88c58ff, 0xc8a878ff, 0xf0c890ff, 0xf8e4a8ff, 0x182010ff, 
0x384018ff, 0x586430ff, 0x788840ff, 0x98a860ff, 0xc0d070ff, 
0xe0f490ff, 0xf8fcb0ff, 0x102010ff, 0x284018ff, 0x386830ff, 
0x508840ff, 0x70a858ff, 0x88cc70ff, 0xa0f488ff, 0xc0fcb0ff, 
0x82010ff, 0x204028ff, 0x306440ff, 0x488860ff, 0x60a878ff, 
0x70cc98ff, 0x88f4b0ff, 0xb0fcd0ff, 0x102020ff, 0x204038ff, 
0x386058ff, 0x488880ff, 0x68a4a0ff, 0x78ccc8ff, 0x90f4f0ff, 
0xb0fcf8ff, 0x101018ff, 0x202838ff, 0x304060ff, 0x405c80ff, 
0x607ca0ff, 0x7898c8ff, 0x90b4f0ff, 0xb0d0f8ff, 0x80818ff, 
0x201c40ff, 0x383060ff, 0x504480ff, 0x685ca0ff, 0x8074c8ff, 
0x9888f0ff, 0xb8acf8ff, 0x180c20ff, 0x301c40ff, 0x583060ff, 
0x784480ff, 0x985ca8ff, 0xb878c8ff, 0xd88ce8ff, 0xf8b0f8ff, 
0x200c10ff, 0x401c30ff, 0x603048ff, 0x804468ff, 0xa85c88ff, 
0xc874a0ff, 0xf08cc8ff, 0xf8ace0ff, 0x280000ff, 0x480400ff, 
0x680408ff, 0x980410ff, 0xb80c10ff, 0xd81c20ff, 0xf82428ff, 
0xf84850ff, 0x281400ff, 0x482808ff, 0x684410ff, 0x905c08ff, 
0xb87410ff, 0xd88c28ff, 0xf8a828ff, 0xf8bc50ff, 0x182c00ff, 
0x384c00ff, 0x587008ff, 0x789808ff, 0x98bc10ff, 0xb8dc28ff, 
0xd8fc28ff, 0xe8fc50ff, 0x2c00ff, 0x104c00ff, 0x187008ff, 
0x189810ff, 0x38bc10ff, 0x48dc20ff, 0x58fc30ff, 0x70fc48ff, 
0x2c10ff, 0x4c18ff, 0x87028ff, 0x109440ff, 0x18bc50ff, 
0x28dc68ff, 0x18fc78ff, 0x48fc98ff, 0x2c28ff, 0x4c48ff, 
0x7070ff, 0x109490ff, 0x20b8b0ff, 0x18dcd8ff, 0x30fcf8ff, 
0x58fcf8ff, 0x828ff, 0x1c48ff, 0x102c68ff, 0x103c90ff, 
0x2058b0ff, 0x868d8ff, 0x307cf8ff, 0x4898f8ff, 0x100428ff, 
0x80448ff, 0x100868ff, 0x200c90ff, 0x2818b8ff, 0x4020d8ff, 
0x502cf8ff, 0x684cf8ff, 0x180028ff, 0x380448ff, 0x580470ff, 
0x701098ff, 0x9810b8ff, 0xb024d8ff, 0xd02cf8ff, 0xe04cf8ff, 
0x280010ff, 0x480428ff, 0x680440ff, 0x980858ff, 0xb81078ff, 
0xd81c88ff, 0xf824a8ff, 0xf84cb8ff, 0x280400ff, 0x480000ff, 
0x680000ff, 0x880400ff, 0xb00000ff, 0xd00800ff, 0xf00800ff, 
0xf80400ff, 0x280c00ff, 0x481800ff, 0x682c00ff, 0x883c00ff, 
0xb05400ff, 0xd06400ff, 0xf07800ff, 0xf88c08ff, 0x202c00ff, 
0x404c00ff, 0x606c00ff, 0x789000ff, 0xa0b400ff, 0xc0d800ff, 
0xe0f800ff, 0xf8fc00ff, 0x102c00ff, 0x84c00ff, 0x186c00ff, 
0x289000ff, 0x30b400ff, 0x30d800ff, 0x48f800ff, 0x60fc08ff, 
0x82c00ff, 0x4c00ff, 0x6c00ff, 0x89000ff, 0x10b000ff, 
0xd410ff, 0xf808ff, 0xfc18ff, 0x2c08ff, 0x4c30ff, 
0x6c40ff, 0x9058ff, 0xb070ff, 0xd488ff, 0xf8a8ff, 
0xfcb8ff, 0x1828ff, 0x2c48ff, 0x4468ff, 0x5c88ff, 
0x74b0ff, 0x1090c8ff, 0xacf0ff, 0x20c0f8ff, 0x28ff, 
0x48ff, 0x80468ff, 0x888ff, 0x100cb0ff, 0x14d0ff, 
0x818f0ff, 0x28f8ff, 0x80020ff, 0x100048ff, 0x100068ff, 
0x200088ff, 0x2008b0ff, 0x3000d0ff, 0x4000f0ff, 0x4808f8ff, 
0x280028ff, 0x380450ff, 0x580068ff, 0x780090ff, 0x9800b0ff, 
0xb800d0ff, 0xd800f0ff, 0xf000f8ff, 0x280008ff, 0x480018ff, 
0x680030ff, 0x880040ff, 0xb00050ff, 0xd00468ff, 0xf00878ff, 
0xf80c88ff
#endif

#elif 1
// manually adjusted, more saturated palette
0, 6371, 14855, 27436, 38066, 48631, 59228, 65535, 6241, 14563, 24966, 33320, 
43755, 52142, 62577, 64885, 6337, 16772, 25190, 35689, 44139, 52559, 63058, 
65333, 6402, 14851, 23334, 31816, 40268, 50830, 59314, 65526, 4354, 10755, 
15174, 21576, 30027, 36462, 42929, 51190, 2306, 8709, 13096, 19532, 25935, 
30323, 36790, 47098, 4356, 8711, 15115, 19536, 27956, 32377, 38846, 47103, 
4227, 8519, 12812, 17136, 25588, 31961, 38334, 46751, 2115, 8424, 14732, 21040, 
27380, 33721, 40030, 48511, 6244, 12520, 22924, 31280, 39669, 48089, 56445, 
64927, 8290, 16614, 24969, 33325, 43761, 52148, 62585, 64892, 10240, 18464, 
26657, 38946, 47202, 55524, 63781, 64074, 10400, 18753, 27170, 37601, 48034, 
56421, 64837, 65002, 6496, 14944, 23425, 31937, 40418, 48869, 57317, 61418, 
352, 4704, 7041, 7362, 15842, 20196, 24550, 30697, 354, 611, 2949, 5288, 7658, 
12013, 8175, 20467, 357, 617, 910, 5298, 9686, 7931, 14335, 24575, 69, 233, 
4461, 4594, 8918, 2907, 13311, 19679, 4133, 2089, 4173, 8306, 10455, 16667, 
20863, 27263, 6149, 14377, 22574, 28819, 39063, 45371, 53631, 57983, 10242, 
18469, 26664, 38987, 47247, 55537, 63797, 64119, 10272, 18432, 26624, 34848, 
45056, 53312, 61504, 63520, 10336, 18624, 26976, 35296, 45728, 54048, 62400, 
64609, 8544, 16992, 25440, 31872, 42400, 50880, 59328, 65504, 4448, 2656, 
7008, 11392, 13728, 14016, 20416, 26593, 2400, 608, 864, 3200, 5504, 1698, 
1985, 2019, 353, 614, 872, 1163, 1422, 1713, 2005, 2039, 197, 361, 557, 753, 
950, 5273, 1406, 9759, 5, 9, 2093, 81, 4214, 186, 2270, 351, 2052, 4105, 4109, 
8209, 8278, 12314, 16414, 18527, 10245, 14378, 22541, 30738, 38934, 47130, 55326, 
61471, 10241, 18435, 26630, 34824, 45066, 53293, 61519, 63601
#else 
// original palette
0, 8484, 19017, 27501, 38034, 46518, 57051, 65535, 8354, 16709, 25096, 33450,
41805, 50192, 58546, 64853, 8386, 16805, 25224, 33642, 42061, 50480, 58898,
65269, 6402, 14853, 23304, 29706, 38157, 46608, 55058, 61429, 4354, 10757,
17160, 23562, 29965, 36368, 42770, 49141, 4355, 10758, 17161, 21516, 27920,
34323, 38678, 45049, 4323, 10759, 17163, 21519, 27923, 34327, 38683, 45055,
4292, 10632, 17004, 21296, 27668, 34008, 38300, 44671, 4260, 10568, 16908,
23216, 29524, 35864, 42172, 48479, 6308, 14664, 23052, 29360, 37716, 46104,
54460, 60767, 8355, 16710, 25098, 33453, 41809, 50196, 58552, 64859, 8257,
16546, 24836, 33093, 41382, 49672, 57929, 64170, 8353, 16738, 25124, 33509,
41894, 50248, 58633, 64970, 6401, 12802, 21252, 27653, 36102, 42504, 50953,
57322, 2305, 6658, 11012, 15365, 19718, 24072, 28425, 32746, 2306, 4612, 8967,
11273, 13580, 17934, 20240, 22515, 2307, 4615, 8971, 11279, 13587, 17943, 20251,
22527, 2180, 4392, 8652, 10864, 13076, 17304, 19516, 21727, 2116, 6312, 10508,
14672, 18868, 23064, 25180, 29375, 6212, 12456, 20748, 26960, 35252, 41496,
49756, 55999, 8258, 16549, 24840, 33099, 41390, 49681, 57940, 64183, 8192,
16384, 24576, 32768, 40960, 49152, 57344, 63488, 8320, 16640, 24960, 33312,
41632, 49952, 58304, 64576, 6400, 14848, 23296, 29696, 38144, 46592, 52992,
61408, 2304, 6656, 8960, 13312, 15616, 19968, 22272, 26592, 256, 513, 769, 1026,
1283, 1539, 1796, 2021, 258, 517, 776, 1035, 1294, 1552, 1811, 2038, 164, 360,
556, 752, 948, 1144, 1308, 1503, 36, 104, 140, 208, 244, 312, 348, 415, 2052,
4104, 8204, 10256, 14356, 16408, 18460, 22559, 6148, 14344, 20492, 28688, 34836,
43032, 51228, 57375, 8194, 16388, 24582, 32777, 40971, 49165, 57359, 63505
#endif
};

/** Adds value (brightness), possibly negative, to given color (represented by
  its palette index). If you know you'll only be either adding or substracting,
  use plusValue() or minusValue() functions, which should be faster. */
static inline uint8_t palette_addValue(uint8_t color, int8_t add)
{
  uint8_t newValue = color + add;
  
  if ((newValue >> 3) == (color >> 3))
    return newValue;
  else
    return add > 0 ? (color | 0x07) : 0;
}

/** Adds a positive value (brightness) to given color (represented by its
  palette index). This should be a little bit faster than addValue(). */
static inline uint8_t palette_plusValue(uint8_t color, uint8_t plus)
{
  uint8_t newValue = color + plus;
  return ((newValue >> 3) == (color >> 3)) ? newValue : (color | 0x07);
}

/** Substracts a positive value (brightness) from given color (represented by
  its palette index). This should be a little bit faster than addValue(). */
static inline uint8_t palette_minusValue(uint8_t color, uint8_t minus)
{
  uint8_t newValue = color - minus;
  return ((newValue >> 3) == (color >> 3)) ? newValue : 0;
}

#endif //guard
