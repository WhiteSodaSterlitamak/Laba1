#include <iostream>
#include <limits>

//���-�� �������� �����
extern int amount;

float getValue();

//���� ���-�� ����� � �������
bool init() {
	while (true) {
		std::cout << "������� ����� ������ �������? (������� 2)\n";
		std::cin >> amount;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (amount >= 2) return true;
		else std::cout << "������ �����. ������� ����� ��� ���.\n";
	}
	return true;
}

//�������� ���-�� ����� �� �����
bool finit(std::istream& f) {
	f >> amount;

	if (f.fail()) {
		std::cout << "������ ����� ����� n �� �����\n";
		return false;
	}

	if (amount >= 2) return true;
	else {
		std::cout << "������ ����� ����� n �� �����\n";
		return false;
	}

	return true;
}

//���������� ������ ���� ���� �����
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
		else std::cout << "������ �����."; 
	}
}

//������� ���������� �� �������
void calcConsole(std::ostream& f) {
	float result{1};
	float a, b;
	a = getValue();
	for (int i = 0; i < amount - 1; i++) {
		b = getValue();
		result *= b + (1 / (abs(a) + 1));
		a = b;
	}
	f << "��������� ����������: " << result << std::endl;
}

//������� ����������� �� �����
void calcf(std::ostream& f, std::istream& fin) {
	float result{ 1 };
	float a, b;
	fin >> a;
	for (int i = 0; i < amount - 1; i++) {
		fin >> b;
		result *= b + (1 / (abs(a) + 1));
		a = b;
	}
	f << "��������� ����������: " << result << std::endl;
}

//���������� ���������� ��� ���
bool getNext() {
	std::cout << "����������? (0 - ���, 1 - ��)\n";
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
		else std::cout << "������ �����";
	}
}

//�������� ����� �� �������
float getValue() {
	float a;
	while (true) {
		std::cin >> a;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "������ �����\n";
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return a;
		}
	}
}