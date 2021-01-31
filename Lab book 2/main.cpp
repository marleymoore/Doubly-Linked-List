/*! \file main.cpp
* Contains the method to run the DLL program.
*/
/*! \mainpage Lab Book 2
 *
 * This program runs a DLL (Double Linked List).
 */

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include "DLLNode.h"
#include "DLL.h"

using namespace std;
string data;

/*! Where I can call and use the different functions created*/
int main() 
{
	int symbol; //!< variable created for user input on what they would like to do
	string ans; //!< string variable to give the newly created nodes data
	DLL<string> myList; //!< lets me call functions
	
	/*! menu options*/
	cout << "Double Linked List/n" << endl;
	cout << "1. Push Node To Head.\n" << "2. Push To Tail.\n" << "3.Push Previous To The Current.\n" << "4.Push Next To The Current.\n" << "5.Pop Head.\n"<< "6.Pop Tail\n" << "7.Move Current Forward\n" << "8.Move current back\n" << "9.Check List\n" << "10. Exit"<< endl;
	
	/*! while loop that requires user input to exit*/
	while (true)
	{

		cin >> symbol;//!<user inputs number
		//!giving user choice to manage list
		/*!
		\if the "symbol" is equal to one then it will execute this code
		\the user can input what string they want
		\calling "my.List" then the desired function with the users answer
		*/
		if (symbol == 1)
		{
			cout << "insert string you would like to add" << endl;
			cin >> ans;
            myList.pushHead(ans);
			cout << ans << endl;
		}

		if (symbol == 2)
		{
			cout << "insert string you would like to add" << endl;
			cin >> ans;
			myList.pushTail(ans);
			cout << ans << endl;
		}

		if (symbol == 3)
		{
			cout << "insert string you would like to add" << endl;
			cin >> ans;
			myList.pushBCurr(ans);
			cout << ans << endl;
		}

		if (symbol == 4)
		{
			cout << "insert string you would like to add" << endl;
			cin >> ans;
			myList.pushACurr(ans);
			cout << ans << endl;
		}

		if (symbol == 5)
		{
			myList.popHead();
		}

		if (symbol == 6)
		{
			myList.popTail();
		}

		if (symbol == 7)
		{
			myList.forwardCurr();
		}

		if (symbol == 8)
		{
			myList.backCurr();
		}

		if (symbol == 9)
		{
			myList.checkList();
		}
		if (symbol == 10)
		{
			return 0;
		}
	}

	

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	
}

