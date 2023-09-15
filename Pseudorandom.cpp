#include "Pseudorandom.h"

// Credit:  Saul Merino & John Kim - Pseudorandom

Pseudorandom::Pseudorandom()
{
    seed = 1;
    multiplier = 40;
    increment = 725;
    modulus = 729;
}

void Pseudorandom::setSeed(int newSeed)
{
    seed = newSeed;
}

void Pseudorandom::setMultiplier(int newMultiplier)
{
    multiplier = newMultiplier;
}

void Pseudorandom::setIncrement(int newIncrement)
{
    increment = newIncrement;
}

void Pseudorandom::setModulus(int newModulus)
{
    modulus = newModulus;
}

int Pseudorandom::getSeed() const
{
    return seed; 
}

int Pseudorandom::getMultiplier() const
{ 
    return multiplier; 
}
int Pseudorandom::getIncrement() const
{ 
    return increment;
}
int Pseudorandom::getModulus() const
{ 
    return modulus;
}

void Pseudorandom::generateSeed()
{
    int newSeed = (multiplier * seed + increment) % modulus;
    setSeed(newSeed);
}

double Pseudorandom::generateNextIndirectNum()
{
    generateSeed();
    return static_cast<double>(seed) / modulus;
}

// Pre-Condition: 
// Post-Condition:
void Pseudorandom::pseudorandomMenu()
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
            std::cout << "Seed: " << getSeed();
            break;
        }
        case 'B':
        {
            setSeed(inputInteger("Enter Seed:"));
            break;
        }
        case 'C':
        {
            std::cout << "Multiplier: " << getMultiplier();
            break;
        }
        case 'D':
        {
            setMultiplier(inputInteger("Enter Multiplier:"));
            break;
        }
        case 'E':
        {
            std::cout << "Modulus: " << getModulus();
            break;
        }
        case 'F':
        {
            setModulus(inputInteger("Enter Modulus:"));
            break;
        }
        case 'G':
        {
            std::cout << "Increment: " << getIncrement();
            break;
        }
        case 'H':
        {
            setIncrement(inputInteger("Enter Increment:"));
            break;
        }
        case 'I':
        {
            generateSeed(); std::cout << getSeed();
            break;
        }
        case 'J':
        {
            std::cout << "Indirect Next Number: " << generateNextIndirectNum();
            break;
        }
        case 'K':
        {
            displayGenerateGaussian();
            break;
        }
        default:
        {
            std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        }

        std::cout << "\n";
        system("pause");

    } while (true);
}

// Pre-Condition: 
// Post-Condition:
char Pseudorandom::pseudorandomMenuOption()
{
    system("cls");
    std::cout << "2: Pseudorandom" << std::endl;
    std::cout << std::string(100, char(205)) << std::endl;
    std::cout << "A. Get Seed" << std::endl;
    std::cout << "B. Set Seed" << std::endl;
    std::cout << "C. Get Multiplier" << std::endl;
    std::cout << "D. Set Multiplier" << std::endl;
    std::cout << "E. Get Modulus" << std::endl;
    std::cout << "F. Set Modulus" << std::endl;
    std::cout << "G. Get Increment" << std::endl;
    std::cout << "H. Set Increment" << std::endl;
    std::cout << "I. Get Next Number" << std::endl;
    std::cout << "J. Get Next Indirect Number" << std::endl;
    std::cout << "K. Run Experiment With Different Numbers (Multiplier, Increment, and Modulus)" << std::endl;
    std::cout << std::string(100, char(205)) << std::endl;
    std::cout << "0. Return" << std::endl;
    std::cout << std::string(100, char(205)) << std::endl;

    char option = toupper(inputChar("Option : "));
    return option;
}

// Pre-Condition: 
// Post-Condition:
void Pseudorandom::generateIndirectNumTable(Pseudorandom pseudorandom)
{
    pseudorandom.setMultiplier(21);
}


/*
double generateGaussian(const std::vector<int>& gaussian) {
    double sum = 0.0;

    for (int i : gaussian) {
        sum += i;
    }

    double mean = sum / gaussian.size();
    double squaredSum = 0.0;

    for (int i : gaussian) {
        squaredSum += pow(i - mean, 2.0);
    }

    double totalDev = squaredSum / (gaussian.size() - 1);
    double standardDev = sqrt(totalDev);
    return standardDev;
}


void displayGenerateGaussian() {
    const int SIZE = 10;
    std::vector<int> numberOfOc(SIZE, 0.0);

    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        numberOfOc[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    double gaussianValue = generateGaussian(numberOfOc);

    std::cout << "\n\t\tWith " << SIZE << " uniformly distributed rand number in the range[0...1.0),\n";
    std::cout << "\t\tthe approximate Gaussian distribution is " << gaussianValue;
}

int generateNextNumber() {
    double nextNumber = (multiplier() * seed + increment) % modulus;
    seed = static_cast<int>(nextNumber);
    return seed;
}

*/

//precondition: going to get the math, using a vector argu so then went print out i can get the information
//postcondition: going to get the sum , mean, and then return the standard deviation
double Pseudorandom::generateGaussian(const std::vector<int> gaussian) {
    double sum = 0.0;
    //go through the data
    for (double i : gaussian) {
        //going to be adding to get the sum
        sum += i;
    }
    double mean = sum / gaussian.size();
    double squaredSum = 0.0;
    for (double i : gaussian) {
        //going to use the pow(lets me square), add all the numbers in the data, call the getMean(mean) function
        squaredSum += pow(i - mean, 2.0);
    }
    //going to then get the square sum and divide it by the size - 1 since thats the formula
    double totalDev = squaredSum / (gaussian.size() - 1);
    double standardDev = sqrt(totalDev);
    return standardDev;
}

//precondition: going to be able to display the information
//postcondition: going to call my member function generateGaussian() to get the gaussian, then show the information
void Pseudorandom::displayGenerateGaussian() {
    const int SIZE = 10;
    //keeping track of the number of occurrences, Size(10, and 0 is the initialize of the values
    std::vector<int>numberOfOc(SIZE, 0.0);
    //doing the srand() so it can change random numbers and not be the same
    srand(time(0));
    //using the generate function to get the beginning and end of the vector size, then 3rd argu makes it rand()
    generate(numberOfOc.begin(), numberOfOc.end(), rand);
    //using the rand() to get random numbers
    setSeed(rand());
    setMultiplier(rand());
    setIncrement(rand());
    setModulus(rand());
    std::cout << "\n\t\texperiment of pseudorandom with random multiplier, increment and modulus: \n\n";
    std::cout << "\t\t" << std::string(76, char(205));
    std::cout << "\n\t\tmultiplier = " << getMultiplier() << ", increment = " << getIncrement() << ", modulus = " << getModulus();
    std::cout << "\n\n\t\tRange \t\tNumber of Occurrences";

    for (int i = 0; i < SIZE; i++) {
        std::cout << "\n\t\t[" << i / static_cast<double>(SIZE) << " ... " << (i + 1) / static_cast<double>(SIZE) << ")\t" << numberOfOc[i];
        numberOfOc[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    double gaussianValue = generateGaussian(numberOfOc);
    std::cout << "\n\n\t\tWith " << SIZE << " uniformly distributed rand number in the range[0...1.0),\n";
    std::cout << "\t\tthe approximate Gaussian distribution is " << gaussianValue;
}

//precondition: going to get the next number (member function)
//postcondition: going to write down the formula to get my next number, then return the next number 
int Pseudorandom::generateNextNumber() {
    //formula for generating a sequence of pseudorandom numbers
    double nextNumber = (multiplier * seed + increment) % modulus;
    return nextNumber;
}

