/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.cpp
 * Author: hale
 * 
 * Created on February 9, 2019, 11:37 AM
 */

#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

/**
 * 
 * @param rows
 * @param cols
 */
Matrix::Matrix(uint rows, uint cols) 
{
    _rows = rows;
    _cols = cols;
    m = new double*[rows];
    for (int i=0; i<rows; i++)
    {
        m[i] = new double[cols];        //initialize empty columns
    }

    for (int i=0; i<rows; i++){
	for (int j=0; j<cols; j++){
            m[i][j] = 0;            //fills empty matrix with 0 vales
	}
    }
}

/**
 * 
 * @param list
 */
Matrix::Matrix(const i_list & list)
{
    
    _rows=list.size();
    _cols=list.begin()->size();

    auto iterator = list.begin();
    
    m = new double*[_rows];       
    
    int i = 0;
    for(iterator = list.begin(); iterator != list.end(); iterator++, i++)
    {
        m[i] = new double[_cols];
        std::copy(iterator->begin(), iterator->end(), m[i]);
    }
    

 }


/**
 * Initializes the copy constructor
 * 
 * @param mat
 */
Matrix::Matrix(const Matrix &mat){
	
    _rows = mat._rows;
    _cols = mat._cols;
    m = new double*[mat._rows];
    for (int i=0; i < mat._rows; i++)
    {
        m[i] = new double[mat._cols];
    }
    
    for (int i=0; i < mat._rows; i++)
    {
        for (int j=0; j < mat._cols; j++)
        {
            m[i][j] = (mat.m)[i][j];
        }
    }
}

/**
 * Destructor
 */
Matrix::~Matrix() {
    for (int i=0; i<_rows; i++)
    {
        delete[] m[i]; //delete columns
    }
    delete[] m; //delete rows	
    
}

/**
 * 
 * @param m
 */
void Matrix::display(Matrix & m)
{
    
    for (int i=0; i< m.numRows(); i++)
    {
        cout << "[";
	for (int j=0; j< m.numCols(); j++)
        {
            if(j!=m.numCols()-1)
                cout << m.at(i, j) << ",";
            else
                cout << m.at(i, j);
	}
        cout << "]\n";
    }
}

Matrix Matrix::add(double s) const
{
    Matrix newMatrix(_rows, _cols);
    for(int i=0; i < _rows; i++)
    {
        for(int j=0; j < _cols; j++)
        {
            newMatrix.m[i][j] += s + m[i][j];        
        }
    }
    return newMatrix;
}

Matrix Matrix::add(const Matrix & m) const
{
    Matrix newMatrix(_rows, _cols);
    for(int i=0; i < _rows; i++)
    {
        for(int j=0; j < _cols; j++)
        {
            newMatrix.m[i][j] += m.m[i][j] + this->m[i][j];        
        }    
    }
    return newMatrix;
}

Matrix Matrix::subtract(double s) const
{
    Matrix newMatrix(_rows, _cols);
    for(int i=0; i < _rows; i++)
    {
        for(int j=0; j < _cols; j++)
        {
            newMatrix.m[i][j] += m[i][j] - s;        
        }    
    }
    return newMatrix;
}

Matrix Matrix::subtract(const Matrix & m) const
{
    Matrix newMatrix(_rows, _cols);
    for(int i=0; i < _rows; i++)
    {
        for(int j=0; j < _cols; j++)
        {
            newMatrix.m[i][j] += this->m[i][j] - m.m[i][j];        
        }
    }
    return newMatrix;
}

Matrix Matrix::multiply(double s) const
{
    Matrix newMatrix(_rows, _cols);
    for (int i=0; i < _rows; i++)
    {  //i = rows
        for (int j=0; j < _cols; j++)
        {  //j = cols
            
            newMatrix.m[i][j] += s * m[i][j];
            
        }
    }
    return newMatrix;
}

Matrix Matrix::multiply(const Matrix & m) const
{
    Matrix newMatrix(_rows, _cols);
    for (int i=0; i < _rows; i++)
    {  //i = rows
        for (int j=0; j < _cols; j++)
        {  //j = cols
            for (int k=0; k < _cols; k++)
            {
                newMatrix.m[i][j] += this->m[i][k] * m.m[k][j];
            }
        }
    }
    return newMatrix;
}

Matrix Matrix::divide(double s) const
{
    Matrix newMatrix(_rows, _cols);
    for (int i=0; i < _rows; i++)
    {  //i = rows
        for (int j=0; j < _cols; j++)
        {  //j = cols
            
            newMatrix.m[i][j] += m[i][j] / s;
            
        }
    }
    return newMatrix;
}

Matrix Matrix::t() const
{
    Matrix newMatrix(_rows, _cols);
    for (int i=0; i < _rows; i++)
    {  //i = rows
        for (int j=0; j < _cols; j++)
        {  //j = cols
            
            newMatrix.m[i][j] = m[j][i];
            
        }
    }
    return newMatrix;
}

/**
 * Overloaded copy assignment operator
 * 
 * @param m
 */
void Matrix::operator=(const Matrix &m) const
{
    if(this->m != m.m && _rows == m._rows && _cols == m._cols)
    {
        for (int i=0; i<_rows; i++)
        {
            for (int j=0; j<_cols; j++)
            {
                this->m[i][j] = m.m[i][j];
            }
        }
    }       
}
    
/**
 * 
 * @param row
 * @param col
 * @return 
 */
double & Matrix::operator()(uint row, uint col) const //x(0, 0) = 1;
{
    return m[row][col]; 

}
    
/**
 * 
 * @param number
 * @param matrix
 * @return 
 */
Matrix operator*(const double &number, const Matrix &matrix)
{
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for (int i=0; i < matrix.numRows(); i++)
    {  //i = rows
        for (int j=0; j < matrix.numCols(); j++)
        {  //j = cols
            
            newMatrix.m[i][j] += number * matrix.m[i][j];
            
        }
    }
    return newMatrix;
}
   
Matrix operator*(const Matrix &matrix, const double &number)
{
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for (int i=0; i < matrix.numRows(); i++)
    {  //i = rows
        for (int j=0; j < matrix.numCols(); j++)
        {  //j = cols
            
            newMatrix.m[i][j] += number * matrix.m[i][j];
            
        }
    }
    return newMatrix;
}

Matrix operator*(const Matrix &matrix1, const Matrix &matrix2)
{
    Matrix newMatrix(matrix1.numRows(), matrix1.numCols());
    for (int i=0; i < matrix1.numRows(); i++)
    {  //i = rows
        for (int j=0; j < matrix1.numCols(); j++)
        {  //j = cols
            for(int k=0; k<matrix1.numCols(); k++)
            {
                newMatrix.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
            }
        }
    }
    return newMatrix;
}

/**
 * 
 * @param number
 * @param matrix
 * @return 
 */
Matrix operator/(const double &number, const Matrix &matrix)
{
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for (int i=0; i < matrix.numRows(); i++)
    {  //i = rows
        for (int j=0; j < matrix.numCols(); j++)
        {  //j = cols
            
            newMatrix.m[i][j] += number / matrix.m[i][j];
            
        }
    }
    return newMatrix;
}

/**
 * 
 * @param matrix
 * @param number
 * @return 
 */
Matrix operator/(const Matrix &matrix, const double &number)
{
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for (int i=0; i < matrix.numRows(); i++)
    {  //i = rows
        for (int j=0; j < matrix.numCols(); j++)
        {  //j = cols
            
            newMatrix.m[i][j] += matrix.m[i][j] / number;
            
        }
    }
    return newMatrix;
}
    
/**
 * 
 * @param number
 * @param matrix
 * @return 
 */
Matrix operator+(const double &number, const Matrix &matrix)
{  
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for(int i=0; i < matrix.numRows(); i++)
    {
        for(int j=0; j < matrix.numCols(); j++)
        {
            newMatrix.m[i][j] += number + matrix.m[i][j];        
        }    
    }
    return newMatrix;
}

Matrix operator+(const Matrix &matrix, const double &number)
{  
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for(int i=0; i < matrix.numRows(); i++)
    {
        for(int j=0; j < matrix.numCols(); j++)
        {
            newMatrix.m[i][j] += matrix.m[i][j] + number;        
        }    
    }
    return newMatrix;
}
    
Matrix operator+(const Matrix &matrix1, const Matrix &matrix2)
{  
    Matrix newMatrix(matrix1.numRows(), matrix1.numCols());
    for(int i=0; i < matrix1.numRows(); i++)
    {
        for(int j=0; j < matrix1.numCols(); j++)
        {
            newMatrix.m[i][j] += matrix1.m[i][j] + matrix2.m[i][j];        
        }    
    }
    return newMatrix;
}

/**
 * 
 * @param number
 * @param matrix
 * @return 
 */
Matrix operator-(const double &number, const Matrix &matrix)
{
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for(int i=0; i < matrix.numRows(); i++)
    {
        for(int j=0; j < matrix.numCols(); j++)
        {
            newMatrix.m[i][j] += number - matrix.m[i][j];        
        }    
    }
    return newMatrix;

}

Matrix operator-(const Matrix &matrix, const double &number)
{
    Matrix newMatrix(matrix.numRows(), matrix.numCols());
    for(int i=0; i < matrix.numRows(); i++)
    {
        for(int j=0; j < matrix.numCols(); j++)
        {
            newMatrix.m[i][j] += matrix.m[i][j] - number;        
        }    
    }
    return newMatrix;

}
    
Matrix operator-(const Matrix &matrix1, const Matrix &matrix2)
{
    Matrix newMatrix(matrix1.numRows(), matrix1.numCols());
    for(int i=0; i < matrix1.numRows(); i++)
    {
        for(int j=0; j < matrix1.numCols(); j++)
        {
            newMatrix.m[i][j] += matrix1.m[i][j] - matrix2.m[i][j];        
        }    
    }
    return newMatrix;

}

/**
 * 
 * @return 
 */
Matrix Matrix::operator-()
{
    Matrix newMatrix(_rows, _cols);
    for(int i=0; i < _rows; i++)
    {
        for(int j=0; j < _cols; j++)
        {
            newMatrix.m[i][j] = m[i][j] * (-1);        
        }    
    }
    return newMatrix;

}
