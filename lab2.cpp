/*Gladys Roman
  CSE330 Lab2
  This program completes a profile of two sorting algorithms by running some tests to collect empirical data.
  June 27, 2019
*/

// libraries
#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// this function sorts a vector by repeatedly finding the minimum element
void selectionSort(vector<int> &v)
{ 	for (int i = 0; i < v.size()-1; i++)
    		for (int j = i + 1; j < v.size(); j++)
        		if (v[i] > v[j])
            			swap(v[i], v[j]);
}

// this function sorts a vector by repeatedly swapping adjacent elements if they're in the wrong order
void bubbleSort(vector<int> &v)
{ 	for (int i = v.size()-1; i > 0; i--)
    		for (int j = 0; j < i; j++)
        		if (v[j] > v[j+1])
            			swap(v[j], v[j+1]);
}

// main
int main()
{
 	clock_t start, finish;
	srand (time(NULL));
	vector<int> v;
	int n = 0;
	cout << "Enter size of input :" ;
	cin >> n;
	for (int i = 0; i < n; i++)
		v.push_back(rand() % 100);
	start = clock();

	//selectionsort(v);
	bubbleSort(v);
	finish = clock();
	cout << "time = " << finish-start << endl;

	return 0;
}
