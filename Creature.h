#pragma once
/*  File: Creature.h
 *  Author: Pat Smith
 *  Date: January, 2022
 *  Purpose: This is the header for the Creature Class.
 * 
 *  Creature is an abstract base class. 
 */
#include "circusHeader.h"

class Creature {
protected:
	string name;
	string description;
	string sound;
	string movement; 

public:
	Creature() {
		name = ""; 
		description = "I am a generic creature. Plain. Vanilla. Boring.";
		sound = "...";
		movement = ""; 
	}
	Creature(string name, string description, string sound, string movement) {
		this->name = name;
		this->description = description;
		this->sound = sound;
		this->movement = movement; 
	}

	/* This perform function calls all the other action functions! - 
	 * It must be provided in the child classes
	 */
	virtual void perform() = 0;
	
	void speak() {
		cout << sound;
	}
	void move() {
		cout << movement;
	}
	string getDescription() {
		return description;
	}

	string getName() {
		return name;
	}

};