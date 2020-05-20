#include<iostream>
#include<fstream>
#include<stack>
#include "Number.cpp"
using namespace std;


void FillBoard(int **gameboard,Number ***PlayArea){
		for(int i=0;i<9;i++){
		gameboard[i]=new int[9];
	}
	cout<<"Please enter the Sudoku Puzzle. Left to Right, Going from Top to Bottom. Enter 0 if the Spot is empty"<<endl;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>gameboard[i][j];
		}
	}
	for(int i=0;i<9;i++){
	 	PlayArea[i] = new Number*[9];
	 }
	 for(int i =0 ;i<9;i++){
	 	for(int j=0;j<9;j++){
	 		if(gameboard[i][j]!=0)
	 			PlayArea[i][j]= new Number(gameboard[i][j],i,j,false);
	 		else	
			 	PlayArea[i][j]=new Number(gameboard[i][j],i,j);
		 }
	 }
}

void PrintBoard(Number ***PlayArea){
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<PlayArea[i][j]->getValue()<<" ";
		}
		cout<<endl;
	}
}
bool** isPreFilled(int **gameboard){
	
	bool ** PreFilled = new bool*[9];
	for(int i=0;i<9;i++){
		PreFilled[i]=new bool[9];
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(gameboard[i][j]>0)
				PreFilled[i][j]=true;
			else
				PreFilled[i][j]=false;		
		}
	}
	
	return PreFilled;
}

bool Conflict(Number *P,Number ***PlayArea){
	for(int i=0;i<9;i++){
		
		if(i==P->getRow())
			continue;
		else if(P->getValue()==PlayArea[i][P->getColumn()]->getValue())
			return true;		
	}
	for(int i=0;i<9;i++){

		if(i==P->getColumn())
			continue;
		else if(P->getValue()==PlayArea[P->getRow()][i]->getValue())
			return true;		
	}
	
	if(P->getRow()>=0 && P->getRow()<=2){
		if(P->getColumn()>=0 && P->getColumn()<=2){
			for(int i=0;i<=2;i++){
				for(int j=0;j<=2;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		}
		else if(P->getColumn()>=3 && P->getColumn()<=5){
			for(int i=0;i<=2;i++){
				for(int j=3;j<=5;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		}
		else if(P->getColumn()>=6 && P->getColumn()<=8){
			for(int i=0;i<=2;i++){
				for(int j=6;j<=8;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		} 
			
	}
	 else if(P->getRow()>=3 && P->getRow()<=5){
	 	if(P->getColumn()>=0 && P->getColumn()<=2){
			for(int i=3;i<=5;i++){
				for(int j=0;j<=2;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		}
		else if(P->getColumn()>=3 && P->getColumn()<=5){
			for(int i=3;i<=5;i++){
				for(int j=3;j<=5;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		}
		else if(P->getColumn()>=6 && P->getColumn()<=8){
			for(int i=3;i<=5;i++){
				for(int j=6;j<=8;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		} 
	 }
		else if(P->getRow()>=6 && P->getRow()<=8){
	 		 	if(P->getColumn()>=0 && P->getColumn()<=2){
			for(int i=6;i<=8;i++){
				for(int j=0;j<=2;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		}
		else if(P->getColumn()>=3 && P->getColumn()<=5){
			for(int i=6;i<=8;i++){
				for(int j=3;j<=5;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		}
		else if(P->getColumn()>=6 && P->getColumn()<=8){
			for(int i=6;i<=8;i++){
				for(int j=6;j<=8;j++){
					if(i==P->getRow() && j==P->getColumn())
						continue;
					else if(P->getValue()==PlayArea[i][j]->getValue())	
						return true;
				}
			}
		} 	
	}
return false;		
}

bool Solver(int **gameboard, bool **PreFilled,Number ***PlayArea){
   
	int i,j;
	bool flag=false;
	for( i=0;i<=8;i++){
		for( j=0;j<=8;j++){
			if(PreFilled[i][j]==false){	
				flag=true;
				break;
		}
	  }
	  if(flag==true)
	  	break;
	}

	stack<Number*> solution;

	int current_column=0;
	int current_row=0;
	
	
	for(int k=1;k<=9;k++){			
		PlayArea[i][j]->updateValue(k);
	
		if(Conflict(PlayArea[i][j],PlayArea)==true)
			continue;
		else{
			current_column=(PlayArea[i][j]->getColumn())+1;
			current_row=(PlayArea[i][j]->getRow());
			solution.push(PlayArea[i][j]);
			break;	
		}
	}


bool backtrack=false;
	while(solution.size()!=0){
   		

		   
			if(current_column>=9 ){
				current_row+=1;
				current_column=0;
					if(current_row>=9)
      					break;
		    }
		
		if((PlayArea[current_row][current_column]->getStatus())==false){

			current_column++;
			continue;
		}

		if(backtrack==true){
			Number *temp=solution.top();
			solution.pop();
			current_row=temp->getRow();
			current_column=temp->getColumn();
		}
		
		int k;
		for( k=(PlayArea[current_row][current_column]->getValue())+1;k<=9;k++){
			PlayArea[current_row][current_column]->updateValue(k);
			if(Conflict(PlayArea[current_row][current_column],PlayArea)==true){
				continue;
			}
			else{
				solution.push(PlayArea[current_row][current_column]);
				current_column++;
				backtrack=false;
				break;
			}
		}
		if(k>9){
			PlayArea[current_row][current_column]->updateValue(0);
			backtrack=true;
		
		}
	}
}

int main(){
	int **gameboard = new int*[9];
	
	 Number ***PlayArea = new Number **[9];

	FillBoard(gameboard,PlayArea);
   	cout<<endl;

	bool **PreFilled = isPreFilled(gameboard);
	
	Solver(gameboard,PreFilled,PlayArea);
   
   PrintBoard(PlayArea);

	
}
