#include<fstream>
#include<iostream>
#include<string>

//вывод содержимого файла по переданному пути в консоль
bool print_file(std::string file_path ) {
	static std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
		return true;
	}
	return false;
}


bool insert_file(std::string file_path, int position, std::string str) {
	std::fstream file;
	std::string file_text;

	// шаг 1
	file.open(file_path, std::ios::in);
	if (file.is_open()) {
		char sym;
		while (file.get(sym))
			file_text += sym;
		file.close();
	}
	else
		return false;

	// шаг2  изменение строки
	file_text.insert(position, str);

	// шаг 3  обновление содержимого файла
	file.open(file_path, std::ios::out);
	if (file.is_open()) {
		file << file_text;
		file.close();
		file.close();
		return true;
	}
	return false;
}





int main() {

	setlocale(LC_ALL, "Ru");
	int n;
	std::string path = "file.txt"; //путь к файлу



	/*std::fstream file;
	file.open(path,std::ios::in | std::ios::app); // в режимах открытия по умолчанию будет ошибка если файла не существует
	if (file.is_open()) {
		std::cout << " файл открыт \n";

		//запись в файл
		std::string str;
		std::cout << " Введите строку \n";
		std::getline(std::cin, str);
		file << str << '\n';
		std::cout << " запись добавлена в файл \n";

		file.seekg(0, std::ios::beg); // перемещение курсора в начало файла для дальнейшего считывания

		// чтение из файла
		std::cout << " содержимое файла \n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
		std::cout << std::endl;
	}
	else
		std::cout << " ошибка открытия \n";

	file.close();

	*/


	// задание - Добавление в середину файла
	/*std::cout << " исх файл \n";
	print_file(path);


	std::cout << " Введите позицию - ";
	std::cin >> n;
	std::cin.ignore();
	std::cout << " Введите строку";
	std::string str;
	std::getline(std::cin, str);

	if (insert_file(path, n, str)) {
		std::cout << " Вставка сделана успешно \n";
		std::cout << " Содержание файла: \n";
		print_file(path);
		std::cout << std::endl;

	}
	*/



	//задача 1 чтение даты из файла

	std::cout << " задача1 \n  Дата: ";
	print_file("date.txt");
	std::string date;

	std::ifstream read;
	read.open("date.txt");

	if (read.is_open()) {
		read >> date;
		read.close();
	}
	int day = std::stoi(date);
	int month = std::stoi(date.substr(date.find('.') + 1));
	int year  = std::stoi(date.substr(date.rfind('.') + 1));

	std::cout << " День:  " << day << std::endl;
	std::cout << " Месяц: " << month << std::endl;
	std::cout << " Год:   " << year << std::endl;

	return 0;
}