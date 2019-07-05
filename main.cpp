#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// https://leetcode.com/problems/univalued-binary-tree/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    template<typename T>
    // function<void(TreeNode *)>
    void preorder(TreeNode *r, T fptr, bool &can_continue) {
        if (!r) return;
        fptr(r->val);
        if (can_continue)
            preorder(r->left, fptr, can_continue);
        if (can_continue)
            preorder(r->right, fptr, can_continue);
    }

    bool isUnivalTree(TreeNode *root) {
        if (!root) return true;
        int val = root->val;
        bool can_continue;
        auto lam = [&](int i) {
            can_continue = (i == val);
        };
        preorder(root, lam, can_continue);
        return can_continue;
    }
};

void test1() {
    auto t1 = new TreeNode("1,2,1,1,1,null,1");
    cout << "1 ? " << Solution().isUnivalTree(t1) << endl;
//    auto t2 = new TreeNode("2,2,2,5,2");
//    cout << "0 ? " << Solution().isUnivalTree(t2) << endl;
}

void test2() {

}

void test3() {

}