#include <stdio.h>
#include <stdlib.h> // для использования функций system()
#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

//Алгоритмы сортировки
//пузырьковая сортировка
void BubleSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "До сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (arrNumber[j - 1] > arrNumber[j]) // если текущий элемент меньше предыдущего
			{
				int temp = arrNumber[j - 1]; // меняем их местами
				arrNumber[j - 1] = arrNumber[j];
				arrNumber[j] = temp;
			}
		}
	}
	cout << "После сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}

//сортировка выбором
void selectionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "До сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	//Организуем цикл для всех элементов кроме последнего
	int min, temp; // для поиска минимального элемента и для обмена
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // запоминаем индекс текущего элемента
				 // ищем минимальный элемент чтобы поместить на место i-ого

		for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
		{
			if (arrNumber[j] < arrNumber[min]) // если элемент меньше минимального,
				min = j;       // запоминаем его индекс в min
		}
		temp = arrNumber[i];      // меняем местами i-ый и минимальный элементы
		arrNumber[i] = arrNumber[min];
		arrNumber[min] = temp;
	}

	cout << "После сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}
}

//сортировка вставками
void inclusionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "До сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	// Для всех элементов кроме начального
	for (int i = 1; i < size; i++)
	{
		int value = arrNumber[i]; // запоминаем значение элемента
		int index = i;     // и его индекс

		while ((index > 0) && (arrNumber[index - 1] > value))
		{
			// смещаем другие элементы к концу массива пока они меньше index
			arrNumber[index] = arrNumber[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		arrNumber[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
	cout << "После сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}


//Алгоритмы поиска 
//бинарный
void BinarySearch()
{
	int count = 0;
	int k[20];
	int r[20];
	int key, i;

	system("cls");

	// Инициализация ключевых полей упорядоченными значениями
	k[0] = 8;  k[1] = 14;
	k[2] = 26;  k[3] = 28;
	k[4] = 38;  k[5] = 47;
	k[6] = 56;  k[7] = 60;
	k[8] = 64;  k[9] = 69;
	k[10] = 70; k[11] = 78;
	k[12] = 80; k[13] = 82;
	k[14] = 84; k[15] = 87;
	k[16] = 90; k[17] = 92;
	k[18] = 98; k[19] = 108;

	// Ввод записей
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "Введите key: ";
	cin >> key;

	int left = 0; // задаем левую и правую границы поиска
	int right = 19;

	int search = -1; // найденный индекс элемента равен -1 (элемент не найден)

	while (left <= right) // пока левая граница не "перескочит" правую
	{
		count++;
		int mid = (left + right) / 2; // ищем середину отрезка

		// если ключевое поле равно искомому
		// мы нашли требуемый элемент, выходим из цикла
		if (key == k[mid])
		{
			search = mid;
			break;
		}


		if (key < k[mid])     // если искомое ключевое поле меньше найденной середины
			right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
		else
			left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
	}

	if (search == -1)     // если индекс элемента по-прежнему -1, элемент не найден
		cout << "Элемент не найден!" << endl;
	else          // иначе выводим элемент, его ключ и значение
		cout << "k[" << search << "]=" << k[search] << " (за " << count << " проходов)" << endl;

	cout << endl;
}

//линейный
void LineSearch()
{
	int k[20];
	int key, i;

	system("cls");

	// Инициализация ключевых полей упорядоченными значениями
	k[0] = 8;  k[1] = 14;
	k[2] = 26;  k[3] = 28;
	k[4] = 38;  k[5] = 47;
	k[6] = 56;  k[7] = 60;
	k[8] = 64;  k[9] = 69;
	k[10] = 70; k[11] = 78;
	k[12] = 80; k[13] = 82;
	k[14] = 84; k[15] = 87;
	k[16] = 90; k[17] = 92;
	k[18] = 98; k[19] = 108;

	// Ввод записей
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "Введите key: ";
	cin >> key;

	for (i = 0; i < 19; i++) // просматриваем все элементы в цикле
	{
		if (k[i] == key)      // если находим элемент со значением key,
		{
			cout << i << endl;     // возвращаем его индекс
			break;
		}

	}
	cout << "элемент не найден за " << i << " шагов" << endl;
}

void testFunc(); //прототип функции

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int n;
	cout << "Введите номер задания: ";
	cin >> n;

	switch (n)
	{


	case 1:
	{
		/*1.	Используя датчик случайных чисел,
		заполнить массив из двадцати элементов
		неповторяющимися числами*/
		int A[20] = {0}, temp, flag = 0, count = 0;
		for (int i = 0; i < 20; i++)
		{
			do
			{
				temp = 10 + rand() % 100;
				flag = 1;
				for (int j = 0; j < 20; j++)
				{
					count++;
					if (A[j] == temp)
					{
						flag = 0;
						break;
					}

				}
			} while (flag == 0);

			A[i] = temp;
			cout << A[i] << endl;

		}

		cout << endl;
		cout << count << endl;
	}
		break;
	case 2:
	{
		/*2.	Определить: 
			a.	сумму всех элементов массива; 
			b.	произведение всех элементов массива; 
			c.	сумму квадратов всех элементов массива; 
			d.	сумму шести первых элементов массива; 
			e.	сумму элементов массива с k1-го по k2-й 
			    (значения k1 и k2 вводятся  с клавиатуры; k2 > k1); 
			f.	среднее арифметическое всех элементов массива; 
			g.	среднее арифметическое элементов массива 
				с s1-го по s2-й (значения s1 и s2 вводятся с клавиатуры; 
				s2 > s1).*/

			int A[20] = { 0 },i, j, k1, k2, s1, s2, sum, mult, square, first6, sumK;
			int sumS, count;
			double average, averageS;

			mult = 1;
			first6 = 0;
			sum = 0;
			square = 1;
				for (i = 0; i < 20; i++)
				{
					A[i] = 10 + rand() % 100;
					cout << "А[" << i << "]=" << A[i] << endl;
					sum += A[i];
					mult*= A[i];
					if(i<6) first6+= A[i];
					square += A[i] * A[i];
				}

				average = sum / 20;

				cout << "Сумма всех элементов массива - " << sum << endl;
				cout << "Произведение всех элементов массива - " << mult << endl;
				cout << "Сумма квадратов всех элементов массива - " << square << endl;
				cout << "Сумма шести первых элементов массива - " << first6 << endl;
				cout << "Среднее арифметическое всех элементов массива - " << average << endl;

					do
					{
						cout << "Должно выполнятся k2 > k1";
						cout << "Введите значения еще раз:" << endl;
						cout << "Введите значение k1: ";
						cin >> k1;
						cout << "Введите значение k2: ";
						cin >> k2;

					}while (k1 > k2);


					sumK = 0;

					for (i = k1; i < k2; i++)
					{			
						cout << "А[" << i << "]=" << A[i] << endl;
						sumK += A[i];
					}

					cout << "Сумма элементов массива с k1-го по k2-й " << sumK << endl;


					do
					{
						cout << "Должно выполнятся s2 > s1";
						cout << "Введите значения еще раз:" << endl;
						cout << "Введите значение s1: ";
						cin >> s1;
						cout << "Введите значение s1: ";
						cin >> s2;

					} while (s1 > s2);

					count = 0;
					sumS = 0;

					for (i = s1; i < s2; i++)
					{
						cout << "А[" << i << "]=" << A[i] << endl;
						sumS += A[i];
						count++;
					}

			
					averageS = sumS / count;
	
					
					cout << "среднее арифметическое элементов массива"
					<< " с s1 - го по s2 - й " << averageS << endl;
					system("pause");
	}
	break;

	case 3:
	{
		/*3.	Дан массив. Найти: 
			a.	сумму элементов массива, значение 
				которых не превышает 20; 
			b.	сумму элементов массива, больших числа a.*/

			int A[20] = { 0 }, i, j, sum20 = 0, a, suma = 0;

				for (i = 0; i < 10; i++)
				{
					A[i] = 10 + rand() % 20;
					cout << "А[" << i << "]=" << A[i] << endl;
					if (A[i] < 20) sum20 += A[i];
				}

				cout << "Сумма элементов массива, значение "
					<< "которых не превышает 20 - " << sum20 << endl;

				cout << "Введите число а: ";
				cin >> a;

				for (i = 0; i < 10; i++)
				{
					if (A[i] > a) suma += A[i];
				}

				cout << "Сумма элементов массива, больших числа a - " << suma << endl;
				system("pause");

	}
	break;


		case 4:
		{
		/*4. Ввести целочисленный массив, состоящий из 9 элементов. 
			 Поменять местами максимальный и минимальный  элементы массива*/
		
			int A[9] = { 0 }, i, j, max = 0, min = 1000000, temp, maxi, mini;

			for (i = 0; i < 9; i++)
			{
				A[i] = 10 + rand() % 20;
				cout << "А[" << i << "]=" << A[i] << endl;
				if (A[i] > max)
				{
					max = A[i];
					maxi = i;
				}
				if (A[i] < min)
				{
					min = A[i];
					mini = i;
				}
			}

			cout << endl;
			cout << "А[" << maxi << "]=" << A[maxi] << " - максимальный"
				 <<" элемент "<<endl;
			cout << "А[" << mini << "]=" << A[mini] << " - минимальный"
				<< " элемент " << endl;
			cout << endl;

				temp = A[mini];
				A[mini] = A[maxi];
				A[maxi] = temp;

				for (i = 0; i < 9; i++)
				{
					cout << "А[" << i << "]=" << A[i] << endl;
				}

				system("pause");

		}
		break;

		case 5:
		{
		/*5. Ввести массив, состоящий из 20 элементов целого типа. 
		Определить  каких элементов больше четных или 
		нечетных по значению.*/
			int A[9] = { 0 }, i, j, sumEven = 0, sumOdd=0;

			for (i = 0; i < 20; i++)
			{
				A[i] = 10 + rand() % 20;
				cout << "А[" << i << "]=" << A[i] << endl;
				if (A[i] % 2 == 0) sumEven += A[i];
				if (A[i] % 2 != 0) sumOdd += A[i];
			}

			cout<<"Сумма четных элементов - "<< sumEven << endl;
			cout << "Сумма нечетных элементов - " << sumOdd << endl;

			if (sumEven > sumOdd) cout << "Четных элементов больше." << endl;
			if (sumEven < sumOdd) cout << "Нечетных элементов больше." << endl;
		}
		system("pause");
		break;
	}
}


