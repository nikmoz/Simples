#include "ExeptionHandler.h"
ExeptionHandler::ExeptionHandler(const char *ErrorMessage) {
	this->ErrorMessage = ErrorMessage;
};
const char * ExeptionHandler::what() const throw () {
	std::cout << this->ErrorMessage << std::endl;
	return this->ErrorMessage;
};
