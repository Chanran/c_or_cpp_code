# 记录一些C/C++的代码

## 计算机图形学

### bresenham.cpp(画直线)

> 使用bresenham算法和openGL库来进行画直线，支持平面内所有的直线

### boundaryFill8.cpp(填充)

> 使用种子填充算法（八连通）和openGL库来进行填充，对比较大的图形的填充实现不是很好（可能也跟本人的电脑有关）

### transformation.cpp(图形变换)

> 使用齐次坐标计算和openGL库进行对三角形的平移、旋转、缩放。封装了一个矩阵乘法

## 算法

### coinsGroups.cpp(钱币组合问题)

具体看我的博客解释：[钱币组合问题](https://chanran.github.io/2016/12/23/moneyGroup/)

### intervalInsect.cpp(区间相交问题)

具体看我的博客解释：[区间相交问题](https://chanran.github.io/2016/12/23/sectionIntersect/)

### buildBaseStation.cpp(基站建设)

具体看我的博客解释：[基站建设](https://chanran.github.io/2016/12/24/baseStation/)

### 01背包的三种算法(动态规划，贪心，回溯)

1. 01backpack_dynamic_planning.cpp (动态规划)
2. 01backpack_greedy.cpp (贪心)
3. 01backpack_backTrack.cpp (回溯)

具体看我的博客解释：[01背包的三种算法](https://chanran.github.io/2016/12/31/01package-algorithm/)

### findLargestKmin (从两个有序的数组里找出第K小的数)

> 从两个有序的数组中找出第K小的数，使用分治法将两个数组分割，递归的寻找第K小的数。难点在与边界的划分。（具体写篇博客来分析一下）


### countInversion.cpp（额，忘了是什么题目，等OJ系统开放了需要回去找找）

### getMode.cpp (分治法求众数)

> 使用分治法求众数。（二年前的。。。需要回忆一下，有空写篇博客）

### patrol_soldier.cpp(巡逻的士兵)

> 使用分治法求众数。（二年前的。。。需要回忆一下，有空写篇博客）

## C++课程

### findLargestBlock(寻找最大子矩阵)

> 主要是考察C++动态数组vector

具体看我的博客解释：[寻找最大子矩阵](https://chanran.github.io/2016/12/16/find-largest-matrix-block/)

### complexClass(复数类)

> 主要是考察C++运算符重载

具体看我的博客解释：[Complex类，运算符重载](https://chanran.github.io/2016/12/16/operator-overloading/)

### checkAccount(模拟银行账户)

> 主要是考察C++面向对象的知识

暂无博客解释

### spit_and_merge_file.cpp(分割与合并文件)

> 主要是考察C++文件读写

具体看我的博客解释：[分割与合并文件](https://chanran.github.io/2016/12/16/split-merge-file/)

### countWordSTL.cpp(统计文件单词数目)

> 主要是考察C++ STL

暂无博客解释
