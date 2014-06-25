//
//  Implementations.cpp
//  SortingAStack
//
//  Created by DoganCan on 11/27/12.
//  Copyright (c) 2012 Dogan Can Dogan. All rights reserved.
//

#include "Header.h"

// check if stack is empty

bool Stack::isEmpty(){
    
    if(top == 0)
        return true;
    else
        return false;
    
}

// push the nodes into stack

void Stack::push(StudentRecord* record){
    
    
    record->next = top ;
    
    top = record ;
    
}

// pop from the stack

StudentRecord* Stack::pop(){
    
    if(top==0)
        return 0;
    else{
    
    StudentRecord *tempRecord = new StudentRecord;
    StudentRecord *topNode;
    
    topNode= top ;
    
    tempRecord->studentNo = topNode->studentNo;
    tempRecord->gpa = topNode->gpa;
    tempRecord->name = topNode->name;
    tempRecord->major = topNode->major ;
    tempRecord->next = 0;
    
    top = top->next ;
    
    delete topNode ;
    
    return tempRecord ;
    }
    
    
}





