#include <iostream>
#include <fstream>
#include <vector>
// I have used rapidxml library to parse XML, so downloaded latest version and used it as below//
#include "C:/Users/A/Downloads/rapidxml-1.13/rapidxml-1.13/rapidxml_utils.hpp"
using namespace std;
using namespace rapidxml;


xml_document<> doc;
xml_node<>* root_node = NULL;

int main(void)
{
	cout << "Conversion from XML" << endl;

	ifstream file("C:/Users/A/Downloads/cd_catalog1.xml");

	vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer
	doc.parse<0>(&buffer[0]);

	// Find out the root node
	root_node = doc.first_node("CATALOG");  // ROOT NODE

	// Iterate over the CD nodes
	for (xml_node<>* cd_node = root_node->first_node("CD"); //HEAD NODE
		cd_node; cd_node = cd_node->next_sibling())
	{
		//SUB NODES
		xml_node<>* title_node = cd_node->first_node("TITLE");
		xml_node<>* artist_node = cd_node->first_node("ARTIST");
		xml_node<>* company_node = cd_node->first_node("COMPANY");
		xml_node<>* country_node = cd_node->first_node("COUNTRY");
		xml_node<>* price_node = cd_node->first_node("PRICE");
		xml_node<>* year_node = cd_node->first_node("YEAR");


	    cout << "TITLE is = " << title_node->value()<<endl;
		cout << "ARTIST is = " << artist_node->value()<<endl;
		cout << "COMPANY is = " << company_node->value()<<endl;
		cout << "COUNTRY is = " << country_node->value()<<endl;
		cout << "PRICE is = " << price_node->value()<<endl;
		cout << "YEAR is = " << year_node->value()<<endl;

		cout << endl; 
	}
	return 0;
}