#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	originalCorners = {{
		{ 0.0f, 0.0f },
		{ 100.0f, 0.0f },
		{ 100.0f, 100.0f },
		{ 0.0f, 100.0f }
	}};
	
	distortedCorners = {{
		{ 0.0f, 0.0f },
		{ 400.0f, 0.0f },
		{ 400.0f, 400.0f },
		{ 0.0f, 400.0f }
	}};
}

//--------------------------------------------------------------
void ofApp::update(){

	distortedCorners[2] = glm::vec2(mouseX, mouseY);
	homography = ofxHomography::findHomography(originalCorners, distortedCorners);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Define a point to be drawn in the warped space
	glm::vec2 point(80, 80);
	
	ofPushMatrix();
	ofMultMatrix(homography);
	
	ofSetColor(ofColor::yellow);
	ofDrawRectangle(0, 0, 100, 100);
	
	ofSetColor(ofColor::black);
	ofDrawCircle(50, 50, 30);
	
	// Draw a point in the warped space
	ofSetColor(ofColor::red);
	ofDrawCircle(point, 1);
	
	ofPopMatrix();
	
	// Draw the screen coordinates of that point
	ofSetColor(ofColor::black);
	glm::vec2 pointInScreen = ofxHomography::toScreenCoordinates(point, homography);
	ofDrawBitmapString("Local coordinates " + ofToString(point) + "\nScreen coordinates " + ofToString(pointInScreen) , pointInScreen);
	
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
