/* Gladys Roman
 * Lab 8
 * This program demonstrates how hashing can be used to do direct lookup of data stored in a vector.
 * July 25, 2019
 */

// libraries
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

// hasing function
int hash2(int n)
{	srand (n);
 
	return rand();
}

// string to integer function
int string2int(string s)
{	int h = 0;
 	int d = 1;
 	for (int i = 0; i < s.length(); i++)
 	{	char x = s[i];
   		h += (x) * d;
   		d = d * 10;
 	}

	return h;
}

// main
int main()
{	//#1
 	srand(time(NULL));
 	string s;
 	cout << "enter string: ";
 	cin >> s;
 	cout << string2int(s);
 	cout << endl;
 	cout << hash2(string2int(s)) << endl;

 	//#2
 	int r;
 	cout << "Input a value r: ";
 	cin >> r;
 	vector<int> v;
 	for(int i = 0; i < r; i++)
 		v.push_back(rand() % 100);
 
	//#3
 	int n;
 	cout << "Input a value n: ";
 	cin >> n;
 	vector<int> a;
 	for(int i = 0; i < n; i++)
		a.push_back(-1);

 	//#4 
 	for(int i = 0; i < v.size(); i++)
 	{	int m;
  		m = hash2(v[i]) % n;
		if(a[m] == -1)
			a[m] = i;
		else
			cout << "There is a collision." << endl;
 	}
 
 	return 0;
}
