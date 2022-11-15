#include <bits/stdc++.h>

using namespace std; 

int main(){
	
	vector<int> hole;
	
	int N;
	
	cin >> N;
	
	int ball[N];
	
	for(int i = 0; i < N; ++i){
		
		int counter = 2;
		
		cin >> ball[i];
		
		hole.push_back(ball[i]);
		
		for(int j = hole.size(); j > 0; --j){
			
			if(ball[i] == hole[j - 2]){
				
				if(counter == ball[i]){
					
					
            		int balls_left = hole.size() - counter;
                    hole.resize(balls_left);
                    cout << balls_left << endl;
                    break;
                    
                } 
                
                counter += 1;
				
			}
			
			else{
				
				cout << hole.size() << endl;
				break;
				
			}
			
		}
		
	}
	
	
	return 0;
	
}
