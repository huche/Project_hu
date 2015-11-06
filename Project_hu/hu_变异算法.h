#pragma once
/*
变异算法：主要特点是修改容器的元素：如：修改容器的元素值，改变容器中元素序列等
主要函数有：

1 复制函数：
copy() 从序列的第一个元素开始正向复制
copy_backward() 从最后一个元素起，进行逆向复制

2 交换函数：
swap()	交换两个元素
iter_swap()	交换由迭代器所指的两个元素
swap_ranges()	交换指定范围的元素

3 变换函数：
transform()	将某操作 应用于指定范围的每一个元素

4 替换函数：
replace()	用一些给定值替换一些值
replace_if()	替换满足条件的元素
repalce_copy()	复制序列时，用一给定值替换元素
repalce_copy_if()	复制序列时，替换满足条件元素

5 填充函数：
fill()	用一给定值，填充所有元素
fill_n()	用一给定值，填充前 n 个元素

6 生成函数：
generate()	用一操作的结果，填充所有元素
generate_n()	用一操作的结果，填充前n个元素

7 删除函数：
remove()	删除所有指定的元素
remove_if()	删除满足条件的的元素
remove_copy()	复制序列时，删除指定的元素
remove_copy_if()	复制序列时，删除满足条件的元素

8 去重函数：
unique()	删除相邻的重复元素
unique_copy()	复制序列时，删除相邻的重复元素

9 反转函数：
reverse()	 反转元素的次序
reverse_copy()	 复制序列时，反转元素的次序

10 循环移动：
rotate()	循环移动元素
rotate_copy()	复制序列时，循环移动元素

11 随机移动：
random_shuffle()	采用均匀分布来随机移动元素

12 划分
partition()	将满足条件的元素，都放在前面
stable_partition()		将满足条件的元素，都放在前面，并维持原来顺序





*/

