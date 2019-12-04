#include "dysk.h"

dysk::dysk()
{
}


dysk::~dysk()
{
}

void dysk::setup()
{
	radius = ofRandom(20);
	x = ofRandom(0+radius, 1600-radius);
	y = ofRandom(0+radius, 768-radius);		
	R = ofRandom(256);
	G = ofRandom(256);
	B = ofRandom(256);
	vx = ofRandom(-5, 5);
	vy = ofRandom(-5, 5);
	mass = ofRandom(1, 20);
}

