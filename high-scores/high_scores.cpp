#include "high_scores.h"

#include <algorithm>

namespace arcade {

    std::vector<int> HighScores::list_scores() {
        // TODO: Return all scores for this session.
        return scores;
    }

    int HighScores::latest_score() {
        // TODO: Return the latest score for this session.
        //scores{100, 0, 90, 30};
        return scores[scores.size() - 1];
    }

    int HighScores::personal_best() {
        // TODO: Return the highest score for this session.
        return *std::max_element(scores.begin(), scores.end());
    }

    std::vector<int> HighScores::top_three() {
        // TODO: Return the top 3 scores for this session in descending order.
        int size = (scores.size() < 3) ? scores.size() : 3;
        std::vector v(size, 0);
        std::partial_sort_copy(scores.begin(), scores.end(), v.begin(), v.end(), std::greater());
        return v;
    }
}  // namespace arcade