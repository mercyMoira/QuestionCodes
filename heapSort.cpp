/* ******************************************** */
/*						*/
/*		# Dev.  : mercyMoira		*/
/*		# Cont. : HeapSorting		*/
/*		# Date  : 2019-04-16		*/
/*						*/
/* ******************************************** */

#include <iostream>
using namespace std;

void buildHeap(int *, int);
void heapify(int *, int, int);
void heapSort(int *, int);

// 입력 배열을 힙 구조로 만들기
void buildHeap(int *pArr, int index)
{
	for(int i=0; i<index/2; i++)
		heapify(pArr, i, index);
}

// 최소힙으로 정렬
void heapify(int *pArr, int k, int index)
{
	int left  = 2 * k;
	int right = 2 * k + 1;
	int smaller = k;

	// choosing a node what is smaller between left and right
	if(right <= index)
	{
		if(pArr[left] < pArr[right])
			smaller = left;
		else
			smaller = right;
	}
	
	else if(left <= index)
		smaller = left;
		
	else
		return;
		
	// recursion
	if(pArr[smaller] < pArr[k])
	{
		int temp = pArr[k];
		pArr[k] = pArr[smaller];
		pArr[smaller] = temp;
		
		heapify(pArr, smaller, index);
	}
}

// 힙정렬
void heapSort(int* pArr, int index)
{
	buildHeap(pArr, index);
	
	for(int i=1; i<index; i++)
	{
		int temp = pArr[0];
		pArr[0] = pArr[i];
		pArr[i] = temp;
		
		heapify(pArr, 0, i-1);
	}
}

int main()
{
	int index;
	cin >> index;
	
	int *pArr = new int[index];
	for(int i=0; i<index; i++)
		cin >> pArr[i];
		
	heapSort(pArr, index - 1);
	for(int i=0; i<index; i++)
		cout << pArr[i] << ' ';
	cout << endl;
	
	delete [] pArr;
	
	return 0;
}
