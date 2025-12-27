#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    string home, away;
    cin >> home >> away;
    
    int n;
    cin >> n;
    
    map<pair<string, int>, int> yellow_cards;
    set<pair<string, int>> sent_off;
    
    for (int i = 0; i < n; i++) {
        int t, m;
        char team, card;
        cin >> t >> team >> m >> card;
        
        string team_name = (team == 'h') ? home : away;
        pair<string, int> player = {team_name, m};
        
        if (sent_off.count(player)) continue;
        
        if (card == 'y') {
            yellow_cards[player]++;
            if (yellow_cards[player] == 2) {
                cout << team_name << " " << m << " " << t << endl;
                sent_off.insert(player);
            }
        } else {
            cout << team_name << " " << m << " " << t << endl;
            sent_off.insert(player);
        }
    }
    
    return 0;
}