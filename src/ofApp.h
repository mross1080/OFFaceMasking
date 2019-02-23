#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "VideoFrag.h"


class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    int ySubsectionStart=0;
    Boolean changeFlag = false;
    int xSubsectionStart=0;
    vector <VideoFrag> videoFrags;
    Boolean createdFrags = false;
    ofVideoGrabber cam;
    ofxCv::ObjectFinder finder;
    ofImage sunglasses;
    int fragsToRender =2;
};

