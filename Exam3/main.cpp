//
//  main.cpp
//  Exam3
//
//  Created by Charles Plater on 12/9/18.
//  Copyright © 2018 Charles Plater. All rights reserved.
//

#include <iostream>
#include <tgmath.h>
#include <math.h>

double E (int x, int x2, int x3) {
    double retval1 = ((pow(x,3) + pow(x2,4) + pow(x3,6)) - 263467);
    double retval2 = ((pow(x2,4) + (x*x3*pow(x2,2)) + pow(x,5)) - 2403);
    double retval3 = ((pow(x,6) + (pow(x2,2) * pow(x3,3) * pow(x,4)) + (pow(x2,3) * pow(x3,5))) - 8571609);
    double returnValue = ( pow(retval1,2) + pow(retval2,2) + pow(retval3,2));
//    double returnValue = retval1 + retval2 + retval3;
    return returnValue;
}

void bruteForce() {
    for (int y1 = 0; y1 < 10; y1++) {
        for (int y2 = 0 ; y2 < 10; y2++) {
            for (int y3 = 0; y3 < 10; y3++) {
                
                if (E(y1,y2,y3) == 0) {
                    std::cout << "Solution Found (via brute force):\n";
                    std::cout << y1;
                    std::cout << " ";
                    std::cout << y2;
                    std::cout << " ";
                    std::cout << y3;
                    std::cout << " ";
                    std::cout << "\n";
                }
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {

    int x1 = arc4random_uniform(9);
    int x2 = arc4random_uniform(9);
    int x3 = arc4random_uniform(9);

    int accepted1, accepted2, accepted3;

    for (int temp = 100; temp > 9; temp -= 10){

        double result1 = E(x1, x2, x3);

        for (int x = 0; x < 50 ; x++) {
            int x4 = arc4random_uniform(9);
            while (x1 == x4) {
                x4 = arc4random_uniform(9);
            }
            int x5 = arc4random_uniform(9);
            while (x2 == x5) {
                x5 = arc4random_uniform(9);
            }
            int x6 = arc4random_uniform(9);
            while (x3 == x6) {
                x6 = arc4random_uniform(9);
            }
            
            double result2 = E(x4,x5,x6);

            float p = exp(-(result1 - result2)/temp);

            if (p>1) {
                accepted1 = x4;
                accepted2 = x5;
                accepted3 = x6;
            } else {
                
                int x7 = arc4random_uniform(9);
                while ((x1==x7) || (x4!=x7)){
                    x7 = arc4random_uniform(9);
                }
                x4 = x7;
                int x8 = arc4random_uniform(9);
                while ((x2==x8) || (x5!=x8)){
                    x8 = arc4random_uniform(9);
                }
                x5 = x8;
                int x9 = arc4random_uniform(9);
                while ((x3==x9) || (x6!=x9)){
                    x9 = arc4random_uniform(9);
                }
                x6 = x9;
            }
        }
        std::cout << accepted1;
        std::cout << " ";
        std::cout << accepted2;
        std::cout << " ";
        std::cout << accepted3;
        std::cout << " accepted at temp ";
        std::cout << temp;
        std::cout << "\n";
    }
    
    bruteForce();
    
    return 0;
}
