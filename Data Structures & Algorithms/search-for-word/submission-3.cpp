class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    string s="";
                    s.push_back(word[0]);
                    if(dfs(1,i,j,s,word,board)) return true;;
                }
            }
        }
        return false;
    }

    bool dfs(int node,int r,int c,string& s,string& word,vector<vector<char>>& board){
        if(word.size()==node){
            return true;
        }
        vector<int> rr={-1,0,1,0};
        vector<int> cc={0,-1,0,1};
        char temp = board[r][c];
        board[r][c] = '#';
        for(int i=0;i<4;i++){
            int x=r+rr[i];
            int y=c+cc[i];
            if(x<0 ||x>=board.size()||y<0 ||y>=board[0].size()||board[x][y]!=word[node]) continue;
          
            s.push_back(word[node]);
            if(dfs(node+1,x,y,s,word,board)) return true;
            s.pop_back();
        }
        board[r][c]=temp;
        return false;
    }

};
