#include<iostream>
using namespace std;
class SavingsAccount
{
public:
	SavingsAccount(double value);		static float annualInterestRate;
	void calculateMonthlyInterest();
	static void modifyIntererestRate(float value);
	float GetBalance() const { return savingsBalance; }
private:
	// Each member of the class contains a private data member 
	// savingsBalance indicating the amount the saver currently has 
	// on deposit.
	float savingsBalance;
};

// copy constructor to initialize the value at instantiation
SavingsAccount::SavingsAccount(double value)
{
	savingsBalance = value;
}

// Use a static data member annualInterestRate to store the annual interest
// rate for each of the savers. 
float SavingsAccount::annualInterestRate = 0;

// Provide member function calculateMonthlyInterest that calculates the 
// monthly interest by multiplying the savingsBalance by annualInterestRate
// divided by 12 and then adds this interest to savingsBalance.
void SavingsAccount::calculateMonthlyInterest()
{
	savingsBalance += ((savingsBalance * annualInterestRate) / 12);
}

//Provide a static member function modifyIntererestRate that sets the 
// static annualInterestRate to a new value. 
void SavingsAccount::modifyIntererestRate(float value)
{
	annualInterestRate = value;
}




int main()
{
	// Instantiate two different objects of class SavingsAccount, saver1 
	// and saver2, with balances of $2000.00 and $3000.00, respectively.
	SavingsAccount saver1(2000.00);
	SavingsAccount saver2(3000.00);

	// Set the annualInterestRate to 3%.
	SavingsAccount::modifyIntererestRate(3);

	cout << "Saver 1 Savings Balance: $" << saver1.GetBalance() << endl;
	cout << "Saver 2 Savings Balance: $" << saver2.GetBalance() << endl;
	cout << endl;

	// Then calculate the monthly interest and print the new balances for 
	// each of the savers. 
	saver1.calculateMonthlyInterest();
	cout << "Saver 1 Savings Balance: $" << saver1.GetBalance() << endl;
	saver2.calculateMonthlyInterest();
	cout << "Saver 2 Savings Balance: $" << saver2.GetBalance() << endl;

	cout << endl;

	// Then set the annualInterestRate to 4%
	SavingsAccount::modifyIntererestRate(4);

	// and calculate the next month's interest and print the new balances 
	// for each of the savers
	saver1.calculateMonthlyInterest();
	cout << "Saver 1 Savings Balance: $" << saver1.GetBalance() << endl;
	saver2.calculateMonthlyInterest();
	cout << "Saver 2 Savings Balance: $" << saver2.GetBalance() << endl;

	cout << endl;



	system("PAUSE");
	return 0;
}
