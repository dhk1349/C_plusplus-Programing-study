#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compares(const long double& var1, const long double& var2) {
	int var1_1 = var1;
	int var2_1 = var2;
	long double var1_2 = var1 - var1_1;
	long double var2_2 = var2 - var2_1;
	if (var1_1 > var2_1) { return true; }
	else if (var1_1 < var2_1) { return false; }
	else { if (var1_2 < var2_2) { return true; } else { return false; } }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<string> hashtable;
	vector<int> hash;
	vector<vector<long double>>playlists;
	vector<int> ans = {};
	long double key = -999;
	for (int i = 0; i < genres.size(); i++) {
		int Found = -1;
		for (int j = 0; j < hashtable.size(); j++) {
			if (hashtable[j] == genres[i]) {
				Found = j;
				break;
			}
		}

		if (Found == -1) {
			key = i / 100000.0;
			hashtable.push_back(genres[i]);
			hash.push_back(plays[i]);
			vector<long double>tmp = { plays[i] + key };
			playlists.push_back(tmp);
		}
		else {
			key = i / 100000.0;
			hash[Found] += plays[i];
			playlists[Found].push_back(plays[i] + key);
		}
	}
	//hash에 장르별 총 재생횟수 저장
	/**
	for (int i = 0; i < hashtable.size(); i++) {
		cout << hashtable[i] << ": " << hash[i] << endl;
		cout << "plays: ";
		for(int j=0;j< playlists[i].size();j++){
			cout<<fixed;
			cout.precision(5);
			cout << playlists[i][j] << " ";
		}
		cout << endl;
	}*/
	//큰 장르부터 선택
	int max = 0;
	int maxidx = -1;
	int cnt = 0;

	for (int i = 0; i < hashtable.size(); i++) {//to make sure every genre takes its turn.
		max = -1;
		for (int j = 0; j < hash.size(); j++) {
			if (hash[j] > max) {
				max = hash[j]; maxidx = j;
			}
		}
		hash[maxidx] = -1;
		sort(playlists[maxidx].begin(), playlists[maxidx].end(), compares);
		for (int k = 0; k < playlists[maxidx].size(); k++) {
			cnt++;
			/*
			cout << fixed;
			cout.precision(10);
			cout << int((playlists[maxidx][k]-int(playlists[maxidx][k]))* 100000+0.1) << " ";
			cout << endl;*/
			ans.push_back(int((playlists[maxidx][k] - int(playlists[maxidx][k])) * 100000 + 0.1));
			if (playlists[maxidx].size() == 1) { cnt = 0; break; }
			if (cnt == 2) { cnt = 0; break; }
		}
	}
	return ans;
}


int main() {
	vector<string> input3 = { "classic", "pop", "classic", "classic", "pop" };
	vector<int>input3_plays = { 500, 600, 150, 800, 2500 };
	vector<int> ans;
	ans = solution(input3, input3_plays);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
