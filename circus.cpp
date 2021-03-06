/*  File: circus.cpp
 *  Author: Pat Smith
 *  Date: January, 2022
 *  Purpose: The main function
 */
#include "circusHeader.h"

 /*  Function: main function
  *  Purpose:  Run the main program - create creatures, tents, populate tents, connect tents. run loop. 
  *  Inputs:   none
  *  Returns:  int status (always zero)
  */
int main() {
	/**********************************************
	 * Here at the start of main you'll need to define all your creatures. 
	 * You can't use the abstract base class "Creature" to create these objects.
	 * You must use your derived child classes here. 
	 * Define each creature by name here. 
	 * The creature constructors can vary depending on what you add. 
	 * 
	 * Create all your creature exhibits here!
	 **********************************************/
	// here's an example of declaring a "magicalBeast" if you had such a class
	//MagicalBeast chimera("Chimera", 
	//	                 "The magnificent 3 headed creature of the Greek Mythos!", 
	//	                 "Rooarrrr!!",
	//	                 "It flies! It runs! It Leaps -- Lookout there!!", 
	//	                 "its hide can't be peirced by metal!");


	/**********************************************
	 * Here you create your tent objects. The Tent constructor expects 2 strings and a boolean value
	 *  The first string is a brief name, like you see on a sign outside the tent. 
	 *  The second string is a longer sting that describes what a person sees when they enter the tent. - 
	 *       Be descriptive -- don't be too short or the user will have a boring time walking through tents
	 *  the third value is 'true' if you can exit the circus from the tent. It is false if you can't leave the circus from this tent
	 * 
	 * I've made four tents as an example for you. 
	 * you must create your own tents. 
	 **********************************************/
	Tent ticketTent("Tickets", "You are in a small tent that sells tickets. From here you can leave the circus.", true); 
	Tent dragonTent("Dragons!", "You're in a vast tent with large menacing creatures quietly waiting", false); 
	Tent beastTent("Magical Beasts", "You're in a smaller tent with mythical creatures you can watch!", false); 
	Tent storageTent("Storage Tent", "This tent is filled with boxes, cobwebs, and rusting detritus", false); 

	// Other variables declared here.  
	// Do not change this section. 
	char choice;						// used for collecting the user input. 
	Tent* currentTent = &ticketTent;  // a pointer to the current tent - visitors start in the ticket tent.

	/***********************************************
	 * Here you connect the tents.
	 * Each of the tents you define above should be linked to and from other tents.
	 * it's possible to have one way links between the tents, but all of these connections
	 * are two-way (except for the storageTent, which has no exits). 
	 */
	// connect the ticketTent to the dragon tent and the beast tent. 
	ticketTent.addExit(&dragonTent);
	ticketTent.addExit(&beastTent); 

	// you would need other sections connecting the other tents to the each other
	// according to your circus "map". 

	/***********************************************
     * Add all your creatures to the tents they belong in. 
	 *  -- NOTE -- You must add a pointer to the object so 
	 *     pass the address of an object. 
	 *  EXAMPLE. If you have a creature object called a "chimera" 
	 *    like the example above, the command would be:
	 * 
	 *      "beastTent.addExhibit(&chimera);"
     */



	/* ************ DO NOT CHANGE CODE BELOW THIS LINE *************************
	 *  
	 *  Here's the main loop.  using the current tent pointer:
	 *    -- Show the description of the tent. 
	 *    -- then get a choice (look at exhibits or use an exit)
	 *  then if they want to look at an exhibit call the current tent's 'viewAnExhibit()' method.
	 *           viewAnExhibit simply lets them choose an exhibit. It will be shown. 
	 *       if they want to use an exit then call the tent's "takeAnExit()" method
	 *          This method returns the pointer to the tent they moved to. 
	 *          The returned pointer is assigned to the current pointer - thus the currentTent  
	 *             points at the tent the user moved into.  
	 *          if the user exits the circus then a nullptr is returned, ending the loop. 
	 */
	while (currentTent != nullptr) {
		currentTent->showDescription();
		choice = showMenuGetChoice(); 
		if (choice == '1') // look at exhibits
			currentTent->viewAnExhibit();
		else               // go to another tent. 
			currentTent = currentTent->takeAnExit(); 
	}

	/* Say goodnight Gracie */
	cout << DOUBLE_ENDLINE; 
	cout << "Thanks for visiting the circus." << endl;
	pressAKeyToContinue();
	return 0; 
}