/*
  rec07 
  Starter Code for required functionality
  Yes, you may add other methods.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;


class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student* oneStudent);
    void removeStudentsFromCourse(); 

private:
    string name;
    vector<Student*> students;
};



class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);

    // Student method needed by Course
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
};


class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string&);
    bool addStudent(const string&);
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
};




int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;

    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  // or registrar.printReport()

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  // or registrar.printReport()

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  // or registrar.printReport()
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}
  

ostream& operator<<(ostream& os, const Course& rhs){
    os << rhs.name<< " has students:" << endl;
    for(int i=0; i < rhs.students.size(); ++i){
        os << rhs.students[i] -> getName();
    }
    os << endl;
    return os;
}
ostream& operator<<(ostream& os, const Student& rhs){
    os << rhs.name <<" has course:"<< endl;
    for(int i=0; i < rhs.courses.size(); ++i){
        os << rhs.courses[i] -> getName() << " ";
    }
     os << endl;
    return os;
};
ostream& operator<<(ostream& os, const Registrar& rhs){
    os << "this registrar has "  << endl;
    for(int i=0; i < rhs.courses.size(); ++i){
        os << *rhs.courses[i];
    }
    for(int j = 0; j < rhs.students.size(); ++j){
        os<< *rhs.students[j];
    }
     os << endl;
    return os;
};

Course::Course(const string& courseName):name(courseName){};
const string& Course::getName() const{
    return name;
};
bool Course::addStudent(Student* oneStudent){
    bool check = true;
    for(int i = 0; i < students.size();i++){
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
    
};
void Course::removeStudentsFromCourse(){
    for(int i = 0; i< students.size(); i++){
        students[i] -> removedFromCourse(this);
        // how to delet? or is it asking for deleting?
        
        // tell the stu
        
    }
    students.clear();
}

Student::Student(const string& name):name(name){};
const string& Student::getName() const{
    return name;
};
bool Student::addCourse(Course* oneCourse){
    for(int i = 0; i < courses.size(); ++i){
        if(oneCourse == courses[i]){
            return false;
        }
    }
    
    
    courses.push_back(oneCourse);
    return true;
};

void Student::removedFromCourse(Course* oneCourse){
    for(size_t i=0; i< courses.size(); i++){
        if(oneCourse == courses[i]){
            courses[i] = courses.back();
            courses.pop_back();
        }
    }
}

//  unsigned (2) < signed (-1) --> 45658495

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
};
bool Registrar::addStudent(const string& studentName){
    // need to check the name
    for(size_t i =0; i < students.size(); ++i){
        if(students[i] ->getName() ==  studentName){
            return false;
        }
    }
    students.push_back(new Student(studentName));
    return true;
};

size_t Registrar::findStudent(const string& studentName) const{
    for(int i =0; i < students.size(); i++){
        if(students[i] -> getName() == studentName){
            return i;
        };
    }
    return students.size();
};

size_t Registrar::findCourse(const string& courseName) const{
    for(int j = 0; j < courses.size(); j++){
        if(courses[j] -> getName() == courseName){
             return j;
        };
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
    
};
bool Registrar::cancelCourse(const string& courseName){
    for(int i =0; i < courses.size(); i ++){
        if(courses[i]->getName() == courseName){
            // this here delete the course from heap or delet the address?
            courses[i] -> removeStudentsFromCourse();
            
            delete courses[i];
            courses[i] = nullptr;
            
            courses[i] = courses.back();
            courses.pop_back();
            return true;
        };
    }
    
    return false;
};
void Registrar::purge(){
    // deleting all in the heap?
    for(int i = 0; i < courses.size() ;++i){
        delete courses[i];
        courses[i] = nullptr;
    }
    courses.clear();
    for (int j = 0; j < students.size() ; ++j){
        delete students[j];
        students[j] = nullptr;
    }
    students.clear();
};
