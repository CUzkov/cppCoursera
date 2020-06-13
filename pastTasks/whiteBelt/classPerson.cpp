#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>


class Person {
public:

	Person(const std::string& name, const std::string& lastName, const int& age) : _yearOfBorn(age){
		personNameHistory[age].first = name;
		personNameHistory[age].second = lastName;
	}

	std::string GetFullNameWithHistory(int year) const {

		if(year < _yearOfBorn)
			return "No person";

		std::vector<std::string> fullNameHistory;
		std::vector<std::string> fullLastNameHistory;

		for(const auto& [key, value] : personNameHistory)
		{
			if(key <= year) {
				if(value.first != "")
					fullNameHistory.push_back(value.first);
				if(value.second != "")
					fullLastNameHistory.push_back(value.second);
			}
		}

		if(fullLastNameHistory.empty() && fullNameHistory.empty()) {
			return "Incognito";
		}
		else if(fullLastNameHistory.empty() && !fullNameHistory.empty())
		{
			std::string ret = retStr(fullNameHistory);
			return ret + " with unknown last name";
		}
		else if(!fullLastNameHistory.empty() && fullNameHistory.empty())
		{
			std::string ret = retStr(fullLastNameHistory);
			return ret + " with unknown first name";
		}
		else {
			std::string ret1 = retStr(fullNameHistory);
			std::string ret2 = retStr(fullLastNameHistory);
			return ret1 + " " + ret2;
		}
  	}

	void ChangeFirstName(int year, const std::string& first_name) {
		personNameHistory[year].first = first_name;
    }

  	void ChangeLastName(int year, const std::string& last_name) {
        personNameHistory[year].second = last_name;
    }

  	std::string GetFullName(int year) const {

		if(year < _yearOfBorn)
			return "No person";

    	std::pair<std::string, std::string> fullName;

		for(const auto& [key, value] : personNameHistory)
		{
			if(key <= year) {
				if(value.first != "")
					fullName.first = value.first;
				if(value.second != "")
					fullName.second = value.second;
			}
    	}    
          
		if(fullName.first + fullName.second == "")
			return "Incognito";
		else if(fullName.first != "" && fullName.second == "")
			return fullName.first + " with unknown last name";
		else if(fullName.first == "" && fullName.second != "")
			return fullName.second + " with unknown first name";
		else
			return fullName.first + " " + fullName.second;
    
    }

private:
    std::map<int, std::pair<std::string, std::string>> personNameHistory;

	int _yearOfBorn = 0;

	std::string retStr(std::vector<std::string> v) const {

		int g = 0;

		auto last = std::unique(begin(v), end(v));
		v.erase(last, v.end());
		std::string ret = v.back() + " (";
		v.pop_back();

		for(const auto& el : v)
		{
			ret += (v.back() + ", ");
			v.pop_back();
			g++;
		}
		ret.pop_back();
		ret.pop_back();
		
		if(g != 0)
			ret += ")";
		
		return ret;

	}
};

int main() {

	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
   	}
  
   	person.ChangeFirstName(1965, "Appolinaria");
   	person.ChangeLastName(1967, "Ivanova");
   	for (int year : {1965, 1967}) {
	   std::cout << person.GetFullNameWithHistory(year) << std::endl;
   	}

  return 0;
}