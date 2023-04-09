//Problem: Clone Graph
//Link: https://leetcode.com/problems/clone-graph/ 

//Code:
class Solution {
public:    
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node){
        if(node == NULL)
            return NULL;
        if(mp.find(node) != mp.end())
            return mp[node];
        Node* newly_created_node = new Node(node -> val);
        mp[node] = newly_created_node;
        for(Node* &it : node -> neighbors)
        {
            Node* adjacent = cloneGraph(it);
            newly_created_node -> neighbors.push_back(adjacent);
        }
        return newly_created_node;
    }
};


/*Explanation of the Code:
    1. The first line defines a class called "Solution".
    2. The next line declares an unordered map called "mp". This map will be used to store the mapping between the original nodes and their corresponding cloned nodes.
    3. The next line defines a public function called "cloneGraph", which takes in a node of the graph as a parameter and returns a cloned node of the graph.
    4. The first few lines in the function check if the input node is NULL or if the node has already been cloned before. If either of these conditions is true, the function returns either NULL or the previously cloned node from the map.
    5. If the node is not NULL and has not been cloned before, a new node is created with the same value as the input node.
    6. The next line adds the mapping between the input node and the newly created node to the map.
    7. The for loop iterates through all of the neighbors of the input node and recursively calls the "cloneGraph" function for each neighbor.
    8. For each neighbor, a new node is created with the same value as the original neighbor, and this newly created node is added to the "neighbors" vector of the newly created node.
    9. Finally, the function returns the newly created node, which is a cloned copy of the input node and its neighboring nodes.
*/

//Time Complexity: O(V+E)
