#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int strLen(char* str) {
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

char* scanString() {
	rewind(stdin);
	int size = 2;
	char* str = (char*)malloc(sizeof(char) * size);
	for (; (str[size - 2] = getchar()) != '\n'; size++) {
		str = (char*)realloc(str, size * sizeof(char));
	}
	str[size - 2] = '\0';
	return str;
}

void replaceElements(char* ptr, int size, char a, char b) {
	for (int i = 0; i < size; i++)
		if (ptr[i] == a) ptr[i] = b;
}

void scanInt(int* ptr) {
	while (1) {
		char* str = scanString();
		if (sscanf(str, "%d %1[^\n]", ptr, ptr) != 1) {
			printf("Wrong input\n");
		}
		else
			break;
	}
}

void scanDouble(double* ptr) {
	while (1) {
		char* str = scanString();
		replaceElements(str, 1024, ',', '.');
		if (sscanf(str, "%lf %1[^\n]", ptr, ptr) != 1) {
			printf("Wrong input\n");
		}
		else
			break;
	}
}

void scanFloat(float* ptr) {
	while (1) {
		char* str = scanString();
		replaceElements(str, strLen(str), ',', '.');
		if (sscanf(str, "%f %1[^\n]", ptr, ptr) != 1) {
			printf("Wrong input\n");
		}
		else
			break;
	}
}
void scanLong(long* ptr) {
	while (1) {
		char* str = scanString();
		if (sscanf(str, "%ld %1[^\n]", ptr, ptr) != 1) {
			printf("Wrong input\n");
		}
		else
			break;
	}
}

void scanChar(char* ptr) {
	while (1) {
		char* str = scanString();
		if (strLen(str) != 1) {
			printf("Wrong input\n");
		}
		else {
			*ptr = str[0];
			break;
		}
	}
	
}