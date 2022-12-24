#include <bits/stdc++.h>

using namespace std;

void queen(int k){
    switch(k){
    case 1: cout<<"|      **      |"; break;
    case 2: cout<<"|    ******    |"; break;
    case 3: cout<<"|    ******    |"; break;
    case 4: cout<<"|      **      |"; break;
    case 5: cout<<"|      **      |"; break;
    case 6: cout<<"|      **      |"; break;
    case 7: cout<<"|   ********   |"; break;
    case 8: cout<<"|**************|"; break;
    }
}

void blank(){
    cout<<"|              |";
}

bool is_safe(int** arr, int x , int y, int n){
     
    for(int row = 0;row < x; row++){ 
        if (arr[row][y]==1){
            return false;
        }
    }
    
    int row=x;
    int col=y;

    // left diagonal
    while(row>=0 &&  col>=0){
        if ( arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row=x;
    col=y;

    //right diagonal
    while(row>=0 && col<n){
        if  (arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** arr, int x ,int n){

    if(x>=n){
        return true;
    }

    for(int col=0; col<n;col++){
        if ( is_safe(arr, x, col , n)){
            arr[x][col]=1;

            if(nQueen(arr ,x+1 ,n)){
                return true;
            }
            arr[x][col]=0;   // backtrack
        }
    }
    return false;
}

int main(){
    cout<<"Enter the size\n: ";
    int n;
    cin>>n;

    int** arr= new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
     
      if(nQueen(arr,0,n)){

        for(int  i=0;i<n;i++){
            int f=1;
            for(int k=1;k<=8;k++){
             for(int j=0;j<n;j++){
                   if(arr[i][j]==1){
                       queen(k);
                   }else{
                       blank();
                   }
                }cout<<endl;
             }
             cout<<endl;
         }
     }

    return 0;
}