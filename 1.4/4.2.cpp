//4.2
/*
си подобный подход такой: храним массив из char-ов; видел где-то сериализацию - пирмерно так писали. Не знаю круто или нет..По-моему прикольно 
Надеюсь я не совершаю какую-нибудь ужасную ошибку

А еще есть темплейты - можно юзать тот же вектор, но там бует вызов деструкторов для каждого объекта данных, который мы храним..
*/

#include "stdio.h"
#include <cstdlib>
#include <string>
#include <iostream>
	
#define halfabstract

halfabstract struct dataWrapper
{
	char* data;
};

class DataTypeInt4 : public dataWrapper
{
public:
	void parseData()
	{
		printf("%d\n", *(int*)data);
	}

	void setData(int* data_in, size_t size_in)
	{
		data = (char*)data_in;
	}
};

/*
	либо как-то так: будем хранить данные в обертке, которая умеет интерпретировать эти данные и работать с ними
*/

enum T
{
	INT,
	//DOUBLE,
	//NODE,
	NONE
};

class UnknownType
{
public:
	UnknownType(T type_in)
	{
		type_we_point_to = type_in;
	}

	T type_we_point_to = NONE;
	void* pointer_to_data = nullptr;
	int len = 0;
	
	void converter(void* data)
	{
		if(type_we_point_to == INT)
		{
			len = sizeof(int);
			pointer_to_data = (int*)malloc(sizeof(len));
			pointer_to_data = (int*)data;
		}
	}

	void printData()
	{
		if(type_we_point_to == INT)
		{
			printf("%d\n", *(int*)pointer_to_data);
		}
	}

	//void serializeData();
	//остальные методы которые нам нужны
};

int main()
{
	
	//int* intData = (int*)malloc(sizeof(int));
	int* intData = new int(1);
	
	*intData = 14;
	DataTypeInt4 d;
	d.setData(intData, sizeof(int));
	d.parseData();

	//free(intData);
	delete intData;
	int data = 18;
	UnknownType t(INT);
	t.converter(&data);
	t.printData();
	

	printf("%d\n", 	data);
	printf("--------\n");
	return 0;
}
