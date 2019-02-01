#include "DOMParser.h"

TagElement* DOMParser::StartParsing(std::string FileName) {
	std::string TmpS;
	std::smatch matches;
	std::regex StartTag("<[a-zA-z]+>");
	std::regex EndTag("</[a-zA-z]+>");
	std::regex Ñontent("[0-9]+");
	std::ifstream myfile;
	myfile.open(FileName);
	getline(myfile, TmpS);
	while (getline(myfile, TmpS))
	{
		std::regex_search(TmpS, matches, StartTag);
		if (matches.size() != 0) {
			FoundStart(matches[0]);
		}
		regex_search(TmpS, matches, Ñontent);
		if (matches.size() != 0) {
			FoundÑontent(matches[0]);
		}
		regex_search(TmpS, matches, EndTag);
		if (matches.size() != 0) {
			FoundEnd(matches[0]);
		}
	}
	if (Tags.size() != 0) {
		throw new ExeptionHandler("Some tags aren't closed");
	};
	myfile.close();
	return Root;
};

void DOMParser::FoundStart(std::string Tag)
{
	std::smatch TagName;
	std::regex RegName("[a-zA-z]+");
	regex_search(Tag, TagName, RegName);
	Tags.push(TagName[0]);
	if (!Root) {
		Root = new TagElement(Root,TagName[0]);
		CurrentElement = Root;
	}
	else {
		TagElement* TMP = new TagElement(CurrentElement, TagName[0]);
		CurrentElement->children.push_back(TMP);
		CurrentElement = TMP;
	}
};

void DOMParser::FoundEnd(std::string Tag)
{
	std::smatch TagName;
	std::regex RegName("[a-zA-z]+");
	regex_search(Tag, TagName, RegName);
	if (Tags.top() == TagName[0]) {
		Tags.pop();
		CurrentElement = CurrentElement->parent;
	}
	else
	{
		throw new ExeptionHandler("Wrong tag order");
	}
};

void DOMParser::FoundÑontent(std::string Ñontent) {
	CurrentElement->InnerText = Ñontent;
};

