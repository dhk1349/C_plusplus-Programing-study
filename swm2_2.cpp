#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//2
int main() {
	int m, n, x, y;
	cin >> m >> n;
	vector<vector<int>> players;
	vector<int>player;
	vector<vector<int>> team;
	for (int i = 0; i < m; i++) {
		player.clear();
		cin >> x >> y;
		player.push_back(x);
		player.push_back(y);
		players.push_back(player);
	}
	cout << "plaers\n";
	for (int i = 0; i < players.size(); i++) {
		cout << players[i][0] << ", " << players[i][1] << endl;
	}

	int found = -1;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x -= 1;
		y -= 1;
		found = -1;
		for (int j = 0; j < team.size(); j++) {
			for (int k = 0; k < team[j].size(); k++) {
				if (x == team[j][k] || x == team[j][k]) {
					//j팀에 속해있다는 뜻
					found = j;
				}
			}
		}
		if (found != -1) {
			team[found].push_back(x);
			team[found].push_back(y);
		}
		else {
			//새로운 팀 추가
			player.clear();
			player.push_back(x);
			player.push_back(y);
			team.push_back(player);
		}
	}

	//팀별로 중복 제거
	for (int i = 0; i < team.size(); i++) {
		sort(team[i].begin(), team[i].end());
		team[i].erase(unique(team[i].begin(), team[i].end()), team[i].end());
	}


	for (int i = 0; i < team.size(); i++) {
		cout << "TEAM" << i << endl;
		for (int j = 0; j < team[i].size(); j++) {
			cout << team[i][j] << " ";
		}
		cout << endl;
	}

	vector<int>Area;
	int x_h, x_l, y_h, y_l;
	for (int i = 0; i < team.size(); i++) {
		x_h = 0, x_l = 10000000, y_h = 0, y_l = 10000000;
		for (int j = 0; j < team[i].size(); j++) {
			//x
			if (x_h < players[team[i][j]][0]) {
				x_h = players[team[i][j]][0];
			}
			if (x_l > players[team[i][j]][0]) {
				x_l = players[team[i][j]][0];
			}
			if (y_h < players[team[i][j]][1]) {
				y_h = players[team[i][j]][1];
			}
			if (y_l > players[team[i][j]][1]) {
				y_l = players[team[i][j]][1];
			}

		}
		cout << "TEAM" << i << x_h << ", " << x_l << ", " << y_h << ", " << y_l << endl;
		Area.push_back(2*(x_h - x_l) + 2*(y_h - y_l));
	}
	cout << *max_element(Area.begin(), Area.end());
	return 0;
}