#include "class.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "� ������ ������� �� ������ ��������?\n(1 - ������, 2 - �����, 3 - �������)\n";
	cin >> listNum;
	while (listNum > 3 || listNum < 1)
	{
		cout << "� ������ ������� �� ������ ��������?\n(1 - ������, 2 - �����, 3 - �������)\n";
		cin >> listNum;
	}
	Schoolboy* head = NULL;
	head = new Schoolboy("��������� ������ ������������", "3�", "18005553535", "5 4 3", 31, "�������", 34123, 1, "������", "��", "�661-2");
	Schoolboy* current = head;
	Schoolboy* tail = NULL;
	tail = new Schoolboy;
	current->Preperation(*&head, *&tail, *&current);
#if VER == 1
	cout << "\n� ��� ���� ������ (7 � 8 ������ ���� ����������)\n";
#else
	cout << "\n� ��� ������ ������ (7 � 8 ������ ���� ��������)\n";
#endif
	while (true)
	{
		cout << "\n1 - �������� ������";
		cout << "\n2 - �������  ������";
		cout << "\n3 - �������� ������";
		cout << "\n4 - ������� ������ ������";
		cout << "\n5 - ����������� ������";
		cout << "\n6 - ����������� �����";
		cout << "\n7 - ��������� ������ � ����";
		cout << "\n8 - ��������� ������ �� �����";
		cout << "\n0 - ����� \n";
		cout << "\n������� ����� ��������: ";
		int action;
		cin >> action;
		current = head;
		switch (action) {
		case(0):
		{
			cout << "\n�����\n";
			return 0;
			break;
		}
		case(1):
		{
			if (current == NULL && head == NULL && tail == NULL)
				head = tail = current = new Schoolboy;
			try
			{
				if (listNum == 1)
					current->schoolKid.Create(*&tail, *&current);
				else if (listNum == 2)
					current->cadet.Create(*&tail, *&current);
				else if (listNum == 3)
					current->student.Create(*&tail, *&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(2):
		{
			try
			{
				current->schoolKid.Delete(*&head, *&tail, *&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(3):
		{
			try
			{
				if (listNum == 1)
					current->schoolKid.Change(*&current);
				else if (listNum == 2)
					current->cadet.Change(*&current);
				else if (listNum == 3)
					current->student.Change(*&current);
				break;
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(4):
		{
			if (current == NULL && head == NULL && tail == NULL) {
				cout << "\n�������� ������\n";
				break;
			}
			if (listNum == 1)
				current->schoolKid.Output(*&head, *&current);
			else if (listNum == 2)
				current->cadet.Output(*&head, *&current);
			else if (listNum == 3)
				current->student.Output(*&head, *&current);
			break;
		}
		case(5):
		{
			if (listNum == 1)
				current->schoolKid.Sort(*&head, *&tail, *&current);
			else if (listNum == 2)
				current->cadet.Sort(*&head, *&tail, *&current);
			else if (listNum == 3)
				current->student.Sort(*&head, *&tail, *&current);
			break;
		}
		case(6):
		{
			if (listNum == 1)
				current->schoolKid.Search(*&head, *&current);
			else if (listNum == 2)
				current->cadet.Search(*&head, *&current);
			else if (listNum == 3)
				current->student.Search(*&head, *&current);
			break;
		}
		case(7):
		{
			try
			{
				SaveFile(*&head);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(8):
		{
			try
			{
				LoadFile(*&tail, *&current);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		default:
		{
			cout << "\n������ �������� ����� �������\n";
			break;
		}
		}
	}
}