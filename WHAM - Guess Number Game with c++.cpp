#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

class code
{
	public:
		void menus();
		generate(int);
		void rules(int);	
		void guess(int);
		void check(int arr[], int arr2[], int);
	private:
		int rand0m[4];
		char answer[4];
		int result[4];
		int coba;
};

void code::menus()
{
	code c;
	system("cls");
	cout<<"-= REND RAY =-"<<endl;
	cout<<"--------------"<<endl;
	cout<<endl;
	int n = 4;
	int a=0;
	int choice;
	cout<<"Select the Level :	"<<endl;
	cout<<"1. Beginner		"<<endl;
	cout<<"2. Intermediate	"<<endl;
	cout<<"3. Advanced		"<<endl;
	cout<<"4. Impossible	"<<endl;
	while(a<1){	
		cout<<"\nYour Choice : ";
		cin>>choice;
		if(choice == 1){
			cout<<"NZWV YB FMRGB";
			system("cls");
			c.generate(n);
			a++;
		}else{
			cout<<"Beta version doesn't provide this level\n";
		}
	}
}


code::generate(int n){
	srand(time(NULL));
	cout<<"Type any 4 numbers, e.g: 1234";
	cout<<endl;
	cout<<endl;
	for(int i=0;i<n;i++){
		rand0m[i] = rand() % 10;
		cout<<"|___|";
	}
	cout<<endl;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(rand0m[i]==rand0m[j]){
				rand0m[i] = rand() % 10;
			}
		}
		for(int j=i+1;j<n;j++){
			if(rand0m[i]==rand0m[j]){
				rand0m[i] = rand() % 10;
			}
		}
	}
	cout<<endl;
	guess(n);
}

void code::guess(int a){
	cout<<"Guess the Number : ";
	cin>>answer;
	if(sizeof(answer) < 4){
		cout<<"Your answer must be consisted of 4 digits'";
		cout<<endl;
		guess(a);
	}else{
		for(int i=0;i<a;i++){
			result[i] = answer[i] - '0';
		}
		check(result, rand0m, a);
	}
}

void code::check(int answer[], int rand0m[], int n){
	int p,a=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(answer[j] == rand0m[i]){
				a = a + 1;
				j=n;
			}
		}
		if(answer[i] == rand0m[i]){
			p += 1;
		}
	}
	
	coba += 1;
	cout<<"-=====-==============-=================-"<<endl;
	cout<<"| NO. | Your Guesses |  Correct Answer |"<<endl;
	cout<<"|-===-|-============-|Position | Number|"<<endl;
	cout<<"| "<<coba<<setw(7)<<"|   ";
	for(int i=0;i<n;i++){
		cout<<answer[i]<<" ";
	}
	cout<<"   |    "<<p<<"    |   "<<a<<"   |"<<endl;
	cout<<"-=====-==============-=================-"<<endl;
	cout<<endl;
	char gu;
	if(coba > 4 && coba % 5 == 0 && p != 4 && a != 4){
		cout<<"Just Give Up ! (Y) = ";
		cin>>gu;
		if(gu == 'Y' || gu == 'y'){
			for(int i=0;i<n;i++){
				cout<<"["<<rand0m[i]<<"] ";
			}
		cout<<endl<<"-= Game Over, Loser! *YOLO* =-";
		}else{
			guess(n);
		}
	}else if(p == 4 && a == 4){
		cout<<"-= Congratulation! You Guess The Number =-"<<coba;
	}else{
		guess(n);	
	}
}

main()
{
	code c;
	c.menus();
}
