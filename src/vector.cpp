//#include <iostream>
#include <vector.h>
#include <stdio.h>

//using namespace std;




Vector::Vector() {
    for (unsigned int i = 0; i < n; i++) {
        coords_[i] = 0;
    }
}

Vector::Vector(double number) {
    for (unsigned int i = 0; i < n; i++) {
        coords_[i] = number;
    }
}

Vector::Vector(const Vector &other) {
    for (unsigned int i = 0; i < n; i++) {
        coords_[i] = other.coords_[i];
    }
}

Vector &Vector::operator=(const Vector &other) {
    for (unsigned int i = 0; i < n; i++) {
        coords_[i] = other.coords_[i];
    }
    return *this; ///??? check this
}

double Vector::operator[](unsigned long i) const {
    return coords_[i]; //red highlight in clion  is noraml
}

double &Vector::operator[](unsigned long i) {
    return coords_[i];
}

Vector & Vector::operator+=(const Vector &other) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] = coords_[i] + other.coords_[i];
    return *this;
}

Vector &Vector::operator-=(const Vector &other) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] = coords_[i] - other.coords_[i];
    return *this;
}

Vector &Vector::operator*=(double number) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] = coords_[i] * number;
    return *this;
}

Vector &Vector::operator/=(double number) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] = coords_[i] / number;
    return *this;
}

bool operator==(const Vector &current, const Vector &other) {
    for (unsigned int i = 0; i < Vector::n; ++i)
        if (current.coords_[i] != other.coords_[i]) {
            return false;
        }
    return true;
}

Vector operator+(const Vector &current, const Vector &other) {
    Vector vector;
    for (unsigned int i = 0; i < Vector::n; i++)
        vector.coords_[i] = current.coords_[i] + other.coords_[i];
    return vector;
}

Vector operator-(const Vector &current, const Vector &other) {
    Vector vector;
    for (unsigned int i = 0; i < Vector::n; i++)
        vector.coords_[i] = current.coords_[i] - other.coords_[i];
    return vector;
}

Vector operator*(const Vector &current, double number) {
    Vector vector;
    for (unsigned int i = 0; i < Vector::n; i++)
        vector.coords_[i] = current.coords_[i] * number;
    return vector;
}

Vector operator*(double number, const Vector &current) {
    Vector vector;
    for (unsigned int i = 0; i < Vector::n; i++)
        vector.coords_[i] = current.coords_[i] * number;
    return vector;
}

Vector operator/(const Vector &current, double number) {
    Vector vector;
    for (unsigned int i = 0; i < Vector::n; i++)
        vector.coords_[i] = current.coords_[i] / number;
    return vector;
}

double operator^(const Vector &current, const Vector &other) {
    double sum[Vector::n];
    double result = 0;
    for (unsigned int i = 0; i < Vector::n; i++) {
        sum[i] = current.coords_[i] * other.coords_[i];
        result = result + sum[i];
    }
    return result;
}

Vector Vector::operator-() const {
    Vector vector;
    for (unsigned int i = 0; i < n; i++)
        vector.coords_[i] = (-1) * coords_[i];
    return vector;
}


bool operator!=(const Vector &current, const Vector &other) {
    if (current == other) {
        return false;
    }
    else {
        return true;
    }
}
