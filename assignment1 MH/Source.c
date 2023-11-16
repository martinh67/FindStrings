/* so that scanf can be used without warnings */
#define _CRT_SECURE_NO_WARNINGS

/* in order to use printf, scanf, fopen, fclose functions */
#include <stdio.h>

/* in order to use strlen and strcmp */
#include <string.h>

/* function protoype for reading of the file */
int read_file(const char *file_name, char* array[]);

/* main function that calls read_file and outputs words ending in '...ed' and '...ED' */
int main()
{
	/* declare and intialise variables required */
	int i, length, array_size, can_read = 0;
	char file_name[260];
	char* array[1000];

	/* information regarding the program */
	printf("You will be asked to enter a file path and name\n");
	printf("\nThis will count the number of words ending in '...ed' or '...ED' in the file you have specified\n");

	do
	{
		/* ask the user to input a file */
		printf("\nInput file path and name: ");
		scanf("%s", file_name);

			/* start to read the file */
			if (-1 == (array_size = read_file(file_name, array))) {

				/* give error message if the file could not be found */
				printf("\nSorry, the file could not be opened\n");

				/* introduce a wait */
				getchar();

				/* set the can_read variable to 0 */
				can_read = 0;
			}
			else {
				/* set the can_read variable to 1 */
				can_read = 1;
			}

	} while (can_read == 0);

	/* print the result of the '...ed' words */
	printf("\nThe strings in the file ending in '...ed' are:\n\n");

	/* loop through the '...ed' strings found in the array */
	for (i = 0; i <= array_size; i++) {

		/* get the length of the current string */
		length = strlen(&array[i][0]);

		/* if the string ends in '...ed' print the string*/
		if (strcmp(&array[i][length - 2], "ed") == 0) {
			printf("%s\n", &array[i][0]);
		}

	}

	/* print the result of the '...ED' words */
	printf("\nThe strings in the file ending with '...ED' are:\n\n");

	/* loop through the '...ED' strings found */
	for (i = 0; i <= array_size; i++) {

		/* get the length of the current string */
		length = strlen(&array[i][0]);

		/* if the string ends in '...ed' print the string*/
		if (strcmp(&array[i][length - 2], "ED") == 0) {
			printf("%s\n", &array[i][0]);
		} 

	}

	return 0;

}


/* function to read in file */
int read_file(const char *file_name, char* array[]) {
	/* declare the variables required in the function */
	char buffer[512];
	int i = 0, length;
	FILE * file_in;

	/* open the file to be read from */
	file_in = fopen(file_name, "r");

	/* check if the file was able to be opened*/
	if (!file_in)

		/* return an error to the main function */
		return -1;
	
	/* if the file was opened without an error */
	else
	{
		while (!feof(file_in)) {
			
			/* read one line in to the function */
			fscanf(file_in, "%s", buffer);
			
			/* find the length of the string */
			length = strlen(buffer);
			
			/* allocate a space in memory for the string */
			array[i] = (char*)malloc(length + 1);
			
			/* add a copy of the string to the array */
			strcpy(array[i], buffer);
			
			/* increment the counter variable */
			++i;
		}
	}

	/* close the file read in */
	fclose(file_in);
	
	/* return the elements of the array to the main function */
	return i;
}