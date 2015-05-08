#include "ParticleVec2.h"

ParticleVec2::ParticleVec2(){
    radius = 5.0;
    friction = 0.01;
    mass = 1.0;
    position = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity = ofVec2f(0, 0);
}

void ParticleVec2::setup(ofVec2f _position, ofVec2f _velocity){
    position = _position;
    velocity = _velocity;
}
void ParticleVec2::setup(float positionX, float positionY, float velocityX, float velocityY){
    position = ofVec2f(positionX, positionY);
    velocity = ofVec2f(velocityX, velocityY);
}

void ParticleVec2::update(){
    acceleration -= velocity * friction;
    velocity += acceleration;
    position += velocity;
    acceleration.set(0, 0);
}

void ParticleVec2::draw(){
    ofCircle(position.x, position.y, radius);
}

void ParticleVec2::addForce(ofVec2f _force){
    acceleration += _force / mass;
}
void ParticleVec2::addForce(float forceX, float forceY){
    acceleration += ofVec2f(forceX, forceY) / mass;
}

void ParticleVec2::bounceOffWalls(){
    bool bDidICollide = false;
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    if (position.x > maxx){
        position.x = maxx;
        velocity.x *= -1;
        bDidICollide = true;
    } else if (position.x < minx){
        position.x = minx;
        velocity.x *= -1;
        bDidICollide = true;
    }
    if (position.y > maxy){
        position.y = maxy;
        velocity.y *= -1;
        bDidICollide = true;
    } else if (position.y < miny){
        position.y = miny;
        velocity.y *= -1;
        bDidICollide = true;
    }
}

void ParticleVec2::throughOfWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    if (position.x < minx) {
        position.x = maxx;
    }
    if (position.y < miny) {
        position.y = maxy;
    }
    if (position.x > maxx) {
        position.x = minx;
    }
    if (position.y > maxy) {
        position.y = miny;
    }
}