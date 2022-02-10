/*  File: Tent.cpp
 *  Author: Pat Smith
 *  Date: January, 2022
 *  Purpose: The definition file for the functions in the class Tent
 */
#include "circusHeader.h"

/*  Function: default constructor
 *  Purpose:  construct an empty object
 *  Inputs:   none
 *  Returns:  a Tent object
 */
Tent::Tent() {
	name = "The Tent";
	for (int i = 0; i < MAX_EXHIBITS; i++)
		exhibits[i] = nullptr;
	for (int i = 0; i < MAX_EXITS; i++)
		exits[i] = nullptr;
	description = "This is an unused tent. Hopefully soon it will have animals!";
	exitCount = 0;
	creatureCount = 0;
	circusExit = false;
}

/*  Function: constructor
 *  Purpose:  construct an tent object
 *  Inputs:   name, description and boolean if you can exit the circus from here.
 *  Returns:  a Tent object
 */
Tent::Tent(string name, string description, bool exitHere) {
		this->name = name;
		this->description = description;
		circusExit = exitHere;
		for (int i = 0; i < MAX_EXHIBITS; i++)
			exhibits[i] = nullptr;
		for (int i = 0; i < MAX_EXITS; i++)
			exits[i] = nullptr;
		description = "This is an unused tent. Hopefully soon it will have animals!";
		exitCount = 0;
		creatureCount = 0;
		circusExit = exitHere;
}

/*  Function: addExhibit
 *  Purpose:  add a new creature exhibit
 *  Inputs:   a pointer to a creature object. ** NOTE - base abstract class pointer is used here
 *  Returns:  nothing
 */
void Tent::addExhibit(Creature* newCreature) {
	if (creatureCount < MAX_EXHIBITS) {
		exhibits[creatureCount++] = newCreature;
	}
	else
		cout << "Could not add creature " << newCreature->getName() << endl;
}

/*  Function: addExit
 *  Purpose:  add a link to another tent
 *  Inputs:   pointer to another tent object
 *  Returns:  nothing
 */
void Tent::addExit(Tent* newExit) {
	if (exitCount < MAX_EXITS)
		exits[exitCount++] = newExit;
	else
		cout << "Could not add exit to " << newExit->getName();
}

/*  Function: showDescription
 *  Purpose:  Display the information about what's in the tent - animals, exits, etc
 *  Inputs:   none
 *  Returns:  none
 */
void Tent::showDescription() {
	clearScreen();
	colorSetter.saveState(); 
	colorSetter.setColors(Yellow, Black); 
	cout << "welcome to the " << name << " tent!" << endl;
	cout << description << endl;
	colorSetter.restoreState(); 
	// show exhibits
	if (creatureCount == 0) {
		colorSetter.saveState();
		colorSetter.setColors(LightPurple, Black);
		cout << endl << "Sorry, there are no exhibits in this tent. We hope to have something here in the future." << endl;
		colorSetter.restoreState(); 
	}
	else {
		cout << endl << "There are " << creatureCount << " creatures here including: ";
		colorSetter.saveState();
		colorSetter.setColors(Red, Black);
		for (int i = 0; i < creatureCount; i++)
			if (exhibits[i]) {
				cout << exhibits[i]->getName();
				if (i < creatureCount - 2)
					cout << ", ";
				if (i == (creatureCount - 2))
					cout << ", and the ";
			}
		cout << endl;
	}
	colorSetter.restoreState(); 

	// show exit names.
	if (exitCount == 0) {
		colorSetter.saveState();
		colorSetter.setColors(Red, Black);
		cout << "Oh MY!! There don't seem to be any exits from this tent! How did you get in here??";
		colorSetter.restoreState(); 
	}
	else {
		cout << "There are " << exitCount << " exits here. The signs above them say: ";
		for (int i = 0; i < MAX_EXITS; i++)
			if (exits[i]) {
				colorSetter.saveState();
				colorSetter.setColors(Blue, Black);
				cout << "-- \"" << exits[i]->getName() << "\" ";
				colorSetter.restoreState();
			}
		if (circusExit) {
			colorSetter.saveState();
			colorSetter.setColors(Gold, Black);
			cout << endl << "In addition, you can exit the circus here through the large flaps to the north.";
			colorSetter.restoreState();
		}
	}
	cout << DOUBLE_ENDLINE;


	cout << "Now that you're here, What would you like to do next? ";
}

/*  Function: viewAnExhibit
 *  Purpose:  List all creatures, let the user pick one, display it.
 *  Inputs:   nothing
 *  Returns:  nothing
 */
void Tent::viewAnExhibit() {
	int choice = -1; 
	string nullstring;
	clearScreen(); 
	cout << DOUBLE_ENDLINE;
	if (creatureCount == 0) {
		colorSetter.saveState();
		colorSetter.setColors(Yellow, Blue);
		cout << "We're sorry, there are no exhibits to see in this tent.  " << endl;
		cout << "You're welcome to hang out here, but there's just nothing" << endl;
		cout << "to look at.                                              " << endl;
		colorSetter.restoreState(); 
		cout << "Maybe you should take an exit?" << endl;
	}
	else {
		while (choice <= 0 || choice > creatureCount) {
			cout << "We have " << creatureCount << " creatures. Please select a number to view." << endl;
			for (int i = 1; i <= creatureCount; i++) {
				cout << "(" << i << ")" << exhibits[i - 1]->getName() << endl;
			}
			cout << "Which would you like to visit? ";
			choice = getIntegerFromCIN();
			cout << DOUBLE_ENDLINE;
		}
		exhibits[choice - 1]->perform();
	}
	pressAKeyToContinue();
}

/*  Function: takeAnExit
 *  Purpose:  show all the exits from this tent, the user picks one, we return the pointer to that tent
 *  Inputs:   none
 *  Returns:  the pointer to the tent the visitor wants to travel to.
 */
Tent* Tent::takeAnExit() {
	int choice = -1; 
	while (choice < 0 || choice > exitCount) {
		cout << endl << "There are " << exitCount << " exits here. Choose a number for the exit you wish to use: " << endl;
		if (circusExit) {
			colorSetter.saveState();
			colorSetter.setColors(Red, Black);
			cout << "0: exit the circus here through the large flaps to the north." << endl;
			colorSetter.restoreState(); 
		}
		for (int i = 0; i < MAX_EXITS; i++)
			if (exits[i])
				cout << i + 1 << ":" << "-- \"" << exits[i]->getName() << "\" " << endl;;

		cout << "Choice? ";
		choice = getIntegerFromCIN();
		if (choice == 0 && exitCount == 0) {
			colorSetter.saveState();
			colorSetter.setColors(Black, Gold);
			cout << "It looks like you're going to sneak out of the circus " << endl;
			cout << "You quietly slip under the tent flap and head north,  " << endl;
			cout << "avoiding the ticket taker and the red dragon taking a " << endl;
			cout << "break to eat some roast-beast (its favorite meal).    " << DOUBLE_ENDLINE; 
			colorSetter.restoreState(); 
			cout << "BYE!  Please come again, and next time don't go into the tents" <<
				endl << "With no exits." << DOUBLE_ENDLINE;
			exit(0); 
		}
		if (choice == 0 && !circusExit)
			choice = -1; // you can't leave from here. 
	}
	// choice is zero (exit) or a number from 1 - N(umber of doors)
	if (choice == 0)
		return nullptr; // exit the circus
	else
		return exits[choice - 1]; // return the pointer to the next tent.
}