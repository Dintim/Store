#pragma once
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

class date_
{
	int day, month, year;
public:
	date_();	
	date_(int day, int month, int year);
	date_(string& str);
	void print()const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int day, int month, int year);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	date_ operator+=(int day);
	date_ operator-=(int day);
	date_ operator++(int);
	date_ operator--(int);
	date_ operator++();
	date_ operator--();
	void getWeekDay()const;		
};

bool operator>(const date_&a, const date_&b);
bool operator<=(const date_&a, const date_&b);
bool operator<(const date_&a, const date_&b);
bool operator>=(const date_&a, const date_&b);
bool operator==(const date_&a, const date_&b);
bool operator!=(const date_&a, const date_&b);
date_ operator+(const date_&a, int day);
date_ operator-(const date_&a, int day);
int daysBetweenDates(const date_&a, const date_&b);
int daysToDateFromCurrDate(const date_&a);

ostream&operator<<(ostream&os, const date_&obj);
istream&operator>>(istream&is, date_&obj);


