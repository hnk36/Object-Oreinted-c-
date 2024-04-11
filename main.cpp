#include <iostream>
using namespace std;

// Define a structure to hold employee salary details
struct salary{
    int id;
    string name;
    double tax;
    double net_salary;
    double gross_salary;

    // Function to take input of employee details
    void input();

    // Function to calculate tax and net salary
    void Salary();

    // Function to display employee details
    void Displayer();
};

// Function to take input of employee details
void salary::input(){
    cout<<"Enter the id: ";
    cin>>id;
    cout<<"Enter the name: ";
    cin>>name;
    cout<<"Enter the gross salary: ";
    cin>>gross_salary;
}

// Function to calculate tax and net salary based on gross salary
void salary::Salary() {
    if(gross_salary>=10000){
        tax=gross_salary*0.35;
    }
    else if(gross_salary>=5000){
        tax=gross_salary*0.2;
    }
    else if(gross_salary>=3000){
        tax=gross_salary*0.15;
    }
    else{
        tax=0;
    }
    net_salary=gross_salary-tax;
}

// Function to display employee details
void salary::Displayer(){
    cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<net_salary<<endl;
}

// Function to search for an employee by ID and display their details
void search(salary s[] , int number) {
    int ID;

    cout<<"Enter Id: ";
    cin>>ID;
    for(int i=0;i<number;i++) {
        if (s[i].id == ID) {
            cout << "Employees_ID" << "\t\t" << "Employ name" << "\t\t" << "Net Salary" << endl;
            cout <<s[i].id << "\t\t\t" << s[i].name << "\t\t\t" << s[i].net_salary << endl;
        }
    }
}

// Main function
int main(){
    int number_em;
    cout<<"How many employees: ";
    cin>>number_em;

    // Create an array of salary structures
    salary s[number_em];

    // Input details for each employee
    for(int i=0;i<number_em;i++){
        s[i].input();
    }

    // Calculate tax and net salary for each employee
    for(int i=0;i<number_em;i++){
        s[i].Salary();
    }

    // Display details for each employee
    cout<<"Employees_ID"<<"\t\t"<<"Employ name"<<"\t\t"<<"Net Salary"<<endl;
    for(int i=0;i<number_em;i++){
        s[i].Displayer();
    }

    // Search for an employee by ID and display their details
    search(s, number_em);

    return 0;
}