#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct Aelem
{
	Aelem() : data(rand()){}
	int data;
};

auto Asort = [](Aelem const&a, Aelem const& b) {
    return  a.data < b.data;
};

void swap(Aelem *xp, Aelem *yp) 
{ 
    Aelem temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void sortAelems(Aelem* arr, int n)
{
	int i, j; 
   	bool swapped; 
   	for (i = 0; i < n-1; i++) 
   	{ 
    	swapped = false; 
     	for (j = 0; j < n-i-1; j++) 
     	{ 
        	if (Asort(arr[j],arr[j+1])) 
        	{ 
        	   swap(&arr[j], &arr[j+1]); 
        	   swapped = true; 
        	} 
        }
    } 
}

int main()
{
	Aelem* arr = new Aelem[1000];
	sortAelems(arr, 1000);
	for(int i = 0; i < 1000; ++i)
		std::cout << arr[i].data << " ";
	return 0;
}