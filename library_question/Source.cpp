#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 7

typedef struct {
	int id;
	char name[50];
	double price;
}bookInfo_t;

void menu() {
	printf("1. Display the curent library\n");
	printf("2. Add new book to the library\n");
	printf("3. EXIT\n");
	printf("\n");
}

int readFromFile(FILE* inp, bookInfo_t arr[]) {
	int i = 0;
	while (fscanf(inp, "%d %s %lf", &arr[i].id, arr[i].name, &arr[i].price) != EOF)
		i++;
	return (i);
}

void display(bookInfo_t arr[], int size) {
	printf("Current Library\n");
	printf("****************\n");
	for (int k = 0; k < size; k++)
	{
		printf("ID : %d\n", arr[k].id);
		printf("Name : %s\n", arr[k].name);
		printf("Price : %.2f\n", arr[k].price);
		printf("\n");
	}
}

int newRecord(bookInfo_t arr[], int size) {
	printf("Please enter new book info\n");

	printf("Enter Book ID: ");
	scanf("%d", &arr[size].id);

	printf("Enter Book Name: ");
	scanf(" %[^\n]", arr[size].name);

	printf("Enter Book Price: ");
	scanf("%lf", &arr[size].price);

	printf("New record succesfully added!\n");
	return(size + 1);
}

int main(void)
{
	FILE* inp;
	inp = fopen("books.txt", "r");
	if (inp == NULL)
		printf("ERROR");
	else
	{
		bookInfo_t arr[MAX];
		int size = readFromFile(inp, arr);
		fclose(inp);

		int choice;
		do {
			menu();

			printf("Enter choice: ");
			scanf("%d", &choice);
			if (choice < 1 || choice > 3)
				while (choice < 1 || choice > 3)
				{
					printf("Re-enter choice: ");
					scanf("%d", &choice);
				}
			printf("\n");

			switch (choice)
			{
			case 1:
				display(arr, size);
				break;
			case 2 :
				if (size != MAX)
					size = newRecord(arr, size);
				else
					printf("The library is full!!!\n");
				break;
			}
			printf("\n");
		} while (choice != 3);
		printf("Goodbye\n");
	}
	return 0;
}