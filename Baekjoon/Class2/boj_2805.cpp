//https://www.acmicpc.net/problem/2805
#include<iostream>
#include<algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(){
    // input
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[n+1] = {0};
    for(int i =0; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    // ����
    sort(arr, arr+n, desc);

    // ������ ���̸� ���Ѵ�. diff�� i��°�� ���� i�� i+1���� ����
    int diff[n];
    for(int i =0 ; i< n ; i++){
        diff[i] = arr[i] - arr[i+1];
    }

    // ���� ū�������� �������������� �����Ѵ�.
    int height = arr[0];
    for(int i =0 ; i< n ; i++){
        // �̹� ì�⸸ŭ ì������ ������
        if( m<=0 ){         
            break;
        }
        //i������ i+1������ ���̰� ���ٸ�
        if(diff[i] == 0){   
            continue;
        }
        //���������� ũ�Ⱑ ���� �ʴٸ�
        else{              
            // i+1�� ������ġ���� �ڸ��� �߸��� ������ ����
            // �̼��� �̿��Ͽ� m���� ���°ų� ���ݳѾ�� ������ �ڸ����� ����͸� �߶���ϴ��� ���Ѵ�.
            int cnt = m%(i+1)? (m/(i+1))+1: (m/(i+1));     
            cnt = cnt<= diff[i] ? cnt : diff[i];
            // ���ϸ� �� ����ŭ �ڸ���
            height -= cnt; 
            m -= cnt * (i+1);
        }
    }

    cout << height<< endl;
}