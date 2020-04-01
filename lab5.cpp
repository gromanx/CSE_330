/* Gladys Roman
 * Lab 5
 * This program develops and implements the concept of linked lists.
 * July 18, 2019
 */

// libraries
#include<iostream>
#include<cassert>
using namespace std;

// Lnode interface
template <typename T>
class Lnode
{
  	public:
  	T data;
  	Lnode *lptr; // left pointer
  	Lnode *rptr; // right pointer
};

// Mlist interface
template <typename T>
class Mlist
{ 	public :
  	typedef Lnode<T>* iterator;
  	Mlist();
  	void add(T x); // add to back
  	void del(); // delete front
  	void del(T x); //deletes nodes with value x;
  	T getfront();
  	T operator[] (unsigned int i);
  	void insert(iterator ix, T x);
  	void erase(iterator ix);
  	void insert(int i, T x);
  	void erase(int i);
  	int size(){return lsize;}
  	void print();

  	private:
  	Lnode<T> *first;
  	Lnode<T> *last;
  	int lsize;
};

// Mlist class definition
template <typename T>
Mlist<T> :: Mlist()
{	lsize = 0;
	first = NULL;
	last = NULL;
}

template <typename T>
void Mlist<T> :: add(T x)
{	Lnode<T> *nnode = new Lnode<T>;	
       	nnode -> data = x;
	nnode -> lptr = last;
	nnode ->rptr = 0;
	if(lsize == 0)
	{	first = nnode;
	}
	else
	{	last -> rptr = nnode;
	}
	last = nnode;
	lsize++;
	return;
}

template <typename T>
void Mlist<T> :: del()
{	if(lsize == 0)
		return;
	else if(lsize == 1)
	{	first = 0;
		last = 0;
		lsize--;
		
		return;
	}
	else
	{	first -> rptr -> lptr = NULL; //deletes the pointer going from 2nd node to 1st (left ptr)
		Lnode<T> *temp = first -> rptr;
		first -> rptr = NULL;
		first = temp;
		lsize--;
	}
}

template <typename T>
void Mlist<T> :: del(T x)
{	if(lsize == 0) 
		return;
	if(first -> data == x)
	{	del();
		del(x);
	}
	else
	{	Lnode<T> *tptr = first;
		while(tptr != NULL)
		{	if(tptr -> data == x)
			{	//we erase
				Lnode<T> *temp;
				tptr -> lptr -> rptr = tptr -> rptr; //makes rptr skip node to next
				tptr -> rptr -> lptr = tptr -> lptr; //now both connection are skipping the node
				temp = tptr -> rptr; //temp = next node on the list
				tptr -> rptr = NULL;
				tptr -> lptr = NULL; // all connections to node are severed
				tptr = temp;
				lsize--;
			}	
			else
				tptr = tptr -> rptr; //moves pointer over. allows us to traverse
		}
	}
}

template <typename T>
T Mlist<T> :: getfront()
{	assert(lsize > 0);
	return first -> data;
}

template <typename T>
T Mlist<T> :: operator[](unsigned int i)
{	assert(i >= 0 && i < lsize);
	Lnode<T> * ptr = new Lnode<T>;
	for(int j = 0; j < i; j++)
		ptr = ptr -> rptr;
	return ptr -> data;
}

template <typename T>
void Mlist<T> :: insert(iterator ix, T x)
{	if(ix == 0)
	{	this -> add(x);
		
		return;
	}
	Lnode<T> * ptr = new Lnode<T>;
	ptr -> data = x;
	if(ix == first)
	{	ptr -> rptr = first;
		ptr -> lptr = 0;
		first -> lptr = ptr;
		first = ptr;
		lsize++;
		
		return;
	}

	ptr -> lptr = ix -> lptr;
	ptr -> rptr = ix;
	ix -> lptr -> rptr = ptr;
	ix -> lptr = ptr;
	lsize++;
	
	return;
}

template <typename T>
void Mlist<T> :: erase(iterator ix)
{	assert(ix != NULL && lsize > 0);
	if(ix == first)
	{	ix -> rptr  -> lptr = 0;
		first = ix -> rptr;
		delete ix;
		lsize--;
	
		return;
	}
	if(ix == last)
	{	last -> lptr -> rptr = 0;
		last = ix -> lptr;
		delete ix;
		lsize--;
	
		return;
	}
	
	//for the middle
	ix -> lptr -> rptr = ix -> rptr;
	ix -> rptr -> lptr = ix -> lptr;
	delete ix;
	lsize--;
	
	return;
}

template <typename T>
void Mlist<T> :: insert(int i, T x)
{	iterator ix = first;
	for(int j = 0; j < i; j++)
		ix = ix -> rptr;
	insert(ix, x);
}

template <typename T>
void Mlist<T> :: erase(int i)
{	assert(i >= 0 && i < lsize);
	iterator ix = first;
	for(int j = 0; j < i; j++)
		ix = ix -> rptr;
	erase(ix);
}

template <typename T>
void Mlist<T> :: print()
{	if(lsize == 0) 
		return;
	Lnode<T> *tptr = first;
	for(int i = 0 ; i < lsize; i++)
	{	cout << tptr -> data << " ";
		tptr = tptr -> rptr;
	}
	cout << endl;
	
	return;
}

// main
int main()
{	//create a new mlist with populated with psuedo-random number generator using add function
	srand(time(NULL));
	Mlist<int> ml = Mlist<int>();
	for(int i = 0; i < 15; i++)
		ml.add(rand() % 100);
	cout << "Pseudo random list: ";

	//use print function
	ml.print();
	int input;
	cout << "Enter a value to be deleted from the list: ";
	cin >> input;

	//use getfront() function
	cout << "New list without 1st value (" << ml.getfront() << ") and " << input << ": ";
	
	//use del() and del(T x) functions
	ml.del();
	ml.del(input);
	ml.print();
	int input2;
	cout << "Enter a position on the list whose value to the right is to be removed: ";
	cin >> input;
	
	//use erase and insert functions
	ml.erase(input);
	cout << "Enter the value you want to replace it with: ";
	cin >> input2;
	ml.insert(input, input2);
	cout << "New list: ";
	ml.print();
	
	return 0;
}
