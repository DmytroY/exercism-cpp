#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {

// TODO: add your solution here
    float Complex::real() const{ return _r; }

    float Complex::imag() const{ return _i; }

    float Complex::abs() const {
        return sqrt(_r * _r + _i * _i);
    }

    Complex Complex::operator*(Complex obj) const{
        // z1 * z2 = (a + jb) * (c + jd) = (a * c - b * d) + j(b * c + a * d)
        Complex result;
        result._r = _r * obj._r - _i * obj._i;
        result._i = _i * obj._r + _r * obj._i;
        return result;
    }

    Complex Complex::operator+(Complex obj) const{
        //z1 + z2 = (a + jb) + (c + jd) = (a + c) + j(b + d)
        Complex result;
        result._r = _r + obj._r;
        result._i = _i + obj._i;
        return result;
    }

    Complex Complex::operator-(Complex obj) const{
        Complex result;
        result._r = _r - obj._r;
        result._i = _i - obj._i;
        return result;
    }

    Complex Complex::operator/(Complex obj) const{
        // (a + bi) / (c + di) = (a * c + b * d) / (c^2 + d^2) + (b * c - a * d) / (c^2 + d^2)i
        Complex result;
        float foo = obj._i * obj._i + obj._r * obj._r;
        result._r = (_r * obj._r + _i * obj._i) / foo;
        result._i = (_i * obj._r - _r * obj._i) / foo;
        return result;
    }

    Complex Complex::conj() const{
        Complex result;
        result._r = _r;
        result._i = - _i;
        return result;
    }
    
    Complex Complex::exp() const{
        // e^(a + bi) = e^a * e^(bi)= e^a * cos(b) + i * e^a * sin(b)
        Complex result;
        result._r = std::exp(_r) * std::cos(_i);
        result._i = std::exp(_r) * std::sin(_i);
        return result;
    }

    Complex operator+(float f, Complex c){
        Complex a(f, 0);
        return a + c;
    }

    Complex operator-(float f, Complex c){
        Complex a(f, 0);
        return a - c;
    }

    Complex operator*(float f, Complex c){
        Complex a(f, 0);
        return a * c;
    }

    Complex operator/(float f, Complex c){
        Complex a(f, 0);
        return a / c;
    }
}  // namespace complex_numbers
