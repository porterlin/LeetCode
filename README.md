# LeetCode
## Note
### Prefix Sum
* 可以將 PrefixSum 陣列大小設為 n + 1，這樣就不用考慮 edge case 的情況 (e.g. 當 left = 0 時)
* ```c++
    // initialization
    for (int i = 0; i < n; i++) {
        PrefixSum[i + 1] = PrefixSum[i] + nums[i];
    }
    ```
* 要計算 [left, right] 加總的值時，要用 PrefixSum[right + 1] - PrefixSum[left]
### Two Pointers
* 如何用 O(1) 時間去得知 O(N) 資訊
* 靈活運用，不一定都是從小開始枚舉
### Sliding Window
* right - left + 1 的精髓
* 兩指針相互移動的過程其實就是在滿足條件跟不滿足條件來回
### Binary Search
* 循環不變量
* 要滿足單調性
* 區間內的是還沒確定的，區間外才是確定的
* 不一定對陣列做二分，原則上題目問什麼就對誰做
* 求最大最小之類的問題
### Linked List
* 反轉結束時，pre 指向反轉這段的最後節點，cur 指向反轉這段最後節點的下一個節點
* 特殊情況時需要添加 dummyNode (需要動到 head 的情況)
* 快慢指針
    * 找入環口<br><img src="images/proof_slow_fast_pointer.png" alt="碰面一定在入門口證明圖" width="50%" height="50%"/>
* 刪除節點
    * 必須有要刪除節點的上一個節點的 pointer，才有辦法正常刪除
    * 只給要刪除節點的 pointer，可以把下一個節點的 val 複製到當前，然後刪除下一個節點
    * 要刪除倒數第 n 個節點，可以用左右指針。右指針先走 n 步，然後左指針從頭開始跟右指針一起每次往下一步，直到右指針走到最後一個節  點。此時左指針剛好會指到要刪除節點的前一個節點
### Binary Tree
* 遞歸的核心就是不要去想子問題的過程，否則很容易想迷糊。只要邊界條件和非邊界條件的邏輯寫正確，其他就交給數學歸納法
* 兩種寫法，一種從上而下，一種從下而上

### Binary Search Tree
* 有三種方法: Preorder, Inorder, Postorder
    ![bst_three_approachs](images/bst_three_approachs.png)
* 順序
    1. Preorder: 根->左->右
    2. Inorder: 左->根->右
    3. Postorder: 左->右->根
* Postorder 最不好想

## Need to review again
| # | Title |
|---| ----- |
|2779|[Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/)|
|15|[3Sum](https://leetcode.com/problems/3sum/)|
|611|[Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/)|
|2962|[Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/)|
|76|[Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)|
|2563|[Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs/)|
|275|[H-Index II](https://leetcode.com/problems/h-index-ii/)|
|875|[Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)|
|2187|[Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/)|
|2439|[Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array/)|
|142|[Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)|
|143|[Reorder List](https://leetcode.com/problems/reorder-list/)|
|82|[Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)|
|3217|[Delete Nodes From Linked List Present in Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/)|
|2487|[Remove Nodes From Linked List](https://leetcode.com/problems/remove-nodes-from-linked-list/)|
|112|[Path Sum](https://leetcode.com/problems/path-sum/)|
|987|[Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)|
|110|[Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)|
|617|[Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)|
|1372|[Longest ZigZag Path in a Binary Tree](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)|
|1080|[Insufficient Nodes in Root to Leaf Paths](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/)|
|2476|[Closest Nodes Queries in a Binary Search Tree](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/)|
|1373|[Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)|

## Too Hard
| # | Title |
|---| ----- |
|2517|[Maximum Tastiness of Candy Basket](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/)|
