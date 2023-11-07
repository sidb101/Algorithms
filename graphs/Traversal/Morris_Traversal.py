""" 
Traverse a binary tree (inorder) without auxiliary stack space.

Advanced technique to thread a binary tree, relies on leveraging the 
unused "right" pointers of nodes with no right children.

TC: O(V)
SC: O(1)
"""

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def print_tree(root: TreeNode):
    def process_node(node: TreeNode):
        print(node.val)

    curr = root
    while curr:
        if curr.left:
            friend = curr.left
            while friend.right and friend.right != curr:
                friend = friend.right
            if not friend.right:
                friend.right = curr
                curr = curr.left 
            else:
                friend.right = None
                process_node(curr)
                curr = curr.right
        else:
            process_node(curr)
            curr = curr.right

    return 