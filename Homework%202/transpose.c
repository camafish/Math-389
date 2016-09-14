#include <stdio.h>
#include <stdlib.h>

//everything up to writing the new file is identical to the example
int main(int argc, char **argv) {
	FILE *f_in, *f_out;
	int rows, columns;
	int r, c;
	int *table;

	if (argc <= 1) {
		fprintf(stderr, "usage: %s <name of spreadsheet file>\n", argv[0]);
		return -1;
	}

	f_in = fopen(argv[1],"r");
	if (f_in == 0) {
		fprintf(stderr, "Error: file '%s' not found.\n", argv[1]);
		return -1;
	}

	printf("Reading '%s'...\n", argv[1]);
	fscanf(f_in, "%d", &rows);
	fscanf(f_in, "%d", &columns);

	table = (int *)malloc(rows * columns * sizeof(int));
	for (r = 0; r < rows; r++) {
		for (c = 0; c < columns; c++) {
		  fscanf(f_in, "%d", &(table[r*columns+c]));
		}
	}

	fclose(f_in);

	//here we need to modify the code to perform the transpose
	
	char *name; 
	sprintf(name, "transpose_%s",argv[1]); 
	
	f_out = fopen(name,"w");
	if (f_out == 0) {
		fprintf(stderr, "Error: cannot create '%s'.\n", name);
		return -1;
	}
	
	printf("Writing '%s'...\n", name);
	fprintf(f_out, "%d %d\n", columns, rows);
	for (r = 0; r < columns; r++) {
		for (c = 0; c < rows; c++) {
		 // printf("%d %d %d\n", r, c, c*columns + r);
		  fprintf(f_out, "%d ", table[c*columns + r]);
		}
	fprintf(f_out, "\n");
	}
	fclose(f_out);


	return 0;
}
	