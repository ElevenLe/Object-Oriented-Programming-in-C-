//
//  Registrar.cpp
//  rec07_2
//
//  Created by Zhengyi Li on 10/19/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <stdio.h>
#include "Course.h"
#include "Student.h"
#include "Registrar.h"
#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly{
    ostream& operator<<(ostream& os, const Registrar& rhs){
        os << "this registrar has "  << endl;
        for(size_t i=0; i < rhs.courses.size(); ++i){
            os << *rhs.courses[i];
        }
        for(size_t j = 0; j < rhs.students.size(); ++j){
            os<< *rhs.students[j];
        }
        os << endl;
        return os;
    }
    
    Registrar::Registrar(){};
    
    bool Registrar::addCourse(const string& courseName){
        for(size_t i =0; i < courses.size(); ++i){
            if(courses[i] ->getName() ==  courseName){
                return false;
            }
        }
        // need to check what?
        courses.push_back(new Course(courseName));
        return true;
    }
    
    bool Registrar::addStudent(const string& studentName){
        // need to check the name
        for(size_t i =0; i < students.size(); ++i){
            if(students[i] ->getName() ==  studentName){
                return false;
            }
        }
        students.push_back(new Student(studentName));
        return true;
    }
    
    size_t Registrar::findStudent(const string& studentName) const{
        for(size_t i =0; i < students.size(); i++){
            if(students[i] -> getName() == studentName){
                return i;
            }
        }
        return students.size();
    }
    
    size_t Registrar::findCourse(const string& courseName) const{
        for(size_t j = 0; j < courses.size(); j++){
            if(courses[j] -> getName() == courseName){
                return j;
            }
        }
        return courses.size();
    }
    
    bool Registrar::enrollStudentInCourse(const string& studentName,const string& courseName){
        size_t studentPosition = findStudent(studentName);
        size_t coursePosition = findCourse(courseName);
        
        if(studentPosition == students.size() || coursePosition == courses.size()){
            return false;
        }
        else if(studentPosition == students.size() && coursePosition == courses.size()){
            return false;
        }
        else{
            students[studentPosition] -> addCourse(courses[coursePosition]);
            courses[coursePosition] -> addStudent(students[studentPosition]);
            return true;
        }
    }
    
    
    bool Registrar::changeStudentName(const std::string& studentName, const std::string& changeStudentName){
        size_t studentPosition = findStudent(studentName);
        
        if (studentPosition == students.size()){
            return false;
        }else
        {
            students[studentPosition] -> changeName(changeStudentName);
            return true;
        }
    }
    
    
    bool Registrar::dropStudentFromCourse(const std::string& studentName, const std::string& courseName){
        size_t studentPosition = findStudent(studentName);
        size_t coursePosition = findCourse(courseName);
        
        if(studentPosition == students.size() || coursePosition == courses.size()){
            return false;
        }else{
            courses[coursePosition] -> dropStudent(students[studentPosition]);
            return true;
        }
    }
    
    
    bool Registrar::removeStudent(const std::string& studentName){
        size_t studentPosition = findStudent(studentName);
        if (studentPosition == students.size()){
            return false;
        }else{
            delete students[studentPosition];
            students[studentPosition] = nullptr;
            
            students[studentPosition] = students.back();
            students.pop_back();
            return true;
        }
    }
    
    bool Registrar::cancelCourse(const string& courseName){
        for(size_t i =0; i < courses.size(); i ++){
            if(courses[i]->getName() == courseName){
                // this here delete the course from heap or delet the address?
                courses[i] -> removeStudentsFromCourse();
                
                delete courses[i];
                courses[i] = nullptr;
                
                courses[i] = courses.back();
                courses.pop_back();
                return true;
            }
        }
        return false;
    }
    
    void Registrar::purge(){
        // deleting all in the heap?
        for(size_t i = 0; i < courses.size() ;++i){
            delete courses[i];
            courses[i] = nullptr;
        }
        courses.clear();
        for (size_t j = 0; j < students.size() ; ++j){
            delete students[j];
            students[j] = nullptr;
        }
        students.clear();
    }
}
