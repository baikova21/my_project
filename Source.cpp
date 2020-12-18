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
	computer_software(); // Конструктор по умолчанию
	computer_software(char* Brand, int Speed, int Version, int Type, int Series_number); // Конструктор с параметрами
	computer_software(const computer_software& s); // Копирующий конструктор
	~computer_software(); // Деструктор
	void copy(const computer_software& s); // Функция копирования полей одного объекта в другой

	int get_work_speed() const; // Функция, которая возвращает значение поля work_speed
	void set_software(); // Изменение всех полей объекта

	computer_software& operator=(const computer_software& s); // перегрузка оператора присваивания
	bool operator>(const computer_software& s); // перегрузка оператора "больше"
	friend ostream& operator<<(ostream& out, const computer_software& s); // перегрузка оператора вывода
};

template <class T>
class conteiner {
private:
	int capacity = 0; // Вместимость вектора
	T* mas = NULL; // Сам вектор

public:
	~conteiner(); // Деструктор
	conteiner(int Capacity); // Конструктор с параметром
	void enter_vector(); // Изменение элементов вектора
	void get_vector() const; // Вывод элементов вектора

	void search() const; // Поиск
	void compare() const; // Сравнение
	void sort(); // Сортировка

};

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	conteiner<computer_software> vector(4); // Создаем вектор
	vector.get_vector(); // Выводим элементы вектора
	system("pause");
	system("cls");
	vector.enter_vector(); // Изменяем элементы вектора
	system("cls");
	vector.get_vector(); // Выводим элементы вектора
	system("pause");
	system("cls");
	vector.search(); // Поиск
	system("pause");
	system("cls");
	vector.compare(); // Сравнение
	system("pause");
	system("cls");
	vector.sort(); // Сортировка
	vector.get_vector(); // Выводим элементы вектора
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

computer_software& computer_software::operator=(const computer_software& s)
{
	if (this != &s) {
		copy(s);
	}
	return *this;
}

bool computer_software::operator>(const computer_software& s)
{
	return work_speed > s.work_speed;
}

template <class T>
conteiner<T>::~conteiner()
{
	delete[] mas;
}

template <class T>
conteiner<T>::conteiner(int Capacity)
{
	if (Capacity > 0) {
		capacity = Capacity;
		mas = new T[capacity];
	}
	else {
		cout << "Ошибка создания!\n";
	}
}

template <class T>
void conteiner<T>::enter_vector()
{
	for (int i = 0; i < capacity; i++) {
		mas[i].set_software();
	}
}

template <class T>
void conteiner<T>::get_vector() const
{
	for (int i = 0; i < capacity; i++) {
		cout << mas[i];
	}
}

template <class T>
void conteiner<T>::search() const
{
	int speed;
	cout << "ПОИСК\nВведите скорость работы: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() == speed) cout << mas[i];
	}
}

template <class T>
void conteiner<T>::compare() const
{
	int speed;
	cout << "СРАВНЕНИЕ\nВведите скорость работы: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() >= speed) cout << mas[i];
	}
}

template <class T>
void conteiner<T>::sort()
{
	for (int i = 0; i < capacity - 1; i++) {
		for (int j = i + 1; j < capacity; j++) {
			if (mas[i] > mas[j]) {
				T tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
		}
	}
}

ostream& operator<<(ostream& out, const computer_software& s)
{
	out << "______________________________\n";
	out << "Бренд: " << s.brand << endl;
	out << "Скорость работы: " << s.work_speed << endl;
	out << "Версия: " << s.version << endl;
	out << "Тип: " << s.type << endl;
	out << "Серийный номер: " << s.series_number << endl;
	return out;
}
