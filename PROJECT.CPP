#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class Status
{
 public:
  char data[100];
  void addstatus(char id[100],char bid[100],char bn[100])
  {
   ofstream out;
   out.open("status.txt",ios::app);
   out<<endl<<id<<"\t";
   out<<bid<<"\t";
   out<<bn;
   out.close();
  }
  int checkstatus(char o[100])
  {
    ifstream in;
    in.open("status.txt");
   while(!in.eof())
    {
     in>>data;
     int h=strcmp(o,data);
     if(h==0)
     {
      cout<<"\n\n\tBENDING...!";
      return 0;
     }
     else
      return 1;
    in.close();
   }
  }
  void changestatus(char sid[100],char bid[100],char bn[100])
  {
   int i=0;
   ifstream input;
   ofstream output;
   input.open("status.txt");
   output.open("temp.txt");
   while(!input.eof())
   {
    input>>data;
    int x=strcmp(sid,data);
    if(x!=0)
     output<<endl<<data<<"\t";
    input>>data;
    int y=strcmp(bid,data);
    if(y!=0)
     output<<data<<"\t";
    input>>data;
    int z=strcmp(bn,data);
    if(z!=0)
     output<<data<<"\t";

   }
   input.close();
   output.close();
   ifstream infile;
   ofstream outfile;
   infile.open("temp.txt");
   outfile.open("status.txt");
   while(!infile.eof())
   {
    infile>>data;
    outfile<<endl<<data<<"\t";
    infile>>data;
    outfile<<data<<"\t";
    infile>>data;
    outfile<<data;
   }
   infile.close();
   outfile.close();
  }
};
class Service
{
 public:
  char bid[50],bname[50],val[100],val1[100],val2[100];
  void Show()
 {
  ifstream infile;
  infile.open("a.txt");
  cout<<"\nBook ID"<<"\tBook Name\n";
  for(;;)
  {
  int i=0;
  if(!infile.eof())
  {
  infile>>val;
  cout<<val<<"\t";
  infile>>val;
  cout<<val<<endl;
  }
  else
   break;
  i++;
  }
  infile.close();
 }

  void getbook(char d[50])
  {
   Status c;
   cout<<"\nEnter the Book ID you want to get: ";
   cin>>bid;
   cout<<"\nEnter the Book Name you want to get: ";
   cin>>bname;
   ifstream input;
   ofstream output;
   input.open("a.txt");
   output.open("b.txt");
   while(!input.eof())
   {
    input>>val1;
    int k=strcmp(bid,val1);
    input>>val2;
    int m=strcmp(bname,val2);
    if(k!=0&&m!=0)
    {
     output<<val1<<"\t";
     output<<val2<<"\n";
    }
   }
   input.close();
   output.close();
   ifstream in;
   ofstream out;
   in.open("b.txt");
   out.open("a.txt");
   while(!in.eof())
   {
    in>>val;
    out<<val<<"\t";
    in>>val;
    out<<val<<endl;
   }
   in.close();
   out.close();
   c.addstatus(d,bid,bname);
   cout<<"\n\n\t YOU CAN GET THE BOOK AND SHOULD RETURN WITH IN 7 DAYS";
  }
  void returnbook(char sid[50],int a)
  {
  Status l;
  char bd[50],bnm[50];
  ofstream outfile;
  outfile.open("a.txt",ios::app);
  for(int i=0;i<a;i++)
  {
  cout<<"Enter the Book ID: ";
  cin>>bd;
  outfile<<bd<<"\t";
  cout<<"Enter the Book Name: ";
  cin>>bnm;
  outfile<<bnm<<endl;
  }
  outfile.close();
  l.changestatus(sid,bd,bnm);
  cout<<"\n\tTHE ISSUED BOOK HAS BEEN RECEIVED SUCCESSFULLY";
  }
};
class Student:public Service
{
 public:
  char id[50],data[100];
  char sname[50],srno[50];
  Login()
  {
  Status f;
  Service sv;
  cout<<"Enter your ID: ";
  cin>>id;
  ifstream infile;
  infile.open("login.txt");
  while(!infile.eof())
  {
  infile>>data;
  int p=strcmp(id,data);
  if(p==0)
  {
  int y;
  cout<<"\n\t1.Get Book";
  cout<<"\n\t2.Return Book";
  cout<<"\nEnter your choice: ";
  cin>>y;
  switch(y)
  {
   case 1:
    int j=f.checkstatus(id);
    if(j==1)
    {
    sv.Show();
    sv.getbook(id);
    }
    break;
   case 2:
    char sd[100];
    int f;
    cout<<"\n\nNo of Books you have to return: ";
    cin>>f;
	   sv.returnbook(id,f);
    break;
   default:
    break;
  }
  }
  }
  infile.close();
  }
  NewAccount()
  {
   cout<<"Enter your Name: ";
   cin>>sname;
   cout<<"Enter your Rollno: ";
   cin>>srno;
   ofstream outfile;
   outfile.open("login.txt",ios::app);
   outfile<<endl<<srno;
   outfile<<"\t"<<sname;
   outfile.close();
   cout<<"\t\tYou have got Our Membership\n\tYou can login with your Rollno\n";
  }
  void Show()
  {
  char stu[100];
  ifstream infile;
  infile.open("login.txt");
  cout<<"\nID"<<"\tName\n\n";
  while(!infile.eof())
  {
  infile>>stu;
  cout<<stu<<"\t";
  infile>>stu;
  cout<<stu<<"\n";
  }
  }
};
class StudentDetails:public Student
{
public:
 int n;
 void getdata()
 {
 Student s1;
 cout<<"\n\t1.Login";
 cout<<"\n\t2.Create new Membership";
 cout<<"\n\nEnter your choice: ";
 cin>>n;
 switch(n)
 {
  case 1:
   s1.Login();
   break;
  case 2:
   s1.NewAccount();
   break;
  default:
   break;
  }
 }
};
class Book
{
public:
 char data[100];
 void Addentry(int a)
 {
  ofstream outfile;
  ofstream out;
  outfile.open("book.txt",ios::app);
  out.open("a.txt",ios::app);
  for(int i=0;i<a;i++)
  {
  cout<<"Enter the Book ID: ";
  cin>>data;
  outfile<<data<<"\t";
  out<<data<<"\t";
  cout<<"Enter the Book Name: ";
  cin>>data;
  cin.ignore();
  outfile<<data<<endl;
  out<<data<<endl;
  }
  outfile.close();
 }
 void Show()
 {
  ifstream infile;
  infile.open("a.txt");
  cout<<"\nBook ID"<<"\tBook Name\n";
  for(;;)
  {
  int i=0;
  if(!infile.eof())
  {
  infile>>data;
  cout<<data<<"\t";
  infile>>data;
  cout<<data<<endl;
  }
  else
   break;
  i++;
  }
 }
 void StockShow()
 {
  ifstream infile;
  infile.open("book.txt");
  cout<<"\nBook ID"<<"\tBook Name\n";
  for(;;)
  {
  int i=0;
  if(!infile.eof())
  {
  infile>>data;
  cout<<data<<"\t";
  infile>>data;
  cout<<data<<endl;
  }
  else
   break;
  i++;
  }
 }
 void IssueBook()
 {
  ifstream in;
  in.open("status.txt");
  while(!in.eof())
  {
   in>>data;
   cout<<data<<"\t";
   in>>data;
   cout<<data<<"\t";
   in>>data;
   cout<<data<<"\n";
  }
 }
};
class BookDetails:public Book
{
public:
 int n;
 void getdata()
 {
 Book b;
 cout<<"\t\tStock Maintenance Details";
 cout<<"\n1.AddBook";
 cout<<"\n2.Show book details";
 cout<<"\nEnter your choice: ";
 cin>>n;
 switch(n)
 {
 case 1:
  int c;
  cout<<"\nHow many books you have to enter:";
  cin>>c;
  b.Addentry(c);
  break;
 case 2:
  b.StockShow();
  break;
 default:
  break;
}
}
};
class Staff:public BookDetails,public StudentDetails
{
 public:
  char staff_id[50],value[50];
  void getdata()
  {
  BookDetails b1;
  StudentDetails b2;
  cout<<"Enter your Staff ID: ";
  cin>>staff_id;
  ifstream ifile;
  ifile.open("staff.txt");
  while(!ifile.eof())
  {
  ifile>>value;
  int v=strcmp(staff_id,value);
  if(v==0)
  {
   int t;
   cout<<"\n\t1.Book Details";
   cout<<"\n\t2.Student Details";
   cout<<"\n\t3.Issued Status";
   cout<<"\nEnter your Choice: ";
   cin>>t;
   switch(t)
   {
    case 1:
      b1.Show();
      break;
    case 2:
      b2.Show();
      break;
    case 3:
      b1.IssueBook();
      break;
    default:
     break;
   }
  }
  }
  }
};
void main()
{
 int n;
 char id[50]="123",stid[50];
 clrscr();
 BookDetails ob1;
 StudentDetails ob2;
 Staff ob3;
 cout<<"\n\t\tLIBRARY MANAGEMENT SYSTEM\n";
 cout<<"\t1.Student\n";
 cout<<"\t2.Staff\n";
 cout<<"\t3.Stock Maintenance Officer\n";
 cout<<"Enter your Role: ";
 cin>>n;
 switch(n)
 {
  case 1:
   ob2.getdata();
   break;
  case 2:
   ob3.getdata();
   break;
  case 3:
   cout<<"\nEnter your ID: ";
   cin>>stid;
   int j=strcmp(stid,id);
   if(j==0)
    ob1.getdata();
   else
    cout<<"\n\n\tINVALID";
   break;
  default:
   break;
 }
 getch();
}
