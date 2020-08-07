/* UNISA Semester 1 - Assignment 2 - Question 2
*  Display a Student Academic Report
*  Name: Roan Fourie
*  Date: 2020-04-03
*  Reference to Tutorial Letter 102/2/2020
*  Introduction to Programming I
*  COS1511
*  Description: Suppose we want to compile a student academic report for a high school learner in grade 12 
*   (matric).
*      A matric learner is enrolled for 6 study units (subjects), namely: English, Mathematics, 
*      Life Orientation, History, Computer literacy, Geography. 
*      The learner has to pass at least four subjects, including English, to complete grade 12. 
*      The subject pass mark is 50%.
*      Write a program that prompts the learner to key in their marks for each subject.
*/

#include <iostream>
#include <iomanip>
using namespace std;

string subjects[6] = {"English","Mathematics","Life Orientation ","History","Computer literacy","Geography"};

struct typeStudent {
    // arrays will be used: [0] to [5] will be used for each subject; [6] will be used for average
    // [0] = English, [1] = Mathematics, [2] = Life Orientation, [3] = History, [4] = Computer literacy, 
    // [5] = Geography, [6] = Average
    string name;
    string surname;
    string schoolName;
    float marks[7];
    string symbols[7];
    int codes[7];
    bool distinctions[7]; // each attribute can be true or false
    string outcome;
    float lowest;
    float highest;
};

// Function Definitions
typeStudent studentDetails(void);
float getMarks(string subject);
float calcAverageYearMark(float marks[7]);
void minMax(float marks[7], float & min, float & max);
string passOrFail(float marks[7]);
bool awardDistinction(float mark);
typeStudent codeSymbol(typeStudent student);
void report(typeStudent student);

//*********************************************************************************************************
/// Main: Create and display a Student Academic Record
//*********************************************************************************************************
int main(){
    typeStudent student;
    float minimumScore;
    float maximumScore;

    // Get the student name and school name
    student = studentDetails();
    
    // Get the student marks one by one
    for (int i=0; i<6; i++){
        student.marks[i] = getMarks(subjects[i]);
    }

    // Calculate the average Year Mark
    student.marks[6] = calcAverageYearMark(student.marks);

    // Check and award distinctions for each mark as well as for the end result
    for (int j=0; j<7; j++){
        student.distinctions[j] = awardDistinction(student.marks[j]);
    }

    // Determine the Symbols and the Codes for each mark as well as for the end result
    student = codeSymbol(student);

    // Determine if student passed or failed
    student.outcome = passOrFail(student.marks);

    // Get the lowest and highest marks
    minMax(student.marks, minimumScore, maximumScore);
    student.lowest = minimumScore;
    student.highest = maximumScore;

    // Compile and print the report
    report(student);

    return 0;
}

//*********************************************************************************************************
/// Get the Student details: Name and Schoolname
//*********************************************************************************************************
typeStudent studentDetails(void){
    typeStudent newStudent;

    cout << "Please key in your name: " << endl;
    getline(std::cin, newStudent.name); 
    cout << "Please key in your surname: " << endl;
    getline(std::cin, newStudent.surname); 
    cout << "Please key in the name of your school: " << endl;
    getline(std::cin, newStudent.schoolName); 

    return newStudent;
}

//*********************************************************************************************************
/// Prompts the student for the marks for each subject
//*********************************************************************************************************
float getMarks(string subject){
    float mark;

    cout << "Key in your mark for " << subject << ": " << endl;
    cin >> mark;
    while (mark > 100 || mark < 0){
        cout << "Please try again, the value must be between 0 and 100: " << endl;
        cin >> mark;
    }

    return mark;
}

//*********************************************************************************************************
/// Calculates the Average Year Mark by adding every mark up and dividing it by the quantity of marks (6)
//*********************************************************************************************************
float calcAverageYearMark(float marks[7]){
    float combinedMark = 0;
    float ave;

    for (int i=0; i<6; i++){
        combinedMark += marks[i];
    }
    ave = combinedMark/6;
    return ave;
}

//*********************************************************************************************************
/// Gets the lowest and largest marks
//*********************************************************************************************************
void minMax(float marks[7], float & min, float & max){
    min = 100;
    max = 0;

    for (int j=0; j<6; j++){
        for (int i=0; i<6; i++){
            if (marks[i] > max){
                max = marks[i];
            }
            if (marks[i] < min){
                min = marks[i];
            }
        }
    }
}

//*********************************************************************************************************
/// Calculates the outcome of the average Year Mark
// The learner has to pass at least four subjects, including English, to complete grade 12. 
// The subject pass mark is 50%.
//*********************************************************************************************************
string passOrFail(float marks[7]){
    int countPasses = 0;

    // Count the marks that pass, thus 50% or more.
    for (int i=0; i<7; i++){ 
        if (marks[i] >= 50){
            countPasses++;
        }
    }

    // Check if English is passed, if yes we check the quantity of passed results in total
    if (marks[0] >= 50){ // marks[0] is the mark for English Subject, which must be passed
        if (countPasses >= 4){ // Must be four or more for a pass
            return "Passed";
        } else { // If not enough subjects is passed
            return "Failed";
        }
    } else { // If English is not passed
        return "Failed"; 
    }
}

//*********************************************************************************************************
/// Determine which of the subjects have received distinctions.
// A subject receives a distinction if the mark is 75% and above. 
// Also a student has passed with distinction if the average mark is 75% and above.
//*********************************************************************************************************
bool awardDistinction(float mark){
    if (mark >= 75){
        return true;
    } else {
        return false;
    }
}

//*********************************************************************************************************
/// Convert each mark to a symbol (A, B, C, D, E, F) and a code (7,6,5,4,3,2,1).
//*********************************************************************************************************
typeStudent codeSymbol(typeStudent student){
    typeStudent aStudent;

    aStudent = student;
    for (int i=0; i<7; i++){
        if (student.marks[i] >= 80 && student.marks[i]<= 100){
            aStudent.symbols[i] = "A";
            aStudent.codes[i] = 7;
        } else if (student.marks[i] >= 70 && student.marks[i]<= 79){
            aStudent.symbols[i] = "B";
            aStudent.codes[i] = 6;
        } else if (student.marks[i] >= 60 && student.marks[i]<= 69){
            aStudent.symbols[i] = "C";
            aStudent.codes[i] = 5;
        } else if (student.marks[i] >= 50 && student.marks[i]<= 59){
            aStudent.symbols[i] = "D";
            aStudent.codes[i] = 4;
        } else if (student.marks[i] >= 40 && student.marks[i]<= 49){
            aStudent.symbols[i] = "E";
            aStudent.codes[i] = 3;
        } else if (student.marks[i] >= 30 && student.marks[i]<= 39){
            aStudent.symbols[i] = "F";
            aStudent.codes[i] = 2;
        } else if (student.marks[i] >= 0 && student.marks[i]<= 29){
            aStudent.symbols[i] = "FF";
            aStudent.codes[i] = 1;
        }
    }
    for (int i=0; i<7; i++){
        aStudent.marks[i] = student.marks[i];
    }
    return aStudent;
}

//*********************************************************************************************************
/// Display the student report.
//*********************************************************************************************************
void report(typeStudent student){
    typeStudent learner;

    learner = student;

    for (int i=0; i<6; i++){
        learner.distinctions[i] = awardDistinction(learner.marks[i]);
    }
    cout << std::left;
    cout << "\n***************************************************" << endl;
    cout << "STUDENT ACADEMIC RECORD" << endl;
    cout << "***************************************************" << endl;
    cout << "Name: " << learner.name << " " << learner.surname << "          School: " << learner.schoolName << endl;
    cout << endl;
    cout << std::setw(20) << "Subject " << std::setw(6) << "Mark " << std::setw(8) << "Symbol" << std::setw(6) << "Code " << endl;
    for (int i=0; i<6; i++){
        if (learner.distinctions[i] == true){
            cout << std::setw(20) << subjects[i] << std::setw(4) << learner.marks[i] << std::setw(2) << "% " << std::setw(8) << learner.symbols[i] << std::setw(6) << learner.codes[i] << "  *Distinction! " << endl;
        } else {
            cout << std::setw(20) << subjects[i] << std::setw(4) << learner.marks[i] << std::setw(2) << "% " << std::setw(8) << learner.symbols[i] << std::setw(6) << learner.codes[i] << endl;
        }
    }
    cout << "\nAverage Year Mark: " << learner.marks[6] << "% with Symbol " << learner.symbols[6] << " and code " << learner.codes[6] << endl;
    if (learner.distinctions[6] == true){
        cout << "Outcome: " << learner.outcome << " with distinction! " << endl;
    } else {
        cout << "Outcome: " << learner.outcome << endl;
    }
    cout << "\nThe highest mark was " << learner.highest << "% " << endl;
    cout << "The lowest mark was " << learner.lowest << "% " << endl;
    cout << "***************************************************" << endl;
}