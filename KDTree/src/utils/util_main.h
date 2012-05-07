#ifndef UTIL_MAIN_H_
#define UTIL_MAIN_H_


const char* modifiers = "hvi";
const char* guion = "-";
const int lineSize = 80;

static struct option long_options[] = {
		{ "help", no_argument, 0, 'h' },
		{ "version", no_argument, 0, 'v' },
		{ "ignore-case", no_argument, 0, 'i' },
		{ 0, 0, 0, 0 }
};

typedef struct options_flags {
	int flag_ignore; //Si se ingreso ignore-case ignore = 1
	int flag_file1;  //Si hay un archivo de entrada file1 = 1
} Oflags;

Oflags oflags;
int posicionesArchivos[2] = { -1, -1 };

int numParameters = 0;

//Funciones para parsear los parametros
int getOptions(int argc, char** argv, char** ofname);

//Funciones complementarias
void substr(char* cadena, int comienzo, int longitud, char* original) {
	int i;

	for (i = 0; i < longitud && comienzo + i < (signed)strlen(cadena); i++)
		original[i] = cadena[comienzo + i];

	original[i] = '\0';
}

void listBytes(char* string, int offset, char search, char* original) {
	int i = 0;
	while (string[i] != search) {
		i++;
	}
	substr(string, offset, i-offset, original);
}

void toUpper(char* cadena){
	if (oflags.flag_ignore == 1) {
		int k;
		for (k = 0; cadena[k] != '\000'; k++){
			cadena[k] = toupper(cadena[k]);
		}
	}
}



void help() {
	printf("\nUsage: join [OPTION]... FILE1 FILE2");
	printf("\nFor each pair of input lines with identical join fields, write a line to");
	printf("\nstandard output. The default join field is the first, delimited");
	printf("\nby whitespace. When FILE1 or FILE2 (not both) is -, read standard input.");
	printf("\n-i, --ignore-case");
	printf("\n-h, --help");
	printf("\n-v, --version");
	printf("\nignore differences in case when comparing fields");
	printf("\ndisplay this help and exit");
	printf("\noutput version information and exit");
	printf("\nImportant: FILE1 and FILE2 must be sorted on the join fields.");
	printf("\nE.g., use ‘sort -k 1b,1’ if ‘join’ has no options.");
	printf("\nNote, comparisons honor the rules specified by ‘LC_COLLATE’.");
	printf("\nIf the input is not sorted and some lines cannot be joined, a");
	printf("\nwarning message will be given.\n\n");
}

void version() {
	printf("\nOrganizacion de Computadoras - 6620\n\tTP0 - Version 1.0.0 \n\n");
}

int getOptions(int argc, char** argv, char** ofname) {
	int option_index = 0;
	int c;
	opterr = 0;

	while ((c = getopt_long(argc, argv, modifiers, long_options, &option_index)) != EOF) {

		switch (c) {
		case 'h':
			help();
			return -1;
			break;
		case 'v':
			version();
			return -1;
			break;
		case 'i':
			oflags.flag_ignore = 1;
			break;
		default:
			help();
			abort();
		}

	}

	if (optind < argc) {
		int j = 0;
		while (optind < argc && j < 2) {
			oflags.flag_file1 = 1;
			posicionesArchivos[j] = optind++;
			j++;
		}
		numParameters = j;
	}

	return EXIT_SUCCESS;
}


#endif
