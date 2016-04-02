
///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

#include "Player.h"

Player::Player(Arena* ap, int r, int c)
{
	if (ap == nullptr)
	{
		cout << "***** The player must be in some Arena!" << endl;
		exit(1);
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
	{
		cout << "**** Player created with invalid coordinates (" << r
			<< "," << c << ")!" << endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
	m_age = 0;
	m_dead = false;
}

int Player::row() const
{
	return m_row;
}

int Player::col() const
{
	return m_col;
}

int Player::age() const
{
	return m_age;
}

void Player::stand()
{
	m_age++;
}

void Player::moveOrAttack(int dir)
{
	m_age++;
	int r = m_row;
	int c = m_col;
	int old_r = m_row;
	int old_c = m_col;
	if (m_arena->determineNewPosition(r, c, dir))
	{
		if (m_arena->nRobotsAt(r, c) > 0)
		{
			if (m_arena->attackRobotAt(r, c, dir)) //if attack and killed, then record.  Returns true if robot is killed.m_arena->attackRobotAt(r, c, dir)
				m_arena->history().record(old_r, old_c);
		}
		else
		{
			m_row = r;
			m_col = c;
		}
	}
}

bool Player::isDead() const
{
	return m_dead;
}

void Player::setDead()
{
	m_dead = true;
}