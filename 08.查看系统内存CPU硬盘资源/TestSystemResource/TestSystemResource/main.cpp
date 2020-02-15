
#include <QtCore/QCoreApplication>
#include <iostream>
#include <Windows.h>
using namespace std;
#define MB (1024*1024)
#define GB (1024*1024*1024)

////��ȡӲ�̿ռ�
////driver:������
////flag��1-���д��̴�С��0-�����ܴ�С
quint64 getDiskSpace(QString driver,int flag)
{
	LPCWSTR lpcwstrDriver=(LPCWSTR)driver.utf16();
	ULARGE_INTEGER liFreeBytesAvailable, liTotalBytes, liTotalFreeBytes;
	if( !GetDiskFreeSpaceEx( lpcwstrDriver, &liFreeBytesAvailable, &liTotalBytes, &liTotalFreeBytes) )
	{
		cout << "ERROR: Call to GetDiskFreeSpaceEx() failed.";
		return 0;
	}
	if(flag==0)
		return (quint64) liTotalBytes.QuadPart/1024/1024/1024;
	if(flag==1)
		return (quint64) liTotalFreeBytes.QuadPart/1024/1024/1024;
	else 
		return 0;
}

__int64 CompareFileTime(FILETIME time1, FILETIME time2)  
{  
	__int64 a = time1.dwHighDateTime << 32 | time1.dwLowDateTime;  
	__int64 b = time2.dwHighDateTime << 32 | time2.dwLowDateTime;  

	return (b - a);  
}

///��ȡϵͳCPUʹ����
void getCpuUsage(){  
	HANDLE hEvent;  
	BOOL res;  
	FILETIME preidleTime;  
	FILETIME prekernelTime;  
	FILETIME preuserTime;  
	FILETIME idleTime;  
	FILETIME kernelTime;  
	FILETIME userTime;  

	res = GetSystemTimes(&idleTime, &kernelTime, &userTime);  
	preidleTime = idleTime;  
	prekernelTime = kernelTime;  
	preuserTime = userTime;  

	hEvent = CreateEventA(NULL, FALSE, FALSE, NULL);   

	WaitForSingleObject(hEvent, 1000);  
	res = GetSystemTimes(&idleTime, &kernelTime, &userTime);  

	///__int64��C++��64λ��չ���޷��ŵı�ʾ��Χ��[0,2^64),�з��ŵķ�ΧΪ[-2^63,2^63)
	__int64 idle = CompareFileTime(preidleTime, idleTime);  
	__int64 kernel = CompareFileTime(prekernelTime, kernelTime);  
	__int64 user = CompareFileTime(preuserTime, userTime);  

	__int64 cpu = (kernel + user - idle) * 100 / (kernel + user);  
	__int64 cpuidle = (idle)* 100 / (kernel + user);  
	cout << "CPU������:" << cpu << "%" << " CPU������:" << cpuidle << "%" << endl;   
} 

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);

	cout<<"CPU "<<endl;
	cout<<"����������:"<<system_info.dwActiveProcessorMask<<endl;
	cout<<"����������:"<<system_info.dwNumberOfProcessors<<endl;
	cout<<"����������:"<<system_info.dwProcessorType<<endl;
	cout<<"�������ȼ�:"<<system_info.wProcessorLevel<<endl;
	cout<<"�������汾:"<<system_info.wProcessorRevision<<endl;

	MEMORYSTATUSEX memoryState;
	memoryState.dwLength = sizeof(memoryState);
	GlobalMemoryStatusEx(&memoryState);
	cout<<"\n�ڴ�\n"<<"�����ڴ�ʹ����:"<<memoryState.dwMemoryLoad<<endl;
	cout<<"�����ڴ�����:"<<float(memoryState.ullTotalPhys)/GB<<"GB"<<endl;
	cout<<"���õ������ڴ�:"<<float(memoryState.ullAvailPhys)/GB<<"GB"<<endl;
	//cout<<"ϵͳҳ���ļ���С:"<<memoryState.ullTotalPageFile/MB<<"MB"<<endl;
	//cout<<"ϵͳ����ҳ���ļ���С:"<<memoryState.ullAvailPageFile/MB<<"MB"<<endl;
	cout<<"�����ڴ�����:"<<float(memoryState.ullTotalVirtual)/GB<<"GB"<<endl;
	cout<<"���õ������ڴ�:"<<float(memoryState.ullAvailVirtual)/GB<<"GB"<<endl;

	cout<<"\nӲ�̿ռ�\n";
	///�ܵ�Ӳ�̴�С
	quint64 diskC = getDiskSpace("C:/",0);
	quint64 diskD = getDiskSpace("D:/",0);
	quint64 diskE = getDiskSpace("E:/",0);
	quint64 diskF = getDiskSpace("F:/",0);
	quint64 diskG = getDiskSpace("G:/",0);
	///����Ӳ�̴�С
	quint64 diskC1 = getDiskSpace("C:/",1);
	quint64 diskD1 = getDiskSpace("D:/",1);
	quint64 diskE1 = getDiskSpace("E:/",1);
	quint64 diskF1 = getDiskSpace("F:/",1);
	quint64 diskG1 = getDiskSpace("G:/",1);
	cout<<"C-Total:"<<diskC<<"G\tFree:"<<diskC1<<"G"<<endl;
	cout<<"D-Total:"<<diskD<<"G\tFree:"<<diskD1<<"G"<<endl;
	cout<<"E-Total:"<<diskE<<"G\tFree:"<<diskE1<<"G"<<endl;
	cout<<"F-Total:"<<diskF<<"G\tFree:"<<diskF1<<"G"<<endl;
	cout<<"G-Total:"<<diskG<<"G\tFree:"<<diskG1<<"G"<<endl;

	cout<<"\nCPUʹ����\n";
	getCpuUsage();

	return a.exec();
}
