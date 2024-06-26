#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;



class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};

void account::create_account()
{
	system("CLS");
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>acno;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Created..";
}

void account::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}



void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

int main()
{
	char ch;
	int num;
	do
	{
	system("CLS");
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t8. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_account();
			break;
	/*	case '2':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;*/
		case '4':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		/*case '5':
			display_all();
			break;*/
		case '6':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\t\t\tThankyou for using come again later Namste";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not open!! press any key .....";
		return;
	}
		cout<<"n\\t\t\tBALANCE DETAILS\n";
		while(inFile.read((char*)&ac,sizeof(account)))
		{
			if(ac.retacno()==n)
			{
				ac.show_account();
				flag=true;
			}
		}
		inFile.close();
		if(flag==false)
		{
			cout<<"\n\n\t\t\tAccount number does not exist ";
		}
	}
	
	
	
	
	void modify_account(int n )
	{
		account ac;
		bool flag=false;
			ifstream inFile;
			fstream outFile;
			inFile.open("account.dat",ios::binary);//inFile.open("account.dat",ios::binary);
			outFile.open("temp.dat",ios::binary|ios::out);
			
			if(!inFile)
			{
				cout<<"File could not be open ! press any key.... ";
				return;
			}
			
			while(inFile.read((char *)&ac,sizeof(ac)))
			{
			
			if(ac.retacno()!=n)         
			{
				outFile.write((char *) &ac, sizeof(account));
			}
		 	else
			{
			flag=true;
				ac.create_account();
				outFile.write((char *) &ac, sizeof(account));
			}
		}	
		
			inFile.close();
			outFile.close();
			remove("account.dat");
			rename("temp.dat","account.dat");
			if(flag==true)
			cout<<"\n\nRecord modified..";
		else{
			cout<<"account no.does not exist";
		}
		
		}
		
		
	
		
		
		
		
		void delete_account(int n)
		{
			account ac;
			ifstream inFile;
			fstream outFile;
			inFile.open("account.dat",ios::binary);//inFile.open("account.dat",ios::binary);
			outFile.open("temp.dat",ios::binary|ios::out);
			
			//cout<<"enter the account number which you want to delete ";
			//cin>>n;
			
			if(!inFile)
			{
				cout<<"File could not be open ! press any key.... ";
				return;
			}
			
			while(inFile.read((char *)&ac,sizeof(ac)))
			{
			
			if(ac.retacno()!=n)           //if(account.ac!=n)
			{
				outFile.write((char *) &ac, sizeof(account));
			}
		}	
		
			inFile.close();
			outFile.close();
			remove("account.dat");
			rename("temp.dat","account.dat");
			cout<<"\n\nTRecord deleted";
			}
