#pragma once

namespace complex_numbers {

// TODO: add your solution here
    class Complex {
        private:
            
        public:
            float _r;
            float _i;
            Complex(float r=0, float i=0) : _r(r), _i(i){};
            float real() const;
            float imag() const;
            float abs() const;
            Complex operator*(Complex) const;
            Complex operator+(Complex) const;
            Complex operator-(Complex) const;
            Complex operator/(Complex) const;
            Complex conj() const;
            Complex exp() const;
    };
    Complex operator+(float, Complex);
    Complex operator-(float, Complex);
    Complex operator*(float, Complex);
    Complex operator/(float, Complex);
}  // namespace complex_numbers
