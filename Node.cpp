//#include <iostream>
#include "Node.h"
using namespace std;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 Constructor & Destructor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
template<class T, class U>
Node<T,U> :: Node(T name, T bkname, U RS)
{
	author = name;
	title = bkname;
	price = RS;
	nextPtr = NULL;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T, class U>
Node<T,U> :: Node()
{
	author = "";
	title = "";
	price = 0;
	nextPtr = NULL;
}

//===================================
template<class T, class U>
Node<T,U> :: ~Node()
{
	
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			Setter Methods
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

template<class T, class U>
void Node<T,U> :: setAuthor(T name)
{
	author = name;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T, class U>
void Node<T,U> :: setTitle(T bkName)
{
	title = bkName;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T, class U>
void Node<T,U> :: setPrice(U RS)
{
	price = RS;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T, class U>
void Node<T,U> :: setNextPtr(Node<T,U> *p)
{
	nextPtr = p;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			Getter Methods
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

template<class T, class U>
T Node<T,U> :: getAuthor()
{
	return author;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T, class U>
T Node<T,U> :: getTitle()
{
	return title;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T, class U>
U Node<T,U> :: getPrice()
{
	return price;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T, class U>
Node<T,U>* Node<T,U> :: getNextPtr()
{
	return nextPtr;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Operator Overloading
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
template<class T, class U>
ostream &operator << (ostream &out, Node<T,U> &p)
{
	out<<"Book Title:\t"<<p.getTitle()<<endl;
	out<<"Author Name:\t"<<p.getAuthor()<<endl;
	out<<"Price:\t"<<p.getPrice()<<endl<<endl;
	return out;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		