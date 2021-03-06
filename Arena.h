
#ifndef ARENA_H
#define ARENA_H

#include "Player.h"
#include "Robot.h"
#include "History.h"
#include "globals.h"
#include <iostream>


using namespace std;

class Player;
class Robot;
class History;
class Arena
{
public:
	// Constructor/destructor
	Arena(int nRows, int nCols);
	~Arena();

	// Accessors
	int     rows() const;
	int     cols() const;
	Player* player() const;
	int     robotCount() const;
	int     nRobotsAt(int r, int c) const;
	bool    determineNewPosition(int& r, int& c, int dir) const;
	void    display() const;
	History& history();

	// Mutators
	bool   addRobot(int r, int c);
	bool   addPlayer(int r, int c);
	bool   attackRobotAt(int r, int c, int dir);
	bool   moveRobots();

private:
	int     m_rows;
	int     m_cols;
	Player* m_player;
	Robot*  m_robots[MAXROBOTS];
	History m_History;
	int     m_nRobots;


};

#endif // !ARENA_H