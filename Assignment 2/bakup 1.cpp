/* UNISA Semester 1 - Assignment 2 - Question 2
*  Display a Student Academic Report
*  Name: Roan Fourie
*  Date: 2020-04-03
*  Reference to Tutorial Letter 102/2/2020
*  Introduction to Programming I
*  COS1511
*  Description: Suppose we want to compile a student academic report for a high school learner in grade 12 (matric).
*      A matric learner is enrolled for 6 study units (subjects), namely: English, Mathematics, Life Orientation,
*      History, Computer literacy, Geography. The learner has to pass at least four subjects, including English,
*      to complete grade 12. The subject pass mark is 50%.
*      Write a program that prompts the learner to key in their marks for each subject.
*/

#include <iostream>
#include <iomanip>
using namespace std;

string subjects[6] = {"English","Mathematics","Life Orientation ","History","Computer literacy","Geography"};

struct typeStudent {
    // arrays will be used: [0] to [5] will be used for each subject; [6] will be used for average
    // [0] = English, [1] = Mathematics, [2] = Life Orientation, [3] = History, [4] = Computer literacy, [5] = Geography, [6] = Average
    string name;
    string schoolName;
    float marks[7];
    string symbols[7];
    int codes[7];
    bool distinctions[7]; // each attribute can be true or false
    string outcome;
    float lowest;
    float highest;
};

struct typeSevenVals {
    float value[7];
};

// Function Definitions
typeStudent studentDetails(void);
float getMarks(string subject);
float calcAverageYearMark(float marks[7]);
typeSevenVals minMax(float marks[7]);
string passOrFail(float marks[7]);
bool awardDistinction(float mark);
typeStudent codeSymbol(typeStudent student);
void report(typeStudent student);

//**********************************************************************************************************************
/// Main: Create and display a Student Academic Record
//**********************************************************************************************************************
int main(){
    typeStudent student;
    typeSevenVals minmax;

    // Get the student name and school name
    student = studentDetails();
    
    // Get the student marks one by one
    for (int i=0; i<6; i++){
        student.marks[i] = getMarks(subjects[i]);
    }

    // Calculate the average Year Mark
    student.marks[6] = calcAverageYearMark(student.marks);

    // Check and award distinctions for each mark as well as for the end result
    for (int n=0; n<7; n++){
        student.distinctions[n] = awardDistinction(student.marks[n]);
    }

    // Determine the Symbols and the Codes for each mark as well as for the end result
    student = codeSymbol(student);

    // Determine if student passed or failed
    student.outcome = passOrFail(student.marks);

    // Get the lowest and highest marks
    minmax = minMax(student.marks);
    student.lowest = minmax.value[0];
    student.highest = minmax.value[1];

    // Compile and print the report
    report(student);

    return 0;
}

//**********************************************************************************************************************
/// Get the Student details: Name, Surname and Schoolname
//**********************************************************************************************************************
typeStudent studentDetails(void){
    typeStudent newStudent;

    cout << "Please key in your name: " << endl;
    getline(std::cin, newStudent.name); 
    cout << "Please key in the name of your school: " << endl;
    getline(std::cin, newStudent.schoolName); 

    return newStudent;
}

//**********************************************************************************************************************
/// Prompts the student for the marks for each subject
//**********************************************************************************************************************
float getMarks(string subject){
    float mark;

    cout << "Key in your mark for " << subject << ": " << endl;
    cin >> mark;

    return mark;
}

//**********************************************************************************************************************
/// Calculates the Average Year Mark by adding every mark up and dividing it by the quantity of marks (6)
//**********************************************************************************************************************
float calcAverageYearMark(float marks[7]){
    float combinedMark = 0;
    float ave;

    for (int i=0; i<6; i++){
        combinedMark += marks[i];
    }
    ave = combinedMark/6;
    return ave;
}

//**********************************************************************************************************************
/// Gets the lowest and largest marks
//**********************************************************************************************************************
typeSevenVals minMax(float marks[7]){
    typeSevenVals results;
    float smallest = 100, largest = 0;

    for (int j=0; j<6; j++){
        for (int i=0; i<6; i++){
            if (marks[i] > largest){
                largest = marks[i];
            }
            if (marks[i] < smallest){
                smallest = marks[i];
            }
        }
    }
    results.value[0] = smallest;
    results.value[1] = largest;

    return results;
}

//**********************************************************************************************************************
/// Calculates the outcome of the average Year Mark
//**********************************************************************************************************************
string passOrFail(float marks[7]){
// The learner has to pass at least four subjects, including English, to complete grade 12. The subject pass mark is 50%.
    int countPasses = 0;

    for (int i=0; i<7; i++){ // Count the marks that pass.
        if (marks[i] >= 50){ // The subject pass mark is 50%.
            countPasses++;
        }
    }

    if (marks[0] >= 50){ // marks[0] is the mark for English Subject, which must be passed
        if (countPasses >= 4){ // if English is passed, we check the count wich must be four or more for a pass
            return "Passed";
        } else { // If not enough subjects is passed
            return "Failed";
        }
    } else { // if English is not passed
        return "Failed"; 
    }
}

//**********************************************************************************************************************
/// Determine which of the subjects have received distinctions.
// A subject receives a distinction if the mark is 75% and above. Also a student
// has passed with distinction if the average mark is 75% and above.
//**********************************************************************************************************************
bool awardDistinction(float mark){

    if (mark >= 75){
        return true;
    } else {
        return false;
    }
}

//**********************************************************************************************************************
/// convert each mark to a symbol (A, B, C, D, E, F) and a code (7,6,5,4,3,2,1).
//**********************************************************************************************************************
typeStudent codeSymbol(typeStudent student){
    typeStudent newStudent;

    newStudent = student;
    for (int i=0; i<7; i++){
        if (student.marks[i] >= 80 && student.marks[i]<= 100){
            newStudent.symbols[i] = "A";
            newStudent.codes[i] = 7;
        } else if (student.marks[i] >= 70 && student.marks[i]<= 79){
            newStudent.symbols[i] = "B";
            newStudent.codes[i] = 6;
        } else if (student.marks[i] >= 60 && student.marks[i]<= 69){
            newStudent.symbols[i] = "C";
            newStudent.codes[i] = 5;
        } else if (student.marks[i] >= 50 && student.marks[i]<= 59){
            newStudent.symbols[i] = "D";
            newStudent.codes[i] = 4;
        } else if (student.marks[i] >= 40 && student.marks[i]<= 49){
            newStudent.symbols[i] = "E";
            newStudent.codes[i] = 3;
        } else if (student.marks[i] >= 30 && student.marks[i]<= 39){
            newStudent.symbols[i] = "F";
            newStudent.codes[i] = 2;
        } else if (student.marks[i] >= 0 && student.marks[i]<= 29){
            newStudent.symbols[i] = "FF";
            newStudent.codes[i] = 1;
        }
    }
    for (int i=0; i<7; i++){
        newStudent.marks[i] = student.marks[i];
    }
    return newStudent;
}

//**********************************************************************************************************************
/// Display the student report.
//**********************************************************************************************************************
void report(typeStudent student){
    typeStudent newStudent;

    newStudent = student;

    for (int i=0; i<6; i++){
        newStudent.distinctions[i] = awardDistinction(newStudent.marks[i]);
    }
    cout << std::left;
    cout << "\n***************************************************" << endl;
    cout << "STUDENT ACADEMIC RECORD" << endl;
    cout << "***************************************************" << endl;
    cout << "Name: " << newStudent.name << "          School: " << newStudent.schoolName << endl;
    cout << endl;
    cout << std::setw(20) << "Subject " << std::setw(6) << "Mark " << std::setw(8) << "Symbol" << std::setw(6) << "Code " << endl;
    for (int i=0; i<6; i++){
        if (newStudent.distinctions[i] == true){
            cout << std::setw(20) << subjects[i] << std::setw(4) << newStudent.marks[i] << std::setw(2) << "% " << std::setw(8) << newStudent.symbols[i] << std::setw(6) << newStudent.codes[i] << "  *Distinction! " << endl;
        } else {
            cout << std::setw(20) << subjects[i] << std::setw(4) << newStudent.marks[i] << std::setw(2) << "% " << std::setw(8) << newStudent.symbols[i] << std::setw(6) << newStudent.codes[i] << endl;
        }
    }
    cout << "\nAverage Year Mark: " << newStudent.marks[6] << "% with Symbol " << newStudent.symbols[6] << " and code " << newStudent.codes[6] << endl;
    if (newStudent.distinctions[6] == true){
        cout << "Outcome: " << newStudent.outcome << "  *Distinction! " << endl;
    } else {
        cout << "Outcome: " << newStudent.outcome << endl;
    }
    cout << "\nThe highest mark was " << newStudent.highest << "% " << endl;
    cout << "The lowest mark was " << newStudent.lowest << "% " << endl;
    cout << "***************************************************" << endl;
}