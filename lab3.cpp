/*Gladys Roman
  CSE330 Lab 3
  This program develops and implements a class PQ (priority queue) using the vector STL. The class works for any data type that supports the < operator.
  July 16, 2019
*/

// libraries
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// PQ interface
template <typename T>
class PQ
{	public:
		PQ(); //default constructor
		PQ(vector<T> x); //accepts a vector and sorts it
		int size(); //return size of the que
		T getfront(); //return front of the list
		void print(); //print entire que
		void add(T x); //add element to que while keeping the list ordered
		void remove(T x); //remove front of the que
	
	private:
		vector<T> STL;
		void bubblesort();
		int vsize;
};

// PQ definition
template <typename T>
PQ<T> :: PQ()
{	vsize = 0;
}

template <typename T>
PQ<T> :: PQ(vector<T> x)
{	STL = x;
	vsize = x.size();
	bubblesort();
}

template <typename T>
void PQ<T> :: bubblesort()
{	for (int i = STL.size()-1; i > 0; i--)
    		for (int j = 0; j < i; j++)
        		if (STL[j] > STL[j+1])
            			swap(STL[j], STL[j+1]);
}

template <typename T>
int PQ<T> :: size()
{	return vsize;
}

template <typename T>
T PQ<T> :: getfront()
{	assert(vsize > 0);
	return *(STL.begin());
}

template <typename T>
void PQ<T> :: print()
{	for(int i = 0; i < STL.size(); i++)
	{	cout << STL[i] << " ";
	}
	cout << endl;
}

template <typename T>
void PQ<T> :: add(T x)
{	for(int i = 0; i < vsize; i++)
	{	if(x < STL[i])
		{	STL.insert((STL.begin()+i), x);
			vsize++;
			return;
		}

	}	
	STL.push_back(x);
	vsize++;
}

template <typename T>
void PQ<T> :: remove(T x)
{	assert(vsize > 0);	
	STL.erase(STL.begin());
	vsize--;
}

// main
int main()
{
  	int r = 0,n = 0;
  	cout << "Enter r: ";
  	cin >> r;
  	cout << "Enter n: ";
  	cin >> n;

  	vector<int> v;
  	srand (time(NULL));

  	for (int i = 0; i <= r; i++)
      		v.push_back(rand() % 100);
  
	PQ<int> pq1 = PQ<int>(v);
  	PQ<int> pq2 = PQ<int>();
  	
	for (int i = 0; i <= n; i++)
      		pq2.add(rand() % 100);
  
	cout << "r: ";
  	pq1.print();
  	cout << "n: ";
  	pq2.print();
  	cout << "Size of r: " << pq1.size() << endl;
  	cout << "First element of n: " << pq2.getfront() << endl;
  	pq2.remove(pq2.getfront());
  	cout << "New n: ";
  	pq2.print();

  	return 0;
}
