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

**原理：**

> 寻找一个基准元素，一般为该数组的第一个数。将小于基准元素的放在基准元素左边。大于基准元素的放在基准元素右边，再在基准元素左边进行排序，用同样的方法，同理基准元素右边也是。直到将这组元素排序完成。

**流程**

例：有一组元素为：

|6  |1  |2|7|9|3|4|5|10|8
|--|--|--|--|--|--|--|--|--|--|

假定基准元素为6，则：

 - step1：

|6  |1  |2|7|9|3|4|5|10|8
|--|--|--|--|--|--|--|--|--|--|
|i|||||||||j|
___
|6  |1  |2|7|9|3|4|5|10|8
|--|--|--|--|--|--|--|--|--|--|
||||i|<--交|换-->||j

> j先移动，寻找小于小于6的数，然后停下来，接下来i开始移动，寻找到大于6的数，交换。

|6  |1  |2|5|9|3|4|7|10|8
|--|--|--|--|--|--|--|--|--|--|
|||||i|<-交换->|j|

 - step2：
 

> j再向左移动，寻找小于6的数停止，i开始向右移动，找到大于6的数，停止，交换两数。

|6  |1  |2|5|*4*|3|*9*|7|10|8
|--|--|--|--|--|--|--|--|--|--|
|||||i|<-交换->|j|

 - step3:
 
 

> j再向左移动，到3，停止，i向右移动，遇到j。本次查找结束。将基准元素和3交换。

|6  |1  |2|5|4|*3*|9|7|10|8
|--|--|--|--|--|--|--|--|--|--|
||||||i
||||||j
---
|*3*  |1  |2|5|4|*6*|9|7|10|8
|--|--|--|--|--|--|--|--|--|--|

 - step4：排左边“3，1，2，5，4”和右边“9，7，10，8”的序

|3|1|2|5|4|
|--|--|--|--|--|
| i |  |||j|
|||i,j|

 - step5:

> 基准元素为3，i向左移动，到2<3停止，i向右移动，遇到j结束，交换

|2|1  |3|5|4|
|--|--|--|--|--|

 - step6：

> 分别对3的左边和右边进行查找；同理，结果为：

|1| 2 |3|4|5|
|--|--|--|--|--|

 - step7：

> 对“9，7，10，8”排序，基准元素为9，j=8<9，i开始向右移动

|9|7  |10|8|
|--|--|--|--|
| i |  |i<-|->j

> i=10>9，交换：9，7，8，10

 - step8：


> j向左移动，遇到i停止，与基准元素交换：8，7，9，10

 - step9：

> 排基准元素9左边的数，结果：7，8，9，10

**核心代码**

    void quickSort（int left, int right）{
	    int i,j,t,temp;
	    if(left>right) return;
	    temp = a[left];//基准数
	    i = left;
	    j = right;
	    while(i!=j){
		    while(a[j] >= temp && i < j) j--;//从右往左
		    while(a[i] <= temp && i < j) i++;//再从左往右
		    if(i < j){
			    t = a[i];
			    a[i] = a[j];
			    a[j] = t;
			}
		}
		a[left] = a[i]; 
		a[i] = temp; 
		quickSort(left,i-1);//处理左边 
		quickSort(i+1,right);//处理右边
	}
		 
	
		





## 贪心算法

> 在对问题求解时，总是做出在当前看来最好的选择，也就是说，不从整体最优解出发来考虑，它所做出的仅是在某种意义上的局部最优解。

**背包问题** 
	
步骤：
	

> 每种物品的单位重量作为贪心选择的依据指标，选择单位重量价值最高的物品，将尽可能多的该物品装入背包，依此策略一直地进行下去，直到背包装满为止。

流程：
例：有一个背包，背包容量M=150，有7个物品，物品可以**分割**成任意大小，要求尽可能让装入背包中的物品总价值最大，但不能超过总容量。


|物品：|A|B|C|D|E|F|G|
|--|--|--|--|--|--|--|--|
|重量：  | 35 |30|60|50|40|10|25
|价值：|10|40|30|50|35|40|30|
|单位价值：|0.28|1.33|0.5|1|0.87|4|1.2|


> 将物品按照单位重量价值进行排序（从大到小）


|  |F  |B|G|D|E|C|A
|--|--|--|--|--|--|--|--|
|W  | 10 |30|25|50|40|60|35
||<-----|**115**||---->


> 可整装的是F，B，G，D分装E，分装的重量为35
> 35 * 0.87 = 30.45
> W=40+40+30+50+30.45=190.45

**核心代码**

    
    

    int main(){
    	float M=150;//背包的容量
    	float w[]={35,30,60,50,40,10,25};
    	float v[]={10,40,30,50,35,40,30};
    	float x[N+1]={0};
    	knapSack(M,v,w,x);
    	count<<"选择装下的物品的比例\n"<<endl;
    	for (int i = 1; i <= N; ++i)
    	{
    		count<<"I"<<i<<"J";<<x[i]<<endl;
    	}
    }
    void knapSack(float M,float v[],float w[],float x[]){
    	int i;//物品整件被装下
    	for(i = 1; i <= N; i++){
    		if (w[i] > M)
    		{
    			break;
    		}
    		x[i] = 1;
    		M -= w[i];
    	}
    	if (i <= N)
    	{
    		x[i] = M/w[i];
    	}
    
    }



**多机调度**


## 动态规划  
 1. 原理
	将所有的解决方案全部求出来，然后会找到一个最优解，通过最优解然后回溯找回最优解选取的方式是什么。	
 
 **0-1背包问题**

2. 例：如图	

|  i | 1  |2   | 3  |4   |
| :------------: | :------------: | :------------: | :------------: | :------------: |
| wi(重量)  | 2  | 3  | 4  | 5  |
| vi(价值)  | 3  |4   | 5  |6   |


设背包的容量capacity＝8		

#### 1.背包容量比该商品体积小，装不下，此时的价值与前i-1个的价值一样：**v（i，j)=v(i-1,j)**	
#### 2.有足够的容量装下，但价值不是最优的	
**v（i，j）=max{v(i-1,j),v(i-1,j-w(i))+v(i)}**


填入表中

| i/j  | 0  |1   | 2  | 3  |4   |5   |6   |7   | 8  |
| :------------: | :------------: | :------------: | :------------: | :------------: | :------------: | :------------: | :------------: | :------------: | :------------: |
|   0|   **0**|   0|   0|   0|   0|   0|  0 |   0|   0|
|   1|   **0**|  0 |  3 |   3|  3 |3   |3   | 3  |3   |
|   2|   0|   0|   3|   **4**|   4| 7  |7   |  7 | 7  |
|   3|   0|   0|   3|   **4**| 5  |  7 | 8  |   9|  9 |
|   4|   0|   0|   3|   4| 5  |  7|   8|   9|**10**|

1. 根据表格的填写找到最优解为10
2. 通过回溯法查找装入的物品
- step1：最优解10=v(i,j)=v(4,8)
- step2：回溯到上一个v(3，8）！=v（4,8）
- step3：因为v(3,8)!=v(4,8)，所以使用公式v(i-1,j-w(i))+v(i)=v(3,8-5)+v(4)=v(3,3)+v(4)=10
- step4：找到v(3,3),向上回溯v(2,3)==v(3,3);所以选择v(2,3)
- step5：v(2,3)再向上回溯v(2,3)！=v(1,3)；使用公式v(i-1,j-w(i))+v(i)=v(1,3-3)+v(2)=4=v(2,3)
- step6：v(1,0)向上回溯v(0,1)==v(1,0)没有选择任何物品
> **所以选择的物品为v(2,3)和v(4,8),即选取2号和4号物品装入背包**

**流水作业调度**	

[简书链接](https://www.jianshu.com/p/31187617a7a0)



![enter image description here](https://upload-images.jianshu.io/upload_images/6650019-4804508f7ebb3df5.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1000/format/webp)

设n=3，背包容量c=8；
W=｛1，2，3｝ V={4，5，6}

---

> 考试分析：
> 1.渐进表达式
> 2.0-1背包：回溯法，分支限界法，动态规划，分治法
> 3.分治法求快速排序（平均时间复杂度，最好时间复杂度，最差时间复杂度，快速排序的思想）
> 4.贪心算法求解 单源最短路径问题
> 5.分治法和动态规划的区别
> 6.分治法，动态规划，贪心算法，回溯法，分支限界法的区别
> 7.回溯法与分支限界法的区别
> 8.概率算法
