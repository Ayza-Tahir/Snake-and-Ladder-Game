#include <iostream>       //cin,cout
#include <queue>        //STL queue
#include<cstdlib>           //Random generate
#include<ctime>           //time 
using namespace std;

class game
{

public:

	string name;
	int n = 0;

	void Players(int num)
	{

		queue<string>qname;      //name store
		queue<int>qscore;         //marks store
		queue<string>qresult;  //wining result with name
		

		cout << "Enter Name's of Players" << endl;
		cout << endl;
		for (int i = 0; i < num; i++)                 //queue names
		{
			cout << " Player" <<" " << i + 1 << " " << ":";
			cin >> name;
			qname.push(name);
		}

		cout << endl;

		for (int i = 0; i < num; i++)               //queue scores
		{
			qscore.push(0);                   //not start game
		}

		cout << "                                           " << ":) LET'S PLAY THE GAME :)" << endl;
		cout << endl;

		while (n != num - 1)             //ending condition
		{

			int i = 0;

			for (i = 0; i < num; i++)
			{


				cout << "Player " << " " << qname.front() << " " << "turn";
				cout << endl;

				char dice;
				cout << "Enter R or r to roll the dice" << endl;
				cin >> dice;

				int total;
				if (dice == 'R' || dice == 'r')
				{
					srand(time(0));          //always generate different number
					int num;
					num = rand() % 6 + 1;  // 6 =0-5 then 0+1=1  5+1=6

					cout << qname.front() << " " << "got" << " " << num << endl;

					total = num + qscore.front();
					cout << "Total Score of" << " " << qname.front() << " " << total << endl;



					if (total == 20)    //ladder 1
					{
						total = 40;
						cout << "Now Score is" << " " << total <<" " << "Because of ladder" << endl;
					}

					if (total == 60)     //ladder 2
					{
						total = 75;
						cout << "Now Score is" << " " << total <<" " << "Because of Ladder" << endl;
					}

					if (total == 50)        //snake 1
					{
						total = 40;
						cout << "Now Score is" << " " << total <<" " << "Because of SNAKE BITE" << endl;
					}

					if (total == 90)         //snake 2
					{
						total = 79;
						cout << "Now Score is" << " " << total <<" " << "Because of SNAKE BITE" << endl;
					}

					if (total > 100)          //exceed then 100
					{
						total = total - num;      //remain same score
						cout << "Now Score is" << " " << total << " " << "Because of it exceed than 100 and cannot add last score" << endl;
					}

					if (total == 100)            //wining condition
					{
						qresult.push(qname.front());             //name 
						  
						n = n + 1;           //show that perosn is now out of the game
						qname.pop();           //no longer part game
						qscore.pop();
					}

					if (total < 100)       //remain part of game
					{
						qname.push(qname.front());      //front last after its turn to allow second player to play
						qname.pop();

						qscore.pop();           //front previous remove
						qscore.push(total);         //new score push
					}
				}

				cout << endl;
				cout << endl;



			}
		}

		cout << endl;
		int j = 1;
		while (!qresult.empty())            //final result display
		{
			cout << qresult.front() << " " << "got" << " " << "Position" <<" " << j << endl;
			j = j + 1;
			qresult.pop();
		}
		cout << qname.front() << " " << "got Last Position" << endl;         //because part of the game queue but game ends
		qname.pop();
		qscore.pop();

		cout << endl;
		
	}
	
	
	
};
int main()
{
	game g;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                       " << " SNAKES AND LADDER GAME" << endl;
	cout<<endl;
	int num;
	cout << "Enter the number of players wants to Play the Game" << endl;
	cin >> num;
	cout << endl;
	g.Players(num);        
	cout << endl;
	cout << "                                              " << ":( GAME END :(" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;

	return 0;

}