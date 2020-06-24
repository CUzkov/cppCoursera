#include <vector>
#include <iostream>
#include <algorithm>


class FunctionPart
{
private:
    char _sign;
    double _number;

public:
    explicit FunctionPart(const char& sign, const double& number): _sign(sign), _number(number) {}

    void applyOperation(double& number) const {
        
        if(_sign == '-')
            number -= _number;
        else if(_sign == '+')
            number += _number;
        else if(_sign == '*')
            number *= _number;
        else if(_sign == '/')
            number /= _number;

    }

    void reversSign() {

        if(_sign == '-' || _sign == '+') {
            if(_sign == '-')
                _sign = '+';
            else
                _sign = '-';
        }
        else
        {
            if(_sign == '/')
                _sign = '*';
            else
                _sign = '/';
        }
        
    }

};

class Function
{
private:
    std::vector<FunctionPart> _func;

public:

    void AddPart(const char& sign, const double& number) {
        
        if(sign == '+' || sign == '-' || sign == '*' || sign == '/'){
            _func.push_back(FunctionPart(sign, number));
        }
    }

    double Apply(double number) const {

        for(const auto& part : _func)
        {
            part.applyOperation(number);
        }

        return number;

    }

    void Invert() {
        
        for(auto& part : _func)
        {
            part.reversSign();
        }
        
        std::reverse(begin(_func), end(_func));

    }

};