#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


//#define DEBUG

void parsePE(char* filePE) {
	if (NULL == filePE) {
		printf("filePE is NULL!\n");
		return;
	}
	IMAGE_DOS_HEADER dos_header = { 0 };
	IMAGE_FILE_HEADER pe_header = { 0 };
	IMAGE_OPTIONAL_HEADER32 optional_header = { 0 };
	IMAGE_SECTION_HEADER *section_header_arr = NULL;

#ifdef DEBUG
	printf("======================================filePE:\t%p\n", filePE);
#endif

	printf("************       DOS     *************\n");
	memcpy(&dos_header, filePE, sizeof(IMAGE_DOS_HEADER));
	printf("sizeof DOS:\t%d\n", sizeof(IMAGE_DOS_HEADER));
	printf("e_magic:\t0x%x\n", dos_header.e_magic);
	printf("e_lfanew:\t0x%x\n", dos_header.e_lfanew);
	printf("****************************************\n\n");

	filePE += dos_header.e_lfanew;
#if defined DEBUG
	printf("======================================filePE:\t%p\n", filePE);
#endif
	 
	printf("*************     PE_HEADER    *********\n");
	printf("sizeof PE_HEADER:\t%d\n", sizeof(IMAGE_FILE_HEADER));
	// PE 头标记
	filePE += 4;
#if defined DEBUG
	printf("======================================filePE:\t%p\n", filePE);
#endif
	// PE 头
	memcpy(&pe_header, filePE, sizeof(IMAGE_FILE_HEADER));
	printf("Machine:\t\t0x%x\n", pe_header.Machine);
	printf("NumberOfSections:\t0x%x\n", pe_header.NumberOfSections);
	printf("SizeOfOptionalHeader:\t0x%x\n", pe_header.SizeOfOptionalHeader);
	printf("Characteristics:\t0x%x\n", pe_header.Characteristics);
	printf("****************************************\n\n");

	// 可选PE头
	printf("**********  OPTIONAL PE HEADER    ***********\n");
	filePE += sizeof(IMAGE_FILE_HEADER);
	memcpy(&optional_header, filePE, sizeof(IMAGE_OPTIONAL_HEADER32));
#if defined DEBUG
	printf("======================================filePE:\t%p\n", filePE);
#endif
	printf("sizeof IMAGE_OPTIONAL_HEADER32:\t%d\n", sizeof(IMAGE_OPTIONAL_HEADER32));
	printf("Magic:\t\t\t0x%x\n", optional_header.Magic);
	printf("SizeOfCode:\t\t0x%x\n", optional_header.SizeOfCode);
	printf("SizeOfInitializedData:\t0x%x\n", optional_header.SizeOfInitializedData);
	printf("AddressOfEntryPoint:\t0x%x\n", optional_header.AddressOfEntryPoint);
	printf("BaseOfCode:\t\t0x%x\n", optional_header.BaseOfCode);
	printf("BaseOfData:\t\t0x%x\n", optional_header.BaseOfData);
	printf("ImageBase:\t\t0x%x\n", optional_header.ImageBase);
	printf("SectionAlignment:\t0x%x\n", optional_header.SectionAlignment);
	printf("FileAlignment:\t\t0x%x\n", optional_header.FileAlignment);
	printf("SizeOfImage:\t\t0x%x\n", optional_header.SizeOfImage);
	printf("SizeOfHeaders:\t\t0x%x\n", optional_header.SizeOfHeaders);
	printf("NumberOfRvaAndSizes:\t0x%x\n", optional_header.NumberOfRvaAndSizes);
	printf("****************************************\n\n");

	
	// 节表
	filePE += sizeof(IMAGE_OPTIONAL_HEADER32);
	//filePE += 16;
	section_header_arr = (IMAGE_SECTION_HEADER *)malloc(sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);
	if (section_header_arr == NULL) {
		printf("malloc failed!\n");
		return;
	}
	memset(section_header_arr, 0, sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);
	memcpy(section_header_arr, filePE, sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);


	printf("************     SECTION   *************\n");
	printf("sizeof SECTION:\t\t%d\n", sizeof(IMAGE_SECTION_HEADER));
	printf("Number Of SECTIONS:\t%d\n", pe_header.NumberOfSections);

#if defined DEBUG
	printf("======================================filePE:\t%p\n", filePE);
#endif
	for (int i = 0; i < pe_header.NumberOfSections; i++) {
		printf("\n++++++     ");
		for (int j = 0; j < 8; j++) {
			printf("%c", section_header_arr[i].Name[j]);
		}
		printf("     ++++++\n");
		printf("Misc:\t\t\t0x%x\n", section_header_arr[i].Misc);
		printf("VirtualAddress:\t\t0x%x\n", section_header_arr[i].VirtualAddress);
		printf("SizeOfRawData:\t\t0x%x\n", section_header_arr[i].SizeOfRawData);
		printf("PointerToRawData:\t0x%x\n", section_header_arr[i].PointerToRawData);
		printf("Characteristics:\t0x%x\n", section_header_arr[i].Characteristics);
	}
	printf("****************************************\n\n");
	
	memset(section_header_arr, 0, sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);
	free(section_header_arr);
}

bool func(char* filepath) {
	FILE* fp = NULL;
	fp = fopen(filepath, "rb");
	if (NULL == fp) {
		printf("fopen failed!\n");
		return false;
	}
	fseek(fp, 0, SEEK_END);
	int fileLength = ftell(fp);
	char* arr = (char*)malloc(fileLength * sizeof(char));
	if (NULL == arr) {
		printf("malloc failed!\n");
		return false;
	}
	memset(arr, 0, fileLength);
	fseek(fp, 0, SEEK_SET);
	size_t ret = fread(arr, fileLength, 1, fp);
	if (ret != 1) {
		printf("fread failed! Actual read:%d\n", ret);
		return false;
	}
	printf("Address in Memory: %p\n", arr);

	parsePE(arr);

	fclose(fp);

	memset(arr, 0, fileLength);
	free(arr);
	arr = NULL;

	return true;
}

int main()
{
	char choice = 0;
	char filePath[60] = { 0 };

_start:
	printf("Input .exe file path: ");
	scanf("%s", filePath);
	func(filePath);
	memset(filePath, 0, sizeof(filePath));

	getchar();
	printf("\n\nContinue(C) or Exit(E)?\n");
	scanf("%c", &choice);

	if ('C' == choice) {
		goto _start;
	}
	if ('E' == choice) {
		return 0;
	}
	printf("wrong input! exit!");
	return 0;
}