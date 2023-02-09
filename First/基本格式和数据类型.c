#include <stdio.h>  //引入标准库

/**
* 添加多行注释
 * 基本数据类型
 *https://blog.csdn.net/qq_25928447/article/details/125330694?spm=1001.2014.3001.5502
 *1111占用四个位置（4个bit位）来保存。一般占用8个bit位表示一个字节（B），2个字节等于1个字，
 * 所以一个字表示16个bit位，它们是计量单位。
 * 8 bit = 1 B ，1024 B = 1KB，1024 KB = 1 MB，1024 MB = 1GB，1024 GB = 1TB，1024TB = 1PB
*/
//原码和补码

/**
 * 原码
 * 负数怎么保存
 * 假如说用4个bit位保存数据，第一个位置保存正负
 * 这样保存的数据范围：
 * 最小：1111：-（2^2+2^1+2^0）==> -7
 *最大：0111：2^2+2^1+2^0 ==> 7
*/
/**
* 反码
 * 正数的反码是本身
 * 负数的反码：是在其原码的基础上，
 * 符号位不变 其余各个位取反
 * -1的原码是1001，除符号取反是1110
 * 1+(-1) = 0001+1110 = 1111 = -0
 * 1111除了符号不变变回原码：1000 ==> -0
 * 0不分正负所以c用补码
*/
/**
 * 补码
 * 正数的补码就是本身
 * 负数的补码：是在其原码的基础上，
 * 符号位不变 其余各个位取反，最后+1
 * 限定一个四比特位的数字
 * 0001+1111 = 1)0000=0000=0因为只有4bits,所以多出的1扔了，草
 *
*/
/**
 * 整数
* int - 占用 4 个字节，32个bit位，能够表示 -2,147,483,648 到 2,147,483,647 之间的数字，默认一般都是使用这种类型
* long - 占用 8 个字节，64个bit位。
* short - 占用2个字节，16个bit位。
*/
/**
* 浮点数 一部分bit保存整数，一部分保存小数，具体多少浮动
* float - 单精度浮点，占用4个字节，32个bit位。
*double - 双精度浮点，占用8个字节，64个bit位。
*/
/**
* 字符类型
 * char - 占用1个字节（-128~127），可以表示所有的ASCII码字符，每一个数字对应的是编码表中的一个字符
*/
