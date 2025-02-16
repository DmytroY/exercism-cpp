#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

// Round down all provided student scores.
// std::vector<double> student_scores {90.3, 40.5, 55.4, 70.5, 30.5, 25.4, 80.4, 95.3, 38.7, 40.3};
// round_down_scores(student_scores) => {90, 40, 55, 70, 30, 25, 80, 95, 38, 40}
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> scores(student_scores.size());
    for (int i = 0; i < student_scores.size(); i++) {
        scores[i] = static_cast<int>(student_scores[i]);
    }
    return scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count{0};
    for (int item : student_scores) {
        if (item <= 40) {
            count++;
        }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int, 4> grades{41, 0, 0 , 0};
    int step = (highest_score - 40) / 4;
    for (int i = 1; i < 4; i++) {
        grades[i] = grades[i-1] + step;
    }
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking;
    for (int i = 1; i <= student_scores.size(); i++){
        ranking.push_back( std::to_string(i) + ". " + student_names[i-1] + ": " + std::to_string(student_scores[i-1]));
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
// perfect_score({"Nur", "Tony", "Fatima"}, {90, 80, 100}) => "Fatima"
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    auto pointer = std::find(student_scores.begin(), student_scores.end(), 100);
    if (pointer != student_scores.end()) {
        int index = std::distance(student_scores.begin(), pointer);
        return student_names[index];
    }
    return "";
}
