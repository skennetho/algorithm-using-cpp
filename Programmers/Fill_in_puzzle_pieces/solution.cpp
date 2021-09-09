#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <array>
#include <utility>
#include <algorithm> 
using namespace std;

/*문제: 퍼즐 조각 채우기

문제 설명
테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈 공간에 적절히 올려놓으려 합니다. 
게임 보드와 테이블은 모두 각 칸이 1x1 크기인 정사각 격자 모양입니다. 
이때, 다음 규칙에 따라 테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈칸에 채우면 됩니다.

 - 조각은 한 번에 하나씩 채워 넣습니다.
 - 조각을 회전시킬 수 있습니다.
 - 조각을 뒤집을 수는 없습니다.
 - 게임 보드에 새로 채워 넣은 퍼즐 조각과 인접한 칸이 비어있으면 안 됩니다.

 제한사항
    3 ≤ game_board의 행 길이 ≤ 50
    game_board의 각 열 길이 = game_board의 행 길이
        즉, 게임 보드는 정사각 격자 모양입니다. 
        game_board의 모든 원소는 0 또는 1입니다.
        0은 빈칸, 1은 이미 채워진 칸을 나타냅니다.
        퍼즐 조각이 놓일 빈칸은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
    table의 행 길이 = game_board의 행 길이
    table의 각 열 길이 = table의 행 길이
        즉, 테이블은 game_board와 같은 크기의 정사각 격자 모양입니다.
        table의 모든 원소는 0 또는 1입니다.
        0은 빈칸, 1은 조각이 놓인 칸을 나타냅니다.
        퍼즐 조각은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
    game_board에는 반드시 하나 이상의 빈칸이 있습니다.
    table에는 반드시 하나 이상의 블록이 놓여 있습니다.
*/


/*시도1
먼저 하나의정의를  좌표의 집합으로 하자. 그리고 조각은 각각 배치하는데 필요한 h,w배열로 표현하자.
    h,w 배열에서 퍼즐이 위치하는곳은 1 아닌곳은 0으로 두자.
    게임보드는 빈칸은 0 막힌곳은 1.

게임보드에 들어갈수 있는지 판단할때는 garo, sero 의 길이에서 h x w 배열이 들어갈수 있는 경우의 수를 모두 돌면서
    예를 들어 0,0위치에 h,w배열의 조각을 배치해본다고 하면 
    게임보드의 0<garo<0+w , 0<sero<0+h 칸에 조각배열의 원소들과 더하여 2가 나오지 않으면 들어갈 수 있는 자리라고 판단하자.

브루트포스즉 전수조사 방식으로 접근하되 아예 안되는 조각들은 pass하며 지나치자
*/




class Problem{
public:
    typedef vector<vector<int>> Board_t;
    typedef vector<vector<pair<int, int>>> BlockPieces_t ;      //i,j가 페어
    typedef vector<pair<int, int>> Block_t;
    Board_t game_board;
    Board_t table;

    void setTestCase(Board_t _game_board, Board_t _table){
        game_board  = _game_board;
        table =_table;
    }

    void solveProblem(){
        int ans= solution(game_board, table);
        cout<<"answer = "<< ans<<endl;
    }
   
   
    int solution(Board_t game_board, Board_t table) {                              //제출코드
        int answer=0;
        //빈공간을 존재하는 공간과 바꾸기
        reverseBoard(game_board);
        
        //조각 벡터로 변환
        BlockPieces_t blocks_game, blocks_table;
        blocks_game = parseBlocks(game_board);
        blocks_table = parseBlocks(table);

        //겜보드의 조각과 테이블의 조각대조하여 가장 최소값이 되는 루트 찾기 : with bfs
        vector<bool> used(blocks_game.size(), false);
        
        for(int i =0  ; i< blocks_table.size(); i++){
            int t_h = getBlockHeight(blocks_table[i]),t_w = getBlockWidth(blocks_table[i]);

            for(int j =0 ; j<used.size(); j++){
                if(used[j]) 
                    continue; 
                int g_h = getBlockHeight(blocks_game[j]), g_w = getBlockWidth(blocks_game[j]);
                if(!(t_h ==g_h && t_w == g_w) && !(t_h == g_w && t_w == g_h) ||
                    blocks_table[i].size()!= blocks_game[j].size()) 
                    continue;

                bool match=false;
                for(int rotate = 0; rotate<360; rotate+=90){
                    rotate90degree(blocks_table[i]);
                    match = matchBlockPiece(blocks_table.at(i),blocks_game.at(j));
                    if(match)         
                        break;
                }
                if(match){
                    used[j] =true;
                    answer+=blocks_table.at(i).size();
                    break;
                }
            }
        }
        return answer;
    }

    //보드 뒤집기
    void reverseBoard(Board_t &board){
        for(int i = 0 ; i< board.size() ; i++){
            for(int j = 0; j< board.size() ; j++){
                if(board.at(i).at(j) ==1 ){
                    board.at(i).at(j) =0;
                }else{
                    board.at(i).at(j)=1;
                }
            }
        }
    }

    //dfs를 사용하여 조각 데이터로 변환
    BlockPieces_t parseBlocks(Board_t board){
        BlockPieces_t blocks;
        for(int i = 0 ; i< board.size() ; i++){
            for(int j = 0; j< board.size() ; j++){
                Block_t block;
                checkAdjacent(board, block, i,j);
                //피스가 만들어졌다면 정렬 
                if(block.size() >0) {
                    sort(block.begin() , block.end());   
                    blocks.push_back(block);
                }
            }
        }
        return blocks;
    }

    void checkAdjacent(Board_t &board,Block_t &block, int i, int j){
        //board를 벗어난 곳을 가리키면 중지
        if(i>=board.size() || j>=board.size() || i<0 || j< 0){
            return;
        }
        if(board[i][j] ==0 ){
            return;
        }
        board[i][j] =0;
        block.push_back(make_pair(i,j));
        
        checkAdjacent(board,block,i-1,j);
        checkAdjacent(board,block,i+1,j);
        checkAdjacent(board,block,i,j+1);
        checkAdjacent(board,block,i,j-1);
    }

    //같은 모양의 블럭인지 판별
    bool matchBlockPiece(Block_t b1,  Block_t b2){
        if(b1.size() != b2.size())
            return false;
        if( !(getBlockWidth(b1) == getBlockWidth(b2) && getBlockHeight(b1)== getBlockHeight(b2)) &&
            !(getBlockWidth(b1) == getBlockHeight(b2) && getBlockWidth(b1)== getBlockHeight(b2)) )
            return false;
        
        int diff_i  = b1.front().first - b2.front().first;
        int diff_j  = b1.front().second - b2.front().second;

        for(int i =0; i< b1.size() ; i++){
            if( b1[i].first == b2[i].first+ diff_i && b1[i].second == b2[i].second+ diff_j){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }

    void rotate90degree(Block_t &b){
        int h_start = 50;
        int w_start = 50;
        int height = getBlockHeight(b);
        int width = getBlockWidth(b);
        int ii, jj;

        for(int i =0 ; i< b.size(); i++){  
            if(b[i].first<h_start) h_start =b[i].first;
            if(b[i].second<w_start) w_start =b[i].second;
        }

        for(int i =0 ; i< b.size(); i++){
            //대각선 대칭
            jj = b[i].first- h_start;
            ii = b[i].second - w_start;
            //좌우대칭
            jj = height -jj-1;
            b[i] = make_pair(ii+h_start,jj+w_start);
        }
        sort(b.begin() , b.end()); 
    }

    int getBlockHeight(Block_t &b){
        int start = 50, end = 0;
        for(int i=0 ; i<b.size(); i++){
            if(b[i].first<start) start =b[i].first;
            if(b[i].first>end) end = b[i].first;
        }
        return  end-start +1;
    }

    int getBlockWidth(Block_t &b){
        int start = 50, end = 0;
        for(int i=0 ; i<b.size(); i++){
            if(b[i].second<start) start =b[i].second;
            if(b[i].second>end) end = b[i].second;
        }
        return  end-start +1;    
    }

    bool comparePair(pair<int, int> const &a ,pair<int, int> const &b){
        if (a.first == b.first) 
		    return a.second < b.second;
        else 
            return a.first < b.first;
    }



    void printBoard(Board_t &board){
        for(int i = 0 ; i< board.size() ; i++){
            for(int j = 0; j< board.size() ; j++){
                if(board[i][j] ==1)
                    cout<< board[i][j]<< " ";
                else   
                    cout<< "  ";
            }
            cout<< endl;
        }
    }

    void printBoard(BlockPieces_t blocks, int boardsize){
        vector<vector<char>> board( boardsize , vector<char> (boardsize, ' '));
        for(int i =0 ; i< blocks.size(); i++ ){
            cout<<"block ("<<i<<"="<<char(i%25+65)<<")   : ";
            for(int x = 0 ; x< blocks[i].size() ; x++){
                cout<<"["<<blocks[i][x].first<<", "<<blocks[i][x].second<<"], ";
                board[blocks[i][x].first][blocks[i][x].second] = char(i%25+65);
            }
            cout<<endl;
        }
        for(int i = 0 ; i< boardsize ; i++){
            cout<< ">>    ";
            for(int j = 0; j< boardsize ; j++){
                if(board[i][j] !=0)
                    cout<< board[i][j]<< " ";
                else   
                    cout<< "  ";
            }
            cout<< endl;
        }
    }
    
    void printBoard(BlockPieces_t blocks, int boardsize, int blockNumber){
        vector<vector<char>> board( boardsize , vector<char> (boardsize, ' '));
       
        for(int x = 0 ; x< blocks[blockNumber].size() ; x++){
            board[blocks[blockNumber][x].first][blocks[blockNumber][x].second] = char('X');
        }

        for(int i = 0 ; i< boardsize ; i++){
            cout<< ">>    ";
            for(int j = 0; j< boardsize ; j++){
                cout<< board[i][j]<< " ";
            }
            cout<< endl;
        }
    }

};

 void _printBlock(Problem::Block_t block){
        Problem problem;
        int h = problem.getBlockHeight(block);
        int w = problem.getBlockWidth(block);
        int d_i = block.front().first;
        int d_j = block.front().second;
        int h_s=100, w_s=100;

        int arr[h][w] = {0};
        // for(int i =0 ; i< block.size(); i++){  
        //     if(block[i].first<h_s) h_s =block[i].first;
        //     if(block[i].second<w_s) w_s =block[i].second;
        // }
        
        for(int i =0 ; i< block.size(); i++){
            if(block[i].first<0 || block[i].second<0){
                cerr<<"out of range";
                return;
            }
            arr[block[i].first][block[i].second]= 1;  
        }

        cout<< "print Block"<<endl;
        for(int i =0 ; i< h ; i++){
            for( int j = 0; j< w ; j++){
                if(arr[i][j] ==1) cout<< "x ";
                else cout<< "  "; 
            }
            cout<<endl;
        }
    }


int main(){
    Problem problem;
    //14: pass
    vector<vector<int>> _game_board = { { 1,1,0,0,1,0 },
                                        { 0,0,1,0,1,0 },
                                        { 0,1,1,0,0,1 },
                                        { 1,1,0,1,1,1 },
                                        { 1,0,0,0,1,0 },
                                        { 0,1,1,1,0,0 }};
    vector<vector<int>> _table = {      { 1,0,0,1,1,0 },
                                        { 1,0,1,0,1,0 },
                                        { 0,1,1,0,1,1 },
                                        { 0,0,1,0,0,0 },
                                        { 1,1,0,1,1,0 },
                                        { 0,1,0,0,0,0 }};

    //73: pass
    vector<vector<int>> _game_board2 = {{0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0}, 
                                        {1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1}, 
                                        {0,1,1,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0}, 
                                        {0,0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,0}, 
                                        {0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1}, 
                                        {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0}, 
                                        {0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,0,0,1}, 
                                        {1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0}, 
                                        {0,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0}, 
                                        {1,1,0,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1}, 
                                        {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0}, 
                                        {1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0}, 
                                        {0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,0,0}, 
                                        {1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1}, 
                                        {1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0}, 
                                        {0,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0}, 
                                        {0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0}, 
                                        {0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0}};
    vector<vector<int>> _table2 =  {    {1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,0}, 
                                        {0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,1,1,0}, 
                                        {1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,1}, 
                                        {1,1,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1}, 
                                        {1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1}, 
                                        {0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,0,0}, 
                                        {1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1}, 
                                        {0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,0,0}, 
                                        {1,0,1,0,0,0,0,1,0,1,1,0,1,1,0,1,1,1}, 
                                        {1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0}, 
                                        {1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0}, 
                                        {0,0,1,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1}, 
                                        {1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1}, 
                                        {1,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1}, 
                                        {0,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0}, 
                                        {1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1}, 
                                        {0,0,0,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1}, 
                                        {0,1,1,1,1,0,0,1,0,0,1,1,0,1,0,0,1,1}}; 

    //54: pass
    vector<vector<int>> _game_board3 ={ {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, 
                                        {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, 
                                        {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}, 
                                        {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1}, 
                                        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, 
                                        {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1}, 
                                        {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, 
                                        {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}, 
                                        {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0},
                                        {0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0},
                                        {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1},
                                        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0} };
    vector<vector<int>> _table3 = {     {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}, 
                                        {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1}, 
                                        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, 
                                        {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, 
                                        {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, 
                                        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
                                        {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, 
                                        {1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, 
                                        {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1}, 
                                        {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, 
                                        {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1}, 
                                        {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1} };
    
    // problem.setTestCase(_game_board3, _table3);
    // cout<<endl;
    // problem.solveProblem();
    
    Problem::Block_t b;
    // b.push_back(make_pair(0,0));
    // b.push_back(make_pair(1,0));
    // b.push_back(make_pair(2,0)); 
    // b.push_back(make_pair(2,1));
    // b.push_back(make_pair(2,2));
    // b.push_back(make_pair(2,3));
    b.push_back(make_pair(0,2));
    b.push_back(make_pair(1,0));
    b.push_back(make_pair(1,1)); 
    b.push_back(make_pair(1,2));
    b.push_back(make_pair(1,3));
    b.push_back(make_pair(2,0));

    _printBlock(b);
    problem.rotate90degree(b);
    _printBlock(b);
    problem.rotate90degree(b);
    _printBlock(b);
    problem.rotate90degree(b);
    _printBlock(b);
    problem.rotate90degree(b);
    _printBlock(b);
     problem.rotate90degree(b);
    _printBlock(b);
    return 0;
}