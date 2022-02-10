#pragma once
#include "circusHeader.h"

class MagicalBeast : public Creature {
private:
	string magicalQuality;

public:
	MagicalBeast() : Creature() {
		magicalQuality = ""; 
	}

	MagicalBeast(string name, string description, string sound, string movement, string quality) : Creature(name, description, sound, movement)
	{
		magicalQuality = quality;
	};

	virtual void perform();

	string getQuality() {
		return magicalQuality;
	}
};