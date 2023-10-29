#pragma once
#include <iostream>
#include <time.h>

using namespace std;
void array_generate(int N, int a[])
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
}


int search(int* array, int max_number, int current_index, int size)
{
	int temp = 0;
	if (array[current_index] > max_number) { temp = current_index; max_number = array[current_index]; }
	if (current_index == size - 1) return temp;
	int temp2 = search(array, max_number, current_index + 1, size);
	if (temp < temp2) return temp2; else return temp;
}


void maxElem() {
	cout << "Enter size of array: ";
	int N;
	cin >> N;
	int* a = new int[N];
	array_generate(N, a);
	int max_index = search(a, a[0], 1, N);
	cout << "\nMaximum element a[" << max_index << "]=" << a[max_index] << endl;
	system("pause");
	delete[] a;
}