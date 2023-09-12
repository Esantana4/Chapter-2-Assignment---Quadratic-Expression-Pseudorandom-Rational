#include "QuadraticExpression.h"
#include <iostream>
#include <cmath>

// Credit: 
// Joe Bryant & Erik Santana - Quadratic Expression


// No argument constructor to initialize the values
// Pre-Condition: no parameters
// Post-Condition: no return. No argument constructor. Initializer constructor
QuadraticExpression::QuadraticExpression()
{
    a = 0;
    b = 0;
    c = 0;
    x = 0;
}

// Pre-Condition: parameters - int coefficientA, int coefficientB, int coefficientC, int coefficientX. These parameters are assigned to the private member variables.
// Post-Condition: no return. Argument constructor
QuadraticExpression::QuadraticExpression(int coefficientA, int coefficientB, int coefficientC, int coefficientX)
{
    a = coefficientA;
    b = coefficientB;
    c = coefficientC;
    x = coefficientX;
}


// Mutators

// Pre-Condition: parameter int coefficientA is assigned to the private member variable a.
// Post-Condition: no return. This mutator member function sets/changes the private variable a. 
void QuadraticExpression::setA(int coefficientA)
{
    a = coefficientA;
}

// Pre-Condition: parameter int coefficientB is assigned to the private member variable b.
// Post-Condition: no return. This mutator member function sets/changes the private variable b. 
void QuadraticExpression::setB(int coefficientB)
{
    b = coefficientB;
}

// Pre-Condition: parameter int coefficientC is assigned to the private member variable c.
// Post-Condition: no return. This mutator member function sets/changes the private variable c. 
void QuadraticExpression::setC(int coefficientC)
{
    c = coefficientC;
}

// Pre-Condition: parameter int coefficientX is assigned to the private member variable x.
// Post-Condition: no return. This mutator member function sets/changes the private variable x. 
void QuadraticExpression::setX(int coefficientX)
{
    x = coefficientX;
}


// Accessors

// Pre-Condition: no parameters.
// Post-Condition: returns a. Accessors function to get(view) the value of a
int QuadraticExpression::getA() const
{
    return a;
}

// Pre-Condition: no parameters.
// Post-Condition: returns b. Accessors function to get(view) the value of b
int QuadraticExpression::getB() const
{
    return b;
}

// Pre-Condition: no parameters.
// Post-Condition: returns c. Accessors function to get(view) the value of c
int QuadraticExpression::getC() const
{
    return c;
}

// Pre-Condition: no parameters.
// Post-Condition: returns x. Accessors function to get(view) the value of x
int QuadraticExpression::getX() const
{
    return x;
}

// Pre-Condition: NA
// Post-Condition: prints out quadratic equation
void QuadraticExpression::displayEquation() const
{
    std::cout << "\t" << a << "x^2 + " << b << "x + " << c << std::endl << std::endl;
}

// Pre-Condition: NA 
// Post-Condition: prints out result of solved quadratic equation with the given x
void QuadraticExpression::getEvaluation() const
{
    double result = 0;

    result = a * (pow(x, 2)) + (b * x) + c;

    std::cout << "\tEvaluation result: " << result;
}

// Pre-Condition: NA
// Post-Condition: prints out number of roots Quadratic equation has
void QuadraticExpression::numRoots() const
{
    double discriminant = 0;

    discriminant = (pow(b, 2)) - (4 * a * c);

    if (discriminant < 0)
    {
        std::cout << "\n\tnumber of real roots: 0\n";
    }
    else if (discriminant == 0)
    {
        std::cout << "\n\tnumber of real roots: 1\n";
    }
    else if (discriminant > 0)
    {
        std::cout << "\n\tnumber of real roots: 2\n";
    }
}

// Pre-Condition: NA
// Post-Condition: calculates the roots of quadratic equation and prints
void QuadraticExpression::getRoots() const
{
    double discriminant = 0;
    double root1 = 0;
    double root2 = 0;

    discriminant = (pow(b, 2)) - (4 * a * c);

    if (discriminant < 0)
    {
        std::cout << "\n\tno real roots\n";
    }
    else if (discriminant == 0)
    {
        root1 = (-b + (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a);

        std::cout << "\n\tonly real root: " << root1 << std::endl;
    }
    else if (discriminant > 0)
    {
        root1 = (-b + (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a);
        root2 = (-b - (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a);

        std::cout << "\n\ttwo real roots are: " << root2 << " and " << root1 << std::endl;
    }
}

// Pre-Condition: no parameters
// Post-Condition: no return. Destructor
QuadraticExpression::~QuadraticExpression()
{}
