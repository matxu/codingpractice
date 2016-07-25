// Check if there is a route between two nodes in a directed graph

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        queue<DirectedGraphNode *> myqueue;
        myqueue.push(s);
        DirectedGraphNode* curnode;
        
        while ( !myqueue.empty()){
            curnode = myqueue.front();
            myqueue.pop();
            
            if ( curnode == t ) return true;
            
            for( int i=0; i<curnode->neighbors.size(); i++)
                myqueue.push(curnode->neighbors[i]);
            
        }
        
        return false;
    }
};

