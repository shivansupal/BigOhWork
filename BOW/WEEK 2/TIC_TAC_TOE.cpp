//Driver Code

#include<bits/stdc++.h>
using namespace std;

// y is for computer turn
// t is for user turn
//initializing game=1 to start the game

int board[3][3] , t , y , game=1;
char name[30], str[500];


/*
    Print Function : Print the board
    @param : void
    @return : void
*/
void print()          
{
    int row , column ;

    cout<<endl;

    for(row =0; row <3; row ++)
    {
        for(column =0;column <3; column++)
        {
            if(board[row][column]==0)
                cout<<".\t";
            else if(board[row][column]==1)
                cout<<"X\t";
            else
                cout<<"O\t";
        }
        
        cout<<endl;
    }
}

/*
    Check function will check if anyone in winning
    @param: void
    @return: integer
*/
int check()//checks if anyone is winning.
{
    for(int i=0;i<3;i++)

        if((board[i][0]!=0&&board[i][0]==board[i][1]&&board[i][1]==board[i][2])||(board[0][i]!=0&&board[0][i]==board[1][i]&&board[1][i]==board[2][i]))

            return 1;
    
    if(board[0][0]!=0&&board[0][0]==board[1][1]&&board[1][1]==board[2][2])

        return 1;

    else if(board[0][2]!=0&&board[0][2]==board[1][1]&&board[1][1]==board[2][0])

        return 1;

    else

        return 0;

}
/*
    Pin function will take input from the player
    @param : void
    @return : void
*/
void pin()//takes input from player
{
    int row=0, column =0;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter column: ";
    cin>>column;
    row--;
    column--;
    if(row>2|| column >2|| row <0 || column <0 || board[row][column]!=0 )
    {
        strcpy(str,"Enter correct value ");
        strcat(str,name);
        strcat(str,".\n");
        puts(str);
        pin();
    }
    else if(board[row][column]!=0)
    {
        cout<<"It is already filled.\n";
        pin();
    }
    else
        board[row][column]=t;
}

/*
    Defend function will defend the computer from loosing
    @param: user input, player input, input
    @return : integer
*/
int defend(int c, int p, int b)
{
    if(b<3)
        return 0;
    else if(board[0][0]+board[1][1]+board[2][2]==2*c&&board[0][0]!=p&&board[1][1]!=p&&board[2][2]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(board[i][i]==0)
            {
                board[i][i]=y;
                cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                return 1;
            }
        }
    }
    else if(board[0][2]+board[1][1]+board[2][0]==2*c&&board[0][2]!=p&&board[1][1]!=p&&board[2][0]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(board[i][2-i]==0)
            {
                board[i][2-i]=y;

                cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;

                return 1;
            }
        }
    }
    else
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            if(board[i][0]+board[i][1]+board[i][2]==2*c&&board[i][0]!=p&&board[i][1]!=p&&board[i][2]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(board[i][j]==0)
                    {
                        board[i][j]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                        return 1;                    }
                }
            }
            else if(board[0][i]+board[1][i]+board[2][i]==2*c&&board[0][i]!=p&&board[1][i]!=p&&board[2][i]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(board[j][i]==0)
                    {
                        board[j][i]=y;
                        cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
/*
    Attack function will try to win
    @param: void
    @return : integer
*/
int attack()
{
    int i,j;

    if(board[0][0]+board[0][2]+board[2][0]+board[2][2]==t||board[0][0]+board[0][2]+board[2][0]+board[2][2]==2*t)
    {
        for(i=0;i<3;i++)
        {
            if( board[i][0]+board[i][1]+board[i][2]==y && (board[i][0]==y||board[i][1]==y||board[i][2]==y) )
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(board[i][j]==0)

                        {
                            board[i][j]=y;

                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            return 1;

                        }
                    }
                }

                else

                {
                    for(j=2;j>=0;j--)
                    {
                        if(board[i][j]==0)
                        {
                            board[i][j]=y;

                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;

                            return 1;
                        }
                    }
                }
            }

            if(board[0][i]+board[1][i]+board[2][i]==y && (board[0][i]==y||board[1][i]==y||board[2][i]==y))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(board[j][i]==0)
                        {
                            board[j][i]=y;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            return 1;
                        }
                    }
                }

                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(board[j][i]==0)
                        {
                            board[j][i]=y;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            return 1;
                        }
                    }
                }
                
            }
        }
        
        if(board[0][0]+board[1][1]+board[2][2]==y && (board[0][0]==y||board[1][1]==y||board[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((board[i][i]==0)&& ((board[i][0]+board[i][1]+board[i][2]==y&&(board[i][0]==y||board[i][1]==y||board[i][2]==y)) ||( (board[0][i]+board[1][i]+board[2][i]==y)&&(board[0][i]==y||board[1][i]==y||board[2][i]==y))))
                {
                    board[i][i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;

                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(board[i][i]==0)
                {
                    if((board[i][0]+board[i][1]+board[i][2]==t&&(board[i][0]==t||board[i][1]==t||board[i][2]==t))&&(board[0][i]+board[1][i]+board[2][i]==t&&(board[0][i]==t||board[1][i]==t||board[2][i]==t)))
                    {
                        board[i][i]=y;

                        cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;

                        return 1;
                    }
                }
            }

            for(i=2;i>=0;i--)
            {
                if(board[i][i]==0)

                {
                    board[i][i]=y;

                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;

                    return 1;
                }
            }
        }
        else if( board[0][2]+board[1][1]+board[2][0]==y && (board[0][2]==y||board[1][1]==y||board[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(board[i][2-i]==0&&((board[i][0]+board[i][1]+board[i][2]==y&&(board[i][0]==y||board[i][1]==y||board[i][2]==y))||( (board[0][2-i]+board[1][2-i]+board[2][2-i]==y)&&(board[0][2-i]==y||board[1][2-i]==y||board[2][2-i]==y))))
                {
                    board[i][2-i]=y;

                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;

                    return 1;
                }
            }

            for(i=2;i>=0;i--)

            {
                if(board[i][2-i]==0)
                {
                    if((board[i][0]+board[i][1]+board[i][2]==t&&(board[i][0]==t||board[i][1]==t||board[i][2]==t))&&(board[0][2-i]+board[1][2-i]+board[2][2-i]==t&&(board[0][2-i]==t||board[1][2-i]==t||board[2][2-i]==t)))
                    {
                        board[i][2-i]=y;

                        cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;

                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(board[i][2-i]==0)
                {
                    board[i][2-i]=y;

                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;

                    return 1;
                }
            }
        }
    }
    else
    {
        if(board[0][0]+board[1][1]+board[2][2]==y && (board[0][0]==y||board[1][1]==y||board[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((board[i][i]==0)&& ((board[i][0]+board[i][1]+board[i][2]==y&&(board[i][0]==y||board[i][1]==y||board[i][2]==y)) ||( (board[0][i]+board[1][i]+board[2][i]==y)&&(board[0][i]==y||board[1][i]==y||board[2][i]==y))))
                {
                    board[i][i]=y;

                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;

                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(board[i][i]==0)
                {
                    if((board[i][0]+board[i][1]+board[i][2]==t&&(board[i][0]==t||board[i][1]==t||board[i][2]==t))&&(board[0][i]+board[1][i]+board[2][i]==t&&(board[0][i]==t||board[1][i]==t||board[2][i]==t)))
                    {
                        board[i][i]=y;

                        cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;

                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(board[i][i]==0)
                {
                    board[i][i]=y;

                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;

                    return 1;
                }
            }
        }
        
        else if( board[0][2]+board[1][1]+board[2][0]==y && (board[0][2]==y||board[1][1]==y||board[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(board[i][2-i]==0&&((board[i][0]+board[i][1]+board[i][2]==y&&(board[i][0]==y||board[i][1]==y||board[i][2]==y))||( (board[0][2-i]+board[1][2-i]+board[2][2-i]==y)&&(board[0][2-i]==y||board[1][2-i]==y||board[2][2-i]==y))))
                {
                    board[i][2-i]=y;

                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;

                    return 1;
                }
            }

            for(i=2;i>=0;i--)
            {
                if(board[i][2-i]==0)
                {
                    if((board[i][0]+board[i][1]+board[i][2]==t&&(board[i][0]==t||board[i][1]==t||board[i][2]==t))&&(board[0][2-i]+board[1][2-i]+board[2][2-i]==t&&(board[0][2-i]==t||board[1][2-i]==t||board[2][2-i]==t)))
                    {
                        board[i][2-i]=y;

                        cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;

                        return 1;
                    }
                }
            }
            
            for(i=2;i>=0;i--)
            {
                if(board[i][2-i]==0)
                {
                    board[i][2-i]=y;

                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;

                    return 1;
                }
            }
        }
        
        else
        {
            for(i=0;i<3;i++)
            {
                if( board[i][0]+board[i][1]+board[i][2]==y && (board[i][0]==y||board[i][1]==y||board[i][2]==y) )
                {
                    if(i==1)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(board[i][j]==0)
                            {
                                board[i][j]=y;

                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;

                                return 1;
                            }
                        }
                    }
                    else{
                        for(j=2;j>=0;j--)
                        {
                            if(board[i][j]==0)
                            {
                                board[i][j]=y;
                                
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                return 1;
                            }
                        }
                    }
                }
                else if(board[0][i]+board[1][i]+board[2][i]==y && (board[0][i]==y||board[1][i]==y||board[2][i]==y))
                {
                    if(i==1)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(board[j][i]==0)
                            {
                                board[j][i]=y;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for(j=2;j>=0;j--)
                        {
                            if(board[j][i]==0)
                            {
                                board[j][i]=y;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void ai(int b)//controls the compter's move
{
    if(!defend(y,t,b))
    {
        if(!defend(t,y,b))
        {
            if((board[0][0]+board[0][2]+board[2][0]+board[2][2]==t+y||board[0][0]+board[0][2]+board[2][0]+board[2][2]==t+2*y)&&board[1][1]==0)
            {
                for(int i=0;i<3;i+=2)
                {
                    for(int j=0;j<3;j+=2)
                        if(board[i][j]==0)
                        {
                            board[i][j]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            goto end;
                        }
                }
                
            }
            else if(b==2&&board[1][1]==0)
            {
                board[1][1]=y;
                cout<<"Computer turn: 2 2\n";
                goto end;
            }
            if(!attack())
            {
                if(b==0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int) seconds);

                    int i,j;

                    board[(rand()%2)*2][(rand()%2)*2]=y;

                    for(i=0;i<3;i+=2)
                    {
                        for(j=0;j<3;j+=2)
                            if(board[i][j]==y)

                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;

                    }
                }
                else if(board[1][1]==0)
                {
                    board[1][1]=y;

                    cout<<"Computer turn: 2 2\n";
                }
                else
                {
                    int i,j;
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(board[i][j]==0)
                            {
                                board[i][j]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                goto end;
                            }
                        }
                    }
                }
            }
        }
    }
end:
    cout<<endl;
}

int main()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            board[i][j]=0;
    if(game==1)
    {
        cout<<"Name ? ";
        gets(name);
       
        
        strcpy(str,"\nyour choice\n");

        strcat(str,name);

        strcat(str,", want to go 1st or 2nd?");

        puts(str);
    }
    else
    {
        strcpy(str,"\nOkay beat me ");
        strcat(str,name);
        strcat(str,".\nLet's see again if you can.");
        puts(str);
        
        strcpy(str,"\nThis time you want to go 1st or 2nd, ");
        strcat(str,name);
        strcat(str,"?");
        puts(str);
    }
    
input:
    cin>>t;
    switch(t)
    {
        case 1:
            y=2;
            cout<<"\nSo your symbol is X.\nAnd mine is O.\n\nLet's start the game.";
            print();
            for(i=0;i<9;)
            {
                pin();
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        strcpy(str,"\nOh, you won ");
                        strcat(str,name);
                        strcat(str," .\nCongratulations\n");
                        puts(str);
                        exit(0);
                        break;
                    }
                if(i>=8)
                    break;
                ai(i);
                print();
                i++;
                if(i>5)
                    if(check())
                    {
                        strcpy(str,"\nIt is impossible to beat me ");
                        strcat(str,name);
                        if(game>1)
                            strcat(str," I won.");
                        else
                            strcat(str,", I won, you loose.");
                        puts(str);
                        break;
                    }
            }
            break;
            
        case 2:
            y=1;
            cout<<"\nSo your symbol is O.\nAnd mine is X.\n\nLet's start the game.";
            print();
            for(i=0;i<9;)
            {
                ai(i);
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        strcpy(str,"It is impossible to beat me ");
                        strcat(str,name);
                        if(game>1)
                            strcat(str,", you couldn't beat me this time too, I won.");
                        else
                            strcat(str,", I won, you loose.");
                        puts(str);
                        break;
                    }
                if(i>=8)
                    break;
                pin();
                print();
                i++;
                if(i>5)
                    if(check())
                    {
                        strcpy(str,"you won ");
                        strcat(str,name);
                        strcat(str," Congratulations\n");
                        puts(str);
                        exit(0);
                        break;
                    }
            }
            break;
        default:
            strcpy(str,"Hey, ");
            strcat(str,name);
            strcat(str," you need to enter either 1 or 2.");
            puts(str);
            cout<<"\nEnter again: ";
            goto input;
            break;
    }
    if(!check())
    {
        if(game>1)
            cout<<"Well Played!\n";
        else
            cout<<"Well Played!\nIt is a tie.\n";

    }
    char c;
    strcpy(str,"Wanna play again ");
    strcat(str,name);
    strcat(str," y/n?");
    puts(str);
    cin>>c;
    if(c=='y'||c=='Y')
    {
        game++;
        main();
    }
    else
        exit(0);
    return 0;

}