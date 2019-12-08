//
//  Student.cpp
//  rec07_2
//
//  Created by Zhengyi Li on 10/19/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include "Student.h"
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly{
    ostream& operator<<(ostream& os, const Student& rhs){
        os << rhs.name <<" has course:"<< endl;
        for(size_t i=0; i < rhs.courses.size(); ++i){
            os << rhs.courses[i] -> getName() << " ";
        }
        os << endl;
        return os;
    }
    
    Student::Student(const string& name):name(name){};
    const string& Student::getName() const{
        return name;
    }
    
    bool Student::addCourse(Course* oneCourse){
        for(size_t i = 0; i < courses.size(); ++i){
            if(oneCourse == courses[i]){
                return false;
            }
        }
        
        
        courses.push_back(oneCourse);
        return true;
    }
    
    void Student::changeName(const std::string& oneName){
        name = oneName;
    }
    
    void Student::removedFromCourse(Course* oneCourse){
        for(size_t i=0; i< courses.size(); i++){
            if(oneCourse == courses[i]){
                courses[i] = courses.back();
                courses.pop_back();
            }
        }
    }
}
