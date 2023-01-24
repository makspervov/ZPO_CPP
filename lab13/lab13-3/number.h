#ifndef NUMBER_H
#define NUMBER_H
#include<iostream>

double reverse(double n){
    if(n==0)
        throw std::runtime_error("Podano 0");
    return n*-1;
}

#endif // NUMBER_H
