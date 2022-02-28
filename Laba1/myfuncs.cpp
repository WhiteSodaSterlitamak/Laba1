#include <iostream>
#include <limits>

//кол-во вводимых чисел
extern int amount;

float getValue();

//ввод кол-во чисел с консоли
bool init() {
	while (true) {
		std::cout << "Сколько чисел будете вводить? (минимум 2)\n";
		std::cin >> amount;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (amount >= 2) return true;
		else std::cout << "Ошибка ввода. Введите число еще раз.\n";
	}
	return true;
}

//получаем кол-во чисел из файла
bool finit(std::istream& f) {
	f >> amount;

	if (f.fail()) {
		std::cout << "Ошибка ввода числа n из файла\n";
		return false;
	}

	if (amount >= 2) return true;
	else {
		std::cout << "Ошибка ввода числа n из файла\n";
		return false;
	}

	return true;
}

//спрашиваем откуда ввод куда вывод
unsigned char get_in_out() {
	while (true) {
		char check{};
		std::cin >> check;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (check == '0' || check == '1') return check;
		else std::cout << "Ошибка ввода."; 
	}
}

//подсчет результата из консоли
void calcConsole(std::ostream& f) {
	float result{1};
	float a, b;
	a = getValue();
	for (int i = 0; i < amount - 1; i++) {
		b = getValue();
		result *= b + (1 / (abs(a) + 1));
		a = b;
	}
	f << "Результат вычислений: " << result << std::endl;
}

//подсчет результатов из файла
void calcf(std::ostream& f, std::istream& fin) {
	float result{ 1 };
	float a, b;
	fin >> a;
	for (int i = 0; i < amount - 1; i++) {
		fin >> b;
		result *= b + (1 / (abs(a) + 1));
		a = b;
	}
	f << "Результат вычислений: " << result << std::endl;
}

//спрашиваем продолжить или нет
bool getNext() {
	std::cout << "Продолжить? (0 - нет, 1 - да)\n";
	while (true) {
		char sm;
		std::cin >> sm;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (sm == '0' || sm == '1') {
			return sm == '1' ? true : false;
		}
		else std::cout << "Ошибка ввода";
	}
}

//получаем числа из консоли
float getValue() {
	float a;
	while (true) {
		std::cin >> a;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка ввода\n";
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return a;
		}
	}
}