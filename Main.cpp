/*
 Erik Santana
 9/4/23
 CPMR 131 - Professor Q

 Description:

 Part 1 works with a quadratic equation using classes.
 Part 2 creates a custom random seed generator that also uses classes.
 Part 3 does math calculations with rational numbers, also uses a class.

 Credit:
 Joe Bryant & Erik Santana - Part 1: Quadratic Expression
 Saul Merino & Oscar Gallardo - Part 2: Pseudorandom
 Otoniel Torres Bernal & John Kim  - Part 3: Rational Number
 */

#include "input.h"
#include "QuadraticExpression.h"
#include "Pseudorandom.h"

using namespace std;

void mainMenu();
void quadraticExpression();
void pseudorandomMenu();
void rationalNumber();
char pseudorandomMenuOption();
void generateIndirectNumTable(Pseudorandom pseudorandom1);

int main()
{
    // program begins
    mainMenu();

    return 0;
}

// Pre-Conditon: no parameters
// Post-Condition: no return. displays main menu and calls specific functions for the case options
void mainMenu()
{
    cout << endl;
    cout << "\tCMPR131 - Chapter 2 ADT Assignment by Erik Santana (9 / 4 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1> Quadratic Expression" << endl;
    cout << "\t2> Pseudorandom" << endl;
    cout << "\t3> Rational number" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > exit" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    // get user input/option of main menu
    int option = inputInteger("\n\tOption: ", 0, 3);

    // loop through main menu until user exits
    do
    {
        switch (option)
        {
        case 0:
            system("cls");
            exit(1);
            break;
        case 1:
            quadraticExpression();
            break;
        case 2:
            pseudorandomMenu();
            break;
        case 3:
            rationalNumber();
            break;
        }

        // new line
        cout << "\n";

    } while (true);
}

// Pre-Condition: no parameters
// Post-Condition: no return. Sub menu, user picks an option.
void quadraticExpression()
{
    QuadraticExpression quadraticExpression;

    // loop through sub menu until user exits
    do
    {
        system("cls");
        cout << "\t\n1 > Quadratic Menu\n";
        cout << "===========================================================\n";
        cout << "1. Display the expression\n";
        cout << "2. Set coefficient (a)\n";
        cout << "3. Set coefficient (b)\n";
        cout << "4. Set coefficient (c)\n";
        cout << "5. Get evaluation (x)\n";
        cout << "6. Get the number of real roots\n";
        cout << "7. Get real root(s)\n";
        cout << "------------------------------------------------------------\n";
        cout << "0. Return to Main Menu\n";
        cout << "===========================================================\n";

        // get user input/option of main menu
        int option = inputInteger("\n\tOption: ", 0, 7);

        switch (option)
        {
        case 0:
        {
            system("cls");
            mainMenu();
            break;
        }
        case 1:
        {
            quadraticExpression.displayEquation();
            break;
        }
        case 2:
        {
            // Set coefficient (a)
            int coefficientA = inputInteger("\nEnter coefficient (a): ");
            quadraticExpression.setA(coefficientA);

            cout << endl << "a = " << quadraticExpression.getA() << endl;
            break;
        }
        case 3:
        {
            // Set coefficient (b)
            int coefficientB = inputInteger("\nEnter coefficient (b): ");
            quadraticExpression.setB(coefficientB);

            cout << endl << "b = " << quadraticExpression.getB() << endl;
            break;
        }
        case 4:
        {
            // Set coefficient (c)
            int coefficientC = inputInteger("\nEnter coefficient (c): ");
            quadraticExpression.setC(coefficientC);

            cout << endl << "c = " << quadraticExpression.getC() << endl;
            break;
        }
        case 5:
        {
            // Set coefficient (x)
            int coefficientX = inputInteger("\nEnter coefficient (x): ");
            quadraticExpression.setX(coefficientX);

            cout << endl << "x = " << quadraticExpression.getX() << endl;
            break;
        }
        case 6:
        {
            quadraticExpression.numRoots();
            break;
        }
        case 7:
        {
            quadraticExpression.getRoots();
            break;
        }
        default:
        {
            cout << "\t\tERROR - Invalid option. Please re-enter.";
            break;
        }
        }

        // new line
        cout << "\n";
        system("pause");

    } while (true);

}

// Pre-Condition: 
// Post-Condition:
void pseudorandomMenu()
{
    Pseudorandom pseudorandom;

    do
    {
        switch (pseudorandomMenuOption())
        {
        case '0':
        {
            system("cls");
            mainMenu();
            break;
        }
        case 'A':
        {
            cout << "Seed: " << pseudorandom.getSeed();
            break;
        }
        case 'B':
        {
            pseudorandom.setSeed(inputInteger("Enter Seed:"));
            break;
        }
        case 'C':
        {
            cout << "Multiplier: " << pseudorandom.getMultiplier();
            break;
        }
        case 'D':
        {
            pseudorandom.setMultiplier(inputInteger("Enter Multiplier:"));
            break;
        }
        case 'E':
        {
            cout << "Modulus: " << pseudorandom.getModulus();
            break;
        }
        case 'F':
        {
            pseudorandom.setModulus(inputInteger("Enter Modulus:"));
            break;
        }
        case 'G':
        {
            cout << "Increment: " << pseudorandom.getIncrement();
            break;
        }
        case 'H':
        {
            pseudorandom.setIncrement(inputInteger("Enter Increment:"));
            break;
        }
        case 'I':
        {
            pseudorandom.generateSeed(); cout << pseudorandom.getSeed();
            break;
        }
        case 'J':
        {
            cout << "Indirect Next Number: " << pseudorandom.generateNextIndirectNum();
            break;
        }
        case 'K':
        {
            generateIndirectNumTable(pseudorandom);
            break;
        }
        default:
        {
            cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        }

        cout << "\n";
        system("pause");

    } while (true);
}

// Pre-Condition: 
// Post-Condition:
char pseudorandomMenuOption()
{
    system("cls");
    cout << "2: Pseudorandom" << endl;
    cout << string(100, char(205)) << endl;
    cout << "A. Get Seed" << endl;
    cout << "B. Set Seed" << endl;
    cout << "C. Get Multiplier" << endl;
    cout << "D. Set Multiplier" << endl;
    cout << "E. Get Modulus" << endl;
    cout << "F. Set Modulus" << endl;
    cout << "G. Get Increment" << endl;
    cout << "H. Set Increment" << endl;
    cout << "I. Get Next Number" << endl;
    cout << "J. Get Next Indirect Number" << endl;
    cout << "K. Run Experiment With Different Numbers (Multiplier, Increment, and Modulus)" << endl;
    cout << string(100, char(205)) << endl;
    cout << "0. Return" << endl;
    cout << string(100, char(205)) << endl;

    char option = toupper(inputChar("Option : "));
    return option;
}

// Pre-Condition: 
// Post-Condition:
void generateIndirectNumTable(Pseudorandom pseudorandom)
{
    pseudorandom.setMultiplier(21);
}

// Pre-Condition: 
// Post-Condition:
void rationalNumber()
{

}
