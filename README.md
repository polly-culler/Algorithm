# Algorithm
## 分治法
### 二分法（binSearch）
  1. 例：find 21  
  
   5 | 13 | 19 | 21 | 37 | 56 | 64 | 75 | 80 | 92  
 step1: 取这11个数的中间数，即第6个数为mid = 56 
        21 < mid = 56 ; 说明在1-5之间 high = mid-1； 
  step2: 取1-5的中间数，即第三个数为mid = 19  
        21 > mid 说明在4-5之间 
  step3: 取4-5之间的数， 
        find no.4 =21 success. :blush: 
#### code    
