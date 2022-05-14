#include "Class.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "С какими данными вы хотите работать?\n(1 - Ученик, 2 - Кадет, 3 - Студент)\n";
	cin >> listNum;
	while (listNum > 3 || listNum < 1)
	{
		cout << "С какими данными вы хотите работать?\n(1 - Ученик, 2 - Кадет, 3 - Студент)\n";
		cin >> listNum;
	}
	Schoolboy* head = NULL;
	head = new Schoolboy("Мисюркеев Никита Вячеславович", "3В", "18005553535", "5 4 3", 31, "Капитан", 34123, 1, "ВСГУТУ", "ПИ", "Б661-2");
	Schoolboy* childs = head;
	Schoolboy* tail = NULL;
	tail = new Schoolboy;
	childs->Preperation(*&head, *&tail, *&childs);
#if VER == 1
	cout << "\nУ ВАС ДЕМО ВЕРСИЯ (7 и 8 пункты меню недоступны)\n";
#else
	cout << "\nУ ВАС ПОЛНАЯ ВЕРСИЯ (7 и 8 пункты меню доступны)\n";
#endif
	while (true)
	{
		cout << "\n1 - Добавить данные";
		cout << "\n2 - Удалить  данные";
		cout << "\n3 - Изменить данные";
		cout << "\n4 - Вывести список данных";
		cout << "\n5 - Сортировать данные";
		cout << "\n6 - Осуществить поиск";
		cout << "\n7 - Сохранить данные в файл";
		cout << "\n8 - Загрузить данные из файла";
		cout << "\n0 - Выход \n";
		cout << "\nВведите номер действия: ";
		int action;
		cin >> action;
		childs = head;
		switch (action) {
		case(0):
		{
			cout << "\nВыход\n";
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
			cout << "\nВведен неверный номер команды\n";
			break;
		}
		}
		childs->AfterPreparation(*&head, *&tail, *&childs);
	}
}