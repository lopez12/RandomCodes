#include <iostream>
using namespace std;

class account
{
public: double balance;
		account(double balance_contrc = 0);
		void credit(double add);
		void debit(double subtract);
		double getBalance(void);

};
account::account(double balance_contrc)
{
	if (balance_contrc >= 0.0)
		balance = balance_contrc;
	else
	{
		cout << "Invalid balance";
		balance = 0.0;
	}
}


void account::credit(double add)
{
	balance += add;
}
void account::debit(double subtract)
{
	if (subtract > balance)
		cout << "debit amount exceeded account balance";
	else
		balance -= subtract;
}

double account::getBalance(void)
{
	return balance;
}

class savingsAccount :public account
{
	double intRate;

public:
	savingsAccount(double intRate_const, double balance_contrc) :account(balance_contrc)
	{
		intRate = intRate_const;
	}
	double calculateInterest(void);
};

double savingsAccount::calculateInterest(void)
{
	return (balance*intRate);

}

class checkingAccount : public account
{
	double fee;
public : checkingAccount(double fee_const, double balance_constrc) :account(balance_constrc)
		{
			fee = fee_const;
		}
		 void debit(double subtract)
		 {
			 if (subtract > balance)
				 cout << "debit amount exceeded account balance";
			 else
				 balance -= (subtract + fee);
	}
};

int main()
{
   
	account *Cuenta1;
	int Amount2Withdraw;
	int Amount2Deposit;
	
	
	savingsAccount CuentasSavings[3] = {savingsAccount(0.5,1500),savingsAccount(0.2,3000),savingsAccount(0.1,1000)};
	//checkingAccount CuentasChecking[3];
	
	Cuenta1 = &CuentasSavings[0];
	cout << "Cuanto Deseas Sacar? \n";
	cin >> Amount2Withdraw;
	Cuenta1->debit(Amount2Withdraw);
	
	cout << "Cuanto Deseas Depositar? \n";
	cin >> Amount2Deposit;
	Cuenta1->credit(CuentasSavings[0].calculateInterest() + Amount2Deposit);
	
	//Cuenta1->credit(Cuenta1->calculateInterest());
	cout << "First Account Balance: ";
	cout << Cuenta1->getBalance();
	cout << '\n';
	
	Cuenta1++;
	Cuenta1++;
	
	cout << "Cuanto Deseas Sacar? \n";
	cin >> Amount2Withdraw;
	Cuenta1->debit(Amount2Withdraw);
	
	cout << "Cuanto Deseas Depositar? \n";
	cin >> Amount2Deposit;
	Cuenta1->credit(CuentasSavings[1].calculateInterest() + Amount2Deposit);
	
	cout << "Second Account Balance: ";
	cout << Cuenta1->getBalance();
	cout << '\n';
	
	Cuenta1++;
	Cuenta1++;
	
	cout << "Cuanto Deseas Sacar? \n";
	cin >> Amount2Withdraw;
	Cuenta1->debit(Amount2Withdraw);
	
	cout << "Cuanto Deseas Depositar? \n";
	cin >> Amount2Deposit;
	Cuenta1->credit(CuentasSavings[2].calculateInterest() + Amount2Deposit);
	
	cout << "Third Account Balance: ";
	cout << Cuenta1->getBalance();
	cout << '\n';
	
	
	delete Cuenta1;
	
	/*savingsAccount Account1(.5, 1500);
	Account1.credit(Account1.calculateInterest());
	cout << Account1.getBalance();*/

}

