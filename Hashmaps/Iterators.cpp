#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


int main()
{
	unordered_map<string, int> ourmap;

	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 2;

	// find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;

	if (ourmap.count("ghi"))
	{
		cout << "ghi is present" << endl;
	}

	unordered_map<string, int>::iterator it = ourmap.begin();
	while (it != ourmap.end())
	{
		cout << "Key : " << it->first << "Value : " << it->second << endl;
		it++;
	}

	unordered_map<string, int>::iterator it2 = ourmap.find("abc");
	ourmap.erase(it2, it2 + 4);
}