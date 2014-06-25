//
//  Header.h
//  SortingAStack
//
//  Created by DoganCan on 11/22/12.
//  Copyright (c) 2012 Dogan Can Dogan. All rights reserved.
//

#ifndef SortingAStack_Header_h
#define SortingAStack_Header_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

// Student record node

struct StudentRecord {
    
    int studentNo ;
    string name, major ;
    float gpa ;
    
    StudentRecord *next ;

};


struct Stack {
    
    StudentRecord *top ;
        
    void push(StudentRecord* record);
    
    StudentRecord* pop();
    
    bool isEmpty();
    
};



#endif
