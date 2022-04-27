#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>rF;
vector<vector<int>>cF;
vector<vector<int>>mF;
vector<vector<char>>ans;
bool ansFound=false;
int find_mN(int i,int j){
    if(i<3){
        if(j<3)return 0;
        else if(j<6)return 1;
        else return 2;
    }
    else if(i<6){
        if(j<3)return 3;
        else if(j<6)return 4;
        else return 5;
    }
    else{
        if(j<3)return 6;
        else if(j<6)return 7;
        else return 8;
    }
}
bool verify(int r,int c,int x){
    if(rF[r][x-1]!=0)return false;
    if(cF[c][x-1]!=0)return false;
    int mat_num=find_mN(r,c);
    if(mF[mat_num][x-1]!=0)return false;
    return true;
}
void fill(vector<vector<char>>board,int r,int c){
    if(ansFound)return;
    if(r==9){
        ans.resize(r);
        for(int i=0;i<9;i++){
            ans[i].resize(9,'.');
            for(int j=0;j<9;j++){
                ans[i][j]=board[i][j];
            }
        }
        ansFound=true;
        return;
    }
    if(board[r][c]!='.'){
        if(c<8)fill(board,r,c+1);
        else fill(board,r+1,0);
        return;
    }
    for(int x=1;x<=9;x++){
        if(verify(r,c,x)){
            board[r][c]='0'+x;
            rF[r][x-1]=1;
            cF[c][x-1]=1;
            int mat_num=find_mN(r,c);
            mF[mat_num][x-1]=1;
            if(c<8)fill(board,r,c+1);
            else fill(board,r+1,0);
            board[r][c]='.';
            rF[r][x-1]=0;
            cF[c][x-1]=0;
            mF[mat_num][x-1]=0; 
        }
    }
}
void solveSudoku(vector<vector<char>>& board) {
    for(int i=0;i<9;i++){
        vector<int>vec(9,0);
        for(int j=0;j<9;j++){
            if(board[i][j]!='.')
                vec[board[i][j]-'1']++;
        }
        rF.push_back(vec);
    }
    for(int j=0;j<9;j++){
        vector<int>vec(9,0);
        for(int i=0;i<9;i++){
            if(board[i][j]!='.')
                vec[board[i][j]-'1']++;
        }
        cF.push_back(vec);
    }
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            vector<int>vec(9,0);
            for(int i1=i;i1<i+3;i1++){
                for(int j1=j;j1<j+3;j1++){
                    if(board[i1][j1]!='.')
                        vec[board[i1][j1]-'1']++;
                }
            }
            mF.push_back(vec);
        }
    }
    fill(board,0,0); 
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            board[i][j]=ans[i][j];
        }
    }
}

int main(){
    int n=9;
    vector<vector<char>>board(n);
    for(int i=0;i<9;i++){
        board[i].resize(9);
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }

    solveSudoku(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }


    

}