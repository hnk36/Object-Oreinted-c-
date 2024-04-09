
#include <iostream>
#include "code2.cpp"
#include "code3.cpp"
using namespace std;
struct Date{
    int day, month, year;
};
struct student{
    int rollNo;
    string name;
    float mark[5];
    Date BoD;
    float result;
    void inPuter();
    void Display();
    void average();

};
void student::inPuter() {

        cout << "Enter rollNo: ";
        cin >> rollNo;
        cout << "Enter name: ";
        cin>>name;
        for (int i = 0; i < 5; i++) {
            cout << "Enter mark :";
            cin >> mark[i];
        }
        cout << "Enter Birth day: ";
        cin >> BoD.day >> BoD.month >> BoD.year;
}
void student::average() {
    float sum =0;

    for( int i=0; i< 5; i++) {
        sum += mark[i];
    }
    result = sum/5;
}
void student::Display() {

    cout<<rollNo<<"\t\t\t"<<name<<"\t\t\t"<<BoD.day<<"/"<<BoD.month<<"/"<<BoD.year<<"\t\t\t"<<result<<endl;
}


int main(){
    student person[1];
    for(int i=0; i<1; i++){
    person[i].inPuter();
    }
    cout<<endl;


        for (int i = 0; i < 1; i++) {
            person[i].average();
        }
    while(true) {
    char choice;
        cout << "Press 1 to display all " << endl;
        cout << "Press 2 to display below 50" << endl;
        cout<<"press 3 to exit program"<<endl;
        cin>>choice;

            switch (choice) {
                case '1':
                    cout << "RollNo" << "\t\t\t" << "name" << "\t\t\t" << "date" << "\t\t\t\t" << "Average" << endl;
                    for (int i = 0; i < 1; i++) {
                        person[i].Display();
                    }
                    break;
                case '2':
                    cout << "RollNo" << "\t\t\t" << "name" << "\t\t\t" << "date" << "\t\t\t\t" << "Average" << endl;
                    for (int i = 0; i < 1; i++) {
                        if (person[i].result < 50) {
                            person[i].Display();
                        }
                        else{
                            cout << "NULL" << "\t\t\t" << "0" << "\t\t\t" << "NULl" << "\t\t\t\t" << "0.00" << endl;
                            cout <<"all students average is above 50"<<endl;
                        }
                    }
                    break;
                case '3':
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
        }
    return 0;
}
