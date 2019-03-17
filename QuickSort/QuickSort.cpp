#include <iostream>
using namespace std;
enum TypeOfNumber
{
	Odd, Even
};
void quickSortOddEven(int *numbers, int left, int right, bool oddorEven)
{
	if (right - left == 0) return;
	int pivot = numbers[left];
	int left_pointer = left;
	int right_pointer = right;
	while (left < right)
	{
		if (oddorEven == Odd)
		{
			while ((numbers[right] >= pivot) && (left < right))
				right--;
		}
		else
		{
			while ((numbers[right] <= pivot) && (left < right))
				right--;
		}
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		if (oddorEven == Odd)
		{
			while ((numbers[left] <= pivot) && (left < right))
				left++;
		}
		else
		{
			while ((numbers[left] >= pivot) && (left < right))
				left++;
		}
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = left_pointer;
	right = right_pointer;
	if (left < pivot)
		if (oddorEven == Odd)
		{
			quickSortOddEven(numbers, left, pivot - 1, Odd);
		}
		else
		{
			quickSortOddEven(numbers, left, pivot - 1, Even);
		}

	if (right > pivot)
		if (oddorEven == Odd)
		{
			quickSortOddEven(numbers, pivot + 1, right, Odd);
		}
		else
		{
			quickSortOddEven(numbers, pivot + 1, right, Even);
		}
}
void SortOddEven(int *numbers, int size, int& step)
{
	bool flag = false;//переменная, используемая для последовательного пропуска четных чисел, если они первые в массиве
	int number;
	for (int i = 0; i < size; i++)
	{

		if (numbers[i] % 2 == 1)
		{
			step++;
			flag = true;

		}
		else
		{
			if (flag == true)
			{
				number = numbers[i - step];
				numbers[i - step] = numbers[i];
				numbers[i] = number;
				if (i != size - 1)
				{
					i = i - step;
					step = 0;

				}
			}

		}
	}

}
void QuickSort(int *numbers, int size)
{
	if (size > 1) //сортировка не выполняется с одной цифрой в массиве
	{
		int step = 0;
		SortOddEven(numbers, size, step);//перносим в левую сторону четные числа, переносим в правую сторону нечетные
		if ((step != 0) && (step != size))//сортировка не выполняется, когда в массиве все цифры одинаковые
		{
			quickSortOddEven(numbers, 0, size - step - 1, Odd);
			quickSortOddEven(numbers, size - step, size - 1, Even);
		}
	}

}
int main()
{
	int size;
	cin >> size;
	int *mas = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> mas[i];

	}
	QuickSort(mas, size);
	for (int j = 0; j < size; j++)
	{
		cout << mas[j];
	}
	return 0;
}