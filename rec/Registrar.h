//
//  Registrar.h
//  rec07_2
//
//  Created by Zhengyi Li on 10/19/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//



#include <iostream>
#include <string>
#include <vector>

#ifndef Registrar_h
#define Registrar_h

namespace BrooklynPoly{
    class Course;
    class Student;
    
    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
    public:
        Registrar();
        bool addCourse(const std::string&);
        bool addStudent(const std::string&);
        bool enrollStudentInCourse(const std::string& studentName,
                                   const std::string& courseName);
        bool changeStudentName(const std::string& studentName, const std::string& changeStudentName);
        bool dropStudentFromCourse(const std::string& studentName, const std::string& courseName);
        bool removeStudent(const std::string& studentName);
        bool cancelCourse(const std::string& courseName);
        void purge();
        
    private:
        size_t findStudent(const std::string&) const;
        size_t findCourse(const std::string&) const;
        
        std::vector<Course*> courses;
        std::vector<Student*> students;
    };
}

#endif /* Registrar_h */
