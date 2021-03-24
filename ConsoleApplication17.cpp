#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include "my_lib.h"

int main() {
	printf("Enter the bit sequences\n");
	int number = get_int_number_than_greater_min_and_less_max(0, 255);
	int result = 0;
	int debug = 256;
	
	_asm {
		mov ecx, 7
		mov ebx, 0
		mov eax, number

			point_one:

				mov edx, eax 
				and edx, 00000001b
				or ebx, edx
				ror eax, 1
				rol ebx, 1

			loop point_one

		mov eax, ebx
		div debug
		mov result, edx
	}

	printf("Result: %d", result);
}
