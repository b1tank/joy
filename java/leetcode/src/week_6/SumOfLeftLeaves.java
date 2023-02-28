package week_6;

import java.util.Stack;

public class SumOfLeftLeaves {
    private class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;
    }

    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null || isLeaf(root))
            return 0;
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        int res = 0;
        while (!st.empty()) {
            TreeNode cur = st.pop();
            if (isLeaf(cur)) {
                res += cur.val;
            }
            if (cur.right != null && !isLeaf(cur.right)) {
                st.push(cur.right);
            }
            if (cur.left != null) {
                st.push(cur.left);
            }
        }
        return res;
    }

    private boolean isLeaf(TreeNode node) {
        return node != null && node.left == null && node.right == null;
    }
}