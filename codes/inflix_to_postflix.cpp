#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int Max = 1000;
class inflix_2_postflix{
	char Postflix[Max];
	string ans;
	char simple_stack[Max];
	int top,top1;
	bool incorrect;
	string user_input;
	string opening_brackets;
	string closing_brackets;
	string operators;
public: 
	inflix_2_postflix(){
		opening_brackets = "({[";
		closing_brackets = ")}]";
		operators = "+-/*^%";
		top = -1;
		top1 = -1;
		incorrect = false;
	}
	void input_data();
	void parenthesis(char input);
	int signs(char input);
	void convert();
	int precedence(char operato);
	void evaluate();
};
inflix_2_postflix ip;

void inflix_2_postflix::evaluate(){
	int top3=-1;
	int evaluate_ans[20];
	/* char ans[] = {"+","+","2","6","+","-","13","2","4"}; */
ans = "35+64-*41-2^+";
	for(int i = 0 ;i<ans.length();i++){			
		if(ans[i]=='+'){
			evaluate_ans[top3-1]=evaluate_ans[top3-1]+evaluate_ans[top3];
			top3 --;
		}
		else if(ans[i]=='-'){
			evaluate_ans[top3-1]=evaluate_ans[top3-1]-evaluate_ans[top3];
			top3 --;
			 
		}
		else if(ans[i]=='*'){
			evaluate_ans[top3-1]=evaluate_ans[top3-1]*evaluate_ans[top3];
			top3 --;
			 
		}
		else if(ans[i]=='/'){
			evaluate_ans[top3-1]=evaluate_ans[top3-1] / evaluate_ans[top3];
			top3 --;
			 
		}
		else if(ans[i]=='^'){
			evaluate_ans[top3-1]=pow(evaluate_ans[top3-1],evaluate_ans[top3]);
			top3 --;
		}
		else if(ans[i]=='%'){
			evaluate_ans[top3-1]=evaluate_ans[top3-1]%evaluate_ans[top3];
			top3 --;
		}
		else{
			evaluate_ans[++top3]=(int)(ans[i]-'0');
		}
	}
		cout<<"Evaluated ans: "<<evaluate_ans[0]<<endl;
}


int inflix_2_postflix::precedence(char operato){
	if(operato == '^')
		return 3;
	else if (operato == '*' || operato == '/' || operato == '%')
		return 2;
	else if (operato == '+' || operato == '-')
		return 1;
	else{
		return 0;
	}
}
void inflix_2_postflix::parenthesis(char input){

	for(int i = 0 ; i<3;i++){
		if(input == opening_brackets[i]){
			simple_stack[++top] = input;
			break;
		}
		else if(input == closing_brackets[i]){
			if(top > -1){
// (+

				for(int z = top; z>-1;z--){
					if(simple_stack[z]==opening_brackets[i]){
						top -=1;
						break;
					}
					else{
						top -=1;
						
						Postflix[++top1] = simple_stack[z];
						
					}
				}

			}
			else{
				cout<<"Invalid Expression \n";
				incorrect = true;
				break;
			}
		}
		else if(signs(input)){
			if(precedence(simple_stack[top]) < precedence(input)){
			simple_stack[++top] = input;
			}

			else{
				Postflix[++top1] = simple_stack[top--];
				simple_stack[++top] = input;		
				if(precedence(simple_stack[top])==precedence(simple_stack[top-1])){
					Postflix[++top1] = simple_stack[top-1];
					simple_stack[top-1] = simple_stack[top];
					top -=1;
				}
			}
			break;
		}
		else{
			if(input != ')'){
			Postflix[++top1] = input;
			}
			break;
		}
	}
}
int inflix_2_postflix::signs(char input){
	for(int i = 0 ; i<operators.length();i++){
		if(input == operators[i]){
			return 1;
		}
	}
	return 0;
}
void inflix_2_postflix::input_data(){
	cout<<"Enter the Expression: \n";
	user_input = "A^B*C-D+E/F/(G+H)";
	// user_input = "((A+B)*C-(D-E))^(F+G)";
	user_input = "A-B/(C*D^E)";
	user_input = "(a+b^c^d)*(e+f/d))";
	user_input = "3-6*7+2/4*5-8";
	// user_input = "(A-B)/((D+E)*F)";
	// user_input = "((A+B)/D)^((E-F)*G)";


	// cin>>user_input;
}
void inflix_2_postflix::convert(){
	string temp = "";
	for(int i = 0; i<user_input.length();i++){
		ip.parenthesis(user_input[i]);
	}
	if(!incorrect){
		cout<<"Postflix : ";
		cout<<Postflix;
		temp += Postflix;
		
		for(int j = top;j>-1;j--){
			cout<<simple_stack[j];
			temp += simple_stack[j];
		}
		cout<<endl;
		cout<<temp<<endl;
		ans = temp;
	}	
}

int main(){
	ip.input_data();
	ip.convert();
	int i;
	cout<<"1: Evaluate \n2: exit\n";
	cin>>i;
	if(i == 1){
		ip.evaluate();
	}
	else if (i == 2){
		exit(0);
	}
	return 0;
}
