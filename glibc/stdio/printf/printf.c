#include <stdio.h>

int main()
{
	/* Controlling integer width with printf */
	printf("%3d\n", 0);
	printf("%3d\n", 123456789);
	printf("%3d\n", -10);
	printf("%3d\n", -123456789);

	/* Left-justifying printf integer output */
	printf("%-3d\n", 0);
	printf("%-3d\n", 123456789);
	printf("%-3d\n", -10);
	printf("%-3d\n", -123456789);

	printf("%03d\n", 0);
	printf("%03d\n", 1);
	printf("%03d\n", 123456789);
	printf("%03d\n", -10);
	printf("%03d\n", -123456789);

	/* printf integer formatting */
	printf("'%5d'\n", 10);
	printf("'%-5d'\n", 10);
	printf("'%05d'\n", 10);
	printf("'%+5d'\n", 10);
	printf("'%-+5d'\n", 10);

	/* printf - formatting floating point numbers */
	printf("'%.1f'\n", 10.3456);
	printf("'%.2f'\n", 10.3456);
	printf("'%8.2f'\n", 10.3456);
	printf("'%8.4f'\n", 10.3456);
	printf("'%08.2f'\n", 10.3456);
	printf("'%-8.2f'\n", 10.3456);
	printf("'%-8.2f'\n", 101234567.3456);

	/* Summary of special printf characters */
	printf("Hello\tworld\n");
	printf("Hello\nworld\n");
	printf("Hello world\n");
	printf("C:\\Windows\\System32\\\n");

	/* 1.int type */
	int intValue = 2;
	printf("1.output integer normally : %i\n",intValue);// output 2
	printf("2.positive, two bit reserved, (before number)other bits blank with white space : #%2i#\n", intValue);// output # 2#
	printf("3.negative，two bit reserved, (after number)other bits blank with white space : #%-2i#\n", intValue);// output #2 #
	printf("4.two bit reserved, other bits blank with zero : #%02i#\n", intValue);// output #02#

	int intValue2 = 23;
	printf("5.本身两位数，格式化并无变化:#%02i#\n",intValue2);//输出#23#
	printf("6.动态保留位宽,其他位以0填充:#%0*i#\n",4,intValue2);//输出#0023#

	//2.float类型(保留有效位数为7位)
	float floatValue = 6.9f;
	printf("7.正常输出浮点型：%f\n",floatValue);//输出6.900000
	printf("8.格式化小数点保留两位，其他位以0填充:#%.2f#\n",floatValue);// 输出#6.90#


	float pi = 3.141592653f;
	printf("9.正常输出浮点型，有效保留7位：%f\n",pi);//输出3.141593
	printf("10.格式化保留10位，并不会有影响，最大有效位为7位：%.10f\n",pi);//输出3.1415927410


	//3.double类型（保留有效位为15位）
	double  doubleValue = 3.1415926531;
	printf("11.正常输出double类型：%lf\n",doubleValue);//输出3.141593
	printf("12.格式化保留10位，有效保留15位,会以15位为位宽：%.10lf\n",doubleValue);//输出3.1415926531

	//4.char
	char charValue = 'a';
	printf("13.字符输出:%c\n",charValue);//输出a

	printf("%*sdd\n", 4, " ");
	printf("%.*sdd", 6, " ");
	printf("a\n");
}
