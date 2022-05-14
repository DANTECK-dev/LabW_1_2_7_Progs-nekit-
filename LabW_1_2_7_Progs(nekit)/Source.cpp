#include "Class.h"

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
	Schoolboy* childs = head;
	Schoolboy* tail = NULL;
	tail = new Schoolboy;
	childs->Preperation(*&head, *&tail, *&childs);
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
		childs = head;
		switch (action) {
		case(0):
		{
			cout << "\n�����\n";
			return 0;
			break;
		}
		case(1):
		{
			try
			{
				childs->CreateBoy(*&tail, *&childs);
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
				childs->DeleteBoy(*&head, *&tail, *&childs);
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
				childs->ChangeBoy(*&childs);
			}
			catch (const exception& err)
			{
				cout << err.what() << endl;
			}
			break;
		}
		case(4):
		{
			childs->OutBoy(*&head, *&childs);
			break;
		}
		case(5):
		{
			childs->SortBoy(*&head, *&tail, *&childs);
			break;
		}
		case(6):
		{
			childs->SearchBoys(*&head, *&childs);
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
				LoadFile(*&tail, *&childs);
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
		childs->AfterPreparation(*&head, *&tail, *&childs);
	}
}