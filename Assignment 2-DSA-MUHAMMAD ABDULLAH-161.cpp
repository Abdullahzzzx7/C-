#include<iostream>
using namespace std;
class date;
class expense;
class list;
class id
{
	public:
		int idd;
		expense* next;
		id* nn;
		id* head;
	public:
		id(int i)
		{	
			idd=i;
			next=nullptr;
			head=nullptr;
			nn=nullptr;
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
			cout<<"======================================"<<endl;
			cout<<" ID: "<<temp->idd;
			if(temp->next!=nullptr)
			{
				cout<<" | Expense: "<<temp->next->exp;
				if(temp->next->next!=nullptr)
				{
					cout<<" | Date: "<<temp->next->next->dat<<endl;
				}
				cout<<"======================================"<<endl;
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
			if(temp->exp-a<=0)
			{
				cout<<" Expense is zero! ";
				cout<<endl;
				temp->exp=0;
				return;
			}
			else
			{
				temp->exp=temp->exp-a;	
			}
		}
		void idreplace(int i)
		{
			id* temp=head;
			temp->idd=i;
		}
		void datereplace(string d)
		{
			id* temp=head;
			temp->next->next=new date(d);
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
		id* gethead()
		{
			return head;
		}
};
class master
{
	public:
    	id* head;
	public:
    	master()
		{
			head=nullptr;
		}
    	void add(id* i)
		{
        	if(head==nullptr)
			{
            	head=i;
        		return;
       		}
        	id* temp=head;
        	while(temp->nn!=nullptr)
			{
            	temp=temp->nn;
        	}
        	temp->nn=i;
    	}
    	void print(int i)
		{
			int a=0;
			if(a==i-1)
			{
				return;
			}
			else
			{
				id* temp=head;
				while(temp!=nullptr)
				{
					cout<<"======================================"<<endl;
					cout<<" ID: "<<temp->idd;
					if(temp->next != nullptr)
					{
						cout<<" | Expense: "<<temp->next->exp;
						if(temp->next->next!=nullptr)
						{
							cout<<" | Date: "<<temp->next->next->dat<<endl;
						}	
					}
					cout<<"======================================"<<endl;
					temp=temp->nn;
				}
				a++;
			}
		}
};
int main()
{
	cout<<"\t\t\t\t\t     Welcome to Expense Management System! "<<endl;
	int i,j=0,aa;float c,total,min,max;string s;char a,end='y',cc;
	list l[10];
	master ml;
	while(end!='n')
	{
		cout<<" ====================================="<<endl;
		cout<<" | 1) For Add or remove expenses!    |"<<endl;
		cout<<" ====================================="<<endl;
		cout<<" | 2) For Modify expense!            |"<<endl;
		cout<<" ====================================="<<endl;
		cout<<" | 3) For Display report of expenses!|"<<endl;
		cout<<" ====================================="<<endl;
		cout<<" Enter your choice: ";
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
				while(!(cin>>i))
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<" Enter valid value: ";
				}
				cout<<" Enter Expense: ";
				while(!(cin>>c))
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<" Enter valid value: ";
				}
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
					l[i].print();
				}
				cout<<" Which expense do you like to delete ? ";
				cin>>aa;
				if(aa>0)
				{
					l[a-1].dele();
					for(int k=aa-1;k<j-1;k++)
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
				l[i].print();
			}	
			cout<<" Which expense do you like to be changed ? ";
			int a;
			cin>>a;
			cout<<" Do you want to change id? (y/n)";
			cin>>cc;
			if(cc=='y')
			{
				cout<<" Enter the id: ";
				int abc;
				cin>>abc;
				l[a-1].idreplace(abc);
			}
			cout<<" Does your expense increased or decreased? (i/d)";
			char b;
			cin>>b;
			if(b=='i')
			{
				l[a-1].increase();
			}	
			else if(b=='d')
			{
				l[a-1].decrease();
			}
			cout<<" You want to change date? (y/n)";
			cin>>cc;
			if(cc=='y')
			{
				cout<<" Enter the date u want to change: ";
				string s;
				cin.ignore();
				getline(cin,s);
				l[a-1].datereplace(s);
			}
			l[a-1].print();	
		}
		else if(abc==3)
		{	
			cout<<" Expense history! "<<endl;
			for(int i=0;i<j;i++)
			{
				l[i].print();
			}			
    		float total=0,min,max;
    		min=l[0].gethead()->next->exp;
    		max=l[0].gethead()->next->exp;
    		for(int i=0;i<j;i++)
    		{
        		float exp=l[i].gethead()->next->exp;
        		total += exp;
        		if(exp<min)
				{
        			min=exp;	
				}
        		if(exp>max)
				{
					max=exp;	
				}
    		}
        	cout<<"|============================|"<<endl;
        	cout<<"| Total Expense:             "<<total<<"|"<<endl;
        	cout<<"| Maximum Expense:            "<<max<<" |"<<endl;
        	cout<<"| Minimum Expense:           " <<min<<"|"<<endl;
        	cout<<"|============================|"<<endl;
		}
		cout<<" Do you want another modification? (y/n)";
		cin>>end;
	}
	cout<<endl;
	cout<<" Details of masterlink list! "<<endl;
	for(int k=0;k<j;k++)
	{
		ml.add(l[k].gethead());
	}
	ml.print(aa);
}