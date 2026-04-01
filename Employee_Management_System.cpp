#include<iostream>
using namespace std;
class Employee{
	private:
	int id;
	string name;
	float salary;
	int attendance;
	static int totalEmployees;
	public:
		Employee():id(0),name("null"),salary(0),attendance(0)
	{

}
		
	Employee(int i,string n,float s,int a):id(i),name(n),salary(s),attendance(a)
	{
	
	totalEmployees ++;
}
Employee(const Employee &e)
{
	name=e.name;
	id=e.id;
	salary=e.salary;
	attendance=e.attendance;
	totalEmployees ++;
}
   void setdata()
   {
   	cout<<"Enter your name :"<<endl;
   	cin.ignore();
   	getline(cin,name);
   	cout<<"Enter your id :"<<endl;
   	cin>>id;
   	cout<<"Enter your salary :"<<endl;
   	cin>>salary;
   	cout<<"Enter attendance :"<<endl;
   	cin>>attendance;
   	totalEmployees ++;
   }
   void display()
   {
   	cout<<"\n ID:"<<id;
   	cout<<"\nNAME :"<<name;
   	cout<<"\nSALARY:"<<salary;
   	cout<<"\nATTENDANCE :"<<attendance;
   }
   float calculateSalary()
   {
   	if(attendance>30 || attendance<0)
   	{
	   cout<<"invalid attendance "<<endl;
	   return 0;
	}
	float perday=salary/30;
	float finalsalary=perday*attendance;
	if (attendance>=28){
	
	cout<<"YOU GOT 1000 RUPEE BONUS "<<endl;
	 finalsalary+=1000;}
	return finalsalary;	   
   }
   static void showtotal()
   {
   	cout<<"total employees :"<<totalEmployees<<endl;
   }
};
int Employee::totalEmployees=0;
int main()
{
	Employee e[5];
	int choice,count=0;
	do{
		 cout << "\n===== MENU =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Calculate Salary\n";
        cout << "4. Show Total Employees\n";
        cout << "5. Copy First Employee\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
	
	switch(choice)
	{
	
	case 1: if(count<5){
	e[count].setdata();
	count++;}
	else {
		cout<<"limit reached "<<endl;
	}
	break;
	case 2: for(int i=0;i<count;i++)
	{
		e[i].display();
	}
	break;
	case 3: for(int i=0;i<count;i++){
	float result=e[i].calculateSalary();
	cout<<"Total salary of employee "<<i+1<<"="<<result<<endl;}
	break;
	case 4: Employee::showtotal();
	break;
	case 5: if(count>0&&count<5)
	{
		e[count]=e[0];
		count++;
		cout<<"First employee copied "<<endl;}
		else
		{
			cout<<"invalid copied"<<endl;
		}
	break;

    case 0:
            cout << "Exiting program..." << endl;
    break;
    default:
            cout << "Invalid choice!" << endl;
           }  
		  
	}while(choice != 0);
	return 0;
        	
}
