# LeetCode
## Note
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
* 特殊情況時需要添加 dummyNode (比如只反轉前三個節點)
* 快慢指針
    * 找入環口<br><img src="images/proof_slow_fast_pointer.png" alt="碰面一定在入門口證明圖" width="50%" height="50%"/>

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

## Too Hard
| # | Title |
|---| ----- |
|2517|[Maximum Tastiness of Candy Basket](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/)|
