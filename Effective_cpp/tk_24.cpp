/*
 * @Author: linkenzone
 * @Date: 2022-04-19 16:37:11
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <vector>

using namespace std;

class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1){
    }
    // const Rational operator* (const Rational& rhs) const {
    //     return 1;
    // }
private:
    int numerator;
    int denominator;
};

const Rational operator* (const Rational & lhs , const Rational & rhs){
    return 2;
}


int main()
{
    Rational oneEight(1, 8);
    Rational oneHalf(1, 2);
    Rational res = oneEight * oneHalf;

    res = oneHalf * 2;
    res = 2 * oneHalf;
}