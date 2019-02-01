#pragma once
#include <list>
class Element {
public:
	Element* parent;
	std::list<Element*> children;
};