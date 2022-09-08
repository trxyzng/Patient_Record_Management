
#include <iostream>
#include<cctype>
#include<string>
#include<stdlib.h>
#include <conio.h>
#include <ctime>
#include<fstream>
#include<sstream>
#define MAX 1000
#pragma warning(disable: 4996)
using namespace std;



void line(int n, char ch) {
	for (int i = 0; i < n; i++)
		cout << ch;
}

void title()
{
	cout << endl;
	line(211, '=');
	cout << "                                                                                        |  HOSPITAL PATIENT RECORD SYSTEM  |                                                                                       ";
	cout << "                                                                                        |     HOAC_CHI_TRUNG  19119057     |                                                                                       ";
	line(211, '=');
}

void function()
{
	cout << "\n\n\n  \t\t\t\t\t\t\t\t\t\t\t      1. Add a patient record\n";
	cout << "\n  \t\t\t\t\t\t\t\t\t\t\t      2. Delete a patient record\n";
	cout << "\n  \t\t\t\t\t\t\t\t\t\t\t      3. Edit a patient record\n";
	cout << "\n  \t\t\t\t\t\t\t\t\t\t\t      4. Search a patient record\n";
	cout << "\n  \t\t\t\t\t\t\t\t\t\t\t      5. Sort and print patient records\n";
	cout << "\n  \t\t\t\t\t\t\t\t\t\t\t      6. Print deleted patient records\n";
	cout << "\n  \t\t\t\t\t\t\t\t\t\t\t      7. Exit program\n";
}

void press()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t   Press any key to continue...\n";
	_getch();
	system("cls");
	return;
}

struct patient {
	int id;                              
	string last_name;
	string middle_name;
	string first_name;
	char gender;
	short int year;
	short int month;
	short int day;                                     
	short int age;                              
	unsigned long long int cmnd;
	string address;
	int phone_number;
	char blood;
	short int year_in;
	short int month_in;
	short int day_in;
	short int room;
	string problem[5];
	string doctor[2];
	short int year_out;
	short int month_out;
	short int day_out;
	unsigned int fee;
	patient* next;
};

class list {

	patient* head = NULL;
	patient* history = NULL;

public:
	//check if the list is empty
	bool isempty() //check if list if empty
	{
		return (head == NULL);
	};
	//check length of a number
	bool checkl(int num, int min, int max)           //check length of integer
	{
		string temp = to_string(num);
		int i = temp.length();
		return ((i > min) && (i < max));
	}
	//check length of a string 
	bool check_len(string str, int min, int max)    //check length of string in a given range
	{
		int i = str.length();
		return ((i >= min) && (i <= max));
	}
	//check if all characters of string is alphabet
	bool check_str(string str)                     //check if all elements of string is alphabet
	{
		int i = str.length();
		for (int h = 0; h < i; h++)
		{
			if (isalpha(tolower(str[h])) == 1)
				h++;
			if (isalpha(str[h]) == 0)
				return 0;
		}
		return 1;
	}
	//check if all elements of string is not digit 
	bool check_str_space(string str)                     
	{
		int i = str.length();
		for (int h = 0; h < i; h++)
		{
			if (isdigit(str[h]) == 0)
				h++;
			else
				return 0;
		}
		return 1;
	}
	//check if all character of string is digit
	bool check_int(string str)                   //check if all elements of string is integer
	{
		int i = str.length();
		for (int h = 0; h < i; h++)
		{
			if (isdigit(str[h]) == 0)
				return 0;
			h++;
		}
		return 1;
	}
	//check if the user want to repeat the current process
	bool next()
	{
	a:
		char a;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t        Repeat process [y/n]: ";
		cin >> a;
		if (tolower(a) == 'y')
		{
			return 1;
		}
		else if (tolower(a) == 'n')
		{
			return 0;
		}
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid choice\n";
			goto a;
		}
	}		
	//user choose which functions to execute 
	void menu() {
		char choice;
		title();
		stastic();
		function();
		cout << "\n\n\n  \t\t\t\t\t\t\t\t\t\t\t        Enter choice (1-7): ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case '1':
			cin.sync();
			add();
			break;
		case '2':
			del();
			menu();
			break;
		case '3':
			update();
			menu();
			break;
		case '4':
			dd:
			system("cls");
			title();
			stastic();
			cout << "  \n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        Search a patient record\n";
			d:
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        1. search by ID\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        2. search by CMND\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        3. search by room\n\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter choice: ";
			int b;
			cin >> b;
			if (b == 1)
			{
				search();
				if (next() == 1)
					goto dd;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			if (b == 2)
			{
				search_cmnd();
				if (next() == 1)
					goto dd;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			if (b == 3)
			{
				search_room();
				if (next() == 1)
					goto dd;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			else
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid choice. Try again\n";
				cout << "  \n\t\t\t\t\t\t\t\t\t\t\t        Search a patient record\n";
				goto d;
			}
			break;
		case '5':
		a:
			system("cls");
			title();
			stastic();
			cout << "  \n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        Sort and print patient records:\n";
			g:
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        1. from oldest to newest\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        2. base on ID (increase order)\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        3. base on age (increase order)\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        4. base on room (increase order)\n\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter choice: ";
			int c;
			cin >> c;
			if (c == 1)
			{
				system("cls");
				title();
				stastic();
				printf("\n\n\n\n\n\n\n\n\n");
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |    SORT AND PRINT    |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |  (Oldest -> Newest)  |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
				print_all(head);
				cout << endl;
				if (next() == 1)
					goto a;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			if (c == 2)
			{
				system("cls");
				title();
				stastic();
				printf("\n\n\n\n\n\n\n\n\n");
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |    SORT AND PRINT    |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |    (Increase ID)     |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
				sort_id();
				cout << endl;
				if (next() == 1)
					goto a;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			if (c == 3)
			{
				system("cls");
				title();
				stastic();
				printf("\n\n\n\n\n\n\n\n\n");
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |    SORT AND PRINT    |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |    (Increase Age)    |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
				sort_age();
				cout << endl;
				if (next() == 1)
					goto a;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			if (c == 4)
			{
				system("cls");
				title();
				stastic();
				printf("\n\n\n\n\n\n\n\n\n");
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |    SORT AND PRINT    |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |    (Increase Room)   |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
				sort_room();
				cout << endl;
				if (next() == 1)
					goto a;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			else
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid choice. Try again\n\n";
				cout << "  \n\t\t\t\t\t\t\t\t\t\t\t        Sort and print patient records\n";
				goto g;
			}
		case '6':
			k:
			system("cls");
			title();
			stastic();
			cout << "  \n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t        Print patients left hospital\n";
			e:
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        1. All history\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        2. This month\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        3. This year\n";
			cout << "  \n\t\t\t\t\t\t\t\t\t\t\t        Enter choice: ";
			int d;
			cin >> d;
			if (d == 1)
			{
				system("cls");
				title();
				stastic();
				printf("\n\n\n\n\n\n\n\n\n");
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |     PATIENT LEAVE    |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      |         (All)        |\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
				print_all(history);
				cout << endl;
				if (next() == 1)
					goto k;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			if (d == 2)
			{
				search_history_month();
				cout << endl;
				if (next() == 1)
					goto k;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			if (d == 3)
			{
				search_history_year();
				cout << endl;
				if (next() == 1)
					goto k;
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
				_getch();
				system("cls");
				menu();
			}
			else
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid choice. Try again\n\n";
				cout << "  \n\t\t\t\t\t\t\t\t\t\t\t        Print patient left hospital\n";
				goto e;
			}


			break;
		case '7':
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Exit the program and save data [y/n]: ";
			char i;
			cin >> i;
			if (tolower(i) == 'y')
			{
				write();
				write_history();
				cout << endl;
				line(98, '-');
				cout << "EXIT PROGRAM";
				line(101, '-');
				exit(0);
			}
			else
			{
				system("cls");
				menu();
			}
		default:
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid choice.\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press any key to choose again\n";
			_getch();
			system("cls");
			menu();
		}
	}	   
	//add a record
	void add()                         //add a record
	{
		string last_name;
		string middle_name;
		string first_name;
		string gender;
		string year;
		string month;
		string day;
		string cmnd;
		string address;
		string phone;
		string blood;
		string problem[5];
		string doctor[3];
		string room_str;
		string year_in;
		string month_in;
		string day_in;
		string year_out;
		string month_out;
		string day_out;
		short int numy = 0;
		short int numm = 0;
		short int numd = 0;
		short int age = 0;
		int num_phone = 0;
		short int room = 0;
		short int numdi = 0;
		short int nummi = 0;
		short int numyi = 0;
		short int numyo = 0;
		short int nummo = 0;
		short int numdo = 0;
		unsigned long long int num_cmnd = 0;
		unsigned int fee = 0;

		time_t current_time = time(0);
		tm* lc = gmtime(&current_time);
		int cur_year = lc->tm_year + 1900;
		int cur_month = lc->tm_mon + 1;
		int cur_day = lc->tm_mday;
		cin.sync();
	x:
		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		srand(time(NULL));
		int id = rand() % (999999 - 100000 + 1) + 100000;
		while (id > 0)
		{
			if (search_int(id) == 1)
				int id = rand() % (999999 - 100000 + 1) + 100000;
			else
				break;
		}
		cin.ignore(100, '\n');
	a:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      |  ADD PATIENT RECORD  |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
		qqq:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter last name: ";
		getline(cin, last_name);
		if (last_name.length() == 0) {
			last_name = " ";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
		}
		else
		{
			if (check_len(last_name, 2, 7) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between 2 and 7 characters\n";
				goto qqq;
			}
			if (check_str(last_name) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be alphabet character and no space\n";
				goto qqq;
			}
		}

	b:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter middle name: ";
		cin.sync();
		getline(cin, middle_name);
		if (middle_name.length() == 0) {
			middle_name = " ";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
		}
		else
		{
			if (check_len(middle_name, 2, 15) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between 2 and 15 characters\n";
				goto b;
			}
			if (check_str_space(middle_name) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be alphabet characters or space\n";
				goto b;
			}
		}

	c:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter first name: ";
		cin.sync();
		getline(cin, first_name);
		if (first_name.length() == 0) {
			first_name = " ";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
		}
		else
		{
			if (check_len(first_name, 2, 7) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between 2 and 7 characters\n";
				goto c;
			}
			if (check_str(first_name) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be alphabet character and no space\n";
				goto c;
			}
		}

	d:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter gender: ";
		cin.sync();
		getline(cin, gender);
		if (gender.length() == 0) {
			gender = ' ';
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			goto e;
		}
		if (gender.length() != 1)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be exactly 1 character m or f\n";
			goto d;
		}
		else
		{
			if (tolower(gender[0]) == 'm')
				goto e;
			if (tolower(gender[0]) == 'f')
				goto e;
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be m or f\n";
		goto d;

	e:
		int valid_y = 0;                         //check 0 = ko nhap, 1 = ko leap, 2 = leap
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter year of birth: ";
		cin.sync();
		getline(cin, year);
		if (year.length() == 0) {
			valid_y = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			year = '0';
			numy = 0;
			goto f;
		}
		if (year.length() != 4)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 4 digits\n";
			goto e;
		}
		else
		{

			numy = stoi(year);
			if (numy > cur_year)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid year. Must be less than or equal " << cur_year << endl;
				goto e;
			}
			if (numy > 1900)
			{
				if ((numy % 4 == 0) || (numy % 400 == 0))
				{
					valid_y = 2;
					goto f;
				}
				valid_y = 1;
				goto f;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number greater than 1900\n";
		goto e;

	f:
		int valid_m = 0;                //check 0 = ko nhap, 1 = 30, 2 = 28, 3 = 31
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter month of birth: ";
		cin.sync();
		getline(cin, month);
		if (month.length() == 0) {
			valid_m = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			month = '0';
			numm = 0;
			goto g;
		}
		if ((month.length() != 1) && (month.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto f;
		}
		else
		{
			numm = stoi(month);
			if ((numy == cur_year) && (numm > cur_month))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be less than or equal " << cur_month << endl;
				goto f;
			}
			if ((numm > 0) && (numm < 13))
			{
				int i[] = { 1, 3, 5, 7, 8, 10, 12 };
				for (int h = 0; h < 7; h++)
				{
					if (numm == i[h])
					{
						valid_m = 3;
						goto g;
					}
				}
				if (numm == 2)
				{
					valid_m = 2;
					goto g;
				}
				valid_m = 1;
				goto g;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 12\n";
		goto f;

	g:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter day of birth: ";
		cin.sync();
		getline(cin, day);
		if (day.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			day = '0';
			numd = 0;
			goto h;
		}
		if ((day.length() != 1) && (day.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto g;
		}
		else
		{
			numd = stoi(day);
			if ((numy == cur_year) && (numm == cur_month) && (numd > cur_day))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be less than or equal " << cur_day << endl;
				goto g;
			}
			if ((numd > 0) && (numd < 32))
			{
				if ((valid_y == 0) || (valid_y == 1))
				{
					if ((valid_m == 0))    //day from 0 -> 31
						goto h;
					if (valid_m == 1)
						if (numd > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto g;
						}
					if (valid_m == 2)          //day from 0 -> 28
						if (numd > 28)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 28\n";
							goto g;
						}
				}
				else						 //leap year
				{
					if ((valid_m == 0))    //day from 0 -> 31
						goto h;
					if (valid_m == 1)
						if (numd > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto g;
						}
					if (valid_m == 2)          //day from 0 -> 9
						if (numd > 29)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 29\n";
							goto g;
						}
				}
				goto h;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 31\n";
		goto g;

	h:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter cmnd: ";
		cin.sync();
		getline(cin, cmnd);
		if (cmnd.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			cmnd = "0";
			num_cmnd = 0;
			goto i;
		}
		else
		{
			if (cmnd.length() != 11)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be 11 digits\n";
				goto h;
			}
			if (check_int(cmnd) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be all digits\n";
				goto h;
			}
		}
		num_cmnd = stoull(cmnd);

	i:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter address: ";
		cin.sync();
		getline(cin, address);
		if (address.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			address = ' ';
			goto j;
		}
		if (address.length() > 40)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Maximum 40 characters\n";
			goto i;
		}

	j:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter phone_number: ";
		cin.sync();
		getline(cin, phone);
		if (phone.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			phone = '0';
			num_phone = 0;
			goto k;
		}
		if (phone.length() != 9)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be 9 digits\n";
			goto j;
		}
		if (check_int(phone) == 0)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be all digits\n";
			goto j;
		}
		if (phone[0] == '0')
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must not start with 0\n";
			goto j;
		}
		num_phone = stoi(phone);

	k:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter blood type: ";
		cin.sync();
		getline(cin, blood);
		if (blood.length() == 0) {
			blood = ' ';
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			goto l;
		}
		if (blood.length() != 1)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be exactly 1 character\n";
			goto k;
		}
		else
		{
			char a[] = { 'a', 'b', 'o' };
			for (int i = 0; i < 3; i++)
			{
				if (tolower(blood[0]) == a[i])
					goto l;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a blood type (A, B, O)\n";
		goto k;

	l:
		int valid_yi = 0;         //check 0 = ko nhap, 1 = ko leap, 2 = leap
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter year go to hospital: ";
		cin.sync();
		getline(cin, year_in);
		if (year_in.length() == 0) {
			valid_yi = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			year_in = '0';
			numyi = 0;
			goto m;
		}
		if (year_in.length() != 4)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 4 digits\n";
			goto l;
		}
		else
		{
			numyi = stoi(year_in);
			if (numyi > cur_year)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid year. Must be less than or equal to " << cur_year << endl;
				goto l;
			}

			if (numyi >= 2000)
			{
				if ((numyi % 4 == 0) || (numyi % 400 == 0))
				{
					valid_yi = 2;
					goto m;
				}
				valid_yi = 1;
				goto m;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 2000\n";
		goto l;

	m:
		int valid_mi = 0;                //check 0 = ko nhap, 1 = 30, 2 = 28, 3 = 31
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter month go to hospital: ";
		cin.sync();
		getline(cin, month_in);
		if (month_in.length() == 0) {
			valid_mi = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			month_in = '0';
			nummi = 0;
			goto n;
		}
		if ((month_in.length() != 1) && (month_in.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto m;
		}
		else
		{
			nummi = stoi(month_in);
			if ((nummi > cur_month) && (numyi == cur_year))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid month. Must be equal or less than " << cur_month << endl;
				goto m;
			}
			if ((nummi > 0) && (nummi < 13))
			{
				int i[] = { 1, 3, 5, 7, 8, 10, 12 };
				for (int h = 0; h < 7; h++)
				{
					if (nummi == i[h])
					{
						valid_mi = 3;
						goto n;
					}
				}
				if (nummi == 2)
				{
					valid_mi = 2;
					goto n;
				}
				valid_mi = 1;
				goto n;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 12\n";
		goto m;

	n:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter day go to hospital: ";
		cin.sync();
		getline(cin, day_in);
		if (day_in.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			day_in = '0';
			numdi = 0;
			goto o;
		}
		if ((day_in.length() != 1) && (day_in.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto n;
		}
		else
		{
			numdi = stoi(day_in);
			if ((nummi == cur_month) && (numyi == cur_year) && (numdi > cur_day))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid day. Must be equal or less than " << cur_day << endl;
				goto n;
			}
			if ((numdi > 0) && (numdi < 32))
			{
				if ((valid_yi == 0) || (valid_yi == 1))
				{
					if ((valid_mi == 0))    //day from 0 -> 31
						goto o;
					if (valid_mi == 1)
						if (numdi > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto n;
						}
					if (valid_mi == 2)          //day from 0 -> 28
						if (numdi > 28)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 28\n";
							goto n;
						}
				}
				else						 //leap year
				{
					if ((valid_mi == 0))    //day from 0 -> 31
						goto o;
					if (valid_mi == 1)
						if (numdi > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto n;
						}
					if (valid_mi == 2)          //day from 0 -> 9
						if (numdi > 29)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 29\n";
							goto n;
						}
				}
				goto o;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 31\n";
		goto n;

	o:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter room: ";
		cin.sync();
		getline(cin, room_str);
		if (room_str.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			room_str = '0';
			room = 0;
			goto p;
		}
		if (room_str.length() != 3)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be 3 digits\n";
			goto o;
		}
		if (check_int(room_str) == 0)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be all digits\n";
			goto o;
		}
		room = stoi(room_str);
		if (((room > 100) && (room < 200)) || ((room > 200) && (room < 300))
			|| ((room > 300) && (room < 400)) || ((room > 400) && (room < 500))
			|| ((room > 500) && (room < 600)))
			goto p;
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between floor 1-5, room 01-99\n";
			goto o;
		}

	p:
		int problem_count = 0;
	q:
		while (problem_count < 5)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter problem " << problem_count + 1 << ": ";
			cin.sync();
			string problem_str;
			getline(cin, problem_str);
			if (problem_str.length() == 0) {
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
				problem[problem_count] = ' ';
				problem_count++;
				goto q;
			}
			if (problem_str.length() > 21)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Maximum 21 characters\n";
				goto q;
			}
			problem[problem_count] = problem_str;
			problem_count++;
		}

		int doctor_count = 0;
	r:
		while (doctor_count < 2)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter doctor in charge " << doctor_count + 1 << ": ";
			cin.sync();
			string doctor_str;
			getline(cin, doctor_str);
			if (doctor_str.length() == 0) {
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
				doctor[doctor_count] = ' ';
				doctor_count++;
				goto r;
			}
			if (doctor_str.length() > 11)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Maximum 11 characters\n";
				goto r;
			}
			for (int i = 0; i < 3; i++)
			{
				if (isdigit(doctor_str[i]) == 0)
				{
					cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must start with 3 number, follow by space and first name\n";
					goto r;
				}
			}
			if (isspace(doctor_str[3]) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must start with 3 digits, follow by space and first name\n";
				goto r;
			}
			doctor[doctor_count] = doctor_str;
			doctor_count++;
		}

	ll:
		int valid_yo = 0;         //check 0 = ko nhap, 1 = ko leap, 2 = leap
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter year leave hospital: ";
		cin.sync();
		getline(cin, year_out);
		if (year_out.length() == 0) {
			valid_yo = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			year_out = '0';
			numyo = 0;
			goto mm;
		}
		if (year_out.length() != 4)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 4 digits\n";
			goto ll;
		}
		else
		{
			numyo = stoi(year_out);
			if (numyo < numyi)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be greater than " << numyi << endl;
				goto ll;
			}
			else
			{
				if ((numyo % 4 == 0) || (numyo % 400 == 0))
				{
					valid_yo = 2;
						goto mm;
				}
				valid_yo = 1;
					goto mm;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from " << numyi << " to " << cur_year << endl;
		goto ll;

	mm:
		int valid_mo = 0;                //check 0 = ko nhap, 1 = 30, 2 = 28, 3 = 31
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter month leave hospital: ";
		cin.sync();
		getline(cin, month_out);
		if (month_out.length() == 0) {
			valid_mo = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			month_out = '0';
			nummo = 0;
			goto nn;
		}
		if ((month_out.length() != 1) && (month_out.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto mm;
		}
		else
		{
			nummo = stoi(month_out);
			if ((numyo == numyi) && (nummo < nummi))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be greater or equal to " << nummi << endl;
				goto mm;
			}
			if ((nummo > 0) && (nummo < 13))
			{
				int i[] = { 1, 3, 5, 7, 8, 10, 12 };
				for (int h = 0; h < 7; h++)
				{
					if (nummo == i[h])
					{
						valid_mo = 3;
						goto nn;
					}
				}
				if (nummo == 2)
				{
					valid_mo = 2;
					goto nn;
				}
				valid_mo = 1;
				goto nn;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 12\n";
		goto mm;

	nn:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter day leave hospital: ";
		cin.sync();
		getline(cin, day_out);
		if (day_out.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Leave blank\n";
			day_out = '0';
			numdo = 0;
			goto oo;
		}
		if ((day_out.length() != 1) && (day_out.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto nn;
		}
		else
		{
			numdo = stoi(day_out);
			if ((numyo == numyi) && (nummo == nummi) && (numdo < numdi))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from " << numdi << " to 31" << endl;
				goto nn;
			}
			if ((numdo > 0) && (numdo < 32))
			{
				if ((valid_yo == 0) || (valid_yo == 1))
				{
					if ((valid_mo == 0))        //day from 0 -> 31
						goto oo;
					if (valid_mo == 1)
						if (numdo > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto nn;
						}
					if (valid_mo == 2)          //day from 0 -> 28
						if (numdo > 28)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 28\n";
							goto nn;
						}
				}
				else						 //leap year
				{
					if ((valid_mo == 0))    //day from 0 -> 31
						goto oo;
					if (valid_mo == 1)
						if (numdo > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto nn;
						}
					if (valid_mo == 2)          //day from 0 -> 9
						if (numdo > 29)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 29\n";
							goto nn;
						}
				}
				goto oo;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 31\n";
		goto nn;
	
	oo:

		patient* newp = new patient();
		if (head == NULL)					  //if list is empty, insert first element to list
		{
			newp->next = NULL;
			head = newp;
		}
		else {								  //insert at end of list
			patient* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newp;
			newp->next = NULL;
		}

		newp->id = id;
		newp->last_name = last_name;
		newp->middle_name = middle_name;
		newp->first_name = first_name;
		newp->gender = toupper(gender[0]);
		newp->year = numy;
		newp->month = numm;
		newp->day = numd;
		newp->address = address;
		newp->phone_number = num_phone;
		newp->blood = toupper(blood[0]);
		newp->cmnd = num_cmnd;
		newp->year_in = numyi;
		newp->month_in = nummi;
		newp->day_in = numdi;
		newp->room = room;
		newp->year_out = numyo;
		newp->month_out = nummo;
		newp->day_out = numdo;
		for (int i = 0; i < 5; i++)
		{
			newp->problem[i] = problem[i];
		}
		for (int i = 0; i < 2; i++)
		{
			newp->doctor[i] = doctor[i];
		}

		//calculate age 

		if (numy == 0)
			age = 0;
		else
			age = (cur_year) - numy;
		if (age < 0)
			age = 0;
		newp->age = age;

		//calculate fee
		int value = 0;
		if ((room > 100) && (room < 200))
			value = 100000;
		if ((room > 200) && (room < 300))
			value = 200000;
		if ((room > 300) && (room < 400))
			value = 300000;
		if ((room > 400) && (room < 500))
			value = 400000;
		if ((room > 500) && (room < 600))
			value = 500000;
		if (room == 0)
			value = 0;

		if ((numdi == 0) || (nummi == 0) || (numyi == 0) || (room == 0))
		{
			fee = 0;
			goto vv;
		}
		else
		{
			tm in {0};
			in.tm_year = numyi - 1900;
			in.tm_mon = nummi - 1;
			in.tm_mday = numdi;
			time_t ein = mktime(&in);

			tm out {0};
			if ((numyo != 0) && (nummo != 0) && (numdo != 0))    //if day out != 0
			{
				out.tm_year = numyo - 1900;
				out.tm_mon = nummo - 1;
				out.tm_mday = numdo;
			}
			else                                       //if day out = 0
			{
				out.tm_year = cur_year - 1900;
				out.tm_mon = cur_month - 1;
				out.tm_mday = cur_day;
			}
			time_t eout = mktime(&out);
			time_t dif = eout - ein;
			fee = value * (dif / 86400 + 1);
		}
	vv:
		newp->fee = fee;

		line(211, '=');
		cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
		line(211, '=');
		print(newp);
		cout << "\n  \t\t\t\t\t\t\t\t\t\t\t        Add successfully.\n";

		if (next() == 1)
		{
			goto x;
		}
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
			_getch();
			system("cls");
			menu();
		}
	};
	//delete a record
	void del()                                //delete a record
	{
	a:
		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      |  DELETE RECORD BY ID |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
		if (isempty())                       //if list empty
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Empty database\n";
			return;
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter ID: ";
		int id;
		cin >> id;
		patient* temp = search(id);
		if (temp == NULL)                     //if no node has that id
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        No ID in database\n";
			free(temp);
			goto b;
		}
		line(211, '=');
		cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
		line(211, '=');
		print(temp);
		cin.ignore(100, '\n');
		cout << "  \n\t\t\t\t\t\t\t\t\t\t\t        Delete this ID [y/n]: ";
		char t;
		t = getchar();
		if (tolower(t) == 'y')
			goto c;
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Not delete";
			goto b;
		}

		c:
		if (temp == head)                             //if node has that id is first node
		{
			patient* newp = new patient();
			if (history == NULL)					  //insert first element to list
			{
				newp->next = NULL;
				history = newp;
			}
			else {								      //insert at end of list history
				patient* t = history;
				while (t->next != NULL)
					t = t->next;
				t->next = newp;
				newp->next = NULL;
			}
			newp->id = temp->id;
			newp->last_name = temp->last_name;
			newp->middle_name = temp->middle_name;
			newp->first_name = temp->first_name;
			newp->gender = temp->gender;
			newp->year = temp->year;
			newp->month = temp->month;
			newp->day = temp->day;
			newp->age = temp->age;
			newp->address = temp->address;
			newp->phone_number = temp->phone_number;
			newp->blood = temp->blood;
			newp->cmnd = temp->cmnd;
			newp->year_in = temp->year_in;
			newp->month_in = temp->month_in;
			newp->day_in = temp->day_in;
			newp->room = temp->room;
			newp->year_out = temp->year_out;
			newp->month_out = temp->month_out;
			newp->day_out = temp->day_out;
			for (int i = 0; i < 5; i++)
			{
				newp->problem[i] = temp->problem[i];
			}
			for (int i = 0; i < 2; i++)
			{
				newp->doctor[i] = temp->doctor[i];
			}
			newp->fee = temp->fee;

			head = head->next;
			free(temp);
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Delete successful\n";
			goto b;
		}
		else
		{
			patient* above = head;
			while (above != NULL)                //if node with that id is at middle or end node
			{
				if (above->next == temp)
				{
					patient* newp = new patient();
					if (history == NULL)					  //insert first element to list
					{
						newp->next = NULL;
						history = newp;
					}
					else {								  //insert at end of list history
						patient* t = history;
						while (t->next != NULL)
							t = t->next;
						t->next = newp;
						newp->next = NULL;
					}
					newp->id = temp->id;
					newp->last_name = temp->last_name;
					newp->middle_name = temp->middle_name;
					newp->first_name = temp->first_name;
					newp->gender = temp->gender;
					newp->year = temp->year;
					newp->month = temp->month;
					newp->day = temp->day;
					newp->age = temp->age;
					newp->address = temp->address;
					newp->phone_number = temp->phone_number;
					newp->blood = temp->blood;
					newp->cmnd = temp->cmnd;
					newp->year_in = temp->year_in;
					newp->month_in = temp->month_in;
					newp->day_in = temp->day_in;
					newp->room = temp->room;
					newp->year_out = temp->year_out;
					newp->month_out = temp->month_out;
					newp->day_out = temp->day_out;
					for (int i = 0; i < 5; i++)
					{
						newp->problem[i] = temp->problem[i];
					}
					for (int i = 0; i < 2; i++)
					{
						newp->doctor[i] = temp->doctor[i];
					}
					newp->fee = temp->fee;

					above->next = temp->next;
					free(temp);
					cout << "  \t\t\t\t\t\t\t\t\t\t\t        Delete successful\n";
					goto b;
				}
				above = above->next;
			}
		}
		b:
		if (next() == 1)
			goto a;
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
			_getch();
			system("cls");
			menu();
		}
	};
	//update a record
	void update() //update a record
	{

	x:
		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      | UPDATE RECORD BY ID  |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter ID: ";
		int idi;
		cin >> idi;
		patient* newp = search(idi);
		if (newp == NULL)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        No ID in database\n";
			if (next() == 1)
				goto x;
			else
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press any button to continue\n";
				_getch();
				system("cls");
				menu();
			}
		}
		line(211, '=');
		cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
		line(211, '=');
		print(newp);
		cout << "  \n\n\t\t\t\t\t\t\t\t\t\t\t        Enter replacement...\n";
		cin.ignore();
		string id;
		string last_name;
		string middle_name;
		string first_name;
		string gender;
		string year;
		string month;
		string day;
		string cmnd;
		string address;
		string phone;
		string blood;
		string problem[5];
		string doctor[3];
		string room_str;
		string year_in;
		string month_in;
		string day_in;
		string year_out;
		string month_out;
		string day_out;
		int num_id = 0;
		short int numy = 0;
		short int numm = 0;
		short int numd = 0;
		short int age = 0;
		int num_phone = 0;
		short int room = 0;
		short int numdi = 0;
		short int nummi = 0;
		short int numyi = 0;
		unsigned long long int num_cmnd = 0;
		short int numyo = 0;
		short int nummo = 0;
		short int numdo = 0;
		unsigned int fee = 0;
		time_t current_time = time(0);
		tm* lc = gmtime(&current_time);

		int cur_year = lc->tm_year + 1900;
		int cur_month = lc->tm_mon + 1;
		int cur_day = lc->tm_mday;

	w:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new id: ";
		cin.sync();
		getline(cin, id);
		if (id.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			id = '0';
			num_id = newp->id;
			goto a;
		}
		else
		{
			if (id.length() != 6)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be 6 digits\n";
				goto w;
			}
			if (check_int(id) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be all digits\n";
				goto w;
			}
			if (id[0] == '0')
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must not start with 0\n";
				goto w;
			}
			num_id = stoi(id);

			patient* count = head;
			while (count != NULL)
			{
				if (num_id != count->id)
				{
					count = count->next;
				}
				else
				{
					cout << "  \t\t\t\t\t\t\t\t\t\t\t        ID already exist. Try different number. Ex " << num_id + 1 << endl;
					goto w;
				}
			}
		}

	a:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new last name: ";
		getline(cin, last_name);
		if (last_name.length() == 0) {
			last_name = newp->last_name;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
		}
		else
		{
			if (check_len(last_name, 2, 7) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between 2 and 7 characters\n";
				goto a;
			}
			if (check_str(last_name) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be alphabet character and no space\n";
				goto a;
			}
		}

	b:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new middle name: ";
		cin.sync();
		getline(cin, middle_name);
		if (middle_name.length() == 0) {
			middle_name = newp->middle_name;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
		}
		else
		{
			if (check_len(middle_name, 2, 15) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between 2 and 15 characters\n";
				goto b;
			}
			if (check_str_space(middle_name) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be alphabet characters or space\n";
				goto b;
			}
		}

	c:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new first name: ";
		cin.sync();
		getline(cin, first_name);
		if (first_name.length() == 0) {
			first_name = newp->first_name;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
		}
		else
		{
			if (check_len(first_name, 2, 7) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between 2 and 7 characters\n";
				goto c;
			}
			if (check_str(first_name) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be alphabet character and no space\n";
				goto c;
			}
		}

	d:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new gender: ";
		cin.sync();
		getline(cin, gender);
		if (gender.length() == 0) {
			gender = newp->gender;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			goto e;
		}
		if (gender.length() != 1)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be exactly 1 character m or f\n";
			goto d;
		}
		else
		{
			if (tolower(gender[0]) == 'm')
				goto e;
			if (tolower(gender[0]) == 'f')
				goto e;
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be m or f\n";
		goto d;

	e:
		int valid_y = 0;         //check 0 = ko nhap, 1 = ko leap, 2 = leap
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new year of birth: ";
		cin.sync();
		getline(cin, year);
		if (year.length() == 0) {
			valid_y = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			numy = newp->year;
			goto f;
		}
		if (year.length() != 4)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 4 digits\n";
			goto e;
		}
		else
		{

			numy = stoi(year);
			if (numy > cur_year)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid year. Must be less than or equal " << cur_year << endl;
				goto e;
			}
			if (numy > 1900)
			{
				if ((numy % 4 == 0) || (numy % 400 == 0))
				{
					valid_y = 2;
					goto f;
				}
				valid_y = 1;
				goto f;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number greater than 1900\n";
		goto e;

	f:
		int valid_m = 0;                //check 0 = ko nhap, 1 = 30, 2 = 28, 3 = 31
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new month of birth: ";
		cin.sync();
		getline(cin, month);
		if (month.length() == 0) {
			valid_m = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			numm = newp->month;
			goto g;
		}
		if ((month.length() != 1) && (month.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto f;
		}
		else
		{
			numm = stoi(month);
			if ((numy == cur_year) && (numm > cur_month))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be less than or equal " << cur_month << endl;
				goto f;
			}
			if ((numm > 0) && (numm < 13))
			{
				int i[] = { 1, 3, 5, 7, 8, 10, 12 };
				for (int h = 0; h < 7; h++)
				{
					if (numm == i[h])
					{
						valid_m = 3;
						goto g;
					}
				}
				if (numm == 2)
				{
					valid_m = 2;
					goto g;
				}
				valid_m = 1;
				goto g;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 12\n";
		goto f;

	g:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter day of birth: ";
		cin.sync();
		getline(cin, day);
		if (day.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			numd = newp->day;
			goto h;
		}
		if ((day.length() != 1) && (day.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto g;
		}
		else
		{
			numd = stoi(day);
			if ((numy == cur_year) && (numm == cur_month) && (numd > cur_day))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be less than or equal " << cur_day << endl;
				goto g;
			}
			if ((numd > 0) && (numd < 32))
			{
				if ((valid_y == 0) || (valid_y == 1))
				{
					if ((valid_m == 0))    //day from 0 -> 31
						goto h;
					if (valid_m == 1)
						if (numd > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto g;
						}
					if (valid_m == 2)          //day from 0 -> 28
						if (numd > 28)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 28\n";
							goto g;
						}
				}
				else						 //leap year
				{
					if ((valid_m == 0))    //day from 0 -> 31
						goto h;
					if (valid_m == 1)
						if (numd > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto g;
						}
					if (valid_m == 2)          //day from 0 -> 9
						if (numd > 29)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 29\n";
							goto g;
						}
				}
				goto h;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 31\n";
		goto g;

	h:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new cmnd: ";
		cin.sync();
		getline(cin, cmnd);
		if (cmnd.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			//cmnd = newp->cmnd;
			num_cmnd = newp->cmnd;
			goto i;
		}
		else
		{
			if (cmnd.length() != 11)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be 11 digits\n";
				goto h;
			}
			if (check_int(cmnd) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be all digits\n";
				goto h;
			}
		}
		num_cmnd = stoull(cmnd);

	i:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new address: ";
		cin.sync();
		getline(cin, address);
		if (address.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			address = newp->address;
			goto j;
		}
		if (address.length() > 40)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Maximum 40 characters\n";
			goto i;
		}

	j:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new phone number: ";
		cin.sync();
		getline(cin, phone);
		if (phone.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			//phone = newp->phone_number;
			num_phone = newp->phone_number;
			goto k;
		}
		if (phone.length() != 9)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be 9 digits\n";
			goto j;
		}
		if (check_int(phone) == 0)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be all digits\n";
			goto j;
		}
		if (phone[0] == '0')
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must not start with 0\n";
			goto j;
		}
		num_phone = stoi(phone);

	k:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter blood type: ";
		cin.sync();
		getline(cin, blood);
		if (blood.length() == 0) {
			blood = newp->blood;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			goto l;
		}
		if (blood.length() != 1)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be exactly 1 character\n";
			goto k;
		}
		else
		{
			char a[] = { 'a', 'b', 'o' };
			for (int i = 0; i < 3; i++)
			{
				if (tolower(blood[0]) == a[i])
					goto l;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a blood type (A, B, O)\n";
		goto k;

	l:
		int valid_yi = 0;         //check 0 = ko nhap, 1 = ko leap, 2 = leap
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new year go to hospital: ";
		cin.sync();
		getline(cin, year_in);
		if (year_in.length() == 0) {
			valid_yi = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			numyi = newp->year_in;
			goto m;
		}
		if (year_in.length() != 4)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 4 digits\n";
			goto l;
		}
		else
		{
			numyi = stoi(year_in);
			if (numyi > cur_year)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Invalid year Try again.\n";
				goto l;
			}
			if (numyi >= 2000)
			{
				if ((numyi % 4 == 0) || (numyi % 400 == 0))
				{
					valid_yi = 2;
					goto m;
				}
				valid_yi = 1;
				goto m;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 2000\n";
		goto l;

	m:
		int valid_mi = 0;                //check 0 = ko nhap, 1 = 30, 2 = 28, 3 = 31
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new month go to hospital: ";
		cin.sync();
		getline(cin, month_in);
		if (month_in.length() == 0) {
			valid_mi = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			nummi = newp->month_in;
			goto n;
		}
		if ((month_in.length() != 1) && (month_in.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto m;
		}
		else
		{
			nummi = stoi(month_in);
			if ((nummi > 0) && (nummi < 13))
			{
				int i[] = { 1, 3, 5, 7, 8, 10, 12 };
				for (int h = 0; h < 7; h++)
				{
					if (nummi == i[h])
					{
						valid_mi = 3;
						goto n;
					}
				}
				if (nummi == 2)
				{
					valid_mi = 2;
					goto n;
				}
				valid_mi = 1;
				goto n;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 12\n";
		goto m;

	n:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new day go to hospital: ";
		cin.sync();
		getline(cin, day_in);
		if (day_in.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			numdi = newp->day_in;
			goto o;
		}
		if ((day_in.length() != 1) && (day_in.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto n;
		}
		else
		{
			numdi = stoi(day_in);
			if ((numdi > 0) && (numdi < 32))
			{
				if ((valid_yi == 0) || (valid_yi == 1))
				{
					if ((valid_mi == 0))    //day from 0 -> 31
						goto o;
					if (valid_mi == 1)
						if (numdi > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto n;
						}
					if (valid_mi == 2)          //day from 0 -> 28
						if (numdi > 28)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 28\n";
							goto n;
						}
				}
				else						 //leap year
				{
					if ((valid_mi == 0))    //day from 0 -> 31
						goto o;
					if (valid_mi == 1)
						if (numdi > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto n;
						}
					if (valid_mi == 2)          //day from 0 -> 9
						if (numdi > 29)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 29\n";
							goto n;
						}
				}
				goto o;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 31\n";
		goto n;

	o:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new room: ";
		cin.sync();
		getline(cin, room_str);
		if (room_str.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			//room_str = '0';
			room = newp->room;
			goto p;
		}
		if (room_str.length() != 3)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be 3 digits\n";
			goto o;
		}
		if (check_int(room_str) == 0)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be all digits\n";
			goto o;
		}
		room = stoi(room_str);
		if (((room > 100) && (room < 200)) || ((room > 200) && (room < 300))
			|| ((room > 300) && (room < 400)) || ((room > 400) && (room < 500))
			|| ((room > 500) && (room < 600)))
			goto p;
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be between floor 1-5, room 01-99\n";
			goto o;
		}

	p:
		int problem_count = 0;
	q:
		while (problem_count < 5)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter problem " << problem_count + 1 << ": ";
			cin.sync();
			string problem_str;
			getline(cin, problem_str);
			if (problem_str.length() == 0) {
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
				problem[problem_count] = newp->problem[problem_count];
				problem_count++;
				goto q;
			}
			if (problem_str.length() > 21)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Maximum 21 characters\n";
				goto q;
			}
			problem[problem_count] = problem_str;
			problem_count++;
		}

		int doctor_count = 0;
	r:
		while (doctor_count < 2)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter doctor in charge " << doctor_count + 1 << ": ";
			cin.sync();
			string doctor_str;
			getline(cin, doctor_str);
			if (doctor_str.length() == 0) {
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
				doctor[doctor_count] = newp->doctor[doctor_count];
				doctor_count++;
				goto r;
			}
			if (doctor_str.length() > 11)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Maximum 11 characters\n";
				goto r;
			}
			for (int i = 0; i < 3; i++)
			{
				if (isdigit(doctor_str[i]) == 0)
				{
					cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must start with 3 number, follow by space and first name\n";
					goto r;
				}
			}
			if (isspace(doctor_str[3]) == 0)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must start with 3 digits, follow by space and first name\n";
				goto r;
			}
			doctor[doctor_count] = doctor_str;
			doctor_count++;
		}

	ll:
		int valid_yo = 0;         //check 0 = ko nhap, 1 = ko leap, 2 = leap
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new year leave hospital: ";
		cin.sync();
		getline(cin, year_out);
		if (year_out.length() == 0) {
			valid_yo = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			numyo = newp->year_out;
			goto mm;
		}
		if (year_out.length() != 4)
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 4 digits\n";
			goto ll;
		}
		else
		{
			numyo = stoi(year_out);
			if (numyo < numyi)
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be greater than " << numyi << endl;
				goto ll;
			}
			if (numyo >= numyi)
			{
				if ((numyo % 4 == 0) || (numyo % 400 == 0))
				{
					valid_yo = 2;
					goto mm;
				}
				valid_yo = 1;
				goto mm;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from " << numyi << endl;
		goto ll;

	mm:
		int valid_mo = 0;                //check 0 = ko nhap, 1 = 30, 2 = 28, 3 = 31
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new month leave hospital: ";
		cin.sync();
		getline(cin, month_out);
		if (month_out.length() == 0) {
			valid_mo = 0;
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			nummo = newp->month_out;
			goto nn;
		}
		if ((month_out.length() != 1) && (month_out.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto mm;
		}
		else
		{
			nummo = stoi(month_out);
			if ((numyo == numyi) && (nummo < nummi))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be greater or equal " << nummi << endl;
				goto mm;
			}
			if ((nummo > 0) && (nummo < 13))
			{
				int i[] = { 1, 3, 5, 7, 8, 10, 12 };
				for (int h = 0; h < 7; h++)
				{
					if (nummo == i[h])
					{
						valid_mo = 3;
						goto nn;
					}
				}
				if (nummo == 2)
				{
					valid_mo = 2;
					goto nn;
				}
				valid_mo = 1;
				goto nn;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 12\n";
		goto mm;

	nn:
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter new day leave hospital: ";
		cin.sync();
		getline(cin, day_out);
		if (day_out.length() == 0) {
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Unchange\n";
			numdo = newp->day_out;
			goto oo;
		}
		if ((day_out.length() != 1) && (day_out.length() != 2))
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number with 1 or 2 digits\n";
			goto nn;
		}
		else
		{
			numdo = stoi(day_out);
			if ((numyo == numyi) && (nummo == nummi) && (numdo < numdi))
			{
				cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from " << numdi << " to 31" << endl;
				goto nn;
			}
			if ((numdo > 0) && (numdo < 32))
			{
				if ((valid_yo == 0) || (valid_yo == 1))
				{
					if ((valid_mo == 0))        //day from 0 -> 31
						goto oo;
					if (valid_mo == 1)
						if (numdo > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto nn;
						}
					if (valid_mo == 2)          //day from 0 -> 28
						if (numdo > 28)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 28\n";
							goto nn;
						}
				}
				else						 //leap year
				{
					if ((valid_mo == 0))    //day from 0 -> 31
						goto oo;
					if (valid_mo == 1)
						if (numdo > 30)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 30\n";
							goto nn;
						}
					if (valid_mo == 2)          //day from 0 -> 9
						if (numdo > 29)
						{
							cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be from 1 to 29\n";
							goto nn;
						}
				}
				goto oo;
			}
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Must be a number from 1 to 31\n";
		goto nn;

	oo:
		
		newp->id = num_id;
		newp->last_name = last_name;
		newp->middle_name = middle_name;
		newp->first_name = first_name;
		newp->gender = toupper(gender[0]);
		newp->year = numy;
		newp->month = numm;
		newp->day = numd;
		newp->address = address;
		newp->phone_number = num_phone;
		newp->blood = toupper(blood[0]);
		newp->cmnd = num_cmnd;
		newp->year_in = numyi;
		newp->month_in = nummi;
		newp->day_in = numdi;
		newp->room = room;
		newp->year_out = numyo;
		newp->month_out = nummo;
		newp->day_out = numdo;

		for (int i = 0; i < 5; i++)
		{
			newp->problem[i] = problem[i];
		}
		for (int i = 0; i < 2; i++)
		{
			newp->doctor[i] = doctor[i];
		}

		//calculate age automatically

		if (numy == 0)
			age = 0;
		else
			age = (cur_year)-numy;
		if (age < 0)
			age = 0;
		newp->age = age;

		//calculate fee
		int value = 0;
		if ((room > 100) && (room < 200))
			value = 100000;
		if ((room > 200) && (room < 300))
			value = 200000;
		if ((room > 300) && (room < 400))
			value = 300000;
		if ((room > 400) && (room < 500))
			value = 400000;
		if ((room > 500) && (room < 600))
			value = 500000;

		if ((numdi == 0) || (nummi == 0) || (numyi == 0) || (room == 0))
		{
			fee = 0;
			goto vv;
		}
		else
		{
			tm in{ 0 };
			in.tm_year = numyi - 1900;
			in.tm_mon = nummi - 1;
			in.tm_mday = numdi;
			time_t ein = mktime(&in);

			tm out{ 0 };
			if ((numyo != 0) && (nummo != 0) && (numdo != 0))    //if day out != 0
			{
				out.tm_year = numyo - 1900;
				out.tm_mon = nummo - 1;
				out.tm_mday = numdo;
			}
			else                                       //if day out = 0
			{
				out.tm_year = cur_year - 1900;
				out.tm_mon = cur_month - 1;
				out.tm_mday = cur_day;
			}
			time_t eout = mktime(&out);
			time_t dif = eout - ein;
			fee = value * (dif / 86400 + 1);
		}

	vv:
		newp->fee = fee;
		line(211, '=');
		cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
		line(211, '=');
		print(newp);
		cout << "\n  \t\t\t\t\t\t\t\t\t\t\t        Update successfully\n";

		if (next() == 1)                   //repeat ?
		{
			goto x;
		}
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Return to main menu\n";
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Press to continue\n";
			_getch();
			system("cls");
			menu();
		}
	};
	//search record using ID
	void search()              //search a record
	{
	a:
		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      |  SEARCH RECORD (ID)  |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter ID: ";
		int id;
		cin >> id;
		patient* temp = head;
		patient* search_ptr = NULL;
		int no = 1;
		while (temp != NULL)
		{
			if (temp->id == id)
			{
				search_ptr = temp;
				line(211, '=');
				cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
				line(211, '=');
				print(search_ptr);
				cout << "\n";
				return;
			}
			temp = temp->next;
			no++;
		}
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        No ID in database\n";
		}
	//search record using room
	void search_room()              //search a record
	{
	a:
		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      | SEARCH RECORD (ROOM) |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter room: ";
		int room;
		cin >> room;
		patient* temp = head;
		patient* search_ptr = NULL;
		patient* temp1 = head;
		int no = 1;
		int count = 0;
		while (temp1 != NULL)
		{
			if (temp1->room == room)
			{
				count++;
			}
			temp1 = temp1->next;
		}
		if (count > 0)
		{
			line(211, '=');
			cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
			line(211, '=');
		}
		while (temp != NULL)
		{
			if (temp->room == room)
			{
				search_ptr = temp;
				print(search_ptr);
				//cout << "\n";
			}
			temp = temp->next;
			no++;
		}
		if (count == 0)
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        No patient with this room in database\n";
		return;
	};
	//search record using cmnd
	void search_cmnd()              //search a record
	{
	a:
		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      | SEARCH RECORD (CMND) |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Enter CMND: ";
		unsigned long long int cmnd;
		cin >> cmnd;
		patient* temp = head;
		patient* search_ptr = NULL;
		patient* temp1 = head;
		int no = 1;
		int count = 0;
		while (temp1 != NULL)
		{
			if (temp1->cmnd == cmnd)
			{
				count++;
			}
			temp1 = temp1->next;
		}
		if (count > 0)
		{
			line(211, '=');
			cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
			line(211, '=');
		}
		while (temp != NULL)
		{
			if (temp->cmnd == cmnd)
			{
				search_ptr = temp;
				print(search_ptr);
			}
			temp = temp->next;
			no++;
		}
		if (count == 0)
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        No patient with this CMND in database\n";
		cout << "\n";
	};
	//search a record for deletion
	patient* search(int id)        //search a record for delete
	{
		patient* temp = head;
		while (temp != NULL)
		{
			if (temp->id == id)
			{
				return temp;
			}
			else
				temp = temp->next;
		}
		return temp;
	};
	//check if a record already has this ID
	bool search_int(int id)        
	{
		patient* temp = head;
		while (temp != NULL)
		{
			if (temp->id == id)
			{
				return 1;
			}
			temp = temp->next;
		}
		return 0;
	};         
	//print all records in data
	void print_all(patient* head)                   //print the list
	{
		int no = 1;
		patient* temp = head;
		if (isempty())
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Database is empty\n";
			return;
		}
		line(211, '=');
		cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
		line(211, '=');
		
		while (temp != NULL)
		{
			string name;
			if (temp->middle_name[0] == ' ')
				name = temp->last_name + ' ' + temp->first_name;
			else
				name = temp->last_name + ' ' + temp->middle_name + ' ' + temp->first_name;
			int day = temp->day;
			int month = temp->month;
			int year = temp->year;
			stringstream daystr;
			stringstream monthstr;
			stringstream yearstr;
			string days;
			string months;
			string years;
			daystr << day;
			monthstr << month;
			yearstr << year;
			daystr >> days;
			monthstr >> months;
			yearstr >> years;
			string bday = days + '/' + months + '/' + years;

			int dayi = temp->day_in;
			int monthi = temp->month_in;
			int yeari = temp->year_in;
			stringstream dayistr;
			stringstream monthistr;
			stringstream yearistr;
			string dayis;
			string monthis;
			string yearis;
			dayistr << dayi;
			monthistr << monthi;
			yearistr << yeari;
			dayistr >> dayis;
			monthistr >> monthis;
			yearistr >> yearis;
			string day_in = dayis + '/' + monthis + '/' + yearis;

			int dayo = temp->day_out;
			int montho = temp->month_out;
			int yearo = temp->year_out;
			stringstream dayostr;
			stringstream monthostr;
			stringstream yearostr;
			string dayos;
			string monthos;
			string yearos;
			dayostr << dayo;
			monthostr << montho;
			yearostr << yearo;
			dayostr >> dayos;
			monthostr >> monthos;
			yearostr >> yearos;
			string day_out = dayos + '/' + monthos + '/' + yearos;

			printf("|%3d|%7d | %-24s| %c | %10s|%3d | %11llu| %-41s| %9d| %c | %10s| %3d | %-21s| %-11s| %10s| %11u|", no, temp->id, name.c_str(), temp->gender, bday.c_str(), temp->age, temp->cmnd, (temp->address).c_str(), temp->phone_number, temp->blood, day_in.c_str(), temp->room, temp->problem[0].c_str(), temp->doctor[0].c_str(), day_out.c_str(), temp->fee
			);
			for (int i = 1; i < 5; i++)
			{
				if ((temp->problem[i] == " ") && (i > 1))
					continue;
				if ((temp->problem[i]).length() > 1)
				{
					if ((temp->doctor[i] != " ") && ((i == 1)||(i == 0)))
						printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s| %-11s|           |            |", temp->problem[i].c_str(), temp->doctor[i].c_str());
					else
						printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s|            |           |            |", temp->problem[i].c_str());
				}
				else
				{
					if ((temp->doctor[i] != " ") && ((i == 1) || (i == 0)))
						printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s| %-11s|           |            |", temp->problem[i].c_str(), temp->doctor[i].c_str());
					else
						printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s|            |           |            |", temp->problem[i].c_str());
				}
			}

			line(211, '-');
			temp = temp->next;
			no++;
		}
	};
	//read from data.txt file
	bool read()
	{
		time_t current_time = time(0);       //local time
		tm* lc = gmtime(&current_time);       //utc time
		int cur_year = lc->tm_year + 1900;
		int cur_month = lc->tm_mon + 1;
		int cur_day = lc->tm_mday;

		ifstream data("data.txt");
		if (data.is_open())
		{
			data.seekg(0, ios::end);
			if (data.tellg() == 0) {
				ofstream data("data.txt");
				data << "//id/last_name/middle_name/first_name/gender/byear/bmonth/bday/age/cmnd/address/phone_number/blood/yearin/monthin/dayin/room/problem0/problem1/problem2/problem3/problem4/doctor0/doctor1/yearout/monthout/dayout/fee\n";
				data << "0| | | | |0|0|0|0|0| |0| |0|0|0|0| | | | | | | |0|0|0|0";
				data.close();
			}
			else
			{
				data.seekg(0, ios::beg);
			}
			while (!data.eof()) {
				string str;
				string arr[28];
				char search = '|';
				int pos = 0;
				int  i = 0;
				int prev = 0;
				int cur = 0;
				getline(data, str);
				if (str[0] == '/')
					continue;
				do
				{
					pos = str.find(search, cur);
					cur = pos;
					arr[i] = str.substr(prev, cur - prev);
					cur++;
					prev = cur;
					i++;
				} while (pos >= 0);
				
				patient* newp = new patient();
				if (head == NULL)					  //if list is empty, insert first element to list
				{
					newp->next = NULL;
					head = newp;
				}
				else {								  //insert at end of list
					patient* temp = head;
					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = newp;
					newp->next = NULL;
				}

				stringstream sid;
				int numid = 0;
				sid << arr[0];
				sid >> numid;
				newp->id = numid;

				newp->last_name = arr[1];
				newp->middle_name = arr[2];
				newp->first_name = arr[3];
				newp->gender = toupper(arr[4][0]);

				stringstream num_year;
				short int num_y;
				num_year << arr[5];
				num_year >> num_y;
				newp->year = num_y;

				stringstream num_month;
				short int num_m;
				num_month << arr[6];
				num_month >> num_m;
				newp->month = num_m;

				stringstream num_day;
				short int num_d;
				num_day << arr[7];
				num_day >> num_d;
				newp->day = num_d;

				stringstream num_cmnd;
				unsigned long long int cmnd;
				num_cmnd << arr[9];
				num_cmnd >> cmnd;
				newp->cmnd = cmnd;

				newp->address = arr[10];

				stringstream num_phone;
				int phone = 0;
				num_phone << arr[11];
				num_phone >> phone;
				newp->phone_number = phone;

				newp->blood = toupper(arr[12][0]);
				
				stringstream num_yearin;
				short int yearin;
				num_yearin << arr[13];
				num_yearin >> yearin;
				newp->year_in = yearin;

				stringstream num_monthin;
				short int monthin;
				num_monthin << arr[14];
				num_monthin >> monthin;
				newp->month_in = monthin;

				stringstream num_dayin;
				short int dayin;
				num_dayin << arr[15];
				num_dayin >> dayin;
				newp->day_in = dayin;

				stringstream num_room;
				short int room;
				num_room << arr[16];
				num_room >> room;
				newp->room = room;

				for (int i = 0; i < 5; i++)
				{
					newp->problem[i] = arr[17+i];
				}
				for (int i = 0; i < 2; i++)
				{
					newp->doctor[i] = arr[22+i];
				}

				stringstream num_yearout;
				short int yearout;
				num_yearout << arr[24];
				num_yearout >> yearout;
				newp->year_out = yearout;

				stringstream num_monthout;
				short int monthout;
				num_monthout << arr[25];
				num_monthout >> monthout;
				newp->month_out = monthout;

				stringstream num_dayout;
				short int dayout;
				num_dayout << arr[26];
				num_dayout >> dayout;
				newp->day_out = dayout;

				//calculate age 
				int age = 0;
				if (num_y == 0)
					age = 0;
				else
					age = (cur_year)-num_y;
				if (age < 0)
					age = 0;
				newp->age = age;

				//calculate fee
				int value = 0;
				int fee = 0;
				if ((room > 100) && (room < 200))
					value = 100000;
				if ((room > 200) && (room < 300))
					value = 200000;
				if ((room > 300) && (room < 400))
					value = 300000;
				if ((room > 400) && (room < 500))
					value = 400000;
				if ((room > 500) && (room < 600))
					value = 500000;

				if ((dayin == 0) || (monthin == 0) || (yearin == 0) || (room == 0))
				{
					fee = 0;
					goto v;
				}
				else
				{
					tm in {0};
					in.tm_year = yearin - 1900;
					in.tm_mon = monthin - 1;
					in.tm_mday = dayin;
					time_t ein = mktime(&in);

					tm out {0};
					if ((yearout != 0) && (monthout != 0) && (dayout != 0))    //if day out != 0
					{
						out.tm_year = yearout - 1900;
						out.tm_mon = monthout - 1;
						out.tm_mday = dayout;
					}
					else                                       //if day out = 0
					{
						out.tm_year = cur_year - 1900;
						out.tm_mon = cur_month - 1;
						out.tm_mday = cur_day;
					}
					time_t eout = mktime(&out);
					time_t dif = eout - ein;
					fee = value * (dif / 86400 + 1);
				}
				v:
				newp->fee = fee;

			}
		}
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Can not open file data.txt\n";
			return 0;
		}
		data.close();
		return 1;
	};
	//write to data.txt file
	bool write()
	{
		ofstream data("data.txt", ios::out | ios::trunc);
		cout << "  \n\t\t\t\t\t\t\t\t\t\t\t        Write to data.txt file\n";
		if (data.is_open())
		{
			data << "//id/last_name/middle_name/first_name/gender/byear/bmonth/bday/age/cmnd/address/phone_number/blood/yearin/monthin/dayin/room/problem0/problem1/problem2/problem3/problem4/doctor0/doctor1/yearout/monthout/dayout/fee";
			patient* temp = head;
			while (temp != NULL)
			{
				data << '\n';
				data << temp->id << '|' << temp->last_name << '|' << temp->middle_name << '|'
					<< temp->first_name << '|' << temp->gender << '|' << temp->year << '|' << temp->month
					<< '|' << temp->day << '|' << temp->age << '|' << temp->cmnd << '|' << temp->address
					<< '|' << temp->phone_number << '|' << temp->blood << '|' << temp->year_in << '|'
					<< temp->month_in << '|' << temp->day_in << '|' << temp->room << '|'
					<< temp->problem[0] << '|' << temp->problem[1] << '|' << temp->problem[2] << '|'
					<< temp->problem[3] << '|' << temp->problem[4] << '|'
					<< temp->doctor[0] << '|' << temp->doctor[1] << '|' << temp->year_out << '|' 
					<< temp->month_out << '|' << temp->day_out << '|' << temp->fee;
				
				temp = temp->next;
			}
		}
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Can not open file data.txt\n";
			return 0;
		}
		return 1;
	}
	//show statistic in main menu
	void stastic()													//
	{
		time_t current_time = time(0);
		tm* lc = localtime(&current_time);
		int cur_year = lc->tm_year + 1900;
		int cur_month = lc->tm_mon + 1;
		int cur_day = lc->tm_mday;
		patient* temp = head;
		int check = 0;
		while (temp != NULL)
		{
			if (temp->year_in == cur_year)
			{
				if (temp->month_in == cur_month)
					if (temp->day_in <= cur_day)
					{
						check++;
					}
			}
			temp = temp->next;
		}
		cout << endl << endl;
		line(94, ' ');
		line(24, '-');
		cout << "\n";
		printf(" \t\t\t\t\t\t\t\t\t\t\t      | Total patients:  %3d |\n", total());
		printf(" \t\t\t\t\t\t\t\t\t\t\t      | This month:     +%3d |\n", check);
		line(94, ' ');
		line(24, '-');
	}
	//calculate total records in database
	int total()
	{
		patient* temp = head;
		int total = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			total++;
		}
		return total;
	}
	//print a single record
	void print(patient* newp)
	{
		patient* temp = head;
		int no = 1;
		while (temp != NULL)
		{
			if (temp->id == newp->id)
			{
				string name;
				if (temp->middle_name[0] == ' ')
					name = temp->last_name + ' ' + temp->first_name;
				else
					name = temp->last_name + ' ' + temp->middle_name + ' ' + temp->first_name;
				int day = temp->day;
				int month = temp->month;
				int year = temp->year;
				stringstream daystr;
				stringstream monthstr;
				stringstream yearstr;
				string days;
				string months;
				string years;
				daystr << day;
				monthstr << month;
				yearstr << year;
				daystr >> days;
				monthstr >> months;
				yearstr >> years;
				string bday = days + '/' + months + '/' + years;

				int dayi = temp->day_in;
				int monthi = temp->month_in;
				int yeari = temp->year_in;
				stringstream dayistr;
				stringstream monthistr;
				stringstream yearistr;
				string dayis;
				string monthis;
				string yearis;
				dayistr << dayi;
				monthistr << monthi;
				yearistr << yeari;
				dayistr >> dayis;
				monthistr >> monthis;
				yearistr >> yearis;
				string day_in = dayis + '/' + monthis + '/' + yearis;

				int dayo = temp->day_out;
				int montho = temp->month_out;
				int yearo = temp->year_out;
				stringstream dayostr;
				stringstream monthostr;
				stringstream yearostr;
				string dayos;
				string monthos;
				string yearos;
				dayostr << dayo;
				monthostr << montho;
				yearostr << yearo;
				dayostr >> dayos;
				monthostr >> monthos;
				yearostr >> yearos;
				string day_out = dayos + '/' + monthos + '/' + yearos;

				printf("|%3d|%7d | %-24s| %c | %10s|%3d | %11llu| %-41s| %9d| %c | %10s| %3d | %-21s| %-11s| %10s| %11u|", no, temp->id, name.c_str(), temp->gender, bday.c_str(), temp->age, temp->cmnd, (temp->address).c_str(), temp->phone_number, temp->blood, day_in.c_str(), temp->room, temp->problem[0].c_str(), temp->doctor[0].c_str(), day_out.c_str(), temp->fee
				);
				for (int i = 1; i < 5; i++)
				{
					if ((temp->problem[i] == " ") && (i > 1))
						continue;
					if ((temp->problem[i]).length() > 1)
					{
						if ((temp->doctor[i] != " ") && ((i == 1) || (i == 0)))
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s| %-11s|           |            |", temp->problem[i].c_str(), temp->doctor[i].c_str());
						else
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s|            |           |            |", temp->problem[i].c_str());
					}
					else
					{
						if ((temp->doctor[i] != " ") && ((i == 1) || (i == 0)))
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s| %-11s|           |            |", temp->problem[i].c_str(), temp->doctor[i].c_str());
						else
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s|            |           |            |", temp->problem[i].c_str());
					}
				}
				line(211, '-');
				break;
			}
			else
			{
				temp = temp->next;
				no++;
			}
		}
	}
	//print a single record
	void print(patient* newp, patient* head)
	{
		patient* temp = head;
		int no = 1;
		while (temp != NULL)
		{
			if (temp->id == newp->id)
			{
				string name;
				if (temp->middle_name[0] == ' ')
					name = temp->last_name + ' ' + temp->first_name;
				else
					name = temp->last_name + ' ' + temp->middle_name + ' ' + temp->first_name;
				int day = temp->day;
				int month = temp->month;
				int year = temp->year;
				stringstream daystr;
				stringstream monthstr;
				stringstream yearstr;
				string days;
				string months;
				string years;
				daystr << day;
				monthstr << month;
				yearstr << year;
				daystr >> days;
				monthstr >> months;
				yearstr >> years;
				string bday = days + '/' + months + '/' + years;

				int dayi = temp->day_in;
				int monthi = temp->month_in;
				int yeari = temp->year_in;
				stringstream dayistr;
				stringstream monthistr;
				stringstream yearistr;
				string dayis;
				string monthis;
				string yearis;
				dayistr << dayi;
				monthistr << monthi;
				yearistr << yeari;
				dayistr >> dayis;
				monthistr >> monthis;
				yearistr >> yearis;
				string day_in = dayis + '/' + monthis + '/' + yearis;

				int dayo = temp->day_out;
				int montho = temp->month_out;
				int yearo = temp->year_out;
				stringstream dayostr;
				stringstream monthostr;
				stringstream yearostr;
				string dayos;
				string monthos;
				string yearos;
				dayostr << dayo;
				monthostr << montho;
				yearostr << yearo;
				dayostr >> dayos;
				monthostr >> monthos;
				yearostr >> yearos;
				string day_out = dayos + '/' + monthos + '/' + yearos;

				printf("|%3d|%7d | %-24s| %c | %10s|%3d | %11llu| %-41s| %9d| %c | %10s| %3d | %-21s| %-11s| %10s| %11u|", no, temp->id, name.c_str(), temp->gender, bday.c_str(), temp->age, temp->cmnd, (temp->address).c_str(), temp->phone_number, temp->blood, day_in.c_str(), temp->room, temp->problem[0].c_str(), temp->doctor[0].c_str(), day_out.c_str(), temp->fee
				);
				for (int i = 1; i < 5; i++)
				{
					if ((temp->problem[i] == " ") && (i > 1))
						continue;
					if ((temp->problem[i]).length() > 1)
					{
						if ((temp->doctor[i] != " ") && ((i == 1) || (i == 0)))
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s| %-11s|           |            |", temp->problem[i].c_str(), temp->doctor[i].c_str());
						else
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s|            |           |            |", temp->problem[i].c_str());
					}
					else
					{
						if ((temp->doctor[i] != " ") && ((i == 1) || (i == 0)))
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s| %-11s|           |            |", temp->problem[i].c_str(), temp->doctor[i].c_str());
						else
							printf("|   |        |                         |   |           |    |            |                                          |          |   |           |     | %-21s|            |           |            |", temp->problem[i].c_str());
					}
				}
				line(211, '-');
				break;
			}
			else
			{
				temp = temp->next;
				no++;
			}
		}
	}
	//sort record base on ID
	void sort_id()
	{
		patient* current = head;  
		patient* newl = NULL;    
		patient* tail = NULL;      

		while (current != NULL)
		{
			if (newl == NULL)
			{
				newl = new patient;
				newl->id = current->id;
				newl->last_name = current->last_name;
				newl->middle_name = current->middle_name;
				newl->first_name = current->first_name;
				newl->gender = current->gender;
				newl->year = current->year;
				newl->month = current->month;
				newl->day = current->day;
				newl->age = current->age;
				newl->cmnd = current->cmnd;
				newl->address = current->address;
				newl->phone_number = current->phone_number;
				newl->blood = current->blood;
				newl->day_in = current->day_in;
				newl->month_in = current->month_in;
				newl->year_in = current->year_in;
				newl->room = current->room;
				newl->year_out = current->year_out;
				newl->month_out = current->month_out;
				newl->day_out = current->day_out;
				newl->fee = current->fee;
				newl->problem[0] = current->problem[0];
				newl->problem[1] = current->problem[1];
				newl->problem[2] = current->problem[2];
				newl->problem[3] = current->problem[3];
				newl->problem[4] = current->problem[4];
				newl->doctor[0] = current->doctor[0];
				newl->doctor[1] = current->doctor[1];
				newl->next = NULL;
				tail = newl;
			}
			else 
			{
				tail->next = new patient;
				tail = tail->next;
				tail->id = current->id;
				tail->last_name = current->last_name;
				tail->middle_name = current->middle_name;
				tail->first_name = current->first_name;
				tail->gender = current->gender;
				tail->year = current->year;
				tail->month = current->month;
				tail->day = current->day;
				tail->age = current->age;
				tail->cmnd = current->cmnd;
				tail->address = current->address;
				tail->phone_number = current->phone_number;
				tail->blood = current->blood;
				tail->day_in = current->day_in;
				tail->month_in = current->month_in;
				tail->year_in = current->year_in;
				tail->room = current->room;
				tail->year_out = current->year_out;
				tail->month_out = current->month_out;
				tail->day_out = current->day_out;
				tail->fee = current->fee;
				tail->problem[0] = current->problem[0];
				tail->problem[1] = current->problem[1];
				tail->problem[2] = current->problem[2];
				tail->problem[3] = current->problem[3];
				tail->problem[4] = current->problem[4];
				tail->doctor[0] = current->doctor[0];
				tail->doctor[1] = current->doctor[1];
				tail->next = NULL;
			}
			current = current->next;
		}

		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Sort base on ID\n";
		patient* a, * b, * c, * d, * r;
		a = b = newl;
		while (b->next) 
		{
			c = d = b->next;
			while (d) 
			{
				if (b->id > d->id) 
				{
					if (b->next == d) 
					{
						if (b == newl) 
						{
							b->next = d->next;
							d->next = b;
							r = b;
							b = d;
							d = r;
							c = d;
							newl = b;
							d = d->next;
						}
						else 
						{
							b->next = d->next;
							d->next = b;
							a->next = d;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
						}
					}
					else 
					{
						if (b == newl) 
						{
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
							newl = b;
						}
						else 
						{
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;
							a->next = d;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
						}
					}
				}
				else 
				{
					c = d;
					d = d->next;
				}
			}
			a = b;
			b = b->next;
		}
		int t = 0;
		patient* temp = newl;
		print_all(temp);

	}
	//sort record base on age
	void sort_age()
	{
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Sort base on age\n";
		patient* current = head;
		patient* newl = NULL;    
		patient* tail = NULL;      

		while (current != NULL)
		{
			if (newl == NULL)
			{
				newl = new patient;
				newl->id = current->id;
				newl->last_name = current->last_name;
				newl->middle_name = current->middle_name;
				newl->first_name = current->first_name;
				newl->gender = current->gender;
				newl->year = current->year;
				newl->month = current->month;
				newl->day = current->day;
				newl->age = current->age;
				newl->cmnd = current->cmnd;
				newl->address = current->address;
				newl->phone_number = current->phone_number;
				newl->blood = current->blood;
				newl->day_in = current->day_in;
				newl->month_in = current->month_in;
				newl->year_in = current->year_in;
				newl->room = current->room;
				newl->year_out = current->year_out;
				newl->month_out = current->month_out;
				newl->day_out = current->day_out;
				newl->fee = current->fee;
				newl->problem[0] = current->problem[0];
				newl->problem[1] = current->problem[1];
				newl->problem[2] = current->problem[2];
				newl->problem[3] = current->problem[3];
				newl->problem[4] = current->problem[4];
				newl->doctor[0] = current->doctor[0];
				newl->doctor[1] = current->doctor[1];
				newl->next = NULL;
				tail = newl;
			}
			else
			{
				tail->next = new patient;
				tail = tail->next;
				tail->id = current->id;
				tail->last_name = current->last_name;
				tail->middle_name = current->middle_name;
				tail->first_name = current->first_name;
				tail->gender = current->gender;
				tail->year = current->year;
				tail->month = current->month;
				tail->day = current->day;
				tail->age = current->age;
				tail->cmnd = current->cmnd;
				tail->address = current->address;
				tail->phone_number = current->phone_number;
				tail->blood = current->blood;
				tail->day_in = current->day_in;
				tail->month_in = current->month_in;
				tail->year_in = current->year_in;
				tail->room = current->room;
				tail->year_out = current->year_out;
				tail->month_out = current->month_out;
				tail->day_out = current->day_out;
				tail->fee = current->fee;
				tail->problem[0] = current->problem[0];
				tail->problem[1] = current->problem[1];
				tail->problem[2] = current->problem[2];
				tail->problem[3] = current->problem[3];
				tail->problem[4] = current->problem[4];
				tail->doctor[0] = current->doctor[0];
				tail->doctor[1] = current->doctor[1];
				tail->next = NULL;
			}
			current = current->next;
		}
		patient* a, * b, * c, * d, * r;
		a = b = newl;
		while (b->next) 
		{
			c = d = b->next;
			while (d) 
			{
				if (b->age > d->age) 
				{
					if (b->next == d) 
					{
						if (b == newl) 
						{
							b->next = d->next;
							d->next = b;
							r = b;
							b = d;
							d = r;
							c = d;
							newl = b;
							d = d->next;
						}
						else 
						{
							b->next = d->next;
							d->next = b;
							a->next = d;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
						}
					}
					else 
					{
						if (b == newl) 
						{
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
							newl = b;
						}
						else 
						{
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;
							a->next = d;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
						}
					}
				}
				else 
				{
					c = d;
					d = d->next;
				}
			}
			a = b;
			b = b->next;
		}
		int t = 0;
		patient* temp = newl;
		print_all(temp);
	}
	//sort record base on room
	void sort_room()
	{
		cout << "  \t\t\t\t\t\t\t\t\t\t\t        Sort base on room\n";
		patient* current = head;
		patient* newl = NULL;    
		patient* tail = NULL;       

		while (current != NULL)
		{
			if (newl == NULL)
			{
				newl = new patient;
				newl->id = current->id;
				newl->last_name = current->last_name;
				newl->middle_name = current->middle_name;
				newl->first_name = current->first_name;
				newl->gender = current->gender;
				newl->year = current->year;
				newl->month = current->month;
				newl->day = current->day;
				newl->age = current->age;
				newl->cmnd = current->cmnd;
				newl->address = current->address;
				newl->phone_number = current->phone_number;
				newl->blood = current->blood;
				newl->day_in = current->day_in;
				newl->month_in = current->month_in;
				newl->year_in = current->year_in;
				newl->room = current->room;
				newl->year_out = current->year_out;
				newl->month_out = current->month_out;
				newl->day_out = current->day_out;
				newl->fee = current->fee;
				newl->problem[0] = current->problem[0];
				newl->problem[1] = current->problem[1];
				newl->problem[2] = current->problem[2];
				newl->problem[3] = current->problem[3];
				newl->problem[4] = current->problem[4];
				newl->doctor[0] = current->doctor[0];
				newl->doctor[1] = current->doctor[1];
				newl->next = NULL;
				tail = newl;
			}
			else
			{
				tail->next = new patient;
				tail = tail->next;
				tail->id = current->id;
				tail->last_name = current->last_name;
				tail->middle_name = current->middle_name;
				tail->first_name = current->first_name;
				tail->gender = current->gender;
				tail->year = current->year;
				tail->month = current->month;
				tail->day = current->day;
				tail->age = current->age;
				tail->cmnd = current->cmnd;
				tail->address = current->address;
				tail->phone_number = current->phone_number;
				tail->blood = current->blood;
				tail->day_in = current->day_in;
				tail->month_in = current->month_in;
				tail->year_in = current->year_in;
				tail->room = current->room;
				tail->year_out = current->year_out;
				tail->month_out = current->month_out;
				tail->day_out = current->day_out;
				tail->fee = current->fee;
				tail->problem[0] = current->problem[0];
				tail->problem[1] = current->problem[1];
				tail->problem[2] = current->problem[2];
				tail->problem[3] = current->problem[3];
				tail->problem[4] = current->problem[4];
				tail->doctor[0] = current->doctor[0];
				tail->doctor[1] = current->doctor[1];
				tail->next = NULL;
			}
			current = current->next;
		}
		patient* a, * b, * c, * d, * r;
		a = b = newl;
		while (b->next) 
		{
			c = d = b->next;
			while (d) 
			{
				if (b->room > d->room) 
				{
					if (b->next == d) 
					{
						if (b == newl) 
						{
							b->next = d->next;
							d->next = b;
							r = b;
							b = d;
							d = r;
							c = d;
							newl = b;
							d = d->next;
						}
						else {
							b->next = d->next;
							d->next = b;
							a->next = d;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
						}
					}
					else 
					{
						if (b == newl) 
						{
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
							newl = b;
						}
						else 
						{
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;
							a->next = d;
							r = b;
							b = d;
							d = r;
							c = d;
							d = d->next;
						}
					}
				}
				else {
					c = d;
					d = d->next;
				}
			}
			a = b;
			b = b->next;
		}
		int t = 0;
		patient* temp = newl;
		print_all(temp);
	}
	//read from history.txt file
	bool read_history()
	{
		time_t current_time = time(0);
		tm* lc = localtime(&current_time);
		int cur_year = lc->tm_year + 1900;
		int cur_month = lc->tm_mon + 1;
		int cur_day = lc->tm_mday;

		ifstream data("history.txt");
		if (data.is_open())
		{
			data.seekg(0, ios::end);
			if (data.tellg() == 0) {
				ofstream data("history.txt");
				data << "//id/last_name/middle_name/first_name/gender/byear/bmonth/bday/age/cmnd/address/phone_number/blood/yearin/monthin/dayin/room/problem0/problem1/problem2/problem3/problem4/doctor0/doctor1/yearout/monthout/dayout/fee\n";
				data << "0| | | | |0|0|0|0|0| |0| |0|0|0|0| | | | | | | |0|0|0|0";
				data.close();
			}
			else
			{
				data.seekg(0, ios::beg);
			}
			while (!data.eof()) {
				string str;
				string arr[28];
				char search = '|';
				int pos = 0;
				int  i = 0;
				int prev = 0;
				int cur = 0;
				getline(data, str);
				if (str[0] == '/')
					continue;
				do
				{
					pos = str.find(search, cur);
					cur = pos;
					arr[i] = str.substr(prev, cur - prev);
					cur++;
					prev = cur;
					i++;
				} while (pos >= 0);

				patient* newp = new patient();
				if (history == NULL)					  //if list is empty, insert first element to list
				{
					newp->next = NULL;
					history = newp;
				}
				else {								  //insert at end of list
					patient* temp = history;
					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = newp;
					newp->next = NULL;
				}

				stringstream sid;
				int numid = 0;
				sid << arr[0];
				sid >> numid;
				newp->id = numid;

				newp->last_name = arr[1];
				newp->middle_name = arr[2];
				newp->first_name = arr[3];
				newp->gender = toupper(arr[4][0]);

				stringstream num_year;
				short int num_y;
				num_year << arr[5];
				num_year >> num_y;
				newp->year = num_y;

				stringstream num_month;
				short int num_m;
				num_month << arr[6];
				num_month >> num_m;
				newp->month = num_m;

				stringstream num_day;
				short int num_d;
				num_day << arr[7];
				num_day >> num_d;
				newp->day = num_d;

				stringstream num_cmnd;
				unsigned long long int cmnd;
				num_cmnd << arr[9];
				num_cmnd >> cmnd;
				newp->cmnd = cmnd;

				newp->address = arr[10];

				stringstream num_phone;
				int phone = 0;
				num_phone << arr[11];
				num_phone >> phone;
				newp->phone_number = phone;

				newp->blood = toupper(arr[12][0]);

				stringstream num_yearin;
				short int yearin;
				num_yearin << arr[13];
				num_yearin >> yearin;
				newp->year_in = yearin;

				stringstream num_monthin;
				short int monthin;
				num_monthin << arr[14];
				num_monthin >> monthin;
				newp->month_in = monthin;

				stringstream num_dayin;
				short int dayin;
				num_dayin << arr[15];
				num_dayin >> dayin;
				newp->day_in = dayin;

				stringstream num_room;
				short int room;
				num_room << arr[16];
				num_room >> room;
				newp->room = room;

				for (int i = 0; i < 5; i++)
				{
					newp->problem[i] = arr[17 + i];
				}
				for (int i = 0; i < 2; i++)
				{
					newp->doctor[i] = arr[22 + i];
				}

				stringstream num_yearout;
				short int yearout;
				num_yearout << arr[24];
				num_yearout >> yearout;
				newp->year_out = yearout;

				stringstream num_monthout;
				short int monthout;
				num_monthout << arr[25];
				num_monthout >> monthout;
				newp->month_out = monthout;

				stringstream num_dayout;
				short int dayout;
				num_dayout << arr[26];
				num_dayout >> dayout;
				newp->day_out = dayout;

				stringstream age_str;
				int age;
				age_str << arr[8];
				age_str >> age;
				newp->age = age;

				stringstream fee_str;
				unsigned long long int fee;
				fee_str << arr[27];
				fee_str >> fee;
				newp->fee = fee;

			}
		}
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Can not open file history.txt\n";
			return 0;
		}
		data.close();
		return 1;
	};
	//write to history.txt file
	bool write_history()
	{
		ofstream data("history.txt", ios::out | ios::trunc);
		cout << "  \n\t\t\t\t\t\t\t\t\t\t\t        Write to history.txt file\n";
		if (data.is_open())
		{
			data << "//id/last_name/middle_name/first_name/gender/byear/bmonth/bday/age/cmnd/address/phone_number/blood/yearin/monthin/dayin/room/problem0/problem1/problem2/problem3/problem4/doctor0/doctor1/yearout/monthout/dayout/fee";
			patient* temp = history;
			while (temp != NULL)
			{
				data << '\n';
				data << temp->id << '|' << temp->last_name << '|' << temp->middle_name << '|'
					<< temp->first_name << '|' << temp->gender << '|' << temp->year << '|' << temp->month
					<< '|' << temp->day << '|' << temp->age << '|' << temp->cmnd << '|' << temp->address
					<< '|' << temp->phone_number << '|' << temp->blood << '|' << temp->year_in << '|'
					<< temp->month_in << '|' << temp->day_in << '|' << temp->room << '|'
					<< temp->problem[0] << '|' << temp->problem[1] << '|' << temp->problem[2] << '|'
					<< temp->problem[3] << '|' << temp->problem[4] << '|'
					<< temp->doctor[0] << '|' << temp->doctor[1] << '|' << temp->year_out << '|'
					<< temp->month_out << '|' << temp->day_out << '|' << temp->fee;
				temp = temp->next;
			}
		}
		else
		{
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        Can not open file history.txt\n";
			return 0;
		}
		return 1;
	}
	//search and print record in history database by month
	void search_history_month()              //search deleted record this month
	{
	a:
		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      |     PATIENT LEAVE    |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      |     (This month)     |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";

		time_t current_time = time(0);
		tm* lc = localtime(&current_time);

		int cur_year = lc->tm_year + 1900;
		int cur_month = lc->tm_mon + 1;
		int cur_day = lc->tm_mday;

		patient* temp = history;
		patient* temp1 = history;
		int no = 1;
		int count = 0;
		while (temp1 != NULL)
		{
			if ((temp1->year_out == cur_year) && (temp1->month_out == cur_month))
			{
				count++;
			}
			temp1 = temp1->next;
		}
		if (count > 0)
		{
			line(211, '=');
			cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
			line(211, '=');
		}
		while (temp != NULL)
		{
			if ((temp->year_out == cur_year) && (temp->month_out == cur_month))
			{
				print(temp, history);
			}
			temp = temp->next;
			no++;
		}
		if (count == 0)
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        No patient left this month\n\n";
	};
	//search and print record in history database by year
	void search_history_year()              //search deleted record this month
	{
	a:
		time_t current_time = time(0);
		tm* lc = localtime(&current_time);

		int cur_year = lc->tm_year + 1900;
		int cur_month = lc->tm_mon + 1;
		int cur_day = lc->tm_mday;

		system("cls");
		title();
		stastic();
		printf("\n\n\n\n\n\n\n\n\n");
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      |     PATIENT LEAVE    |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      |      (This year)     |\n";
		cout << "  \t\t\t\t\t\t\t\t\t\t\t      ------------------------\n\n";


		patient* temp = history;
		patient* temp1 = history;
		int no = 1;
		int count = 0;
		while (temp1 != NULL)
		{
			if (temp1->year_out == cur_year) 
			{
				count++;
			}
			temp1 = temp1->next;
		}
		if (count > 0)
		{
			line(211, '=');
			cout << "| NO|   ID   |          NAME           | G |  BIRTHDAY |AGE |    CMND    |                 ADDRESS                  |  PHONE   |BT |   DAY IN  |ROOM |       PROBLEM        |   DOCTOR   |  DAY OUT  |    FEE     |";
			line(211, '=');
		}
		while (temp != NULL)
		{
			if (temp->year_out == cur_year)
			{
				print(temp, history);
			}
			temp = temp->next;
			no++;
		}
		if (count == 0)
			cout << "  \t\t\t\t\t\t\t\t\t\t\t        No patient left this year\n\n";
	};

};


int main()
{
	list a;
	a.read();
	a.read_history();
	title();
	press();
	a.menu();
}

