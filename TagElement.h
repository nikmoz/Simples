#pragma once
#include "Element.h"
#include<string>
#include<vector>
class TagElement
{
public:
	TagElement* parent;
	std::vector<TagElement*> children;
	TagElement(TagElement* parent, std::string name);
	std::string name;
	std::string InnerText;
};

