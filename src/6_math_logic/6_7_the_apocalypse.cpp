#include <iostream>

using namespace std;

void simulate(int n){
    
    int mm = 0;
    int idx = -1;
    
	int B = 0, G = 0;
	for(int i=0; i<n; i++){
		//simulate family
		int c;
		int m=0;
		cout << i << "\t";
		do{
			c = rand()%2;
			if(c==0) G++; // 0 = girl
			else {
			    B++; // 1 = boy
			    m++;   
			}
			cout << (c==0?'+':'-');
		}while(c!=0);
		if(m>mm){
		    mm = m;
		    idx = i;
		}
		cout << endl;
	}
	
	cout << "B = " << B << "\tG = "<< G << endl;
    cout << "idx = " << idx << "\tmax = " << mm << endl;
}

int main(){
	cout << "Insert number of families to simulate: " << endl;
	int n; cin >> n;
	simulate(n);


	int z; cin >> z; // wait
	return 0;
}