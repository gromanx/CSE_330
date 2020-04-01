/* Gladys Roman
 * CSE 330 Lab 4
 * This progrom buils on lab3.cpp by using the class Mvector.
 * July 11, 2019
 */

// libraries
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Mvector interface
template<typename T>
class Mvector
{
 	public:
 	typedef T* iterator;
 	Mvector();
 	Mvector(unsigned int n);
 	void pushback(T x);
 	void popback();
 	void clear();
 	void insert(int i, T x);
 	void erase(int i);
 	T operator[] (unsigned int i);
 	void operator-- (int); 
 	int size();
 	iterator begin() {return v;}
 	iterator end() {return v+vsize;}
 	void insert(iterator ix, T x);
 	void erase(iterator ix);
 
	private:
 	int vsize;
 	int vcap;
 	T *v;
 	void reserve(unsigned int n);
};

// Mvector definition
template <typename T>
Mvector<T> :: Mvector()
{	T *newv = new T[10];
	assert(newv != NULL); //asserts that newv is not pointing to nothing
	vsize = 0; // user hasn’t put anything in vector yet
	vcap = 10;
	v = newv; 
}

template <typename T>
Mvector<T>:: Mvector(unsigned int n) 
{	T *newv = new T[n];
	assert(newv != NULL);
	vsize = n; //n elements and all undefined
	vcap = n;
	v = newv;
}

template <typename T>
void Mvector<T>::reserve(unsigned int n) //from private
{	assert(n > vcap); //reserve creates new array of size n
	T *newv = new T[n]; //new array
	for(int i = 0; i<vsize-1; i++)
	{	newv[i] = v[i]; 
	}
	delete [] v; //deletes old array
	v = newv;
	vcap = n;
}

template <typename T>
void Mvector<T>::pushback(T x)
{	if(vsize < vcap) //we have room to add x
	{	v[vsize] = x;
		vsize++;
	}
	else 
	{	reserve(2 * vcap); //doubles size of the array //func changes value of vcap
		v[vsize] = x;
		vsize++; 
	}
}

template <typename T>
void Mvector<T>::popback()
{	assert(vsize > 0);
	vsize--; 
}

template <typename T>
void Mvector<T>::clear()
{	vsize = 0; //makes vector appear as tho it’s empty
}

template <typename T>
void Mvector<T>::insert(int i, T x)
{	assert(i >= 0 && i<= vsize);
	if(vsize == vcap)
	{	reserve(2 * vcap); 
	}
	for(int  j = vsize; j > i; j --)
	{	v[j] = v[j - 1]; 
	} //shifting everything over to the right by one
	v[i] = x;
	vsize++;
}

template <typename T>
void Mvector<T>::erase(int i)
{	assert(i >= 0 && i < vsize);
	for(int j = i; j < vsize - 1; j++)
	{	v[j] = v[j + 1]; 
	}
	vsize --;
}

template <typename T>
T Mvector<T>::operator[](unsigned int i)
{	assert(i >= 0 && i < vsize);
	return v[i];
}

template <typename T>
void Mvector<T> :: operator-- (int)
{	vsize--;
}

template <typename T>
int Mvector<T>::size()
{	return vsize;
}

template <typename T>
void Mvector<T>::insert(iterator ix, T x)
{	assert((ix - v) >= 0 && (ix - v) <= (vsize + 1)); //assert that iterator is w/i bounds
	int index = ix - v;
	insert(index, x);
}

template <typename T>
void Mvector<T>::erase(iterator ix)
{	assert((ix - v) >= 0 && (ix - v) <= (v + vsize));
	iterator ix1;
	for(ix1 = ix; ix != (--v + vsize); ix1++)
	{	*ix1 = *(++ix1); }
}

// main
int main()
{ 	Mvector<int> v;
  	Mvector<int>::iterator it;
  	v.pushback(10);
  	v.pushback(20);
  	v.pushback(30);
  	v.pushback(40);
  	v.pushback(50);
  	v.pushback(60);
  	v.pushback(70);
  	v.pushback(80);

  	for (int i = 0; i < v.size(); i++)
	  	cout << v[i] << endl;
  	cout << endl;
  
	cout << *v.begin() << endl;
 	cout << *v.end() << endl;
  	cout << v.end() - v.begin() << endl;
  	it = v.end();
  	it--;
  	cout << *it << endl;

  	for (it = v.begin(); it != v.end(); it++)
	  	cout << *it  << endl;
  	
	v.insert(it, 25);
  
	for (int i = 0; i < v.size(); i++)
	  	cout << v[i] << endl;
  
	cout << *(v.begin());

  return 0;
}
