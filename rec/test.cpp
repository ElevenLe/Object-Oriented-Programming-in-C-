
//
//  test.cpp
//  rec07_2
//
//  Created by Zhengyi Li on 10/19/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Registrar.h"
using namespace std;
using namespace BrooklynPoly;


int main(){
    ifstream ifs("transaction.txt");
    if (!ifs) {
        cerr << "File not opened" << endl;
        exit(1);
    }
    
    Registrar registrar;
    
    string command;
    while(ifs >> command){
        if(command == "PrintReport"){
            cout << registrar << endl;
        }else if (command == "AddCourse"){
            string courseName;
            ifs >> courseName;
            registrar.addCourse(courseName);
        }else if (command == "AddStudent"){
            string studentName;
            ifs >> studentName;
            registrar.addStudent(studentName);
        }else if (command == "EnrollStudentInCourse"){
            string studentName;
            string courseName;
            ifs >> studentName >> courseName;
            
            registrar.enrollStudentInCourse(studentName, courseName);
        }else if (command == "CancelCourse"){
            string courseName;
            ifs >> courseName;
            
            registrar.cancelCourse(courseName);
        }else if (command == "ChangeStudentName"){
            string firstName;
            string secondName;
            ifs >> firstName >> secondName;
            registrar.changeStudentName(firstName, secondName);
            
        }else if(command == "DropStudentFromCourse"){
            string courseName;
            string studentName;
            
            ifs >> studentName >> courseName;
            
            registrar.dropStudentFromCourse(studentName, courseName);
            
        }else if (command == "RemoveStudent"){
            string studentName;
            ifs >> studentName;
            registrar.removeStudent(studentName);
        }else if (command == "Purge"){
            registrar.purge();
        }
    }
}
