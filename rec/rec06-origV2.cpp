/*
  Recitation 06
  CS2124
 
  Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << ' ' << rhs.room
           << ' ' << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
        : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    unsigned getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    // Overload output operator
    friend ostream& operator<<(ostream& os, const Directory& rhs){
        for(int i = 0; i < rhs.size ; ++i){
            // this could be wrong
            os << *rhs.entries[i] << endl;
        }
        return os;
    }
public:
    Directory(size_t size = 0,size_t capacity = 1):size(size),capacity(capacity),entries(new Entry*[capacity]){}
    
    Directory(const Directory& rhs): size(rhs.size),capacity(rhs.capacity), entries(new Entry*[rhs.capacity]){
        cout << "using copy constructor" << endl;
        for(int i = 0;i < size; ++i){
            ///
            // using a deep copy. call the Entry deflut copy constructor. And create a copy entry in the heap!!
            entries[i] =  new Entry(*rhs.entries[i]);
        }
    };
    
    Directory& operator=(const Directory& rhs){
        cout << "using assign constructor" << endl;
        if(this != &rhs){
            // maybe the free up here need to use clear;
            for(int i=0; i < size ; ++i){
                delete entries[i];
            }
            delete[] entries;
            
            size = rhs.size;
            capacity = rhs.capacity;
            
            entries = new Entry*[size];
            
            // using a deep copy. call the Entry deflut copy constructor. And create a copy entry in the heap!!
            for(int i = 0; i < size;++i){entries[i] = new Entry(*rhs.entries[i]);}
        }
        
        return *this;
    }
    
    const unsigned operator[] (string name) const{
        for(int i = 0; i < size ; ++i){
            if(entries[i] -> getName() == name){
                //pos = i;
                return entries[i] -> getPhone();
            }
        }
        
        
        return 0;
    }
    
    ~Directory(){
        cout << "using destructor" << endl;
        for(int i = 0; i < size ; ++i){
            delete entries[i];
        }
        delete[] entries;
    }
    
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)	{
            // something is missing!!!  Add it!
            Entry** oldEntries = entries;
            entries = new Entry*[2*capacity];
            for (size_t i =0 ; i < size; ++i){
                entries[i] = oldEntries[i];
            }
            capacity *= 2;
            
            delete[] oldEntries;
            
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
    

    
//    Entry** begin(){return entries;};
//    Entry** end(){return entries + size;};

private:
    // Entry* *
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

void doNothing(Directory dir) {
    cout << dir << endl;}

int main() {
	
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
	
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;	// What function is being used??
    // using copy constructor
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d2 << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    // using assign constructor
    d3 = d2;
    
    

    // Should display 1592
    cout << d2["Carmack"] << endl;
	
} // main
