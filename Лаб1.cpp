#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
class computer_software {
private:
	char* brand = NULL; // Бренд
	int work_speed; // Скорость работы
	int version; // Версия
	int type; // Тип
	int series_number; // Серийный номер

public:
	void constructor(); // Псевдоконструктор по умолчанию
	void constructor(char* Brand, int Speed, int Version, int Type, int Series_number); // псевдоконструктор с параметрами
	void destructor(); // Псевдодеструктор

	int get_work_speed() const; // Функция, которая возвращает значение поля work_speed
	void get_software() const; // Вывод всех полей объекта
	void set_software(); // Изменение всех полей объекта
};

class conteiner {
private:
	int capacity = 0; // Вместимость вектора
	computer_software* mas; // Сам вектор

public:
	void destructor(); // Псевдодеструктор
	void set_vector(int Capacity); // Псевдоконструктор
	void enter_vector(); // Изменение элементов вектора
	void get_vector() const; // Вывод элементов вектора

	void search() const; // Поиск
	void compare() const; // Сравнение
	void sort(); // Сортировка

};

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	conteiner vector; // объявляем вектор
	vector.set_vector(4); // создаем вектор
	vector.get_vector(); // выводим элементы вектора
	system("pause");
	system("cls");
	vector.enter_vector(); // изменяем элементы вектора
	system("cls");
	vector.get_vector(); // выводим элементы вектора
	system("pause");
	system("cls");
	vector.search(); // поиск
	system("pause");
	system("cls");
	vector.compare(); // сравнение
	system("pause");
	system("cls");
	vector.sort(); // сортировка
	vector.get_vector(); // выводим элементы вектора
	vector.destructor(); // удаляем вектор
	system("pause");
	return 0;
}

void computer_software::constructor()
{
	char def[] = "default";
	brand = new char[strlen(def) + 1];
	strcpy_s(brand, strlen(def) + 1, def);

	work_speed = 0;
	version = 0;
	type = 0;
	series_number = 0;
}

void computer_software::constructor(char* Brand, int Speed, int Version, int Type, int Series_number)
{
	brand = new char[strlen(Brand) + 1];
	strcpy_s(brand, strlen(Brand) + 1, Brand);

	work_speed = Speed;
	version = Version;
	type = Type;
	series_number = Series_number;
}

void computer_software::destructor()
{
	if (brand != NULL) delete[] brand;
}

int computer_software::get_work_speed() const
{
	return work_speed;
}

void computer_software::get_software() const
{
	cout << "______________________________\n";
	cout << "Бренд: " << brand << endl;
	cout << "Скорость работы: " << work_speed << endl;
	cout << "Версия: " << version << endl;
	cout << "Тип: " << type << endl;
	cout << "Серийный номер: " << series_number << endl;
}

void computer_software::set_software()
{
	char str[25];
	cout << "Введите бренд: "; cin >> str;
	if (brand != NULL) delete[] brand;
	brand = new char[strlen(str) + 1];
	strcpy_s(brand, strlen(str) + 1, str);

	work_speed = rand() % 100;
	version = rand() % 100;
	type = rand() % 100;
	series_number = rand() % 100;
}

void conteiner::destructor()
{
	for (int i = 0; i < capacity; i++) {
		mas[i].destructor();
	}
	delete[] mas;
}

void conteiner::set_vector(int Capacity)
{
	if (Capacity > 0) {
		capacity = Capacity;
		mas = new computer_software[capacity];
		for (int i = 0; i < capacity; i++) {
			mas[i].constructor();
		}
	}
	else {
		cout << "Ошибка создания!\n";
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
	cout << "ПОИСК\nВведите скорость работы: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() == speed) mas[i].get_software();
	}
}

void conteiner::compare() const
{
	int speed;
	cout << "СРАВНЕНИЕ\nВведите скорость работы: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() >= speed) mas[i].get_software();
	}
}

void conteiner::sort()
{
	for (int i = 0; i < capacity - 1; i++) {
		for (int j = i + 1; j < capacity; j++) {
			if (mas[i].get_work_speed() > mas[j].get_work_speed()) {
				swap(mas[i], mas[j]);
			}
		}
	}
}
