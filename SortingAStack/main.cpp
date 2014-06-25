//
//  main.cpp
//  SortingAStack
//
//  Created by DoganCan on 11/22/12.
//  Copyright (c) 2012 Dogan Can Dogan. All rights reserved.
//

#include "Header.h"

int main(int argc, const char * argv[])
{
    // I will use main stack to store the records and tempStack to sort,
    
    Stack mainStack, tempStack ;
    
    // I am using records with the point gpa (e.g 3.80),
    // So I can read and parse all variables with respect to their types
    
    ifstream infile("/Users/DoganCan/Desktop/records2.txt");
    
    string name, major ;
    int no ;
    float gpa;
    
    //read records from the file and assign them to temporary variables
    //and create a new node with those variables
    
    while (infile >> no >> name >> gpa >> major ) {
        
        StudentRecord* newRecord = new StudentRecord ;
        newRecord->studentNo = no ;
        newRecord->name = name ;
        newRecord->major = major;
        newRecord->gpa = gpa ;
        
        //if stack is empty or new records comes to the top push directly,
        
        if(mainStack.isEmpty() or gpa > mainStack.top->gpa)
            mainStack.push(newRecord);
        
        // else sort the stack until record finds its place
        // if gpa's are equal compare student numbers
        // so student with greater number comes first, in case of equal gpa's
        
        else if(gpa < mainStack.top->gpa ){
                do {
                    tempStack.push(mainStack.pop());
                    if(mainStack.top == 0)
                        break;
                }while (gpa < mainStack.top->gpa );
                
                mainStack.push(newRecord);
                
                while (tempStack.top != 0) {
                    mainStack.push(tempStack.pop());
                }
            
            if(no > mainStack.top->studentNo)
                mainStack.push(newRecord);
            else{
                do {
                    tempStack.push(mainStack.pop());
                }while (no < mainStack.top->studentNo );
                
                mainStack.push(newRecord);
                
                while (tempStack.top != 0) {
                    mainStack.push(tempStack.pop());
                }
                
            }

        
        
        }
        else{
            
        
            if(no > mainStack.top->studentNo)
                mainStack.push(newRecord);
            else{
                do {

                    tempStack.push(mainStack.pop());
                    
                    if(mainStack.top == 0)
                        break;
                    
                }while (no < mainStack.top->studentNo );
                
                mainStack.push(newRecord);
                
                while (tempStack.top != 0) {
                    mainStack.push(tempStack.pop());
                }
                
                }
            
            
            }
    
    }
    /*
    do{
        
        cout<<mainStack.top->studentNo<<"\t"<<mainStack.top->name<<"\t"<<mainStack.top->gpa<<"\t"<<mainStack.top->major<<"\t"<<endl;
     
        mainStack.top = mainStack.top->next ;
    }while (mainStack.top!=0);
      */
    // write sorted stack to the file
    
    ofstream outfile("/Users/DoganCan/Desktop/SortedRecords.txt");
   
    StudentRecord* traverse = mainStack.top;
    
    // traverse the stack for writing to the file
    
    while (traverse!=0){
        
        outfile<<traverse->studentNo<<"\t"<<traverse->name<<"\t"<<traverse->gpa<<"\t"<<traverse->major<<endl;
        
        traverse = traverse->next ;
        
    }

    infile.close() ;

    outfile.close();
         
    
    return 0;
}

