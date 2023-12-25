#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<conio.h>  //using for console input or output use in control panal			
using namespace std;
class Uni_management 
{
	protected:	
	string s_fname,s_lname;
	string s_contact,email;	
	public:
	Uni_management ()
	{
		s_fname="";
		s_lname="";
		s_contact="";
	}
	void setFName(string n)
	{
		s_fname=n;
	}
	string getFName()
	{
		return s_fname;
	}
	void setLName(string n)
	{
		s_lname=n;
	}
	string getLName()
	{
		return s_lname;
	}
	void setContact(string cont)
	{
		s_contact=cont;
		}
		string getContact()
		{
			return s_contact;
		}
	
	void setemail(string em)
	{
		email=em;
		}
		string getemail()
		{
			return email;
		}
	virtual void control_panel()=0;
	virtual void insert()=0; 
	virtual void search()=0;
	virtual void update()=0;
	virtual void del()=0;
	virtual void show()=0;
	virtual void Voucher()=0;
	virtual void backup()=0;
	~Uni_management ()
		{
		
		}
		
};

//SMD ->Student managment system
class SMD: public Uni_management
{
	private:	
		string s_class,s_smester;
		long int s_roll;
		long int s_fees;
		
	public:
	SMD():Uni_management()
	{
		s_class="";
		s_roll=0;
		s_fees=0;
		s_smester="";
	}
	void setClass(string c)
	{
		s_class=c;
		}
	string getClass()
	{
		return s_class;
	}
	void SetSemester(string sem)
	{
		s_smester=sem;
	}
	string getSemester()
	{
		return s_smester;
	}
	void setRoll(long int r)
		{
		s_roll=r;
		}
	int getRoll()
		{
		return s_roll;
		}
	void setFee(long int f)
		{
		s_fees=f;
		}
	int getFee()
		{
		return s_fees;
		}
	
	void control_panel();
	void insert(); 
	void search();
	void update();
	void del();
	void show();
	void Voucher();
	void backup();
	~SMD()
		{
		
	}
		
};
void SMD::control_panel()
{
	
	system("cls");
	cout<<"\t\t\t\t    ******************************************\n";
	cout<<"\t\t\t\t    ||| STUDENT DATABASE MANAGEMENT SYSTEM |||\n";
	cout<<"\t\t\t\t    ******************************************\n";
	cout<<"\n\n1. Add New  Student Date";
	cout<<"\n\n2. Find     Student Data";
	cout<<"\n\n3. Modified Data";
	cout<<"\n\n4. Delete   Data";
	cout<<"\n\n5. Show All Recocrd";
	cout<<"\n\n6. Print    Fee Voucher";
	cout<<"\n\n7. Data File Backup";
	cout<<"\n\n8. Exit";
	cout<<"\n\n9. Enter Your Choice = ";
}
//function for insert recocd. 
void SMD::insert()	
{

	system("cls");
	ofstream file;
	cout<<"\t\t\t\t    ***************************************\n";
	cout<<"\t\t\t\t    ||||||||||| Add Student Data ||||||||||\n";
	cout<<"\t\t\t\t    ***************************************\n";
	cout<<"\n\n\t\t Enter First Name = ";
	cin>>s_fname;
	cout<<"\n\n\t\t Enter Last Name = ";
	cin>>s_lname;
	cout<<"\n\n\t\t Enter Roll Number (Integer type) = ";
	cin>>s_roll;
	cout<<"\n\n\t\t Enter Class = ";
	cin>>s_class;
	cout<<"\n\n\t\t Enter Contact Number (11 Digits)= ";
	cin>>s_contact;
	cout<<"\n\n\t\t Enter Email= ";
	cin>>email;
	cout<<"\n\n\t\t Enter Semester Fee (Integer type) = ";
	cin>>s_fees;
	cout<<"\n\n\t\t Enter Semester = ";
	cin>>s_smester;
	cout<<"\n\nRecord Sucessfuly Added ......";
	file.open("project.txt",ios::out|ios::app);		// :: means rasolation  oprater
	file<<s_fname<<"      "<<s_lname<<"      "<<s_roll<<"      "<<s_class<<"      "<<s_contact<<"      "<<s_fees<<"      "<<s_smester<<"      "<<email<<"\n";
	file.close();
}

//function for search information
void SMD::search()
{
	int roll;
	int count=0;
	system("cls");
	ifstream file;
	cout<<"\t\t\t\t    ***************************************\n";
	cout<<"\t\t\t\t    |||||||| Search Student Record ||||||||\n";
	cout<<"\t\t\t\t    ***************************************\n";
	file.open("project.txt",ios::in);
	if(!file)
	{
		cout<<"\n\nFile dose not exist....."<<endl;
	}
	else
		{
			cout<<"Enter Roll No. to Find Student Information: ";
			cin>>roll;
			file>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
			while(!file.eof())
			{
				if(roll==s_roll )
				{
					cout<<"\n\n First Name    = "<<s_fname;
					cout<<"\n\n Last  Name    = "<<s_lname;
					cout<<"\n\n Roll  Number  = "<<s_roll;
					cout<<"\n\n Class         = "<<s_class;
					cout<<"\n\n Semester      = "<<s_smester;
					cout<<"\n\n Semester Fee  = "<<s_fees;
					cout<<"\n\n Contact Number= "<<s_contact;
					cout<<"\n\n Email  Address= "<<email;
					cout<<"\n\n\n Press any key go to main manu ....."<<endl;
					count++;
				
					}
				file>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
				
			}
		file.close();
		if(count == 0)
			{
				cout<<"\n\nRecord not Found.\nPlease try with valid information.";
				cout<<"\nPress any key go to main manu ....."<<endl;
			}
	
}
}

//function for update information	
void SMD::update()
{
	system("cls");
	int count=0;
	int roll;
	fstream exfile,newfile;	
	cout<<"\t\t\t\t    **************************************\n";
	cout<<"\t\t\t\t    |||||||| Update Student Record ||||||||\n";
	cout<<"\t\t\t\t    **************************************\n";
	exfile.open("project.txt",ios::in);
	newfile.open("project1.txt",ios::app|ios::out);
	if(!exfile)
		{
			cout<<"\n\n\nFile dose not exist....."<<endl;
		}
		else
			{
				cout<<"Enter Roll No. to Update Student Information: ";
				cin>>roll;
				while(!exfile.eof())
				{
					exfile>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
					if(roll == s_roll)
					{
						cout<<"\n Old First Name    = "<<s_fname;
						cout<<"\n Old Last  Name    = "<<s_lname;
						cout<<"\n Old Roll  Number  = "<<s_roll;
						cout<<"\n Old Class         = "<<s_class;
						cout<<"\n Old Semester Fee  = "<<s_fees;
						cout<<"\n Old Semester      = "<<s_smester;
						cout<<"\n Old Contact Number= "<<s_contact;
						cout<<"\n Old Email Address = "<<email;
						//start update data
						cout<<"\n\n\t\tEnter Semester Fee = ";
						cin>>s_fees;
						cout<<"\n\n\t\tEnter Semester = ";
						cin>>s_smester;
						cout<<"\n\n\t\tEnter New Contact Number (11 Digits) = ";
						cin>>s_contact;
						cout<<"\n\n\t\tEnter New Email Address = ";
						cin>>email;
						newfile<<s_fname<<"      "<<s_lname<<"      "<<s_roll<<"      "<<s_class<<"      "<<s_contact<<"      "<<s_fees<<"      "<<s_smester<<"      "<<email<<"\n";
						count++;
						exfile>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
						cout<<"\n\n Press any key go to main manu ....."<<endl;		
					}
					else
						newfile<<s_fname<<"      "<<s_lname<<"      "<<s_roll<<"      "<<s_class<<"      "<<s_contact<<"      "<<s_fees<<"      "<<s_smester<<"      "<<email<<"\n";
						
						}
					if(count == 0)
						{
							cout<<"\n\nRecord not Found.\nPlease try with valid information.......";
							cout<<"\nPress any key go to main manu ....."<<endl;
						}
	}
	exfile.close();
	newfile.close();
	remove("project.txt");
	rename("project1.txt","project.txt");
}
//function for Delete information
void SMD::del()
{
	system("cls");
	int count=0;  //count is for condition to check input is valid
	static int roll;
	fstream exfile,newfile;	
	cout<<"\t\t\t\t    **********************************************\n";
	cout<<"\t\t\t\t    ||||||||| Delete Student Information |||||||||\n";
	cout<<"\t\t\t\t    **********************************************\n";
	exfile.open("project.txt",ios::in);
	newfile.open("project1.txt",ios::app|ios::out);
	if(!exfile)
		{
			cout<<"\n\nFile dose not exist....."<<endl;
		}
		else
		{
			cout<<"Enter Roll No. to Delete Student Information: ";
			cin>>roll;
			exfile>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
			while(!exfile.eof())
			{
					
				//	exfile>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;	
			  if(roll == s_roll)
				{
				
					cout<<"Record Deleted Successfuly...............";
					cout<<"\n\nPress any key go to main manu..........."<<endl;
					count++;		
				}
				else
				newfile<<s_fname<<"      "<<s_lname<<"      "<<s_roll<<"      "<<s_class<<"      "<<s_contact<<"      "<<s_fees<<"      "<<s_smester<<"      "<<email<<"\n";
		     	exfile>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;				
					
	}
	if(count == 0)
		{
			cout<<"\n\nRecord not Found.\nPlease try with valid information.......";
			cout<<"\nPress any key go to main manu .............."<<endl;
		}
	}
	exfile.close();
	newfile.close();
	remove("project.txt");
	rename("project1.txt","project.txt");
	
	
}
//function for Show All information
void SMD::show()
{

	//use system("Cls") to clear screen.
	int total;
	system("cls");
	ifstream file;
	cout<<"\t\t\t\t    ********************************************\n";
	cout<<"\t\t\t\t    |||||||||||| Total Student Data ||||||||||||\n";
	cout<<"\t\t\t\t    ********************************************\n";
	file.open("project.txt",ios::in);
	if(!file){
		cout<<"\n\nFile dose not exist....."<<endl;
		}
		else 
			{
				cout<<"First Name	Last Name	Roll No.	Class	FEEs	Semester	Contact No.	Email Address "<<endl;
				while (true) {
					file>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
				    if (file.eof()) {     
				        break;            
				    }
				    cout<<s_fname<<"\t\t"<<s_lname<<" \t\t"<<s_roll<<"\t\t"<<s_class<<"\t"<<s_fees<<"\t"<<s_smester<<"\t\t"<<s_contact<<"\t"<<email<<"\n";
					//total++;
				   
				}
			//	cout<<"\n\nTotal Students are : "<<total;
				cout<<"\nPress any key go to main manu .....";
	}
	file.close();
}

//function to print voucher 
void SMD::Voucher()
{
	//use system("Cls") to clear screen.
	system("cls");
	ifstream file;
	cout<<"\t\t\t\t    ********************************************\n";
	cout<<"\t\t\t\t    |||||||||||| Print Fee Vouchers ||||||||||||\n";
	cout<<"\t\t\t\t    ********************************************\n";
	file.open("project.txt",ios::in);
	if(!file){
	cout<<"\n\nFile dose not exist....."<<endl;
	}
	else 
	{
		int count=0,roll;
		long int instalment;
		char con; //con->Instalment condition
		cout<<"\nEnter Roll Number to Print Fee Voucher:";
		cin>>roll;
		cout<<"\nEnter (H) For Instalment Or (F) For Full Fee:";
		cin>>con;
		system("cls");
		file>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
		while(!file.eof())
		{
			file>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
			
			if(roll==s_roll)
			{
				cout<<"\n\t--------LAHORE  GARRISON   UNIVERSITY--------";
				cout<<"\n\t--------Sector C,DHA Phase-VI  Lahore--------";
				// current date/time with retun value(0) based on current system
				string arr[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
				time_t now = time(0);
				tm *ltm = localtime(&now);
				cout<<"\n\t\t\t\tIssue Date:"<< ltm->tm_mday<< "/"<<arr[ltm->tm_mon]<<  "/" << 1900 + ltm->tm_year;
				now = time(0)+(10*24*60*60);
				tm *ltm2 = localtime(&now);
				cout<<"\n\t\t\t\tDue   Date:"<< ltm2->tm_mday<<"/"<<arr[ltm2->tm_mon]<<"/"<< 1900 + ltm2->tm_year;
				cout<<"\n\n\tFirst Name:"<<s_fname;
				cout<<"\n\n\tLast    Name:"<<s_lname;
				cout<<"\n\n\tRoll No :"<<s_roll;
				cout<<"\n\n\tSemester:"<<s_smester;
				cout<<"\n\n\tEmail Address:"<<email;
				if(con=='F'||con=='f')
					{
						cout<<"\n\n\n\tTotal   Fee:"<<s_fees;
						cout<<"\n\n\tAmount Paid Now:"<<s_fees;
					}
				if(con=='H'||con=='h')
				{
					cout<<"\n\n\n\tTotal   Fee:"<<s_fees;
					instalment=s_fees/2;		
					cout<<"\n\n\tAmount Paid Now:"<<instalment;	
					cout<<"\n\n\tRemaining Balance:"<<instalment;
				}
					cout<<"\n\n\n\tRs 20 / day to be charged after due date.";
					cout<<"\n\tTo be Paid under Account No. xxxx-xxxxxxx-xx";
					cout<<"\nPress any key go to main manu ....."<<endl;
					count++;
			
			}
			
		}
		if(count == 0)
			{
				cout<<"\n\nRecord not Found.\nPlease try with valid information...........";
				cout<<"\nPress any key go to main manu ....."<<endl;
			}
	}
	file.close();
	
	
}
		
void SMD::backup()
{
	system("cls");
	string a;
	ofstream outfile;
	string createFile = "";
	ifstream file;
	cout<<"\t\t\t\t    ********************************************\n";
	cout<<"\t\t\t\t    |||||||||||| Backup   All   Data ||||||||||||\n";
	cout<<"\t\t\t\t    ********************************************\n";
	file.open("project.txt",ios::in);
	if(!file){
	cout<<"\n\nFile dose not exist....."<<endl;
	}
	else 
	{ 
		cout<<"\nEnter path where you want to save backup :";
		cin.ignore();
		getline(cin,a); 
		string path=a;
		createFile = path + "/" + "SMD_BACKUP" + ".txt";          
		outfile.open(createFile.c_str());  
		file>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;     
		while(!file.eof())
		{
				outfile<<s_fname<<"      "<<s_lname<<"      "<<s_roll<<"      "<<s_class<<"      "<<s_contact<<"      "<<s_fees<<"      "<<s_smester<<"      "<<email<<"\n";
				file>>s_fname>>s_lname>>s_roll>>s_class>>s_contact>>s_fees>>s_smester>>email;
		}
		cout<<"\nBack Data Successfuly:....";
		
		outfile.close();
	}
		file.close();
}
int main()
{
	
   /*string name,password;
	system("cls");
   	while(1){
   	cout<<"\n\n\n\n\nEnter Username= ";
   	cin>>name;
   	cout<<"\n\n\n\t\tEnter Your Password= ";
   	cin>>password;
   	if(name == "admin" && password == "admin"){
   		break;
	}
	system("cls");
	cout<<"\n\n\n\n\n\n Please login again...................";
   }*/
	p:
	char x;
	Uni_management* m;
	SMD s;
	m=&s;
	system("Color 1A");
	m->control_panel();
	int choice;
	cin>>choice;
	switch(choice){
		case 1:
		{
				do
   			{
				
				system("Color 3B"); 
				m->insert();
			
   				cout<<"\n\n\n\n Do you want to add another record press (y/n) : ";
   	    		cin>>x;
			}while(x=='y');
		}
		break;
		case 2:
		{
			system("Color A1"); 
			m->search();
		}
		break;
		case 3:
		{
			m->update();
		}
		break;
		case 4:
		{
			m->del();
		}
		break;
		case 5:
		{
			m->show();
		}
		break;
		case 6:
		{
			m->Voucher();	
		}
		break;
		case 7:
			{
				m->backup();
			}
			break;
		case 8:
		system("cls");
		cout<<("\n\n\n");
		cout<<("\n\n\n"); 
		cout<<("\n\n\n");
		cout<<("\t\t\t\t\t");
		cout<<("\n");
		cout<<("\t\t\t\t     ***********************************\n");
		cout<<("\t\t\t\t     ||||||||||||| THANKS ||||||||||||||\n");
		cout<<("\t\t\t\t     ***********************************\n");
		cout<<("\n\n");
		cout<<("\t\t\t\t");
		cout<<("\n\n\n");
		cout<<("\n\n\n"); 
		cout<<("\n\n\n");
		exit(0);
		default:
		cout<<"\n\n\n\n\n\ninvalid value........";
	}
	getch();
	goto p;
	return 0;
}
