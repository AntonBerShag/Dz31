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

	//������ 1
	cout << "������ 1\n������� ������ � ����� ���������: ";
	int N, M;
	cin >> N >> M;
	try {
		cout << "��������� ����� = " << randNum(N, M) << "\n\n";
	}
	catch(const invalid_argument &ex){
		cerr << "The beginning of the range is greater or equal than the end of the range: ";
		cerr << ex.what() << "\n\n";
	}

	//������ 2
	cout << "������ 2\n������� ������ \"����� �����_�����\": ";
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

//������ 2
bool lengtStr(string str) {
	int index = 0; // ��� ������ �������
	int num = 0; // ��� �������� ���� ����� ������� if(num > 0)
	int nums = 0; // ��� �������������� � int
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			num++;
		index = str.find(" ");
	}
	if (num > 1)
		throw runtime_error("������� ���������� ������\n");
	if (num < 1)
		throw runtime_error("������� ���������� ������\n");
	if (index == str.length() + 1)
		throw runtime_error("������� ���������� ������\n");
	for (int j = index + 1; j < str.length(); j++) {
		string str2 = str.substr(j, str.length());
		nums = stoi(str2);
	}
	if(index > nums)
		throw runtime_error("������� ���������� ������\n");
	if (index == nums)
		return true;
	return false;

}
//������ 1
int randNum(int N, int M) {
	int randNum;
	if (N >= M)
		throw invalid_argument("Invalid value!\n");
	return randNum = rand() % (M - N + 1) + N;
}