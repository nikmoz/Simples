#pragma once
#include<string>
#include <iostream>
#include <fstream>
#include <regex>
#include <stack>
#include "TagElement.h"
#include "ExeptionHandler.h"
class DOMParser {
public:
	TagElement* Root;
	TagElement* CurrentElement;
	std::stack<std::string> Tags;
	TagElement* StartParsing(std::string FileName);
	void FoundStart(std::string Tag);
	void FoundEnd(std::string Tag);
	void Found—ontent(std::string —ontent);
};

