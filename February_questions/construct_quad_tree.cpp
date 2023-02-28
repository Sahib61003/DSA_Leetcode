//Problem: Construct Quad Tree
//Link: https://leetcode.com/problems/construct-quad-tree/

//Code:
Node* zero = new Node(false, true);
Node* one = new Node(true, true);

class Solution {
public:
    Node* create(vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 1) {
            return grid[x][y] == 1 ? one : zero;
        }
        int mid = n / 2;
        Node *topLeft = create(grid, x, y, mid);
        Node *topRight = create(grid, x, y+mid, mid);
        Node *botLeft = create(grid, x+mid, y, mid);
        Node *botRight = create(grid, x+mid, y+mid, mid);
        if (topLeft == topRight and botLeft == botRight and topLeft == botLeft) {
            return topLeft;
        }
        return new Node(false, false, topLeft, topRight, botLeft, botRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return create(grid, 0, 0, grid.size());    
    }
};

/*Explanation of the code:
    1. We will use a function to create the quad tree.
    2. We will use a base case to check if the size of the grid is 1.
    3. We will use a mid variable to store the mid value of the grid.
    4. We will use a topLeft variable to store the top left node of the grid.
    5. We will use a topRight variable to store the top right node of the grid.
    6. We will use a botLeft variable to store the bottom left node of the grid.
    7. We will use a botRight variable to store the bottom right node of the grid.
    8. We will use a if condition to check if the topLeft, topRight, botLeft and botRight are equal.
    9. If they are equal then we will return the topLeft.
    10. Else we will return a new node with topLeft, topRight, botLeft and botRight as its children.
    11. We will return the function call with the grid, 0, 0 and the size of the grid as the parameters.
*/

// Time Complexity: O(n^2)
