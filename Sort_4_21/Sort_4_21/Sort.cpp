#include"Sort.h"

template<typename T >
void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

void Insert_Sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}


void Shell_Sort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;

		for (int i = 0; i < n - gap; i += gap)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

void Bubble_Sort(int* arr, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		bool bl = true;
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				bl = false;
			}
		}
		if (bl)
		{
			break;
		}
	}
}



void Select_Sort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int pi = i;
		int pmin = i;
		while (pi < n)
		{
			if (arr[pi] < arr[pmin])
			{
				pmin = pi;
			}
			pi++;
		}
		swap(arr[i], arr[pmin]);
	}
}


void Quick_Sort(int* arr, int left, int right)
{
	if (left >= right) return;
	int prev = left;
	int cur = left + 1;
	int tmp = arr[left];

	while (cur <= right)
	{
		if (arr[cur] <= tmp)
		{
			prev++;
			swap(arr[cur], arr[prev]);
			cur++;
		}
		else
		{
			cur++;
		}
	}
	swap(arr[prev], arr[left]);
	Quick_Sort(arr, left, prev - 1);
	Quick_Sort(arr, prev + 1 , right);
}



void merge(int* arr, int* brr, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	int left1 = left, right1 = mid, left2 = mid + 1, right2 = right;
	merge(arr, brr, left1, right1);
	merge(arr, brr, left2, right2);

	int t = 0;
	while (left1 <= right1 && left2 <= right2)
	{
		if (arr[left1] <= arr[left2]) brr[t++] = arr[left1++];
		else brr[t++] = arr[left2++];
	}
	while (left1 <= right1) brr[t++] = arr[left1++];
	while (left2 <= right2) brr[t++] = arr[left2++];

	for (left1 = left, t = 0; left1 <= right; left1++,t++)
	{
		arr[left1] = brr[t];
	}
}

void merge_Sort(int* arr, int left , int right)
{
	int* brr = new int[right - left + 1];
	merge(arr, brr, left, right);
	delete[] brr;
}