#include <iostream>
#include <fstream>
#include "myfuncs.h"

int amount{};

int main() {
	setlocale(LC_ALL, "RUS");
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	unsigned char input{};
	unsigned char output{};

	while (true) {

		if (fin.is_open() && fout.is_open()) {

			std::cout << "Откуда произвести ввод? 0 - консоль 1 - файл\n";
			input = get_in_out();

			std::cout << "Куда произвести вывод? 0 - консоль 1 - файл\n";
			output = get_in_out();

			if (input == '0' && output == '0') {

				if (init()) {
					std::cout << "Введите числа: \n";
					calcConsole(std::cout);
				}

				if (getNext())
					continue;
				else
					break;
			}

			else if (input == '0' && output == '1') {

				if (init()) {
					std::cout << "Введите числа: \n";
					calcConsole(fout);
				}

				if (getNext())
					continue;
				else
					break;
			}

			else if (input == '1' && output == '0') {

				if (finit(fin)) {
					calcf(std::cout, fin);
				}
				break;

			}

			else if (input == '1' && output == '1') {

				if (finit(fin)) {
					calcf(fout, fin);
				}
				break;
			}
			else {
				std::cout << "Ошибка ввода \ ввывода";
				break;
			}
		}
		std::cout << "Ошибка открытия файлов (";
		break;
	}
	fin.close();
	fout.close();
}