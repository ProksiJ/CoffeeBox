#include <iostream>
#include<windows.h>
using namespace std;

double priceEspresso = 1.7;
double priceCappucino = 3.4;
double priceLatte = 3.4;
int cups = 7;

void printMenu();
double insertCoin(double price);
void makeCoffe(string name, double price, double balance);
void progress();
bool checkCups();
bool checkBalance(double price, double balance);

int main() {
	
	int choice = 0;
	double balance = 0.0;
	string error = "";
	string name = "Espresso";

	while(true) {
		cout << endl << endl;
		cout << "Your balance " << balance << " BYN" << endl;
		printMenu();
		cout << "Please, choose an option: ";
		cin >> choice;
		
		if (choice == 1) {
			balance += insertCoin(priceEspresso);
		} else if (choice == 2) {
			makeCoffe("Espresso", priceEspresso, balance);
		} else if (choice == 3) {
			makeCoffe("Cappucino", priceCappucino, balance);
		} else if (choice == 4) {
			makeCoffe("Latte", priceLatte, balance);
		} else if (choice == 5) {
			
		} else if (choice == 6) {
			cout << "Thank you for your purchase!";
			break;
		} else 
			cout << "Error! Incorrect input. Please, enter of of the options listed bellow";
	}

	return 0;
}

void printMenu() {
	cout << "-----------------------" << endl;
	cout << "1. Insert coins " << endl;
	cout << "2. Espresso" << "\t" << priceEspresso << " BYN" << endl;
	cout << "3. Cappuccino" << "\t" << priceCappucino << " BYN" << endl;
	cout << "4. Latte" << "\t" << priceLatte << " BYN" << endl;
	cout << "5. Service menu" << endl;
	cout << "6. Exit" << endl;
	cout << "-----------------------" << endl;
}

double insertCoin(double price) {
	double balance = 0.0;
	cout << "Deposit: ";
	cin >> balance;
	if ( balance > 2) //and balance < 10)
		//cout << "Machine only accepts coins";
		balance /= 100;
	return balance;
}


void makeCoffe(string name,  double price, double balance) {
	if (checkCups() and checkBalance(price, balance)){
		cout << "Your coffee is being prepared, please wait a bit..." << endl;
		progress();
		cout << "Now, take your "<< name << "." << endl;
	    cout << "Have a nice day!" << endl;
	} else if (!checkCups()){
		cout << "Currently, we are out of cups." << endl;
		cout << "Please call customer service." << endl;
	} else 
		cout << "Insufficient balance. Please, insert coins...";
	
}

void progress() {
	int maxWidth = 100;
    int progress = 0;
    
    while (progress <= maxWidth) {
        cout << "[";
        cout << string(progress, '=');

        if (progress < maxWidth) cout << ">";
        else if (progress == maxWidth) cout << "=";

        cout << string(maxWidth - progress, ' ');
        cout << "] "<< progress << "%\r";
        
        progress += 10;
        Sleep(100);
    } 
    cout << endl;
}
	
bool checkCups() {
	if (cups == 0) {
		return false;
	}else {
		return true;
	}
}	
	
bool checkBalance(double balance, double price) {
	if (balance > price) {
		return false;
	}else {
		return true;
	}
}
	

