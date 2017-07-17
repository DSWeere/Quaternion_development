#include <iostream>
#include "Quaternion.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cmath>


TEST_CASE("Quaternion getW function check for identity Quaternion","Q.W")
{
    REQUIRE(Quaternion().getW()==1);
}
TEST_CASE("Quaternion getX function check for identity Quaternion","Q.X")
{
    REQUIRE(Quaternion().getX()==0);
}
TEST_CASE("Quaternion getY function check for identity Quaternion","Q.Y")
{
    REQUIRE(Quaternion().getY()==0);
}
TEST_CASE("Quaternion getZ function check for identity Quaternion","Q.Z")
{
    REQUIRE(Quaternion().getZ()==0);
}
TEST_CASE("Quaternion getW function check for input (0.5,0.3,0.1,0.7) ","Q.W")
{
    REQUIRE(Quaternion(0.5,0.3,0.1,0.7).getW()==0.7f);
}
TEST_CASE("Quaternion getX function check for input (0.5,0.3,0.1,0.7) ","Q.X")
{
    REQUIRE(Quaternion(0.5,0.3,0.1,0.7).getX()==0.5);
}
TEST_CASE("Quaternion getY function check for input (0.5,0.3,0.1,0.7)","Q.Y")
{
    REQUIRE(Quaternion(0.5,0.3,0.1,0.7).getY()==0.3f);
}
TEST_CASE("Quaternion getZ function check for input (0.5,0.3,0.1,0.7)","Q.Z")
{
    REQUIRE(Quaternion(0.5,0.3,0.1,0.7).getZ()==0.1f);
}

//test set methord
SCENARIO("Quaternion  setX() Function ","Quaternion")
{

    Quaternion q ;

    WHEN("Set X value to 0.23 (input 0.23) ")
    {
        q.setX(0.23);
        THEN("Output should equal to 0.23"){
            REQUIRE(q.getX() ==0.23f);
        }
    }
    WHEN("Set X value to 0.-1.236 (input -1.236)")
    {
        q.setX(-1.236f);
        THEN("Output should equal to  -1.236f"){
            REQUIRE(q.getX() == -1.236f);
        }
    }
    WHEN("Set X value to 999998 (input 999998)")
    {
        q.setX(999998);
        THEN("Output should equal to  999998"){
            REQUIRE(q.getX() == 999998);
        }
    }


}

SCENARIO("Quaternion  setY() Function ","Quaternion")
{

    Quaternion q ;
    WHEN("Set Y value to 0.93 (input 0.93)")
    {
        q.setY(0.93);
        THEN("Output should equal to  0.93"){
            REQUIRE(q.getY() ==0.93f);
        }
    }
    WHEN("Set Y value to -1.893 (input -1.893)")
    {
        q.setY(-1.893);
        THEN("Output should equal to  -1.893"){
            REQUIRE(q.getY() == -1.893f);
        }
    }
    WHEN("Set Y value to 999998 (input 999998)")
    {
        q.setY(999998);
        THEN("Output should equal to  999998"){
            REQUIRE(q.getY() == 999998);
        }
    }
}

SCENARIO("Quaternion  setZ() Function ","Quaternion")
{
    Quaternion q ;
    WHEN("Set Z value to 0.8933 (input 0.8933)")
    {
        q.setZ(0.8933);
        THEN("Output should equal to  0.8933"){
            REQUIRE(q.getZ() ==0.8933f);
        }
    }
    WHEN("Set Z value to -145 (input -145)")
    {
        q.setZ(-145);
        THEN("Output should equal to  -145"){
            REQUIRE(q.getZ() == -145);
        }
    }
    WHEN("Set Z value to 12999998 (input 12999998)")
    {
        q.setZ(12999998);
        THEN("Output should equal to  12999998"){
            REQUIRE(q.getZ() == 12999998);
        }
    }

}

SCENARIO("Quaternion  setW() Function ","Quaternion")
{

    Quaternion q ;
    WHEN("Set W value to 4.36 (input 4.36)")
    {
        q.setW(4.36);
        THEN("Output should equal to  4.36"){
            REQUIRE(q.getW() ==4.36f);
        }
    }
    WHEN("Set W value to -56 (input -56)")
    {
        q.setW(-56);
        THEN("Output should equal to  -56"){
            REQUIRE(q.getW() == -56);
        }
    }
    WHEN("Set W value to 8998 (input 8998)")
    {
        q.setW(8998);
        THEN("Output should equal to  8998"){
            REQUIRE(q.getW() == 8998);
        }
    }

}

//Check conjugate
SCENARIO("Conjugate Function ","Quaternion")
{


    Quaternion q1(1, 1, 1, 1);
    Quaternion q2;
    Quaternion q3(-1, -1, -1, -1);

    WHEN("All the elements in quaternion positive (input (1,1,1,1))")
    {
        q1.Conjugate();
        THEN("Output of the function must be (-1,-1,-1,1)")
        {
            REQUIRE(q1.getW() ==1);
            REQUIRE(q1.getX() ==-1);
            REQUIRE(q1.getY() ==-1);
            REQUIRE(q1.getZ() ==-1);
        }
    }
    WHEN("Claculete conjugate of the identity Quaternion (input (0,0,0,1))")
    {
        q2.Conjugate();
        THEN("Output of the function must be (0,0,0,1)")
        {
            REQUIRE(q2.getW() ==1);
            REQUIRE(q2.getX() ==0);
            REQUIRE(q2.getY() ==0);
            REQUIRE(q2.getZ() ==0);
        }
    }
    WHEN("All the elements in Quaternion are negative (input (-1,-1,-1,-1))")
    {
        q3.Conjugate();
        THEN("Output of the function must be (1,1,1,-1")
        {
            REQUIRE(q3.getW() ==-1);
            REQUIRE(q3.getX() ==1);
            REQUIRE(q3.getY() ==1);
            REQUIRE(q3.getZ() ==1);
        }
    }

}

//Check dot product
SCENARIO("Dot product Function ","Quaternion")
{
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(0.5, 0.5, 0.5, 0.5);
    Quaternion q3(-1, -5, -3, 6);
    Quaternion q4(100, 100, 100, 100);
    WHEN("The both input are equal (inputs quaternions (1, 2, 3, 4) and (1, 2, 3, 4))")
    {
        THEN("Output should be 60") {
            REQUIRE(q1.Dot(q1)==30.0f );
        }
    }
    WHEN(" The both input quaternion directions are same (input quaternions (0.5, 0.5, 0.5, 0.5) and (100, 100, 100, 100),)")
    {
        THEN("Output should be 1") {
            REQUIRE(q2.Dot(q4)==200.0f );
        }
    }

    WHEN(" The both input quaternion directions are different (input quaternions (0.5, 0.5, 0.5, 0.5) and (-1, -5, -3, 6) )")
    {
        THEN("Absolute value of the output should be < 1") {
            REQUIRE(q2.Dot(q3)== -1.5f );
        }
    }

}

//Normalized function
SCENARIO("Normalized Function "," Quaternion")
{
    Quaternion q1(1,1,1,1);
    Quaternion q2(0,0,0,0);
    Quaternion q3(-1,-1,-1,-1);
    Quaternion q4(-1.5,2.5,-6.8,7.6);

    WHEN("All elements in Quaternion equal positive (input Quaternion (1,1,1,1)) ")
    {
        q1.Normalize();
        THEN("Output Quaternion should be (0.5,0.5,0.5,0.5)")
        {
            REQUIRE(q1.getW()==0.5f);
            REQUIRE(q1.getX()==0.5f);
            REQUIRE(q1.getY()==0.5f);
            REQUIRE(q1.getZ()==0.5f);
        }
    }
    WHEN("All elements in Quaternion the equal and negative (input Quaternion (-1,-1,-1,-1))")
    {
        q3.Normalize();
        THEN(" Output Quaternion should be (-0.5,-0.5,-0.5,-0.5)")
        {
            REQUIRE(q3.getW()==-0.5f);
            REQUIRE(q3.getX()==-0.5f);
            REQUIRE(q3.getY()==-0.5f);
            REQUIRE(q3.getZ()==-0.5f);
        }
    }
    WHEN("All elements in the Quaternion are equal to zero (input Quaternion (0,0,0,0)) ")
    {
        q2.Normalize();
        THEN("Output Quaternion should be (0,0,0,0)")
        {
            REQUIRE(q2.getW()==0.0f);
            REQUIRE(q2.getX()==0.0f);
            REQUIRE(q2.getY()==0.0f);
            REQUIRE(q2.getZ()==0.0f);
        }
    }
    WHEN("All elements in the  Quaternion equal to random numbers (input Quaternion (-1.5,2.5,-6.8,7.6))")
    {
        q4.Normalize();
        THEN("Output Quaternion should be ( -0.141421356237310, 0.235702260395516,-0.641110148275803,0.716534871602368)")
        {
            REQUIRE(abs(q4.getW()-0.716534871602368f)<0.00001f);
            REQUIRE(abs(q4.getX()-(-0.141421356237310f))<0.00001f);
            REQUIRE(abs(q4.getY()-0.235702260395516f)<0.00001f);
            REQUIRE(abs(q4.getZ()-(-0.641110148275803f))<0.00001f);
        }
    }

}

//Norm function testing
SCENARIO("Norm Function  ","Quaternion")
{
    Quaternion q(1,1,1,1);
    Quaternion q1(-1,-1,-1,-1);
    Quaternion q2(0,0,0,0);
    WHEN("Input Quaternion all the elements are positive (input quaternion (1,1,1,1)) ")
    {
        THEN("Output should be 2")
        {
            REQUIRE(q.Norm() == 2.0f);
        }
    }
    WHEN("Input Quaternion, all the elements are negative (input quaternion (-1,-1,-1,-1))")
    {
        THEN("Output should be 2")
        {
            REQUIRE(q1.Norm() == 2.0f);
        }
    }
    WHEN("Input Quaternion all zero Quaternion (input quaternion (0,0,0,0))")
    {
        THEN("Output should be 0")
        {
            REQUIRE(q2.Norm() == 0.0f);
        }
    }
}

// Quaternion addition testing
SCENARIO("Addition(+) operation ","Quaternion")
{
    Quaternion q(1,1.3,1.5,8);
    Quaternion q1;
    Quaternion q2(5,4,8,2);
    Quaternion q3(-1,-2,-4,-1);
    Quaternion q4(-4,-2,-6,-1);
    WHEN("Add two positive Quaternion (input quaternions are (1,1.3,1.5,8)and (5,4,8,2))")
    {
        Quaternion out =q+q2;
        THEN("Output should be (6,5.3,9.5,10)")
        {
            REQUIRE(out.getW() ==10);
            REQUIRE(out.getX() ==6);
            REQUIRE(out.getY() ==5.3f);
            REQUIRE(out.getZ() ==9.5f);
        }
    }
    WHEN("Add two negative Quaternion (input quaternions are (-1,-2,-4,-1)and (-4,-2,-6,-1))")
    {
        Quaternion out =q3+q4;
        THEN("Output should be (-5,-4,-10,-2)")
        {
            REQUIRE(out.getW() == -2);
            REQUIRE(out.getX() == -5);
            REQUIRE(out.getY() == -4);
            REQUIRE(out.getZ() == -10);
        }
    }
    WHEN("Add  positive and negative Quaternion (input quaternions are (5,4,8,2) and (-1,-2,-4,-1))")
    {
        Quaternion out =q2+q3;
        THEN("Output should be ( 1,4,2,4)")
        {
            REQUIRE(out.getW() ==1);
            REQUIRE(out.getX() ==4);
            REQUIRE(out.getY() ==2);
            REQUIRE(out.getZ() ==4);
        }
    }
}

//quaternion subtraction  testing
SCENARIO("Subtraction(-) operation ","Quaternion")
{
    Quaternion q(1,6,4,8);
    Quaternion q1;
    Quaternion q2(5,4,8,2);
    Quaternion q3(-1,-2,-4,-1);
    Quaternion q4(-4,-2,-6,-1);
    WHEN("Subtraction of two positive Quaternion (input quaternions are (1,6,4,8)and (5,4,8,2))")
    {
        Quaternion out =q - q2;
        THEN("Output should be (-4,2,-4,6)")
        {
            REQUIRE(out.getW() ==6);
            REQUIRE(out.getX() ==-4);
            REQUIRE(out.getY() ==2);
            REQUIRE(out.getZ() ==-4);
        }
    }
    WHEN("Subtraction of two negative Quaternion (input quaternions are (-1,-2,-4,-1)and (-4,-2,-6,-1))")
    {
        Quaternion out =q3-q4;
        THEN("Output should be (3,0,2,0)")
        {
            REQUIRE(out.getW() == 0);
            REQUIRE(out.getX() == 3);
            REQUIRE(out.getY() == 0);
            REQUIRE(out.getZ() == 2);
        }
    }
    WHEN("Subtraction of  positive and negative Quaternion (input quaternions are (5,4,8,2)and (-1,-2,-4,-1))")
    {
        Quaternion out =q2-q3;
        THEN("Output should be (6,6,12,3)")
        {
            REQUIRE(out.getW() ==3);
            REQUIRE(out.getX() ==6);
            REQUIRE(out.getY() ==6);
            REQUIRE(out.getZ() ==12);
        }
    }

}
//Quaternion product calculation testing
SCENARIO("Multiplication(*) operation ","Quaternion")
{
    Quaternion q1;
    Quaternion q2(0.5,0.5,0.5,0.5);
    Quaternion q3(-1,-2,-1,-3);
    Quaternion q4(-0.5,-0.5,-0.5,0.5);
    Quaternion q5(7,6,1,5);
    WHEN("Get product of two quaternion (input quaternions are (-1,-2,-1,-3) and (7,6,1,5))")
    {
        Quaternion out = q3*q5;
        THEN("Output should be (-22,-34,0,5)")
        {
            REQUIRE(out.getW() == 5);
            REQUIRE(out.getX() == -22);
            REQUIRE(out.getY() == -34);
            REQUIRE(out.getZ() == 0);
        }
    }
    WHEN("Quaternion order change and get product between two quaternion (input quaternions are (7,6,1,5) and (-1,-2,-1,-3))")
    {
        Quaternion out = q5*q3;
        THEN("Output should be (-22,-34,0,5)")
        {
            REQUIRE(out.getW() == 5);
            REQUIRE(out.getX() == -30);
            REQUIRE(out.getY() == -22);
            REQUIRE(out.getZ() == -16);
        }
    }
    WHEN("Quaternion multiply by it's inverse (input quaternions are (0.5,0.5,0.5,0.5) and (-0.5,-0.5,-0.5,0.5) )")
    {
        Quaternion out = q2*q4;
        THEN("Output should be  (0,0,0,1)") {
            REQUIRE(out.getW() == 1.0f);
            REQUIRE(out.getX() == 0.0f);
            REQUIRE(out.getY() == 0.0f);
            REQUIRE(out.getZ() == 0.0f);
        }
    }
    WHEN("Quaternion multiply by identity Quaternion (input quaternions are (-1,-2,-1,-3) and (0,0,0,1))")
    {
        Quaternion out = q3*q1;
        THEN("Output should be  (-1,-2,-1,-3)") {
            REQUIRE(out.getW() == -3);
            REQUIRE(out.getX() == -1);
            REQUIRE(out.getY() == -2);
            REQUIRE(out.getZ() == -1);
        }
    }
    WHEN("Identity Quaternion multiply by Identity Quaternion (input quaternions are (0,0,0,1) and (0,0,0,1))")
    {
        Quaternion out = q1*q1;
        THEN("Output should be  0,0,0,1") {
            REQUIRE(out.getW() == 1);
            REQUIRE(out.getX() == 0);
            REQUIRE(out.getY() == 0);
            REQUIRE(out.getZ() == 0);
        }
    }


}
SCENARIO("Multiplication(*) operation for scalar multiplication","Quaternion")
{
    Quaternion q(2,3,-1,5);

    WHEN("multiply float scalar with quaternion (input quaternion (2,3,-1,5) and float scalar 5)")
    {   float x = 5;
        Quaternion out = q*x;
        THEN("Output should be (10,15,-5,25)")
        {
            REQUIRE(out.getW() == 25);
            REQUIRE(out.getX() == 10);
            REQUIRE(out.getY() == 15);
            REQUIRE(out.getZ() == -5);
        }
    }
    WHEN("multiply integer scalar with quaternion (input quaternion (2,3,-1,5) and integer 5)")
    {   int x =5;
        Quaternion out ;
        out = q * x;
        THEN("Output should be (10,15,-5,25)")
        {
            REQUIRE(out.getW() == 25);
            REQUIRE(out.getX() == 10);
            REQUIRE(out.getY() == 15);
            REQUIRE(out.getZ() == -5);
        }
    }

    WHEN("multiply double scalar with quaternion (input quaternion (2,3,-1,5) and double 5)")
    {   double  x =5;
        Quaternion out ;
        out = q * x;
        THEN("Output should be (10,15,-5,25)")
        {
            REQUIRE(out.getW() == 25);
            REQUIRE(out.getX() == 10);
            REQUIRE(out.getY() == 15);
            REQUIRE(out.getZ() == -5);
        }
    }
    WHEN("multiply  scalar(0) with quaternion (input quaternion (2,3,-1,5) and float scalar 0)")
    {   float x =0;
        Quaternion out ;
        out = q * x;
        THEN("Output should be (0,0,0,0)")
        {
            REQUIRE(out.getW() == 0);
            REQUIRE(out.getX() == 0);
            REQUIRE(out.getY() == 0);
            REQUIRE(out.getZ() == 0);
        }
    }

    WHEN("multiply negative scalar with quaternion (input quaternion (2,3,-1,5) and float scalar -1)")
    {   float x =-1;
        Quaternion out ;
        out = q * x;
        THEN("Output should be (-2,-3,1,-5)")
        {
            REQUIRE(out.getW() == -5);
            REQUIRE(out.getX() == -2);
            REQUIRE(out.getY() == -3);
            REQUIRE(out.getZ() == 1);
        }
    }



}

SCENARIO("QuaternionToEuler Function","Quaternion")
{
    Quaternion q;
    Euler e;
    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (0,0,0,1) )")
    {
        e = q.QuaternionToEuler();
        THEN("Output should be [0,0,0]")
        {
            REQUIRE(e.x==0);
            REQUIRE(e.y==0);
            REQUIRE(e.z==0);
        }
    }
    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (0,0,1,1) )")
    {    Quaternion q(0,0,1,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [0,0,1.57079]")
        {
            REQUIRE(abs(e.z-1.5708f)<0.0001);
            REQUIRE(e.y == 0);
            REQUIRE(e.x == 0);
        }
    }
    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (0,1,0,1) )")
    {    Quaternion q(0,1,0,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [0,1.57079,0]")
        {
            REQUIRE(abs(e.y-1.5708f)<0.0001);
            REQUIRE(e.z == 0);
            REQUIRE(e.x == 0);
        }

    }
    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (1,0,0,1) )")
    {    Quaternion q(1,0,0,1);
        e = q.QuaternionToEuler();
        THEN("Output should be [1.57079,0,0]")
        {
            REQUIRE(abs(e.x-1.5708f)<0.0001);
            REQUIRE(e.z == 0);
            REQUIRE(e.y == 0);
        }
    }

    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (-1,0,0,1) )")
    {    Quaternion q(-1,0,0,1);
        e = q.QuaternionToEuler();
        THEN("Output should be [1.57079,0,0]")
        {
            REQUIRE(abs(e.x+1.5708f)<0.0001);
            REQUIRE(e.z == 0);
            REQUIRE(e.y == 0);
        }
    }

    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (0,0,-1,1) )")
    {    Quaternion q(0,0,-1,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [0,0,-1.57079]")
        {
            REQUIRE(abs(e.z+1.5708f)<0.0001);
            REQUIRE(e.y == 0);
            REQUIRE(e.x == 0);
        }
    }
    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (0,-1,0,1) )")
    {    Quaternion q(0,-1,0,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [0,-1.57079,0]")
        {
            REQUIRE(abs(e.y+1.5708f)<0.0001);
            REQUIRE(e.z == 0);
            REQUIRE(e.x == 0);
        }

    }
    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (1,1,1,1) )")
    {    Quaternion q(1,1,1,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [1.57079,0,1.57079]")
        {
            REQUIRE(abs(e.z-1.5708f)<0.0001);
            REQUIRE(e.y == 0);
            REQUIRE(abs(e.x-1.5708f)<0.0001);
        }

    }

    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (-1,-1,-1,1) )")
    {    Quaternion q(-1,-1,-1,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [0,-1.57079,0]")
        {
            REQUIRE(abs(e.y+1.5708f)<0.0001);
            REQUIRE(e.z == 0);
            REQUIRE(e.x == 0);
        }

    }
    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (1,0,1,1) )")
    {    Quaternion q(1,0,1,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [1.1071,-0.7297,1.1071]")
        {
            REQUIRE(abs(e.z-1.1071f)<0.0001);
            REQUIRE(abs(e.y+0.7297f)<0.0001);
            REQUIRE(abs(e.x-1.1071f)<0.0001);
        }

    }

    WHEN("Apply identity quaternion to the QuaternionToEuler  (input quaternion (-1,0,-1,1) )")
    {    Quaternion q(-1,0,-1,1);
        e = q.QuaternionToEuler();

        THEN("Output should be [-1.1071,-0.7297,-1.1071]")
        {
            REQUIRE(abs(e.z+1.1071f)<0.0001);
            REQUIRE(abs(e.y+0.7297f)<0.0001);
            REQUIRE(abs(e.x+1.1071f)<0.0001);
        }

    }


}








/*
int main(){
    Quaternion q(1,0,1,1);

    auto a = q.QuaternionToEuler();

    std:: cout << a.z << std::endl;
    std:: cout << a.y << std::endl;
    std:: cout << a.x << std::endl;
    return 0;
}
*/