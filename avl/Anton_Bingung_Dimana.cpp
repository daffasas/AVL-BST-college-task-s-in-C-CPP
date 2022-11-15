#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    string query;
    int n;
    cin >> n;
    
    vector<string> dir = {"home","anton"};
    
    while(n--){ //perulangan sebanyak int n
    	
        cin >> query; //masuk jumlah query
        
        if(query == "goto"){
        	
        	string next;
            cin >> next;
            dir.push_back(next); //push back next
            
        }
		
		
		else if(query == "goback"){
			
            if(dir.size() == 0){
            	
                cout << "cannot go back" << endl;
                
            }
			
			else{
				
                dir.pop_back(); //di pop back
                
            }
            
        }
		
		else if(query == "whereami"){
			
            if(dir.size() == 0){
               	cout << "i am nowhere" << endl;
            }
			
			else{
				
                for(unsigned i = 0; i < dir.size(); ++i){
                    cout << dir[i];
                    if(i != dir.size()-1) cout << "/";
                    
                }
                
                cout << endl;
            }
            
        }
		
		else {
			
        	cout << "Query not found" << endl;
		}
		
    }
    
    return 0;
}