#pragma once
#include <set>
#include <math.h>
class FindSimple
{
private:
	bool IsSimple(unsigned int i);
public:
	static std::set<unsigned int> simples;
	unsigned int low = 0;
	unsigned int high = 0;
	FindSimple(unsigned int low, unsigned int high);
	void FindSimples();
};

