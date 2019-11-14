#pragma once
#ifndef HEX32_H
#define HEX32_H

class Hex32
{
	int decimalForm{ 0 };
	unsigned char hexAddress[4]{ 0, 0, 0, 0 };

public:
	void IntToHex(int* intToConvert);
	Hex32(int intToConvert);
	void Print();
};

#endif