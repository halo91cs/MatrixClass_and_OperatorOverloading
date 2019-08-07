/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hale
 *
 * Created on February 9, 2019, 11:37 AM
 */

#include <cstdlib>
#include <iostream>
#include "Matrix.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Matrix a(3, 3);
    
    a.at(0, 0) = 1;
    a.at(0, 1) = 2;
    a.at(0, 2) = 3;
    a.at(1, 0) = 4;
    a.at(1, 1) = 5;
    a.at(1, 2) = 6;
    a.at(2, 0) = 7;
    a.at(2, 1) = 8;
    a.at(2, 2) = 9;
    
    cout << "===================" << endl;
    cout << "Matrix a is created" << endl;
    cout << "===================\n" << endl;
    a.display(a);
    
    Matrix b(2, 1);
    b.at(0, 0) = 3;
    b.at(1, 0) = 2;
    
    cout << "===================" << endl;
    cout << "Matrix b is created" << endl;
    cout << "===================\n" << endl;
    b.display(b);
    
    Matrix c = {{1, 2},{3, 4}};
    cout << "==============================================" << endl;
    cout << "Matrix c is created with an initializer list: " << endl;
    cout << "==============================================\n" << endl;
    c.display(c);
    
    
    cout << "===================================" << endl;
    cout << "Overloaded function call operator: " << endl;
    cout << "Matrix f is created." << endl;
    cout << "===================================\n" << endl;
    Matrix f(2, 2);
    f(0, 0) = 5; 
    f(0, 1) = 5;
    f(1, 0) = 5;
    f(1, 1) = 5;    
    f.display(f);
    
    cout << "=====================================" << endl;
    cout << "Overloaded copy assignment operator: " << endl;
    cout << "Matrix f is copied to matrix g." << endl;
    cout << "=====================================\n" << endl;

    Matrix g(2, 2);    
    g = f; // copy assignment    
    g.display(g);
    
    cout << "======================================================" << endl;
    cout << "OVERLOADED NON-MEMBER ARITHMETIC OPERATORS FOR SCALARS" << endl;
    cout << "======================================================\n" << endl;

    cout << "Matrix c is: " << endl;
    c.display(c);
    cout << "Overloaded non-member arithmetic scalar addition (4 + Matrix c)\n" << endl;
    Matrix add = 4.0 + c;
    add.display(add);
    
    cout << "Overloaded non-member arithmetic scalar subtraction (4 - Matrix c)\n" << endl;
    Matrix sub = 4 - c;
    sub.display(sub);
    
    cout << "Overloaded non-member arithmetic scalar multiplication (2 * Matrix c)\n" << endl;
    Matrix mul = 2 * c;
    mul.display(mul);
    
    cout << "Overloaded non-member arithmetic scalar division (12 / Matrix c)\n" << endl;
    Matrix div = 12 / c;
    div.display(div);
    
    cout << "Overloaded Unary Minus Operator (-Matrix c)\n" << endl;
    Matrix neg = -c;
    neg.display(neg);
    
    cout << "=======================================" << endl;
    cout << "MEMBER ARITHMETIC OPERATORS FOR SCALARS" << endl;
    cout << "=======================================\n" << endl;
    
    Matrix a1{{4, 6},{12, 5}};
    cout << "=====================" << endl;
    cout << "Matrix a1 is created." << endl;
    cout << "=====================\n" << endl;
    a1.display(a1);
    
    Matrix b1{{1, 2},{3, 5}};    
    cout << "=====================" << endl;
    cout << "Matrix b1 is created." << endl;
    cout << "=====================\n" << endl;
    
    
    b1.display(b1);
    
    cout << "======================" << endl;
    
    cout << "Adding scalar to a matrix (a1 + 2)\n" << endl;
    Matrix a11 = a1.add(2);
    a11.display(a11);
    
    cout << "==================================\n" << endl;
    
    cout << "Adding matrix to another matrix (a1 + b1)" << endl;    
    Matrix a1b1 = a1.add(b1);
    a1b1.display(a1b1);
    
    cout << "=======================================\n" << endl;
    
    cout << "Subtracting a scalar from a matrix (a1 - 2)" << endl;    
    Matrix a22 = a1.subtract(2);
    a22.display(a22);
    
    cout << "=======================================\n" << endl;

    
    cout << "Subtracting a matrix from another matrix (a1 - b1)" << endl;
    Matrix a2b2 = a1.subtract(b1);
    a2b2.display(a2b2);
    
    cout << "==================================================\n" << endl;

    
    cout << "Multiplying a matrix with a scalar (a1 * 2)" << endl;
    Matrix a33 = a1.multiply(2);
    a33.display(a33);
    
    cout << "===========================================\n" << endl;

    
    cout << "Multiplying a matrix with another matrix (a1 * b1)" << endl;
    Matrix a44 = a1.multiply(b1);
    a44.display(a44);
    
    cout << "===========================================\n" << endl;
    
    cout << "Dividing a matrix by a scalar (a1 / 2)" << endl;
    Matrix a55 = a1.divide(2);
    a55.display(a55);
    
    cout << "===========================================\n" << endl;
    
    cout << "Transpose of a1" << endl;
    Matrix a66 = a1.t();
    a66.display(a66);
    
    //m1 * n1
    /*cout << "m1 * n1" << endl;
    Matrix m1(2, 2);
    m1.at(0, 0) = 1; // [ 1, 2 ]
    m1.at(0, 1) = 2; // [ 1, 3 ]
    m1.at(1, 0) = 1;
    m1.at(1, 1) = 3;
    Matrix n1(2, 1);
    n1.at(0, 0) = 3; // [ 3 ]
    n1.at(1, 0) = 2; // [ 2 ]
    
    Matrix k = m1.multiply(n1);
    cout << "[ " << k.at(0, 0) << " ]" << endl // [ 7 ]
         << "[ " << k.at(1, 0) << " ]" << endl; // [ 9 ] */
     
   // k.display(k);

   // Matrix a1{{4, 6},{12, 5}};
    //Matrix b1{{1, 2},{3, 5}};
    
    cout << "================================" << endl;
    cout << "EXAMPLES IN THE PROJECT DOCUMENT" << endl;
    cout << "================================\n" << endl;
        
    cout << "Matrix c0 = 5.2 + a1" << endl;
    
    Matrix c0 = 5.2 + a1;
    c0.display(c0);
    
    cout << "\nMatrix c1 = a1 + a1" << endl;
    
    Matrix c1 = a1 + a1; // NOTE: these examples actually end up calling the copy constructor
    c1.display(c1);
    
    cout << "\nMatrix c2 = 3.5 - a1" << endl;
    
    Matrix c2 = 3.5 - a1; // e.g., this line is the same as Matrix c2(a - 3.5);
    c2.display(c2);
    
    cout << "\nMatrix c3 = b1 - b1" << endl;
    
    Matrix c3 = b1 - b1;
    c3.display(c3);
    
    cout << "\nMatrix c4 = 2.1 * a1" << endl;
    
    Matrix c4 = 2.1 * a1;
    c4.display(c4);
    
    cout << "\nMatrix c5 = a1 * b1" << endl;
    
    Matrix c5 = a1 * b1;
    c5.display(c5);
    
    cout << "\nMatrix c6 = 2.0 / a1" << endl;
    
    Matrix c6 = 2.0 / a1;
    c6.display(c6);
    
    return 0;
}

