#include "class.h"

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
	Schoolboy* current = head;
	Schoolboy* tail = NULL;
	tail = new Schoolboy;
	current->Preperation(*&head, *&tail, *&current);
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
		current = head;
		switch (action) {
		case(0):
		{
			cout << "\nВыход\n";
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
				cout << "\nВыводить нечего\n";
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
			cout << "\nВведен неверный номер команды\n";
			break;
		}
		}
	}
}