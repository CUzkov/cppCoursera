#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <iomanip>


struct Year
{
    int year;
};

struct Mounth
{
    int mounth;
};

struct Day
{
    int day;
};

class Date
{

public:

    explicit Date(const Year& year, const Mounth& mounth, const Day& day) {
        _year = year;
        _mounth = mounth;
        _day = day;
    }

    std::string getDate() const {

        std::stringstream ss;

        ss << std::setfill('0') 
            << std::setw(4) << _year.year
            << '-' << std::setw(2) << _mounth.mounth
            << '-' << std::setw(2) << _day.day;

        return ss.str();

    }

private:

    Year _year;
    Mounth _mounth;
    Day _day;

};

bool operator<(const Date& lhs, const Date& rhs) {

    if(lhs.getDate() < rhs.getDate())
        return true;
    else
        return false;

}

class DataBase
{

public:

void realiseCommand(const std::string& command) {

    std::stringstream ss(command);
    std::string buffer1 = "", buffer2 = "";

    ss >> buffer1;

    try
    {
        
        if(buffer1 == "Add") {
            
            ss >> buffer1 >> buffer2;
            addEvent(buffer1, buffer2);
            
        }
        else if(buffer1 == "Del") {
            
            ss >> buffer1;
            
            if(!ss.eof()) {
                ss >> buffer2;
            }

            delEVent(buffer1, buffer2);

        }
        else if(buffer1 == "Find") {
            
            ss >> buffer1;
            findEvent(buffer1);

        }
        else if(buffer1 == "Print")
            printAll();
        else
            throw std::domain_error("Unknown command: " + buffer1);


    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        exit(0);
    }
    
}

private:

    std::map<Date, std::set<std::string>> DB;

    Date parseDate(const std::string& date) const {

        int year = 0, mounth = 0, day = 0;
        std::stringstream ss;

        ss << date;

        if(!(ss >> year 
            && ss.peek() == '-' 
            && ss.ignore(1) 
            && ss >> mounth 
            && ss.peek() == '-' 
            && ss.ignore(1) 
            && ss >> day 
            && ss.eof())) {

            throw std::invalid_argument("Wrong date format: " + ss.str());

        }

        if(mounth <= 0 || mounth >12)
            throw std::invalid_argument("Month value is invalid: " + std::to_string(mounth));

        if(day <= 0 || day > 31)
            throw std::invalid_argument("Day value is invalid: " + std::to_string(day));

        ss.clear();

        return Date(Year{year}, Mounth{mounth}, Day{day});

    }

    void addEvent(const std::string& date, const std::string& event) {
            DB[parseDate(date)].insert(event);
    }

    void printAll() const {

        for(const auto& [key, vaule] : DB)
        {

            for(const auto& el : vaule)
            {
                std::cout << key.getDate() << ' ' << el << std::endl;
            }

        }

    }

    void delEVent(const std::string& date, const std::string& event) {

        if(event == "") {
        
            try
            {
                auto val = DB.at(parseDate(date));
                int N = DB[parseDate(date)].size();
                DB.erase(parseDate(date));
                std::cout << "Deleted " << N << " events" << std::endl;
            }
            catch(const std::out_of_range& e)
            {
                std::cout << "Deleted 0 events" << '\n';
            }

        }
        else
        {
            
            try
            {
                auto val = DB.at(parseDate(date));
                
                if(DB[parseDate(date)].count(event) != 0) {
                    
                    DB[parseDate(date)].erase(event);

                    if(DB[parseDate(date)].empty())
                        DB.erase(parseDate(date));

                    std::cout << "Deleted successfully" << std::endl;

                }
                else
                {
                    std::cout << "Event not found" << std::endl;
                }

            }
            catch(const std::exception& e)
            {
                std::cout << "Event not found" << '\n';
            }
            
        }
        
    }

    void findEvent(const std::string& date) const {

        try
        {
            auto val = DB.at(parseDate(date));

            for(const auto& el : DB.at(parseDate(date)))
            {
                std::cout << el << std::endl;
            }

        }
        catch(const std::out_of_range& e)
        {

        }

    }

};

int main(int argc, char const *argv[])
{
    
    DataBase f;
    std::string buff;

    try
    {
        while (getline(std::cin, buff))
        {
            if(buff == "")
                continue;

            f.realiseCommand(buff);    
        }
    }
    catch(const std::domain_error& e)
    {
        std::cout << e.what() << '\n';
        return 0;
    }
    

    return 0;
}
