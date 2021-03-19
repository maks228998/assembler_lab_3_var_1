#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include "my_lib.h"

int main() {
	printf("Enter the bit sequences\n");
	int number = get_int_number_than_greater_one();
	
	int multiplier = 256;
	int result = 0;

	_asm {
		mov ecx, 8
		mov ebx, 2

			point_one:

				mov eax, number
				mov edx, 0
				div ebx;
				imul edx, multiplier
				add result, edx
				mov number, eax
				mov eax, multiplier
				mov edx, 0
				div ebx;
				mov multiplier, eax
				mov eax, number

			loop point_one 
	}
	
	printf("Result: %d", result);
}