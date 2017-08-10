#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetBackgroundAuto(false);
	ofSetWindowTitle("Insta");
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int angle_step = 30;

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	ofPushMatrix();

	ofSetLineWidth(0.3);
	ofSetColor(128);
	for (int i = 0; i < 360; i += angle_step / 2) {
		ofRotate(angle_step / 2);
		ofLine(ofVec2f(0, 0), ofVec2f(ofGetWidth(), 0));
	}

	ofPopMatrix();

	ofSetLineWidth(5);
	ofSetColor(255);

	Leap::Frame frame = leap.frame();
	for (Leap::Hand hand : frame.hands()) {
		if (hand.isRight()) {
			for (Leap::Finger finger : hand.fingers()) {
				if (finger.type() == Leap::Finger::Type::TYPE_INDEX) {
					this->pre_index_position = this->index_position;
					this->index_position = ofVec3f(finger.tipPosition().x, -finger.tipPosition().y, 0);
				}
			}
		}
	}

	if (pre_index_position != ofVec3f(0, 0, 0)) {
		for (int i = 0; i < 360; i += angle_step) {
			ofPushMatrix();

			ofRotateZ(i);
			ofLine(index_position, pre_index_position);

			ofRotateY(180);
			ofLine(index_position, pre_index_position);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		ofBackground(0);
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
