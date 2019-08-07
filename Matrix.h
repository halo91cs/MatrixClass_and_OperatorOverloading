/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.h
 * Author: hale
 *
 * Created on February 9, 2019, 11:37 AM
 */

#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
typedef unsigned int uint;
typedef std::initializer_list<std::initializer_list<double>> i_list;
   

class Matrix {
    
    
    
public:
    
    /**
     * 
     * @param rows
     * @param cols
     */
    Matrix(uint rows, uint cols);// constructor (all elements initialized to 0) 
    
    /**
     * 
     * @param list
     */
    Matrix(const i_list & list); // constructor (using initializer list)
    
    /**
     * 
     * @param m
     */
    Matrix(const Matrix& m); // copy constructor
    
    /**
     * 
     */
    
    ~Matrix(); // destructor
    
    /**
     * 
     * @param s
     * @return 
     */
    Matrix add(double s) const; // add scalar to this matrix
    
    /**
     * 
     * @param m
     * @return 
     */
    Matrix add(const Matrix & m) const; // add this matrix and another matrix
    
    
    /**
     * 
     * @param s
     * @return 
     */
    Matrix subtract(double s) const; // subtract scalar from this matrix
    
    /**
     * 
     * @param m
     * @return 
     */
    
    Matrix subtract(const Matrix & m) const; // subtract another matrix from this matrix
    
    /**
     * 
     * @param s
     * @return 
     */
    Matrix multiply(double s) const; // multiply this matrix by a scaler
    
    /**
     * 
     * @param m
     * @return 
     */
    Matrix multiply(const Matrix & m) const; // multiply this matrix by another matrix
    
    /**
     * 
     * @param s
     * @return 
     */
    Matrix divide(double s) const; // divide this matrix by a scaler
    
    /**
     * 
     * @return 
     */
    Matrix t() const; // transpose of this matrix
    
    /**
     * 
     * @return 
     */
    const uint numRows() const {return _rows;} // returns the number of rows
    
    /**
     * 
     * @return 
     */
    const uint numCols() const {return _cols;} // returns the number of cols
    
    /**
     * 
     * @param row
     * @param col
     * @return 
     */
    double & at(uint row, uint col){return m[row][col];} // get/set element at row,col
    const double & at (uint row, uint col) const{return m[row][col];} // get element at row,col (when using a const object)
    
    /**
     * 
     * @param m
     */
    void display(Matrix & m); //displays matrix as expected format.
    
    /**
     * 
     * @param m
     * @return 
     */
    
    void operator=(const Matrix &m) const;
    
    /**
     * 
     * @param row
     * @param col
     * @return 
     */
    double & operator()(uint row, uint col) const;
    

    friend Matrix operator*(const double &number, const Matrix &m);
    friend Matrix operator*(const Matrix &m, const double &number);
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);
    
    friend Matrix operator/(const double &number, const Matrix &m);
    friend Matrix operator/(const Matrix &m, const double &number);
    
    friend Matrix operator+(const double &number, const Matrix &m);
    friend Matrix operator+(const Matrix &m, const double &number);
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    
    friend Matrix operator-(const double &number, const Matrix &m);
    friend Matrix operator-(const Matrix &m, const double &number);
    friend Matrix operator-(const Matrix &m1, const Matrix &m2);
    Matrix operator-();
    
    
    
private:
    uint _rows = 0;
    uint _cols = 0;
    double **m;
};

#endif /* MATRIX_H */

