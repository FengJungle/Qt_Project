#pragma once

typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef unsigned long  DWORD;
typedef unsigned long  LONG;
typedef unsigned char  BYTE;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

typedef struct _IMAGE_DOS_HEADER { // DOS的.EXE头部
	USHORT e_magic;    // * MZ标记，用于判断是否为可执行文件
	USHORT e_cblp;     // 文件最后页的字节数 
	USHORT e_cp;       // 文件页数 
	USHORT e_crlc;     // 重定义元素个数 
	USHORT e_cparhdr;  // 头部尺寸，以段落为单位 
	USHORT e_minalloc; // 所需的最小附加段 
	USHORT e_maxalloc; // 所需的最大附加段 
	USHORT e_ss;       // 初始的SS值（相对偏移量）
	USHORT e_sp;       // 初始的SP值 
	USHORT e_csum;     // 校验和 
	USHORT e_ip;       // 初始的IP值 
	USHORT e_cs;       // 初始的CS值（相对偏移量）
	USHORT e_lfarlc;   // 重分配表文件地址
	USHORT e_ovno;     // 覆盖号 
	USHORT e_res[4];   // 保留字
	USHORT e_oemid;    // OEM标识符（相对e_oeminfo）
	USHORT e_oeminfo;  // OEM信息
	USHORT e_res2[10]; // 保留字
	LONG e_lfanew;     // * 指示NT头的偏移（根据不同文件拥有可变值），用于定位PE文件
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_FILE_HEADER {
	WORD    Machine;              // * 每个CPU拥有唯一的Machine码 -> 4C 01 -> PE -> 兼容32位Intel X86芯片

	WORD    NumberOfSections;     // * 指文件中存在的节段（又称节区）数量，也就是节表中的项数
	                              //   该值一定要大于0，且当定义的节段数与实际不符时，将发生运行错误。

	DWORD   TimeDateStamp;         // PE文件的创建时间，一般有编译器填写
	DWORD   PointerToSymbolTable; 
	DWORD   NumberOfSymbols;      

	WORD    SizeOfOptionalHeader; // * 指出IMAGE_OPTIONAL_HEADER32结构体的长度。默认：32位-E0，64位-F0

	WORD    Characteristics;      // * 标识文件的属性，二进制中每一位代表不同属性
	                              //   属性参见https://blog.csdn.net/qiming_zhang/article/details/7309909#3.2.2'
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
	DWORD   VirtualAddress;
	DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

typedef struct _IMAGE_OPTIONAL_HEADER {
	WORD    Magic;                      // * 说明文件类型 32位为0x10B，64位为0x20B
	BYTE    MajorLinkerVersion;         
	BYTE    MinorLinkerVersion;         
	DWORD   SizeOfCode;                 // * 所有代码节的和，一般放在“.text”节里，必须是FileAlignment的整数倍，编译器填写
	DWORD   SizeOfInitializedData;      // * 已初始化数据大小，一般放在“.data”节里，必须是FileAlignment的整数倍，编译器填写
	DWORD   SizeOfUninitializedData;    // * 未初始化数据大小，一般放在“.bss”节里，必须是FileAlignment的整数倍，编译器填写
	DWORD   AddressOfEntryPoint;        // * 程序入口点 OEP
	DWORD   BaseOfCode;                 // * 代码基址，当镜像被加载进内存时代码节的开头RVA。必须是SectionAlignment的整数倍，编译器填写
	DWORD   BaseOfData;                 // * 数据基址，当镜像被加载进内存时数据节的开头RVA。必须是SectionAlignment的整数倍，编译器填写
										//   在64位文件中此处被并入紧随其后的ImageBase中。

	DWORD   ImageBase;                  // * 当加载进内存时，镜像的第1个字节的首选地址。
		// Windows EXE默认ImageBase值为00400000，DLL文件的ImageBase值为10000000，也可以指定其他值。
		// 执行PE文件时，PE装载器先创建进程，再将文件载入内存
		// 然后把EIP寄存器的值设置为  ImageBase + AddressOfEntryPoint

	    // PE文件的Body部分被划分成若干节段，这些节段储存着不同类别的数据。
	DWORD   SectionAlignment;           // * 内存对齐大小
	DWORD   FileAlignment;              // * 文件对齐大小
									    //   SectionAlignment必须大于或者等于FileAlignment

	WORD    MajorOperatingSystemVersion;// 主系统的主版本号
	WORD    MinorOperatingSystemVersion;// 主系统的次版本号
	WORD    MajorImageVersion;          // 镜像的主版本号
	WORD    MinorImageVersion;          // 镜像的次版本号
	WORD    MajorSubsystemVersion;      // 子系统的主版本号
	WORD    MinorSubsystemVersion;      // 子系统的次版本号
	DWORD   Win32VersionValue;          // 保留，必须为0 

	DWORD   SizeOfImage;                // * 内存中整个PE文件的大小。向上舍入为SectionAlignment的倍数。
										// * 一般文件大小与加载到内存中的大小是不同的

	DWORD   SizeOfHeaders;              // * 所有头（DOS头+PE标记+标准PE头+可选PE头）+节表 的总大小，向上舍入为FileAlignment的倍数。
										// * 可以以此值作为PE文件第一节的文件偏移量

	DWORD   CheckSum;                   // 镜像文件的校验和

	WORD    Subsystem;                  // 运行此镜像所需的子系统
										// 用来区分系统驱动文件（*.sys)与普通可执行文件（*.exe，*.dll），
		// 参考：https://blog.csdn.net/qiming_zhang/article/details/7309909#3.2.3'

	WORD    DllCharacteristics;         // DLL标识 -> 00 00
	DWORD   SizeOfStackReserve;         // 最大栈大小。CPU的堆栈。默认是1MB。-> 00 10 00 00
	DWORD   SizeOfStackCommit;          // 初始提交的堆栈大小。默认是4KB -> 00 00 10 00
	DWORD   SizeOfHeapReserve;          // 最大堆大小。编译器分配的。默认是1MB ->00 10 00 00
	DWORD   SizeOfHeapCommit;           // 初始提交的局部堆空间大小。默认是4K ->00 00 10 00
	DWORD   LoaderFlags;                // 保留，必须为0 -> 00 00 00 00

	DWORD   NumberOfRvaAndSizes;        // 指定DataDirectory的数组个数，由于以前发行的Windows NT的原因，它只能为16。 -> 00 00 00 10
	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES]; // 数据目录数组。详见下文。
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

//
// Section header format.
// 节表
//

#define IMAGE_SIZEOF_SHORT_NAME              8

typedef struct _IMAGE_SECTION_HEADER {
	BYTE    Name[IMAGE_SIZEOF_SHORT_NAME]; //* 节的名字
	union {
		DWORD   PhysicalAddress;
		DWORD   VirtualSize;
	} Misc;                                //* 该节在没有内存对齐前的真实尺寸
	DWORD   VirtualAddress;                //* 节区在内存中的偏移地址，加上ImageBase才是在内存中真正的地址
	DWORD   SizeOfRawData;                 //* 该节在文件对齐后的真实尺寸
	DWORD   PointerToRawData;              //* 节区在文件中的偏移（文件对齐的整数倍）
	DWORD   PointerToRelocations;
	DWORD   PointerToLinenumbers;
	WORD    NumberOfRelocations;
	WORD    NumberOfLinenumbers;
	DWORD   Characteristics;               //* 属性，根据属性来分析该节是什么内容
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;