#include "ofMain.h"
#include "ofApp.h"

int main() {
//    ofSetupOpenGL(640, 480, OF_WINDOW);
    ofSetupOpenGL(640*2, 480*2, OF_WINDOW);

    ofRunApp(new ofApp());
}

