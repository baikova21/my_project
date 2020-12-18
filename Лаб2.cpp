#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

class computer_software {
private:
	char* brand = NULL; // �����
	int work_speed; // �������� ������
	int version; // ������
	int type; // ���
	int series_number; // �������� �����

public:
	computer_software(); // ����������� �� ���������
	computer_software(char* Brand, int Speed, int Version, int Type, int Series_number); // ����������� � �����������
	computer_software(const computer_software& s); // ���������� �����������
	~computer_software(); // ����������
	void copy(const computer_software& s); // ������� ����������� ����� ������ ������� � ������

	int get_work_speed() const; // �������, ������� ���������� �������� ���� work_speed
	void get_software() const; // ����� ���� ����� �������
	void set_software(); // ��������� ���� ����� �������
};

class conteiner {
private:
	int capacity = 0; // ����������� �������
	computer_software* mas = NULL; // ��� ������

public:
	~conteiner(); // ����������
	conteiner(int Capacity); // ����������� � ����������
	void enter_vector(); // ��������� ��������� �������
	void get_vector() const; // ����� ��������� �������

	void search() const; // �����
	void compare() const; // ���������
	void sort(); // ����������

};

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	conteiner vector(4); // ������� ������
	vector.get_vector(); // ������� �������� �������
	system("pause");
	system("cls");
	vector.enter_vector(); // �������� �������� �������
	system("cls");
	vector.get_vector(); // ������� �������� �������
	system("pause");
	system("cls");
	vector.search(); // �����
	system("pause");
	system("cls");
	vector.compare(); // ���������
	system("pause");
	system("cls");
	vector.sort(); // ����������
	vector.get_vector(); // ������� �������� �������
	system("pause");
	return 0;
}

computer_software::computer_software()
{
	char def[] = "default";
	brand = new char[strlen(def) + 1];
	strcpy_s(brand, strlen(def) + 1, def);

	work_speed = 0;
	version = 0;
	type = 0;
	series_number = 0;
}

computer_software::computer_software(char* Brand, int Speed, int Version, int Type, int Series_number)
{
	brand = new char[strlen(Brand) + 1];
	strcpy_s(brand, strlen(Brand) + 1, Brand);

	work_speed = Speed;
	version = Version;
	type = Type;
	series_number = Series_number;
}

computer_software::computer_software(const computer_software& s)
{
	copy(s);
}

computer_software::~computer_software()
{
	if (brand != NULL) delete[] brand;
}

void computer_software::copy(const computer_software& s)
{
	if (brand != NULL) delete[] brand;
	if (s.brand != 0) {
		brand = new char[strlen(s.brand) + 1];
		strcpy_s(brand, strlen(s.brand) + 1, s.brand);
	}
	work_speed = s.work_speed;
	version = s.version;
	type = s.type;
	series_number = s.series_number;
}

int computer_software::get_work_speed() const
{
	return work_speed;
}

void computer_software::get_software() const
{
	cout << "______________________________\n";
	cout << "�����: " << brand << endl;
	cout << "�������� ������: " << work_speed << endl;
	cout << "������: " << version << endl;
	cout << "���: " << type << endl;
	cout << "�������� �����: " << series_number << endl;
}

void computer_software::set_software()
{
	char str[25];
	cout << "������� �����: "; cin >> str;
	if (brand != NULL) delete[] brand;
	brand = new char[strlen(str) + 1];
	strcpy_s(brand, strlen(str) + 1, str);

	work_speed = rand() % 100;
	version = rand() % 100;
	type = rand() % 100;
	series_number = rand() % 100;
}

conteiner::~conteiner()
{
	delete[] mas;
}

conteiner::conteiner(int Capacity)
{
	if (Capacity > 0) {
		capacity = Capacity;
		mas = new computer_software[capacity];
	}
	else {
		cout << "������ ��������!\n";
	}
}

void conteiner::enter_vector()
{
	for (int i = 0; i < capacity; i++) {
		mas[i].set_software();
	}
}

void conteiner::get_vector() const
{
	for (int i = 0; i < capacity; i++) {
		mas[i].get_software();
	}
}

void conteiner::search() const
{
	int speed;
	cout << "�����\n������� �������� ������: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() == speed) mas[i].get_software();
	}
}

void conteiner::compare() const
{
	int speed;
	cout << "���������\n������� �������� ������: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() >= speed) mas[i].get_software();
	}
}

void conteiner::sort()
{
	for (int i = 0; i < capacity - 1; i++) {
		for (int j = i + 1; j < capacity; j++) {
			if (mas[i].get_work_speed() > mas[j].get_work_speed()) {
				computer_software tmp(mas[i]);
				mas[i].copy(mas[j]);
				mas[j].copy(tmp);
			}
		}
	}
}
