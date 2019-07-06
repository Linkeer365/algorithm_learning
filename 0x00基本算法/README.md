## 0x01
### 知识点：
#### 1、&，|,~,^的理解与运用.(cpp)
tips: b&1 表示取 <img src="http://chart.googleapis.com/chart?cht=tx&chl=$$(b)_2$$" style="border:none;">的第0位.
#### 2、补码的概念和特性.
(以32位二进制数为例)\
(1)、补码中每个数都有唯一的表示方式.\
(2)、在做加减运算时等价于二进制最高位不进位的加减法运算.(unsigned int溢出时自动对<img src="http://chart.googleapis.com/chart?cht=tx&chl=$$2^{32}$$" style="border:none;">取模，int会变负数)
#### 3、int和unsigned int的区别.
(1)、int 首位是符号位，0表示非负，1表示负.\
(2)、unsigned int 编码直接看作二进制数
#### 4、位移运算.
(1)、算术左移 1<<n=<img src="http://chart.googleapis.com/chart?cht=tx&chl=$$2^n$$" style="border:none;">\
     n<<1=<img src="http://chart.googleapis.com/chart?cht=tx&chl=$$2n$$" style="border:none;">(其中高位舍弃，低位填0)\
(2)、算术右移 n>>1=<img src="http://chart.googleapis.com/chart?cht=tx&chl=$$\lfloor \frac{n}{2} \rfloor$$" style="border:none;">.\
tips:"/"是向0取整.
##### 小应用:[快速幂取模](https://github.com/zezewww/algorithm_learning/blob/master/0x00%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x01_%E5%BF%AB%E9%80%9F%E5%B9%82.cpp)
#### 5、状态压缩的基本操作.(暂搁，到状压dp再看看)
#### 6、成对变化概念理解.(cpp)
(令n为非负整数)\
n为奇数，则n^1=n-1\
n为偶数，则n^1=n+1\
用于邻接表的储存.
#### 7、[lowbit运算的概念理解和推导.](https://github.com/zezewww/algorithm_learning/blob/master/0x00%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x00_lowbit%E8%BF%90%E7%AE%97%E6%80%BB%E7%BB%93.cpp)\

### 0x02
####下面是书中内容的一些摘抄：
_1、一个实际问题的各种可能情况构成的集合通常称为“状态空间”，而程序的运行则是对于状态空间的遍历，算法和数据结构则是通过划分、归纳、提取、抽象来帮助提高程序遍历的
状态空间效率。递推和递归就是程序遍历状态空间的两种基本方式._\
_2、递推：**以已知的“问题边界”为起点向“原问题”正向推导的扩展方式就是递推.**_\
_3、递归：**以“原问题”为起点尝试寻找把状态空间缩小到已知“问题边界”的路线，再通过该路线反向回溯的遍历方式就是递归.**_\
_4、递归算法中的3个操作：_
>_(1)、缩小问题状态空间的规模._\
>_(2)、尝试求解规模缩小以后的问题。结果可能成功也可能失败._\
>_(3)、如果成功，即找到了缩小规模后的答案，那么将答案扩展到当前问题。如果失败，那么重新回到当前问题，程序可能会继续寻找当前问题的其他变化路线，直至最终确定当前问题无法求解._

其实以上的三个操作就蕴含着DFS的基本思想，自身调用自身，寻找边界答案和回溯要还原现场。希望在后面学习DFS这一暴力大杀器的时候有帮助...(其实还是要多做题)
### 书中所列举的简单应用：
1、递归实现指数型枚举\
同时还用[位运算实现](https://github.com/zezewww/algorithm_learning/blob/master/0x00%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x02%E4%BD%8D%E8%BF%90%E7%AE%97%E5%AE%9E%E7%8E%B0%E6%8C%87%E6%95%B0%E6%9E%9A%E4%B8%BE(n%3C20).cpp)了一下，复习上一章所学的内容.\
2、递归实现组合型枚举\
3、递归实现排列型枚举\
看着书上的代码，看起来都是dfs啊...\
4、例题CH0201，[递推方法求解](https://github.com/zezewww/algorithm_learning/blob/master/0x00%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x02%E8%B4%B9%E8%A7%A3%E7%9A%84%E5%BC%80%E5%85%B3_%E9%80%92%E6%8E%A8(ch0201).cpp)和[递归方法求解](https://github.com/zezewww/algorithm_learning/blob/master/0x00%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x02%E8%B4%B9%E8%A7%A3%E7%9A%84%E5%BC%80%E5%85%B3_%E9%80%92%E5%BD%92(ch0201).cpp)\
5、[四盘汉诺塔问题](https://github.com/zezewww/algorithm_learning/blob/master/0x00%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x02%E6%B1%89%E8%AF%BA%E5%A1%94POJ1958.cpp)(书上对于递推的说明精炼到位，强).

