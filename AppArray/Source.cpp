#include <stdio.h>
#include <stdlib.h> // ��� ������������� ������� system()
#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

//��������� ����������
//����������� ����������
void BubleSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "�� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // ��� ���� ��������� ����� i-���
		{
			if (arrNumber[j - 1] > arrNumber[j]) // ���� ������� ������� ������ �����������
			{
				int temp = arrNumber[j - 1]; // ������ �� �������
				arrNumber[j - 1] = arrNumber[j];
				arrNumber[j] = temp;
			}
		}
	}
	cout << "����� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}

//���������� �������
void selectionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "�� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	//���������� ���� ��� ���� ��������� ����� ����������
	int min, temp; // ��� ������ ������������ �������� � ��� ������
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // ���������� ������ �������� ��������
				 // ���� ����������� ������� ����� ��������� �� ����� i-���

		for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
		{
			if (arrNumber[j] < arrNumber[min]) // ���� ������� ������ ������������,
				min = j;       // ���������� ��� ������ � min
		}
		temp = arrNumber[i];      // ������ ������� i-�� � ����������� ��������
		arrNumber[i] = arrNumber[min];
		arrNumber[min] = temp;
	}

	cout << "����� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}
}

//���������� ���������
void inclusionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "�� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	// ��� ���� ��������� ����� ����������
	for (int i = 1; i < size; i++)
	{
		int value = arrNumber[i]; // ���������� �������� ��������
		int index = i;     // � ��� ������

		while ((index > 0) && (arrNumber[index - 1] > value))
		{
			// ������� ������ �������� � ����� ������� ���� ��� ������ index
			arrNumber[index] = arrNumber[index - 1];
			index--;    // ������� �������� � ������ �������
		}
		arrNumber[index] = value; // ��������������� ������� �������� �� �������������� �����
	}
	cout << "����� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}


//��������� ������ 
//��������
void BinarySearch()
{
	int count = 0;
	int k[20];
	int r[20];
	int key, i;

	system("cls");

	// ������������� �������� ����� �������������� ����������
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

	// ���� �������
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "������� key: ";
	cin >> key;

	int left = 0; // ������ ����� � ������ ������� ������
	int right = 19;

	int search = -1; // ��������� ������ �������� ����� -1 (������� �� ������)

	while (left <= right) // ���� ����� ������� �� "����������" ������
	{
		count++;
		int mid = (left + right) / 2; // ���� �������� �������

		// ���� �������� ���� ����� ��������
		// �� ����� ��������� �������, ������� �� �����
		if (key == k[mid])
		{
			search = mid;
			break;
		}


		if (key < k[mid])     // ���� ������� �������� ���� ������ ��������� ��������
			right = mid - 1;  // ������� ������ �������, ��������� ����� � ����� �����
		else
			left = mid + 1;   // ������� ����� �������, ��������� ����� � ������ �����
	}

	if (search == -1)     // ���� ������ �������� ��-�������� -1, ������� �� ������
		cout << "������� �� ������!" << endl;
	else          // ����� ������� �������, ��� ���� � ��������
		cout << "k[" << search << "]=" << k[search] << " (�� " << count << " ��������)" << endl;

	cout << endl;
}

//��������
void LineSearch()
{
	int k[20];
	int key, i;

	system("cls");

	// ������������� �������� ����� �������������� ����������
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

	// ���� �������
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "������� key: ";
	cin >> key;

	for (i = 0; i < 19; i++) // ������������� ��� �������� � �����
	{
		if (k[i] == key)      // ���� ������� ������� �� ��������� key,
		{
			cout << i << endl;     // ���������� ��� ������
			break;
		}

	}
	cout << "������� �� ������ �� " << i << " �����" << endl;
}

void testFunc(); //�������� �������

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int n;
	cout << "������� ����� �������: ";
	cin >> n;

	switch (n)
	{


	case 1:
	{
		/*1.	��������� ������ ��������� �����,
		��������� ������ �� �������� ���������
		���������������� �������*/
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
		/*2.	����������: 
			a.	����� ���� ��������� �������; 
			b.	������������ ���� ��������� �������; 
			c.	����� ��������� ���� ��������� �������; 
			d.	����� ����� ������ ��������� �������; 
			e.	����� ��������� ������� � k1-�� �� k2-� 
			    (�������� k1 � k2 ��������  � ����������; k2 > k1); 
			f.	������� �������������� ���� ��������� �������; 
			g.	������� �������������� ��������� ������� 
				� s1-�� �� s2-� (�������� s1 � s2 �������� � ����������; 
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
					cout << "�[" << i << "]=" << A[i] << endl;
					sum += A[i];
					mult*= A[i];
					if(i<6) first6+= A[i];
					square += A[i] * A[i];
				}

				average = sum / 20;

				cout << "����� ���� ��������� ������� - " << sum << endl;
				cout << "������������ ���� ��������� ������� - " << mult << endl;
				cout << "����� ��������� ���� ��������� ������� - " << square << endl;
				cout << "����� ����� ������ ��������� ������� - " << first6 << endl;
				cout << "������� �������������� ���� ��������� ������� - " << average << endl;

					do
					{
						cout << "������ ���������� k2 > k1";
						cout << "������� �������� ��� ���:" << endl;
						cout << "������� �������� k1: ";
						cin >> k1;
						cout << "������� �������� k2: ";
						cin >> k2;

					}while (k1 > k2);


					sumK = 0;

					for (i = k1; i < k2; i++)
					{			
						cout << "�[" << i << "]=" << A[i] << endl;
						sumK += A[i];
					}

					cout << "����� ��������� ������� � k1-�� �� k2-� " << sumK << endl;


					do
					{
						cout << "������ ���������� s2 > s1";
						cout << "������� �������� ��� ���:" << endl;
						cout << "������� �������� s1: ";
						cin >> s1;
						cout << "������� �������� s1: ";
						cin >> s2;

					} while (s1 > s2);

					count = 0;
					sumS = 0;

					for (i = s1; i < s2; i++)
					{
						cout << "�[" << i << "]=" << A[i] << endl;
						sumS += A[i];
						count++;
					}

			
					averageS = sumS / count;
	
					
					cout << "������� �������������� ��������� �������"
					<< " � s1 - �� �� s2 - � " << averageS << endl;
					system("pause");
	}
	break;

	case 3:
	{
		/*3.	��� ������. �����: 
			a.	����� ��������� �������, �������� 
				������� �� ��������� 20; 
			b.	����� ��������� �������, ������� ����� a.*/

			int A[20] = { 0 }, i, j, sum20 = 0, a, suma = 0;

				for (i = 0; i < 10; i++)
				{
					A[i] = 10 + rand() % 20;
					cout << "�[" << i << "]=" << A[i] << endl;
					if (A[i] < 20) sum20 += A[i];
				}

				cout << "����� ��������� �������, �������� "
					<< "������� �� ��������� 20 - " << sum20 << endl;

				cout << "������� ����� �: ";
				cin >> a;

				for (i = 0; i < 10; i++)
				{
					if (A[i] > a) suma += A[i];
				}

				cout << "����� ��������� �������, ������� ����� a - " << suma << endl;
				system("pause");

	}
	break;


		case 4:
		{
		/*4. ������ ������������� ������, ��������� �� 9 ���������. 
			 �������� ������� ������������ � �����������  �������� �������*/
		
			int A[9] = { 0 }, i, j, max = 0, min = 1000000, temp, maxi, mini;

			for (i = 0; i < 9; i++)
			{
				A[i] = 10 + rand() % 20;
				cout << "�[" << i << "]=" << A[i] << endl;
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
			cout << "�[" << maxi << "]=" << A[maxi] << " - ������������"
				 <<" ������� "<<endl;
			cout << "�[" << mini << "]=" << A[mini] << " - �����������"
				<< " ������� " << endl;
			cout << endl;

				temp = A[mini];
				A[mini] = A[maxi];
				A[maxi] = temp;

				for (i = 0; i < 9; i++)
				{
					cout << "�[" << i << "]=" << A[i] << endl;
				}

				system("pause");

		}
		break;

		case 5:
		{
		/*5. ������ ������, ��������� �� 20 ��������� ������ ����. 
		����������  ����� ��������� ������ ������ ��� 
		�������� �� ��������.*/
			int A[9] = { 0 }, i, j, sumEven = 0, sumOdd=0;

			for (i = 0; i < 20; i++)
			{
				A[i] = 10 + rand() % 20;
				cout << "�[" << i << "]=" << A[i] << endl;
				if (A[i] % 2 == 0) sumEven += A[i];
				if (A[i] % 2 != 0) sumOdd += A[i];
			}

			cout<<"����� ������ ��������� - "<< sumEven << endl;
			cout << "����� �������� ��������� - " << sumOdd << endl;

			if (sumEven > sumOdd) cout << "������ ��������� ������." << endl;
			if (sumEven < sumOdd) cout << "�������� ��������� ������." << endl;
		}
		system("pause");
		break;
	}
}


