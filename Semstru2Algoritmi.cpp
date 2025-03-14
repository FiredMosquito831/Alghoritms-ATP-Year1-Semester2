#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h> //; cannot have instrutions outside functions
 // instruction terminator is ; it is also an empty instruction
#define MAX 10

class seminar1 {
public:

	void debugging()
	{
		float v[MAX], max;
		int n, poz, i;
		printf_s("\nNumber of elements:");
		scanf_s("%d", &n);		
		for (i = 0; i < n; i++)
		{
			printf_s("v[%d]=",i);
				scanf_s("%f", &v[i]); // or v + i
		}

		printf_s("\n The read vector has %d elements:\n", n);
		for (i = 0; i < n; i++)
			printf_s(" %.2f", v[i]); // total number of charcaters and the second is the precsion, number of digits x.y - x total num of char and y total num of decimals

		max = v[0];
		poz = 0;
		for (i = 1; i < n; i++)
			if (v[i] > max)
			{
				max = v[i];
				poz = i;
			}

		printf_s("\nThe highest element is: %.2f, on position %d", max, poz);
		printf_s("\nDone, press a key to exit...");
		_getch(); // part of conion it is used to add a pause
	}

	int main() {


		return 0;
	}

};


class seminar2 {
public:





	int main() {


		return 0;
	}

};
class seminar3 {
public:

	class offsets {
	public:
		typedef struct {
			short int a;
			char b;
			int c;
			long d;
		} V1;

		typedef struct {
			char b;
			int c;
			short int a;
			long d;
		} V2;

		typedef struct {
			int c;
			short int a;
			long d;
			char b;
		} V3;
		
		void main()
		{
			V1 x;
			V2 y;
			V3 z;

			printf_s("\nsize of V1: %d", sizeof(V1));
			printf_s("\nsize of V2: %d", sizeof(V2));
			printf_s("\nsize of V3: %d", sizeof(V3));

			printf_s("\n\nOffsets for V1"); // begining from start of structure to the begining of the field
			printf_s("\na: %2d\nb: %2d\nc: %2d\nd: %2d", (char*)&x.a - (char*)&x,
				(char*)&x.b - (char*)&x,
				(char*)&x.c - (char*)&x,
				(char*)&x.d - (char*)&x);
			printf_s("\n\nOffsets for V2");
			printf_s("\nb: %2d\nc: %2d\na: %2d\nd: %2d", (char*)&y.b - (char*)&y,
				(char*)&y.c - (char*)&y,
				(char*)&y.a - (char*)&y,
				(char*)&y.d - (char*)&y);
			printf_s("\n\nOffsets for V3");
			printf_s("\nc: %2d\na: %2d\nd: %2d\nb: %2d", (char*)&z.c - (char*)&z,
				(char*)&z.a - (char*)&z,
				(char*)&z.d - (char*)&z,
				(char*)&z.b - (char*)&z);
		}

	};

	void test_bucla_cifre() {
		char text[100];
		int number;


		printf("\n1st attempt to read a text after reading a number");
		printf("\nNumber: ");
		scanf_s("%d", &number);
		printf("I read this number: %d", number);
		printf("\nText: ");
		gets_s(text);
		printf("\nI read this text: -->%s<--", text);

		printf("\n\n2nd attempt to read a text after reading a number");
		printf("\nNumber: ");
		scanf_s("%d", &number);
		printf("I read this number: %d", number);
		printf("\nText: ");
		fflush(stdin);
		gets_s(text);
		printf("\nI read this text: -->%s<--", text);

		printf("\n\n3rd attempt to read a text after reading a number");
		printf("\nNumber: ");
		scanf_s("%d", &number);
		printf("I read this number: %d", number);
		printf("\nText: ");
		gets_s(text); //or use some other string variable   // clear buffer works in context if we a carriage return in the buffer (if buffer empty then will just take input)
		             // use only if we know there will be a carriage in buffer, have carriage if we read text after a number
		gets_s(text);  // now reads input
		printf("\nI read this text: -->%s<--", text);

		printf("\n\n1st attempt to read in a loop, control field is a number");
		printf("\nNumber: ");
		// readin gfile alghoritm
		scanf_s("%d", &number);
		while (!feof(stdin)) // not enter end of file
		{
			// process what was read
			printf("I read this number: %d", number);
			printf("\nNext number (or CTRL+Z): "); // tell user how to exit loop
			scanf_s("%d", &number);
		}
		printf("\nOut of the loop!");
		// start we want to run with a clean buffer
		//test this with and without the previous code!
		printf("\n\n2nd attempt to read in a loop, control field is a string");
		printf("\nText: ");
		gets_s(text); // will fail because there still are characters in the buffer from the ctrl+z (x3) (^Z ^Z ^Z)
		while (!feof(stdin))
		{
			printf("\nI read this text: -->%s<--", text);
			printf("\nNext text (or CTRL+Z): ");
			gets_s(text);
		}
		printf("\nOut of the loop!");
		// we want to run with a clean buffer
		// finish
		printf("\n\n3rd attempt to read in a loop, control field is a number");
		printf("\nNumber: ");
		scanf_s("%d", &number);
		while (number != 0)		//conventional value, depending on problem
		{
			printf("I read this number: %d", number);
			printf("\nNext number (or 0): "); // we tell the convention to the user
			scanf_s("%d", &number);
		}
		printf("\nOut of the loop!");

		printf("\n\n");

	}

	class create_and_populate_k {
	public:
		typedef struct {
			int nrm;             //enrolment number
			char CNP[14];        //string ASCIIZ
			char nume[30];       //string
			int an;              //study year // unsing char would be more eff but next we def an int which takes 4 and we would have 1 0 0 0 1 1 1 1, we waste 3 bytes
			int grupa;           //group
			unsigned char note[20];  //grades
		} STUDENT;

		void main()
		{
			char numef[30] = ".\\Studenti_s_k.dat";
			FILE* f;
			STUDENT x;
			int i;

			//printf_s("File name: ");
			//gets_s(numef);
			fopen_s(&f, numef, "wb"); // create file on the disk binary and if it exists delete, recommended to try opening with r if it opens then ask user for a new file name homework


			printf_s("Enrollment number: "); 
			scanf_s("%d", &x.nrm); // first control number
			while (x.nrm != 0)			//convention, to avoid microsoft issues, while enrollment is diff from 0
				//while (!feof(stdin))	//replace with another convention in visual studio
			{						//for example while(x.nrm) to stop when a zero is entered
									//it still works if the first field is a string, not a number
				printf_s("CNP: "); /*fflush(stdin);  fo rother environments*/ /* clear buffer*/ gets_s(x.CNP); /* now reads*/gets_s(x.CNP);
				printf_s("Name: "); gets_s(x.nume);
				printf_s("Year: "); scanf_s("%d", &x.an);
				printf_s("Group: "); scanf_s("%d", &x.grupa);
				for (i = 0; i < 20; i++)
					x.note[i] = 0; // fill the vector with 0 since all initial grades are 0
				fwrite(&x, sizeof(STUDENT), 1, f); // write a record to the file
				// fwrite (record, sizeof(RECORD) used to move all the bytes of record, 1 (mention how many arrays of structsyou want, number of continous blocks we will always transfer 1 record so we will have only 1) ,f); f is the internal file pointer 
				printf_s("Enrollment number: ");
				scanf_s("%d", &x.nrm);
			}

			fclose(f);

			printf_s("\nDone. File <%s> was created. Press a key...", numef);
			_getch();
		}
	};

	class full_list_read_bin_file {
	public:
		typedef struct {
			int nrm;             //enrolment number
			char CNP[14];        //string ASCIIZ
			char nume[30];       //string
			int an;              //study year
			int grupa;           //group
			unsigned char note[20];  //grades
		} STUDENT;


		void main()
		{
			char numefd[30], numeft[30];
			FILE* f, * g;
			STUDENT x;
			int crt, j;


			//strcpy(numefd, "..\\Studenti_s_f1.dat"); strcpy(numeft, "..\\Report1.txt");
			strcpy_s(numefd, ".\\Studenti_s.dat"); strcpy_s(numeft, ".\\Full list.txt");

			fopen_s(&f, numefd, "rb");
			if (!f)
				printf_s("\nYou have probably misplaced your file. Stopping here.");
			else
			{
				fopen_s(&g, numeft, "wt");
				fprintf_s(g, "%4s %4s %-30s %-14s %2s %4s %4s", "Crt.", "Nrm.", "Nume", "CNP", "An", "Gr.", "Note"); 
				crt = 0;
				fread(&x, sizeof(STUDENT), 1, f);
				while (!feof(f)) // while reading is succesful
				{ // processes record

					fprintf_s(g, "\n%4d %4d %-30s %-14s %2d %2d ", ++crt, x.nrm, x.nume, x.CNP, x.an, x.grupa);
					for (j = 0; j < 20; j++)
						fprintf_s(g, "%2d ", x.note[j]);
					fread(&x, sizeof(STUDENT), 1, f);
				}

				fclose(g);
				fclose(f);
				printf_s("\nThe full list is in <%s>.", numeft);
			}

			printf_s("\nDone. Press a key");
			_getch();
		}
	};

	int main() {

		//offsets offset_obj;
		//offset_obj.main();
		create_and_populate_k create_and_populate_k_obj;
		create_and_populate_k_obj.main();
		full_list_read_bin_file full_list_read_bin_file_obj;
		full_list_read_bin_file_obj.main();
		return 0;
	}

};

class Homework1 {
public:
	void read_from_console_write_to_file_vector() {
		printf_s("Input vector size: \n");
		int size;
		scanf_s("%d", &size);
		int* vector = (int*)malloc(size * sizeof(int));
		printf_s("Input the elements of the vector:\n");
		for (int i = 0; i < size; i++) {
			scanf_s("%d", &vector[i]);
		}

		FILE* f;
		int error = fopen_s(&f, "./test_vector.txt", "w");
		if (error != 0) {
			printf("Error %d, opening file.", error);
			
		}
		for (int i = 0; i < size; i++) {
			//fprintf_s(stdout, "%d ", vector[i]);
			fprintf_s(f, "%d ", vector[i]);
		}

		fprintf_s(f, "\n");
		fclose(f);
		printf_s("Saved to file");
	}

	void read_from_file_print_to_console_vector() {
		FILE* f;
		int error = fopen_s(&f, "./test_vector.txt", "r");
		if (error != 0) {
			printf_s("Error %d reading file."); }
		fseek(f, 0, SEEK_END); // goes to the end of file
		int file_len = ftell(f);
		printf("\n%d\n", file_len);
		rewind(f); // goes back to the start of file
		int* vector = (int*)malloc(file_len * sizeof(int));
		int pos_pointer_and_size = 0;
		//int vector[100];
		if (f) {
			int element;
			fscanf_s(f, "%d", &element);
			while (!feof(f)) {
				vector[(pos_pointer_and_size)++] = element;
				fscanf_s(f, "%d", &element);
			}
		}
		for (int i = 0; i < pos_pointer_and_size; i++) {
			printf_s("%d ", vector[i]);
		}
	}



	void read_from_console_write_to_file_matrix() {
		int rows, cols;
		printf_s("Please input the number of rows:\n");
		scanf_s("%d", &rows);
		printf_s("Please input the number of columns:\n");
		scanf_s("%d", &cols);
		int** matrix = (int**)malloc(rows * sizeof(int));
		for (int i = 0; i < rows; i++) {
			matrix[i] = (int*)malloc(cols * sizeof(int));
		}

		printf_s("Please input the matrix elements:\n ");
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				scanf_s("%d", &matrix[i][j]);
				// fprintf_s(f, "%d ", matrix[i][j]);
				
			}
			// fprintf_s(f, "\n");
		}
		                                                             
		FILE* f;

		int error = fopen_s(&f, "./test_matrix.txt", "w");
		if (error != 0) {
			printf_s("Error %d opening file.", error);
		}
		fprintf_s(f, "%d %d\n", rows, cols);

		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				fprintf_s(f, "%d ", matrix[i][j]);
			}
			fprintf_s(f, "\n");
		}


		fprintf_s(f, "\n");
		fclose(f);

		printf_s("Sucess!");

		
	}

	void read_from_file_print_to_console_matrix() {

		FILE* f;
		int error = fopen_s(&f, "./test_matrix.txt", "r");
		if (error != 0) {
			printf_s("Error %d opening file.", error);
		}
		//// go to the end
		//fseek(f, 0, SEEK_END);

		//int file_len = ftell(f); // tells the current position
		//rewind(f); // go back to the start

		//int index = 0;

		int cols, rows;

		fscanf_s(f, "%d", &cols);
		fscanf_s(f, "%d", &rows);
		printf("%d %d\n", cols, rows);
		int** matrix = (int**)malloc(cols * sizeof(int));
		for (int i = 0; i < cols; i++) {
			matrix[i] = (int*)malloc(rows * sizeof(int));
		}
		int element;
		for (int i = 0; i < cols && !feof(f); i++) {
			for (int j = 0; j < rows && !feof(f); j++) {
				fscanf_s(f, "%d", &matrix[i][j]);
				printf_s("%d ", matrix[i][j]);
			}
			printf_s("\n");
		}

		fclose(f);
	
	}

};

int main() {

	// seminar1 seminar1_obj;
	// Homework1 homework1_obj;
	// homework1_obj.read_from_console_write_to_file_vextor();
	// homework1_obj.read_from_file_print_to_console_vector();
	// homework1_obj.read_from_console_write_to_file_matrix();
	// homework1_obj.read_from_file_print_to_console_matrix();
	seminar3 seminar3_obj;
	seminar3_obj.main();
}
