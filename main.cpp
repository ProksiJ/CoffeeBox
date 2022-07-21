#include <iostream>
#include<windows.h>
#include <iomanip>
using namespace std;

double priceEspresso = 1.7;
double priceCappucino = 3.4;
double priceLatte = 3.4;
int cups = 7;
const int MAXCUPS = 700;
const int PIN = 5472;

void printMenu();
double insertCoin(double price);
void makeCoffe(string name, double price, double balance);
void progress();
bool checkCups();
bool checkBalance(double price, double balance);
void addSugar();

int enterPIN();
bool checkPIN(int pin);
void enteringServiceMod();
void printServiceMenuHeader();
void printServiceEnterHeader();
void printChoiceServiceMenu(double cash);
void printFooter();
void printWithdrawingCash();
void printCupsInfo();
bool addCups();

int main() {
	
	int serviceChoice = 0;
	int choice = 0;
	double balance = 0.0;
	double cash = 0.0;

	while(true) {
		cout << endl << endl;
		cout << "Your balance " << balance << " BYN" << endl;
		printMenu();
		cout << "Please, choose an option: ";
		cin >> choice;
		
		if (choice == 1) {
			if (checkCups()) {
				balance += insertCoin(priceEspresso);
				system("CLS");
			} else {
				cout << "Currently, we are out of cups." << endl;
				cout << "Please call customer service." << endl;
				Sleep(3000);
				system("CLS");
			}
			
		} else if (choice == 2) {
			makeCoffe("Espresso", priceEspresso, balance);
			cash += balance;
			balance = 0;
			Sleep(5000);
			system("CLS");
		} else if (choice == 3) {
			makeCoffe("Cappucino", priceCappucino, balance);
			cash += balance;
			balance = 0;
			Sleep(5000);
			system("CLS");
		} else if (choice == 4) {
			makeCoffe("Latte", priceLatte, balance);
			cash += balance;
			balance = 0;
			Sleep(5000);
			system("CLS");
		} else if (choice == 5) {
			system("cls");
			enteringServiceMod();

    		while (true) 
    		{
        		system("cls");
        		printServiceMenuHeader();
        		printChoiceServiceMenu(cash);
        		printFooter();
        		cin >> serviceChoice;

        		if (serviceChoice == 1) {
            		system("cls");
            		printServiceMenuHeader();
            		printWithdrawingCash();
            		cash = 0.0;
        		}
        		else if (serviceChoice == 2) {
            		system("cls");
            		printServiceMenuHeader();
            		printCupsInfo();
            		if (!addCups()) {
                		do {
                    		system("cls");
                    		printServiceMenuHeader();
                    		cout << "WARNING: The amount of cups cannot be more than " << MAXCUPS - cups << " and less or equal zero." << endl;
                    		printCupsInfo();
                		} while (!addCups());
            		}
        		}		
        		else if (serviceChoice == 3) {
        			system("cls");
					break;
        		}
        		else {
            		cout << "Error! Incorrect input. Please, enter of of the options listed bellow";
            		Sleep(3000);
					system("CLS");
        		}
    		}	
		} else {
			cout << "Error! Incorrect input. Please, enter of of the options listed bellow";
			Sleep(3000);
			system("CLS");
		}
			
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
	cout << "-----------------------" << endl;
}

double insertCoin(double price) {
	double balance = 0.0;
	cout << "Deposited money: ";
	cin >> balance;
	if (balance >= 10) 
		balance /= 100;
	return balance;
}

void makeCoffe(string name,  double price, double balance) {

	if (checkBalance(price, balance)){	
		system("CLS");
		cout << "Your coffee is being prepared, please wait a bit..." << endl;
		progress();
		cout << "Now, take your "<< name << "." << endl;
	    cout << "Have a nice day!" << endl;
	    cups--;
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

void addSugar() {
	int sugar = 0;
	cout << "Some sugar?" << endl;
	cout << "Enter, how many sugar do you want?";
	cin >> sugar;
}
	
int enterPIN()
{
    int pin = 0;

    cout << "Please, enter PIN and press \"Enter\":" << endl;
    printFooter();
    cin >> pin;

    return pin;
}

bool checkPIN(int pin)
{
    if (pin == PIN)
        return true;
    else
        return false;
}

void printServiceEnterHeader()
{
    cout << "COFFEEBOX" << endl;
    cout << "------------------" << endl;
}

void printServiceMenuHeader()
{
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
}

void printFooter()
{
    cout << "------------------" << endl;
}
void enteringServiceMod() 
{
    int pin = 0;

    printServiceEnterHeader();
    printServiceMenuHeader();
    pin = enterPIN();
    if (!checkPIN(pin))
    {
        do
        {
            system("cls");
            printServiceEnterHeader();
            printServiceMenuHeader();
            cout << "Error! Incorrect PIN." << endl;
            pin = enterPIN();

        } while (!checkPIN(pin));
    }
}

void printChoiceServiceMenu(double cash) {
    cout << "Current amount of cups: " << cups << endl;
    cout << "Accumulated cash: " << setprecision(2) << cash << " BYN" << endl;
    cout << "Please, choose an option: " << endl;
    cout << "1. Withdraw cash" << endl;
    cout << "2. Add cups" << endl;
    cout << "3. Return to Main Menu" << endl;
}

void printWithdrawingCash() 
{
    cout << "Withdrawing cash";
    for (int i = 0; i <= 5; i++)
    {
        Sleep(500);
        cout << ".";
    }
    cout << endl << "Cash withdrawn." << endl;
    cout << "Returning to Service Menu..." << endl;
    printFooter();
    Sleep(3000);
}

void printCupsInfo() 
{
    cout << "Current amount of cups is: " << cups << endl;
    cout << "The total amount of cups cannot be more than " << MAXCUPS << endl;
}

bool addCups() 
{
    int additionCups = 0;
    
    cin >> additionCups;

    if (additionCups + cups > MAXCUPS or additionCups <= 0)
        return false;
    else
        cups += additionCups;
    return true;
}
