#ifndef Included_LIBRARY_H
#define Included_LIBRARY_H
//#include<iostream>
#include "Node.h"

using namespace std;

template < class T , class U>
class Library
{
	private :
		int counter;
		Node<T,U> * head;
	public :
		Library();						//constructor
		~Library();					//destructor
		
		void addBook();					// add book at the end
		
		void deleteBook();			//delete book by index value
		
		void updateBook();		// update book at specific index
		void makeEmpty();				// make the library empty
					
		void display();
		
		void logo();
		void menu();
		void searchBook();		
}; 

#endif