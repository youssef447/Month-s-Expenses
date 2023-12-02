#include<iostream>
#include<string>
#include<math.h>
#include<map>
#include<unordered_map>
#include<vector>
#include<windows.h>
#include "expenses.h"
using namespace std;

expenses item;
vector<expenses> v[];
map<string, vector<expenses>> Smap;
map<int, map<string, vector<expenses>>> Pmap;
bool wrongChoice = false;
void AddItems();
void Display();

int main()
{


	int choice;
	while (true) //main outer loop
	{
		cout << "\n\n--------------------------- MAIN MENU --------------------------\n\n";
		cout << ">>>Enter your choice: \n\n";
		cout << "1-Add new expenses\n2-Delete expenses\n3-Edit expenses\n4-Search\n5-Display\n6-Exit\n";  //level 1 display
		cout << "\nChoice >>> "; cin >> choice;
		system("cls");
		if (choice == 6)  //to exit the program
		{
			cout << "Goodbye :)\n";
		}
		else if (choice == 1)  //to add new expenses
		{
			AddItems();
			system("cls");

			continue;  //to back to main menue
		}
		else if (choice == 2)  //to delete expenses
		{

			continue;  //to back to main menue
		}
		else if (choice == 3)  //to edit expenses
		{

			continue;  //to back to main menue
		}
		else if (choice == 4)  //to search
		{

			continue;  //to back to main menue
		}
		else if (choice == 5)  //to display
		{
			Display();
			system("cls");
			if (wrongChoice = true)
				cout << "wrong choice !!";
			wrongChoice = false;
			continue;  //to back to main menue
		}

		break;
	}  //main outer loop end


	system("PAUSE");
	return 0;
}

void AddItems()
{
	int num;
	char ch;
	while (true)
	{
		cout << "Enter number of items: ";
		cin >> num;

		if (num <= 0)
		{
			cout << "Do you want do add any items? (y/n): ";  cin >> ch;
			if (ch == 'n' || ch == 'N')
			{
				cout << "\n\n\n\t\t\t\t\t--No items were added--\n\n";
				break;
			}
			else
			{
				continue;
			}
		}
		cout << "Enter items information:\n";
		for (int i = 0; i < num; i++)
		{
			cout << "#" << i + 1 << " Item:\n";
			cout << "Name: ";  cin >> item.name;
			cout << "Category: ";  cin >> item.category;
			cout << "Date of buying(Day->Month->Year):  ";  cin >> item.buying_date.day >> item.buying_date.month >> item.buying_date.year;
			cout << "Total Price: ";  cin >> item.price;
			cout << "Amount of money spent: ";  cin >> item.money_spent;
			cout << "Amount of money remaining: ";  cin >> item.money_remaining;
			cout << "\n";
			Pmap[item.buying_date.month][item.category].push_back(item);
		}
		cout << "\n\n///////////////////////////////////////////////////////////////\n\n";
		cout << "\n\n\t\t\t\t\tItems were added successfully.\n\n";
		cout << "Do you want do add more items? (y/n) ";  cin >> ch;
		if (ch == 'n' || ch == 'N')
		{
			break;
		}
	}
	system("PAUSE");

}

void Search(int ch)
{
	char chr;
	int month;
	string category;
	vector<expenses>::iterator it3;
	map<string, vector<expenses>>::iterator it2;
	map<int, map<string, vector<expenses>>>::iterator it;



	if (ch == 1)  //search by month
	{
		cout << "->Enter month: "; cin >> month;
		it = Pmap.find(month);

		if (it != Pmap.end())
		{
			cout << "Month: " << it->first << "\nItems in that month:\n";

			for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
			{
				cout << "Category [" << it2->first << "] \nItems: ";
				for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
				{
					cout << "\nName: " << it3->name << "\nPrice: " << it3->price << endl;
				}

			}
		}
		else
		{
			cout << "Month wasn't found..!\n";
			cout << "Do you want do try again? (y/n) ";  cin >> chr;
			system("cls");
			if (chr == 'y' || chr == 'Y')
			{
				Search(1);
			}
		}

	}
	else if (ch == 2)  //search by category per month 
	{
		cout << "->Enter month: "; cin >> month;
		cout << "\n->Enter category: "; cin >> category;
		it = Pmap.find(month);
		it2 = Pmap[month].find(category);
		if (it != Pmap.end() && it2 != Pmap[month].end())
		{
			cout << "Month: " << it->first << "\nCategory: " << it2->first << "\nItems in that Category: \n";
			for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
			{
				cout << "\nName: " << it3->name << "\nPrice: " << it3->price << endl;
			}
		}
		else
		{
			cout << "Month or Category wasn't found..!\n";
			cout << "Do you want do try again? (y/n) ";  cin >> chr;
			system("cls");
			if (chr == 'y' || chr == 'Y')
			{
				Search(2);
			}
		}

	}
}

void Display() {
	map<int, map<string, vector<expenses>>> ::iterator itr;
	map<string, vector<expenses>> ::iterator itr2;
	vector<expenses> ::iterator itr3;
	int month;
	string cat;
	int choice2;
	float sum = 0;
	int counter = 0;
	cout << "1-Display Expenses per category \n2-Display Expenses per month \n";
	cout << ">>> Enter your choice: ";
	cin >> choice2;
	if (choice2 == 1) {
		cout << "\nEnter month number: ";
		cin >> month;
		cout << "\nEnter category name: ";
		cin >> cat;

		for (itr = Pmap.begin(); itr != Pmap.end(); itr++)
		{
			if (month == itr->first) {
				for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
				{
					if (cat == itr2->first) {
						cout << "\nTotal amount of money spent per " << itr->first << " per " << itr2->first;
						for (itr3 = itr2->second.begin(); itr3 != itr2->second.end(); itr3++)
						{
							sum += itr3->money_spent;
							counter++;
						}
						cout << " = " << sum << "\n" << endl;
						cout << "Number of Expenses is >> " << counter << " <<\n";
						break;
					}

				}
			}
			system("pause");
		}

	}
	else if (choice2 == 2) {
		cout << "\nEnter month number: ";
		cin >> month;
		for (itr = Pmap.begin(); itr != Pmap.end(); itr++)
		{
			if (month == itr->first) {
				for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
				{
					cout << "\nTotal amount of money spent per " << itr->first << " = ";
					for (itr3 = itr2->second.begin(); itr3 != itr2->second.end(); itr3++)
					{
						sum += itr3->money_spent;
						counter++;
					}
					cout << sum << "\n";
					cout << "Number of Expenses is >> " << counter << " <<\n";
					break;
				}


			}

		}
		system("pause");


	}
	else if (choice2 != 1 && choice2 != 2)
	{
		wrongChoice = true;

	}


}