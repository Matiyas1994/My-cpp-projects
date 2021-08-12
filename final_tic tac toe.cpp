
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

string a[9]={"1","2","3","4","5","6","7","8","9"};
int b[9]={0};
int c=0, winner;
int k,lev,start;
char with;
string ch;
bool isDone=false;
int guser(int);
int attack();
int defence();
void display(char);
void cheak();
void congradulation(char);
void restart();
void main_Mainu();
int levelchose();

int main(){
mainu:
main_Mainu();
if(with=='c'||with=='C'){
  cout<<"\nDo you want to be ---->\t player [1] or player [2]"<<endl;
cin>>start;
  if(start==1)
    c=0;
  else if(start==2)
   c=1;
  system("cls");
  lev=levelchose();
  system("cls");
}
label2:
do {
display(with);
if(with=='c'||with=='C'){
if(c%2==0)
cin>>k;
else{
    if(c==1 && lev==3){
      k=5;
    }
    else
    k=guser(lev);
//display(with);
}
}
else
cin>>k;
inv:

if(k>0 && k < 10 ){
    if(a[k-1]!="X" && a[k-1]!="O"){
        if(c%2==0){
           a[k-1]="X";
           b[k-1]=1;
        }

        else{
            a[k-1]="O";
            b[k-1]=1;
        }
    }
else
    goto label;

c++;
}
else if(k==0)
    goto label3;

else{
label:
if(c%2==0)
{
cout<<"Invalid input\n";
cin>>k;
}

else{

if(c==1 && lev==3)
{
  k=7;
}
else{k=guser(lev);}
goto inv;
}

}

cheak();
system("cls");
}while (isDone==false);
 display(with);
congradulation(with);

label3:
if(ch=="A"||ch=="a"||k==0)
{
restart();
    goto label2;
}
else if (ch=="q"||ch=="Q")
return 0;
else if(ch=="M"||ch=="m")
{restart();
goto mainu;
}
else
{
cout<<"invalid choice !!! "<<endl;
cin>>ch;
  goto label3;
}

}

//screen display updater
void display(char choice){

 cout<<"\n\n \tTic Tac Toe \n\n";
 if(choice=='f'||choice=='F')
cout<<"\tPlayer 1 (X)\tPlayer 2 (O)\t[0] Restart\n\n";
else  if(choice=='c'||choice=='c')
cout<<"\tYou (X)\t computer (O)\t[0] Restart\n\n";
cout<<"\t   | "<<"  | "<<endl;
cout<<"\t "<<a[0]<<" | "<< a[1]<<" | "<<a[2]<<endl;
cout<<"\t___|___|_____"<<endl;
cout<<"\t   | "<<"  | "<<endl;
cout<<"\t "<<a[3]<<" | "<< a[4]<<" | "<<a[5]<<endl;
cout<<"\t___|___|_____"<<endl;
cout<<"\t   | "<<"  | "<<endl;
cout<<"\t "<<a[6]<<" | "<< a[7]<<" | "<<a[8]<<endl;
cout<<"\t   | "<<"  | "<<endl;

if(c%2==0 && (choice=='f'|| choice=='F'))
    cout<<"\n\nPlayer 1 ---> ";
 else if(choice=='f'||choice=='F')
cout<<"\n\nPlayer 2 ---> ";

else if(c%2==0 && choice=='c')
    cout<<"\n\nYour Turn ---> ";

}

//cheack if the game ends and the winner
void cheak(){

if((a[0]=="X" && a[1]=="X" && a[2]=="X") ||
   (a[0]=="X" && a[3]=="X" && a[6]=="X") ||
   (a[0]=="X" && a[4]=="X" && a[8]=="X") ||
   (a[1]=="X" && a[4]=="X" && a[7]=="X") ||
   (a[2]=="X" && a[5]=="X" && a[8]=="X") ||
   (a[2]=="X" && a[4]=="X" && a[6]=="X") ||
   (a[3]=="X" && a[4]=="X" && a[5]=="X") ||
   (a[6]=="X" && a[7]=="X" && a[8]=="X"))
{
    isDone=true;
    winner=1;
}

else if((a[0]=="O" && a[1]=="O" && a[2]=="O") ||
   (a[0]=="O" && a[3]=="O" && a[6]=="O") ||
   (a[0]=="O" && a[4]=="O" && a[8]=="O") ||
   (a[1]=="O" && a[4]=="O" && a[7]=="O") ||
   (a[2]=="O" && a[5]=="O" && a[8]=="O") ||
   (a[2]=="O" && a[4]=="O" && a[6]=="O") ||
   (a[3]=="O" && a[4]=="O" && a[5]=="O") ||
   (a[6]=="O" && a[7]=="O" && a[8]=="O"))
{
    isDone=true;
    winner=2;
}

 else if(  (a[0]=="X"||a[0]=="O") &&
         (a[1]=="X"||a[1]=="O") &&
         (a[2]=="X"||a[2]=="O") &&
         (a[3]=="X"||a[3]=="O") &&
         (a[4]=="X"||a[4]=="O") &&
         (a[5]=="X"||a[5]=="O") &&
         (a[6]=="X"||a[6]=="O") &&
         (a[7]=="X"||a[7]=="O") &&
         (a[8]=="X"||a[8]=="O") )
    {
    isDone=true;
    winner=3;
}

}



int guser(int level){

int num,atta,def;
atta=attack();
def=defence();

if(level==1){ num=rand()%9+1;}
else{
if(atta!=-1)
    num=atta;
else if(def!=-1)
   num=def;
else
    num=rand()%9+1;
}
return num;
}

int attack(){
int num=-1;
   //ATTACK
    //ROW
  if(a[0]=="O" && a[1]=="O" && b[2]==0)
   num=3;
   if(a[0]=="O" && a[2]=="O" && b[1]==0)
  num=2;
    if( a[1]=="O"&& a[2]=="O" && b[0]==0)
    num=1;
   if( a[3]=="O"&& a[4]=="O" && b[5]==0)
    num=6;
      if( a[3]=="O"&& a[5]=="O" && b[4]==0)
    num=5;
     if( a[4]=="O"&& a[5]=="O" && b[3]==0)
    num=4;
      if( a[6]=="O"&& a[7]=="O" && b[8]==0)
    num=9;
      if( a[6]=="O"&& a[8]=="O" && b[7]==0)
    num=8;
      if( a[7]=="O"&& a[8]=="O" && b[6]==0)
    num=7;

 //column
  if( a[0]=="O"&& a[3]=="O" && b[6]==0)
    num=7;
      if( a[0]=="O"&& a[6]=="O" && b[3]==0)
    num=4;
     if( a[3]=="O"&& a[6]=="O" && b[0]==0)
    num=1;

      if( a[1]=="O"&& a[4]=="O" && b[7]==0)
    num=8;
         if( a[7]=="O"&& a[1]=="O" && b[4]==0)
    num=5;
     if( a[4]=="O"&& a[7]=="O" && b[1]==0)
    num=2;

     if( a[2]=="O"&& a[5]=="O" && b[8]==0)
    num=9;
     if( a[2]=="O"&& a[8]=="O" && b[5]==0)
    num=6;
     if( a[5]=="O"&& a[8]=="O" && b[2]==0)
    num=3;

    //diagonal
      if( a[0]=="O"&& a[4]=="O" && b[8]==0)
    num=9;
      if( a[4]=="O"&& a[8]=="O" && b[0]==0)
    num=1;
      if( a[0]=="O"&& a[8]=="O" && b[4]==0)
    num=5;
     if( a[6]=="O"&& a[4]=="O" && b[2]==0)
    num=3;
     if( a[4]=="O"&& a[2]=="O" && b[6]==0)
    num=7;
     if( a[6]=="O"&& a[2]=="O" && b[4]==0)
    num=5;

    return num;
}
int defence(){
int num=-1;
//DEFENCE
//row
if(a[0]=="X" && a[1]=="X"  && b[2]==0 )
   num=3;
   if(a[0]=="X" && a[2]=="X"  && b[1]==0)
     num=2;
    if( a[1]=="X"&& a[2]=="X" && b[0]==0)
     num=1;
    if( a[3]=="X"&& a[4]=="X" && b[5]==0)
     num=6;
      if( a[3]=="X"&& a[5]=="X" && b[4]==0)
     num=5;
     if( a[4]=="X"&& a[5]=="X" && b[3]==0)
    num=4;
      if( a[6]=="X"&& a[7]=="X" && b[8]==0)
    num=9;
      if( a[6]=="X"&& a[8]=="X" && b[7]==0)
    num=8;
      if( a[7]=="X"&& a[8]=="X" && b[6]==0)
    num=7;

 //column
  if( a[0]=="X"&& a[3]=="X" && b[6]==0)
    num=7;
      if( a[0]=="X"&& a[6]=="X" && b[3]==0)
    num=4;
      if( a[3]=="X"&& a[6]=="X" && b[0]==0)
    num=1;

      if( a[1]=="X"&& a[4]=="X" && b[7]==0)
    num=8;
         if( a[7]=="X"&& a[1]=="X" && b[4]==0)
    num=5;
      if( a[4]=="X"&& a[7]=="X" && b[1]==0)
    num=2;

     if( a[2]=="X"&& a[5]=="X" && b[8]==0)
    num=9;
      if( a[2]=="X"&& a[8]=="X" && b[5]==0)
    num=6;
      if( a[5]=="X"&& a[8]=="X" && b[2]==0)
    num=3;

    //diagonal
     if( a[0]=="X"&& a[4]=="X" && b[8]==0)
    num=9;
     if( a[4]=="X"&& a[8]=="X" && b[0]==0)
    num=1;
      if( a[0]=="X"&& a[8]=="X" && b[4]==0)
    num=5;
     if( a[6]=="X"&& a[4]=="X" && b[2]==0)
    num=3;
      if( a[4]=="X"&& a[2]=="X" && b[6]==0)
    num=7;
      if( a[6]=="X"&& a[2]=="X" && b[4]==0)
    num=5;

return num;
}

void game(){


}
void congradulation(char w){

if(winner ==1 && (w=='f'||w=='F'))
    cout<<"\n\n\tCongratulation  Player 1(X) Wins !!!\n\n";
else if (winner == 2 && (w=='f'||w=='F'))
    cout<<"\n\n\tCongratulation Player 2(O) Wins !!!\n\n";

else if (winner == 1 && (w=='c'||w=='C'))
    cout<<"\n\n\tCongratulation YOU WON!!!\n\n";

else if (winner == 2 && (w=='c'||w=='C'))
    cout<<"\n\n\tYou lost !!!\n\n";

else if(winner ==3)
    cout<<"\n\n\tThe Game Is Draw ";


cout<<"\t[A] Play again \t [Q] Quit\t [M] Main Menu"<<endl;
cin>>ch;

}
void main_Mainu()
{
again_choice:
char w;
cout<<"\n\n\t\tWelcome To Tic Tac Toe Game\n";
cout<<"\t\t___________________________\n\n";
cout<<" Play with\t [F] a Friend    or  \t[c] computer\n";
cin>>w;
if(w=='f'||w=='F'|| w=='c'||w=='C')
{
 with=w;
}
else
{
 system("cls");
 goto again_choice;

}
 system("cls");
}

 void restart(){
 system("cls");
    a[0]="1"; a[1]="2"; a[2]="3"; a[3]="4"; a[4]="5"; a[5]="6"; a[6]="7"; a[7]="8"; a[8]="9";
    for(int i=0;i<9;i++)
    b[i]=0;
    if(start==2)
    c=1;
    else
    c=0;
isDone=false;
 }
int levelchose(){
char l; int level;
cout<<"\t\t choice level\n";
cout<<"\t[E] Easy \t [M] Medium\t [H] Hard "<<endl;
cin>>l;
switch(l)
{
case 'e':
case'E':
   level=1;
break;
case 'm':
case'M':
   level=2;
break;
case 'h':
case'H':
   level=3;
break;
default:
system("cls");
levelchose();
}
return level;
}
