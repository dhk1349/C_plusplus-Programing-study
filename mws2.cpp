#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
//2

int checker(vector<vector<int>> &graph, int row, int col) {
	if (graph[row][col] == 2) { return 0; }
	vector<int> left_up_th, left_bo_th, right_up_th,right_bo_th;
	left_up_th = { max(0,row - 1), max(0,col-1) };
	right_bo_th = { min(int(graph.size()) - 1, row + 1),min(col+1, int(graph[0].size()-1))};

	left_bo_th = { min(int(graph.size()) - 1, row + 1) ,max(0,col - 1) };
	right_up_th = { max(0,row - 1),min(col + 1, int(graph[0].size()-1)) };
	//�ش� ��ǥ�� �߽����� �ֺ� ĭ���� ������ ����

	/*
	cout << left_up_th[0] << left_up_th[1]<<endl;
	cout << right_bo_th[0] << right_bo_th[1]<<endl;
	cout << left_bo_th[0] << left_bo_th[1] << endl;
	cout << right_up_th[0] << right_up_th[1] << endl;
	*/
	//���� �� �κ�
	//2*2���� Ȯ�� �� ��� 1���� Ȯ��
	bool result;
	if (col - left_up_th[1] == 1 && row - left_up_th[0] == 1) {
		result = true;
		for(int i=left_up_th[0];i<=row;i++){
			for (int j = left_up_th[1];j<=col;j++) {
				if (graph[i][j] == 0) { result = false;}
			}
		}
		if (result == true) {
			//Ÿ�� ĥ�ϱ� ����
			for (int i = left_up_th[0]; i <= row; i++) {
				for (int j = left_up_th[1]; j <= col; j++) {
					graph[i][j] = 2;
				}
			}
			//cout << row << ", " << col << " left up\n";
			return 0;
		}		
	}
	//���� �Ʒ� �κ�
	if(col - left_bo_th[1] == 1 && left_bo_th[0]-row == 1){
		result = true;
		for (int i = row; i <= left_bo_th[0]; i++) {
			for (int j = left_bo_th[1]; j <= col; j++) {
				if (graph[i][j] == 0) { result = false; }
			}
		}
		if (result == true) {
			//Ÿ�� ĥ�ϱ� ����
			for (int i = row; i <= left_bo_th[0]; i++) {
				for (int j = left_bo_th[1]; j <= col; j++) {
					graph[i][j] = 2;
				}
			}
			//cout << row << ", " << col << " left bo\n";
			return 0;
		}
	}

	//������ �� �κ�
	if (right_up_th[1] -col== 1 && row- right_up_th[0] == 1) {
		result = true;
		for (int i = right_up_th[0]; i <= row; i++) {
			for (int j = col; j <=right_up_th[1]; j++) {
				if (graph[i][j] == 0) { result = false; }
			}
		}
		if (result == true) {
			//Ÿ�� ĥ�ϱ� ����
			for (int i = right_up_th[0]; i <= row; i++) {
				for (int j = col; j <=right_up_th[1]; j++) {
					graph[i][j] = 2;
				}
			}
			//cout << row << ", " << col << " right up\n";
			return 0;
		}
	}

	//������ �Ʒ� �κ�
	if (right_bo_th[1] - col == 1 && right_bo_th[0] - row == 1) {
		result = true;
		for (int i = row; i <= right_bo_th[0]; i++) {
			for (int j = col; j <= right_bo_th[1]; j++) {
				if (graph[i][j] == 0) { result = false; }
			}
		}
		if (result == true) {
			//Ÿ�� ĥ�ϱ� ����
			for (int i = row; i <= right_bo_th[0]; i++) {
				for (int j = col; j <= right_bo_th[1]; j++) {
					graph[i][j] = 2;
				}
			}
			//cout << row << ", " << col << " right bo\n";
			return 0;
		}
	}
	return 1;
}

int main() {
	int tc,m,n;
	int tmp;
	vector<int> row;
	vector<vector<int>>graph;
	cin >> tc;
	for(int i=0;i<tc;i++){
		graph.clear();

		//�׷��� �����
		cin >> n >> m;
		for (int j = 0;j<n; j++) {
			//inset row
			row.clear();
			for(int k=0;k<m;k++){
				//make row
				cin >> tmp;
				row.push_back(tmp);
			}
			graph.push_back(row);
		}
		
		//�׷����� ��ȸ�ϸ鼭 ��ĥ
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				checker(graph, a, b);
			}
		}
		bool result = true;
		for (int h = 0; h < graph.size(); h++) {
			for (int b = 0; b < graph[h].size(); b++) {
				if (graph[h][b] == 1) { result = false; }
			}
		}
		if (result) { cout << "YES\n"; }
		else { cout << "NO\n"; }
	}
	return 0;
}

/*
for(int h=0;h<graph.size();h++){
			for(int b=0;b<graph[h].size();b++){
				cout << graph[h][b] << " ";
			}
			cout << endl;
		}
*/