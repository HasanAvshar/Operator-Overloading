#include <iostream>
using namespace std;
#include<cassert>

class Fraction {
private:
	int _numerator; // suret
	int _denominator; // mexrec
public:
	Fraction() {
		_numerator = 0;
		_denominator = 0;
	}
	Fraction(int num, int don) : Fraction() {
		SetDenumerator(don);
		SetNumerator(num);
	}
	Fraction(const Fraction& other) :_numerator(other._numerator), _denominator(other._denominator)
	{
		cout << "Ctor Copy" << endl;
	}

	Fraction Multiply(const Fraction& other) {
		int numerator = this->_numerator * other._numerator;
		int denumerator = this->_denominator * other._numerator;

		return Fraction(numerator, denumerator);
	}
	Fraction Add(const Fraction& other) {
		int don = this->_denominator;
		int num = this->_numerator + other._numerator;
		if (this->_denominator != other._denominator) {
			don = this->_denominator * other._denominator;
			num = (this->_numerator * other._denominator) + (this->_denominator * other._numerator);
		}

		return Fraction(num, don);
	}
	Fraction Minus(const Fraction& other) {
		int don = this->_denominator;
		int num = this->_numerator - other._numerator;
		if (this->_denominator != other._denominator) {
			don = this->_denominator * other._denominator;
			num = (this->_numerator * other._denominator) - (this->_denominator * other._numerator);
		}

		return Fraction(num, don);
	}
	Fraction Divide(const Fraction& other) {
		int don = this->_denominator * other._numerator;
		int num = this->_numerator * other._denominator;

		return Fraction(num, don);
	}
	Fraction Simplify() const {// Kəsri ixtisar edir
		int ebob = 1;
		if (_numerator < _denominator) {
			for (size_t i = 1; i <= _numerator; i++)
			{
				if (_numerator % i == 0) {
					if (_denominator % i == 0) {
						if (i > ebob) {
							ebob = i;
						}
					}
				}
			}
		}
		else {
			for (size_t i = 1; i <= _denominator; i++)
			{
				if (_denominator % i == 0) {
					if (_numerator % i == 0) {
						if (i > ebob) {
							ebob = i;
						}
					}
				}
			}
		}

		return Fraction(_numerator / ebob, _denominator / ebob);
	}
	int GetNumerator() { return _numerator; }
	int GetDenumerator() { return _denominator; }

	void SetNumerator(int number) {
		if (number > 0 && number < 100)
			_numerator = number;
		else assert(!"Number Error");
	}
	void SetDenumerator(int number) {
		if (number > 0 && number < 100)
			_denominator = number;
		else assert(!"DeNum Error");
	}

	Fraction operator+(const Fraction& other) {
		return this->Add(other);
	}

	Fraction operator+(const int other) {
		int don = this->_denominator;
		int num = this->_numerator + (other * this->_denominator);

		return Fraction(num, don);
	}

	Fraction operator-(const Fraction& other) {
		return this->Minus(other);
	}
	Fraction operator*(const Fraction& other) {
		return this->Multiply(other);
	}
	Fraction operator/(const Fraction& other) {
		return this->Divide(other);
	}

	bool operator>(const Fraction& other) {
		Fraction a = this->Simplify();
		Fraction b = other.Simplify();
		return (a._numerator * b._denominator) > (b._numerator * a._denominator);
	}

	bool operator>=(const Fraction& other) {
		Fraction a = this->Simplify();
		Fraction b = other.Simplify();
		return (a._numerator * b._denominator) >= (b._numerator * a._denominator);
	}

	bool operator<(const Fraction& other) {
		Fraction a = this->Simplify();
		Fraction b = other.Simplify();
		return (a._numerator * b._denominator) < (b._numerator * a._denominator);
	}

	bool operator<=(const Fraction& other) {
		Fraction a = this->Simplify();
		Fraction b = other.Simplify();
		return (a._numerator * b._denominator) <= (b._numerator * a._denominator);
	}

	bool operator==(const Fraction& other) {
		Fraction a = this->Simplify();
		Fraction b = other.Simplify();
		return (this->_numerator == other._numerator) && (this->_denominator == other._denominator);
	}

	bool operator !=(const Fraction& other) {
		Fraction a = this->Simplify();
		Fraction b = other.Simplify();
		return !((this->_numerator == other._numerator) && (this->_denominator == other._denominator));
	}


	Fraction& operator++(int num) {
		this->_numerator = this->_numerator + this->_denominator;
		return *this;
	}

	Fraction& operator++() {
		this->_numerator = this->_numerator + this->_denominator;
		return *this;
	}

	Fraction& operator--() {
		this->_numerator = this->_numerator - this->_denominator;
		return *this;
	}

	Fraction& operator--(int num) {
		this->_numerator = this->_numerator - this->_denominator;
		return *this;
	}

	operator int() const
	{
		return _denominator;
	}

	friend ostream& operator<<(ostream& print, const Fraction& other);
	friend istream& operator>>(istream& print, Fraction& other);

};
ostream& operator<<(ostream& print, const Fraction& other)
{
	print << "Numerator: " << other._numerator << endl;
	print << "Denominator: " << other._denominator << endl;
	return print;
}

istream& operator>>(istream& input, Fraction& other)
{
	int _numerator; // suret
	int _denominator; // mexrec

	cout << "Enter Numerator: ";
	input >> _numerator;

	cout << "Enter Denumerator: ";
	input >> _denominator;

	other.SetDenumerator(_denominator);
	other.SetNumerator(_numerator);

	return input;
}

int main()
{
	Fraction f1, f2;
	cin >> f1;
	cin >> f2;
	Fraction result = f1 + f2;
	cout << result << endl;
}