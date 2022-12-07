//
// Created by bakatrouble on 23/10/22.
//

#include "physics.h"
//#include "box2d/box2d.h"
//
//void physics() {
//    b2Vec2 gravity(0.f, -10.f);
//    b2World world(gravity);
//
//    b2BodyDef groundBodyDef;
//    groundBodyDef.position.Set(-1.f, 0.f);
//    b2Body* groundBody = world.CreateBody(&groundBodyDef);
//    b2PolygonShape groundBox;
//    groundBox.SetAsBox(18.f, 2.f);
//    groundBody->CreateFixture(&groundBox, 0.f);
//
//    b2BodyDef bodyDef;
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.position.Set(8.f, 8.f);
//    b2Body* body = world.CreateBody(&bodyDef);
//    b2PolygonShape dynamicBox;
//    dynamicBox.SetAsBox(3.f, 3.f);
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.3f;
//    body->CreateFixture(&fixtureDef);
//
//    float gz;
//    while (true) {
//        Accelerometer_GetAccel(&gravity.x, &gravity.y, &gz);
//        world.SetGravity(gravity);
//        world.Step(1.f / 10.f, 6, 2);
//        LedMatrix_Fill(0);
//        for (uint8_t x=0; x < 16; x++) {
//            for (uint8_t y=0; y < 18; y++) {
//                auto lp = body->GetLocalPoint(b2Vec2(x, y));
//                if (lp.x >= 0 && lp.x < 3 && lp.y >= 0 && lp.y < 3) {
//                    LedMatrix_SetPixel(x, y, 0x10);
//                }
//            }
//        }
//    }
//}
