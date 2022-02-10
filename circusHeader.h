#pragma once
/*  File: Color.h
 *  Author: Pat Smith
 *  Date: January, 2022
 *  Purpose: The header file for a class to control console text color
 *
 *  Note on the class "Color" - everything is implemented in this header
 *    file in order to improve portability.
 */
// include files here.
#include <string>
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <limits> 

#undef max // this is here to remove the macro "max()" which overrides the max function I need for max stream size. 

using namespace std; 

// Constants
const int MAX_EXHIBITS = 5;				// how many creature exhibits per tent
const int MAX_EXITS = 3;				// how many exits per tent?
const string DOUBLE_ENDLINE = "\n\n";   // used for putting out two endlines... not efficient... I just like it.

void clearScreen();			// clear the console screen
char showMenuGetChoice();	// show menu of options, return entered choice
void pressAKeyToContinue();	// pause the program til user enters a choice
int getIntegerFromCin();	// get an integer, handling errors if alpha chars entered

// All the include files 
/*  NOTE -- You'll need to put "Creature.h" before your child classes
 *          and you'll need to put "Creature.h" before the Tent.h here
 */
#include "ColorText.h"

// Put your class heirarchies here
#include "Creature.h"
// your child class go here, like on the next line, but you'll have your own child class header files to include. 
// #include "MagicalBeast.h"
#include "Tent.h"

