#include <iostream>
#include <fstream>

#include "Hex32.h"

int main()
{
	// Gets the file path from the user input
	std::wcout << L"Enter a file path: ";
	std::wstring filePath;
	std::wcin >> filePath;
	// C:\Users\alexs\source\repos\HexConverterApplication\ExeToHexApplication\x64\Release\ExeToHexApplication.exe
	// Creates a txt file to write the Hex code to
	std::wofstream hexTextFile;
	hexTextFile.open(L"Hex.txt");

	// Reads an exe to copy to the txt file
	std::wifstream readExeFile;
	readExeFile.open(filePath, std::wfstream::binary | std::wfstream::in);

	// Gets the next character and counts what column the program is in
	wchar_t c{ 0 };
	short int count{ 0 };
	// Counts 16 hex codes for each row
	short int const MAX_COUNT{ 16 };
	short int rowOfNumbers[MAX_COUNT];
	unsigned long long int addressLine{ 0 };

	hexTextFile << L"000000000" << std::hex << addressLine << L"\t";
	addressLine += 16;

	// Reads through each character in the exe and turns it into hex as well as it's unicode character
	while (readExeFile.get(c)) {
		unsigned char decimalForm{ static_cast<unsigned char>(c) };

		// Checks to see if the value is 0 to make the file organized
		if (decimalForm == 0) {
			hexTextFile << L"00 ";
		}
		else {
			if (decimalForm < 16) {
				hexTextFile << L"0";
			}
			hexTextFile << std::hex << decimalForm << L" ";
		}
		rowOfNumbers[count] = decimalForm;
		++count;

		// Prints the characters in unicode after 16 hex codes and then moves onto the next line
		if (count == 16) {
			hexTextFile << L"\t";

			for (short int i = 0; i < MAX_COUNT; ++i) {
				// Codes for NULL or a new line
				if (rowOfNumbers[i] == 0 || rowOfNumbers[i] == 13 || rowOfNumbers[i] == 10) {
					hexTextFile << L".";
				}
				else {
					hexTextFile << static_cast<wchar_t>(rowOfNumbers[i]);
				}

			}

			hexTextFile << L"\n";
			count = 0;

			unsigned long long int amountDivided{ addressLine / 16 };
			if (amountDivided < 16) {
				hexTextFile << L"00000000";
			}
			else if (amountDivided < 256) {
				hexTextFile << L"0000000";
			}
			else if (amountDivided < 4096) {
				hexTextFile << L"000000";
			}
			else if (amountDivided < 65536) {
				hexTextFile << L"00000";
			}
			else if (amountDivided < 1048576) {
				hexTextFile << L"0000";
			}
			else if (amountDivided < 16777216) {
				hexTextFile << L"000";
			}
			else if (amountDivided < 268435456) {
				hexTextFile << L"00";
			}

			hexTextFile << std::hex << addressLine << L"\t";
			addressLine += 16;
		}
	}

	hexTextFile.close();
	readExeFile.close();
}