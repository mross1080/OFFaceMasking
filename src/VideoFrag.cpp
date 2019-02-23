//
//  VideoFrag.cpp
//  Basic3dStuff
//
//  Created by Matt Ross on 2/22/19.
//

#include <stdio.h>
#include "VideoFrag.h"

VideoFrag::VideoFrag(){}

void VideoFrag::setup(int _xPos,int _yPos,int _width,int _height, int _subsectionX, int _subsectionY) {
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    height = _height;
    subsectionX = _subsectionX;
    subsectionY = _subsectionY;
    rotateAmount =0;
    
    
}

void VideoFrag::update(ofRectangle object) {
//
    
    int objectX = object.x;
    int objectY = object.y;
    ofLog(OF_LOG_NOTICE, "Incoming Object X Pos is  " + ofToString(objectX));
    ofLog(OF_LOG_NOTICE, "Incomping Width is  " + ofToString(width));
    subsectionX =  ofRandom(objectX, objectX + object.width);
    ofLog(OF_LOG_NOTICE, "Updating Subsection start X Pos to  " + ofToString(subsectionX));

//    subsectionY = ofRandom(yPos, height);
//

    
}

void VideoFrag::reSize(int currentCount) {
    // if  original is 200 and we add one more lets  divide that by that number?
    
    width = width *.75;
    width = height *.75;
    
    
    
    
}
void VideoFrag::draw(ofTexture videoFrag) {
    
    
    videoFrag.drawSubsection(xPos, yPos, width, height, subsectionX,  subsectionY);
    
    
    
}

