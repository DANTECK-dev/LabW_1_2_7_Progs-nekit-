#include "libs.h"

class Schoolboy {

	const int maxListNum = 3;

	Schoolboy* next = NULL;
	Schoolboy* prev = NULL;

	friend void SaveFile(Schoolboy*&);
	friend void LoadFile(Schoolboy*&, Schoolboy*&);

public:

	class SchoolKid
	{
		string	Fio;
		string	Clase;
		string	Number;
		string	Grades;
	public:

		string GetFio()
		{
			return Fio;
		}

		string GetClase()
		{
			return Clase;
		}

		string GetNumber()
		{
			return Number;
		}

		string GetGrades()
		{
			return Grades;
		}

		void SetFio(string Fio)
		{
			this->Fio = Fio;
		}

		void SetClase(string Clase)
		{
			this->Clase = Clase;
		}

		void SetNumber(string Number)
		{
			this->Number = Number;
		}

		void SetGrades(string Grades)
		{
			this->Grades = Grades;
		}

		virtual void Create(Schoolboy*& tail, Schoolboy*& current)
		{
			cout << "\n��������� ����� - ����������\n";

			string s1, s2, s3, s4;
			cout << "\n������� ������ �������\n";
			cout << "\n���: ";
			cin.get();
			getline(cin, s1);
			int size = s1.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(s1[i]))
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			cout << "\n�����: ";
			getline(cin, s2);
			cout << "\n����� ��������: ";
			getline(cin, s3);
			size = s3.size();
			for (int i = 0; i < size; i++)
			{
				if (!isdigit(s3[i]))
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			cout << "\n������: ";
			getline(cin, s4);
			size = s4.size();
			for (int i = 0; i < size; i++)
			{
				if (!isdigit(s4[i]) && !s4[i] == ' ')
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			current = tail;
			current->next = new Schoolboy;
			current->next->prev = current;
			current = current->next;
			tail = current;

			current->schoolKid.SetFio(s1);
			current->schoolKid.SetClase(s2);
			current->schoolKid.SetNumber(s3);
			current->schoolKid.SetGrades(s4);
			cout << "\n������ ������� ���������!\n";
		}

		void Delete(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& current)
		{
			if (head == NULL || tail == NULL)
			{
				cout << "\n� ������ ��� ������\n";
			}
			cout << "\n��������� ����� - ��������\n";
			cout << "\n������� ����� ������, ������� ����� �������: ";
			int lineNum;
			cin >> lineNum;
			current = head;
			lineNum--;
			bool isCurrent = true;
			for (int i = 0; i < lineNum; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("��� ������ � ������ �������");
					break;
				}
			}
			if (isCurrent == true)
			{
				cout << "\n�� ����� ������ ������� ������ ��� ������� '" << lineNum + 1 << "'? (1 - ��, 2 - ���)\n";
				int yourAction;
				cin >> yourAction;
				switch (yourAction)
				{
				case(1):
				{
					if (current != head && current != tail)
					{
						current->prev->next = current->next;
						current->next->prev = current->prev;
					}
					else if (current == head && current != tail)
					{
						head = current->next;
						head->prev = NULL;
					}
					else if (current == tail && current != head)
					{
						tail = current->prev;
						tail->next = NULL;
					}
					else if (current == tail && current == head)
					{
						head = NULL;
						tail = NULL;
						current = NULL;
						cout << "\n������� ��������� ������, ������ ������� ������\n";
						return;
					}
					delete current;
					current = head;
					cout << "\n������ ������� �������\n";
					break;
				}
				case(2):
				{
					break;
				}
				default:
				{
					cout << "\n������ �������� ����� �������\n";
					break;
				}
				}
				current = head;
			}
		}

		virtual void Change(Schoolboy*& current)
		{
			cout << "\n��������� ����� - ���������\n";
			cout << "\n������� ����� ������, ������� ����� ��������: ";
			int lineNum;
			cin >> lineNum;
			bool isCurrent = true;
			for (int i = 0; i < lineNum - 1; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("��� ������ � ������ �������");
					break;
				}
			}
			if (isCurrent == true)
			{
				cout << "\n�� ����� ������ �������� ������ ��� ������� '" << lineNum << "'? (1 - ��, 2 - ���)\n";
				int yourAction;
				cin >> yourAction;
				switch (yourAction)
				{
				case(1):
				{
					string s1, s2, s3, s4;
					if (listNum == 1)
					{
						cout << "\n������� ������ �������\n";
					}
					else
					{
						if (listNum == 2)
						{
							cout << "\n������� ������ ������\n";
						}
						else if (listNum == 3)
						{
							cout << "\n������� ������ ��������\n";
						}
					}
					cout << "\n���: ";
					cin.get();
					getline(cin, s1);
					int size = s1.size();
					for (int i = 0; i < size; i++)
					{
						if (isdigit(s1[i]))
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					if (listNum == 1 || listNum == 2)
					{
						cout << "\n�����: ";
						getline(cin, s2);
					}
					cout << "\n����� ��������: ";
					getline(cin, s3);
					size = s3.size();
					for (int i = 0; i < size; i++)
					{
						if (!isdigit(s3[i]))
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					cout << "\n������: ";
					getline(cin, s4);
					size = s4.size();
					for (int i = 0; i < size; i++)
					{
						if (!isdigit(s4[i]) && !s4[i] == ' ')
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					current->schoolKid.SetFio(s1);
					current->schoolKid.SetClase(s2);
					current->schoolKid.SetNumber(s3);
					current->schoolKid.SetGrades(s4);
					break;
				}
				case(2):
				{
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

		virtual void Output(Schoolboy*& head, Schoolboy*& current)
		{
			cout << "\n��������� ����� - ����� �������\n";
			cout << "|------------------------------------------------------------------------------------|" << endl;
			cout << "| ������� '�������'                                                                  |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|" << endl;
			cout << "|              ���              | ����� | ����� �������� |  ������  | ������� ������ |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|" << endl;
			current = head;

			while (true) {
				int size = current->schoolKid.GetGrades().size();
				float num = 0;
				float count = 0;
				for (int i = 0; i < size; i++)
				{
					switch (current->schoolKid.GetGrades()[i])
					{
					case '2':
						num += 2;
						count++;
						break;
					case '3':
						num += 3;
						count++;
						break;
					case '4':
						num += 4;
						count++;
						break;
					case '5':
						num += 5;
						count++;
						break;
					default:
						break;
					}
				}
				float avgGrades = num / count;
				cout << "| ";
				cout.width(30);
				cout << left << current->schoolKid.GetFio().c_str();
				cout << "| ";
				cout.width(6);
				cout << left << current->schoolKid.GetClase().c_str();
				cout << "| ";
				cout.width(15);
				cout << left << current->schoolKid.GetNumber().c_str();
				cout << "| ";
				cout.width(9);
				cout << left << current->schoolKid.GetGrades().c_str();
				cout << "| ";
				cout.width(15);
				cout << left << avgGrades;
				cout << "|" << endl;
				cout << "|-------------------------------|-------|----------------|----------|----------------|" << endl;
				if (current->next == NULL) break;
				current = current->next;
			}
			current = head;
		}

		virtual void Sort(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& current)
		{
			cout << "\n��������� ����� - ����������\n";
			current = head;
			int counter = 1;
			Schoolboy* temp = NULL;
			temp = new Schoolboy;
			current = head;

			for (int i = 1; i < counter; i++)
			{
				current = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (current->schoolKid.GetClase() > current->next->schoolKid.GetClase())
					{
						temp->schoolKid = current->schoolKid;
						current->schoolKid = current->next->schoolKid;
						current->next->schoolKid = temp->schoolKid;
					}
					current = current->next;
				}
			}
			cout << "\n������ ������� ������������� �� �������\n";
		}

		virtual void Search(Schoolboy*& head, Schoolboy*& current)
		{
			string search;
			cout << "\n��������� ����� - �����\n";
			if (listNum == 1 || listNum == 2)
			{
				cout << "\n������� ����� �������, �������� ����� ����� � ������: ";
			}
			else if (listNum == 3)
			{
				cout << "\n������� ������������� ��������, �������� ����� ����� � ������: ";
			}
			cin >> search;
			current = head;
			bool SuccesSearch = false;
			while (true)
			{
				if (current == NULL)
					break;
				if (search == current->schoolKid.GetClase())
				{
					int size = current->schoolKid.GetGrades().size();
					float num = 0;
					float count = 0;
					for (int i = 0; i < size; i++)
					{
						switch (current->schoolKid.GetGrades()[i])
						{
						case '2':
							num += 2;
							count++;
							break;
						case '3':
							num += 3;
							count++;
							break;
						case '4':
							num += 4;
							count++;
							break;
						case '5':
							num += 5;
							count++;
							break;
						default:
							break;
						}
					}
					float avgGrades = num / count;
					cout << "\n������� ������ ��������������� ���������:";
					SuccesSearch = true;
					cout << "\n���: " << current->schoolKid.GetFio()
						<< "\n�����: " << current->schoolKid.GetClase()
						<< "\n����� ��������: " << current->schoolKid.GetNumber()
						<< "\n������: " << current->schoolKid.GetGrades()
						<< "\n������� ������: " << avgGrades
						<< "\n����� �����: " << current->cadet.GetSchoolNum()
						<< "\n������: " << current->cadet.GetRank() << endl;
				}
				current = current->next;
			}
			current = head;
			if (SuccesSearch == true)
			{
				cout << "\n������� ����������\n";
			}
			else
			{
				cout << "\n���������� �� �������\n";
			}
		}

	} schoolKid;

	class Cadet : SchoolKid
	{
		int SchoolNum;
		string Rank;
	public:
#pragma region GetSet

		int GetSchoolNum()
		{
			return SchoolNum;
		}

		string GetRank()
		{
			return Rank;
		}

		void SetSchoolNum(int SchoolNum)
		{
			this->SchoolNum = SchoolNum;
		}

		void SetRank(string Rank)
		{
			this->Rank = Rank;
		}
#pragma endregion
		void Create(Schoolboy*& tail, Schoolboy*& current) override
		{
			cout << "\n��������� ����� - ����������\n";
			string s1, s2, s3, s4, s6;
			int s5;
			cout << "\n������� ������ ������\n";
			cout << "\n���: ";
			cin.get();
			getline(cin, s1);
			int size = s1.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(s1[i]))
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			if (listNum == 1 || listNum == 2)
			{
				cout << "\n�����: ";
				getline(cin, s2);
			}
			cout << "\n����� ��������: ";
			getline(cin, s3);
			size = s3.size();
			for (int i = 0; i < size; i++)
			{
				if (!isdigit(s3[i]))
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			cout << "\n������: ";
			getline(cin, s4);
			size = s4.size();
			for (int i = 0; i < size; i++)
			{
				if (!isdigit(s4[i]) && !s4[i] == ' ')
				{
					throw exception("\n�������� ������ ������\n");
				}
			}

			cout << "\n����� �����: ";
			cin >> s5;
			cin.get();
			cout << "\n������: ";
			getline(cin, s6);

			current = tail;
			current->next = new Schoolboy;
			current->next->prev = current;
			current = current->next;
			tail = current;

			current->schoolKid.SetFio(s1);
			current->schoolKid.SetClase(s2);
			current->schoolKid.SetNumber(s3);
			current->schoolKid.SetGrades(s4);
			current->cadet.SetSchoolNum(s5);
			current->cadet.SetRank(s6);
			cout << "\n������ ������� ���������!\n";
		}

		void Change(Schoolboy*& current) override
		{
			cout << "\n��������� ����� - ���������\n";
			cout << "\n������� ����� ������, ������� ����� ��������: ";
			int lineNum;
			cin >> lineNum;
			bool isCurrent = true;
			for (int i = 0; i < lineNum - 1; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("��� ������ � ������ �������");
					break;
				}
			}
			if (isCurrent == true)
			{
				cout << "\n�� ����� ������ �������� ������ ��� ������� '" << lineNum << "'? (1 - ��, 2 - ���)\n";
				int yourAction;
				cin >> yourAction;
				switch (yourAction)
				{
				case(1):
				{
					string s1, s2, s3, s4, s6;
					int s5;
					cout << "\n������� ������ ������\n";
					cout << "\n���: ";
					cin.get();
					getline(cin, s1);
					int size = s1.size();
					for (int i = 0; i < size; i++)
					{
						if (isdigit(s1[i]))
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					if (listNum == 1 || listNum == 2)
					{
						cout << "\n�����: ";
						getline(cin, s2);
					}
					cout << "\n����� ��������: ";
					getline(cin, s3);
					size = s3.size();
					for (int i = 0; i < size; i++)
					{
						if (!isdigit(s3[i]))
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					cout << "\n������: ";
					getline(cin, s4);
					size = s4.size();
					for (int i = 0; i < size; i++)
					{
						if (!isdigit(s4[i]) && !s4[i] == ' ')
						{
							throw exception("\n�������� ������ ������\n");
						}
					}

					cout << "\n����� �����: ";
					cin >> s5;
					cin.get();
					cout << "\n������: ";
					getline(cin, s6);

					current->schoolKid.SetFio(s1);
					current->schoolKid.SetClase(s2);
					current->schoolKid.SetNumber(s3);
					current->schoolKid.SetGrades(s4);
					current->cadet.SetSchoolNum(s5);
					current->cadet.SetRank(s6);
					break;
				}
				case(2):
				{
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

		void Output(Schoolboy*& head, Schoolboy*& current) override
		{
			cout << "|-----------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| ������� '������'                                                                                                |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|-------------|--------------|" << endl;
			cout << "|              ���              | ����� | ����� �������� |  ������  | ������� ������ | ����� ����� |    ������    |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|-------------|--------------|" << endl;

			current = head;

			while (true)
			{
				int size = current->schoolKid.GetGrades().size();
				float num = 0;
				float count = 0;
				for (int i = 0; i < size; i++)
				{
					switch (current->schoolKid.GetGrades()[i])
					{
					case '2':
						num += 2;
						count++;
						break;
					case '3':
						num += 3;
						count++;
						break;
					case '4':
						num += 4;
						count++;
						break;
					case '5':
						num += 5;
						count++;
						break;
					default:
						break;
					}
				}
				float avgGrades = num / count;
				cout << "| ";
				cout.width(30);
				cout << left << current->schoolKid.GetFio().c_str();
				cout << "| ";
				cout.width(6);
				cout << left << current->schoolKid.GetClase().c_str();
				cout << "| ";
				cout.width(15);
				cout << left << current->schoolKid.GetNumber().c_str();
				cout << "| ";
				cout.width(9);
				cout << left << current->schoolKid.GetGrades().c_str();
				cout << "| ";
				cout.width(15);
				cout << left << avgGrades;
				cout << "| ";
				cout.width(12);
				cout << left << current->cadet.GetSchoolNum();
				cout << "| ";
				cout.width(13);
				cout << left << current->cadet.GetRank().c_str();
				cout << "|" << endl;
				cout << "|-------------------------------|-------|----------------|----------|----------------|-------------|--------------|" << endl;
				if (current->next == NULL) break;
				current = current->next;
			}
			current = head;
		}

		void Sort(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& current) override
		{
			cout << "\n��������� ����� - ����������\n";
			current = head;
			int counter = 1;
			Schoolboy* temp = NULL;
			temp = new Schoolboy;
			current = head;

			for (int i = 1; i < counter; i++)
			{
				current = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (current->schoolKid.GetClase() > current->next->schoolKid.GetClase())
					{
						temp->schoolKid = current->schoolKid;
						current->schoolKid = current->next->schoolKid;
						current->next->schoolKid = temp->schoolKid;
						temp->cadet = current->cadet;
						current->cadet = current->next->cadet;
						current->next->cadet = temp->cadet;
					}
					current = current->next;
				}
			}
			cout << "\n������ ������� ������������� �� �������\n";
		}

		void Search(Schoolboy*& head, Schoolboy*& current) override
		{
			string search;
			cout << "\n��������� ����� - �����\n";
			if (listNum == 1 || listNum == 2)
			{
				cout << "\n������� ����� �������, �������� ����� ����� � ������: ";
			}
			else if (listNum == 3)
			{
				cout << "\n������� ������������� ��������, �������� ����� ����� � ������: ";
			}
			cin >> search;
			current = head;
			bool SuccesSearch = false;
			while (true)
			{
				if (current == NULL)
					break;
				if (search == current->schoolKid.GetClase())
				{
					int size = current->schoolKid.GetGrades().size();
					float num = 0;
					float count = 0;
					for (int i = 0; i < size; i++)
					{
						switch (current->schoolKid.GetGrades()[i])
						{
						case '2':
							num += 2;
							count++;
							break;
						case '3':
							num += 3;
							count++;
							break;
						case '4':
							num += 4;
							count++;
							break;
						case '5':
							num += 5;
							count++;
							break;
						default:
							break;
						}
					}
					float avgGrades = num / count;
					cout << "\n������� ������ ��������������� ���������:";
					SuccesSearch = true;
					cout << "\n���: " << current->schoolKid.GetFio()
						<< "\n�����: " << current->schoolKid.GetClase()
						<< "\n����� ��������: " << current->schoolKid.GetNumber()
						<< "\n������: " << current->schoolKid.GetGrades()
						<< "\n������� ������: " << avgGrades << endl;
				}
				current = current->next;
			}
			current = head;
			if (SuccesSearch == true)
			{
				cout << "\n������� ����������\n";
			}
			else
			{
				cout << "\n���������� �� �������\n";
			}
		}

	}cadet;

	class Student : SchoolKid
	{
		int Id;
		int Course;
		string NameUniv;
		string Spec;
		string GroupNum;
	public:
#pragma region SetGet
		int GetId()
		{
			return Id;
		}
		void SetId(int Id)
		{
			this->Id = Id;
		}
		int GetCourse()
		{
			return Course;
		}
		void SetCourse(int Course)
		{
			this->Course = Course;
		}
		string GetNameUniv()
		{
			return NameUniv;
		}
		void SetNameUniv(string NameUniv)
		{
			this->NameUniv = NameUniv;
		}
		string GetSpec()
		{
			return Spec;
		}

		void SetSpec(string Spec)
		{
			this->Spec = Spec;
		}

		string GetGroupNum()
		{
			return GroupNum;
		}

		void SetGroupNum(string GroupNum)
		{
			this->GroupNum = GroupNum;
		}
#pragma endregion
		void Create(Schoolboy*& tail, Schoolboy*& current) override
		{
			cout << "\n��������� ����� - ����������\n";

			string s1, s2, s3, s4, s9, s10, s11;
			int s7, s8;
			cout << "\n������� ������ ��������\n";
			cout << "\n���: ";
			cin.get();
			getline(cin, s1);
			int size = s1.size();
			for (int i = 0; i < size; i++)
			{
				if (isdigit(s1[i]))
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			cout << "\n�����: ";
			getline(cin, s2);
			cout << "\n����� ��������: ";
			getline(cin, s3);
			size = s3.size();
			for (int i = 0; i < size; i++)
			{
				if (!isdigit(s3[i]))
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			cout << "\n������: ";
			getline(cin, s4);
			size = s4.size();
			for (int i = 0; i < size; i++)
			{
				if (!isdigit(s4[i]) && !s4[i] == ' ')
				{
					throw exception("\n�������� ������ ������\n");
				}
			}
			cout << "\n����� �������: ";
			cin >> s7;
			cout << "\n����: ";
			cin >> s8;
			cin.get();
			cout << "\n�������� ������������: ";
			getline(cin, s9);
			cout << "\n�������� �������������: ";
			getline(cin, s10);
			cout << "\n����� ������: ";
			getline(cin, s11);

			current = tail;
			current->next = new Schoolboy;
			current->next->prev = current;
			current = current->next;
			tail = current;

			current->schoolKid.SetFio(s1);
			current->schoolKid.SetNumber(s3);
			current->schoolKid.SetGrades(s4);
			current->student.SetId(s7);
			current->student.SetCourse(s8);
			current->student.SetNameUniv(s9);
			current->student.SetSpec(s10);
			current->student.SetGroupNum(s11);

			cout << "\n������ ������� ���������!\n";
		}

		void Change(Schoolboy*& current) override
		{
			cout << "\n��������� ����� - ���������\n";
			cout << "\n������� ����� ������, ������� ����� ��������: ";
			int lineNum;
			cin >> lineNum;
			bool isCurrent = true;
			for (int i = 0; i < lineNum - 1; i++)
			{
				current = current->next;
				if (!current)
				{
					isCurrent = false;
					throw exception("��� ������ � ������ �������");
					break;
				}
			}
			if (isCurrent == true)
			{
				cout << "\n�� ����� ������ �������� ������ ��� ������� '" << lineNum << "'? (1 - ��, 2 - ���)\n";
				int yourAction;
				cin >> yourAction;
				switch (yourAction)
				{
				case(1):
				{
					string s1, s2, s3, s4, s9, s10, s11;
					int s7, s8;
					cout << "\n������� ������ ��������\n";
					cout << "\n���: ";
					cin.get();
					getline(cin, s1);
					int size = s1.size();
					for (int i = 0; i < size; i++)
					{
						if (isdigit(s1[i]))
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					cout << "\n�����: ";
					getline(cin, s2);
					cout << "\n����� ��������: ";
					getline(cin, s3);
					size = s3.size();
					for (int i = 0; i < size; i++)
					{
						if (!isdigit(s3[i]))
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					cout << "\n������: ";
					getline(cin, s4);
					size = s4.size();
					for (int i = 0; i < size; i++)
					{
						if (!isdigit(s4[i]) && !s4[i] == ' ')
						{
							throw exception("\n�������� ������ ������\n");
						}
					}
					cout << "\n����� �������: ";
					cin >> s7;
					cout << "\n����: ";
					cin >> s8;
					cin.get();
					cout << "\n�������� ������������: ";
					getline(cin, s9);
					cout << "\n�������� �������������: ";
					getline(cin, s10);
					cout << "\n����� ������: ";
					getline(cin, s11);

					current->schoolKid.SetFio(s1);
					current->schoolKid.SetNumber(s3);
					current->schoolKid.SetGrades(s4);
					current->student.SetId(s7);
					current->student.SetCourse(s8);
					current->student.SetNameUniv(s9);
					current->student.SetSpec(s10);
					current->student.SetGroupNum(s11);
					break;
				}
				case(2):
				{
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

		void Output(Schoolboy*& head, Schoolboy*& current) override
		{
			cout << "\n��������� ����� - ����� �������\n";
			cout << "|------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| ������� '��������'                                                                                                                       |" << endl;
			cout << "|-------------------------------|----------------|----------|----------------|---------------|------|-------------|---------------|--------|" << endl;
			cout << "|              ���              | ����� �������� |  ������  | ������� ������ | ����� ������� | ���� | ����������� | ������������� | ������ |" << endl;
			cout << "|-------------------------------|----------------|----------|----------------|---------------|------|-------------|---------------|--------|" << endl;
			current = head;

			while (true) {
				int size = current->schoolKid.GetGrades().size();
				float num = 0;
				float count = 0;
				for (int i = 0; i < size; i++)
				{
					switch (current->schoolKid.GetGrades()[i])
					{
					case '2':
						num += 2;
						count++;
						break;
					case '3':
						num += 3;
						count++;
						break;
					case '4':
						num += 4;
						count++;
						break;
					case '5':
						num += 5;
						count++;
						break;
					default:
						break;
					}
				}
				float avgGrades = num / count;
				cout << "| ";
				cout.width(30);
				cout << left << current->schoolKid.GetFio().c_str();
				cout << "| ";
				cout.width(15);
				cout << left << current->schoolKid.GetNumber().c_str();
				cout << "| ";
				cout.width(9);
				cout << left << current->schoolKid.GetGrades().c_str();
				cout << "| ";
				cout.width(15);
				cout << left << avgGrades;
				cout << "| ";
				cout.width(14);
				cout << left << current->student.GetId();
				cout << "| ";
				cout.width(5);
				cout << left << current->student.GetCourse();
				cout << "| ";
				cout.width(12);
				cout << left << current->student.GetNameUniv().c_str();
				cout << "| ";
				cout.width(14);
				cout << left << current->student.GetSpec().c_str();
				cout << "| ";
				cout.width(7);
				cout << left << current->student.GetGroupNum().c_str();
				cout << "|" << endl;
				cout << "|-------------------------------|----------------|----------|----------------|---------------|------|-------------|---------------|--------|" << endl;
				if (current->next == NULL) break;
				current = current->next;
			}
			current = head;
		}

		void Sort(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& current) override
		{
			cout << "\n��������� ����� - ����������\n";
			current = head;
			int counter = 1;
			Schoolboy* temp = NULL;
			temp = new Schoolboy;
			current = head;

			for (int i = 1; i < counter; i++)
			{
				current = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (current->student.GetCourse() > current->next->student.GetCourse())
					{
						temp->schoolKid = current->schoolKid;
						current->schoolKid = current->next->schoolKid;
						current->next->schoolKid = temp->schoolKid;
						temp->student = current->student;
						current->student = current->next->student;
						current->next->student = temp->student;
					}
					current = current->next;
				}
			}
			cout << "\n������ ������� ������������� �� ������\n";
		}

		void Search(Schoolboy*& head, Schoolboy*& current) override
		{
			string search;
			cout << "\n��������� ����� - �����\n";
			cout << "\n������� ������������� ��������, �������� ����� ����� � ������: ";
			cin >> search;
			current = head;
			bool SuccesSearch = false;
			while (true)
			{
				if (current == NULL)
					break;
				if (search == current->student.GetSpec())
				{
					int size = current->schoolKid.GetGrades().size();
					float num = 0;
					float count = 0;
					for (int i = 0; i < size; i++)
					{
						switch (current->schoolKid.GetGrades()[i])
						{
						case '2':
							num += 2;
							count++;
							break;
						case '3':
							num += 3;
							count++;
							break;
						case '4':
							num += 4;
							count++;
							break;
						case '5':
							num += 5;
							count++;
							break;
						default:
							break;
						}
					}
					float avgGrades = num / count;
					cout << "\n������� ������ ��������������� ���������:";
					SuccesSearch = true;
					cout << "\n���: " << current->schoolKid.GetFio()
						<< "\n����� ��������: " << current->schoolKid.GetNumber()
						<< "\n������: " << current->schoolKid.GetGrades()
						<< "\n������� ������: " << avgGrades
						<< "\n����� �������: " << current->student.GetId()
						<< "\n����: " << current->student.GetCourse()
						<< "\n�����������: " << current->student.GetNameUniv()
						<< "\n�������������: " << current->student.GetSpec()
						<< "\n����� ������: " << current->student.GetGroupNum() << endl;
				}
				current = current->next;
			}
			current = head;
			if (SuccesSearch == true)
			{
				cout << "\n������� ����������\n";
			}
			else
			{
				cout << "\n���������� �� �������\n";
			}
		}

	}student;

	Schoolboy* GetNext()
	{
		return next;
	}

	Schoolboy()
	{
		schoolKid.SetFio("");
		if (listNum == 1 || listNum == 2)
		{
			schoolKid.SetClase("");
		}
		schoolKid.SetNumber("");
		schoolKid.SetGrades("");
		if (listNum == 2)
		{
			cadet.SetSchoolNum(0);
			cadet.SetRank("");
		}
		else if (listNum == 3)
		{
			student.SetId(0);
			student.SetCourse(1);
			student.SetNameUniv("");
			student.SetSpec("");
			student.SetGroupNum("");
		}
	};

	Schoolboy(string fio, string clase, string number,
		string grades, int schoolNum, string rank,
		int id, int course, string nameUniv, string spec,
		string groupNum)
	{
		schoolKid.SetFio(fio);
		if (listNum == 1 || listNum == 2)
		{
			schoolKid.SetClase(clase);
		}
		schoolKid.SetNumber(number);
		schoolKid.SetGrades(grades);
		if (listNum == 2)
		{
			cadet.SetSchoolNum(schoolNum);
			cadet.SetRank(rank);
		}
		else if (listNum == 3)
		{
			student.SetId(id);
			student.SetCourse(course);
			student.SetNameUniv(nameUniv);
			student.SetSpec(spec);
			student.SetGroupNum(groupNum);
		}
	};

	void Preperation(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& current)
	{
		current = head;
		string Fios[4] = { "��������� ����� ����������", "������ �������� ����������", "��������� ������ ���������", "������������ ���� ��������" };
		string Clase[4] = { "2�", "8�", "4�", "2�" };
		string Numbers[4] = { "78652158365", "78664788078", "78027969659", "78895542709" };
		string Gradess[4] = { "4 3 4", "5 5 5",	"5 5 5", "3 4 5" };
		int schoolNums[4] = { 35, 31, 71, 134 };
		string Ranks[4] = { "�����", "���������", "������", "������" };
		int Ids[4] = { 34315, 34543, 53123, 43247 };
		int Courses[4] = { 4, 2, 1, 1 };
		string nameUnivs[4] = { "������", "������", "������", "������" };
		string Specs[4] = { "��", "��", "��", "��" };
		string GroupNums[4] = { "�611-2", "�611-1", "�611-1", "�611-3" };

		for (int i = 0; i < 4; i++) {
			current->next = new Schoolboy(Fios[i], Clase[i], Numbers[i], Gradess[i],
				schoolNums[i], Ranks[i], Ids[i], Courses[i],
				nameUnivs[i], Specs[i], GroupNums[i]);
			current->next->prev = current;
			current = current->next;
			tail = current;
		}
	}
};

void SaveFile(Schoolboy*& head)
{
#if VER == 2
	cout << "\n��������� ����� - ����������\n";
	int fileAction = -5;
	while (fileAction < 1 || fileAction > 2)
	{
		cout << "1 - ���� �� ��������� (Schoolboys.txt)\n2 - ������������ ����\n�������� ���� ����������:";
		cin >> fileAction;
		if (fileAction < 1 || fileAction > 2)
		{
			cout << "����������� ����� ��������";
		}
	}
	switch (fileAction)
	{
	case 1:
	{
		ofstream writeFile;
		writeFile.open("Schoolboys.txt");
		if (!writeFile)
		{
			throw exception("���� �� ��������");
			break;
		}
		else
		{
			Schoolboy* curent = head;
			while (curent)
			{
				Schoolboy boy = *curent;
				if (listNum == 1)
				{
					writeFile << boy.schoolKid.GetFio() << ' ' << boy.schoolKid.GetClase() << ' ' << boy.schoolKid.GetNumber() << ' ' << boy.schoolKid.GetGrades();
				}
				else if (listNum == 2)
				{
					writeFile << boy.schoolKid.GetFio() << ' ' << boy.schoolKid.GetClase() << ' ' << boy.schoolKid.GetNumber() << ' ' << boy.schoolKid.GetGrades() << ' ' << boy.cadet.GetSchoolNum() << ' ' << boy.cadet.GetRank();
				}
				else if (listNum == 3)
				{
					writeFile << boy.schoolKid.GetFio() << ' ' << boy.schoolKid.GetNumber() << ' '
						<< boy.schoolKid.GetGrades() << ' ' << boy.student.GetId() << ' ' << boy.student.GetCourse()
						<< ' ' << boy.student.GetNameUniv() << ' ' << boy.student.GetSpec() << ' ' << boy.student.GetGroupNum();
				}
				curent = curent->next;
				if (curent)
					writeFile << endl;
			}
			cout << "\n���� ������� �������\n";
		}
		break;
	}
	case 2:
	{
		cout << "������� �������� ����� ��� ���������� ������: ";
		string filename;
		cin >> filename;
		filename += ".txt";
		ofstream writeFile;
		writeFile.open(filename);
		if (!writeFile)
		{
			throw exception("���� �� ��������");
			break;
		}
		else
		{
			Schoolboy* curent = head;
			while (curent)
			{
				Schoolboy boy = *curent;
				if (listNum == 1)
				{
					writeFile << boy.schoolKid.GetFio() << ' ' << boy.schoolKid.GetClase() << ' ' << boy.schoolKid.GetNumber() << ' ' << boy.schoolKid.GetGrades();
				}
				else if (listNum == 2)
				{
					writeFile << boy.schoolKid.GetFio() << ' ' << boy.schoolKid.GetClase() << ' ' << boy.schoolKid.GetNumber() << ' ' << boy.schoolKid.GetGrades() << ' ' << boy.cadet.GetSchoolNum() << ' ' << boy.cadet.GetRank();
				}
				else if (listNum == 3)
				{
					writeFile << boy.schoolKid.GetFio() << ' ' << boy.schoolKid.GetNumber() << ' '
						<< boy.schoolKid.GetGrades() << ' ' << boy.student.GetId() << ' ' << boy.student.GetCourse()
						<< ' ' << boy.student.GetNameUniv() << ' ' << boy.student.GetSpec() << ' ' << boy.student.GetGroupNum();
				}
				curent = curent->next;
				if (curent)
					writeFile << endl;
			}
			cout << "\n���� ������� �������\n";
		}
		break;
	}
	}
#else
	cout << "\n� ��� ���� ������, ��� ������� ����������\n";
#endif
}

void LoadFile(Schoolboy*& tail, Schoolboy*& current)
{
#if VER == 2
	cout << "\n��������� ����� - ��������\n";
	int fileAction = -5;
	while (fileAction < 1 || fileAction > 2)
	{
		cout << "1 - ���� �� ��������� (Schoolboys.txt)\n2 - ������������ ����\n�������� ���� ��������:";
		cin >> fileAction;
		if (fileAction < 1 || fileAction > 2)
		{
			cout << "����������� ����� ��������";
		}
	}
	switch (fileAction)
	{
	case 1:
	{
		ifstream readFile;
		readFile.open("Schoolboys.txt");
		if (!readFile)
		{
			throw exception("���� �� ��������");
			break;
		}
		else
		{
			while (readFile.eof() == false)
			{
				Schoolboy* boy = new Schoolboy;
				string name;
				string surname;
				string patronymic;
				string s1, s2, s4, s7, s8, s9;
				int s3, s5, s6;
				string g1, g2, g3;
				readFile >> name >> surname >> patronymic;
				boy->schoolKid.SetFio(name + " " + surname + " " + patronymic);
				if (listNum == 1 || listNum == 2)
				{
					readFile >> s1;
					boy->schoolKid.SetClase(s1);
				}
				readFile >> s2;
				boy->schoolKid.SetNumber(s2);
				readFile >> g1 >> g2 >> g3;
				boy->schoolKid.SetGrades(g1 + " " + g2 + " " + g3);
				if (listNum == 2)
				{
					readFile >> s3;
					boy->cadet.SetSchoolNum(s3);
					readFile >> s4;
					boy->cadet.SetRank(s4);
				}
				else if (listNum == 3)
				{
					readFile >> s5;
					boy->student.SetId(s5);
					readFile >> s6;
					boy->student.SetCourse(s6);
					readFile >> s7;
					boy->student.SetNameUniv(s7);
					readFile >> s8;
					boy->student.SetSpec(s8);
					readFile >> s9;
					boy->student.SetGroupNum(s9);
				}
				current = tail;
				current->next = new Schoolboy;
				current = current->next;
				tail = current;
				current->schoolKid.SetFio(boy->schoolKid.GetFio());
				if (listNum == 1 || listNum == 2)
				{
					current->schoolKid.SetClase(boy->schoolKid.GetClase());
				}
				current->schoolKid.SetNumber(boy->schoolKid.GetNumber());
				current->schoolKid.SetGrades(boy->schoolKid.GetGrades());
				if (listNum == 2)
				{
					current->cadet.SetSchoolNum(boy->cadet.GetSchoolNum());
					current->cadet.SetRank(boy->cadet.GetRank());
				}
				else if (listNum == 3)
				{
					current->student.SetId(boy->student.GetId());
					current->student.SetCourse(boy->student.GetCourse());
					current->student.SetNameUniv(boy->student.GetNameUniv());
					current->student.SetSpec(boy->student.GetSpec());
					current->student.SetGroupNum(boy->student.GetGroupNum());
				}
			}
			cout << "\n������ ������� ���������\n";
			readFile.close();
		}
		break;
	}
	case 2:
	{
		cout << "������� �������� ����� ��� �������� ������: ";
		string filename;
		cin >> filename;
		filename += ".txt";
		ifstream readFile;
		readFile.open(filename);
		if (!readFile)
		{
			throw exception("���� �� ��������");
			break;
		}
		else
		{
			while (readFile.eof() == false)
			{
				Schoolboy* boy = new Schoolboy;
				string name;
				string surname;
				string patronymic;
				string s1, s2, s4, s7, s8, s9;
				int s3, s5, s6;
				string g1, g2, g3;
				readFile >> name >> surname >> patronymic;
				boy->schoolKid.SetFio(name + " " + surname + " " + patronymic);
				if (listNum == 1 || listNum == 2)
				{
					readFile >> s1;
					boy->schoolKid.SetClase(s1);
				}
				readFile >> s2;
				boy->schoolKid.SetNumber(s2);
				readFile >> g1 >> g2 >> g3;
				boy->schoolKid.SetGrades(g1 + " " + g2 + " " + g3);
				if (listNum == 2)
				{
					readFile >> s3;
					boy->cadet.SetSchoolNum(s3);
					readFile >> s4;
					boy->cadet.SetRank(s4);
				}
				else if (listNum == 3)
				{
					readFile >> s5;
					boy->student.SetId(s5);
					readFile >> s6;
					boy->student.SetCourse(s6);
					readFile >> s7;
					boy->student.SetNameUniv(s7);
					readFile >> s8;
					boy->student.SetSpec(s8);
					readFile >> s9;
					boy->student.SetGroupNum(s9);
				}
				current = tail;
				current->next = new Schoolboy;
				current = current->next;
				tail = current;
				current->schoolKid.SetFio(boy->schoolKid.GetFio());
				if (listNum == 1 || listNum == 2)
				{
					current->schoolKid.SetClase(boy->schoolKid.GetClase());
				}
				current->schoolKid.SetNumber(boy->schoolKid.GetNumber());
				current->schoolKid.SetGrades(boy->schoolKid.GetGrades());
				if (listNum == 2)
				{
					current->cadet.SetSchoolNum(boy->cadet.GetSchoolNum());
					current->cadet.SetRank(boy->cadet.GetRank());
				}
				else if (listNum == 3)
				{
					current->student.SetId(boy->student.GetId());
					current->student.SetCourse(boy->student.GetCourse());
					current->student.SetNameUniv(boy->student.GetNameUniv());
					current->student.SetSpec(boy->student.GetSpec());
					current->student.SetGroupNum(boy->student.GetGroupNum());
				}
			}
			cout << "\n������ ������� ���������\n";
			readFile.close();
		}
		break;
	}
	}
#else
	cout << "\n� ��� ���� ������, ��� ������� ����������\n";
#endif
}