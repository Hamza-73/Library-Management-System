//#include<iostream>
//#include<conio.h>
#include "library.h"
using namespace std;

//======================
template < class T , class U>
Library<T,U> :: Library()
{
	counter = 0 ;
	head = NULL ;
}

//======================
template < class T , class U>
Library<T,U> :: ~Library()
{
	makeEmpty();
}

//======================
template < class T , class U>
void Library<T,U> :: addBook()

{
	T title , author ;
	U price;	
	system("cls");
	logo();
	Node<T,U> * temp = new Node<T,U>();
		cout << "\t\tEnter Book Title : ";
		cin>>title;
		temp->setTitle(title);
		cout <<"\n\t\tEnter Book Author : ";
		cin>>author;
		temp->setAuthor(author);
		cout<<"\n\t\tEnter Book Price : ";
		cin>>price;
		temp->setPrice(price);
		int index ;
		cout <<"\n\t\tENTER INDEX AT WHICH YOU WANT TO ADD BOOK : ";
		cin>>index;
		
		if(head==NULL)
		{
			cout <<"\n\t\tTHERE WAS NO BOOK SO THHIS IS THE FIRST BOOK ADDED IN THE LIBRARY\n";
			head = temp ;
			counter++;
		}
		else if(index<0||index>counter+1)
		{
			cout << "\n\t\tERROR: INVALID INDEX";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
		}
		
	else
	{
	
	//At start
	if(index ==  1)
	{
		temp->setNextPtr(head);
		head = temp;
		counter++;
	}
	//At end
	else if(index==counter+1)
	{
		Node<T,U> * current = head;
		
		while(current->getNextPtr() != NULL)
		{
			current = current->getNextPtr();
		}
		current->setNextPtr(temp);
		temp->setNextPtr(NULL);
		counter++;
	}
	//At specific Index
	else
	{
		Node<T,U> * current = head ;
		Node<T,U> * previous ;
		for( int i=1; i<index; i++ )
		{
			previous = current ;
			current = current->getNextPtr() ;
		}
		previous->setNextPtr(temp);
		temp->setNextPtr(current);
		counter++;
	}
}

		cout<<"\n\t\tBOOK ADDED\n\n";
        cout<<("\t\tPress any key to go to the main menu: ");
        getch();
        system("cls");
        menu();
}

//======================
template < class T , class U>
void Library<T,U> :: deleteBook()
{
	int found = 0 ;
	//Checking if list is empty
	if(head==NULL)
	{
		cout<<"\nError : Library is Empty\n";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
	}
	
	int index;
		cout << "\nEnter Index at which you want to delete Book\n";
		cin>>index;
	
	//Validating Index
	if(index<=0 || index>counter)
	{
		cout<<"\nError : Array Index Out Of Bound\n";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
	}
	//First Element
	else if(index==1)
	{
		Node<T,U>* temp = head ;
		head = head->getNextPtr();
		delete temp;
		found++;
		cout<<"\n\t\tBOOK Deleted\n\n";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
	}
	//At end
	else if(index==counter)
	{
		Node<T,U>* current = head;
		Node<T,U>* previous = NULL;
		
		while(current->getNextPtr() != NULL)
		{
			previous = current ;
			current = current->getNextPtr();
		}
		
		previous->setNextPtr(NULL);
		counter--;
		delete current;
		found++;
		cout<<"\n\t\tBOOK Deleted\n\n";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
	}
	//At specific location
	else
	{
		Node<T,U>* current = head;
		Node<T,U>* previous = NULL;
		
		for(int i=1; i<index; i++)
		{
			previous = current;
			current = current->getNextPtr();
		}
		
		previous->setNextPtr(current->getNextPtr());
		counter--;
		delete current;
		found++;
		cout<<"\n\t\tBOOK Deleted\n\n";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
	}
		
		if(found==0){
		cout<<"\n\t\tNo Such Book is Available\n\n";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();	
		}
}
	
//======================
template < class T , class U>
void Library<T,U> :: updateBook()
{
	system("cls");
	logo();
	string bk_title;
	int found=0;
	T title , author;
	U price;
	if( head == NULL )
	{
		cout<<"\n\t\tNO  BOOKS AVAILABLE.";
		return;
	}
	else
	{
		cout<<"\n\n\t\t\tEnter Book Title Which You Want to update: ";
		cin>>bk_title;
		
		Node<T,U> * temp = head ;
		while(temp!=NULL)
		{
			if(bk_title==temp->getTitle())
			{
				cout<<"\n\t\t*******BOOK FOUND*******\n";
				cout<<"\t\tADD DETAILS OF BOOKS TO REPLACE\n";
					cout << "\t\tEnter Book Title : ";
				cin>>title;
				temp->setTitle(title);
				cout <<"\n\t\tEnter Book Author : ";
				cin>>author;
				temp->setAuthor(author);
				cout<<"\n\t\tEnter Book Price : ";
				cin>>price;
				temp->setPrice(price);
				cout<<"\n\t\tBOOK HAS BEEN UPDATED\n";
				found++;
				cout<<("\n\n\t\t\tPress any key to go to the main menu: ");
            	getch();
            	system("cls");
            	menu();
			}
			temp = temp->getNextPtr();
		}
		if(found==0)
		{
			cout<<"\n\t\tNO SUCH BOOK IS AVAILABLE IN LIBRARY\n";
			cout<<("\n\n\t\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
		}
	}
}

//======================
template < class T , class U>
void Library<T,U> :: makeEmpty()
{
	if(head!=NULL)
	{
		Node<T,U>* current = head;
		Node<T,U>* previous;
		while(current->getNextPtr()!=NULL)
		{
			previous = current;
			current=current->getNextPtr();
			head = head->getNextPtr();
			delete previous;
		}
		delete current;
		counter=0;
		head=NULL;
	}
}

//===================
template < class T , class U>
void Library<T,U> :: display()
{
	int num=1;
	system("cls");
	logo();
	Node<T,U> * temp = head ;
	if( head == NULL )
	{
		cout<<"\n\t\tNO BOOKS AVAILABLE\n";
            cout<<("\t\tPress any key to go to the main menu: ");
            getch();
            system("cls");
            menu();
	}
	else
	{
		while(temp!=NULL)
		{
            cout <<"\n\n\t\t===========================================\n\n";
            cout <<"\t\tBook " << num << "\n\n";
			cout<<"\t\tTitle: "<<temp->getTitle()<<endl;
            cout<<"\t\tAuthor: "<<temp->getAuthor()<<endl;
            cout<<"\t\tPrice: "<<temp->getPrice() << endl;
            cout <<"\n\n\t\t===========================================\n\n";
            temp=temp->getNextPtr();
            num++;
		}
		
				cout<<("\n\n\t\t\tPress any key to go to the main menu: ");
            	getch();
            	system("cls");
            	menu();
	}
}

//=================
template<class T , class U>
void Library<T,U> :: logo()
{	
	cout<<("\n\n");
    cout<<("\t\t\t     ****************************************\n");
    cout<<("\t\t\t     *                                      *\n");
    cout<<("\t\t\t     *     ----------------------------     *\n");
    cout<<("\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n");
    cout<<("\t\t\t     *     ----------------------------     *\n");
    cout<<("\t\t\t     *                                      *\n");
    cout<<("\t\t\t     ****************************************\n");
    cout<<("\n\n");
}

//=============
template<class T , class U>
void Library<T,U> :: menu()
{
	p:
	system("cls");
	int choice ;
    cout<<("\n\n\n\t\t\t*************************************************\n");
        cout<<("\n\t\t\t\t      MAIN MENU: ");
        cout<<("\n\t\t\t\t     1.ADD BOOK ");
        cout<<("\n\t\t\t\t     2.DELETE BOOK ");
        cout<<("\n\t\t\t\t     3.SEARCH BOOK");
        cout<<("\n\t\t\t\t     4.UPDATE BOOK");
        cout<<("\n\t\t\t\t     5.SHOW BOOKS");
        cout<<("\n\t\t\t\t     6.EXIT\n ");
        cout<<("\n\t\t\t*************************************************\n");
        cout<<("\n\t\t\t\t      Enter your choice: ");
        cin>>choice;
        
    switch(choice)
    {
    	case 1:
    		addBook();
    		break;
    	case 2:
    		deleteBook();
    		break;
    	case 3:
    		searchBook();
    		break;
    	case 4:
    		updateBook();
    		break;
    	case 5:
    		display();
    		break;
    	case 6:
    		exit(0);
    	default :
    		cout<<"\n\n*********INVALID OPTION*********\n\n";
    				
	}
}

//===========================
template<class T, class U>
void Library<T,U> :: searchBook()
{
	system("cls");
	logo();
	Node<T,U> * temp = head;
	string bk_title;
	if(head==NULL)
	{
		cout<<"\n\t\t\tNo Books Available\n";
		cout<<("\n\n\t\tPress any key to go to the main menu: ");
        getch();
        system("cls");
        menu();
	}
	else
	{
		cout <<"\n\t\tEnter Book Title YOU Want To Search : ";
		cin>>bk_title;
		
		while(temp!=NULL)
		{
			if(temp->getTitle()==bk_title)
			{
           		cout <<"\n\n\t\t===========================================\n\n";
				cout<<"\t\tTitle: "<<temp->getTitle()<<endl;
            	cout<<"\t\tAuthor: "<<temp->getAuthor()<<endl;
            	cout<<"\t\tPrice: "<<temp->getPrice() << endl;
            	cout <<"\n\n\t\t===========================================\n\n";
            	
				cout<<("\n\n\t\tPress any key to go to the main menu: ");
            	getch();
            	system("cls");
            	menu();
			}
			temp=temp->getNextPtr();
		}
		cout <<"NO SUCH BOOK AVAILABLE";
	}
}
