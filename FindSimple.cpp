#include "FindSimple.h"
bool FindSimple::IsSimple(unsigned int i) {
	if (i < 2) return false;
	for (int j = 2; j <= sqrt(i); ++j)
	{
		if ((i%j == 0) && (i != j)) return false;
	}
	return true;
};
FindSimple::FindSimple(unsigned int low, unsigned int high) {
	this->low = low;
	this->high = high;
};
void FindSimple::FindSimples() {
	for (auto i = low; i <= high; ++i) {
		if ((FindSimple::simples.find(i) == FindSimple::simples.end())&&(IsSimple(i))) {
			FindSimple::simples.insert(i);
		}
	}
}