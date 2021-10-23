#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution( vector<string> list){
    bool flag = false;
    for(int i =0 ; i<list.size(); i++){
        int sum = 0;
        int o_cnt =0;

        for(char &ch : list[i]){
            if(ch == 'O'){
                o_cnt=flag? o_cnt+1: 1;
                flag = true;
                sum+=o_cnt;
            }else{
                flag = false;
            }
        }
        cout<< sum<<endl;
    }
}

int main(){
    int n;
    vector<string> list;   

    cin>> n;
    for(int i =0 ; i< n ; i++){
        string input;
        cin>> input;
        list.push_back(input);
    }
    solution( list);
}

/*모범답안
int t;
char s[81];
int main() {
	scanf("%d", &t);
	while (t--) {
		int r = 0,c=0;
		scanf("%s", s);
		for (int i = 0; s[i]; i++) s[i] == 'O' ? r += ++c : c = 0;
		printf("%d\n", r);
	}
	return 0;
}
*/