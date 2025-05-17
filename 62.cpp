#include<iostream>
using namespace std;
class date;
class expense;
class id
{
	public:
		int idd;
		expense* next;
	public:
		id(int i)
		{
			idd=i;
			next=nullptr;
		}
};
class expense
{
	public:
		float exp;
		date* next;		
	public:
		expense(float i)
		{
			exp=i;
			next=nullptr;
		}
};
class date
{
	public:
		string dat;
		date* next;
	public:
		date(string d)
		{
			dat=d;
			next=nullptr;
		}
};
class list
{
	public:
		id* head;
	public:
		list():head(nullptr)
		{
			//constructor
		}
		void insertstart(int i,float ii,string iii)
		{
			id* i1=new id(i);
			expense* i2=new expense(ii);
			date* i3=new date(iii);
			i1->next=i2;
			i2->next=i3;
			if(head==nullptr)
			{
				head=i1;
			}
		}
		void print()
		{
			id* temp=head;
			cout<<" "<<temp->idd<<" -> ";
			if(temp->next!=nullptr)
			{
				cout<<temp->next->exp<<" -> ";
				if(temp->next->next!=nullptr)
				{
					cout<<temp->next->next->dat<<endl;
				}
			}
		}
		void increase()
		{
			expense* temp=head->next;
			cout<<" Enter the expense that are increased: ";
			float a;
			cin>>a;
			temp->exp=temp->exp+a;
		}
		void decrease()
		{
			expense* temp=head->next;
			cout<<" Enter the expense that are decreased: ";
			float a;
			cin>>a;
			temp->exp=temp->exp-a;
		}
		void dele()
		{	
			if(head==nullptr)
			{
				return;
			}
			id* temp=head;
			delete temp->next->next;
			delete temp->next;
			delete temp;	
		}	
};
int main()
{
	cout<<"\t\t\t\t\t     Welcome to Expense Management System! "<<endl;
	int i,j=0; float c; string s; char a,end;
	list l[10];
	while(end!='n')
	{
		cout<<" 1) For Add or remove expenses! "<<endl;
		cout<<" 2) For Modify expense! "<<endl;
		cout<<" 3) For Display report of expenses! "<<endl;
		cout<<" Enter your choice ";
		int abc;
		cin>>abc;
		if(abc==1)
		{
			cout<<" You want to Add or remove expense? ";
			string def;
			cin>>def;
			if(def=="add"||def=="Add")
			{
				cout<<" Enter Id: ";
				cin>>i;
				cout<<" Enter Expense: ";
				cin>>c;
				cout<<" Enter Date: ";
				cin.ignore();
				getline(cin,s);
				l[j].insertstart(i,c,s);
				l[j].print();
				j++;
			}
			else if(def=="remove"||def=="Remove")
			{
				cout<<" All expenses are below! "<<endl;
				for(int i=0;i<j;i++)
				{
					cout<<i+1<<")";
					l[i].print();
				}
				cout<<" Which expense do you like to delete ? ";
				int a;
				cin>>a;
				if(a>0)
				{
					l[a-1].dele();
					for(int k=a-1;k<j-1;k++)
					{
						l[k]=l[k+1];
					}
					j--;
				}
			}
		}
		else if(abc==2)
		{
			cout<<" All expenses are below! "<<endl;
			for(int i=0;i<j;i++)
			{
				cout<<i+1<<")";
				l[i].print();
			}	
			cout<<" Which expense do you like to be changed ? ";
			int a;
			cin>>a;
			cout<<" Does your expense increased or decreased? (i/d)";
			char b;
			cin>>b;
			if(b=='i')
			{
				l[a-1].increase();
				l[a-1].print();
			}	
			else if(b=='d')
			{
				l[a-1].decrease();
				l[a-1].print();
			}	
		}
		else if(abc==3)
		{	
			for(int i=0;i<j;i++)
			{
				cout<<i+1<<"  Expense history: ";
				l[i].print();
			}	
		}
		cout<<" Do you want another modification? (y/n)";
		cin>>end;
	}
}
