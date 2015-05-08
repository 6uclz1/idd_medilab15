#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void setup(ofVec2f position, ofVec2f velocity);
    void setup(float positionX, float positionY, float velocityX, float velocityY);
    void update();
    void draw();
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f force;
    float friction;
    float radius;
    float mass;
};