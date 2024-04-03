// Include necessary libraries
#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;
// Define a Hospital class
class Hospital{
    string* patientName;
    int* patientAge;
    string* diseaseName;
    string* doctorName;
    string* date;
    string* cardNumber;

public:
    // Declare public member functions
    Hospital(){
patientName=new string;
patientAge=new int;
diseaseName=new string;
doctorName=new string;
date=new string;
cardNumber=new string;
    };// Constructor
    ~Hospital(){
        delete patientName;
        delete patientAge;
        delete diseaseName;
        delete doctorName;
        delete date;
        delete cardNumber;
    }
    void appointmentsR();// Function to record appointments
    void displayappointment();// Function to display appointments
    void searchPatient();// Function to search for a patient
    void Delete();// Function to delete a patient record
    void roomNumber();// Function to assign room number (commented out in this code)
    void mapDeallocation();
};
// Declare a map to store hospital data
map<string,list<string>> lionHospital;


// Define the appointmentsR function
void Hospital::appointmentsR(){
    // This function prompts the user to enter patient details and stores them in the map
    cout<<"Enter patient name: ";
    getline(cin, *patientName);
    cout<<"patient age: ";
    cin>>*patientAge;
    cin.ignore(); // to clear the newline character from the input buffer
    cout<<"Enter disease name: ";
    getline(cin, *diseaseName);
    cout<<"Enter card number: ";
    getline(cin, *cardNumber);
    cout<<"Enter appointments record date: ";
    getline(cin, *date);
    lionHospital[*cardNumber] = {*patientName, to_string(*patientAge), *date, *diseaseName};
    cout<<"\nRecord added successfully\n";
}
// Define the displayappointment function
    void Hospital::displayappointment() {
    // This function displays all the appointments stored in the map
        cout<<"Card Number"<<" Patient Name "<<"Age "<<"Date "<<" Disease "<<endl;
        for(auto it:lionHospital){
            cout << it.first << " ";
            for(const auto& item : it.second) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
// Define the searchPatient function
void Hospital::searchPatient(){
    // This function prompts the user to enter a card number and searches for it in the map
    cout <<"Enter card number: ";
    getline(cin, *cardNumber);
    if(lionHospital.find(*cardNumber)!=lionHospital.end()){
        cout<<"Patient is found"<<endl;
        cout<<"patient list: ";
        for(const auto& item : lionHospital[*cardNumber]) {
            cout << item << " ";
        }
        cout << endl;
    } else {
        cout << "Patient not found" << endl;
    }
}
void Hospital::Delete(){
    // This function prompts the user to enter a card number and deletes the corresponding record from the map
    cout<<"Enter patient card number: ";
    getline(cin, *cardNumber);
    if(lionHospital.find(*cardNumber)!=lionHospital.end()){
        lionHospital.erase(*cardNumber);
        cout<<"Removed patient card number from list"<<endl;
    }
    else{
        cout<<"The patient is not found please insert a card number correctly"<<endl;
    }
}
void Hospital::mapDeallocation(){
    // This function deletes all the records from the map
    for(auto it:lionHospital) {
        lionHospital.erase(it.first);
    }
    if(lionHospital.empty()){
        cout<<"All records deleted"<<endl;
    }
    else{
        cout<<"Record are not deleted"<<endl;
    }
}

// Define the main function
int main(){
    // Create an instance of Hospital
    Hospital Patient;
    // Enter an infinite loop to display a menu and perform actions based on user choice
    while(true) {
        cout<<"1) Appointments record\n";
        cout<<"2) Display appointment\n";
        cout<<"3) Search patient\n";
        cout<<"4) Delete patient from patient list\n";
        cout<<"5)Deallocte map from memory\n";
        cout<<"6) Exit\n";
        char choice;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // to clear the newline character from the input buffer
        switch (choice) {
            case '1':
                Patient.appointmentsR();
                break;
            case '2':
                Patient.displayappointment();
                break;
            case '3':
                Patient.searchPatient();
                break;
            case '4':
                Patient.Delete();
            // exit the program
            case '5':
                Patient.mapDeallocation();
                break;
            case '6':
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}



