#include <iostream>
#include<windows.h>
#include <iomanip>
using namespace std;

int cups = 7;
const int sleepTime = 3000;
const double ESPRESSO_PRICE = 1;
const double CAPPUCINO_PRICE = 2.5;
const double LATTE_PRICE = 2.5;
const int MAXCUPS = 700;
const int PIN = 5472;

void printMainMenu(double balance);
void printCoinMenu();
void viewBalance(double balance);
double insertCoin(double balance);
bool preparation(double price, double balance);
void makeCoffe(string name);
void progressBar();
bool checkCups();
bool checkBalance(double price, double balance);
void addSugar();
void printErrorInput();
void printOutOfCups();

void serviceMod(double cash);
bool logInServiceMod();
bool enteringServiceMod();
int enterPIN();
bool checkPIN(int pin);
void printServiceMenuHeader();
void printServiceEnterHeader();
void printChoiceServiceMenu(double cash);
void printFooter();
void printWithdrawingCash();
void printCupsInfo();
bool addCups();

int main() {
	int choice = 0;
	double inputMoney = 0.0;
	double cash = 0.0;		
	double balance = 0.0;

	while(true) {
		
		printMainMenu(balance);
		cin >> choice;
	
		if (choice == 1) {
			if (checkCups()) {
				inputMoney = insertCoin(balance);
				balance += inputMoney;	
				cash += inputMoney;
			} else 
				printOutOfCups();
				
		} else if (choice == 2) {
			if (preparation(balance, ESPRESSO_PRICE)){
				makeCoffe("Espresso");
				balance -= ESPRESSO_PRICE;
			}	
		} else if (choice == 3) {
			if (preparation(balance, CAPPUCINO_PRICE)){
				makeCoffe("Cappucino");
				balance -= CAPPUCINO_PRICE;
			}	
		} else if (choice == 4) {
			if (preparation(balance, LATTE_PRICE)){
				makeCoffe("Latte");
				balance -= LATTE_PRICE;
			}
		} else if (choice == 5) {
			if (!logInServiceMod()){
				return 0;
			}else{
				serviceMod(cash);
			}
		} else
			printErrorInput();	
	}
	
	return 0;
}

void printOutOfCups()
{
	cout << "Currently, we are out of cups." << endl;
	cout << "Please call customer service." << endl;
	Sleep(sleepTime);
	system("CLS");
}

void printErrorInput()
{
	cout << "Error! Incorrect input. Please, enter of of the options listed bellow";
    Sleep(sleepTime);
	system("CLS");
}

void printMainMenu(double balance) {
	system("CLS");
	printServiceEnterHeader();
	viewBalance(balance);
	cout << "-----------------------" << endl;
	cout << "1. Insert coins " << endl;
	cout << "2. Espresso" << "\t" << ESPRESSO_PRICE << " BYN" << endl;
	cout << "3. Cappuccino" << "\t" << CAPPUCINO_PRICE << " BYN" << endl;
	cout << "4. Latte" << "\t" << LATTE_PRICE << " BYN" << endl;
	cout << "5. Service menu" << endl;
	cout << "-----------------------" << endl;
	cout << "Please, choose an option: ";
}

void printCoinMenu() {
	cout << "-----------------------" << endl;
	cout << "1. 2 BYN" <<  endl;
	cout << "2. 1 BYN" << endl;
	cout << "3. 0,50 BYN" << endl;
	cout << "4. 0,20 BYN" << endl;
	cout << "5. 0,10 BYN" << endl;
	cout << "6. Exit to Main Menu " << endl;
	cout << "-----------------------" << endl;
}

void viewBalance(double balance) {
	cout << "Your balance " << balance << " BYN" << endl;
}

double insertCoin(double balance) {
	double insertCoins = 0.0;
	int choice = 0;
	while (true) {
		system("CLS");
		viewBalance(balance + insertCoins);
		printCoinMenu();
		cout << "Please, choose an option: ";
		cin >> choice;
		if (choice == 1)
			insertCoins += 2.0;
		else if (choice == 2)
			insertCoins += 1.0;
		else if (choice == 3)
			insertCoins += 0.5;
		else if (choice == 4)
			insertCoins += 0.2;
		else if (choice == 5)
			insertCoins += 0.1;
		else if (choice == 6)
			break;
		else {
			printErrorInput();
		}
	}
	return insertCoins;
}

bool preparation(double price, double balance) {
	if (!checkBalance(price, balance)){
		cout << "Insufficient balance. Please, insert coins...";
		Sleep(sleepTime);
		return false;
	}	
	if (!checkCups()) {	
		cout << "Currently, we are out of cups." << endl;
		cout << "Please call customer service." << endl;
		Sleep(sleepTime);
		return false;
	}
	return true;
}

void makeCoffe(string name) {
	system("CLS");
	cout << "Your coffee is being prepared, please wait a bit..." << endl;
	progressBar();
	cout << "Now, take your "<< name << "." << endl;
    cout << "Have a nice day!" << endl;
    cups--;
    Sleep(sleepTime);
}

void progressBar() {
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
	if (cups == 0)
		return false;
	return true;

}	
	
bool checkBalance(double balance, double price) {
	if (balance < price) {
		return false;
	}else {
		return true;
	}
}

bool enteringServiceMod() 
{
    int pin = 0;

    printServiceEnterHeader();
    printServiceMenuHeader();
    pin = enterPIN();    
    if (!checkPIN(pin)){
    	system("cls");
        printServiceEnterHeader();
        printServiceMenuHeader();
        cout << "Error! Incorrect PIN." << endl;
        Sleep(sleepTime);
        return false;
    }
    return true;
}

bool logInServiceMod()
{
	int flag = 0;
    do{
		if (!enteringServiceMod()){
			flag++;
		}
		else
			break;
	} while(flag < 3);
	
	if (flag == 3){
		printFooter();
		cout << "You entered the wrong PIN 3 times." << endl; 
		cout << "The machine will be blocked, contact the service department." << endl;
		printFooter();
		return false;
	}
	return true;
}

void serviceMod(double cash)
{
	int serviceChoice = 0;
	
	while (true) 
	{
		printServiceMenuHeader();
		printChoiceServiceMenu(cash);
		printFooter();
		cin >> serviceChoice;

		if (serviceChoice == 1) {
    		printServiceMenuHeader();
    		printWithdrawingCash();
    		cash = 0.0;
		}
		else if (serviceChoice == 2) {
    		printServiceMenuHeader();
    		printCupsInfo();
    		while(!addCups()){
            	printServiceMenuHeader();
            	cout << "WARNING: The amount of cups cannot be more than " << MAXCUPS - cups << " and less or equal zero." << endl;
            	printCupsInfo();
			}
		}		
		else if (serviceChoice == 3) {
			system("cls");
			break; 
		}
		else {
    		printErrorInput();
		}
	}	
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
	system("cls");
    cout << "Service Menu" << endl;
    cout << "------------------" << endl;
}

void printFooter()
{
    cout << "------------------" << endl;
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
        Sleep(sleepTime/6);
        cout << ".";
    }
    cout << endl << "Cash withdrawn." << endl;
    cout << "Returning to Service Menu..." << endl;
    printFooter();
    Sleep(sleepTime);
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
