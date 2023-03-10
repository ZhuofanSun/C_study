#include <stdio.h>

/**
* 511 = int -> 00000000 00000000 00000001 11111111
* chr只能取最后8个bit位（最后一个字节）
 * 负数反码是除了符号位取反最后+1
 * 所以11111111-1 = 11111110
 * 取反10000001——>-1
* char -> 11111111 -> -1
*/

/**
不同的类型优先级不同（根据长度而定）
char和short类型在参与运算时一律转换为int再进行运算。
浮点类型默认按双精度进行计算，所以就算有float类型，也会转换为double类型参与计算。
当有一个更高优先级的类型和一个低优先级的类型同时参与运算时，统一转换为高优先级运算，
 比如int和long参与运算，那么int转换为long再算，所以结果也是long类型，int和double参与运算，那么先把int转换为double再算。

char \                                              float
      -> int -> unsigned int -> long -> double <-/
short/
 优先级右侧double最高
*/
//强制类型转换：
/**
* (强制类型转换类型) 变量、常量或表达式；
*/