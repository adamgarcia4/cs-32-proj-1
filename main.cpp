// robots.cpp

#include <iostream>
#include <utility>
#include <cstdlib>
#include "Game.h"
#include "History.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////

int main()
{
	// Create a game
	// Use this instead to create a mini-game:   Game g(3, 4, 2);
	//Game g(7, 8, 28);
	History h(3, 3);
	int cont = 1;
	int r = 0;
	int c = 0;
	while (cont)
	{
		cout << "R" << endl;
		cin >> r;
		cout << "C" << endl;
		cin >> c;
		h.record(r, c);

		h.display();
	}
	//h.record(1, 1);
	
	system("pause");
	// Play the game
	//g.play();

}