#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";

    int length = scores.size();
    int sum=0;
    double avg=0;
    int big =0 , small =100;
    int isOnlyBigOrSmall = false;
    for (int j =0 ; j<length ; j++){
        big =scores[j][j];
        small = scores[j][j];
        int isOnlyOne = true;
        sum = scores[j][j];

        for(int i=0 ; i<length; i++){
            if( i==j) continue;
            sum += scores[i][j];
            if (big <scores[i][j]) big =scores[i][j];
            if (small >scores[i][j]) small =scores[i][j];
            if (scores[j][j] == scores[i][j]) isOnlyOne=false;
        }
        
        if(isOnlyOne &&(big ==scores[j][j] || small ==scores[j][j])){
            sum -= scores[j][j];
            avg=(double)sum/ (double)(length-1);
        }else{
            avg=(double)sum / (double)length;
        }
        
        if(avg >=90.0){
            answer+='A';
        }else if(avg>=80.0){
            answer+='B';
        }else if(avg>=70.0){
            answer+='C';
        }else if(avg>=50.0){
            answer+='D';
        }else{
            answer+='F';
        }
    }
    return answer;
}