#include <iostream>
#include <vector>
#include<set>
using namespace std;
//Connected Component

int checker(vector<vector<int>>& container, int N, int& cnt, int row, vector<int>& checklist, vector<int>& hist) {
	/*
	cout << "=====================\n";
	for (int i = 0; i < checklist.size(); i++) {
		cout << checklist[i] + 1 << " ";
	}
	*/
	checklist.pop_back();

	//cout << endl;
	for (int j = 0; j < N; j++) {
		if (container[row][j] == 1) {
			container[row][j] = 2;
			container[j][row] = 2;
			/*
			for (int i = 0; i < checklist.size(); i++) {
				if (checklist[i]==j){
					goto next;
				}
			}*/
			//cout << "checklist pushback " << j+1 << " ";
			checklist.push_back(j);
			//next:;
		}
	}
	if (checklist.empty() == true) {
		//cout << "cnt added" << endl;
		cnt++;
		for (int i = 0; i < hist.size(); i++) {
			if (hist[i] == 1) {
				/*
				cout << "hist not empty :";
				for (int i = 0; i < hist.size(); i++) {
					if (hist[i] == 1) { cout << i + 1 << " "; }
				}
				cout << endl;
				cout << "checklist pushback " << i+1 << " ";
				*/
				checklist.push_back(i);
				goto recur;

			}
		}
		return cnt;
	}
	else {//if checklist not empty
	recur:
		hist[checklist[checklist.size() - 1]] = 0;
		//cout << "going to " << checklist[checklist.size() - 1]+1 << endl;
		checker(container, N, cnt, checklist[checklist.size() - 1], checklist, hist);
	}
}

int main() {
	int N, M, a, b, cnt = 0;
	vector<vector<int>> container;
	cin >> N >> M;
	//filling matrix with 0
	for (int i = 0; i < N + 2; i++) {
		vector<int > row(N + 2, 0);
		container.push_back(row);
	}
	//filling edge data
	set <int> node;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		node.insert(a);
		node.insert(b);
		container[b - 1][a - 1] = 1;
		container[a - 1][b - 1] = 1;
	}
	/*
	for (int i = 0;i<container.size(); i++) {
		for(int j=0;j<container[i].size();j++){
			cout << container[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int row = 0;
	vector<int> checklist;
	checklist.push_back(0);
	vector<int> hist(N, 1);
	hist[0] = 0;

	cout << checker(container, N, cnt, row, checklist, hist) << endl;

	return 0;
}