#include "Qt_PE_Tool.h"

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <QFileDialog>

Qt_PE_Tool::Qt_PE_Tool(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	ui.tableWidget_Sections->setColumnCount(6);
	ui.tableWidget_Sections->setColumnWidth(0, 80);
	ui.tableWidget_Sections->setColumnWidth(1, 80);
	ui.tableWidget_Sections->setColumnWidth(2, 110);
	ui.tableWidget_Sections->setColumnWidth(3, 110);
	ui.tableWidget_Sections->setColumnWidth(4, 120);
	ui.tableWidget_Sections->setColumnWidth(5, 120);

	QStringList listHeader;
	listHeader << "Name"
		<< "Misc"
		<< "VirtualAddress"
		<< "SizeOfRawData"
		<< "PointerToRawData"
		<< "Characteristics";
	ui.tableWidget_Sections->setHorizontalHeaderLabels(listHeader);

	connect(ui.pushButton_OpenFile, SIGNAL(clicked()), this, SLOT(openExeFile()));
}

Qt_PE_Tool::~Qt_PE_Tool()
{
	if (NULL != itemArr) {
		delete[]itemArr;
	}
}

void Qt_PE_Tool::parsePE(char* filePE)
{
	if (NULL == filePE) {
		return;
	}
	IMAGE_DOS_HEADER dos_header = { 0 };
	IMAGE_FILE_HEADER pe_header = { 0 };
	IMAGE_OPTIONAL_HEADER32 optional_header = { 0 };
	IMAGE_SECTION_HEADER *section_header_arr = NULL;

	// DOS
	memcpy(&dos_header, filePE, sizeof(IMAGE_DOS_HEADER));
	ui.textEdit_FileInfo->append("Size of DOS: " + QString::number(sizeof(IMAGE_DOS_HEADER)));
	ui.lineEdit_e_magic->setText("0x" + QString::number(dos_header.e_magic, 16));
	ui.lineEdit_e_lfanew->setText("0x" + QString::number(dos_header.e_lfanew, 16));

	filePE += dos_header.e_lfanew;

	// PE
	filePE += 4;

	// PE HEADER
	memcpy(&pe_header, filePE, sizeof(IMAGE_FILE_HEADER));
	ui.textEdit_FileInfo->append("Size of PE HEADER: " + QString::number(sizeof(IMAGE_FILE_HEADER)));
	ui.textEdit_FileInfo->append("Size of OPTIONAL PE HEADER: " + QString::number(pe_header.SizeOfOptionalHeader));
	ui.lineEdit_machine->setText("0x" + QString::number(pe_header.Machine, 16));
	ui.lineEdit_NumberOfSections->setText("0x" + QString::number(pe_header.NumberOfSections, 16));
	ui.lineEdit_SizeOfOptionalHeader->setText("0x" + QString::number(pe_header.SizeOfOptionalHeader, 16));
	ui.lineEdit_Characteristics->setText("0x" + QString::number(pe_header.Characteristics, 16));

	// OPTIONAL PE HEADER
	filePE += sizeof(IMAGE_FILE_HEADER);
	memcpy(&optional_header, filePE, sizeof(IMAGE_OPTIONAL_HEADER32));
	ui.lineEdit_Magic->setText("0x" + QString::number(optional_header.Magic, 16));
	ui.lineEdit_SizeOfCode->setText("0x" + QString::number(optional_header.SizeOfCode, 16));
	ui.lineEdit_SizeOfInitializedData->setText("0x" + QString::number(optional_header.SizeOfInitializedData, 16));
	ui.lineEdit_SizeOfUninitializedData->setText("0x" + QString::number(optional_header.SizeOfUninitializedData, 16));
	ui.lineEdit_AddressOfEntryPoint->setText("0x" + QString::number(optional_header.AddressOfEntryPoint, 16));
	ui.lineEdit_BaseOfCode->setText("0x" + QString::number(optional_header.BaseOfCode, 16));
	ui.lineEdit_BaseOfData->setText("0x" + QString::number(optional_header.BaseOfData, 16));
	ui.lineEdit_ImageBase->setText("0x" + QString::number(optional_header.ImageBase, 16));
	ui.lineEdit_SectionAlignment->setText("0x" + QString::number(optional_header.SectionAlignment, 16));
	ui.lineEdit_FileAlignment->setText("0x" + QString::number(optional_header.FileAlignment, 16));
	ui.lineEdit_SizeOfImage->setText("0x" + QString::number(optional_header.SizeOfImage, 16));
	ui.lineEdit_SizeOfHeaders->setText("0x" + QString::number(optional_header.SizeOfHeaders, 16));
	ui.lineEdit_NumberOfAvaAndSizes->setText("0x" + QString::number(optional_header.NumberOfRvaAndSizes, 16));

	// SECTION
	filePE += sizeof(IMAGE_OPTIONAL_HEADER32);
	section_header_arr = (IMAGE_SECTION_HEADER *)malloc(sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);
	if (section_header_arr == NULL) {
		return;
	}
	memset(section_header_arr, 0, sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);
	memcpy(section_header_arr, filePE, sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);

	ui.textEdit_FileInfo->append("Size of SECTION: " + QString::number(sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections));
	
	ui.tableWidget_Sections->setRowCount(pe_header.NumberOfSections);

	itemArr = new QTableWidgetItem[pe_header.NumberOfSections * 6];
	
	for (int i = 0; i < pe_header.NumberOfSections; i++) {
		QString tempData[6] = {
			QLatin1String((char*)(section_header_arr[i].Name)),
			"0x" + QString::number((DWORD)(section_header_arr[i].Misc.PhysicalAddress), 16),
			"0x" + QString::number((DWORD)(section_header_arr[i].VirtualAddress), 16),
			"0x" + QString::number((DWORD)(section_header_arr[i].SizeOfRawData), 16),
			"0x" + QString::number((DWORD)(section_header_arr[i].PointerToRawData), 16),
			"0x" + QString::number((DWORD)(section_header_arr[i].Characteristics), 16),
		};
		for (int j = 0; j < 6; j++) {
			itemArr[i * 6 + j] = QTableWidgetItem(tempData[j]);
			ui.tableWidget_Sections->setItem(i, j, &itemArr[i * 6 + j]);
		}
	}

	memset(section_header_arr, 0, sizeof(IMAGE_SECTION_HEADER)*pe_header.NumberOfSections);
	free(section_header_arr);
}

void Qt_PE_Tool::openExeFile()
{
	QString filePath = QFileDialog::getOpenFileName(0, "Open File", ".", "exe file(*.exe)");
	ui.lineEdit_FilePath->setText(filePath);
	ui.textEdit_FileInfo->clear();

	QByteArray ba = filePath.toLatin1();

	FILE* fp = NULL;
	fp = fopen((const char*)(ba.data()), "rb");
	if (NULL == fp) {
		return;
	}
	fseek(fp, 0, SEEK_END);
	int fileLength = ftell(fp);
	char* arr = (char*)malloc(fileLength * sizeof(char));
	if (NULL == arr) {
		return;
	}
	memset(arr, 0, fileLength);
	fseek(fp, 0, SEEK_SET);
	size_t ret = fread(arr, fileLength, 1, fp);
	if (ret != 1) {
		return;
	}

	parsePE(arr);

	fclose(fp);

	memset(arr, 0, fileLength);
	free(arr);
	arr = NULL;
}