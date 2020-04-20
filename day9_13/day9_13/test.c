#include <stdio.h>
#include <limits.h>
/*给定一个 32 位有符号整数，将整数中的数字进行反转。
示例 1:
输入: 123
输出: 321
 示例 2:
输入: -123
输出: -321
示例 3:
输入: 120
输出: 21
注意:
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。
根据这个假设，如果反转后的整数溢出，则返回 0。
*/

int reverse(int x) 
{
	int temp = 0;
	while (x != 0)
	{
		//正数是否越界
		if (temp > 0 && ((temp == INT_MAX / 10 && x % 10 > INT_MAX % 10) || temp > INT_MAX / 10))
			return 0;

		//负数是否越界
		if (temp < 0 && ((temp == INT_MIN / 10 && x % 10 < (unsigned)INT_MIN % 10) || temp < INT_MIN / 10))
			return 0;
		temp = temp * 10 + x % 10;
		x /= 10;
	}
	//while (abs(x) > 0)
	//{
	//	temp = reverse_x;

	//	/**判断是否越界**/

	//	//正数是否越界
	//	if (temp > 0 && ((temp == INT_MAX / 10 && x % 10 > INT_MAX % 10) || temp > INT_MAX / 10))
	//		return 0;

	//	//负数是否越界
	//	if (temp < 0 && ((temp == INT_MIN / 10 && x % 10 < (unsigned)INT_MIN % 10) || temp < INT_MIN / 10))
	//		return 0;

	//	reverse_x = reverse_x * 10 + x % 10;
	//	x = x / 10;
	//}
	//return reverse_x;

	return temp;
}

int main()
{
	//printf("%d ",pow(2,31));//  0
	//printf("%d ", -pow(2, 31)+1);//  0

	printf("%d \n",reverse(1234));
	return 0;
}