#include <stdio.h>
#include <malloc.h>
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





	int main() {


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

	seminar1 seminar1_obj;
	Homework1 homework1_obj;
	// homework1_obj.read_from_console_write_to_file_vextor();
	// homework1_obj.read_from_file_print_to_console_vector();
	// homework1_obj.read_from_console_write_to_file_matrix();
	homework1_obj.read_from_file_print_to_console_matrix();
}
