#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
    char name[30];
    cout << "Enter the name of file to create ";
    cin >> name;
    ofstream fout;
    fout.open(name);
    if (!fout)
    {
        cout << "Error opening the file";
        exit(1);
    }
    cout << "Writing to the file" << endl;
    cout << "Enter contents for file end it with ^D";
    string data;
    while (getline(cin, data))
    {
        if (data == "^D")
            break;
        fout << data << endl;
    }
    fout.close();
    ifstream fin;
    fin.open(name);
    if (!fin)
    {
    }
    cout << "Error opening the file";
    exit(1);
    cout << "Reading from the file\n";
    while (fin)
    {
        getline(fin, data);
        cout << data;
    }
    fin.close();
    return 0;
}














#include <iostream>
#include <fstream> /
#include <string>

using namespace std;

int main() {
   
    ofstream outFile("example.txt");

   
    if (outFile.is_open()) {
       
        outFile << "Hello, this is a sample text written to the file.\n";
        outFile << "C++ file handling example.\n";

        
        outFile.close();
        cout << "Data written to the file successfully.\n";
    } else {
        cerr << "Error: Unable to open the file for writing.\n";
        return 1;
    }

    
    ifstream inFile("example.txt");

    
    if (inFile.is_open()) {
        string line;

        cout << "\nReading from the file:\n";
       
        while (getline(inFile, line)) {
            cout << line << endl;
        }

      
        inFile.close();
    } else {
        cerr << "Error: Unable to open the file for reading.\n";
        return 1;
    }

    return 0;
}
