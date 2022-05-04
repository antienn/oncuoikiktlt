#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<conio.h>

using namespace std;


struct sinhvien {
	string tksv;
	string name;
	string date;
	string hometown;
	string major;
	string pass;
};

sinhvien* ptr;

void dinhdangten(sinhvien arr[], int count) {
	char* name;
	for (int i = 0; i < count; i++) {
		name = new char[arr[i].name.length()];
		for (int j = 0; j < arr[i].name.length(); j++) {
			name[j] = arr[i].name[j];
		}
		name[0] = toupper(name[0]);
		for (int j = 0; j < arr[i].name.length(); j++) {
			if ((int)name[j] == 32) {
				name[j + 1] = toupper(name[j + 1]);
			}
		}
		for (int j = 0; j < arr[i].name.length(); j++) {
			arr[i].name[j] = name[j];
		}
	}
}

bool checksnt(int n,int number2 ,int sqrtn) {
	if (number2 > sqrtn) {
		return true;
	}
	else {
		if (n % number2 == 0) {
			return false;
		}
		else {
			return checksnt(n, number2 + 1, sqrtn);
		}
	}
}

bool isSpecialCharacters(char c) {
	if ((int)c >= 35 && (int)c <= 38 || (int)c == 64) {
		return true;
	}
	else {
		return false;
	}
}

bool isLetterCharacters(char c) {
	if ((int)c >= 97 && (int)c <= 122) {
		return true;
	}
	else {
		return false;
	}
}

bool isNumberCharacters(char c) {
	if ((int)c >= 48 && (int)c <= 57) {
		return true;
	}
	else {
		return false;
	}
}

bool isCapitalizeLetter(char c) {
	if ((int)c >= 65 && (int)c <= 90) {
		return true;
	}
	else {
		return false;
	}
}

bool checkChangePass(string pass) {
	int countSpecialCharacters = 0;
	int countLetterCharacters = 0;
	int countCapitalizeLetter = 0;
	int countsnt = 0;
	for (int i = 0; i < pass.length(); i++) {
		double tempsnt = 0;
		if (isSpecialCharacters(pass[i])) {
			countSpecialCharacters++;
		}
		if (isLetterCharacters(pass[i])) {
			countLetterCharacters++;
		}
		if (isCapitalizeLetter(pass[i])) {
			countCapitalizeLetter++;
		}
		if (isNumberCharacters(pass[i])) {
			tempsnt += ((int)pass[i] - 48);
			for (int j = i + 1; j < pass.length(); j++) {
				if (checksnt(tempsnt, 2, sqrt(tempsnt)) && tempsnt != 0 && tempsnt != 0) {
					countsnt++;
					break;
				}
				if (isNumberCharacters(pass[j])) {
					i++;
					tempsnt *= 10;
					tempsnt += ((int)pass[j] - 48);
				}
				else {
					break;
				}
			}
		}
	}
	/*cout << countLetterCharacters << endl;
	cout << countsnt << endl;
	cout << countSpecialCharacters << endl;
	cout << countCapitalizeLetter << endl;*/
	if (countLetterCharacters == 0 || countSpecialCharacters == 0 || countCapitalizeLetter == 0 || countsnt == 0) {
		return false;
	}
	else {
		return true;
	}
}

void inputPass(char pass[],string user) {
	int i = 0;
	char p = 0;
	cout << "password: ";
	while (true) {
		p = _getch();
		if (p == 13) {
			break;
		}
		if (p != 8) {
			pass[i] = p;
			cout << "*";
			i++;
		}
		else {
			pass[i] = '\0';
			i--;
			if (i < 0) {
				i = 0;
			}
			system("cls");
			cout << "-------logic---------" << endl;
			cout << "user: " << user << endl;
			cout << "password: ";
			for (int j = 0; j < i; j++) {
				cout << "*";
			}
		}
	}
	cout << endl;
	pass[i] = '\0';
	/*cout << pass << endl;*/
}
bool checkPass(char inputpass[],int count,string user) {
	bool passerror = false;
	int temp;
	for (int i = 0; i < count; i++) {
		if (user == ptr[i].tksv) {
			temp = i;
			for (int j = 0; j < ptr[i].pass.length(); j++) {
				if (inputpass[j] != ptr[i].pass[j]) {
					passerror = true;
				}
			}
		}
	}
	if (user == ptr[temp].tksv && !passerror) {
		return true;
	}
	return false;
}

void printInformation(int count, string user) {
	for (int i = 0; i < count; i++) {
		if (user == ptr[i].tksv) {
			cout << "-------------------------------------------" << endl;
			cout << "User: " << ptr[i].tksv << endl;
			cout << "Name: " << ptr[i].name << endl;
			cout << "Date: " << ptr[i].date << endl;
			cout << "Hometown: " << ptr[i].hometown << endl;
			cout << "Major: " << ptr[i].major << endl;
			cout << "password: ";
			int temp = ptr[i].pass.length();
			for (int i = 0; i < temp; i++) {
				cout << "*";
			}
			cout << "\n-------------------------------------------" << endl;
			break;
		}
	}
}

void comfirmName(string user, string tempname,int count) {
	char p;
	for (int i = 0; i < count; i++) {
		if (user == ptr[i].tksv) {
			cout << "Are you sure change " << ptr[i].name << " to " << tempname << endl;
			cout << "if you confirm, you will press enter key" << endl;
			p = _getch();
			if (p == 13) {
				ptr[i].name = tempname;
				system("cls");
				cout << "change successfull" << endl;
			}
			break;
		}
	}
}

void comfirmDate(string user, string tempdate, int count) {
	char p;
	for (int i = 0; i < count; i++) {
		if (user == ptr[i].tksv) {
			cout << "Are you sure change " << ptr[i].date << " to " << tempdate << endl;
			cout << "if you confirm, you will press enter key" << endl;
			p = _getch();
			if (p == 13) {
				ptr[i].date = tempdate;
				system("cls");
				cout << "change successfull" << endl;
			}
			break;
		}
	}
}


void comfirmHometown(string user, string temphometown, int count) {
	char p;
	for (int i = 0; i < count; i++) {
		if (user == ptr[i].tksv) {
			cout << "Are you sure change " << ptr[i].hometown << " to " << temphometown << endl;
			cout << "if you confirm, you will press enter key" << endl;
			p = _getch();
			if (p == 13) {
				ptr[i].hometown = temphometown;
				system("cls");
				cout << "change successfull" << endl;
			}
			break;
		}
	}
}

void comfirmMajor(string user, string tempmajor, int count) {
	char p;
	for (int i = 0; i < count; i++) {
		if (user == ptr[i].tksv) {
			cout << "Are you sure change " << ptr[i].major << " to " << tempmajor << endl;
			cout << "if you confirm, you will press enter key" << endl;
			p = _getch();
			if (p == 13) {
				ptr[i].major = tempmajor;
				system("cls");
				cout << "change successfull" << endl;
			}
			break;
		}
	}
}

bool slidechangepass(string& temppass, int count, string user ) {
	int i = 0;
	char oldPass[20];
	char newPass[20];
	char p;
	system("cls");
	cout << "old pass: ";
	while (true) {
		p = _getch();
		if (p == 13) {
			break;
		}
		oldPass[i] = p;
		cout << "*";
		i++;
	}
	oldPass[i] = '\0';
	cout << endl;
	cout << "new pass: ";
	i = 0;
	while (true) {
		p = _getch();
		if (p == 13) {
			break;
		}
		newPass[i] = p;
		cout << "*";
		i++;
	}
	newPass[i] = '\0';
	cout << endl;
	if (!checkPass(oldPass, count, user)) {
		cout << "old pass wrong!" << endl;
		return false;
	}
	if (!checkChangePass(newPass)) {
		cout << "The password is still weak, please try again" << endl;
		return false;
	}
	temppass = newPass;
	return true;
}

void comfirmPass(string user, string temppass, int count) {
	char p;
	for (int i = 0; i < count; i++) {
		if (user == ptr[i].tksv) {
			cout << "Are you sure change pass" << endl;
			cout << "if you confirm, you will press enter key" << endl;
			p = _getch();
			if (p == 13) {
				ptr[i].pass = temppass;
				system("cls");
				cout << "change successfull" << endl;
			}
			break;
		}
	}
}

int main() {
	string tempinformation;
	bool loginSuccessfull = false;
	int choose;
	int countwrong = 0;
	string user;
	char temppass[20] ;
	ifstream ifile;
	ofstream ghifile;
	int count = 0;
	string temp;
	int index = 0;
	ifile.open("sinhvien.txt");
	ghifile.open("sinhviennew.txt", ios::out);
	if (!ifile.is_open()) {
		return 1;
	}
	while (ifile.eof() == false) {
		getline(ifile, temp);
		count++;
	}
	ptr = new sinhvien[count];
	ifile.close();
	ifile.open("sinhvien.txt");
	if (!ifile.is_open()) {
		return 1;
	}
	while (ifile.eof() == false) {
		getline(ifile, ptr[index].tksv, ',');
		getline(ifile, ptr[index].name, ',');
		getline(ifile, ptr[index].date, ',');
		getline(ifile, ptr[index].hometown, ',');
		getline(ifile, ptr[index].major, ',');
		getline(ifile, ptr[index].pass);
		index++;
	}
	ifile.close();
	dinhdangten(ptr, count);
	//menu
	do {
		system("cls");
		cout << "-------logic---------" << endl;
		cout << "user: ";
		cin >> user;
		inputPass(temppass, user);
		if (!checkPass(temppass, count, user)) {
			cout << "pass or user is incorrect" << endl;
			countwrong++;
			cout << "you entered wrong " << countwrong << " time(you have 3 time)" << endl;
			system("pause");
		}
		else {
			loginSuccessfull = true;
		}
	} while (!checkPass(temppass, count, user) && countwrong!=3);
	if (!loginSuccessfull) {
		return 1;
	}
	system("cls");
	cout << "login successfull" << endl;
	do {
		printInformation(count, user);
		cout << "1/Change name" << endl;
		cout << "2/Change date" << endl;
		cout << "3/Change hometown" << endl;
		cout << "4/Change major" << endl;
		cout << "5/Change pass" << endl;
		cout << "6/Log out" << endl;
		cin >> choose;
		switch (choose){
		case 1:
		{
			cout << "Enter your name..." << endl;
			cin.ignore();
			getline(cin, tempinformation);
			comfirmName(user, tempinformation, count);
			break;
		}
		case 2:
		{
			cout << "Enter your date..." << endl;
			cin>> tempinformation;
			comfirmDate(user, tempinformation, count);
			break;
		}
		case 3:
		{
			cout << "Enter your hometown..." << endl;
			cin.ignore();
			getline(cin, tempinformation);
			comfirmHometown(user, tempinformation, count);
			break;
		}
		case 4:
		{
			cout << "Enter your major..." << endl;
			cin.ignore();
			getline(cin, tempinformation);
			comfirmMajor(user, tempinformation, count);
			break;
		}
		case 5:
		{
			if (slidechangepass(tempinformation, count, user)) {
				comfirmPass(user, tempinformation, count);
			}
			break;
		}
		case 6:
		{
			cout << "log out succesfull" << endl;
			break;
		}
		default:
		{
			cout << "error choose !" << endl;
		}
		}
	} while (choose != 6);
	for (int i = 0; i < count; i++) {
		ghifile << ptr[i].tksv << "," << ptr[i].name << "," << ptr[i].date << "," << ptr[i].hometown << "," << ptr[i].major << "," << ptr[i].pass << endl;
	}
	ghifile.close();
	delete[] ptr;
	return 0;
}