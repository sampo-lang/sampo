/*
 ============================================================================
 Name        : rivita.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, kpl;

char rivi[67];
char otsikko[80];
FILE *infile;
FILE *outfile;

int main(int argc, const char *argv[]) {
	char *nimi = argv[1];
	char source[100], dest[100];
	strcpy(source, nimi);
	strcat(source, ".blk\0");
	strcpy(dest, nimi);
	strcat(dest, ".txt\0");

	infile = fopen(source, "rb");
	if (infile == NULL) {
		printf("infile error\n");
	}

	outfile = fopen(dest, "wb");
	if (outfile == NULL) {
		printf("outfile error\n");
		return -1;
	}

	rivi[64] = '\r';
	rivi[65] = '\n';

	for (i = 0; i < 10000; i++) {

		kpl = fread(rivi, sizeof(char), 64, infile);

		if (kpl < 64) {
			fclose(infile);
			fclose(outfile);
			return EXIT_SUCCESS;
		}
		/*
		if (i % 16 == 0) {
			sprintf(otsikko, "\n\n*** ruutu %i ****\n\0", i / 16);
			fwrite(otsikko, sizeof(char), strlen(otsikko), outfile);
		}
		*/
		fwrite(rivi, sizeof(char), 64, outfile);

	}

}
