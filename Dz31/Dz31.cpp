#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int randNum(int N, int M);
bool lengtStr(string str);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	//Задача 1
	cout << "Задача 1\nВведите начало и конец диапазона: ";
	int N, M;
	cin >> N >> M;
	try {
		cout << "Случайное число = " << randNum(N, M) << "\n\n";
	}
	catch(const invalid_argument &ex){
		cerr << "The beginning of the range is greater or equal than the end of the range: ";
		cerr << ex.what() << "\n\n";
	}

	//Задача 2
	cout << "Задача 2\nВведите строку \"слово длина_слова\": ";
	string str;
	cin.ignore(256, '\n');
	getline(cin, str);
	try {
		if (lengtStr(str))
			cout << "True\n\n";
		else
			cout << "False\n\n";
	}
	catch(const runtime_error& ex){
		cout << ex.what() << "\n\n";
	}

	return 0;
}

//Задача 2
bool lengtStr(string str) {
	int index = 0; // для записи пробела
	int num = 0; // для проверки цифр после пробела if(num > 0)
	int nums = 0; // для преобразования в int
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			num++;
		index = str.find(" ");
	}
	if (num > 1)
		throw runtime_error("Неверно составлена строка\n");
	if (num < 1)
		throw runtime_error("Неверно составлена строка\n");
	if (index == str.length() + 1)
		throw runtime_error("Неверно составлена строка\n");
	for (int j = index + 1; j < str.length(); j++) {
		string str2 = str.substr(j, str.length());
		nums = stoi(str2);
	}
	if(index > nums)
		throw runtime_error("Неверно составлена строка\n");
	if (index == nums)
		return true;
	return false;

}
//Задача 1
int randNum(int N, int M) {
	int randNum;
	if (N >= M)
		throw invalid_argument("Invalid value!\n");
	return randNum = rand() % (M - N + 1) + N;
}