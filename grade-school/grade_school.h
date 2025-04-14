#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <vector>
#include <string>


namespace grade_school {

// TODO: add your solution here
    using map_roster = std::map<int, std::vector<std::string>>;
    using vector_str = std::vector<std::string>;

    class school {
        private:
            map_roster _roster;

        public:
            map_roster roster() const;
            void add(std::string, int);
            vector_str grade(int) const;
    };

}  // namespace grade_school

#endif  // GRADE_SCHOOL_H