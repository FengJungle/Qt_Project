#ifndef __DATA_H__
#define __DATA_H__

#include <string>


// �Զ�������ݽṹ���������⸴�ӣ��˴���Ϊʾ��
class Data
{

public:
	Data(int size = 1) :raw_data_size(size)
	{
		raw_data = new char[raw_data_size];
		memset(raw_data, 9, raw_data_size);
	}
	~Data()
	{
		if (raw_data)
		{
			delete[] raw_data;
			raw_data = nullptr;
		}
	}
	int getRawDataSize()
	{
		return raw_data_size;
	}

private:
	int dims[3];
	char* raw_data = nullptr;
	int raw_data_size = 0;
};

Q_DECLARE_METATYPE(Data)

#endif