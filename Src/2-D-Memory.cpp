#include <iostream>
#include <cstdio>   // or <stdio.h>
#include <cstring>  // or <string.h>
/* 
    Demostrate the usage of void type pointer and memor allocation
 */
int main(int argc, char* argv[])
{
    const int NUM=10;
    int i=0;
    int* ptr1 = NULL;

    ptr1=(int*)malloc(NUM*sizeof(int));
    if (ptr1==NULL)
    {
        exit(0);
    }
    else
    {
        //initialize the memory
        for(i=0;i<NUM;i++)
            // alternatively ptr1[i]=i;
            *(ptr1+i)=i;
        std::cout<< "ptr1 point to: "<< ptr1 << std::endl;
        std::cout<< "ptr1+NUM-1=: "<< *(ptr1+NUM-1) << std::endl;
    }
    
    /* 
    “calloc or contiguous allocation” method in C is used to dynamically allocate
    the specified number of blocks of memory of the specified type. 
    It initializes each block with a default value ‘0’.
    */
    char* ptr11 =(char*)calloc(NUM,sizeof(char));
    if (ptr11==NULL)
    {
        exit(0);
    }
    else
    {
        // calloc will automatically initialize the memory to 0
        std::cout<< "ptr11 point to: "<< ptr11 << std::endl;
        std::cout<< "ptr11+NUM-1=: "<< *(ptr11+NUM-1) << std::endl;
    }

    int* ptr2=NULL;
    ptr2= new(std::nothrow) int;
    if(ptr2==NULL)
    {
        std::cout<< "Memory allcocation failed."<< std::endl;
        exit(0);
    }
    else
        std::cout<< "ptr2 point to: "<< ptr2<< std::endl;

    int* ptr21=new(std::nothrow) int[NUM];
    if(ptr21==NULL)
        std::cout<< "Memory allcocation failed."<< std::endl;
    else
    {
        memcpy(ptr21,ptr1,NUM*sizeof(int));  //need include string.h
        std::cout<< "ptr21 point to: "<< ptr21<< std::endl;
        for(i=0;i<NUM;i++)
            std::cout<< "Element"<< ptr21[i]<< std::endl;
    }

    free(ptr1);
    free(ptr11);
    delete ptr2;
    delete[] ptr21;


    
    return 0;
}