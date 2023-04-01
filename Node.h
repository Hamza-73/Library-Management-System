#ifndef Included_NODE_H
#define Included_NODE_H
#include<iostream>
#include<conio.h>

using namespace std;

template < class T , class U >
class Node
{
	private :
		T author;
		T title;
		U price;
		Node<T,U> * nextPtr;
	public :
		Node();
		Node(T,T,U);
		~Node();
		
		// Setter Methods
//--------------------------------
		void setAuthor(T);
		void setTitle(T);
		void setPrice(U);
		void setNextPtr(Node<T,U> *);
				
	//Getter Methods
//--------------------------------
		T getAuthor();
		T getTitle();
		U getPrice();
		Node<T,U>* getNextPtr();
		
		// Operator overloading
//--------------------------------
	template<class X,class Y>
	friend ostream &operator <<(ostream &, Node<X,Y> &);
//--------------------------------

};

#endif
