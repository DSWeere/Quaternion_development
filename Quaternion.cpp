
//
// Created by dulaj on 7/12/17.
//

#include "Quaternion.h"




Quaternion :: Quaternion (float Nxi, float Nyi, float Nzi, float Nw) {
    Xi  = Nxi;
    Yi  = Nyi;
    Zi  = Nzi;
    W   = Nw;
}

Quaternion :: Quaternion()
{   Xi   = 0.0;
    Yi   = 0.0;
    Zi   = 0.0;
    W   =  1.0;
}

float Quaternion:: getX() const  { return Xi; }
float Quaternion:: getY() const  { return Yi; }
float Quaternion:: getZ() const  { return Zi; }
float Quaternion:: getW() const  { return W;  }

void Quaternion:: setX(float val) { Xi = val; }
void Quaternion:: setY(float val) { Yi = val; }
void Quaternion:: setZ(float val) { Zi = val; }
void Quaternion:: setW(float val) { W = val; }


// calculate quaternion product
Quaternion Quaternion :: 	operator * (Quaternion q)
{
    return Quaternion
            (

            W * q.Xi + Xi * q.W + Yi * q.Zi - Zi * q.Yi,
            W * q.Yi + Yi * q.W + Zi * q.Xi - Xi * q.Zi,
            W * q.Zi + Zi * q.W + Xi * q.Yi - Yi * q.Xi,
            W * q.W  - Xi * q.Xi - Yi *q.Yi - Zi * q.Zi

            );

}

// calculate quaternion scalar product
// non-commutative
Quaternion Quaternion :: operator * (float t)
{
    return Quaternion( Xi * t,Yi * t,Zi * t, W * t);
}



// calculate quaternion  addition
Quaternion Quaternion :: operator + (Quaternion q)
{
    return Quaternion(	    q.Xi+Xi,
                            q.Yi+Yi,
                            q.Zi+Zi,
                            q.W+W );
}


// calculate scalar product
Quaternion Quaternion::  operator - (Quaternion q)
{
    return Quaternion(	 Xi- q.Xi ,
                         Yi- q.Yi ,
                         Zi- q.Zi ,
                         W - q.W );
}

// calculate quaternion norm (ABS)
float Quaternion :: Norm()
{
    return sqrt( Xi*Xi	+	Yi*Yi	+	Zi*Zi	+	W*W);
}

// set quaternion to normalized one
void Quaternion::Normalize()
{
    float norm_q = Norm();
    if(norm_q !=0)
    {
        Xi = Xi / norm_q;
        Yi = Yi / norm_q;
        Zi = Zi / norm_q;
        W = W / norm_q;
    }
    else
    {
        Xi = 0;
        Yi = 0;
        Zi = 0;
        W =  0;
    }

}

// calculate dot product of two quaternion
float  Quaternion:: Dot(Quaternion q)
{

    return 	q.Xi * Xi	+	q.Yi * Yi	+	q.Zi *Zi	+ q.W * W;
}

// set conjugate of the current quaternion
void Quaternion::Conjugate()
{
    Xi= -Xi ;
    Yi= -Yi ;
    Zi= -Zi ;
    W =  W  ;
}
//calculate Quaternion circular interpolation
Quaternion Quaternion::SLERP(Quaternion q_new, Quaternion q_old, float t)
{
    Quaternion q(0, 0, 0, 1);
    q_new.Normalize();
    q_old.Normalize();
    float theta = acos(q_new.Dot(q_old));
    q = q_new * (sin(theta * (1 - t)) / sin(theta)) +
        q_old * (sin(theta * t) / sin(theta));
    return q;
}

//calculate quaternion linear interpolation
Quaternion  Quaternion::Lerp(Quaternion q1, Quaternion q2, float t)
{
    return ((q1*(1 - t)) + (q2* t));
}

///calculate ZYX euler angle using quaternion

Euler Quaternion::QuaternionToEuler ()
{


    Quaternion q1;
    q1.setX(Xi);
    q1.setY(Yi);
    q1.setZ(Zi);
    q1.setW(W) ;
    q1.Normalize();
    float sqy = q1.getY() * q1.getY();

    Euler v;
    // roll (x-axis rotation)
    float t0 = +2.0 * (q1.getW()* q1.getX() + q1.getY() * q1.getZ());
    float t1 = +1.0 - 2.0 * (q1.getX() * q1.getX() + sqy);
    v.x = atan2(t0, t1);

    // pitch (y-axis rotation)
    float t2 = +2.0 * (q1.getW() * q1.getY() - q1.getZ() * q1.getX());

    t2 = ((t2 > 1.0) ? 1.0 : t2);
    t2 = ((t2 < -1.0) ? -1.0 : t2);

    v.y = asin(t2);

    // yaw (z-axis rotation)
    float t3 = +2.0 * (q1.getW() * q1.getZ() +q1.getX() * q1.getY());
    float t4 = +1.0 - 2.0 * (sqy + q1.getZ() * q1.getZ());
    v.z = atan2(t3, t4);

    return v;
}

//calculate euler quaternion using euler angle
Quaternion Quaternion:: EulerToquaternion(float phi, float theta, float psi)
{
    float cosPsi = (float)cos(psi * 0.5);
    float sinPsi = (float)sin(psi * 0.5);

    float cosTheta = (float)cos(theta * 0.5);
    float sinTheta = (float)sin(theta * 0.5);

    float cosPhi = (float)cos(phi * 0.5);
    float sinPhi = (float)sin(phi * 0.5);

    Quaternion q (cosPsi * cosTheta * cosPhi + sinPsi * sinTheta * sinPhi,
                  -(cosPsi * cosTheta * sinPhi - sinPsi * sinTheta * cosPhi),
                  -(cosPsi * sinTheta * cosPhi + sinPsi * cosTheta * sinPhi),
                  -(sinPsi * cosTheta * cosPhi - cosPsi * sinTheta * sinPhi));

    return q;
}

Quaternion Quaternion :: toQuaternion(float pitch, float roll, float yaw)
{
    Quaternion q;
    float t0 = cos(yaw * 0.5);
    float t1 = sin(yaw * 0.5);
    float t2 = cos(roll * 0.5);
    float t3 = sin(roll * 0.5);
    float t4 = cos(pitch * 0.5);
    float t5 = sin(pitch * 0.5);

    q.W  = t0 * t2 * t4 + t1 * t3 * t5;
    q.Xi = t0 * t3 * t4 - t1 * t2 * t5;
    q.Yi = t0 * t2 * t5 + t1 * t3 * t4;
    q.Zi = t1 * t2 * t4 - t0 * t3 * t5;
    return q;
}

float * Quaternion::toEulerianAngle( Quaternion q)
{
    float euler[3];
    q.Normalize();

    float ysqr = q.getY() * q.getY();

    // roll (x-axis rotation)
    float t0 = +2.0 * (q.getW() * q.getX() + q.getY() * q.getZ());
    float t1 = +1.0 - 2.0 * (q.getX() * q.getX() + ysqr);
    euler[0] = atan2(t0, t1);

    // pitch (y-axis rotation)
    float t2 = +2.0 * (q.getW()* q.getY() - q.getZ() * q.getX());
    t2 = ((t2 > 1.0) ? 1.0 : t2);
    t2 = ((t2 < -1.0) ? -1.0 : t2);
    euler[1] = asin(t2);

    // yaw (z-axis rotation)
    float t3 = +2.0 * (q.getW() * q.getZ() + q.getX() * q.getY());
    float t4 = +1.0 - 2.0 * (ysqr + q.getZ() * q.getZ());
    euler[2] = atan2(t3, t4);

    return euler;
}




