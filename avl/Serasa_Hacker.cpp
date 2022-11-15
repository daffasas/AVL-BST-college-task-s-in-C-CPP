#include<bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;



int main(){
	
 	ull angka_n;
 	
 	set<ull> hack;
 	
 	while(scanf("%llu", &angka_n) != EOF){
 		
 		if(hack.count(angka_n)){
 			
 			ull ans = ; //CARI ANS-NYA!!! // angka ini random dari 1 - 10000
 						// clue bonus: angka diatas 5000
 			ull x = angka_n % 10001;
			if(x < ans) printf("<\n");
			if(x ==ans) printf("==\n");
			if(x > ans) printf(">\n");
 			
		 }
 		
 		else hack.insert(angka_n);
 		
	 }
 	

	return 0;
}
