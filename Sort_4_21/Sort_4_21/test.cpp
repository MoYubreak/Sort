#include"Sort.h"

const int N = 100;
void Init(int* arr)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % (N*10) + 23;
	}
}

void print(int* arr)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[N];
	srand(time(NULL));
	Init(arr);

	//Insert_Sort(arr, N);

	//Shell_Sort(arr, N);

	//Bubble_Sort(arr, N);

	//Select_Sort(arr, N);

	//Quick_Sort(arr, 0, N - 1);

	//merge_Sort(arr, 0, N - 1);

	//merge_Sort(arr, 0, N - 1);

	print(arr);
}