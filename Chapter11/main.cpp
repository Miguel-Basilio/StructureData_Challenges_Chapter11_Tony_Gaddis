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













struct MonthlyBudget
{
    double housing = 0.0;
    double utilities = 0.0;
    double householdExpenses = 0.0;
    double transportation = 0.0;
    double food = 0.0;
    double medical = 0.0;
    double insurance = 0.0;
    double entrenaiment = 0.0;
    double clothing = 0.0;
    double miscellaneous = 0.0;
    double total = 0.0;
};
void getBudget(MonthlyBudget&);
void totalMonthly(MonthlyBudget&);
void bugetTotalCalculation(const double, const double);
void displayBudget(const MonthlyBudget, const MonthlyBudget);
void Challenge11()
{
    MonthlyBudget spentBudget;
    MonthlyBudget fixedBuget = { 500.00,150.00,65.00,50.00,250.00,30.00,100.00,150.00,75.00,50.00,1420.00 };

    getBudget(spentBudget);
    totalMonthly(spentBudget);
    displayBudget(spentBudget, fixedBuget);

}
void getBudget(MonthlyBudget &spentBudget)
{
    cout << "\t Please enter the total spent for each category: \n";
    //getting all spending amounts from user:
    cout << "\t Housing: $";
    cin >> spentBudget.housing;
    while (spentBudget.housing <= 0.0)
    {
        cout << "\t Housing: $";
        cin >> spentBudget.housing;
    }
    cout << "\t Utilities: $";
    cin >> spentBudget.utilities;
    while (spentBudget.utilities <= 0.0)
    {
        cout << "\t Utilities: $";
        cin >> spentBudget.utilities;
    }
    cout << "\t Household Expenses: $";
    cin >> spentBudget.householdExpenses;
    while (spentBudget.householdExpenses <= 0.0)
    {
        cout << "\t Household Expenses: $";
        cin >> spentBudget.householdExpenses;
    }
    cout << "\t Transportation: $";
    cin >> spentBudget.transportation;
    while (spentBudget.transportation <= 0.0)
    {
        cout << "\t Transportation: $";
        cin >> spentBudget.transportation;
    }
    cout << "\t Food: $";
    cin >> spentBudget.food;
    while (spentBudget.food <= 0.0)
    {
        cout << "\t Food: $";
        cin >> spentBudget.food;
    }
    cout << "\t Medical: $";
    cin >> spentBudget.medical;
    while (spentBudget.medical <= 0.0)
    {
        cout << "\t Medical: $";
        cin >> spentBudget.medical;
    }
    cout << "\t Insurance: $";
    cin >> spentBudget.insurance;
    while (spentBudget.insurance <= 0.0)
    {
        cout << "\t Insurance: $";
        cin >> spentBudget.insurance;
    }
    cout << "\t Entretainment: $";
    cin >> spentBudget.entrenaiment;
    while (spentBudget.entrenaiment <= 0.0)
    {
        cout << "\t Entretainment: $";
        cin >> spentBudget.entrenaiment;
    }
    cout << "\t Clothing: $";
    cin >> spentBudget.clothing;
    while (spentBudget.clothing <= 0.0)
    {
        cout << "\t Clothing: $";
        cin >> spentBudget.clothing;
    }
    cout << "\t Miscellaneous: $";
    cin >> spentBudget.miscellaneous;
    while (spentBudget.miscellaneous <= 0.0)
    {
        cout << "\t Miscellaneous: $";
        cin >> spentBudget.miscellaneous;
    }
}
void totalMonthly(MonthlyBudget &spentBuget) 
{
    // adding all expenses to total variable:
    spentBuget.total = spentBuget.housing + spentBuget.utilities + spentBuget.householdExpenses + spentBuget.transportation +
        spentBuget.food + spentBuget.medical + spentBuget.insurance + spentBuget.entrenaiment + spentBuget.clothing + spentBuget.miscellaneous;
}
void bugetTotalCalculation(const double spentBudget, const double fixedBuget)
{

    //calculating under, over or balance budget:
    const string overBudget = "  over budget\n";
    const string underBudget = "  under budget!\n";

    if (spentBudget > fixedBuget)
    {
        cout << (spentBudget - fixedBuget) << overBudget;
    }
    if (spentBudget < fixedBuget)
    {
        cout << ( fixedBuget - spentBudget) << underBudget;
    }
    
}
void displayBudget(const MonthlyBudget spentBudget, const MonthlyBudget fixedBudget)
{
    cout << "\n\n\tMONTHLY BUDGET - EVALUATION\n\n\n";

    cout << "\tDESCRIPTION"
        << setw(20) << right << "BUDGETED"
        << setw(20) << right << "SPENT"
        << setw(34) << right << "OVER / UNDER";

    cout << "\n\t" << setw(97) << right << setfill('-') << "\n";

    cout << setfill(' ');
    cout << fixed << showpoint << setprecision(2);

    cout << setw(20) << left << "\tHousing"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.housing
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.housing
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.housing, fixedBudget.housing);

    cout << setw(20) << left << "\tUtilities"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.utilities
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.utilities
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.utilities, fixedBudget.utilities);

    cout << setw(20) << left << "\tHousehold Expenses"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.householdExpenses
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.householdExpenses
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.householdExpenses, fixedBudget.householdExpenses);

    cout << setw(20) << left << "\tTransport"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.transportation
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.transportation
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.transportation, fixedBudget.transportation);

    cout << setw(20) << left << "\tFood"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.food
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.food
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.food, fixedBudget.food);

    cout << setw(20) << left << "\tMedical"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.medical
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.medical
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.medical, fixedBudget.medical);

    cout << setw(20) << left << "\tInsurance"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.insurance
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.insurance
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.insurance, fixedBudget.insurance);

    cout << setw(20) << left << "\tEntertainment"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.entrenaiment
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.entrenaiment
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.entrenaiment, fixedBudget.entrenaiment);

    cout << setw(20) << left << "\tClothing"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.clothing
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.clothing
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.clothing, fixedBudget.clothing);

    cout << setw(20) << left << "\tMiscellaneous"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.miscellaneous
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.miscellaneous
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.miscellaneous, fixedBudget.miscellaneous);

    cout << "\t" << setw(97) << right << setfill('-') << "\n";
    cout << setfill(' ');

    cout << setw(20) << left << "\tTotal"
        << setw(5) << right << "$ " << setw(7) << right << fixedBudget.total
        << setw(16) << right << "$ " << setw(7) << right << spentBudget.total
        << setw(19) << right << "$ " << setw(7) << right;
    bugetTotalCalculation(spentBudget.total, fixedBudget.total);





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