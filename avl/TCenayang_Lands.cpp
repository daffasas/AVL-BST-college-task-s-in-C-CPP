
// merupakan problem https://tlx.toki.id/problems/osn-2005/C
// jawaban didapat dari salah satu submission

#include<bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int answer = INT_MAX;
	bool check;
	
	int N;
	
	cin >> N;
	
	pair<int, int> xy[N];
	
	for(int i = 0; i < N; ++i){
		
		cin >> xy[i].first >> xy[i].second;
		
	}
	
	for(int i = 0; i < N - 2; ++i){
		
		for(int j = i + 1; j < N - 1; ++j){
			
			for(int k = j + 1; k < N; ++k){
				
				int x_1 = xy[i].first * xy[j].second;
				int x_2 = xy[i].second * xy[k].first;
				int x_3 = xy[j].first * xy[k].second;
				int y_1 = xy[i].second * xy[j].first;
				int y_2 = xy[i].first * xy[k].second;
				int y_3 = xy[j].second * xy[k].first;	
				
				int answer2 = abs(x_1 + x_2 + x_3 - y_1 - y_2 - y_3);
				
				if(answer2 > 0 && answer2 < answer){
					
					answer = answer2; 
					check = true;
					
				}
				
				else if(answer2 == answer) check = false;
				
			}
			
		}
		
	}
	
	if(check && answer != INT_MAX){
		
		if(answer % 2 == 0) cout << answer / 2 << ".00" << endl;
		
		else cout << answer / 2 << ".50" << endl;
		
	}
	
	else cout << "-1.00" << endl;
	
	return 0;
}
