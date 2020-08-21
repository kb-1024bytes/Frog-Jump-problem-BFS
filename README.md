# Frog-Jump-problem-BFS
There are total of 7 spaces, 3 leftmost spaces contain a frog each of one family  while the 3 rightmost spaces contain a frog each of second family. The 3 frogs  on left need to be transfered to 3 rightmost positions while 3 frogs on right need to be transfered to 3 leftmost positions, but the condition is that each and every  one of the frog can jump either to next position in left or right of it (if empty) or to two places to left or right (if empty). Find a suitable set of instructions to get to final position.

Inital State(Input):
FROG1 FROG1 FROG1 ___ FROG2 FROG2 FROG2

Final State(Output):
FROG2 FROG2 FROG2 ___ FROG1 FROG1 FROG1 (where FROG1 denotes frog of first family and FROG2 denotes frog of second family)

Idea: This can be solved by making a tree structure and then applying bfs to find the required state. The root of this tree is initial state, lets denote the state at one time by 'x' to denote frog of one family, 'o' to denote frog of other family, '_' to denote space. So, the initial state becomes: ooo_xxx and final state is xxx_ooo.
The root node contains xxx_ooo, and information of its 4 children and its parent.
To generate children of a node, just move the space ('_') to left, right, left to left and right to right of its position in parent node (if the state is valid, otherwise the child will be null). Keep building the tree untill the goal state is found and once the goal state is found print the path in reverse order from that node to root using the pointer of its parent.
