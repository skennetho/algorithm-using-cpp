//https://www.acmicpc.net/problem/1931
//회의실 배정
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define Meeting pair<int,int>
#define MeetingList vector<Meeting>

using namespace std;

bool compare(Meeting a, Meeting b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first< b.first;
}

bool compareByEnd(Meeting a, Meeting b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int findMeetingAvailableAfterTime(MeetingList& list, int time) {
    int mid;
    int begin = 0, end = list.size();

    while (begin < end) {
        mid = (begin + end) / 2;
        if (list[mid].first >= time) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    return end;
}

void dfs(MeetingList& list, vector<bool>& visited, int timeBefore, int count, int& best) {
    int index = findMeetingAvailableAfterTime(list, timeBefore);
    if (index >= list.size()) {
        if (count > best) 
            best = count;
        return;
    }

    for (int i = findMeetingAvailableAfterTime(list, timeBefore) ; i < list.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(list, visited, list[i].second, count+1, best);
        visited[i] = false;
    }
}

void solveWithDFS(MeetingList& meetingList) {
    vector<bool> visited(meetingList.size(), false);

    sort(meetingList.begin(), meetingList.end(), compare);
    int best = 0;
    dfs(meetingList, visited, 0, 0, best);
    printf("%d", best);
}

int main() {
    MeetingList meetingList;
    int n;
    scanf("%d", &n);
    
    int beginTime, endTime;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &beginTime, &endTime);
        meetingList.emplace_back(make_pair(beginTime, endTime));
    }

    // solveWithDFS(meetingList);
    sort(meetingList.begin(), meetingList.end(), compareByEnd);
    int now = meetingList[0].second;
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(now <= meetingList[i].first){
            count++;
            now = meetingList[i].second;
        }
    }
    printf("%d", count);
}