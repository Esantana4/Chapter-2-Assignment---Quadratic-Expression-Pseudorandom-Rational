#pragma once

// Credit:
// Joe Bryant & Erik Santana - Quadratic Expression

class QuadraticExpression
{
private:
    int a, b, c, x;

public:

    // Pre-Condition: no parameters
    // Post-Condition: no return. No argument constructor. Initializer constructor
    QuadraticExpression();

    // Pre-Condition: parameters - int coefficientA, int coefficientB, int coefficientC, int coefficientX. These parameters are assigned to the private member variables.
    // Post-Condition: no return. Argument constructor
    QuadraticExpression(int coefficientA, int coefficientB, int coefficientC, int coefficientX);

    // Mutators

    // Pre-Condition: parameter int coefficientA is assigned to the private member variable a.
    // Post-Condition: no return. This mutator member function sets/changes the private variable a. 
    void setA(int coefficientA);

    // Pre-Condition: parameter int coefficientB is assigned to the private member variable b.
    // Post-Condition: no return. This mutator member function sets/changes the private variable b. 
    void setB(int coefficientB);

    // Pre-Condition: parameter int coefficientC is assigned to the private member variable c.
    // Post-Condition: no return. This mutator member function sets/changes the private variable c.
    void setC(int coefficientC);

    // Pre-Condition: parameter int coefficientX is assigned to the private member variable x.
    // Post-Condition: no return. This mutator member function sets/changes the private variable x. 
    void setX(int coefficientX);


    // Accessors

    // Pre-Condition: no parameters.
    // Post-Condition: returns a. Accessors function to get(view) the value of a
    int getA() const;

    // Pre-Condition: no parameters.
    // Post-Condition: returns b. Accessors function to get(view) the value of b
    int getB() const;

    // Pre-Condition: no parameters.
    // Post-Condition: returns c. Accessors function to get(view) the value of c
    int getC() const;

    // Pre-Condition: no parameters.
    // Post-Condition: returns x. Accessors function to get(view) the value of x
    int getX() const;

    // Pre-Condition: NA
    // Post-Condition: prints out quadratic equation
    void displayEquation() const;

    // Pre-Condition: NA
    // Post-Condition: prints out result of solved quadratic equation with the given x
    void getEvaluation() const;

    // Pre-Condition: NA
    // Post-Condition: prints out number of roots Quadratic equation has
    void numRoots() const;

    // Pre-Condition: NA
    // Post-Condition: calculates the roots of quadratic equation and prints
    void getRoots() const;

    // Pre-Condition: no parameters
    // Post-Condition: no return. Destructor
    ~QuadraticExpression();
};