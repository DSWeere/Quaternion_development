
// Created by dulaj on 7/12/17.
//

#ifndef QUATERNION_H
#define QUATERNION_H

#include <cmath>

typedef struct{
    float x;
    float y;
    float z;
}Euler;

class Quaternion {


public :


    Quaternion(float Nxi, float Nyi, float Nzi, float Nw);

    Quaternion();

    float getX() const;

    float getY() const;

    float getZ() const;

    float getW() const;

    void setX(float val);

    void setY(float val);

    void setZ(float val);

    void setW(float val);

    //Quaternion product
    Quaternion operator * (Quaternion q);

    //Quaternion scaler product
    Quaternion operator * (float t );

    //Quaternion addition
    Quaternion  operator + (Quaternion q);

    //Quaternion subtraction
    Quaternion  operator - (Quaternion q);

    //Quaternion Norm
    float Norm();


    // Normalized the Quaternion
    void Normalize();

    // calculate dot product
    float  Dot (Quaternion q);


    // set conjugate of the current Quaternion
    void Conjugate() ;

    // Quaternion curculer interpolation

    Quaternion SLERP(Quaternion q_new, Quaternion q_old, float t);

    // Quaternion linear interpolation
    Quaternion Lerp (Quaternion q1, Quaternion q2, float t);

    //Quaternion  to euler transform
    Euler QuaternionToEuler ();


    // convert euler angle to Quaternion
    Quaternion EulerToquaternion(float phi, float theta, float psi);

    Quaternion toQuaternion(float pitch, float roll, float yaw);


    float * toEulerianAngle( Quaternion q);


private:
    float Xi = 0;
    float Yi = 0;
    float Zi = 0;
    float W = 0;

};


#endif //QUATERNION_H
