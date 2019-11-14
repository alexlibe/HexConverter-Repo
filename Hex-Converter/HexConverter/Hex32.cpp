#include <iostream>
#include "Hex32.h"

Hex32::Hex32(int intToConvert) {
	decimalForm = intToConvert;

	IntToHex(&intToConvert);
}

void Hex32::IntToHex(int* intToConvert) {
	int quotient{ *intToConvert / 16 };
	int remainder{ *intToConvert % 16 };
	unsigned char count{ 3 };

	while (quotient != 0) {

		switch (remainder) {
		case 10: {
			hexAddress[count] = 65;
			--count;
			break;
		}
		case 11: {
			hexAddress[count] = 66;
			--count;
			break;
		}
		case 12: {
			hexAddress[count] = 67;
			--count;
			break;
		}
		case 13: {
			hexAddress[count] = 68;
			--count;
			break;
		}
		case 14: {
			hexAddress[count] = 69;
			--count;
			break;
		}
		case 15: {
			hexAddress[count] = 70;
			--count;
			break;
		}
		default: {
			hexAddress[count] = remainder;
			--count;
			break;
		}
		}

		quotient /= 16;
		remainder %= 16;
	}
}

void Hex32::Print() {
	for (int i = 0; i < 4; ++i) {
		std::wcout << hexAddress[i];
	}
}