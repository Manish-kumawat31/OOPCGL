#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct PersonalRecord {
    string name;
    string dob;
    string phone;

    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }
};

void displayRecords(const vector<PersonalRecord>& records) {
    cout << "\nPersonal Records:\n";
    cout << "------------------------------------------\n";
    for (const auto& record : records) {
        cout << "Name: " << record.name
             << ", DOB: " << record.dob
             << ", Phone: " << record.phone << endl;
    }
    cout << "------------------------------------------\n";
}

void searchRecord(const vector<PersonalRecord>& records, const string& searchName) {
    auto it = find_if(records.begin(), records.end(),
        [&searchName](const PersonalRecord& record) {
            return record.name == searchName;
        });

    if (it != records.end()) {
        cout << "\nRecord Found:\n";
        cout << "Name: " << it->name
             << ", DOB: " << it->dob
             << ", Phone: " << it->phone << endl;
    } else {
        cout << "\nRecord with name \"" << searchName << "\" not found.\n";
    }
}

int main() {

    vector<PersonalRecord> records;

    records.push_back({"Alice", "1995-04-12", "9876543210"});
    records.push_back({"Bob", "1993-08-24", "9123456789"});
    records.push_back({"Charlie", "1990-01-15", "9988776655"});

    cout << "Records before sorting:";
    displayRecords(records);

    sort(records.begin(), records.end());

    cout << "Records after sorting by name:";
    displayRecords(records);

    string searchName;
    cout << "\nEnter the name to search: ";
    cin >> searchName;
    searchRecord(records, searchName);

    return 0;
}











#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Item
{
public:
    
    char name[10]; 
    int quantity;
    int cost;
    int code;
    bool operator==(const Item &i1)
       
    {
        if (code == i1.code)
           
    return 1;
    return 0;
    }
    bool operator<(const Item &i1)
    {
        if (code < i1.code)
          return 1;
          return 0;
    }
};
vector<Item> o1;
void print(Item &i1);
void display();
void insert();
void search();
void dlt();

bool compare(const Item &i1, const Item &i2)
{
    return i1.cost < i2.cost;
    return i1.cost < i2.cost;
}
int main()
{
    int ch;
    do
    {
        cout << "\n***** Menu *****";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Sort";
        cout << "\n5.Delete";
        cout << "\n6.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort(o1.begin(), o1.end(), compare);
            cout << "\n\n Sorted on Cost";
            display();
            break;
        case 5:
            dlt();
            break;
        case 6:
            exit(0);
        }
    } while (ch != 7);
    return 0;
}
void insert()
{
    Item i1;
    cout << "\nEnter Item Name:";
    cin >> i1.name;
    cout << "\nEnter Item Quantity:";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost:";
    cin >> i1.cost;
    cout << "\nEnter Item Code:";
    cin >> i1.code;
    o1.push_back(i1);
}
void display()
{
    for_each(o1.begin(), o1.end(), print);
}
void print(Item &i1)
{
    cout << "\n";
    cout << "\nItem Name:" << i1.name;
    cout << "\nItem Quantity:" << i1.quantity;
    cout << "\nItem Cost:" << i1.cost;
    cout << "\nItem Code:" << i1.code;
}
void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search:";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
        cout << "\nNot found.";
    else
    {
    }
}
void dlt()
{
    cout << "\nFound.";
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete:";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
        cout << "\nNot found.";
    else
    {
        o1.erase(p);
        cout << "\nDeleted.";
    }
}