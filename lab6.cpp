/* Gladys Roman
 * Lab 6
 * In this program, we develop and implement the concept of trees.
 * July 23, 2019
 */

// libraries
#include <iostream>
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
  	void preorder(Tnode<T> *ptr);
  	void postorder(Tnode<T> *ptr);
  
	private:
  	vector<T> v;
  	Tnode<T> *root;
  	int tsize;
  	bool find(Tnode<T> *tptr, T x);
  	void del(Tnode<T> *ptr, T x);
};

// Mtree class definiton
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

template<typename T>
void Mtree<T> :: preorder(Tnode<T> *ptr)
{	if(ptr == 0)
           	return;
        v.push_back(ptr -> data);
        preorder(ptr -> lptr);
        preorder(ptr -> rptr);
}

template<typename T>
void Mtree<T> :: postorder(Tnode<T> *ptr)
{       if(ptr == 0)
           	return;
        else
        {   	postorder(ptr->lptr);
                postorder(ptr->rptr);
                delete ptr;
        }
}

template<typename T>
void Mtree<T> :: del(T x)
{       if(root -> data == x)
        {	v.clear(); //in case there’s stuff in v already
                preorder(root);
                postorder(root); //this deleted the whole tree
                for(int i = 0; i < v.size(); i++)
                {          if(v[i] != x)
				add(v[i]);
                           else
                                del(root, x);
                }
         }
}

template<typename T>
void Mtree<T> :: del(Tnode<T> *ptr, T x)
{       if(ptr == 0){ return; }
	if(ptr -> lptr -> data == x)
        {      v.clear();
               preorder(ptr -> lptr);
               postorder(ptr -> lptr);  
	       ptr -> lptr = 0;
	       for(int i = 0; i<v.size(); i++)
               {	if(v[i] != x)
                        add(v[i]);
	       }         

	       return;
       }
       if(x <= ptr -> data)
          	del(ptr -> lptr, x);
       else
                del(ptr -> rptr, x);
}

//returns true if x is in tree
template <typename T>
bool Mtree<T> :: find(T x)
{ 	if(tsize == 0) return false;	
	Tnode<T> *tptr = root; //temporary pointer

	return find(tptr, x);
}

template <typename T>
bool Mtree<T> :: find(Tnode<T> *tptr, T x)
{	if(tptr == NULL) 
		return false;
	else if(tptr -> data == x)  
		return true;
	else if(x <= tptr -> data) 
		return find(tptr -> lptr, x);
	else 
		return find(tptr -> rptr, x);
}

// main
int main()
{
 	Mtree<int> li;
 	li.add(3);
 	li.add(10);
 	li.add(20);
 	li.add(6);
 	li.add(9);
 	li.add(50);
 	li.add(60);
 
 	li.del(50);

 	if(li.find(50))
		cout << "50 is in the tree." << endl;
 	else
		cout << "50 is no longer in the tree." << endl;

	return 0;
}

