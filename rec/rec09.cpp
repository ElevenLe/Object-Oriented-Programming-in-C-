//
//  rec09.cpp
//  rec09
//
//  Created by Zhengyi Li on 11/2/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial( unsigned numPages ): numOfPages(numPages){}
    virtual void displayNumPages() const =0;
protected:
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const{
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine( unsigned numPages ): PrintedMaterial(numPages){}
    void displayNumPages() const{
        cout << "magazine" <<endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book( unsigned numPages ): PrintedMaterial(numPages){}
    void displayNumPages() const{
        cout << "book : " <<endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class TextBook : public Book {
public:
    TextBook( unsigned numPages, unsigned numIndxPgs  )
    : Book(numPages),
    numOfIndexPages(numIndxPgs)
    {}
    void displayNumPages() const
    {
        
        cout << "index :"<< numOfIndexPages << endl;
        cout << " pages :";
        PrintedMaterial::displayNumPages();
    }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel( unsigned numPages ): Book(numPages){}
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& pm){
    pm.displayNumPages();
}

// tester/modeler code
int main()
{
    TextBook t(5430, 234);
    Novel n(213);
    Magazine m(6);
    
//    t.displayNumPages();
//    n.displayNumPages();
//    m.displayNumPages();
    
    
//    PrintedMaterial pm = t;
//    pm.displayNumPages();
    // slicing problem
    // lost part of t. t is include the pm, and only assgin the pm part to pm.
//
//    PrintedMaterial pm2(908);
//    pm2.displayNumPages();
//    pm2 = t;
//    pm2.displayNumPages();
    
//    PrintedMaterial* pmPtr;
//    pmPtr = &t;
//    pmPtr -> displayNumPages();
//    vector<PrintedMaterial> materials;
//    materials.push_back(t);
//    materials.push_back(n);
//    materials.push_back(m);
//    displayNumberOfPages(t);
//    displayNumberOfPages(n);
//    displayNumberOfPages(m);
    vector<PrintedMaterial*> materials;
    materials.push_back(&t);
    materials.push_back(&n);
    materials.push_back(&m);
    
    for(int i =0 ;i < materials.size(); i++){
        materials[i] -> displayNumPages();
    }
}
