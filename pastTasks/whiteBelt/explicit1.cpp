#include <string>


struct Specialization
{
    explicit Specialization(std::string str){
        value = str;
    }
    std::string value;
};

struct Week
{
    explicit Week(std::string str){
        value = str;
    }
    std::string value;
};

struct Course
{
    explicit Course(std::string str){
        value = str;
    }
    std::string value;
};

struct LectureTitle {

    explicit LectureTitle(Specialization sp, Course cr, Week wk): 
        specialization(sp.value), 
        course(cr.value), 
        week(wk.value){}

    std::string specialization;
    std::string course;
    std::string week;
};
