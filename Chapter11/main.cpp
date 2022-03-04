#include <iostream>
#include <string>
#include <iomanip>
#include "input121.h"
using namespace std;
int menuOption();
void Challenge6();
void Challenge7();
void Challenge8();
void Challenge11(); 
void Challenge12();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 6: Challenge6(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break;
        case 11: Challenge11(); break;
        case 12: Challenge12(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{

    cout << "\nt Chapter 11 Assigments" << endl;
    cout << "\n" << string(60, char(9205)) << endl;
    cout << "\n0. Exit 0" << endl;
    cout << "\n6. Challenge 6" << endl;
    cout << "\n7. Challenge 7" << endl;
    cout << "\n8. Challenge 8" << endl;
    cout << "\n11. Challenge 11" << endl;
    cout << "\n12. Challenge 12" << endl;
    cout << "\n" << string(60, char(9205)) << endl;
    int option;
    cin >> option;

    return option;
}


struct Player
{
    string name ="Unknown";
    int number = 0;
    int scorePoints = 0;
};
void Challenge6()
{
    const int SIZE = 12;
    Player players[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        cout << "index" << i << endl;
        cin.ignore();
        players[i].name = inputString("\t Enter player's name: ", true);
        players[i].number = inputInteger("\t Enter Player number: ", true);
        players[i].scorePoints = inputInteger("\t Enter Player score Points: ", true);

     }

    int totalPoints = 0;
    int highScore = 0;
    int playerIndex = 0;

    for (int i = 0; i < SIZE; i++)
    {
        totalPoints += players[i].scorePoints;
        cout << setw(30) << left << players[i].name << setw(10) << right<< players[i].number << setw(10) << right << players[i].scorePoints << endl;
        
        if (players[i].scorePoints > highScore)
        {
            highScore = players[i].scorePoints;
            playerIndex = i;
        }
    }
    cout <<"\t Total Points Scored: " << totalPoints << endl;
    cout << "\t The players with higher scores" << players[playerIndex].name << " " << players[playerIndex].number << endl;

}



struct Account
{
    string name = "Unknown";
    string address = "Unknown";
    string cityStateZip = "Unknown";
    string phoneNumber = "Unknown";
    double balance = 0.00;
    string date = "mm/dd/yyyy";

};
void Challenge7()
{

    int SIZE = inputInteger("t Enter the number of accounts to be created:", 1, 20);
    Account* accounts = new Account[SIZE];

    //input 
    for (int i = 0; i < SIZE; i++)
    {
        cout << "index: " << i << endl;
        accounts[i].name = inputString("\t Enter customer name: ", true);
        accounts[i].address = inputString("\t Enter customer address: ", true);
        accounts[i].cityStateZip = inputString("\t Enter customer city, State, Zip: ", true);
        accounts[i].phoneNumber = inputString("\t Enter phone number", true);
        accounts[i].date = inputString("\t Enter date of last payment", false);
        accounts[i].balance = inputDouble("\t Enter Balance: $", 0.01,1000.00);
        cout << "\n";
        
    }

    //updates record using index
    int index = inputInteger("\t Enter index of account to change: ", 0, SIZE - 1);
    accounts[index].name = inputString("\t Enter customer name: ", true);
    accounts[index].address = inputString("\t Enter customer address: ", true);
    accounts[index].cityStateZip = inputString("\t Enter customer city, State, Zip: ", true);
    accounts[index].phoneNumber = inputString("\t Enter phone number", true);
    accounts[index].date = inputString("\t Enter date of last payment", false);
    accounts[index].balance = inputDouble("\t Enter Balance: $", 0.01, 1000.00);
    cout << "\n";

   

    //display:
    for (int i = 0; i < SIZE; i++)
    {
        cout << "index: " << i << endl;
        cout << "\t Customer information:" << endl;
        cout<< "\t Name: " << accounts[i].name << '\n';
        cout<<"\t Address: " << accounts[i].address << '\n';
        cout << "\t City: " <<  accounts[i].cityStateZip << '\n';
        cout << "\t Phone Number: " << accounts[i].phoneNumber << '\n';
        cout << "\t Date: " << accounts[i].date << '\n';
        cout << "\t Balance: $" << accounts[i].balance << '\n';
     
    }


    delete[] accounts;
}

void Challenge8()
{

}


void Challenge11()
{

}

struct  StudentGrade
{
    string name = "Unknow";
    int id = 0;
    int *testScores = 0;
    double average = 0;
    char grade = 'F';

};

enum letterGrade {A,B,C,D,F};
void getStudents(StudentGrade*, const int, const int);
void getScores(StudentGrade*, const int, const int);
void avgScore(StudentGrade*, const int, const int);
void assignGrade(StudentGrade*, const int);
void displayTable(const StudentGrade*, const int);


void Challenge12()
{
    StudentGrade* students = nullptr;


    int numStudents = 0;
    int numTests = 0;

    cout << "Gradebook" << endl;
    cout << "\tHow many students are in your class? ";
    cin >> numStudents;

    cout << "\tHow many tests scores do you wish to grade?   ";
    cin >> numTests;

    students = new StudentGrade[numStudents]();

    getStudents(students, numStudents, numTests);
    getScores(students, numStudents, numTests);
    avgScore(students, numStudents, numTests);
    assignGrade(students, numStudents);
    displayTable(students, numStudents);

    // Free dinamically allocated memory
    delete[] students;
    students = nullptr;
}

void getStudents(StudentGrade* students, const int numStudents,
    const int numTests)
{
    //dinamically allocation of test scores to an arrray
    for (int index = 0; index < numStudents; index++)
    {
        students[index].testScores = new int[numTests]();
    }
}
void getScores(StudentGrade* students, const int numStudents,
    const int numTests)
{
    //Sorting input and allocating it to the correct member of structure:
    for (int index = 0; index < numStudents; index++)
    {
        cout << "\n\tStudent name: ";
        cin.ignore();
        getline(cin, students[index].name);

        //validateing name:
        while (students[index].name.empty() ||
            isblank(students[index].name[0]) &&
            !isalpha(students[index + 1].name[index]))
        {
            cout << "\tStudent name: ";
            getline(cin, students[index].name);
        }

        cout << "\tStudent ID:   ";
        cin >> students[index].id;
      
        while (students[index].id == students[index - 1].id ||
            students[index].id == 0)
        {
            cout << "\n\tStudent ID:   " << students[index].id
                << " taken.\n"
                << "\tStudent ID:   ";
            cin >> students[index].id;
        }

        for (int blank = 0; blank < 1; blank++)
        {
            cout << "\n";
        }

        for (int testIdx = 0; testIdx < numTests; testIdx++)
        {
            cout << "\tTest score " << (testIdx + 1) << ": ";
            cin >> students[index].testScores[testIdx];

            //No negative number on Test Scores:
            while (students[index].testScores[testIdx] <= 0 ||
                students[index].testScores[testIdx] > 100)
            {
                cout << "\n\tInvalid score!\n"
                    << "\tTest score " << (testIdx + 1) << ": ";
                cin >> students[index].testScores[testIdx];
            }
        }
    }
}
void avgScore(StudentGrade* students, const int numStudents,
    const int numTests)
{
    // Calculate the stotal of test scores  &
    // Get the average score for each student:
    for (int index = 0; index < numStudents; index++)
    {
        double total = 0.0;

        for (int testIdx = 0; testIdx < numTests; testIdx++)
        {
           
            total += students[index].testScores[testIdx];
            
            students[index].average = total / numTests;
        }
    }
}

void assignGrade(StudentGrade* students, const int numStudents)
{
    //Assigning grades according to test scores:
    const char letterGrades[] = { 'A', 'B', 'C', 'D', 'F' };

    for (int studentIndex = 0; studentIndex < numStudents; studentIndex++)
    {
        students[studentIndex].average > 90 ? students[studentIndex].grade = letterGrades[A] :
            students[studentIndex].average >= 81 && students[studentIndex].average < 91 ?
            students[studentIndex].grade = letterGrades[B] :
            students[studentIndex].average >= 71 && students[studentIndex].average < 81 ?
            students[studentIndex].grade = letterGrades[C] :
            students[studentIndex].average >= 61 && students[studentIndex].average < 71 ?
            students[studentIndex].grade = letterGrades[D] :
            students[studentIndex].grade = letterGrades[F];
    }
}

void displayTable(const StudentGrade* students, const int numStudents)
{
        //using dynamic allocated array to display student table:
    cout << "\n\t REPORT CARD\n\n"
        << "\tStudent Name"
        << setw(25) << right << "Student ID"
        << setw(19) << right << "Average Score"
        << setw(23) << right << "Letter Grade\n";
    cout << "\t" << setw(79) << right << setfill('-') << "\n";
    cout << setfill(' ');

    for (int studentIndex = 0; studentIndex < numStudents; studentIndex++)
    {
        cout << fixed << showpoint << setprecision(2) << "\t";
        cout << setw(25) << left << students[studentIndex].name
             << setw(12) << right << students[studentIndex].id
             << setw(19) << right << students[studentIndex].average
             << setw(22) << right << students[studentIndex].grade << "\n";
    }
}