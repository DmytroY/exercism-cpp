#include <string>
#include <vector>

namespace election {

    // The election result struct is already created for you:

    struct ElectionResult {
        // Name of the candidate
        std::string name{};
        // Number of votes the candidate has
        int votes{};
    };

    // TODO: Task 1
    // vote_count takes a reference to an `ElectionResult` as an argument and will
    // return the number of votes in the `ElectionResult.
    // ElectionResult hamilton{"Alex", 1804};
    // vote_count(hamilton) => 1804
    int vote_count(ElectionResult& er) {return er.votes;}

    // TODO: Task 2
    // increment_vote_count takes a reference to an `ElectionResult` as an argument
    // and a number of votes (int), and will increment the `ElectionResult` by that
    // number of votes.
    void increment_vote_count(ElectionResult& er, int new_votes) {er.votes += new_votes;}

    // TODO: Task 3
    // determine_result receives the reference to a final_count and returns a
    // reference to the `ElectionResult` of the new president. It also changes the
    // name of the winner by prefixing it with "President". The final count is given
    // in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
    // `ElectionResults` of all the participating candidates.
    //
    // ElectionResult sanchez{"Pedro", 471};
    // ElectionResult wheatley{"Summer", 340};
    // std::vector<ElectionResult> final_count{sanchez, wheatley};
    // ElectionResult& winner = determine_result(final_count);
    // winner.name => "President Pedro"
    ElectionResult& determine_result(std::vector<ElectionResult>& final_count){
        int winner_index = 0;
        int winner_votes = final_count[0].votes;
        for (int i = 1; i < final_count.size(); i++) {
            if (final_count[i].votes > winner_votes) {
                winner_index = i;
                winner_votes = final_count[i].votes;
            }     
        }
        final_count[winner_index].name = "President " + final_count[winner_index].name;
        return final_count[winner_index];
    }

}  // namespace election