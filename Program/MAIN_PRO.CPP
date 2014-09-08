#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<process.h>
#include<time.h>
#include<dos.h>

class member{		          				        //Name = C.Aditya
	int mem_no;              	 				//Class = CS 'A'
	public :                 		 		        //USN = 1MV11CS027
		char sex;        	 				//College = Sir MVIT
		char address[100];
		float pin;
		char name[50];
		void getdata()
		{
			cout<<"\n Enter Name = ";
			gets(name);
			cout<<endl;
			cout<<" Enter Sex (m/f) = ";
			cin>>sex;
			cout<<endl;
			cout<<" Enter Address = ";
			gets(address);
			cout<<endl;
			cout<<" Enter Pin Code = ";
			cin>>pin;
			cout<<endl;
		}


		void membership_code()
		{
			randomize();
			int code;
			code=random(1001)+0;
			mem_no=code;
		}

		void putdata()
		{
			cout<<"\n Name = "<<name<<endl;
			cout<<"\n Sex (m = Male) (f = Female)  = "<<sex<<endl;
			cout<<"\n Address = "<<address<<endl;
			cout<<"\n Pin Code = "<<pin<<endl;
			cout<<"\n Membership Code = "<<mem_no<<endl;
		}

		int getcode()
		{
			int qwe;
			qwe=mem_no;
			return qwe;
		}
	}m1, m2, m3, m4;

class book_details {
	int book_code;
	float cost;
	char author[50];
	char publisher[50];
	int pub_year;

	public: char name[75];
		void getdata()
		{
			cout<<"\n Enter Name Of The Book = ";
			gets(name);
			cout<<endl;
			cout<<" Enter Book Code = ";
			cin>>book_code;
			cout<<endl;
			cout<<" Enter Cost = ";
			cin>>cost;
			cout<<endl;
			cout<<" Enter Author\'s Name = ";
			gets(author);
			cout<<endl;
			cout<<" Enter Publisher\'s Name = ";
			gets(publisher);
			cout<<endl;
			cout<<" Enter Year Of Publication = ";
			cin>>pub_year;
			cout<<endl;
		}

		void putdata()
		{
			cout<<"\n Name = "<<name<<endl;
			cout<<" Book Code = "<<book_code<<endl;
			cout<<" Cost = "<<cost<<endl;
			cout<<" Author = "<<author<<endl;
			cout<<" Publisher = "<<publisher<<endl;
			cout<<" Year Of Publication = "<<pub_year<<endl;
		}

		int getcode()
		{
			int abc;
			abc=book_code;
			return abc;
		}

	}b1, b2, b3, b4, b5, b6, b7;

void main_menu();
void edit_record();
void trans_details();
void issued_books();
void book_details();
void member_details();
void new_record();
void delete_record();
void password1();
void password2();
void password3();
void password4();
void password5();
void issue_book();
void renew_book();
void return_book();
void become_member();
void delete_member();
void mem_details();
void check_member();
void terms();
void books_present();
void delete_avail(int zxc);
void member_list();
void return_date(int);
void print();

void print()
{
	char ch,option,choice;
	int i=0;
	ifstream infile("Receipt.txt");
	ofstream outfile("PRN");
	qwerty: {
	cout<<"\n\n\n PLEASE ENSURE THAT THE PRINTER IS CONNECTED........\n IF NOT.......POSSIBLE DATA LOSS EXPECTED !!!";
	cout<<"\n Is The Printer Connected To The Computer ?? (y/n) = ";
	cin>>option;
	if(option=='y')
	{
		if(!outfile)
		{
			cout<<"ERROR !!!\n\n Unable To Connect To Printer !!!";
			cout<<"\n Want To Try Again ??? (y/n) = ";
			cin>>choice;
			if(choice=='y')
				goto qwerty;
			else
			{
				cout<<"\n\n Plese Collect A Manually Written Receipt !!!";
				cout<<"\n\n\n Press Any Key To Continue..........";
				getch();
			}
		}
		else
		{
			while(!infile.eof())
			{
				if(i==0)
				{
					cout<<"\n Processing.........";
					i++;
				}
				outfile.put(ch);
			}
			cout<<"\n Please Collect Your Recepit !!! ";
			cout<<"\n Press Any Key To Continue........";
			getch();
		}
	}
	else
	{
		cout<<"\n Please Collect A Manually Written Receipt !!!";
		cout<<"\n Press Any Key To Proceed.........";
		getch();
	}  }
}
void return_date(int bookcode)
{
	date d1;
	struct time t1;
	gettime(&t1);
	ofstream ofile;
	ofile.open("Receipt.txt",ios::out|ios::binary);
	int dd,mm,yy,ndd,nmm,nyy,temp1,temp2;
	getdate(&d1);
	dd=d1.da_day;
	mm=d1.da_mon;
	yy=d1.da_year;
	if((dd<18)&&(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12))
	{
		ndd=dd+14;
		nmm=mm;
		nyy=yy;
	}
	else if((dd<17)&&(mm==4||mm==6||mm==9||mm==11))
	{
		ndd=dd+14;
		nmm=mm;
		nyy=yy;
	}
	else if((dd>17)&&(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10))
	{
		nyy=yy;
		nmm=mm+1;
		temp1=31-dd;
		temp2=14-temp1;
		ndd=temp2;
	}
	else if((dd>16)&&(mm==4||mm==6||mm==9||mm==11))
	{
		nyy=yy;
		nmm=mm+1;
		temp1=30-dd;
		temp2=14-temp1;
		ndd=temp2;
	}
	else if((dd>17)&&(mm==12))
	{
		nyy=yy+1;
		nmm=1;
		temp1=31-dd;
		temp2=14-temp1;
		ndd=temp2;
	}
	else if((dd<15)&&(mm==2))
	{
		ndd=dd+14;
		nmm=mm;
		nyy=yy;
	}
	else if((dd>14)&&(mm==2))
	{
		nyy=yy;
		nmm=mm+1;
		temp1=28-dd;
		temp2=14-temp1;
		ndd=temp2;
	}
	cout<<"\n\n Date Of Book Return(day-month-year) = "<<ndd<<"-"<<nmm<<"-"<<nyy;
	ofile<<"\n\n\t\t\t DSI Library";
	ofile<<"\n\t\t\t ___________";
	ofile<<"\n\n Date = "<<dd<<"-"<<mm<<"-"<<yy;
	ofile<<"\n Time = "<<t1.ti_hour<<"-"<<t1.ti_min<<"-"<<t1.ti_sec;
	ofile<<"\n\n Bookcode = "<<bookcode;
	ofile<<"\n\n Date Of Book Return = "<<ndd<<"-"<<nmm<<"-"<<nyy;
	ofile<<"\n\n\n\n THANK YOU !!!\n Visit Us Again !!! \n Take Care......";
	ofile.close();
	print();
}
void member_list()
{
	clrscr();
	textcolor(WHITE);
	textbackground(BLACK);
	cout<<"\n\n\n\t\t\t\t Member List "<<endl;
	cout<<"\t\t\t\t ___________ ";
	ifstream ifile;
	ifile.open("Member_Details.txt",ios::in|ios::binary);
	cout<<"\n\n\n\n";
	cout<<"\t\t"<<"Sl.No."<<"\t"<<"Name"<<"\t\t"<<"Membership Code"<<endl;
	cout<<"\t\t"<<"---------------------------------------"<<endl;
	cout<<"\n";
	int j=1,i=1;
	while (!ifile.eof())
	{
		ifile.read((char*)&m1, sizeof(m1));
		if (ifile.eof())
			break;
		if(strlen(m1.name)>7)
		{
			cout<<"\t\t"<<j<<"."<<"\t"<<m1.name<<"\t     "<<m1.getcode()<<"\n ";
			j++;
			i++;
		}
		else
		{
			cout<<"\t\t"<<j<<"."<<"\t"<<m1.name<<"\t\t     "<<m1.getcode()<<"\n ";
			j++;
			i++;
		}
		if(i>10)
		{
			cout<<"\n\n Press Any Key To Show More........ \n\n";
			i=0;
			getch();
		}
	}
	ifile.close();
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu........";
	getch();
	member_details();
}

void delete_avail(int zxc)
{
	 textcolor(CYAN);
	 textbackground(RED);
	 ifstream ifile;
	 ifile.open("Available_Books.txt",ios::in|ios::binary);
	 ofstream ofile;
	 ofile.open("ASD.txt", ios::out|ios::binary);
	 while (!ifile.eof())
	 {
		ifile.read((char*)&b3, sizeof(b3));
		if (b3.getcode()==zxc)
			;
		else
			ofile.write((char*)&b3, sizeof(b3));
		if (ifile.eof())
			break;
	 }
	 ifile.close();
	 ofile.close();
	 remove("Available_Books.txt");
	 rename("ASD.txt", "Available_Books.txt");
}
void trans_details()
{
	clrscr();
	textcolor(WHITE);
	textbackground(RED);
	char choice;
	cout<<"\n\n\n\t\t\t\t Transaction Details "<<endl;
	cout<<"\t\t\t\t ___________________\n\n\n\n\n "<<endl;
	cout<<"\t\t\t 1. Issue New Book "<<endl;
	cout<<"\t\t\t 2. Renew Book "<<endl;
	cout<<"\t\t\t 3. Return Book "<<endl;
	cout<<"\t\t\t 4. Return To Main Menu "<<endl;
	cout<<"\n\n\t\t Enter Your Choice (1,2,3,4) = ";
	cin>>choice;
	asdf : {
	switch(choice)
	{
		case '1': check_member();
			  break;
		case '2': renew_book();
			  break;
		case '3': return_book();
			  break;
		case '4': main_menu();
			  break;
		default : cout<<"\n Wrong Choice !!!! ";
			  cout<<"\n\n Enter Your Choice (1,2,3,4) = ";
			  cin>>choice;
			  goto asdf;
	}
	}
	getch();
}
void return_book()
{
	clrscr();
	textcolor(GREEN);
	textbackground(WHITE);
	int bookno;
	char found='n';
	ifstream ifile;
	ofstream ofile;
	ofstream oofile;
	ifile.open("Issued_Books.txt", ios::in|ios::binary);
	ofile.open("XYZ.txt", ios::out|ios::binary);
	oofile.open("Available_Books.txt", ios::out|ios::binary|ios::app);
	cout<<"\n\n\n\n\t\t\t\t Return Book "<<endl;
	cout<<"\t\t\t\t ___________ ";
	cout<<"\n\n\n\n\n Enter Book No. = ";
	cin>>bookno;
	while (!ifile.eof())
	{
		ifile.read((char*)&b7, sizeof(b7));
		if (ifile.eof())
			break;
		if (b7.getcode()==bookno)
		{
			b7.putdata();
			found='y';
			oofile.write((char*)&b7, sizeof(b7));
			cout<<"\n\n\n\n\n The Book Has Been Added Back To The Library ";
			cout<<"\n Thank You !!!!!";
		}
		else
			ofile.write((char*)&b7, sizeof(b7));
	}
	if (found=='n')
		cout<<"\n This Book Hasn't Been Borrowed ";
	ifile.close();
	ofile.close();
	oofile.close();
	remove("Issued_Books.txt");
	rename("XYZ.txt", "Issued_Books.txt");
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu......";
	getch();
	trans_details();
}
void renew_book()
{
	clrscr();
	textcolor(BLACK);
	textbackground(GREEN);
	cout<<"\n\n\n\n\t\t\t\t Renew Book "<<endl;
	cout<<"\t\t\t\t __________ " ;
	int bookno;
	char found='n';
	ifstream ifile;
	ifile.open("Issued_Books.txt", ios::in|ios::binary);
	cout<<"\n\n\n\n\n Enter The Book No. = ";
	cin>>bookno;
	while (!ifile.eof())
	{
		ifile.read((char*)&b6, sizeof(b6));
		if (ifile.eof())
			break;
		if (b6.getcode()==bookno)
		{
			found='y';
			cout<<"\n\n\n Book Has Been Renewed ";
			return_date(bookno);
			break;
		}
	}
	if (found=='n')
		cout<<"\n This Book Hasn\'t Been Borrowed !!!!! ";
	ifile.close();
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu.......";
	getch();
	trans_details();
}
void check_member()
{
	clrscr();
	textcolor(RED);
	textbackground(BLACK);
	int memno;
	char choice;
	char found='n';
	cout<<"\n\n\n\n\t Enter Membership No. = ";
	cin>>memno;
	ifstream ifile;
	ifile.open("Member_Details.txt",ios::in|ios::binary);


	while(!ifile.eof())
	{
		ifile.read((char*)&m4, sizeof(m4));
		if (ifile.eof())
			break;
		if(m4.getcode()==memno)
		{
			found='y';
			break;
		}
	}
	ifile.close();
	if (found=='y')
	{
		cout<<"\n Valid Membership Code !!!!! ";
		cout<<"\n\n Press Any Key To Continue......";
		getch();
		issue_book();
	}
	if (found=='n')
	{
		cout<<"\n Invalid Membership No. !!!!!! ";
		cout<<"\n\n Want To Become A Member ???? (y/n) = ";
		cin>>choice;
		if (choice=='y'||choice=='Y')
			become_member();
		else
		{
			cout<<"\n\n\n Press Any Key To Return To The Previous Menu......";
			getch();
			trans_details();
		}
	}
}
void issue_book()
{
	clrscr();
	struct time t;
	struct date d;
	textcolor(BLUE);
	textbackground(WHITE);
	int bookcode;
	char choice;
	char found='n';
	ifstream ifile;
	ofstream ofile;
	ifile.open("Available_Books.txt", ios::in|ios::binary);
	ofile.open("Issued_Books.txt", ios::out|ios::binary|ios::app);
	cout<<"\n\n\n\n\t\t\t\t Issue Book "<<endl;
	cout<<"\t\t\t\t __________ ";
	cout<<"\n\n\n\n Enter The Book Code Of The Book To Be Borrowed = ";
	cin>>bookcode;
	while (!ifile.eof())
	{
		ifile.read((char*)&b5, sizeof(b5));
		if (ifile.eof())
			break;
		if (b5.getcode()==bookcode)
		{
			found='y';
			b5.putdata();
			cout<<"\n\n Are You Sure You Want To Borrow This Book ??? (y/n) = ";
			cin>>choice;
			if (choice=='y')
			{
				ofile.write((char*)&b5, sizeof(b5));
				ifile.close();
				delete_avail(bookcode);
				cout<<"\n The Book Can Now Be Borrowed !!!";
				gettime(&t);
				getdate(&d);
				cout<<"\n Book Issued On \n";
				printf(" Time (hours-minutes-seconds) = %2d-%02d-%02d \n",t.ti_hour,t.ti_min,t.ti_sec);
				printf(" Date (day-month-year)        = %d-%d-%d",d.da_day,d.da_mon,d.da_year);
				return_date(bookcode);
				cout<<"\n\n Thank You !!!!!!! "<<endl;
				break;
			}
			else
				break;
		}
	}
	ifile.close();
	ofile.close();
	if (choice=='n')
	{
		cout<<"\n\n\n Press Any Key To Return To The Previous Menu......";
		getch();
		trans_details();
	}
	if (found=='n')
		cout<<"\n Invalid Book No. !!!!! ";
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu........";
	getch();
	trans_details();
}

void issued_books()
{
	clrscr();
	textcolor(CYAN);
	textbackground(BLACK);
	cout<<"\n\n\n\n\t\t\t\t Issued Books "<<endl;
	cout<<"\t\t\t\t ____________ ";
	ifstream ifile;
	ifile.open("Issued_Books.txt", ios::in|ios::binary);
	cout<<"\n\n\n\n";
	cout<<"\t\t"<<"Sl.No."<<"\t"<<"Book Code"<<"\t"<<"Name Of The Book"<<endl;
	cout<<"\t\t"<<"-----------------------------------------"<<endl;
	cout<<"\n";
	int j=1,i=1;
	while (!ifile.eof())
	{
		ifile.read((char*)&b1, sizeof(b1));
		if (ifile.eof())
			break;
		cout<<"\t\t"<<j<<"."<<"\t"<<b1.getcode()<<"\t\t"<<b1.name<<endl;
		j++;
		i++;
		if(i>10)
		{
			cout<<"\n Press Any Key To Show More......... \n\n";
			i=0;
			getch();
		}
	}
	ifile.close();
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu........";
	getch();
	main_menu();
}

void mem_details()
{
	clrscr();
	textcolor(BLACK);
	textbackground(WHITE);
	cout<<"\n\n\n\n\t\t\t Membership Details "<<endl;
	cout<<"\t\t\t __________________";
	int memno;
	char found = 'n';
	ifstream ifile;
	ifile.open("Member_Details.txt",ios::in|ios::binary);
	cout<<"\n\n\n\n\n\n\n\t Enter The Membership Code = ";
	cin>>memno;
	cout<<"\n\n\n";
	while (!ifile.eof())
	{
		ifile.read((char*)&m3, sizeof(m3));
		if (ifile.eof())
			break;
		if (m3.getcode()==memno)
		{
			m3.putdata();
			found = 'y';
			break;
		}
	}
	if (found=='n')
	cout<<"\n Invalid Membership Code !!!!!!! ";
	ifile.close();
	cout<<"\n\n\n\n Press Any Key To Return To The Previous Menu.......";
	getch();
	member_details();
}

void delete_member()
{
	clrscr();
	textcolor(WHITE);
	textbackground(BLACK);
	cout<<"\n\n\n\n\t\t\t\t Detele Member "<<endl;
	cout<<"\t\t\t\t _____________ ";
	ifstream ifile;
	ofstream ofile;
	ifile.open("Member_Details.txt",ios::in|ios::binary);
	ofile.open("Temp1.txt",ios::out|ios::binary);
	int memno;
	char found='n';
	char confirm='n';
	cout<<"\n\n\n\n Enter The Membership Code Of The Member Whose Membership Is To Be Deleted = ";
	cin>>memno;
	while(!ifile.eof())
	{
		ifile.read((char*)&m2, sizeof(m2));
		if (ifile.eof())
			break;
		if (m2.getcode()==memno)
		{
			m2.putdata();
			found='y';
			cout<<"\nAre You Sure You Want To Delete This Membership ? (y/n) = ";
			cin>>confirm;
			if (confirm=='n')
				ofile.write((char*)&m2, sizeof(m2));
			else
				cout<<"\n\n Membership Deleted !!!!!";
		}
		else
			ofile.write((char*)&m2, sizeof(m2));
	}
	if (found=='n')
	cout<<"\n Invalid Membership Code !!!!!! ";
	ifile.close();
	ofile.close();
	remove("Member_Details.txt");
	rename("Temp1.txt", "Member_Details.txt");
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu.......";
	getch();
	member_details();
}

void become_member()
{
	clrscr();
	textcolor(BLACK);
	textbackground(WHITE);
	cout<<"\n\n\n\n\t\t\t\t Become A Member "<<endl;
	cout<<"\t\t\t\t _______________ "<<endl;
	cout<<"\n\n\n\n";
	ofstream ofile;
	ofile.open("Member_Details.txt",ios::out|ios::app|ios::binary);
	m1.getdata();
	m1.membership_code();
	ofile.write((char*)&m1, sizeof(m1));
	cout<<"\n\n\n You Are Now A Member !!!!!!! ";
	cout<<"\n Your Membership Code Is = "<<m1.getcode();
	ofile.close();
	cout<<"\n\n\n\n Thank You !!!!!! ";
	cout<<"\n Press Any Key To Return To The Previous Menu.......";
	getch();
	member_details();
}

void member_details()
{
	clrscr();
	textcolor(WHITE);
	textbackground(BLACK);
	char choice;
	cout<<"\n\n\n\n\t\t\t\t Member Details "<<endl;
	cout<<"\t\t\t\t ______________ "<<endl;
	cout<<"\n\n\t\t\t 1.   Become A Member "<<endl;
	cout<<"\t\t\t 2. $ Delete Membership "<<endl;
	cout<<"\t\t\t 3.   Membership Details "<<endl;
	cout<<"\t\t\t 4. $ Member List "<<endl;
	cout<<"\t\t\t 5.   Return To The Previous Menu "<<endl;
	cout<<"\n\n Enter Your Choice (1,2,3,4,5) = ";
	cin>>choice;
	zxcv : {
	switch(choice)
	{
		case '1': become_member();
			  break;
		case '2': password3();
			  break;
		case '3': mem_details();
			  break;
		case '4': password5();
			  break;
		case '5': main_menu();
			  break;
		default : cout<<"\n Wrong Choice !!!!!! ";
			  cout<<"\n\n\n Enter Your Choice (1,2,3,4,5) = ";
			  cin>>choice;
			  goto zxcv;
	}
	}
}

void book_details()
{
	clrscr();
	textcolor(CYAN);
	textbackground(WHITE);
	cout<<"\n\n\n\n\t\t\t\t Book Details "<<endl;
	cout<<"\t\t\t\t ____________";
	int recno;
	char found='n';
	ifstream ifile;
	ifile.open("List_Of_Books.txt",ios::in|ios::binary);
	cout<<"\n\n\n\n\n Enter The Book Code Whose Details Is To Printed = ";
	cin>>recno;
	while(!ifile.eof())
	{
		ifile.read((char*)&b3, sizeof(b3));
		if (ifile.eof())
			break;
		if(b3.getcode()==recno)
		{
			b3.putdata();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"\n\n\n Record Not Found !!!!!!! ";
	ifile.close();
	cout<<"\n\n\n\n\nPress Any Key To Return To The Previous Menu.......";
	getch();
	main_menu();
}

void new_record()
{
	clrscr();
	textcolor(BLACK);
	textbackground(WHITE);
	cout<<"\n\n\n\n\t\t\t\t New Record "<<endl;
	cout<<"\t\t\t\t____________";
	ofstream ofile;
	ofstream oofile;
	oofile.open("Available_Books.txt",ios::app|ios::binary);
	ofile.open("List_Of_Books.txt",ios::app|ios::binary);
	cout<<"\n\n\n\n\n";
	char opt='y';
	while (opt=='y'||opt=='Y')
	{
		cout<<"\n Enter Details Of The Book ........\n";
		b1.getdata();
		ofile.write((char*)&b1, sizeof(b1));
		oofile.write((char*)&b1, sizeof(b1));
		cout<<"\n\n\n Record Written !!!!!\n ";
		cout<<"\n\n\n Do You Want To Write More ???? (y/n) = ";
		cin>>opt;
	}
	ofile.close();
	oofile.close();
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu.......";
	getch();
	edit_record();
}

void password1()
{
	clrscr();
	textcolor(RED);
	textbackground(WHITE);
	char log;
	char *pass="admin";
	char *pword = new char;
	cout<<"\n\n\n\tEnter Password = ";
	char h = getch();
	int j = 0;
	while (h != '\r')
		{
		if (h == '\b')
		{
			if (j == 0)
			h = getch();
			else
			{
				cout << '\b';
				cout << " ";
				cout << '\b';
				j--;
				pword--;
				h = getch();
			}
		}
		else
		{
			cout << "*";
			*pword = h;
			h = getch();
			pword++;
			j++;
		}
	}
	*pword = '\0';
	for (; j>0; j--)
	pword--;
	cout << endl;
	if (strcmp(pass,pword)!=0 )
	{
		cout<<"\n\n\n Login Failed !!!!!";
		cout<<"\n Try again ???? (y,n) = ";
		cin>>log;
		if (log=='y'||log=='Y')
			password1();
		else
		{
			cout<<"\n Press Any Key To Return To The Previous Menu.......";
			getch();
			edit_record();
		}
	}
	else
	{
		cout<<"\n\n Login Successful !!!!!!";
		cout<<"\n\n Press Any Key To Continue.....";
		getch();
		new_record();
	}

}

void password2()
{
	clrscr();
	textcolor(RED);
	textbackground(WHITE);
	char log;
	char *pass="admin";
	char *pword = new char;
	cout<<"\n\n\n\tEnter Password = ";
	char h = getch();
	int j = 0;
	while (h != '\r')
		{
		if (h == '\b')
		{
			if (j == 0)
			h = getch();
			else
			{
				cout << '\b';
				cout << " ";
				cout << '\b';
				j--;
				pword--;
				h = getch();
			}
		}
		else
		{
			cout << "*";
			*pword = h;
			h = getch();
			pword++;
			j++;
		}
	}
	*pword = '\0';
	for (; j>0; j--)
	pword--;
	cout << endl;
	if (strcmp(pass,pword)!=0 )
	{
		cout<<"\n\n\n Login Failed !!!!!";
		cout<<"\n Try again ???? (y,n) = ";
		cin>>log;
		if (log=='y'||log=='Y')
			password2();
		else
		{
			cout<<"\n Press Any Key To Return To The Previous Menu......";
			getch();
			edit_record();
		}
	}
	else
	{
		cout<<"\n\n Login Successful !!!!!!";
		cout<<"\n\n Press Any Key To Continue.....";
		getch();
		delete_record();
	}

}

void password3()
{
	clrscr();
	textcolor(RED);
	textbackground(WHITE);
	char log;
	char *pass="admin";
	char *pword = new char;
	cout<<"\n\n\n\tEnter Password = ";
	char h = getch();
	int j = 0;
	while (h != '\r')
		{
		if (h == '\b')
		{
			if (j == 0)
			h = getch();
			else
			{
				cout << '\b';
				cout << " ";
				cout << '\b';
				j--;
				pword--;
				h = getch();
			}
		}
		else
		{
			cout << "*";
			*pword = h;
			h = getch();
			pword++;
			j++;
		}
	}
	*pword = '\0';
	for (; j>0; j--)
	pword--;
	cout << endl;
	if (strcmp(pass,pword)!=0 )
	{
		cout<<"\n\n\n Login Failed !!!!!";
		cout<<"\n Try again ???? (y,n) = ";
		cin>>log;
		if (log=='y'||log=='Y')
			password3();
		else
		{
			cout<<"\n Press Any Key To Return To The Previous Menu......";
			getch();
			member_details();
		}
	}
	else
	{
		cout<<"\n\n Login Successful !!!!!!";
		cout<<"\n\n Press Any Key To Continue.....";
		getch();
		delete_member();
	}
}

void password4()
{
	clrscr();
	textcolor(RED);
	textbackground(WHITE);
	char log;
	char *pass="admin";
	char *pword = new char;
	cout<<"\n\n\n\tEnter Password = ";
	char h = getch();
	int j = 0;
	while (h != '\r')
		{
		if (h == '\b')
		{
			if (j == 0)
			h = getch();
			else
			{
				cout << '\b';
				cout << " ";
				cout << '\b';
				j--;
				pword--;
				h = getch();
			}
		}
		else
		{
			cout << "*";
			*pword = h;
			h = getch();
			pword++;
			j++;
		}
	}
	*pword = '\0';
	for (; j>0; j--)
	pword--;
	cout << endl;
	if (strcmp(pass,pword)!=0 )
	{
		cout<<"\n\n\n Login Failed !!!!!";
		cout<<"\n Try again ???? (y,n) = ";
		cin>>log;
		if (log=='y'||log=='Y')
			password4();
		else
		{
			cout<<"\n Press Any Key To Return To The Previous Menu.......";
			getch();
			main_menu();
		}
	}
	else
	{
		cout<<"\n\n Login Successful !!!!!!";
		cout<<"\n\n Press Any Key To Continue.....";
		getch();
		issued_books();
	}

}

void password5()
{
	clrscr();
	textcolor(RED);
	textbackground(WHITE);
	char log;
	char *pass="admin";
	char *pword = new char;
	cout<<"\n\n\n\tEnter Password = ";
	char h = getch();
	int j = 0;
	while (h != '\r')
		{
		if (h == '\b')
		{
			if (j == 0)
				h = getch();
			else
			{
				cout << '\b';
				cout << " ";
				cout << '\b';
				j--;
				pword--;
				h = getch();
			}
		}
		else
		{
			cout << "*";
			*pword = h;
			h = getch();
			pword++;
			j++;
		}
	}
	*pword = '\0';
	for (; j>0; j--)
	pword--;
	cout << endl;
	if (strcmp(pass,pword)!=0 )
	{
		cout<<"\n\n\n Login Failed !!!!!";
		cout<<"\n Try again ???? (y,n) = ";
		cin>>log;
		if (log=='y'||log=='Y')
			password5();
		else
		{
			cout<<"\n Press Any Key To Return To The Previous Menu.......";
			getch();
			member_details();
		}
	}
	else
	{
		cout<<"\n\n Login Successful !!!!!!";
		cout<<"\n\n Press Any Key To Continue.....";
		getch();
		member_list();
	}

}



void delete_record()
{
	clrscr();
	textcolor(WHITE);
	textbackground(BLACK);
	cout<<"\n\n\n";
	cout<<"\n\t\t\t\t Delete Record"<<endl;
	cout<<"\t\t\t\t _____________";
	char confirm='n';
	char found='n';
	ifstream ifile;
	ifstream ifile1;
	ifile1.open("Available_Books.txt", ios::in|ios::binary);
	int recno;
	ifile.open("List_Of_Books.txt", ios::in|ios::binary);
	ofstream ofile;
	ofile.open("Temp.txt", ios::out|ios::binary);
	cout<<"\n\n\n\n\n Enter The Book Code Whose Details Is To Be Deleted = ";
	cin>>recno;
	while(!ifile.eof())
	{
		ifile.read((char*)&b2, sizeof(b2));
		if (ifile.eof())
			break;
		if (b2.getcode()==recno)
		{
			b2.putdata();
			found='y';
			cout<<"\n\n Are You Sure You Want To Delete This Record ??? (y/n) = ";
			cin>>confirm;
			if (confirm == 'y')
				delete_avail(recno);
			else if(confirm == 'n')
				ofile.write((char*)&b2, sizeof(b2));
			else
				cout<<"\n Record Deleted !!!!! ";
		}
		else
			ofile.write((char*)&b2, sizeof(b2));
	}
	if(found=='n')
		cout<<"\n\n Record Not Found !!!!!! ";
	ifile.close();
	ofile.close();
	remove("List_Of_Books.txt");
	rename("Temp.txt", "List_Of_Books.txt");
	cout<<"\n\n\n Press Any Key To Return To The Previous Menu.......";
	getch();
	edit_record();
}

void edit_record()
{
	clrscr();
	textcolor(BLUE);
	textbackground(YELLOW);
	char edit;
	cout<<"\n\n\n\n\n\t\t\t\tEdit Record "<<endl;
	cout<<"\t\t\t\t___________"<<endl;
	cout<<"\n\n\n\t\t\t\t 1. $ Enter New Book Details "<<endl;
	cout<<"\t\t\t\t 2. $ Delete Old Book Details "<<endl;
	cout<<"\t\t\t\t 3.   Return To Main Menu "<<endl;
	cout<<"\n\n\n\t\t\t Enter Your Choice (1,2,3) = ";
	cin>>edit;
	edits:
	{
	switch (edit)
	{
		case '1': password1();
			break;
		case '2': password2();
			break;
		case '3': main_menu();
			break;
		default: cout<<"\n\t\t\t Wrong Choice !!!!! ";
			 cout<<"\n\t\t\t Enter Your Choice (1,2,3) = ";
			 cin>>edit;
			 goto edits;
	}
	}
}

void terms()
{
	clrscr();
	textcolor(CYAN);
	textbackground(RED);
	cout<<"\n\t\t\t\t User Guide "<<endl;
	cout<<"\t\t\t\t __________ ";
	cout<<"\n\n";
	cout<<"\t PURPOSE : \n";
	cout<<"\n The Main Idea Behind This Software Is To Carry Out The Basic Functions Being\n Done In A Library....."<<endl;
	cout<<" This Software Can Be Used By \n (i) The Administrator (i.e. The Librarian) \n (ii) Members Of The Library \n (iii) Non-Members"<<endl;
	cout<<"\n\n Options Available To The Administrator (Password Protected) : "<<endl;
	cout<<"\n 1. Edit Record (i.e. Allows The Librarian To Add More Books Into The Library)"<<endl;
	cout<<" 2. Delete Record (i.e. Allows The Librarian To Delete Old Books"<<endl;
	cout<<"\t\t\t\t\t\t\t From The Library)"<<endl;
	cout<<" 3. Delete Membership (i.e. Allows The Librarian To Delete"<<endl;
	cout<<"\t\t\t\t\t\t The Membership Of The Members)"<<endl;
	cout<<" 4. Issued Books (i.e. Allows The Librarian To Keep A Track Of Issued Books)"<<endl;
	cout<<" 5. Member List (i.e. Displays The Name And The Membership Code Of The Member)"<<endl;
	cout<<"\n\n Press Any Key To Show More........";
	getch();
	cout<<"\n\n Options Available To The Rest (Members & Non-Members)"<<endl;
	cout<<"\n 1. Book Details (i.e Shows The Details Of The Book)"<<endl;
	cout<<" 2. Renew Book (i.e. Extends The Duration Period Of The Book)"<<endl;
	cout<<" 3. Return Book (i.e. Lets You Add The Book Back To The Library)"<<endl;
	cout<<" 4. Become A Member (i.e. Lets You Become A Member And Thus Borrow Books)"<<endl;
	cout<<" 5. Membership Details (i.e. Lets You Display The Details Of The Members)"<<endl;
	cout<<" 6. Books Available In The Library (i.e. Displays The Books Available "<<endl;
	cout<<"\t\t\t\t\t\t\t In The Library)"<<endl;
	cout<<"\n\n Press Any Key To Show More........";
	getch();
	cout<<"\n\n\n\n KEY FEATURE :"<<endl;
	cout<<"\n\t (i) Unless One Is A Member........He/She Cant Borrow A Book !!! "<<endl;
	cout<<"\t (ii) The Receipt Obtained At The Time Of Book Issue Must Be Produced At\t\t\b\b\b The Time Of Book Return !!!"<<endl;
	cout<<"\t (iii) PLEASE ENSURE PRINTER IS CONNECTED AT THE TIME OF\n\t\t\b\b BOOK ISSUE OR RENEW.......POSSIBLE DATA LOSS EXPECTED "<<endl;
	cout<<"\t (iv) OPTIONS WITH DOLLER '$' SYMBOL ARE PASSWORD PROTECTED !!!"<<endl;
	cout<<"\n\n\n Press Any Key To Procced........";
	getch();
	main_menu();
}

void books_present()
{
	clrscr();
	textcolor(BLACK);
	textbackground(CYAN);
	ifstream ifile;
	ifile.open("Available_Books.txt", ios::in|ios::binary);
	cout<<"\n\n\n\n\t\t\t\t Books Available "<<endl;
	cout<<"\t\t\t\t _______________ ";
	cout<<"\n\n\n\n";
	cout<<"\t\t"<<"Sl.No."<<"\t"<<"Book Code"<<"\t"<<"Name Of The Book"<<endl;
	cout<<"\t\t"<<"-----------------------------------------"<<endl;
	cout<<"\n";
	int j=1,i=1;
	while (!ifile.eof())
	{
		ifile.read((char*)&b1, sizeof(b1));
		if (ifile.eof())
			break;
		cout<<"\t\t"<<j<<"."<<"\t"<<b1.getcode()<<"\t\t"<<b1.name<<endl;
		if (ifile.eof())
			break;
		j++;
		if (ifile.eof())
			break;
		i++;
		if (ifile.eof())
			break;
		if(i>10)
		{
			cout<<"\n Press Any Key To Show More........";
			i=0;
			getch();
		}
		if (ifile.eof())
			break;
	}
	ifile.close();
	cout<<"\n\n\n\n Press Any Key To Return To The Previous Menu....... ";
	getch();
	main_menu();
}

void main_menu()
{
	clrscr();
	textcolor(WHITE);
	textbackground(BLACK);
	char choice;
	char exits;
	cout<<"\n\n\n\n\n\t\t\t\tMain Menu"<<endl;
	cout<<"\t\t\t\t---------\n\n";
	cout<<"\n\t\t\t 1.   Edit Record "<<endl;
	cout<<"\t\t\t 2.   Transaction Details "<<endl;
	cout<<"\t\t\t 3. $ Issued Books "<<endl;
	cout<<"\t\t\t 4.   Book Details "<<endl;
	cout<<"\t\t\t 5.   Member\'s Details "<<endl;
	cout<<"\t\t\t 6.   Books Present In The Library "<<endl;
	cout<<"\t\t\t 7.   User\'s Guide "<<endl;
	cout<<"\t\t\t 8.   Exit "<<endl;
	cout<<"\n\t\t Enter Your Choice (1,2,3,4,5,6,7,8) = ";
	cin>>choice;
	label:
	{
	switch (choice)
	{
		case '1': edit_record();
			break;
		case '2': trans_details();
			break;
		case '3': password4();
			break;
		case '4': book_details();
			break;
		case '5': member_details();
			break;
		case '6': books_present();
			 break;
		case '7': terms();
			 break;
		case '8': cout<<"\n\n\t\t Are You Sure ???? (y/n) = ";
			cin>>exits;
			if (exits=='y'||exits=='Y')
				{
					cout<<"\n\t\t Thank You !!!!!!"<<endl;
					cout<<"\t\t Press Any Key To Terminate........"<<endl;
					cout<<"\n\n\n\n\n\t\t\t\t\t\t Created By C.Aditya ";
					getch();
					exit(0);
				}
			else
				{
					cout<<"\n\t\t Enter Your Choice (1,2,3,4,5,6,7,8) = ";
					cin>>choice;
					goto label;
				}
			break;
		default: cout<<"\n\t\t Wrong Choice !!!!!";
			 cout<<"\n\t\t Enter Your Choice (1,2,3,4,5,6,7,8) = ";
			 cin>>choice;
			 goto label;
	}
	}
}
void main()
{
	clrscr();
	textcolor(BLACK);
	textbackground(WHITE);
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t____________________\n"<<endl;
	cout<<"\t\t\t____________________\n"<<endl;
	cout<<"\t\t\t Welcome To Library \n"<<endl;
	cout<<"\t\t\t____________________\n"<<endl;
	cout<<"\t\t\t____________________\n"<<endl;
	cout<<"\n\n\n\t\t Press Any Key To Continue ...........";
	getch();
	terms();
	main_menu();
	getch();
}