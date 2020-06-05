/*
 * 'newid' - Simple utility for Sony ARW files to replace 'SonyModelId'.
 *           Helps to open an ARW file from "unsupported" camera in your
 *           'old' but trusty ACR or etc.
 *           Simple 'surgical' mod of Dave Coffin's 'dcraw'
 *
 * The code provided "as is" without warranty of any kind, either express
 * or implied. Use at your own risk.
 *
 * wrapper.c
 *
 * Wrapper to call dcraw main()
 *
 * Yuri Sysoyev
 * - 05/06/2020
 */

#include <stdio.h>
#include <stdlib.h>

unsigned char SonyModels[] = "\
2 = DSC-R1                256 = DSLR-A100        257 = DSLR-A900        258 = DSLR-A700\n\
259 = DSLR-A200           260 = DSLR-A350        261 = DSLR-A300        262 = DSLR-A900(APS-C mode)\n\
263 = DSLR-A380/A390      264 = DSLR-A330        265 = DSLR-A230        266 = DSLR-A290\n\
269 = DSLR-A850           270 = DSLR-A850(APS-C) 273 = DSLR-A550        274 = DSLR-A500\n\
275 = DSLR-A450           278 = NEX-5            279 = NEX-3            280 = SLT-A33\n\
281 = SLT-A55/SLT-A55V    282 = DSLR-A560        283 = DSLR-A580        284 = NEX-C3\n\
285 = SLT-A35             286 = SLT-A65/SLT-A65V 287 = SLT-A77/SLT-A77V 288 = NEX-5N\n\
289 = NEX-7               290 = NEX-VG20E        291 = SLT-A37          292 = SLT-A57\n\
293 = NEX-F3              294 = SLT-A99/SLT-A99V 295 = NEX-6            296 = NEX-5R\n\
297 = DSC-RX100           298 = DSC-RX1          299 = NEX-VG900        300 = NEX-VG30E\n\
302 = ILCE-3000/ILCE-3500 303 = SLT-A58          305 = NEX-3N           306 = ILCE-7\n\
307 = NEX-5T              308 = DSC-RX100M2      309 = DSC-RX10         310 = DSC-RX1R\n\
311 = ILCE-7R             312 = ILCE-6000        313 = ILCE-5000        317 = DSC-RX100M3\n\
318 = ILCE-7S             319 = ILCA-77M2        339 = ILCE-5100        340 = ILCE-7M2\n\
341 = DSC-RX100M4         342 = DSC-RX10M2       344 = DSC-RX1RM2       346 = ILCE-QX1\n\
347 = ILCE-7RM2           350 = ILCE-7SM2        353 = ILCA-68          354 = ILCA-99M2\n\
355 = DSC-RX10M3          356 = DSC-RX100M5      357 = ILCE-6300        358 = ILCE-9\n\
360 = ILCE-6500           362 = ILCE-7RM3        363 = ILCE-7M3         364 = DSC-RX0\n\
365 = DSC-RX10M4          366 = DSC-RX100M6      367 = DSC-HX99         369 = DSC-RX100M5A\n\
371 = ILCE-6400           372 = DSC-RX0M2        374 = DSC-RX100M7      375 = ILCE-7RM4\n\
376 = ILCE-9M2            378 = ILCE-6600        379 = ILCE-6100\n\
";

void usage()
{
	printf("usage:\n\
	newid id file.arw - to replace SonyModelId with id\n\
	newid 0 - to list possible SonyModelId's\n");
}

int dcraw_main (int argc, const char **argv);
char *pass_argv[2];

extern int new_model_ID;

int main(int argc, char **argv)
{
int retn;

	if(argc != 3)
	{
		if(argc == 2)
		{
			printf("Sony Model ID's:\n\n%s", SonyModels);
			exit(0);
		}
		usage();
		exit(-1);
	}

	retn = sscanf(argv[1], "%d", &new_model_ID);
	if(EOF == retn)
	{
		printf("Incorrect format of Sony Model ID: must be decimal value. To refer, run 'newid 0'\n");
		exit(-1);
	}

	pass_argv[0] = "dcraw";
	pass_argv[1] = argv[2];
	
	dcraw_main(2, pass_argv);

	exit(0); return 0; // to make compiler happy
}
