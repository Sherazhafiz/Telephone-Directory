//Implement telephone directory with following Functionalities using OOP and
// File Handling approach: Same First
//Name, Last Name, Phone Number, Email, City of member.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

fstream file("Q15.txt",ios::out);

class Contact{
	private:
		string  FirstName;
		string  LastName;
		string  TelephoneNumber;
		string  Email;
		string  City;
	public:
//		set function
		void setdata(){
			cout<<"enter the First Name: ";
			getline(cin>>ws,FirstName);
			cout<<"enter the Last Name: ";
			getline(cin,LastName);
			cout<<"enter the Telephone Number: ";
			getline(cin,TelephoneNumber);
			cout<<"enter the Email: ";
			getline(cin,Email);
			cout<<"enter the City: ";
			getline(cin,City);
			
			file<<FirstName<<" ";
			file<<LastName<<" ";
			file<<TelephoneNumber<<" ";
			file<<Email<<" ";
			file<<City<<endl;
		}
//		get function
		string getFirstName(){
			return FirstName;
		}
		
		string getLastName(){
			return LastName;
		}
		
		string getTelephoneNumber(){
			return TelephoneNumber;
		}
		
		
		string getEmail(){
			return Email;
		}
		string getCity(){
			return City;
		}
		
	
	//		display function	
	void display(){
		cout<<"The First Name is: "<<FirstName<<endl;
		cout<<"The Last Name is: "<<LastName<<endl;
		cout<<"The Telephone Number is: "<<TelephoneNumber<<endl;
		cout<<"The Email is: "<<Email<<endl;
		cout<<"The City is: "<<City<<endl;
	}
	//		search function	
	void search_FirstName(string str,int &num){
		if(str==FirstName){
			cout<<endl;
			cout<<" The First Name is: "<<FirstName<<endl;	
			cout<<" The Last Name is: "<<LastName<<endl;	
			cout<<" The Telephone Number is: "<<TelephoneNumber<<endl;	
			cout<<" The Email is: "<<Email<<endl;
			cout<<" The City is: "<<City<<endl;
			num=1;
			cout<<endl;
		}
	}

	void change_FirstName(string str,int &num ,int num2){
		if(str==FirstName){
			cout<<endl;
			
			cout<<"enter the First Name to change: ";
			getline(cin>>ws,FirstName);
			file<<"UPDATED FIRST NAME OF RECORD #"<<num2<<": "<<endl;
			file<<"record #"<<num2<<": "<<" ";
			file<<FirstName<<" ";
			file<<LastName<<" ";
			file<<TelephoneNumber<<" ";
			file<<Email<<" ";
			file<<City<<endl;
			num=1;
			cout<<endl;
		}
	}
	
	
	void search_city(string str,int &num){
		if(str==City){
			cout<<endl;
			cout<<" The First Name is: "<<FirstName<<endl;	
			cout<<" The Last Name is: "<<LastName<<endl;	
			cout<<" The Telephone Number is: "<<TelephoneNumber<<endl;	
			cout<<" The Email is: "<<Email<<endl;
			cout<<" The City is: "<<City<<endl;
			num=1;
			cout<<endl;
		}
	}	
	
	void change_city(string str,int &num ,int num2){
		if(str==City){
			cout<<endl;
			
			cout<<"enter the City to change: ";
			getline(cin>>ws,City);
			file<<"UPDATED FIRST NAME OF RECORD #"<<num2<<": "<<endl;
			file<<"record #"<<num2<<": "<<" ";
			file<<FirstName<<" ";
			file<<LastName<<" ";
			file<<TelephoneNumber<<" ";
			file<<Email<<" ";
			file<<City<<endl;
			num=1;
			cout<<endl;
		}
	}
	
};

	

int main (){
	string choice,str;
	int count,i,size=5;
	Contact PhoneDirectiory[size];
	if(!file){
	cout<<"error";
	}else{
		while(1){
			cout<<"Telephone Directory:"<<endl;
			cout<<"==================="<<endl;
			cout<<"1 TO Input Record:"<<endl;
			cout<<"2 TO Display All:"<<endl;
			cout<<"3 TO Search By First Name:"<<endl;
			cout<<"4 TO Search By city:"<<endl;
			cout<<"5 TO Update First Name:"<<endl;
			cout<<"6 TO Update Phone number:"<<endl;
			cout<<"7 TO Exit:"<<endl;
			cout<<"Enter your choice: "<<endl;
			getline(cin,choice);
			
			if(choice=="1"){
				for(int i=0;i<size;i++){
					cout<<"enter the number of record: "<<endl;
					cin>>i;
					if(i<=size){
						cout<<"Enter the value for Record :"<<endl;
						file<<"Record #"<<i<<" : ";
						PhoneDirectiory[i-1].setdata();
						break;	
					}else{
						cout<<"Record Does Not Exist!\nPress enter to continue"<<endl;
						cin.ignore();
						cin.get();
						break;
					}
				}
			}
			if(choice=="2"){
				fstream infile("Q15.txt");
				string str1;
				while(!infile.eof()){
					getline(infile,str1);
					cout<<str1<<endl;
				}
				cout<<"Contact that are Exist!"<<endl;
			}
			
			
			if(choice=="3"){
				int flag=0;
				string searchstr;
				cout<<"Enter the FIRST NAME to seacrh:";
				getline(cin,searchstr);
				for(int i=0;i<size;i++){
					PhoneDirectiory[i].search_FirstName(searchstr,flag);
				}
				if(flag==0){
				cout<<"DOES NOT EXIST"<<endl;
				}
			}
			
			
			if(choice=="4"){
				int flag=0;
				string searchstr;
				cout<<"Enter the City to seacrh:";
				getline(cin,searchstr);
				for(int i=0;i<size;i++){
					PhoneDirectiory[i].search_city(searchstr,flag);
				}
				if(flag==0){
				cout<<"DOES NOT EXIST"<<endl;
				}
			}
			
			if(choice=="5"){
				int flag=0;
				string searchstr ;
				cout<<"Enter the FIRST NAME to seacrh:";
				getline(cin,searchstr);
				for(int i=0;i<size;i++){
					PhoneDirectiory[i].change_FirstName(searchstr,flag,i+1);
				}
				if(flag==0){
					cout<<"DOES NOT EXIST"<<endl;
				}
				
			}
			if(choice=="6"){
				int flag=0;
				string searchstr ;
				cout<<"Enter the City to seacrh:";
				getline(cin,searchstr);
				for(int i=0;i<size;i++){
					PhoneDirectiory[i].change_city(searchstr,flag,i+1);
				}
				if(flag==0){
				cout<<"DOES NOT EXIST"<<endl;
				}
			}
			if(choice=="7"){
				break;
			}
			if(choice>="8"){
				cout<<"INVALID CHOICE"<<endl;
				break;
			}
		}
	}
	file.close();
	return 0;
}
