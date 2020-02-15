
#include <QtCore/QCoreApplication>
#include <iostream>
#include <Windows.h>
using namespace std;
#define MB (1024*1024)
#define GB (1024*1024*1024)

////获取硬盘空间
////driver:磁盘名
////flag：1-空闲磁盘大小；0-磁盘总大小
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

///获取系统CPU使用率
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

	///__int64是C++的64位扩展，无符号的表示范围是[0,2^64),有符号的范围为[-2^63,2^63)
	__int64 idle = CompareFileTime(preidleTime, idleTime);  
	__int64 kernel = CompareFileTime(prekernelTime, kernelTime);  
	__int64 user = CompareFileTime(preuserTime, userTime);  

	__int64 cpu = (kernel + user - idle) * 100 / (kernel + user);  
	__int64 cpuidle = (idle)* 100 / (kernel + user);  
	cout << "CPU利用率:" << cpu << "%" << " CPU空闲率:" << cpuidle << "%" << endl;   
} 

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);

	cout<<"CPU "<<endl;
	cout<<"处理器掩码:"<<system_info.dwActiveProcessorMask<<endl;
	cout<<"处理器个数:"<<system_info.dwNumberOfProcessors<<endl;
	cout<<"处理器类型:"<<system_info.dwProcessorType<<endl;
	cout<<"处理器等级:"<<system_info.wProcessorLevel<<endl;
	cout<<"处理器版本:"<<system_info.wProcessorRevision<<endl;

	MEMORYSTATUSEX memoryState;
	memoryState.dwLength = sizeof(memoryState);
	GlobalMemoryStatusEx(&memoryState);
	cout<<"\n内存\n"<<"物理内存使用率:"<<memoryState.dwMemoryLoad<<endl;
	cout<<"物理内存总量:"<<float(memoryState.ullTotalPhys)/GB<<"GB"<<endl;
	cout<<"可用的物理内存:"<<float(memoryState.ullAvailPhys)/GB<<"GB"<<endl;
	//cout<<"系统页面文件大小:"<<memoryState.ullTotalPageFile/MB<<"MB"<<endl;
	//cout<<"系统可用页面文件大小:"<<memoryState.ullAvailPageFile/MB<<"MB"<<endl;
	cout<<"虚拟内存总量:"<<float(memoryState.ullTotalVirtual)/GB<<"GB"<<endl;
	cout<<"可用的虚拟内存:"<<float(memoryState.ullAvailVirtual)/GB<<"GB"<<endl;

	cout<<"\n硬盘空间\n";
	///总的硬盘大小
	quint64 diskC = getDiskSpace("C:/",0);
	quint64 diskD = getDiskSpace("D:/",0);
	quint64 diskE = getDiskSpace("E:/",0);
	quint64 diskF = getDiskSpace("F:/",0);
	quint64 diskG = getDiskSpace("G:/",0);
	///空闲硬盘大小
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

	cout<<"\nCPU使用率\n";
	getCpuUsage();

	return a.exec();
}
