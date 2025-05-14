#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sys/shm.h>
using namespace std;
char B[10] = { '1','2','3','4','5','6','7','8','9' };


void Board(int& p1, int& p2, int& p3, string name)
{
cout << "      " << name << " =(X)        Computer=(O)" << endl;
cout << "     _______________________________" << endl;
cout << "     |         |         |         |" << endl;
cout << "     |    " << B[0] << "    |    " << B[1] << "    |    " << B[2] << "    |" << endl;
cout << "     |_________|_________|_________|" << endl;
cout << "     |         |         |         |" << endl;
cout << "     |    " << B[3] << "    |    " << B[4] << "    |    " << B[5] << "    |" << endl;
cout << "     |_________|_________|_________|" << endl;
cout << "     |         |         |         |" << endl;
cout << "     |    " << B[6] << "    |    " << B[7] << "    |    " << B[8] << "    |" << endl;
cout << "     |_________|_________|_________|" << endl;
cout << "\n     " << name << " wins= " << p1 << "\tComputer wins= " << p2 << "\tDraw = " << p3 << endl;
}

int check()
{
if (B[0] == B[1] && B[1] == B[2])
return 0;
else if (B[3] == B[4] && B[4] == B[5])
return 0;
else if (B[6] == B[7] && B[7] == B[8])
return 0;
else if (B[0] == B[3] && B[3] == B[6])
return 0;
else if (B[1] == B[4] && B[4] == B[7])
return 0;
else if (B[2] == B[5] && B[5] == B[8])
return 0;
else if (B[0] == B[4] && B[4] == B[8])
return 0;
else if (B[2] == B[4] && B[4] == B[6])
return 0;
else if (B[0] != '1' && B[1] != '2' && B[2] != '3' && B[3] != '4' && B[4] != '5' && B[5] != '6' && B[6] != '7' && B[7] != '8' && B[8] != '9')
return -1;
else
return 1;
}

int toss()
{
int p;
p = (rand() % 2) + 1;
return p;
}
int main()
{
        cout<<"\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout << "\t\t\tWELCOME TO TIC TAC TOE WORLD!"<<endl;
	cout<<"\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
string name;
srand(time(0));
char c, pressed;
int p1, p2, main_meu, p3;
int p, j, ai;
bool i = 1;
bool k;
p1 = 0;
p2 = 0;
p3 = 0;

int *shared_memory;
int shmid;
shmid=shmget((key_t)1122,sizeof(int),0666);

shared_memory=(int*)shmat(shmid,NULL,0);
int new_data =*shared_memory-30 ;
*shared_memory=new_data;

if (shmdt(shared_memory) == -1) 
{
        perror("shmdt error");
        exit(1);
}



cout << "Welcome to the tic tac toe game\n\nIt is a single player game against computer\n\nEnter your Name:";
cin >> name;
while (i)
{
system("CLS");
p = toss();
Board(p1, p2, p3, name);
if (p == 1)
cout <<"     "<< name << " has won the toss and will mark first" << endl;
else
cout << "     Computer has won the toss and will mark first" << endl;
j = 1;
char m, choi;
while (j == 1)
{
if (p % 2 == 0)
p = 2;
else
p = 1;
if (p == 1)
m = 'X';
else
m = 'O';
if (p == 2)
{

if (B[0] == 'X' && B[1] == 'X' && B[2] == '3')
choi = '3';
else if (B[3] == 'X' && B[4] == 'X' && B[5] == '6')
choi = '6';
else if (B[6] == 'X' && B[7] == 'X' && B[8] == '9')
choi = '9';
else if (B[0] == 'X' && B[3] == 'X' && B[6] == '7')
choi = '7';
else if (B[1] == 'X' && B[4] == 'X' && B[7] == '8')
choi = '8';
else if (B[2] == 'X' && B[5] == 'X' && B[8] == '9')
choi = '9';
else if (B[0] == 'X' && B[4] == 'X' && B[8] == '9')
choi = '9';
else if (B[2] == 'X' && B[4] == 'X' && B[6] == '7')
choi = '7';
else if (B[0] == 'X' && B[2] == 'X' && B[1] == '2')
choi = '2';
else if (B[3] == 'X' && B[5] == 'X' && B[4] == '5')
choi = '5';
else if (B[6] == 'X' && B[8] == 'X' && B[7] == '8')
choi = '8';
else if (B[0] == 'X' && B[6] == 'X' && B[3] == '4')
choi = '4';
else if (B[1] == 'X' && B[7] == 'X' && B[4] == '5')
choi = '5';
else if (B[2] == 'X' && B[8] == 'X' && B[5] == '6')
choi = '6';
else if (B[0] == 'X' && B[8] == 'X' && B[4] == '5')
choi = '5';
else if (B[2] == 'X' && B[6] == 'X' && B[4] == '5')
choi = '5';
else if (B[2] == 'X' && B[1] == 'X' && B[0] == '1')
choi = '1';
else if (B[5] == 'X' && B[4] == 'X' && B[3] == '4')
choi = '4';
else if (B[8] == 'X' && B[7] == 'X' && B[6] == '7')
choi = '7';
else if (B[6] == 'X' && B[3] == 'X' && B[0] == '1')
choi = '1';
else if (B[7] == 'X' && B[4] == 'X' && B[1] == '2')
choi = '2';
else if (B[8] == 'X' && B[5] == 'X' && B[2] == '3')
choi = '3';
else if (B[8] == 'X' && B[4] == 'X' && B[0] == '1')
choi = '1';
else if (B[6] == 'X' && B[4] == 'X' && B[2] == '3')
choi = '3';
else if (B[0] == 'O' && B[1] == 'O' && B[2] == '3')
choi = '3';
else
{
ai = (rand() % 9) + 1;
if (ai == 1)
choi = '1';
else if (ai == 2)
choi = '2';
else if (ai == 3)
choi = '3';
else if (ai == 4)
choi = '4';
else if (ai == 5)
choi = '5';
else if (ai == 6)
choi = '6';
else if (ai == 7)
choi = '7';
else if (ai == 8)
choi = '8';
else if (ai == 9)
choi = '9';
}
if (B[0] == 'O' && B[1] == '2' && B[2] == 'O')
choi = '2';
if (B[0] == '1' && B[1] == 'O' && B[2] == 'O')
choi = '1';
if (B[3] == 'O' && B[4] == 'O' && B[5] == '6')
choi = '6';
if (B[3] == 'O' && B[4] == '5' && B[5] == 'O')
choi = '5';
if (B[3] == '4' && B[4] == 'O' && B[5] == 'O')
choi = '4';
if (B[6] == 'O' && B[7] == 'O' && B[8] == '9')
choi = '9';
if (B[6] == 'O' && B[7] == '8' && B[8] == 'O')
choi = '8';
if (B[6] == '7' && B[7] == 'O' && B[8] == 'O')
choi = '7';
if (B[0] == 'O' && B[3] == 'O' && B[6] == '7')
choi = '7';
if (B[0] == 'O' && B[3] == '4' && B[6] == 'O')
choi = '4';
if (B[0] == '1' && B[3] == 'O' && B[6] == 'O')
choi = '1';
if (B[1] == 'O' && B[4] == 'O' && B[7] == '8')
choi = '8';
if (B[1] == 'O' && B[4] == '5' && B[2] == '7')
choi = '5';
if (B[1] == '2' && B[4] == 'O' && B[7] == 'O')
choi = '2';
if (B[2] == 'O' && B[5] == 'O' && B[8] == '9')
choi = '9';
if (B[2] == 'O' && B[5] == '6' && B[8] == 'O')
choi = '6';
if (B[2] == '3' && B[5] == 'O' && B[8] == 'O')
choi = '3';
if (B[0] == 'O' && B[4] == 'O' && B[8] == '9')
choi = '9';
if (B[0] == 'O' && B[4] == '5' && B[8] == 'O')
choi = '5';
if (B[0] == '1' && B[4] == 'O' && B[8] == 'O')
choi = '1';
if (B[2] == 'O' && B[4] == 'O' && B[6] == '7')
choi = '7';
if (B[2] == 'O' && B[4] == '5' && B[6] == 'O')
choi = '5';
if (B[2] == '3' && B[4] == 'O' && B[6] == 'O')
choi = '3';
}
else {
cout << "\n     Enter the number of box in which you want to put your mark:";
cin >> choi;
}
if (choi == '1' && B[0] == '1')
{
system("CLS");
B[0] = m;
Board(p1, p2, p3, name);
}
else if (choi == '2' && B[1] == '2')
{
system("CLS");
B[1] = m;
Board(p1, p2, p3, name);
}
else if (choi == '3' && B[2] == '3')
{
system("CLS");
B[2] = m;
Board(p1, p2, p3, name);
}
else if (choi == '4' && B[3] == '4')
{
system("CLS");
B[3] = m;
Board(p1, p2, p3, name);
}
else if (choi == '5' && B[4] == '5')
{
system("CLS");
B[4] = m;
Board(p1, p2, p3, name);
}
else if (choi == '6' && B[5] == '6')
{
system("CLS");
B[5] = m;
Board(p1, p2, p3, name);
}
else if (choi == '7' && B[6] == '7')
{
system("CLS");
B[6] = m;
Board(p1, p2, p3, name);
}
else if (choi == '8' && B[7] == '8')
{
system("CLS");
B[7] = m;
Board(p1, p2, p3, name);
}
else if (choi == '9' && B[8] == '9')
{
system("CLS");
B[8] = m;
Board(p1, p2, p3, name);
}
else
continue;
j = check();
p = p + 1;
}
if (j == 0)
{
if (p - 1 == 1)
cout << "      " << name << " Wins" << endl;
else
cout << "       Computer Wins" << endl;
if (p - 1 == 1)
{
p1 = p1 + 1;
}
else
p2 = p2 + 1;
}
else
{
cout << "     Game is Draw" << endl;
p3++;
}
cout << "     If you want to play again:Enter\'Y\':";
cin >> c;
if (c == 'Y')
{
i = 1;
B[0] = '1';
B[1] = '2';
B[2] = '3';
B[3] = '4';
B[4] = '5';
B[5] = '6';
B[6] = '7';
B[7] = '8';
B[8] = '9';
}
else
i = 0;
}
cout << "Enter any key to quit " << endl; cin >> pressed;
{
                     int *shared_memory;
                      int shmid;
                     shmid=shmget((key_t)1122,sizeof(int),0666);
                     shared_memory=(int*)shmat(shmid,NULL,0);
                      int new_data =*shared_memory+30 ;
                      *shared_memory=new_data;
                      if (shmdt(shared_memory) == -1) 
                      {
                        perror("shmdt error");
                        exit(1);
                      }
                   }
system("pause");
}

