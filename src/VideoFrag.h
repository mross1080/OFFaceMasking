//
//  VideoFrag.h
//  Basic3dStuff
//
//  Created by Matt Ross on 2/22/19.
//

#ifndef VideoFrag_h
#define VideoFrag_h

#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
class VideoFrag {
public:
    void setup(int _xPos,int _yPos,int _width,int _height, int _subsectionX, int _subsectionY);
    void update(ofRectangle object) ;
    void draw(ofTexture videoFrag);
    int xPos;
    int yPos;
    int width;
    int height;
    int subsectionX;
    int subsectionY;
    void reSize(int currentCount);
    int rotateAmount;
    
    
    VideoFrag();
private:
};
#endif /* VideoFrag_h */

