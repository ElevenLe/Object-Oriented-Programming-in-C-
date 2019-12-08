//
//  Course.h
//  rec07_2
//
//  Created by Zhengyi Li on 10/19/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//



#ifndef Course_h
#define Course_h

#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly{
    class Student;
    
    class Course {
        friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
    public:
        // Course methods needed by Registrar
        Course(const std::string& courseName);
        const std::string& getName() const;
        bool addStudent(Student* oneStudent);
        void removeStudentsFromCourse();
        bool dropStudent(Student* oneStudent);
        
    private:
        std::string name;
        std::vector<Student*> students;
    };
}
#endif /* Course_h */
