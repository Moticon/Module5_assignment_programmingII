#pragma once
/*  File: Tent.h
 *  Author: Pat Smith
 *  Date: January, 2022
 *  Purpose: The header file for a Tent class 
 *
 *  A "tent" is a location in the circus. 
 */
#include "circusHeader.h"

class Tent {
private:
	Creature* exhibits[MAX_EXHIBITS];	// array of pointers to creatures objects for display
	int creatureCount;					// current number of beasts on display
	string description;					// This is the text description of the tent.
	Tent* exits[MAX_EXITS];				// array of pointers to tents you may visit from here.
	int exitCount;						// current number of exits that are valid in the array
	string name;						// short string - the name of the Tent. 
	bool circusExit;					// Can you leave the circus from this tent? True is possible
	ColorText colorSetter;				// A stub class to allow you to change output text color
public:
	Tent();										// constructor 
	Tent(string name, string description, bool exitHere); // full constructor
	void addExhibit(Creature* newCreature);		// adds a creature to the tent
	void addExit(Tent* newExit);				// adds a link to another tent
	void showDescription();						// display what's in the tent
	void viewAnExhibit();						// display list of exhibits, users chooses
	Tent* takeAnExit();							// display list of exits, user takes one
	string getName() {							// getter for the tent's name. 
		return name; 
	}
};