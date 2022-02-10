/*  File: CircusFunctions.cpp
 *  Author: Pat Smith
 *  Date: February, 2022
 *  Purpose: single place for all general purpose functions. 
 */#include "circusHeader.h"


/*  Function: showMenuGetChoice
 *  Purpose: Display the menu for the circus visitor
 *           Collect their input about looking at exhibits or going to another tent.
 *  Inputs: None
 *  Returns: Upper
 */
char showMenuGetChoice() {
	char choice = '\0'; // used to collect user input. set to null to begin.

	// display menu and get user input. 
	while ((choice != '1') && (choice != '2')) {
		cout << "You may: " << endl;
		cout << "   (1) - look at one of the creature exhibits" << endl;
		cout << "   (2) - use one of the exits" << endl;
		cout << "what would you like to do? (enter '1' or '2')? ";
		cin >> choice;
		// secret cheat code to quit.  -- 'b' is for "bye!"
		if (choice == 'b')
			exit(0); 
	}
	return choice; 
}

/*  Function: pressAKeyToContinue
 *  Purpose: pause the execution until user enters a key
 *  Inputs: None
 *  Returns: None
 *  NOTE: This function is specific to Windows. It is not portable
 */
void pressAKeyToContinue() {
	system("pause"); // use the system built in pause. 
}

/*  Function: clearscreen
 *  Purpose: clear the screen
 *  Inputs: None
 *  Returns: None
 *  NOTE: This function is specific to Windows. It is not portable
 */
void clearScreen() {
	system("cls"); 
}

/*  Function: getIntegerFromCIN
 *  Purpose:  get an integer from the cin stream. catch alphas
 *  Inputs:   none
 *  Returns:  integer entered, -1 if alpha entered
 */
int getIntegerFromCIN() {
	int response; // the integer entered by the user
	cin >> response;
	if (cin.fail()) {
		cin.clear();
		response = -1; // default feedback if there's bad input. 
	}
	// skip the newline after the integer, or skip alpha chars if bad input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return response; 
}