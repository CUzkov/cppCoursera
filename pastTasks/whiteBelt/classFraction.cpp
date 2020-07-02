#include <algorithm>
#include <numeric>
#include <iostream>


class Rational {

public:

    Rational():
        _numerator(0),
        _denominator(1) {};

    Rational(long numerator, long denominator) {

        if(denominator == 0)
            throw std::invalid_argument("Invalid argument");

        if(numerator * denominator < 0) {
            _numerator = -1 * abs(numerator);
            _denominator = abs(denominator);
        }
        else if(numerator == 0)
        {
            _numerator = 0;
            _denominator = 1;
        }
        else
        {
            _numerator = abs(numerator);
            _denominator = abs(denominator);
        }

        Reduce();

    };

    int Numerator() const {
        return _numerator;
    };

    int Denominator() const {
        return _denominator;
    };

    void Reduce() {
            int GCD = std::gcd(_numerator, _denominator);     

            if(GCD != 0) {
                _numerator /= GCD;
                _denominator /= GCD;
            } 
    }

private:

    long _denominator;
    long _numerator;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {

    return Rational(
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), 
            lhs.Denominator() * rhs.Denominator());

}

Rational operator-(const Rational& lhs, const Rational& rhs) {

    return Rational(
            lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), 
            lhs.Denominator() * rhs.Denominator());

}

bool operator==(const Rational& lhs, const Rational& rhs) {

    if(rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator())
        return true;

    return false;

}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {

    if(rhs.Numerator() == 0) 
        throw std::domain_error("Division by zero");

    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());

}

std::ostream& operator<<(std::ostream& out, const Rational& ral) {
    
    out << ral.Numerator() << "/" << ral.Denominator();

    return out;
}

std::istream& operator>>(std::istream& inn, Rational& ral) {
    
    int p, q;
    
    if (inn >> p && inn.ignore(1) && inn >> q) {
        ral = { p, q };
    }

    return inn;

}

bool operator<(const Rational& lhs, const Rational& rhs) {

    if(lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator())
        return true;
    else
        return false;

}

bool operator>(const Rational& lhs, const Rational& rhs) {

    if(lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator())
        return true;
    else
        return false;

}

bool operator<=(const Rational& lhs, const Rational& rhs) {

    if(lhs.Numerator() * rhs.Denominator() <= rhs.Numerator() * lhs.Denominator())
        return true;
    else
        return false;

}

bool operator>=(const Rational& lhs, const Rational& rhs) {

    if(lhs.Numerator() * rhs.Denominator() >= rhs.Numerator() * lhs.Denominator())
        return true;
    else
        return false;

}

int main(int argc, char const *argv[])
{
    int a, b;
    char sign, buff;

    std::cin >> a >> sign >> b;

    try
    {
        Rational f(a, b);

        std::cin >> sign >> a >> buff >> b;

        Rational s(a, b);
        
        if(sign == '+')
            std::cout << f + s << std::endl;
        if(sign == '-')
            std::cout << f - s << std::endl;
        if(sign == '*')
            std::cout << f * s << std::endl;
        if(sign == '/') {
            try
            {
                std::cout << f / s << std::endl;
            }
            catch(const std::domain_error& e)
            {
                std::cout << e.what() << '\n';
            }
        }

    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}
