/* UNISA Semester 1 - Assignment 2 - Question 1
*  Display BMI Result on screen
*  Name: Roan Fourie
*  Date: 2020-04-03
*  Reference to Tutorial Letter 102/2/2020
*  Introduction to Programming I
*  COS1511
*  Description:  BMI or Body Mass Index is a method of estimating a person's body fat levels based on a 
*       person's weight and height measurement. 
*       The BMI is calculated by dividing the person’s body mass/weight (in kilograms) by the square of 
*       the body height (in metres). 
*       The result is universally expressed in units of kg/m2.
*/

#include <iostream>
using namespace std;

void getData(double &weight, double &height);
double calcBMI(double kg, double meter);
void displayFitnessResults(double weight, double height, double bmi);

//*********************************************************************************************************
/// Main: Display the product of BMI (Body Mass Index) on screen
//*********************************************************************************************************
int main(){
    double bmi, weight, height;

    getData(weight, height);
    bmi = calcBMI(weight, height);
    displayFitnessResults(weight, height, bmi);
    
    return 0;
}

//*********************************************************************************************************
/// Prompts the user for weight and height and returns these values
//*********************************************************************************************************
void getData(double &weight, double &height){

    cout << "Enter your weight " << endl;
    cin >> weight;
    cout << "Enter your height " << endl;
    cin >> height;
}

//*********************************************************************************************************
/// Calculates the Body Mass Index
//*********************************************************************************************************
double calcBMI(double kg, double meter){
    double bmi;

    bmi = kg / (meter * meter);
    return bmi;
}

//*********************************************************************************************************
/// Display the various result messages
//*********************************************************************************************************
void displayFitnessResults(double weight, double height, double bmi){
    string fitness;

    cout << "The calculated BMI for weight: " << weight << " and height: " << height <<" is: " << bmi << endl;
    if (bmi < 18.5){
        fitness = "Underweight" ;
    } else if (bmi >= 18.5 && bmi <= 24.9){
        fitness = "Healthy" ;
    } else if (bmi >= 25.0 && bmi <= 29.9){
        fitness = "Overweight" ;
    } else {
        fitness = "Obese" ;
    }
    cout << "The Fitness Result is: " << fitness << endl;
}