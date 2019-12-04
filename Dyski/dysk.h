#pragma once
#include "ofMain.h"

class dysk
{
public:
	dysk();
	~dysk();
	
	float x, y, radius, mass, rx, ry, fx, fy;				
	void setup();				//Ustawienie ich
	int R, G, B;		//Kolory
	float vx, vy;		//Predkosci

};

