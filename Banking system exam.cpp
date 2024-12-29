#include <iostream>
#include <string>
using namespace std;

class BankAccount 
{
public:
    int accNum;
    string accHname;
    float balance;

    BankAccount() :accNum(0), balance(0)
    {
        accHname="";
    }

    void getDetails()
    {
        cout<<"Enter Account Number: ";
        cin>>accNum;
        cout<<"Enter Account Holder Name: ";
        cin.ignore();  
        getline(cin, accHname);
        cout<<"Enter Initial Balance: ";
        cin>>balance;
    }

    void display() 
    {
        cout<<"Account Number: "<<accNum<<endl;
        cout<<"Account Holder Name: "<<accHname<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    float calculateInterest() 
    {
        return 0;
    }

    void withdraw(float amount)
    {
        if (balance>=amount)
        {
            balance -= amount;
            cout<<"Withdrawal successful! New balance: "<<balance<<endl;
        } 
        else 
        {
            cout<<"Insufficient balance!"<<endl;
        }
    }

    virtual ~BankAccount()=default;
};

class SavingsAccount : public BankAccount
{
public:
    float intRate;

    void getDetails()
    {
        BankAccount::getDetails();
        cout<<"Enter Interest Rate: ";
        cin>>intRate;
    }

    void display()
    {
        BankAccount::display();
        cout<<"Interest Rate: "<<intRate<<"%"<<endl;
    }

    float calculateInterest()
    {
        return(balance*intRate)/100;
    }
};

class CheckingAccount : public BankAccount
{
public:
    float overdraftLimit;

    void getDetails()
    {
        BankAccount::getDetails();
        cout<<"Enter Overdraft Limit: ";
        cin>>overdraftLimit;
    }

    void display() 
    {
        BankAccount::display();
        cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
    }

    void withdraw(float amount)
    {
        if (balance+overdraftLimit>=amount) 
        {
            balance-=amount;
            cout<<"Withdrawal successful! New balance: "<<balance<<endl;
        } 
        else
        {
            cout<<"Exceeds overdraft limit!"<<endl;
        }
    }
};

class FDAcc: public BankAccount
{
public:
    float intRate;
    float term;

    void getDetails()
    {
        BankAccount::getDetails();
        cout<<"Enter Term (duration in months): ";
        cin>>term;
        cout<<"Enter Interest Rate: ";
        cin>>intRate;
    }

    void display()  
    {
        BankAccount::display();
        cout<<"Term: "<<term<<" months"<<endl;
        cout<<"Interest Rate: "<<intRate<<"%"<<endl;
        cout<<"Interest: " << calculateInterest() << endl;
    }

    float calculateInterest() 
    {
        return(balance*intRate*term)/(100 * 12);
    }
};

int main() 
{
    BankAccount* bank[50]; 
    int mainChoice, accountChoice, accountCount=0;
    BankAccount* account=nullptr;  
    do 
    {
        cout<<"==== MAIN MENU ===="<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"1. CREATE ACCOUNT"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>mainChoice;

        switch(mainChoice)
        {
        case 1:
    
            cout<<"CREATE ACCOUNT "<<accountCount+1<<endl;
            cout<<"Enter Account type:" << endl;
            cout<<"1. Saving Account" << endl;
            cout<<"2. Checking Account" << endl;
            cout<<"3. Fixed Deposit Account" << endl;
            cout<<"Enter your choice: ";
            cin>>accountChoice;

            switch(accountChoice)
            {
            case 1:
                account=new SavingsAccount();
                account->getDetails();
                break;
            case 2:
                account=new CheckingAccount();
                account->getDetails();
                break;
            case 3:
                account=new FDAcc;
                account->getDetails();
                break;
            default:
                cout<<"Invalid choice!"<<endl;
                continue;
            }

            bank[accountCount]=account;
            accountCount++;

            int choice;
            float amount;
            do {
                cout<<" BANK MANAGEMENT SYSTEM "<<endl;
                cout<<"1. Deposit money"<<endl;
                cout<<"2. Withdraw money"<<endl;
                cout<<"3. Calculate Interest rate"<<endl;
                cout<<"4. Display account"<<endl;
                cout<<"0. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;

                switch(choice)
                {
                case 1:
                    cout<<"Enter the amount to deposit: ";
                    cin>>amount;
                    account->balance+=amount;
                    cout<<"Deposited successfully."<<endl;
                    break;

                case 2:
                    cout<<"Enter the amount to withdraw: ";
                    cin>>amount;
                    account->withdraw(amount);
                    break;

                case 3:
                    cout<<"Interest: "<<account->calculateInterest()<<endl;
                    break;

                case 4:
                    account->display();
                    break;

                case 0:
                    cout<<"Exiting system..."<<endl;
                    break;

                default:
                    cout<<"Invalid choice."<<endl;
                }
            } while(choice!=0);

            
            delete account;
            break;

        case 0:
            cout<<"Exiting system..."<<endl;
            break;

        default:
            cout<<"Invalid choice!"<<endl;
        }
    } while (mainChoice!=0);

    return 0;
}
________________________________________________________________________________________________
#include <iostream>
#include <string>
using namespace std;

class BankAccount 
{
public:
    int accNum;
    string accHname;
    float balance;

    BankAccount() :accNum(0), balance(0),accHname("") {}
    
    virtual void getDetails()
    {
        cout<<"Enter Account Number: ";
        cin>>accNum;
        cout<<"Enter Account Holder Name: ";
        cin.ignore();  
        getline(cin, accHname);
        cout<<"Enter Initial Balance: ";
        cin>>balance;
    }

    virtual void display() 
    {
        cout<<"Account Number: "<<accNum<<endl;
        cout<<"Account Holder Name: "<<accHname<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    virtual float calculateInterest() 
    {
        return 0;
    }

    void withdraw(float amount)
    {
        if (balance>=amount)
        {
            balance -= amount;
            cout<<"Withdrawal successful! New balance: "<<balance<<endl;
        } 
        else 
        {
            cout<<"Insufficient balance!"<<endl;
        }
    }

    virtual ~BankAccount()=default;
};

class SavingsAccount : public BankAccount
{
public:
    float intRate;

    void getDetails()
    {
        BankAccount::getDetails();
        cout<<"Enter Interest Rate: ";
        cin>>intRate;
    }

    void display()
    {
        BankAccount::display();
        cout<<"Interest Rate: "<<intRate<<"%"<<endl;
    }

    float calculateInterest()
    {
        return(balance * intRate) / 100;
    }
};

class CheckingAccount : public BankAccount
{
public:
    float overdraftLimit;

    void getDetails()
    {
        BankAccount::getDetails();
        cout<<"Enter Overdraft Limit: ";
        cin>>overdraftLimit;
    }

    void display() 
    {
        BankAccount::display();
        cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
    }

    void withdraw(float amount)
    {
        if (balance+overdraftLimit>=amount) 
        {
            balance-=amount;
            cout<<"Withdrawal successful! New balance: "<<balance<<endl;
        } 
        else
        {
            cout<<"Exceeds overdraft limit!"<<endl;
        }
    }
     float calculateInterest()
     {
         return 0;
     }
};

class FDAcc: public BankAccount
{
public:
    float intRate;
    float term;

    void getDetails()
    {
        BankAccount::getDetails();
        cout<<"Enter Term (duration in months): ";
        cin>>term;
        cout<<"Enter Interest Rate: ";
        cin>>intRate;
    }

    void display()  
    {
        BankAccount::display();
        cout<<"Term: "<<term<<" months"<<endl;
        cout<<"Interest Rate: "<<intRate<<"%"<<endl;
        cout<<"Interest: " << calculateInterest() << endl;
    }

    float calculateInterest() 
    {
        return(balance * intRate * term) / (100 * 12);
    }
};

int main() 
{
    BankAccount* bank[50]; 
    int mainChoice, accountChoice, accountCount=0;
    BankAccount* account=nullptr;  
    do 
    {
        cout<<"==== MAIN MENU ===="<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"1. CREATE ACCOUNT"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>mainChoice;

        switch(mainChoice)
        {
        case 1:
    
            cout<<"CREATE ACCOUNT "<<accountCount+1<<endl;
            cout<<"Enter Account type:" << endl;
            cout<<"1. Saving Account" << endl;
            cout<<"2. Checking Account" << endl;
            cout<<"3. Fixed Deposit Account" << endl;
            cout<<"Enter your choice: ";
            cin>>accountChoice;

            switch(accountChoice)
            {
            case 1:
                account=new SavingsAccount();
                account->getDetails();
                break;
            case 2:
                account=new CheckingAccount();
                account->getDetails();
                break;
            case 3:
                account=new FDAcc;
                account->getDetails();
                break;
            default:
                cout<<"Invalid choice!"<<endl;
                continue;
            }

            bank[accountCount]=account;
            accountCount++;

            int choice;
            float amount;
            do {
                cout<<" BANK MANAGEMENT SYSTEM "<<endl;
                cout<<"1. Deposit money"<<endl;
                cout<<"2. Withdraw money"<<endl;
                cout<<"3. Calculate Interest rate"<<endl;
                cout<<"4. Display account"<<endl;
                cout<<"0. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;

                switch(choice)
                {
                case 1:
                    cout<<"Enter the amount to deposit: ";
                    cin>>amount;
                    account->balance+=amount;
                    cout<<"Deposited successfully."<<endl;
                    break;

                case 2:
                    cout<<"Enter the amount to withdraw: ";
                    cin>>amount;
                    account->withdraw(amount);
                    break;

                case 3:
                    cout<<"Interest: "<<account->calculateInterest()<<endl;
                    break;

                case 4:
                    account->display();
                    break;

                case 0:
                    cout<<"Exiting system..."<<endl;
                    break;

                default:
                    cout<<"Invalid choice."<<endl;
                }
            } while(choice!=0);
            
            delete account;
            break;

        case 0:
            cout<<"Exiting system..."<<endl;
            break;

        default:
            cout<<"Invalid choice!"<<endl;
        }
    } while (mainChoice!=0);

    return 0;
}
