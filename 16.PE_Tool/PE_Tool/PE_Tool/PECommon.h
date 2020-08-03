#pragma once

typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef unsigned long  DWORD;
typedef unsigned long  LONG;
typedef unsigned char  BYTE;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

typedef struct _IMAGE_DOS_HEADER { // DOS��.EXEͷ��
	USHORT e_magic;    // * MZ��ǣ������ж��Ƿ�Ϊ��ִ���ļ�
	USHORT e_cblp;     // �ļ����ҳ���ֽ��� 
	USHORT e_cp;       // �ļ�ҳ�� 
	USHORT e_crlc;     // �ض���Ԫ�ظ��� 
	USHORT e_cparhdr;  // ͷ���ߴ磬�Զ���Ϊ��λ 
	USHORT e_minalloc; // �������С���Ӷ� 
	USHORT e_maxalloc; // �������󸽼Ӷ� 
	USHORT e_ss;       // ��ʼ��SSֵ�����ƫ������
	USHORT e_sp;       // ��ʼ��SPֵ 
	USHORT e_csum;     // У��� 
	USHORT e_ip;       // ��ʼ��IPֵ 
	USHORT e_cs;       // ��ʼ��CSֵ�����ƫ������
	USHORT e_lfarlc;   // �ط�����ļ���ַ
	USHORT e_ovno;     // ���Ǻ� 
	USHORT e_res[4];   // ������
	USHORT e_oemid;    // OEM��ʶ�������e_oeminfo��
	USHORT e_oeminfo;  // OEM��Ϣ
	USHORT e_res2[10]; // ������
	LONG e_lfanew;     // * ָʾNTͷ��ƫ�ƣ����ݲ�ͬ�ļ�ӵ�пɱ�ֵ�������ڶ�λPE�ļ�
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_FILE_HEADER {
	WORD    Machine;              // * ÿ��CPUӵ��Ψһ��Machine�� -> 4C 01 -> PE -> ����32λIntel X86оƬ

	WORD    NumberOfSections;     // * ָ�ļ��д��ڵĽڶΣ��ֳƽ�����������Ҳ���ǽڱ��е�����
	                              //   ��ֵһ��Ҫ����0���ҵ�����Ľڶ�����ʵ�ʲ���ʱ�����������д���

	DWORD   TimeDateStamp;         // PE�ļ��Ĵ���ʱ�䣬һ���б�������д
	DWORD   PointerToSymbolTable; 
	DWORD   NumberOfSymbols;      

	WORD    SizeOfOptionalHeader; // * ָ��IMAGE_OPTIONAL_HEADER32�ṹ��ĳ��ȡ�Ĭ�ϣ�32λ-E0��64λ-F0

	WORD    Characteristics;      // * ��ʶ�ļ������ԣ���������ÿһλ����ͬ����
	                              //   ���Բμ�https://blog.csdn.net/qiming_zhang/article/details/7309909#3.2.2'
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
	DWORD   VirtualAddress;
	DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

typedef struct _IMAGE_OPTIONAL_HEADER {
	WORD    Magic;                      // * ˵���ļ����� 32λΪ0x10B��64λΪ0x20B
	BYTE    MajorLinkerVersion;         
	BYTE    MinorLinkerVersion;         
	DWORD   SizeOfCode;                 // * ���д���ڵĺͣ�һ����ڡ�.text�����������FileAlignment������������������д
	DWORD   SizeOfInitializedData;      // * �ѳ�ʼ�����ݴ�С��һ����ڡ�.data�����������FileAlignment������������������д
	DWORD   SizeOfUninitializedData;    // * δ��ʼ�����ݴ�С��һ����ڡ�.bss�����������FileAlignment������������������д
	DWORD   AddressOfEntryPoint;        // * ������ڵ� OEP
	DWORD   BaseOfCode;                 // * �����ַ�������񱻼��ؽ��ڴ�ʱ����ڵĿ�ͷRVA��������SectionAlignment������������������д
	DWORD   BaseOfData;                 // * ���ݻ�ַ�������񱻼��ؽ��ڴ�ʱ���ݽڵĿ�ͷRVA��������SectionAlignment������������������д
										//   ��64λ�ļ��д˴��������������ImageBase�С�

	DWORD   ImageBase;                  // * �����ؽ��ڴ�ʱ������ĵ�1���ֽڵ���ѡ��ַ��
		// Windows EXEĬ��ImageBaseֵΪ00400000��DLL�ļ���ImageBaseֵΪ10000000��Ҳ����ָ������ֵ��
		// ִ��PE�ļ�ʱ��PEװ�����ȴ������̣��ٽ��ļ������ڴ�
		// Ȼ���EIP�Ĵ�����ֵ����Ϊ  ImageBase + AddressOfEntryPoint

	    // PE�ļ���Body���ֱ����ֳ����ɽڶΣ���Щ�ڶδ����Ų�ͬ�������ݡ�
	DWORD   SectionAlignment;           // * �ڴ�����С
	DWORD   FileAlignment;              // * �ļ������С
									    //   SectionAlignment������ڻ��ߵ���FileAlignment

	WORD    MajorOperatingSystemVersion;// ��ϵͳ�����汾��
	WORD    MinorOperatingSystemVersion;// ��ϵͳ�Ĵΰ汾��
	WORD    MajorImageVersion;          // ��������汾��
	WORD    MinorImageVersion;          // ����Ĵΰ汾��
	WORD    MajorSubsystemVersion;      // ��ϵͳ�����汾��
	WORD    MinorSubsystemVersion;      // ��ϵͳ�Ĵΰ汾��
	DWORD   Win32VersionValue;          // ����������Ϊ0 

	DWORD   SizeOfImage;                // * �ڴ�������PE�ļ��Ĵ�С����������ΪSectionAlignment�ı�����
										// * һ���ļ���С����ص��ڴ��еĴ�С�ǲ�ͬ��

	DWORD   SizeOfHeaders;              // * ����ͷ��DOSͷ+PE���+��׼PEͷ+��ѡPEͷ��+�ڱ� ���ܴ�С����������ΪFileAlignment�ı�����
										// * �����Դ�ֵ��ΪPE�ļ���һ�ڵ��ļ�ƫ����

	DWORD   CheckSum;                   // �����ļ���У���

	WORD    Subsystem;                  // ���д˾����������ϵͳ
										// ��������ϵͳ�����ļ���*.sys)����ͨ��ִ���ļ���*.exe��*.dll����
		// �ο���https://blog.csdn.net/qiming_zhang/article/details/7309909#3.2.3'

	WORD    DllCharacteristics;         // DLL��ʶ -> 00 00
	DWORD   SizeOfStackReserve;         // ���ջ��С��CPU�Ķ�ջ��Ĭ����1MB��-> 00 10 00 00
	DWORD   SizeOfStackCommit;          // ��ʼ�ύ�Ķ�ջ��С��Ĭ����4KB -> 00 00 10 00
	DWORD   SizeOfHeapReserve;          // ���Ѵ�С������������ġ�Ĭ����1MB ->00 10 00 00
	DWORD   SizeOfHeapCommit;           // ��ʼ�ύ�ľֲ��ѿռ��С��Ĭ����4K ->00 00 10 00
	DWORD   LoaderFlags;                // ����������Ϊ0 -> 00 00 00 00

	DWORD   NumberOfRvaAndSizes;        // ָ��DataDirectory�����������������ǰ���е�Windows NT��ԭ����ֻ��Ϊ16�� -> 00 00 00 10
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES]; // ����Ŀ¼���顣������ġ�
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

//
// Section header format.
// �ڱ�
//

#define IMAGE_SIZEOF_SHORT_NAME              8

typedef struct _IMAGE_SECTION_HEADER {
	BYTE    Name[IMAGE_SIZEOF_SHORT_NAME]; //* �ڵ�����
	union {
		DWORD   PhysicalAddress;
		DWORD   VirtualSize;
	} Misc;                                //* �ý���û���ڴ����ǰ����ʵ�ߴ�
	DWORD   VirtualAddress;                //* �������ڴ��е�ƫ�Ƶ�ַ������ImageBase�������ڴ��������ĵ�ַ
	DWORD   SizeOfRawData;                 //* �ý����ļ���������ʵ�ߴ�
	DWORD   PointerToRawData;              //* �������ļ��е�ƫ�ƣ��ļ��������������
	DWORD   PointerToRelocations;
	DWORD   PointerToLinenumbers;
	WORD    NumberOfRelocations;
	WORD    NumberOfLinenumbers;
	DWORD   Characteristics;               //* ���ԣ����������������ý���ʲô����
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;