#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

int getTotalDayUpToNow(int iMonth,int isLeapYear)
{
	switch(iMonth)
	{
	case 1:return 0;
	case 2:return 31;
	case 3:return 31+28+isLeapYear;
	case 4:return 31+28+isLeapYear+31;
	case 5:return 31+28+isLeapYear+31+30;
	case 6:return 31+28+isLeapYear+31+30+31;
	case 7:return 31+28+isLeapYear+31+30+31+30;
	case 8:return 31+28+isLeapYear+31+30+31+30+31;
	case 9:return 31+28+isLeapYear+31+30+31+30+31+31;
	case 10:return 31+28+isLeapYear+31+30+31+30+31+31+30;
	case 11:return 31+28+isLeapYear+31+30+31+30+31+31+30+31;
	case 12:return 31+28+isLeapYear+31+30+31+30+31+31+30+31+30;
	default:return -1;
	}
}

int main()
{
	while(1)
	{
		char *dataStr=new char[20];
		printf("输入年/月/日：");
		scanf("%s",dataStr);
		int year = 0, month = 0, day=0, week=0;
		int isLeapYear=-1;
		int d=-1,i=0;

		///提取用户输入的年月日
		while(dataStr[i])
		{
			if((dataStr[i]=='/' || dataStr[i] == '.') && d==-1)
			{
				d=0;
				i++;
				continue;
			}
			if((dataStr[i]=='/' || dataStr[i] == '.') && d==0)
			{
				d=1;
				i++;
				continue;
			}
			if(d==-1)
				year = year*10+(dataStr[i]-'0');
			if(d==0)
				month = month*10+(dataStr[i]-'0');
			if(d==1)
				day = day*10+(dataStr[i]-'0');
			i++;
		}

		if(month<1 || month>12)
		{
			printf("You input a wrong month!");
			exit(0);
		}
		if(day<0 || day>31)
		{
			printf("You input a wrong day!");
			exit(0);
		}

		///判断是否是闰年
		if((year%4==0 && year%100!=0)||(year%100==0 && year%400==0))
			isLeapYear = 1;
		else
			isLeapYear = 0;

		///计算今年到该月1号为止总共的天数
		day = 1+getTotalDayUpToNow(month,isLeapYear);
		d = year-1+(year-1)/4+(year-1)/400-(year-1)/100+day;
		///计算该月1号是星期几
		week = d%7;

		switch(month)
		{
		case 1:month=31;break;
		case 2:month=(isLeapYear==1?29:28);break;
		case 3:month=31;break;
		case 4:month=30;break;
		case 5:month=31;break;
		case 6:month=30;break;
		case 7:month=31;break;
		case 8:month=31;break;
		case 9:month=30;break;
		case 10:month=31;break;
		case 11:month=30;break;
		case 12:month=31;break;
		}

		printf("\n***********************\n");
		printf(" SUN  MON  TUE  WEN  THU  FRI  STA\n");

		for(i=0;i<week;i++)
			printf("     ");
		for(int i=1;i<=month;i++)
		{
			printf(" %2d  ",i);
			week++;
			if(week%7==0 && i!=month)
				printf("\n");
		}

		printf("\n******************************************\n");
	}
	
	printf("\n**************欢迎再次使用**************\n");
	system("pause");
	return 0;
}