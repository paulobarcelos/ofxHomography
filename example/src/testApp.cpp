#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	originalCorners[0].set(0, 0);
	originalCorners[1].set(100, 0);
	originalCorners[2].set(100, 100);
	originalCorners[3].set(0, 100);
	
	distortedCorners[0].set(0, 0);
	distortedCorners[1].set(400, 0);
	distortedCorners[2].set(400, 400);
	distortedCorners[3].set(0, 400);
}

//--------------------------------------------------------------
void testApp::update(){

	distortedCorners[2].set(mouseX, mouseY);
	homography = ofxHomography::findHomography(originalCorners, distortedCorners);
}

//--------------------------------------------------------------
void testApp::draw(){
	
	// Define a point to be drawn in the warped space
	ofPoint point(80,80);
	
	
	ofPushMatrix();
	glMultMatrixf(homography.getPtr());
	
	ofSetColor(ofColor::yellow);
	ofRect(0, 0, 100, 100);
	
	ofSetColor(ofColor::black);
	ofCircle(50, 50, 30);
	
	// Draw a point in the warped space
	ofSetColor(ofColor::red);
	ofCircle(point, 1);
	
	ofPopMatrix();
	
	// Draw the screen coordinates of that point
	ofSetColor(ofColor::black);
	ofPoint pointInScreen = ofxHomography::toScreenCoordinates(point, homography);
	ofDrawBitmapString("Local coordinates " + ofToString(point) + "\nScreen coordinates " + ofToString(pointInScreen) , pointInScreen);
	
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}