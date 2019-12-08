//
//  Student.h
//  rec07_2
//
//  Created by Zhengyi Li on 10/19/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly{
    class Course;
    
    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    public:
        // Student methods needed by Registrar
        Student(const std::string& name);
        const std::string& getName() const;
        bool addCourse(Course*);
        
        // Student method needed by Course
        void removedFromCourse(Course*);
        void changeName(const std::string& oneName);
        
    private:
        std::string name;
        std::vector<Course*> courses;
    };
};


#endif /* Student_h */

