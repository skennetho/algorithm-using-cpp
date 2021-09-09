#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <array>
#include <utility>
#include <algorithm> 
using namespace std;

/*����: ���� ���� ä���

���� ����
���̺� ���� ���� ���� ������ ���� ������ �� ������ ������ �÷������� �մϴ�. 
���� ����� ���̺��� ��� �� ĭ�� 1x1 ũ���� ���簢 ���� ����Դϴ�. 
�̶�, ���� ��Ģ�� ���� ���̺� ���� ���� ���� ������ ���� ������ ��ĭ�� ä��� �˴ϴ�.

 - ������ �� ���� �ϳ��� ä�� �ֽ��ϴ�.
 - ������ ȸ����ų �� �ֽ��ϴ�.
 - ������ ������ ���� �����ϴ�.
 - ���� ���忡 ���� ä�� ���� ���� ������ ������ ĭ�� ��������� �� �˴ϴ�.

 ���ѻ���
    3 �� game_board�� �� ���� �� 50
    game_board�� �� �� ���� = game_board�� �� ����
        ��, ���� ����� ���簢 ���� ����Դϴ�. 
        game_board�� ��� ���Ҵ� 0 �Ǵ� 1�Դϴ�.
        0�� ��ĭ, 1�� �̹� ä���� ĭ�� ��Ÿ���ϴ�.
        ���� ������ ���� ��ĭ�� 1 x 1 ũ�� ���簢���� �ּ� 1������ �ִ� 6������ ����� ���·θ� �־����ϴ�.
    table�� �� ���� = game_board�� �� ����
    table�� �� �� ���� = table�� �� ����
        ��, ���̺��� game_board�� ���� ũ���� ���簢 ���� ����Դϴ�.
        table�� ��� ���Ҵ� 0 �Ǵ� 1�Դϴ�.
        0�� ��ĭ, 1�� ������ ���� ĭ�� ��Ÿ���ϴ�.
        ���� ������ 1 x 1 ũ�� ���簢���� �ּ� 1������ �ִ� 6������ ����� ���·θ� �־����ϴ�.
    game_board���� �ݵ�� �ϳ� �̻��� ��ĭ�� �ֽ��ϴ�.
    table���� �ݵ�� �ϳ� �̻��� ����� ���� �ֽ��ϴ�.
*/


/*�õ�1
���� �ϳ������Ǹ�  ��ǥ�� �������� ����. �׸��� ������ ���� ��ġ�ϴµ� �ʿ��� h,w�迭�� ǥ������.
    h,w �迭���� ������ ��ġ�ϴ°��� 1 �ƴѰ��� 0���� ����.
    ���Ӻ���� ��ĭ�� 0 �������� 1.

���Ӻ��忡 ���� �ִ��� �Ǵ��Ҷ��� garo, sero �� ���̿��� h x w �迭�� ���� �ִ� ����� ���� ��� ���鼭
    ���� ��� 0,0��ġ�� h,w�迭�� ������ ��ġ�غ��ٰ� �ϸ� 
    ���Ӻ����� 0<garo<0+w , 0<sero<0+h ĭ�� �����迭�� ���ҵ�� ���Ͽ� 2�� ������ ������ �� �� �ִ� �ڸ���� �Ǵ�����.

���Ʈ������ �������� ������� �����ϵ� �ƿ� �ȵǴ� �������� pass�ϸ� ����ġ��
*/




class Problem{
public:
    typedef vector<vector<int>> Board_t;
    typedef vector<vector<pair<int, int>>> BlockPieces_t ;      //i,j�� ���
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
   
   
    int solution(Board_t game_board, Board_t table) {                              //�����ڵ�
        int answer=0;
        //������� �����ϴ� ������ �ٲٱ�
        reverseBoard(game_board);
        
        //���� ���ͷ� ��ȯ
        BlockPieces_t blocks_game, blocks_table;
        blocks_game = parseBlocks(game_board);
        blocks_table = parseBlocks(table);

        //�׺����� ������ ���̺��� ���������Ͽ� ���� �ּҰ��� �Ǵ� ��Ʈ ã�� : with bfs
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

    //���� ������
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

    //dfs�� ����Ͽ� ���� �����ͷ� ��ȯ
    BlockPieces_t parseBlocks(Board_t board){
        BlockPieces_t blocks;
        for(int i = 0 ; i< board.size() ; i++){
            for(int j = 0; j< board.size() ; j++){
                Block_t block;
                checkAdjacent(board, block, i,j);
                //�ǽ��� ��������ٸ� ���� 
                if(block.size() >0) {
                    sort(block.begin() , block.end());   
                    blocks.push_back(block);
                }
            }
        }
        return blocks;
    }

    void checkAdjacent(Board_t &board,Block_t &block, int i, int j){
        //board�� ��� ���� ����Ű�� ����
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

    //���� ����� ������ �Ǻ�
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
            //�밢�� ��Ī
            jj = b[i].first- h_start;
            ii = b[i].second - w_start;
            //�¿��Ī
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