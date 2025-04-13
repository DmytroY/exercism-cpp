#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <vector>
#include <string>


namespace grade_school {

// TODO: add your solution here
    class school {
        private:
            std::map<int, std::vector<std::string>> _roster;

        public:
            std::map<int, std::vector<std::string>> roster() const;
            void add(std::string, int);
            // std::vector<std::string> grade(int);
    };

}  // namespace grade_school

#endif  // GRADE_SCHOOL_H