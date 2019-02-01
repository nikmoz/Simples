#include "TagElement.h"
TagElement::TagElement(TagElement* parent, std::string name){
	TagElement::parent = parent;
	TagElement::name = name;
};