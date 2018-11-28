#include "date_.h"



date_::date_()
{
	day = 1;
	month = 1;
	year = 1900;
}


date_::date_(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

date_::date_(string & str)
{
	vector<string> v(3);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] = str.substr(0, str.find('.'));
		str = str.substr(str.find('.') + 1);
	}
	this->setDay(stoi(v[0]));
	this->setMonth(stoi(v[1]));
	this->setYear(stoi(v[2]));
}

void date_::print()const
{
	if (day < 10) cout << "0";
	cout << day << ".";
	if (month < 10) cout << "0";
	cout << month << ".";
	cout << year << endl;
}

void date_::setDay(int day)
{	
	if (day < 0 || day>31)
		this->day = 1;
	else {
		if (day > 28 && this->month == 2) {
			if (day == 29 && (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0)))
				this->day = day;
			else
				this->day = 1;
		}
		else if (day == 31 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11))
			this->day = 1;
		else
			this->day = day;
	}

}

void date_::setMonth(int month)
{
	if (month > 0 && month < 13) this->month = month;
	else this->month = 1;
}

void date_::setYear(int year)
{
	if (year < 1900) this->year = 1900;
	else this->year = year;
}

void date_::setDate(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(month);
}

int date_::getDay()const
{
	return this->day;
}

int date_::getMonth()const
{
	return this->month;
}

int date_::getYear()const
{
	return this->year;
}

date_ date_::operator+=(int day)
{
	int day_tmp = this->day + day;
	int month_tmp = this->month;
	int year_tmp = this->year;
	while (day_tmp > 31) {
		if (month_tmp == 1 || month_tmp == 3 || month_tmp == 5 || month_tmp == 7 || month_tmp == 8 || month_tmp == 10 || month_tmp == 12) {
			day_tmp = day_tmp - 31;
		}
		if (month_tmp == 4 || month_tmp == 6 || month_tmp == 9 || month_tmp == 11) {
			day_tmp = day_tmp - 30;
		}		
		if (month_tmp == 2) {
			if (year_tmp % 400 == 0 || (year_tmp % 4 == 0 && year_tmp % 100 != 0))
				day_tmp = day_tmp - 29;
			else
				day_tmp = day_tmp - 28;
		}
		month_tmp++;
		if (month_tmp > 12) {
			year_tmp += month_tmp / 12;
			month_tmp = month_tmp % 12;
		}
	}

	
	if (day_tmp == 31) {	
		if (month_tmp == 4 || month_tmp == 6 || month_tmp == 9 || month_tmp == 11) {
			day_tmp = day_tmp - 30;
			month_tmp++;
		}
		else if (month_tmp == 2) {
			if (year_tmp % 400 == 0 || (year_tmp % 4 == 0 && year_tmp % 100 != 0)) 
				day_tmp = day_tmp - 29;
			else 
				day_tmp = day_tmp - 28;
			month_tmp++;
		}		
	}
	else if (day_tmp == 30) {
		if (month_tmp == 2) {
			if (year_tmp % 400 == 0 || (year_tmp % 4 == 0 && year_tmp % 100 != 0)) 
				day_tmp = day_tmp - 29;
			else 
				day_tmp = day_tmp - 28;
			month_tmp++;
		}
	}
	else if (day_tmp == 29) {
		if (!(year_tmp % 400 == 0 || (year_tmp % 4 == 0 && year_tmp % 100 != 0))) {
			day_tmp = day_tmp - 28;
			month_tmp++;
		}
	}
	
	this->day = day_tmp;
	this->month = month_tmp;
	this->year = year_tmp;	
	return *this;
}

date_ date_::operator-=(int day)
{
	int day_tmp = this->day - day;
	int month_tmp = this->month;
	int year_tmp = this->year;	
	while (day_tmp < 0) {
		month_tmp--;
		if (month_tmp == 0) {
			year_tmp--;
			month_tmp = 12;
		}

		if (month_tmp == 1 || month_tmp == 3 || month_tmp == 5 || month_tmp == 7 || month_tmp == 8 || month_tmp == 10 || month_tmp == 12)
			day_tmp = day_tmp + 31;
		if (month_tmp == 4 || month_tmp == 6 || month_tmp == 9 || month_tmp == 11) 
			day_tmp = day_tmp + 30;
		if (month_tmp == 2) {
			if (year_tmp % 400 == 0 || (year_tmp % 4 == 0 && year_tmp % 100 != 0))
				day_tmp = day_tmp + 29;
			else
				day_tmp = day_tmp + 28;
		}		
	}

	if (day_tmp == 0) {
		if (month_tmp == 4 || month_tmp == 6 || month_tmp == 9 || month_tmp == 11)
			day_tmp = 30;
		else if (month_tmp == 1 || month_tmp == 3 || month_tmp == 5 || month_tmp == 7 || month_tmp == 8 || month_tmp == 10 || month_tmp == 12)
			day_tmp = 31;
		else if (month_tmp == 2) {
			if (year_tmp % 400 == 0 || (year_tmp % 4 == 0 && year_tmp % 100 != 0))
				day_tmp = 29;
			else
				day_tmp = 28;
		}
	}	

	this->day = day_tmp;
	this->month = month_tmp;
	this->year = year_tmp;
	return *this;
}

date_ date_::operator++(int)
{
	date_ tmp;
	tmp = *this;
	this->day++;
	if (this->day > 31 && (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10)) {
		this->month++;
		this->day = this->day - 31;
	}
	else if (this->day > 31 && this->month == 12) {
		this->year++;
		this->month = 1;
		this->day = this->day - 31;
	}
	else if (this->day > 30 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)) {
		this->month++;
		this->day = this->day - 30;
	}
	else if (this->day > 28 && this->month == 2) {
		if (this->day > 29 && (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))) {
			this->month++;
			this->day = this->day - 29;
		}
		else if (this->day > 28 && !(this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))) {
			this->month++;
			this->day = this->day - 28;
		}
	}	
	return tmp;
}

date_ date_::operator--(int)
{
	date_ tmp;
	tmp = *this;
	this->day--;
	if (this->day == 0) {
		this->month--;
		if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
			this->day = 31;
		else if (this->month == 0) {
			this->day = 31;
			this->year--;
			this->month = 12;
		}
		else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
			this->day = 30;
		else if (this->month == 2) {
			if (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))
				this->day = 29;
			else
				this->day = 28;
		}
	}		
	return tmp;
}

date_ date_::operator++()
{
	this->day++;
	if (this->day > 31 && (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10)) {
		this->month++;
		this->day = this->day - 31;
	}
	else if (this->day > 31 && this->month == 12) {
		this->year++;
		this->month = 1;
		this->day = this->day - 31;
	}
	else if (this->day > 30 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)) {
		this->month++;
		this->day = this->day - 30;
	}
	else if (this->day > 28 && this->month == 2) {
		if (this->day > 29 && (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))) {
			this->month++;
			this->day = this->day - 29;
		}
		else if (this->day > 28 && !(this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))) {
			this->month++;
			this->day = this->day - 28;
		}
	}
	return *this;
}

date_ date_::operator--()
{
	this->day--;
	if (this->day == 0) {
		this->month--;
		if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
			this->day = 31;
		else if (this->month == 0) {
			this->day = 31;
			this->year--;
			this->month = 12;
		}
		else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
			this->day = 30;
		else if (this->month == 2) {
			if (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))
				this->day = 29;
			else
				this->day = 28;
		}
	}
	return *this;
}

void date_::getWeekDay()const
{
	int a = (14 - this->month) / 12;
	int y = this->year - a;
	int m = this->month + 12 * a - 2;
	int result = (this->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	switch (result)
	{
	case 0:
		cout << "Sunday";
		break;
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	}
	
}


bool operator>(const date_ & a, const date_ & b)
{
	if (a.getYear() > b.getYear()) return true;
	else if (a.getYear() < b.getYear()) return false;
	else {
		if (a.getMonth() > b.getMonth()) return true;
		else if (a.getMonth() < b.getMonth()) return false;
		else {
			if (a.getDay() > b.getDay()) return true;
			else return false;
		}
	}	
}

bool operator<=(const date_ & a, const date_ & b)
{
	if (a.getDay() == b.getDay() && a.getMonth() == b.getMonth() && a.getYear() == b.getYear()) return true;
	else {
		if (a.getYear() < b.getYear()) return true;
		else if (a.getYear() > b.getYear()) return false;
		else {
			if (a.getMonth() < b.getMonth()) return true;
			else if (a.getMonth() > b.getMonth()) return false;
			else {
				if (a.getDay() < b.getDay()) return true;
				else return false;
			}
		}
	}
}

bool operator<(const date_ & a, const date_ & b)
{
	if (a.getYear() < b.getYear()) return true;
	else if (a.getYear() > b.getYear()) return false;
	else {
		if (a.getMonth() < b.getMonth()) return true;
		else if (a.getMonth() > b.getMonth()) return false;
		else {
			if (a.getDay() < b.getDay()) return true;
			else return false;
		}
	}
}

bool operator>=(const date_ & a, const date_ & b)
{
	if (a.getDay() == b.getDay() && a.getMonth() == b.getMonth() && a.getYear() == b.getYear()) return true;
	else {
		if (a.getYear() > b.getYear()) return true;
		else if (a.getYear() < b.getYear()) return false;
		else {
			if (a.getMonth() > b.getMonth()) return true;
			else if (a.getMonth() < b.getMonth()) return false;
			else {
				if (a.getDay() > b.getDay()) return true;
				else return false;
			}
		}
	}
}

bool operator==(const date_ & a, const date_ & b)
{
	return (a.getDay() == b.getDay() && a.getMonth() == b.getMonth() && a.getYear() == b.getYear());
}

bool operator!=(const date_ & a, const date_ & b)
{
	return !(a.getDay() == b.getDay() && a.getMonth() == b.getMonth() && a.getYear() == b.getYear());
}

date_ operator+(const date_ & a, int day)
{
	date_ tmp(a.getDay(), a.getMonth(), a.getYear());
	tmp += day;
	return tmp;
}

date_ operator-(const date_ & a, int day)
{
	date_ tmp(a.getDay(), a.getMonth(), a.getYear());
	tmp -= day;
	return tmp;
}

int daysBetweenDates(const date_ & a, const date_ & b)
{
	int counDays = 0;
	int x = 0, x_const = 0, n = 0, h = 0, y = 0, y_const = 0, m = 0, k = 0;
	if (b.getYear() > a.getYear() || b.getYear() < a.getYear()) {
		if (b.getYear() > a.getYear()) {
			x = b.getYear(), y = a.getYear();
			x_const = b.getYear(), y_const = a.getYear();
			n = b.getMonth(), m = a.getMonth();
			h = b.getDay(), k = a.getDay();
		}
		else {
			x = a.getYear(), y = b.getYear();
			x_const = a.getYear(), y_const = b.getYear();
			n = a.getMonth(), m = b.getMonth();
			h = a.getDay(), k = b.getDay();
		}

		counDays += h;

		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			counDays += 31 - k;
		if (m == 4 || m == 6 || m == 9 || m == 11)
			counDays += 30 - k;
		if (m == 2) {
			if (y_const % 400 == 0 || (y_const % 4 == 0 && y_const % 100 != 0))
				counDays += 29 - k;
			else
				counDays += 28 - k;
		}


		x = x - 1;
		while (x != y) {
			if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
				counDays += 366;
			else
				counDays += 365;
			x--;
		}

		//считаем дни в b.year		
		n = n - 1;
		while (n != 0) {
			if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10)
				counDays += 31;
			if (n == 4 || n == 6 || n == 9 || n == 11)
				counDays += 30;
			if (n == 2) {
				if (x_const % 400 == 0 || (x_const % 4 == 0 && x_const % 100 != 0))
					counDays += 29;
				else
					counDays += 28;
			}
			n--;
		}
		//считаем дни в a.year		
		m = m + 1;
		while (m < 13) {
			if (m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				counDays += 31;
			if (m == 4 || m == 6 || m == 9 || m == 11)
				counDays += 30;
			if (m == 2) {
				if (y_const % 400 == 0 || (y_const % 4 == 0 && y_const % 100 != 0))
					counDays += 29;
				else
					counDays += 28;
			}
			m++;
		}
	}
	if (b.getYear() == a.getYear()) {
		x = b.getYear(), y = a.getYear();
		if (b.getMonth() >= a.getMonth()) {
			n = b.getMonth(), m = a.getMonth();
			h = b.getDay(), k = a.getDay();
		}
		else if (b.getMonth() < a.getMonth()) {
			n = a.getMonth(), m = b.getMonth();
			h = a.getDay(), k = b.getDay();
		}
		counDays += h;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			counDays += 31 - k;
		if (m == 4 || m == 6 || m == 9 || m == 11)
			counDays += 30 - k;
		if (m == 2) {
			if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
				counDays += 29 - k;
			else
				counDays += 28 - k;
		}

		n--;
		while (n != m) {
			if (n == 3 || n == 5 || n == 7 || n == 8 || n == 10)
				counDays += 31;
			if (n == 4 || n == 6 || n == 9 || n == 11)
				counDays += 30;
			if (n == 2) {
				if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
					counDays += 29;
				else
					counDays += 28;
			}
			n--;
		}
	}


	if (b.getYear() < a.getYear()) {
		return -counDays;
	}
	else {
		if (b.getMonth() < a.getMonth())
			return -counDays;
		else {
			if (b.getDay() < a.getDay())
				return -counDays;
		}
	}
	return counDays;
}

int daysToDateFromCurrDate(const date_ & a)
{
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);
	now.tm_sec;
	int day = now.tm_mday;
	int month = (now.tm_mon + 1);
	int year = (now.tm_year + 1900);
	date_ currDay(day, month, year);	
	return daysBetweenDates(currDay, a);
}


ostream & operator<<(ostream & os, const date_ & obj)
{		
	if (obj.getDay() < 10) os << "0";
	os << obj.getDay() << ".";
	if (obj.getMonth() < 10) os << "0";
	os << obj.getMonth() << ".";
	os << obj.getYear() << endl;
	return os;
}

istream & operator>>(istream & is, date_ & obj)
{
	int x;
	char y;
	is >> x;
	obj.setDay(x);
	is >> y;
	is >> x;
	obj.setMonth(x);
	is >> y;
	is >> x;
	obj.setYear(x);
	return is;	
}
