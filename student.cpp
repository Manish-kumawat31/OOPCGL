#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Student
{
    int roll;
    char name[15];
    char address[25];
    char class_name[12];
    char dob[12];
    char licno[15];
    char blood_gr[3];
    char mobile_no[12];

public:
   
    Student()
    {
        roll = 0;
        strcpy(name, "");
        strcpy(address, "");
        strcpy(class_name, "");
        strcpy(dob, "");
        strcpy(licno, "");
        strcpy(blood_gr, "");
        strcpy(mobile_no, "");
    }


    Student(int roll, const char *name, const char *address, const char *class_name, const char *dob, const char *licno, const char *blood_gr, const char *mobile_no)
    {
        this->roll = roll;
        strcpy(this->name, name);
        strcpy(this->address, address);
        strcpy(this->class_name, class_name);
        strcpy(this->dob, dob);
        strcpy(this->licno, licno);
        strcpy(this->blood_gr, blood_gr);
        strcpy(this->mobile_no, mobile_no);
    }


    void accept()
    {
        cout << "\nEnter roll number: ";
        cin >> roll;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 15);
        cout << "Enter address: ";
        cin.getline(address, 25);
        cout << "Enter class name: ";
        cin.getline(class_name, 12);
        cout << "Enter DOB (dd/mm/yyyy): ";
        cin.getline(dob, 12);
        cout << "Enter license number: ";
        cin.getline(licno, 15);
        cout << "Enter blood group: ";
        cin.getline(blood_gr, 3);
        cout << "Enter mobile number: ";
        cin.getline(mobile_no, 12);
    }

    void display() const
    {
        cout << "\nRoll: " << roll;
        cout << "\nName: " << name;
        cout << "\nAddress: " << address;
        cout << "\nClass: " << class_name;
        cout << "\nDOB: " << dob;
        cout << "\nLicense No: " << licno;
        cout << "\nBlood Group: " << blood_gr;
        cout << "\nMobile No: " << mobile_no << endl;
    }
};

int main()
{
    int ch, n;
    Student students[20]; 

    while (true)
    {
        cout << "\nMenu\n1. Accept Student Details\n2. Display All Students\n3. Exit\nEnter Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEntering details for Student " << (i + 1) << ":\n";
                students[i].accept();
            }
            break;

        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << "\nDisplaying details of Student " << (i + 1) << ":\n";
                students[i].display();
            }
            break;

        case 3:
            exit(0);

        default:
            cout << "\nInvalid choice. Please try again.";
        }
    }

    return 0;
}


















#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Student
{
private:
    char *name, *class1, *div, *dob, *bldgrp, *address, *drv;
    int rno, phone;
    static int counter;

public:
    Student();
    Student(char *, int, char *, int, char *, char *, char *, char *, char *);
    ~Student();
    inline void getDetails();
    inline void showDetails();
    static void count();
};
int Student::counter;
Student::Student()
{
    name = new char[1];
    class1 = new char[1];
    div = new char[1];
    dob = new char[1];
    bldgrp = new char[1];
    address = new char[1];
    drv = new char[1];
    rno = 0;
    phone = 0;
}
Student::Student(char *name, int rno, char *address, int phone, char *class1, char *div, char *dob, char *bldgrp, char *drv)
{
    int len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
    len = strlen(class1);
    this->class1 = new char[len + 1];
    strcpy(this->class1, class1);
    len = strlen(div);
    this->div = new char[len + 1];
    strcpy(this->div, div);
    len = strlen(dob);
    this->dob = new char[len + 1];
    strcpy(this->dob, dob);
    len = strlen(bldgrp);
    this->bldgrp = new char[len + 1];
    strcpy(this->bldgrp, bldgrp);
    len = strlen(address);
    this->address = new char[len + 1];
    strcpy(this->address, address);
    len = strlen(drv);
    this->drv = new char[len + 1];
    strcpy(this->drv, drv);
    this->rno = rno;
    this->phone = 0;
}
Student::~Student()
{
    delete name;
    delete address;
    delete dob;
    delete drv;
    delete bldgrp;
    delete class1;
    delete div;
    rno = 0;
    phone = 0;
    cout << "\nThank you for deleting details\n";
}
void Student::getDetails()
{
    cout << "\n******Enter Details of Student ********\n";
    cout << "Name : ";
    cin >> name;
    cout << "Roll No. : ";
    cin >> rno;
    cout << "Class : ";
    cin >> class1;
    cout << "Div : ";
    cin >> div;
    cout << "Address: ";
    cin >> address;
    cout << "Phone : ";
    cin >> phone;
    cout << "Date of Birth : ";
    cin >> dob;
    cout << "Driving License : ";
    cin >> drv;
    cout << "Blood Group : ";
    cin >> bldgrp;
}
void Student::showDetails()
{
    Student::count();
    cout << "\nName : " << name;
    cout << "\tRoll No. : " << rno;
    cout << "\nClass : " << class1;
    cout << "\tDiv : " << div;
    cout << "\nAddress: " << address;
    cout << "\tPhone : " << phone;
    cout << "\nDate of Birth : " << dob;
    cout << "\tDriving License : " << drv;
    cout << "\tBlood Group : " << bldgrp << endl;
}
void Student::count()
{
    counter++;
    cout << "\n****************Details of Student " << counter << "****************\n";
}
int main()
{
    cout << "\n***************Student Information System***********\n";
    cout << "How many student you have?";
    int num;
    cin >> num;
    Student s[num];
    for (int i = 0; i < num; i++)
    {
        s[i].getDetails();
    }
    system("clear");
    cout << "\n***************Student Information System***********\n";
    for (int i = 0; i < num; i++)
    {
        s[i].showDetails();
    }
    Student s1("ABC", 5, "Pune", 12345, "SE", "A", "10-07-2016", "B+", "777");
    s1.showDetails();
    return 0;
}