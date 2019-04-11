# Algorithm
![](https://github.com/polly-culler/Algorithm/blob/master/Algorithm.png)
## 分治法  
### 原理  
### 二分法（binSearch）
  1. 例：find 21  
  
   5 | 13 | 19 | 21 | 37 | 56 | 64 | 75 | 80 | 92  
 **step1:** 取这11个数的中间数，即第6个数为mid = 56  
  21 < mid = 56 ; 说明在1-5之间 high = mid-1；   
 **step2:** 取1-5的中间数，即第三个数为mid = 19  
  21 > mid 说明在4-5之间  
 **step3:** 取4-5之间的数,   
  find no.4 =21 success. :blush:  
#### [code](https://github.com/polly-culler/Algorithm/blob/master/%E5%88%86%E6%B2%BB%E6%B3%95/%E4%BA%8C%E5%88%86%E6%B3%95/binSearch.c)  
___ 
### 快速查询(quickSort)
#### [code](https://github.com/polly-culler/Algorithm/blob/master/%E5%88%86%E6%B2%BB%E6%B3%95/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F/quickSort.c)


## 动态规划  
 1. 原理
	将所有的解决方案全部求出来，然后会找到一个最优解，通过最优解然后回溯找回最优解选取的方式是什么。
 2. 例：如图	

|  i | 1  |2   | 3  |4   |
| :------------: | :------------: | :------------: | :------------: | :------------: |
| wi(重量)  | 2  | 3  | 4  | 5  |
| vi(价值)  | 3  |4   | 5  |6   |


设背包的容量capacity＝8		

#### 1.背包容量比该商品体积小，装不下，此时的价值与前i-1个的价值一样：**v（i，j)=v(i-1,j)**	
#### 2.有足够的容量装下，但价值不是最优的	
**v（i，j）=max{v(i-1,j),v(i-1,j-w(i))+v(i)}**
