#pragma once

#include "ofMain.h"
#include "ofxHomography.h"
#include <array>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		std::array<glm::vec2, 4> originalCorners;
		std::array<glm::vec2, 4> distortedCorners;
		glm::mat4 homography;
		
};
