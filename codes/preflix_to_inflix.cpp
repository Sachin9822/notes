#include<iostream>

using namespace std;

#define MAX 100

class preflix2inflix{
	string arr[MAX];
	int top;
	string user_input;
	
public:
	preflix2inflix(){
		top = -1;
	}
	bool operator_(char ch){
		string operato = "+-%/*^";
		for(int i = 0; i<operato.length();i++){
			if(ch == operato[i])
				return true;
			}
		return false;
	}
	void input(){
		cout<<"Enter the Postflix expression: ";
		user_input = "+A*-*BC*/D^EFGH";
	}
 	void convert();
 	void display(){
 		cout<<arr[0]<<"\n";
 	}
};
	preflix2inflix t;

void preflix2inflix::convert(){
 		for(int i =user_input.length()-1;i>-1;i--){
 		// 			cout<<"top : ";
 		// 		for(int k = top;k>-1;k--){
 		// 			cout<<arr[top-k]<<"  ";
 		// 		}
 		// 		cout<<endl;
 		// 	cout<<"arr = ";
 		// 	t.display();
 			// cout<<"\n"<<user_input[i]<<endl;
 			// cout<<endl;
 			if(operator_(user_input[i])){
 				if(top>0){
 				string temp = "("+arr[top]+user_input[i]+arr[top-1]+")";
 				arr[top---1] = temp;
 				// cout<<"temp : "<<temp<<endl;
 				}
 				else
 					cout<<"empty\n";
 			}
 			else{
 				arr[++top] = user_input[i];
 			}
 		}
 	}

int main(){
	t.input();
	t.convert();
	cout<<"\nInflix : ";
	t.display();
	return 0;
}