#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int c;
	cout<<"\t\t\t_______________________________________________________\n\n\n";
	cout<<"\t\t\t                  Welcome to the Log in Page            \n\n\n";
	cout<<"\t\t\t ___________________      Menu            _________________\n\n\n";
	cout<<"                                                                 \n\n";
	cout<<"\t)| Press 1 to LOGIN            |"<<endl;
	cout<<"\t)| Press 2 to REGISTER            |"<<endl;
	cout<<"\t)| Press 3 to If you forgot PASSWORD            |"<<endl;
	cout<<"\t)| Press 4 to EXIT            |"<<endl;
	cout<<"\n\t\t\t Please enter your choice : ";
	cin>>c;
	cout<<endl;
	
	switch(c)
	{
		case 1:
			login();
			break;
			
		case 2:
			registration();
			break;
			
		case 3:
			forgot();
			break;
			
		case 4:
		    cout<<"\t\t\t Thankyou! \n\n";
			break;
			
		default:
			system("cls");
		    cout<<"\t\t\t Please select among the options given \n"<<endl;
			main();				
	}	
	
}

void login()
{
	int count;
	string userId, password, Id, pass;
	system("cls");
	cout<<"\t\t\t Please enter the Username and Password : "<<endl;
	cout<<"\t\t\t USERNAME ";
	cin>>userId;
	cout<<"\t\t\t PASSWORD ";
	cin>>password;
	
	ifstream input("records.txt");
	
	while(input>>Id>>pass)
	{
		if(Id==userId && pass==password)
		{
			count=1;
			system("cls");
			
		}
	}
	input.close();
	
	if(count==1)
	{
		cout<<userId<<"\n Your LOGIN is successful \n Thanks for logging in ! \n";
		main();
	}
	else{
		cout<<"\n LOGIN ERROR \n Please check your Username and Password \n";
		main();
	}
}
void registration()
{
	int count;
	string ruserId, rpassword, rId, rpass;
	system("cls");
	cout<<"\t\t\t Enter the Username : ";
	cin>>ruserId;
	cout<<"\t\t\t Enter password : ";
	cin>>rpassword;
	
	ofstream f1("records.txt", ios::app); //offstream writes inside the file
	f1<<ruserId<<' '<<rpassword<<endl;
	system("cls");;
	cout<<"\n\t\t\t Registrationnis successfull! \n";
	main();	
}
void forgot()
{
  int option;
  system("cls");
  cout<<"\t\t\t You forgot the password? No worries \n";
  cout<<"Press 1 to search your id by username "<<endl;	
  cout<<"Press 2 to go back to the main menu "<<endl;
  cout<<"\t\t\t Enter your choice : "<<endl;
  cin>>option;
  switch(option)
  {
  	case 1:
  		{
  			int count=0;
  			string suserId,sId,spass;
  			cout<<"\n\t\t\t Enter the username you remember : ";
  			cin>>suserId;
  			
  			ifstream f2("records.txt");
  			while(f2>>sId>>spass)
			  {
			  	if(sId==suserId)
				  {
				  	count=1;
				  }
			  }
			  f2.close();
			  if(count==1)
			  {
			  	cout<<"\n\n Your account is found! \n";
			  	cout<<"\n\n Your password is : "<<spass;
			  	main();
			  }
			  else{
			  	cout<<"\n\t Sorry! Your account is not found! \n";
			  	main();
			  }
			  break;
		  }
	case 2:
		{
			main();
		}
		default:
			cout<<"/t/t/t Wrong choice ! Please try again "<<endl;
			forgot();
  	
  }	
}

