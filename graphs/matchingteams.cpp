#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <memory>

using namespace std;

struct matchResult {
    string winning_team; 
    string losing_team;
};



bool CanBeatTeamABeatTeamB(const vector<matchResult> &mathches, const string& teamA, const string& teamB) { 
    return IsReachableDFS(BuidlGraph(matches), teamA, teamB, make_unique<unordered_set<string>>().get());

}

bool IsReachableDFS(const unordered_map<string, unordered_set<string> >& graph, const string& curr, const string& dest, unordered_set<string>* visited_ptr) {
    unordered_set<string>& visited = *visited_ptr;
    if (curr == dest) {
        return true;
    }
    else if (visited.count(curr) || !graph.count(curr)) {
        return false; 
    }
    visited.insert(curr);
    const unordered_set<string>&team_list = graph.at(curr);
    return any_of(begin(team_list), end(team_list), [&](const string& team) {
        return IsReachableDFS(graph,team, dest, visited_ptr);
    });
}

