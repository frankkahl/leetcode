// 85. Maximal Rectangle                                              [Hard]
//
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example 1:
//
// []
//
//     Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//     Output: 6
//     Explanation: The maximal rectangle is shown in the above picture.
//
// Example 2:
//
//     Input: matrix = [["0"]]
//     Output: 0
//
// Example 3:
//
//     Input: matrix = [["1"]]
//     Output: 1
//
// Constraints:
//
// - rows == matrix.length
// - cols == matrix[i].length
// - 1 <= rows, cols <= 200
// - matrix[i][j] is '0' or '1'.
// https://leetcode.com/problems/maximal-rectangle/

#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const auto max_row = matrix.size();
        int max_rectangle = 0;
        for (size_t row = 0 ; row < max_row ; ++row) {
            // this assumes that all nested vectors have the same dimension
            const auto max_col = matrix.begin()->size();
            for (size_t col = 0 ; col < max_col ; ++col) {
                if (matrix[row][col] == '1') {
                    max_rectangle = std::max(max_rectangle, max_rectangle_at_pos(matrix, max_row, max_col, row, col));
                }
            }
        }
        return max_rectangle;
    }
private:
    // this method assumes that at position (row, col) the cell contains a '1'
    // This check could also be moved into this method, but doing the check in the calling method minimizes the total
    // number of calls to max_rectangle_at_pos()
    // This method computes the maximum area of all rectangles consisting of '1' where (row, col) is at its top, left corner.
    int max_rectangle_at_pos(const vector<vector<char>>& matrix, const int max_row, const int max_col, int row, int col) {
        int max_area = 0;
        auto curr_row = row;
        int min_col_count = 0;
        while (curr_row < max_row && matrix[curr_row][col] == '1') {
            auto curr_col = col;
            while (curr_col < max_col && matrix[curr_row][curr_col] == '1') {
                ++curr_col;
            }
            if (curr_row == row) {
                min_col_count = curr_col - col;
            }
            else {
                min_col_count = ::min(curr_col - col, min_col_count);
            }
            max_area = std::max((curr_row - row+1)*min_col_count, max_area);
            ++curr_row;
        }
        return max_area;
    }
};
