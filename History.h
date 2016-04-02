#ifndef HISTORY_H
#define HISTORY_H

#include "globals.h"
#include <iostream>
#include <vector>
using namespace std;

class History
{
	public:
		History(int nRows, int nCols);
		bool record(int r, int c);
		void display()const;

	private:
		int m_nRows;
		int m_nCols;
		vector< vector<int> > m_history; //allows multidimensional matrix to be dynamically allocated.
		
};

#endif
