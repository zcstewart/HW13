//Homework 13

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to prompt the user to
 *                      enter three lengths of the side of a triangle. The
 *                      program will then determine if the triangle is a
 *                      scalene, isosceles, or equilateral triangle. It will
 *                      also determine if it isn't possible to make a triangle
 *                      using the given lengths. This will be accomplished
 *                      using the enumeration type triangleType within 
 *                      a namespace call Triangle. A user defined function
 *                      triangleShape will determine the shape of the triangle
 *                      using the user input lengths of the sides a, b, and c.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/29/2017 12:24 PST
 */

#include<cstdlib>
#include<iostream>
#include<cmath>

namespace Triangle
{
    enum triangleType {scalene, isosceles, equilateral, noTriangle};
    triangleType TR;    
}

Triangle::triangleType triangleShape(int a, int b, int c);

int main(int argc, char** argv)
{
    //Declare variables to gather input from user
    int sA, sB, sC;
    
    //Prompt user for input
    std::cout << "Triangle testing program" << std::endl << std::endl;
    std::cout << "Enter length of side a: "  << std::endl;
    std::cin >> sA;
    std::cout << "Enter length of side b: " << std::endl;
    std::cin >> sB;
    std::cout << "Enter length of side c: " << std::endl;
    std::cin >> sC;
    std::cout << std::endl;
       
    //Call function traingleShape which returns triangle enumeration
    int choice = triangleShape(sA, sB, sC);
    
    switch(choice)
    {
        case 0:
            std::cout << "The triangle type is: Scalene" << std::endl;
            break;
        case 1: 
            std::cout <<  "The triangle type is: Isosceles" << std::endl;
            break;
        case 2:
            std::cout << "The triangle type is: Equilateral" << std::endl;
            break;
        case 3:
            std::cout << "The triangle type is: Not a Triangle" << std::endl;
            break;
        default:
            std::cout << "Invalid" << std::endl;
    }    
    std::exit(EXIT_SUCCESS);
}

Triangle::triangleType triangleShape(int a, int b, int c)
{
    Triangle::triangleType TR;
    if(((a + b) <= c) || ((a + c) <= b) || ((b + c) <= a)
            || a == 0 || b == 0 || c == 0)
    {
        return Triangle::noTriangle;
    }
    else if((a==b) && (b==c))
    {
        return Triangle::equilateral;
    }
    else if((a == b) || (a == c) || (b == c))
    {
        return Triangle::isosceles;
    }
    else
    {
        return Triangle::scalene;
    }
}