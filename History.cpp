#pragma once

#include "History.h"

History::History(int nRows, int nCols) {
	//Specs say do not check for invalid Row/Cols
	m_nRows = nRows;
	m_nCols = nCols;
	m_history.resize(nRows); //grow rows by n_rows
	for (int i = 0; i < nRows; ++i)
		m_history[i].resize(nCols); //for each row, grow col by nCols
	
	for (int i = 0; i < nRows; ++i) //Initialize all spots with 0 (by default)  Inefficient, but it works
		for (int j = 0; j < nCols; ++j)
			m_history[i][j] = 0;
}

bool History::record(int r, int c) {
	if (r < 1 || r>m_nRows || c < 1 || c>m_nCols) //If out of bounds
		return false;
	m_history[r-1][c-1] += 1; //successfully adds 1 to entire matrix.
	//cout << "Current is:" << m_history[r-1][c-1]<<endl;
	return true;
}

void History::display()const {
	clearScreen();
	for (int r = 0; r < m_nRows; r++)
	{
		for (int c = 0; c < m_nCols; c++) 
		{
			if (m_history[r][c] == 0)
				cout << '.';
			else if (m_history[r][c] >= 1 && m_history[r][c] <= 25)
				cout << (char)('A' + m_history[r][c]-1);
			else
				cout << 'Z';
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
}