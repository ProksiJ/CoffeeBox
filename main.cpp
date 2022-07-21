#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<iomanip>
#include<windows.h>
using namespace std;

double priceEspresso = 1.7;
double priceCappucino = 3.4;
double priceLatte = 3.4;

void printMenu();
double insertCoin();
void makeEspresso();
void makeCappuccino();
void makeLatte();

int main(int argc, char** argv) {
	
	int choice = 0;
	double balance = 0.0;
	string str = "";

	while(true) {
		cout << endl << "COFFEEBOX" << endl << "-----------------------" << endl;
		printMenu();
		cout << "-----------------------" << endl;
		cout << "Your choice? ";
		cin >> choice;
		if (choice == 0) {
			system("CLS");
			balance += insertCoin(priceEspresso);
			system("CLS");
		} else if (choice == 1) {
			makeEspresso();
		} else if (choice == 2) {
			
		} else if (choice == 3) {
			
		} else if (choice == 4) {
			
		} else if (choice == 5) {
			cout << "Thank you for your purchase!";
			system("CLS");
			break;
		} else 
			cout << "Wrong command! Try again with number [1..5]";
	}
	return 0;
}

void printMenu() {
	cout << "Please, choose an option: " << endl;
	cout << "1. Espresso" << "\t" << priceEspresso << " BYN" << endl;
	cout << "2. Cappuccino" << "\t" << priceCappucino << " BYN" << endl;
	cout << "3. Latte" << "\t" << priceLatte << " BYN" << endl;
	cout << "4. Service menu" << endl;
	cout << "5. Exit" << endl;
}

double insertCoin(double price) {
	double balance = 0.0;
	cout << "Please, deposit " << price << " BYN";
	cout << "Currently deposited: " << balance;
	cin >> balance;
	if ( balance > 2) //and balance < 10)
		//cout << "Machine only accepts coins";
		balance /= 100;
	return balance;
}


void makeEspresso() {
	cout << "Wait...";
	Sleep(300);
	cout << "Done";
}
