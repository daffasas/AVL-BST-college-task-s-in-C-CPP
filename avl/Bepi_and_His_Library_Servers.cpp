#include <bits/stdc++.h>

using namespace std;

map<string, string> serverData;
map<string, vector<string> > servers;
map<string, vector<int> > lantai;

vector<int>::iterator lowBound;
map<string, vector<string> >::iterator bukuIt;
map<string, vector<int> >::iterator lantaiIt;


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string ipServer, namaBuku;
	int namaLantai, selisih, sum = 0;
	bool check;
	int N, banyakBuku, computerBound;
	
	cin >> N;
	
	for(int i = 0; i < N; ++i){
		
		cin >> ipServer >> banyakBuku >> namaLantai;
		
		for(int i = 0; i < banyakBuku; ++i){
			
			cin >> namaBuku;
			servers[namaBuku].push_back(ipServer);
			lantai[namaBuku].push_back(namaLantai);
			
		}
		
	}
	
	for(bukuIt = servers.begin(); bukuIt != servers.end(); ++bukuIt){
		
		sort(bukuIt->second.begin(), bukuIt->second.end());
		
		for(int i = 0; i < bukuIt->second.size(); ++i){
			
			if(i) serverData[bukuIt->first] += '|';
			serverData[bukuIt->first] += bukuIt->second[i];
			
		}
		
	}
	
	for(lantaiIt = lantai.begin(); lantaiIt != lantai.end(); ++lantaiIt){
		
		sort(lantaiIt->second.begin(), lantaiIt->second.end());
		
	}
	
	int M;
	
	cin >> M;
	
	for(int i = 1; i <= M; ++i){
		
		check = true;
		
		cin >> banyakBuku >>  namaLantai;
		
		set<int> floorSet;
		
		priority_queue< pair<int, string>, vector< pair<int, string> >, greater< pair<int, string> > > bookPq;
		
		for(int j = 0; j < banyakBuku; ++j){
			
			cin >> namaBuku;
			
			if(servers.count(namaBuku)){
				
				computerBound = servers[namaBuku].size();
				lowBound = lower_bound(lantai[namaBuku].begin(), lantai[namaBuku].end(), namaLantai);
				
				if(lowBound == lantai[namaBuku].begin()) selisih = abs(*lowBound - namaLantai);
				
				else if(lowBound == lantai[namaBuku].end()) selisih = abs(*(lowBound - 1) - namaLantai);
				
				else selisih = min(abs(*lowBound - namaLantai), abs(*(lowBound - 1) - namaLantai));
				
				for(int k = 0; k < computerBound; ++k){
					
					floorSet.insert(lantai[namaBuku][k]);
					
				}
				
				bookPq.push(make_pair(selisih, namaBuku));
				
			}
			
			else check = false;
			
		}
			
			if(check){
				
				cout << "Client " << i;
            	cout << " got what they need\n";
            	
            	while(!bookPq.empty()){
				
					cout << bookPq.top().second << ' ';
					cout << serverData[bookPq.top().second] << '\n';
					bookPq.pop();
				
				}
	            
        	}
        	
        	else {
            	
            	cout << "As Client " << i;
	            cout << " is unable to find the needed data, they went to the competitor instead :(\n";
			
			}
	
		
		sum = sum + floorSet.size();
		
	}
	
	cout << "Number of connections: " << sum << '\n';
	
	return 0;
}
