#include "circusHeader.h"

void MagicalBeast::perform() {
	cout << "Now Presenting.... the " << name << "!!" << endl;
	cout << "See how it moves!" << endl << "   ";
	move();
	cout << endl << "Listen to it speak! " << endl << "  ";
	speak();
	cout << endl << "All Magical beasts have a special quality! " << endl;
	cout << "This beast's magic quality is: " << magicalQuality;
	cout << DOUBLE_ENDLINE << "Thank you for visiting the " << name << endl;
}