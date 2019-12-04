#include "ofApp.h"
#include "../dysk.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i < 200; i++) {
		dyski.push_back(dysk());
	}
	for (int i = 0; i < dyski.size(); i++) {
		dyski[i].setup();
	}
	
	ofBackground(ofColor::black);
	cx = 800;
	cy = 380;
	
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


	ofSetColor(ofColor::white);
	ofDrawCircle(cx, cy, 20);

	ofSetColor(106, 90, 205, 120);
	ofDrawRectangle(recx, 0, 200, ofGetHeight());

	float cm = 15500;
	float r, wersorX, wersorY, ax, ay;
	float dt = 0.001;


	for (int i = 0; i < dyski.size(); i++) {
		ofSetColor(dyski[i].R, dyski[i].G, dyski[i].B);
		ofDrawCircle(dyski[i].x, dyski[i].y, dyski[i].radius);
	}


	for (int i = 0; i < dyski.size(); i++) {

		r = sqrt(pow((dyski[i].x - cx), 2) + pow((dyski[i].y - cy), 2));

		if (r <= 20)
			r = ofRandom(13, 16);
		
		wersorX = -(dyski[i].x - cx) / r;
		wersorY = -(dyski[i].y - cy) / r;


		dyski[i].fx = (0.4*dyski[i].mass * cm  / pow(r, 2)) * wersorX;		//Sily
		dyski[i].fy = (0.4*dyski[i].mass * cm  / pow(r, 2)) * wersorY;


		if (dyski[i].x > recx && dyski[i].x < recx+200) {			//Opor
				float fyy = -6 * PI * 2.5 * dyski[i].radius * dyski[i].vy *(ofRandom(1, 5) / 10000);
				float fxx = -6 * PI * 2.5 * dyski[i].radius * dyski[i].vx *(ofRandom(1, 5) / 10000);

				dyski[i].fy += fyy;
				dyski[i].fx += fxx;
		}

		ax = dyski[i].fx / dyski[i].mass;		//Przyspieszenie
		ay = dyski[i].fy / dyski[i].mass;

		float dt = 0.2;
		dyski[i].vx = dyski[i].vx + ax * dt;		//Predkosc
		dyski[i].vy = dyski[i].vy + ay * dt;
			


		dyski[i].x += dyski[i].vx*0.8;		//Polozenie
		dyski[i].y += dyski[i].vy*0.8;

		if (dyski[i].x < 0 + dyski[i].radius || dyski[i].x > 1600 - dyski[i].radius) { dyski[i].vx = -dyski[i].vx; }		//Odbicie
		if (dyski[i].y < 0 + dyski[i].radius || dyski[i].y > 768 - dyski[i].radius) { dyski[i].vy = -dyski[i].vy; }

	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	if (key == OF_KEY_BACKSPACE) {
		dyski.erase(dyski.begin() + int(ofRandom(dyski.size() - 1)));
	}
	if (key == 'n') {
		dysk a;
		a.setup();
		dyski.push_back(a);
	}
	if (key == OF_KEY_LEFT) {		//Przesuwanie paska
		if (recx > 0) {
			recx -= 3;
		}
	}
	if (key == OF_KEY_RIGHT) {
		if (recx < ofGetWidth()-200) {
			recx += 3;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	cx = x;		//Zmiana punktu
	cy = y;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
