class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            vector<string> rows(9), columns(9), boxes(9);
            bool flag = true;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    rows[i] += board[i][j];
                    columns[j] += board[i][j];
                    boxes[i / 3 * 3 + j / 3] += board[i][j];
                }
            }
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    char currentChar = board[i][j];
                    if (currentChar != '.')
                    {
                        auto currentBoxPos = boxes[i / 3 * 3 + j / 3].find(currentChar);
                        if (rows[i].find(currentChar, j + 1) != string::npos || columns[j].find(currentChar, i + 1) != string::npos || boxes[i / 3 * 3 + j / 3].find(currentChar, currentBoxPos + 1) != string::npos)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (!flag) break;
            }
            return flag;
        }
};