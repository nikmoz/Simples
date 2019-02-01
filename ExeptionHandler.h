#pragma once
#include <string>
#include <iostream>
#include <exception>
class ExeptionHandler:public std::exception
{
public:
	const char * ErrorMessage;
	ExeptionHandler(const char * ErrorMessage);
	const char * what() const throw ();
};

