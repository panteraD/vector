#include <vector.h>

Vector::Vector() {
    for (unsigned long i = 0; i < n; i++) {
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
    return *this;
}

double Vector::operator[](unsigned long i) const {
    return coords_[i]; //red highlight in clion  is normal
}

double &Vector::operator[](unsigned long i) {
    return coords_[i];
}

Vector &Vector::operator+=(const Vector &other) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] += other.coords_[i];
    return *this;
}

Vector &Vector::operator-=(const Vector &other) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] -= other.coords_[i];
    return *this;
}

Vector &Vector::operator*=(double number) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] *= number;
    return *this;
}

Vector &Vector::operator/=(double number) {
    for (unsigned int i = 0; i < n; i++)
        coords_[i] /= number;
    return *this;
}

bool operator==(const Vector &current, const Vector &other) {
    for (unsigned int i = 0; i < Vector::n; i++)
        if (current.coords_[i] != other.coords_[i]) {
            return false;
        }
    return true;
}

Vector operator+(const Vector &current, const Vector &other) {
    Vector vector(current);
    return vector += other;
}

Vector operator-(const Vector &current, const Vector &other) {
    Vector vector(current);
    return vector -= other;
}

Vector operator*(const Vector &current, double number) {
    Vector vector(current);
    return vector *= number;
}

Vector operator*(double number, const Vector &current) {
    Vector vector(current);
    return vector *= number;
}

Vector operator/(const Vector &current, double number) {
    Vector vector(current);
    return vector /= number;
}

double operator^(const Vector &current, const Vector &other) {
    double result = 0;
    for (unsigned int i = 0; i < Vector::n; i++) {
        result += current.coords_[i] * other.coords_[i];
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
    return !(current == other);
}
