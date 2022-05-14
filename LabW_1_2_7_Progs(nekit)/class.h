#include "Libs.h"

class Schoolboy {

	const int maxListNum = 3;

	Schoolboy* next = NULL;
	Schoolboy* prev = NULL;

	friend void SaveFile(Schoolboy*&);
	friend void LoadFile(Schoolboy*&, Schoolboy*&);

public:
	class DefaultDate
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

		DefaultDate()
		{
			Fio = "";
			Clase = "";
			Number = "";
			Grades = "";
		}

		DefaultDate(const DefaultDate& other)
		{
			this->Fio = other.Fio;
			this->Clase = other.Clase;
			this->Number = other.Number;
			this->Grades = other.Grades;
		}

		void OutDate()
		{
			cout << endl;
			cout << "����� ������: ";
			cout << '\n' << Fio << endl;
			cout << '\n' << Clase << endl;
			cout << '\n' << Number << endl;
			cout << '\n' << Grades << endl;
			cout << endl;
		}

		void SortDate(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& childs)
		{
			childs = head;
			int counter = 1;
			Schoolboy* temp = NULL;
			temp = new Schoolboy;
			while (true)
			{
				counter++;
				childs = childs->next;
				if (childs == tail)
					break;
			}
			childs = head;
			for (int i = 1; i < counter; i++)
			{
				childs = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (childs->Info1.Grades < childs->next->Info1.Grades)
					{
						temp->Info1 = childs->Info1;
						childs->Info1 = childs->next->Info1;
						childs->next->Info1 = temp->Info1;
					}
					childs = childs->next;
				}
			}
		}

	} Info1;

	class OtherDate1 : DefaultDate
	{
		int SchoolNum;
		string Rank;
	public:
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
	}Info2;

	class OtherDate2 : DefaultDate
	{
		int Id;
		int Course;
		string NameUniv;
		string Spec;
		string GroupNum;
	public:
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
	}Info3;

	Schoolboy* GetNext()
	{
		return next;
	}

	Schoolboy()
	{
		Info1.SetFio("");
		if (listNum == 1 || listNum == 2)
		{
			Info1.SetClase("");
		}
		Info1.SetNumber("");
		Info1.SetGrades("");
		if (listNum == 2)
		{
			Info2.SetSchoolNum(0);
			Info2.SetRank("");
		}
		else if (listNum == 3)
		{
			Info3.SetId(0);
			Info3.SetCourse(1);
			Info3.SetNameUniv("");
			Info3.SetSpec("");
			Info3.SetGroupNum("");
		}
	};

	Schoolboy(string fio, string clase, string number,
		string grades, int schoolNum, string rank,
		int id, int course, string nameUniv, string spec,
		string groupNum
	)
	{
		Info1.SetFio(fio);
		if (listNum == 1 || listNum == 2)
		{
			Info1.SetClase(clase);
		}
		Info1.SetNumber(number);
		Info1.SetGrades(grades);
		if (listNum == 2)
		{
			Info2.SetSchoolNum(schoolNum);
			Info2.SetRank(rank);
		}
		else if (listNum == 3)
		{
			Info3.SetId(id);
			Info3.SetCourse(course);
			Info3.SetNameUniv(nameUniv);
			Info3.SetSpec(spec);
			Info3.SetGroupNum(groupNum);
		}
	};

	void Preperation(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& childs)
	{
		while (true)
		{
			if (childs->next == NULL)
				break;
			childs = childs->next;
			tail = childs;

		}
		childs = head;
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
			childs->next = new Schoolboy(Fios[i], Clase[i], Numbers[i], Gradess[i],
				schoolNums[i], Ranks[i], Ids[i], Courses[i],
				nameUnivs[i], Specs[i], GroupNums[i]);
			childs = childs->next;
		}

		childs = head;
		while (true) {
			if (childs->next == NULL)
				break;
			childs = childs->next;
			tail = childs;
		}
		while (true) {
			if (childs->prev == NULL)
				break;
			childs = childs->prev;
			head = childs;
		}
	}

	void AfterPreparation(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& childs)
	{
		childs = head;
		while (true)
		{
			if (childs->next == NULL)
				break;
			childs = childs->next;
			tail = childs;
		}
		while (true)
		{
			if (childs->prev == NULL)
				break;
			childs = childs->prev;
			head = childs;
		}
	}

	void CreateBoy(Schoolboy*& tail, Schoolboy*& childs)
	{
		cout << "\n��������� ����� - ����������\n";

		string s1, s2, s3, s4, s6, s9, s10, s11;
		int s5, s7, s8;
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
		if (listNum == 2)
		{
			cout << "\n����� �����: ";
			cin >> s5;
			cin.get();
			cout << "\n������: ";
			getline(cin, s6);
		}
		else if (listNum == 3)
		{
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
		}
		childs = tail;
		childs->next = new Schoolboy;
		childs = childs->next;

		childs->Info1.SetFio(s1);
		if (listNum == 1 || listNum == 2)
		{
			childs->Info1.SetClase(s2);
		}
		childs->Info1.SetNumber(s3);
		childs->Info1.SetGrades(s4);
		if (listNum == 2)
		{
			childs->Info2.SetSchoolNum(s5);
			childs->Info2.SetRank(s6);
		}
		else if (listNum == 3)
		{
			childs->Info3.SetId(s7);
			childs->Info3.SetCourse(s8);
			childs->Info3.SetNameUniv(s9);
			childs->Info3.SetSpec(s10);
			childs->Info3.SetGroupNum(s11);
		}
		cout << "\n������ ������� ���������!\n";
	}

	void DeleteBoy(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& childs)
	{
		if (head == NULL || tail == NULL)
		{
			cout << "\n� ������ ��� ������\n";
		}
		//childs = head;
		//while (true)
		//{
		//	if (childs->next == NULL) break;
		//	childs = childs->next;
		//	tail = childs;
		//}
		//while (true)
		//{
		//	if (childs->prev == NULL) break;
		//	childs = childs->prev;
		//	head = childs;
		//}
		cout << "\n��������� ����� - ��������\n";
		//childs = head;
		cout << "\n������� ����� ������, ������� ����� �������: ";
		int lineNum;
		cin >> lineNum;
		childs = head;
		bool isChilds = true;
		for (int i = 0; i < lineNum - 1; i++)
		{
			childs = childs->next;
			if (!childs)
			{
				isChilds = false;
				throw exception("��� ������ � ������ �������");
				break;
			}
		}
		if (isChilds == true)
		{
			cout << "\n�� ����� ������ ������� ������ ��� ������� '" << lineNum << "'? (1 - ��, 2 - ���)\n";
			int delAction;
			cin >> delAction;
			switch (delAction)
			{
			case(1):
			{
				if (childs == head && childs != tail)
				{
					head = childs->next;
					head->prev = NULL;
				}
				else if (childs == tail && childs != head)
				{
					tail = childs->prev;
					tail->next = NULL;
				}
				else
				{
					head = NULL;
					tail = NULL;
				}
				delete childs;
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
			childs = head;
		}
	}

	void ChangeBoy(Schoolboy*& childs)
	{
		cout << "\n��������� ����� - ���������\n";
		cout << "\n������� ����� ������, ������� ����� ��������: ";
		int lineNum;
		cin >> lineNum;
		bool isChilds = true;
		for (int i = 0; i < lineNum - 1; i++)
		{
			childs = childs->next;
			if (!childs)
			{
				isChilds = false;
				throw exception("��� ������ � ������ �������");
				break;
			}
		}
		if (isChilds == true)
		{
			cout << "\n�� ����� ������ ������� ������ ��� ������� '" << lineNum << "'? (1 - ��, 2 - ���)\n";
			int delAction;
			cin >> delAction;
			switch (delAction)
			{
			case(1):
			{
				string s1, s2, s3, s4, s6, s9, s10, s11;
				int s5, s7, s8;
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
				if (listNum == 2)
				{
					cout << "\n����� �����: ";
					cin >> s5;
					cin.get();
					cout << "\n������: ";
					getline(cin, s6);
				}
				else if (listNum == 3)
				{
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
				}
				Info1.SetFio(s1);
				if (listNum == 1 || listNum == 2)
				{
					Info1.SetClase(s2);
				}
				Info1.SetNumber(s3);
				Info1.SetGrades(s4);
				if (listNum == 2)
				{
					Info2.SetSchoolNum(s5);
					Info2.SetRank(s6);
				}
				else if (listNum == 3)
				{
					Info3.SetId(s7);
					Info3.SetCourse(s8);
					Info3.SetNameUniv(s9);
					Info3.SetSpec(s10);
					Info3.SetGroupNum(s11);
				}
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

	void OutBoy(Schoolboy*& head, Schoolboy*& childs)
	{
		cout << "\n��������� ����� - ����� �������\n";
		if (listNum == 1)
		{
			cout << "|------------------------------------------------------------------------------------|" << endl;
			cout << "| ������� '�������'                                                                  |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|" << endl;
			cout << "|              ���              | ����� | ����� �������� |  ������  | ������� ������ |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|" << endl;
		}
		else if (listNum == 2)
		{
			cout << "|-----------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| ������� '������'                                                                                                |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|-------------|--------------|" << endl;
			cout << "|              ���              | ����� | ����� �������� |  ������  | ������� ������ | ����� ����� |    ������    |" << endl;
			cout << "|-------------------------------|-------|----------------|----------|----------------|-------------|--------------|" << endl;
		}
		else if (listNum == 3)
		{
			cout << "|------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| ������� '��������'                                                                                                                       |" << endl;
			cout << "|-------------------------------|----------------|----------|----------------|---------------|------|-------------|---------------|--------|" << endl;
			cout << "|              ���              | ����� �������� |  ������  | ������� ������ | ����� ������� | ���� | ����������� | ������������� | ������ |" << endl;
			cout << "|-------------------------------|----------------|----------|----------------|---------------|------|-------------|---------------|--------|" << endl;
		}
		childs = head;

		while (true) {
			int size = childs->Info1.GetGrades().size();
			float num = 0;
			float count = 0;
			for (int i = 0; i < size; i++)
			{
				switch (childs->Info1.GetGrades()[i])
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
			cout << left << childs->Info1.GetFio().c_str();
			cout << "| ";
			if (listNum == 1 || listNum == 2)
			{
				cout.width(6);
				cout << left << childs->Info1.GetClase().c_str();
				cout << "| ";
			}
			cout.width(15);
			cout << left << childs->Info1.GetNumber().c_str();
			cout << "| ";
			cout.width(9);
			cout << left << childs->Info1.GetGrades().c_str();
			cout << "| ";
			cout.width(15);
			cout << left << avgGrades;
			if (listNum == 2)
			{
				cout << "| ";
				cout.width(12);
				cout << left << childs->Info2.GetSchoolNum();
				cout << "| ";
				cout.width(13);
				cout << left << childs->Info2.GetRank().c_str();
			}
			else if (listNum == 3)
			{
				cout << "| ";
				cout.width(14);
				cout << left << childs->Info3.GetId();
				cout << "| ";
				cout.width(5);
				cout << left << childs->Info3.GetCourse();
				cout << "| ";
				cout.width(12);
				cout << left << childs->Info3.GetNameUniv().c_str();
				cout << "| ";
				cout.width(14);
				cout << left << childs->Info3.GetSpec().c_str();
				cout << "| ";
				cout.width(7);
				cout << left << childs->Info3.GetGroupNum().c_str();
			}
			cout << "|" << endl;
			if (listNum == 1)
			{
				cout << "|-------------------------------|-------|----------------|----------|----------------|" << endl;
			}
			else if (listNum == 2)
			{
				cout << "|-------------------------------|-------|----------------|----------|----------------|-------------|--------------|" << endl;
			}
			else if (listNum == 3)
			{
				cout << "|-------------------------------|----------------|----------|----------------|---------------|------|-------------|---------------|--------|" << endl;
			}
			if (childs->next == NULL) break;
			childs = childs->next;
		}
		childs = head;
	}

	void SortBoy(Schoolboy*& head, Schoolboy*& tail, Schoolboy*& childs)
	{
		cout << "\n��������� ����� - ����������\n";
		childs = head;
		int counter = 1;
		Schoolboy* temp = NULL;
		temp = new Schoolboy;
		while (true)
		{
			counter++;
			childs = childs->next;
			if (childs == tail)
				break;
		}
		childs = head;
		if (listNum == 1 || listNum == 2)
		{
			for (int i = 1; i < counter; i++)
			{
				childs = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (childs->Info1.GetClase() > childs->next->Info1.GetClase())
					{
						temp->Info1 = childs->Info1;
						childs->Info1 = childs->next->Info1;
						childs->next->Info1 = temp->Info1;
						temp->Info2 = childs->Info2;
						childs->Info2 = childs->next->Info2;
						childs->next->Info2 = temp->Info2;
					}
					childs = childs->next;
				}
			}
			cout << "\n������ ������� ������������� �� �������\n";
		}
		else
		{
			for (int i = 1; i < counter; i++)
			{
				childs = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (childs->Info3.GetCourse() > childs->next->Info3.GetCourse())
					{
						temp->Info1 = childs->Info1;
						childs->Info1 = childs->next->Info1;
						childs->next->Info1 = temp->Info1;
						temp->Info3 = childs->Info3;
						childs->Info3 = childs->next->Info3;
						childs->next->Info3 = temp->Info3;
					}
					childs = childs->next;
				}
			}
			cout << "\n������ ������� ������������� �� ������\n";
		}
	}

	void SearchBoys(Schoolboy*& head, Schoolboy*& childs)
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
		childs = head;
		bool SuccesSearch = false;
		while (true)
		{
			if (childs == NULL)
				break;

			if (listNum == 1 || listNum == 2)
			{
				if (search == childs->Info1.GetClase())
				{
					int size = childs->Info1.GetGrades().size();
					float num = 0;
					float count = 0;
					for (int i = 0; i < size; i++)
					{
						switch (childs->Info1.GetGrades()[i])
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
					cout << "\n���: " << childs->Info1.GetFio()
						<< "\n�����: " << childs->Info1.GetClase()
						<< "\n����� ��������: " << childs->Info1.GetNumber()
						<< "\n������: " << childs->Info1.GetGrades()
						<< "\n������� ������: " << avgGrades;
					if (listNum == 1)
					{
						cout << endl;
					}
					else if (listNum == 2)
					{
						cout << "\n����� �����: " << childs->Info2.GetSchoolNum();
						cout << "\n������: " << childs->Info2.GetRank() << endl;
					}
				}
			}
			else if (listNum == 3)
			{
				if (search == childs->Info3.GetSpec())
				{
					int size = childs->Info1.GetGrades().size();
					float num = 0;
					float count = 0;
					for (int i = 0; i < size; i++)
					{
						switch (childs->Info1.GetGrades()[i])
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
					cout << "\n���: " << childs->Info1.GetFio()
						<< "\n����� ��������: " << childs->Info1.GetNumber()
						<< "\n������: " << childs->Info1.GetGrades()
						<< "\n������� ������: " << avgGrades
						<< "\n����� �������: " << childs->Info3.GetId()
						<< "\n����: " << childs->Info3.GetCourse()
						<< "\n�����������: " << childs->Info3.GetNameUniv()
						<< "\n�������������: " << childs->Info3.GetSpec()
						<< "\n����� ������: " << childs->Info3.GetGroupNum() << endl;
				}
			}
			childs = childs->next;
		}
		childs = head;
		if (SuccesSearch == true)
		{
			cout << "\n������� ����������\n";
		}
		else
		{
			cout << "\n���������� �� �������\n";
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
					writeFile << boy.Info1.GetFio() << ' ' << boy.Info1.GetClase() << ' ' << boy.Info1.GetNumber() << ' ' << boy.Info1.GetGrades();
				}
				else if (listNum == 2)
				{
					writeFile << boy.Info1.GetFio() << ' ' << boy.Info1.GetClase() << ' ' << boy.Info1.GetNumber() << ' ' << boy.Info1.GetGrades() << ' ' << boy.Info2.GetSchoolNum() << ' ' << boy.Info2.GetRank();
				}
				else if (listNum == 3)
				{
					writeFile << boy.Info1.GetFio() << ' ' << boy.Info1.GetNumber() << ' '
						<< boy.Info1.GetGrades() << ' ' << boy.Info3.GetId() << ' ' << boy.Info3.GetCourse()
						<< ' ' << boy.Info3.GetNameUniv() << ' ' << boy.Info3.GetSpec() << ' ' << boy.Info3.GetGroupNum();
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
					writeFile << boy.Info1.GetFio() << ' ' << boy.Info1.GetClase() << ' ' << boy.Info1.GetNumber() << ' ' << boy.Info1.GetGrades();
				}
				else if (listNum == 2)
				{
					writeFile << boy.Info1.GetFio() << ' ' << boy.Info1.GetClase() << ' ' << boy.Info1.GetNumber() << ' ' << boy.Info1.GetGrades() << ' ' << boy.Info2.GetSchoolNum() << ' ' << boy.Info2.GetRank();
				}
				else if (listNum == 3)
				{
					writeFile << boy.Info1.GetFio() << ' ' << boy.Info1.GetNumber() << ' '
						<< boy.Info1.GetGrades() << ' ' << boy.Info3.GetId() << ' ' << boy.Info3.GetCourse()
						<< ' ' << boy.Info3.GetNameUniv() << ' ' << boy.Info3.GetSpec() << ' ' << boy.Info3.GetGroupNum();
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

void LoadFile(Schoolboy*& tail, Schoolboy*& childs)
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
				boy->Info1.SetFio(name + " " + surname + " " + patronymic);
				if (listNum == 1 || listNum == 2)
				{
					readFile >> s1;
					boy->Info1.SetClase(s1);
				}
				readFile >> s2;
				boy->Info1.SetNumber(s2);
				readFile >> g1 >> g2 >> g3;
				boy->Info1.SetGrades(g1 + " " + g2 + " " + g3);
				if (listNum == 2)
				{
					readFile >> s3;
					boy->Info2.SetSchoolNum(s3);
					readFile >> s4;
					boy->Info2.SetRank(s4);
				}
				else if (listNum == 3)
				{
					readFile >> s5;
					boy->Info3.SetId(s5);
					readFile >> s6;
					boy->Info3.SetCourse(s6);
					readFile >> s7;
					boy->Info3.SetNameUniv(s7);
					readFile >> s8;
					boy->Info3.SetSpec(s8);
					readFile >> s9;
					boy->Info3.SetGroupNum(s9);
				}
				childs = tail;
				childs->next = new Schoolboy;
				childs = childs->next;
				tail = childs;
				childs->Info1.SetFio(boy->Info1.GetFio());
				if (listNum == 1 || listNum == 2)
				{
					childs->Info1.SetClase(boy->Info1.GetClase());
				}
				childs->Info1.SetNumber(boy->Info1.GetNumber());
				childs->Info1.SetGrades(boy->Info1.GetGrades());
				if (listNum == 2)
				{
					childs->Info2.SetSchoolNum(boy->Info2.GetSchoolNum());
					childs->Info2.SetRank(boy->Info2.GetRank());
				}
				else if (listNum == 3)
				{
					childs->Info3.SetId(boy->Info3.GetId());
					childs->Info3.SetCourse(boy->Info3.GetCourse());
					childs->Info3.SetNameUniv(boy->Info3.GetNameUniv());
					childs->Info3.SetSpec(boy->Info3.GetSpec());
					childs->Info3.SetGroupNum(boy->Info3.GetGroupNum());
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
				boy->Info1.SetFio(name + " " + surname + " " + patronymic);
				if (listNum == 1 || listNum == 2)
				{
					readFile >> s1;
					boy->Info1.SetClase(s1);
				}
				readFile >> s2;
				boy->Info1.SetNumber(s2);
				readFile >> g1 >> g2 >> g3;
				boy->Info1.SetGrades(g1 + " " + g2 + " " + g3);
				if (listNum == 2)
				{
					readFile >> s3;
					boy->Info2.SetSchoolNum(s3);
					readFile >> s4;
					boy->Info2.SetRank(s4);
				}
				else if (listNum == 3)
				{
					readFile >> s5;
					boy->Info3.SetId(s5);
					readFile >> s6;
					boy->Info3.SetCourse(s6);
					readFile >> s7;
					boy->Info3.SetNameUniv(s7);
					readFile >> s8;
					boy->Info3.SetSpec(s8);
					readFile >> s9;
					boy->Info3.SetGroupNum(s9);
				}
				childs = tail;
				childs->next = new Schoolboy;
				childs = childs->next;
				tail = childs;
				childs->Info1.SetFio(boy->Info1.GetFio());
				if (listNum == 1 || listNum == 2)
				{
					childs->Info1.SetClase(boy->Info1.GetClase());
				}
				childs->Info1.SetNumber(boy->Info1.GetNumber());
				childs->Info1.SetGrades(boy->Info1.GetGrades());
				if (listNum == 2)
				{
					childs->Info2.SetSchoolNum(boy->Info2.GetSchoolNum());
					childs->Info2.SetRank(boy->Info2.GetRank());
				}
				else if (listNum == 3)
				{
					childs->Info3.SetId(boy->Info3.GetId());
					childs->Info3.SetCourse(boy->Info3.GetCourse());
					childs->Info3.SetNameUniv(boy->Info3.GetNameUniv());
					childs->Info3.SetSpec(boy->Info3.GetSpec());
					childs->Info3.SetGroupNum(boy->Info3.GetGroupNum());
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