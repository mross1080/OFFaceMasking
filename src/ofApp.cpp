#include "ofApp.h"
#include "VideoFrag.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    finder.setup("/Users/mattross/Desktop/haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);
    finder.getTracker().setSmoothingRate(.3);
    cam.setup(640, 480);
    sunglasses.load("/Users/mattross/Desktop/mattface.png");
    ofEnableAlphaBlending();
    fragsToRender = 4;
    
    
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        finder.update(cam);
    }
    
    

    
}

void ofApp::draw() {
    cam.draw(0, 0);
    
    for(int i = 0; i < finder.size(); i++) {
        
        
        
        
        ofRectangle object = finder.getObjectSmoothed(i);
        ofTexture videoFrag = cam.getTexture();
videoFrag.setAnchorPercent(.5, .5);
        float scaleAmount = .85 * object.width / sunglasses.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
        ofScale(scaleAmount, scaleAmount);

  
        
        if (!createdFrags) {
            
            VideoFrag tempVideoFrag;
            VideoFrag tempVideoFrag1;
            
            ofLog(OF_LOG_NOTICE, "Object Width is " + ofToString(object.getWidth()));
            ofLog(OF_LOG_NOTICE, "Object Height is " + ofToString(object.getHeight()));
            
            ofLog(OF_LOG_NOTICE, "Object X Start is " + ofToString(object.x));
            ofLog(OF_LOG_NOTICE, "Object Y Start is " + ofToString(object.y));

            for (int i = 0 ; i<fragsToRender/2; i++) {
                for (int j = 0 ; j<fragsToRender/2; j++) {

                VideoFrag tempVideoFrag;
                ofLog(OF_LOG_NOTICE, "Frag Y Start is " + ofToString(i * (object.getHeight()/fragsToRender)));

                tempVideoFrag.setup(i * (object.getWidth()/fragsToRender),  j * (object.getHeight()/fragsToRender), object.getWidth()/fragsToRender, object.getHeight()/fragsToRender, object.x + object.width / 4., object.y + object.height * .22);
                
                videoFrags.push_back(tempVideoFrag);
                
                }
                
                
            }
//
//
//
//            tempVideoFrag.setup(0, 0, object.getWidth()/2, object.getHeight()/2, object.x + object.width / 4., object.y + object.height * .22);
//
//            videoFrags.push_back(tempVideoFrag);
//
//            tempVideoFrag1.setup(0, object.getHeight()/2, object.getWidth()/2, object.getHeight()/2, object.x + object.width / 3., object.y + object.height * .72);
//
//            videoFrags.push_back(tempVideoFrag1);
            
            createdFrags = true;
            
        }
        
        if(changeFlag) {
            for (int i = 0 ; i<videoFrags.size(); i++) {
                videoFrags[i].update(object);
            }
            
            changeFlag = false;
            
        }
        
        for (int i = 0 ; i<videoFrags.size(); i++) {
            videoFrags[i].draw(videoFrag);
        }
        // X ,Y, Width , Height , Subsection Start x, SS Y
//        videoFrag.drawSubsection(0, 0, object.getWidth()/2, object.getHeight()/2, object.x + object.width / 2., object.y + object.height * .42);
//        videoFrag.drawSubsection(0, object.getHeight()/2, object.getWidth()/2, object.getHeight()/2, object.x + object.width / 2., object.y + object.height * .42);
        
        
        
//               videoFrag.drawSubsection(0, object.getHeight()/2, object.getWidth()/2, object.getHeight()/2, object.x + object.width / 2., ySubsectionStart );

        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
    }
}

void ofApp::keyPressed(int key){
    changeFlag = true;
    


    
}
