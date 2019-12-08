//
//  Course.cpp
//  rec07_2
//
//  Created by Zhengyi Li on 10/19/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//


#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly{
    
    ostream& operator<<(ostream& os, const Course& rhs){
        os << rhs.name<< " has students:" << endl;
        for(size_t i=0; i < rhs.students.size(); ++i){
            os << rhs.students[i] -> getName();
        }
        os << endl;
        return os;
    }
    
    Course::Course(const string& courseName):name(courseName){};
    const string& Course::getName() const{
        return name;
    };
    bool Course::addStudent(Student* oneStudent){
        bool check = true;
        for(size_t i = 0; i < students.size();i++){
            if (oneStudent == students[i]) {
                check = false;
            }
        }
        if (check == true){
            students.push_back(oneStudent);
            return true;
        }
        else{
            return false;
        }
        
    }
    
    bool Course::dropStudent(Student* oneStudent){
        size_t studentsP=-1;
        for(size_t i = 0; i< students.size(); i++){
            if(oneStudent == students[i]){
                students[i] -> removedFromCourse(this);
                studentsP = i;
            }
        }
        
        if(studentsP == -1){
            return false;
        }
        else{
            students[studentsP] = students.back();
            students.pop_back();
            return true;
        }
        
    }
    
    void Course::removeStudentsFromCourse(){
        for(size_t i = 0; i< students.size(); i++){
            students[i] -> removedFromCourse(this);
            // how to delet? or is it asking for deleting?
            
            // tell the stu
            
        }
        students.clear();
    }
}
