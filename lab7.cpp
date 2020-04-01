/* Gladys Roman
 * Lab 7
 * This program builds on lab6.cpp, in regard to trees.
 * July 23, 2019
 */

// libraries
#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>

using namespace std;

// Tnode interface
template <typename T>
class Tnode
{
  	public:
  	T data;
  	Tnode *lptr;
  	Tnode *rptr;
};

// Mtree interface
template <typename T>
class Mtree
{ 	public:
  	Mtree();
  	void add(T x);
  	void del(T x);
  	bool find(T x);
  	vector<T> inorder();
  
	private :
  	vector<T> v;
  	void inorder(Tnode<T> *tptr);
  	Tnode<T> *root;
  	int tsize;
  	bool find(Tnode<T> *tptr, T x);
  	void del(Tnode<T> *ptr, T x);
};

// Mtree class definition
template <typename T>
Mtree<T> :: Mtree()
{	root = NULL;
	tsize = 0;	
}

//add element to tree
template <typename T>
void Mtree<T> :: add(T x)
{ 	if(tsize == 0)
	{	Tnode<T> *nnode = new Tnode<T>;
		nnode -> data = x;
		nnode -> lptr = NULL;
		nnode -> rptr = NULL; //bc there's nothing in the tree
		tsize++; //tsize is now 1
		root  = nnode;
	
		return;
	}
	else
	{	Tnode<T> *tnode = root; //temporary pointer that'll help traverse the tree
		Tnode<T> *nnode = new Tnode<T>;
		nnode -> data = x;
		nnode -> lptr = NULL;
		nnode -> rptr = NULL;
		while(tnode != NULL) 
		{	if(nnode -> data <= tnode -> data) //if x <= data go to left else go right
			{	if(tnode -> lptr == NULL)
				{	tnode -> lptr = nnode;
	
					return;
				}
				tnode = tnode -> lptr; //move over to left by 1 node
			}
			else
			{	if(tnode -> rptr == NULL)
				{	tnode -> rptr = nnode;
	
					return;
				}
				tnode = tnode -> rptr;
			}
		}
	}
}

//returns true if x is in tree
template <typename T>
bool Mtree<T> :: find(T x)
{ 	if(tsize == 0) 
		return false;	
	Tnode<T> *tptr = root; //temporary pointer
	
	return find(tptr, x);
}

template <typename T>
bool Mtree<T> :: find(Tnode<T> *tptr, T x)
{	if(tptr -> data == x) 
		return true;
	else if(tptr == NULL)	
		return false;
	else if(x <= tptr -> data) 
		return find(tptr -> lptr, x);
	else 
		find(tptr -> rptr, x);
}

//vector that we're returning
template <typename T>
vector<T> Mtree<T> :: inorder()
{	v.clear();
	inorder(root);
	
	return v;
}

template <typename T>
void Mtree<T> :: inorder(Tnode<T> *tptr)
{	if(tptr == NULL) 
		return;
	else
	{	inorder(tptr -> lptr);
		v.push_back(tptr -> data);
		inorder(tptr -> rptr);
	}
	return;
}

// main
int main()
{
	clock_t start, finish;
	srand (time(NULL));
	Mtree<int> t;
	int n=0;
	cout << "Enter size of input : " ;
	cin >> n;
	for (int i = 0; i < n; i++)
		t.add(rand());
	start = clock();
	vector<int> v = t.inorder();
	finish = clock();
	cout << "time= " << finish - start << endl;
}
