//
//  Rec04.cpp
//  Rec04
//
//  Created by Zhengyi Li on 9/28/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Complex{
    double real;
    double img;
};


class PlainOldClass{
public:
    PlainOldClass() : x(-72){}
    int getX() const {
        return x;
    }
    //void setX(int x){ x = x;} // this will give x to this.x;
    void setX(int x){ this->x = x;};
    //Before adding the dereferencing of parameter this, you were assigning the parameter x to itself.
    
private:
    int x;
};


class Colour{
public:
    Colour(const string& name, unsigned r, unsigned g, unsigned b): name(name), r(r), g(g), b(b){}
    
    void display() const{
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    };
    
private:
    string name;// what we call this colour
    unsigned r, g, b;// red/green/blue values for displaying
};

class SpeakerSystem {
public:
    void vibrateSpeakerCones(unsigned signal) const {
        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Amplifier {
public:
    void attachSpeakers(const SpeakerSystem& spkrs)
    {
        if(attachedSpeakers){
            cout << "already have speakers attached!\n";}
        else{
            attachedSpeakers = &spkrs;}
    }
    
    void detachSpeakers() { // should there be an "error" message if not attached?
        attachedSpeakers = nullptr;
    }
    
    void playMusic( ) const {
        if (attachedSpeakers)
            attachedSpeakers -> vibrateSpeakerCones(440);
        else
            cout << "No speakers attached\n";
    }
private:
    const SpeakerSystem* attachedSpeakers = nullptr;
};


class Person {
public:
    Person(const string& name) : name(name) {}
    void movesInWith(Person& newRoomate) {
        if(&newRoomate == this){
            cout << "you cannot move in with yourself";
        }else{
            if(roomie != nullptr){
                cout << name << " already have roomie";
            }else if(newRoomate.roomie != nullptr){
                cout << newRoomate.name<< " already have roomie";
            }
            else{
                roomie = &newRoomate;// now I have a new roomie
                newRoomate.roomie = this;
                
            }
        }
        
        
        //newRoomate.roomie = this;    // and now they do too
    }
    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string& getRoomiesName() const { return roomie->getName(); }
    
    
private:
    Person* roomie = nullptr;
    string name;
};


int main(){
    int x;
    x = 10;
    cout << "x = " << x << endl;
//    cout << 0xA;
//    cout << 0xB;
//    cout << hex << 0xB;
//    cout << dec << 0xB;
    
    int* p;
    p = &x;
    cout << "p = " << p << endl;
//    this 0x0012fed4 will be recognized as a int most likely.
//    ask how to casting an integral value to a pointer to an int
//    int -> int* or int* -> int?????
//    p = 0x0012fed4;
    
//    int* p;
    // it's very clear that the * is part of the type's name - the type is "pointer to int"
    // PREFERRED
//    int *p;
    // it looks the * is part of the variable name but the compiler reads it as above
//    int * p;
    // it looks more like multiplication but the compiler again reads it as above
    // (probably NOT a good idea to use)
//    int* p1, p2, *p3;   // This is compile-able code but's it's VERY unclear as the type of p2.
    // Since the * is part of the type's name, it's clear that p1 is an int*; and it's pretty clear that
    //  p3 is an int* but notice that it looks like p2 is also an int* - but it's not!
    // (definitely NOT a good idea to mix int and int* definitions
    
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    // the expression *p is the dereference operator applied to the variable p.
    
    *p = -2763;
    cout << "p points to where  " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    
    int y(13);
    cout << "y contains "<< y << endl;
    p = &y;
    cout << " p now points to where " << *p << "is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << " *p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    
    int* q;
    q = p;
    cout << "q points to where " << *q << "is stored\n";
    cout << "*q contains " << *q << endl;
    
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p = *pD;
    *q = *p;
    //pD = p;
    //p = pD;
    
    int joe = 24;
    const int sal = 19;
    int*  pI;
    pI = &joe;
    *pI = 234;
//    pI = &sal; // int* ->! const int*
    *pI = 7623;
    
    const int* pcI;
    pcI = &joe; // const int* -> int*
//    *pcI = 234; // const int* pcI cannot be changed, readable only;
    pcI = &sal; // const int* -> conts int*
    
    // different between const int* and int* const is that const int* can repointing but cannot change the value, but int* const can change the value but cannot reassign or repointing to new address.
    
//    *pcI = 7623; // readable only
    
//    int* const cpI; // must have initialization for int* const type;
    int* const cpI(&joe); // int* const -> int*
//    int* const cpI(&sal); // int* const unable to redefine bc it is const
    // int* const ->! const int*
//    cpI = &joe; // not reassgin
    *cpI = 234;
    //cpI = &sal;
    *cpI = 7623;
    
    const int* const cpcI = &joe; // must have initialization, same as int* const type
    //const int* const cpcI(&joe); // const int* const -> int*
    //const int* const cpcI(&sal); // not initialization
    //cpcI = &joe;  //*cpcI = 234; // not both repointing or changing the value
    //cpcI = &sal;
    // *cpcI = 7623;
    
    //TYPE* variableName, can hold a pointer to TYPE value
    
    
    Complex c = {11.23, 45.67};
    Complex* pC(&c);
//    cout << "real: " << *pC.real << "\nimaginarty:" << *pC.img << endl;
    cout << "real: " << (*pC).real << "\nimaginarty:" << (*pC).img << endl; // too old, not write agian.
    //  pC ->real : dereferencer operator for pointer to struct or class
    // -> only works for pointing to struct or class
    cout << "real: " << pC -> real << "\nimaginarty: " << pC -> img << endl;
    
    PlainOldClass poc;
    PlainOldClass* ppoc(&poc);
    cout << ppoc -> getX() << endl;
    ppoc -> setX(2873);
    cout << ppoc -> getX() << endl;
    
    
    //now we are getting the freeee store in the RAM( random access momory). To get one piece from heap, one area in momory, use new!!!
    // new yields a pointer value -> to heap memory
    // initializaiton must use ()
    
    int* pDyn = new int(3);// p points to an int initialzed to 3 on the heap
    *pDyn = 17;
    
    cout << "The " << *pDyn << " is stored at address " << pDyn << " which is in the heap\n";
    cout << pDyn << endl;
    delete pDyn;
    
    cout << pDyn << endl;
    
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    pDyn = nullptr;
    
    
    double* pDouble = nullptr; // when pointing to nullptr, the access will be bad
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    double* pTest = new double(12);
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe
    
    short* pShrt = new short(5);
    delete pShrt;
    //delete pShrt;
    
    long jumper = 12238743;
    //delete jumper;
    long* ptrTolong = &jumper;
    //delete ptrTolong;
    Complex cmplx;
    //delete cmplx;
    
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        delete complV[ndx];
    }
    // clear the vector
    complV.clear();
    
    
    vector<Colour*> colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));
    }
    
    // display all the Colours in the vector:

    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        colours[ndx]->display();
        cout << endl;
    }
    
    
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane"), cancy("cancy");
    
    // now model these two becoming roommates
    joeBob.movesInWith(billyJane);
    
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    joeBob.movesInWith(joeBob);
    joeBob.movesInWith(cancy);
}


