/*Gladys Roman
  CSE330 Lab1 Part1
  This program creates a clock using the class Time, then tests the class's functionality in main.
  June 20, 2019
*/

// libraries
#include <iostream>
#include <unistd.h>

using namespace std;

class Time
{
	public:
	Time(int h, int m);
	int gethours() const;
	int getminutes() const;
	void addminute();
	void subtractminute();
	bool operator==(Time t);
	void operator++(); //prefix
	void operator++(int); //postfix
  	void operator--();
   	void operator--(int);
   
	private :
   	int hours;
   	int minutes;
}; // Time class interface
 
// Time class definition
Time::Time(int h, int m)
{ 	hours = h;
  	minutes = m;
}

int Time::gethours() const
{ 	return hours;
}

int Time::getminutes() const
{ 	return minutes;
}

bool Time::operator==(Time t)
{ 	if (this->gethours() != t.gethours()) 
		return false;
  	if (this->getminutes() != t.getminutes()) 
		return false;
  
	return true;
}

void Time::operator++()
{ 	this -> addminute();
}

void Time::operator++(int)
{ 	this -> addminute();
}

void Time::addminute()
{ 	minutes++;
  	if (minutes == 60 )
    	{	minutes=0;
      		hours++;
      	}
   	if (hours == 13)
     	 	hours = 1;
}

void Time::operator--()
{ 	this -> subtractminute();
}

void Time::operator--(int)
{ 	this -> subtractminute();
}

void Time::subtractminute()
{ 	minutes--;
	if(minutes == -1)
  	{  	minutes = 59;
     		hours--;
     		if(hours == 0)
        		hours = 12;
   	}
}


// main
int main()
{
	Time start = Time(1,0);
	cout << "Class starts at: " << start.gethours() << ":" << start.getminutes() << endl;
        start.subtractminute();
        cout << "I arrived at: " << start.gethours() << ":" << start.getminutes() << endl;

        return 0;
}
