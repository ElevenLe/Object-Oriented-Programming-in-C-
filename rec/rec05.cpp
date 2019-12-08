//
//  rec05.cpp
//  rec5
//
//  Created by Zhengyi Li on 10/5/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;



class StudentRecord{
public:
    
    friend ostream& operator<<(ostream& os, const StudentRecord& rhs){
        os << "Name: " << rhs.name << ", Grades: ";
        for(int grade : rhs.grades){
            os << grade << " ";
        }
        os << endl;
        return os;
    }
    
    
    StudentRecord(const string& name):name(name),grades(14,-1){    }
    
    const string& getName() const{
        // the function
        return name;
    }
    
    void changeGrade(int grade, int day){
        grades[day-1] = grade;
    };
    
private:
    string name;
    vector<int> grades;
};

class Section{
public:
//    overload teh Section
    friend ostream& operator<<(ostream& os, const Section& rhs){
        if (rhs.studentListPointer.size() == 0) {
            os << "Section: " << rhs.sectionName << ", Time slot: " << rhs.sectionTimeSlot << ", Students: None" ;
        }else{
            os << "Section: " << rhs.sectionName << ", Time slot: " << rhs.sectionTimeSlot << ", Students: " << endl;
            for(int i = 0; i < rhs.studentListPointer.size(); ++i){
                os << *rhs.studentListPointer[i] ;
            }
        }
        return os;
    };
    
//    constructor of Section, initialize the TimeSlot as well
    Section(const string& sectionName, const string& date, int dateNumber): sectionName(sectionName),sectionTimeSlot(date,dateNumber){};
    
    Section(const Section& oldSection) : sectionName(oldSection.sectionName), sectionTimeSlot(oldSection.sectionTimeSlot) {
        for(StudentRecord* oldCopyStudent: oldSection.studentListPointer){
            StudentRecord* newCopyStudent = new StudentRecord(*oldCopyStudent);
            // using defult copy constructor for Stu
            studentListPointer.push_back(newCopyStudent);
//            delete newCopyStudent;
        }
        
    }
    
    ~Section(){
        for(int i =0; i < studentListPointer.size(); ++i){
            delete studentListPointer[i];
            studentListPointer[i] = nullptr;
        }
    }
    
    void addStudent(const string& studentName){
        StudentRecord* newStudent = new StudentRecord(studentName);
        studentListPointer.push_back(newStudent);
    };
    
    void addGreade(const string& studentName, int grade, int time){
        for(StudentRecord* findStudent : studentListPointer){
            if (findStudent->getName() == studentName){
                findStudent->changeGrade(grade, time);
            }
        }
    };
    
private:
    string sectionName;
    
    
    class TimeSlot{
    public:
        TimeSlot(const string& date, int dateNumberLong): date(date) {
            if(dateNumberLong > 12){
                dateNumber = dateNumberLong - 12;
                dateNumberUnit = "pm";
                
            }
            else if(dateNumberLong <= 12){
                dateNumber = dateNumberLong;
                dateNumberUnit = "am";
            }
            
        };
        friend ostream& operator<<(ostream& os, const TimeSlot& rhs){
            os << "[Day: " << rhs.date << ", Start Time: " << rhs.dateNumber << rhs.dateNumberUnit <<"]";
            return os;
        };
    private:
        string date;
        int dateNumber;
        string dateNumberUnit;
    };
    
    
    vector<StudentRecord*> studentListPointer;
    TimeSlot sectionTimeSlot;
    
};



class LabWorker{
public:
    LabWorker(const string& workerName):name(workerName){};
    //   void addSection(const Section& newSection){
    void addSection(Section& newSection){
        section = &newSection;
//        *section = newSection;
    }
    
    void addGrade(const string& studentName, int grade, int time){
        // int* should not be doing here because it change the number and copy does not take many spaces
        section -> addGreade(studentName, grade, time);
    }
    
    friend ostream& operator<<(ostream& os, const LabWorker& rhs){
        if (rhs.section == nullptr){
            os << rhs.name << " does not have a section";
        }else{
            os << rhs.name << " has " << *rhs.section;
        }
        
        return os;
    };
private:
    string name;
    Section* section = nullptr;
};


// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {
    
    
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;
    
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;
    
    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;
    
    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
     secB3.addStudent("Kili");
     secB3.addStudent("Fili");
     secB3.addStudent("Dori");
     secB3.addStudent("Nori");
     secB3.addStudent("Ori");
     secB3.addStudent("Oin");
     secB3.addStudent("Gloin");
     secB3.addStudent("Bifur");
     secB3.addStudent("Bofur");
     secB3.addStudent("Bombur");
     jane.addSection( secB3 );
     cout << jane << endl;
    
    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;
    
    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;
    
    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
    << "those students (or rather their records?)\n";
    
    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
    << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";
    
} // main
