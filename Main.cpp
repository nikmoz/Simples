#include "DOMParser.h"
#include "TagElement.h"
#include "FindSimple.h"
#include "ExeptionHandler.h"
#include <iostream>
#include <thread>
#include <set>
using namespace std;
set<unsigned int> FindSimple::simples = {};
int main()
{
	DOMParser MyParser;
	TagElement* Root;
	vector<FindSimple> simples;
	vector<thread> t;
	try {
		Root = MyParser.StartParsing("XMLFile.xml");
	}
	catch (ExeptionHandler& e) {
		e.what();
		return 0;
	}
	try {
		if (Root->children.size() != 1)
		{
			throw ExeptionHandler("Root have more than one children");
		}
		else if (Root->children[0]->name != "intervals") {
			throw ExeptionHandler("Roots doesn't contain intervals");
		}
		for (auto i : Root->children[0]->children) {
			if (i->name != "interval") {
				throw ExeptionHandler("Intervals contains wrong tag type");
			}
			else if (i->children.size() != 2)
			{
				throw ExeptionHandler("Interval contains more than two tags");
			}
			else if ((i->children[0]->name != "low") || (i->children[1]->name != "high"))
			{
				throw ExeptionHandler("Interval doesn't contains low or high tags, or contains them in wrong order");
			}
			else {
				if (i->children[0]->InnerText == "") {
					throw ExeptionHandler("Low tag has no info");
				}
				else if (i->children[1]->InnerText == "") {
					throw ExeptionHandler("High tag has no info");
				}
				else {
					unsigned int low = std::stoul(i->children[0]->InnerText);
					unsigned int high = std::stoul(i->children[1]->InnerText);
					simples.push_back(FindSimple(low, high));
				}
			}
		}
	}
	catch(ExeptionHandler& e) {
		e.what();
	}
	for (auto& r : simples)
		t.push_back(std::thread(std::bind(&FindSimple::FindSimples, &r)));
	for (auto& th : t)
		th.join();
	for (auto i = FindSimple::simples.begin(); i != FindSimple::simples.end(); ++i)
	{
		cout << *i << endl;
	}
	system("pause");
}