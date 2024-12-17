#include <iostream> 
#include <string> 
using namespace std; 

class Publication { 
protected: 
    string title; 
    float price; 
 
public: 
    Publication() : title(""), price(0.0) {} 
 
    void getData() { 
        cout << "Enter title: "; 
        cin.ignore(); 
        getline(cin, title); 
        cout << "Enter price: "; 
        cin >> price; 
 
        if (price < 0) { 
            throw invalid_argument("Price cannot be negative."); 
        } 
    } 
 
    void displayData() const { 
        cout << "Title: " << title << ", Price: " << price << endl; 
    } 
 
    void resetData() { 
        title = ""; 
        price = 0.0; 
    } 
}; 
 
 
class Book : public Publication { 
private: 
    int pageCount; 
 
public: 
    Book() : pageCount(0) {} 
 
    void getData() { 
        try { 
            Publication::getData(); 
            cout << "Enter page count: "; 
            cin >> pageCount; 
 
            if (pageCount < 0) { 
                throw invalid_argument("Page count cannot be negative."); 
            } 
        } catch (exception &e) { 
            cout << "Exception: " << e.what() << endl; 
            resetData(); 
        } 
    } 
 
    void displayData() const { 
        Publication::displayData(); 
        cout << "Page Count: " << pageCount << endl; 
    } 
 
    void resetData() { 
        Publication::resetData(); 
        pageCount = 0; 
    } 
}; 
 
 
class Tape : public Publication { 
private: 
    float playTime; 
 
public: 
    Tape() : playTime(0.0) {} 
 
    void getData() { 
        try { 
            Publication::getData(); 
            cout << "Enter play time (in minutes): "; 
            cin >> playTime; 
 
            if (playTime < 0) { 
                throw invalid_argument("Play time cannot be negative."); 
            } 
        } catch (exception &e) { 
            cout << "Exception: " << e.what() << endl; 
            resetData(); 
        } 
    } 
 
    void displayData() const { 
        Publication::displayData(); 
        cout << "Play Time: " << playTime << " minutes" << endl; 
    } 
 
    void resetData() { 
        Publication::resetData(); 
        playTime = 0.0; 
    } 
}; 
 
int main() { 
    Book book; 
    Tape tape; 
 
    cout << "Enter details for book:\n"; 
    book.getData(); 
 
    cout << "\nEnter details for tape:\n"; 
    tape.getData(); 
 
    cout << "\nDisplaying book details:\n"; 
    book.displayData(); 
 
    cout << "\nDisplaying tape details:\n"; 
    tape.displayData(); 
 
    return 0; 
} 


