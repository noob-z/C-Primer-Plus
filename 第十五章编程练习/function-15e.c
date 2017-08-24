#include "define_declaration_15e.h"

char * itobs(int n, char *ps)
{
	int i;
	static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (n & 01) + '0';
	ps[size] = '\0';

	return ps;
}

char * s_gets(char *st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void test_bintoi(void)
{
	char * pbin = "01001001";
	printf("result = %d\n",bstoi(pbin));
}

int bstoi(char *str)
{
	int sum = 0;
	
	while (*str != '\0')
		sum = sum * 2 + (*str++ - '0');

	return sum;
}

void test_bin_str(void)
{
	char str1[BINSIZE];
	char str2[BINSIZE];

	puts("Enter first binary number(empty line to quit):");
	while(s_gets(str1, BINSIZE) != NULL && str1[0] != '\0')
	{
		puts("Enter second binary number(empty line to quit):");
		while (s_gets(str2, BINSIZE) != NULL && str2[0] != '\0')
		{
			operate_binstr(str1, str2);
			break;
		}
		if (str2[0] = '\0')
			break;
		puts("Enter next first binary number(empty line to quit):");
	}
	puts("Bye!");

}

void show_bstr(const char * str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}

void operate_binstr(char * st1, char *st2)
{
	int bin1;
	int bin2;
//	int value;
	char temp1[BINSIZE];
	//char temp2[BINSIZE];

	bin1 = bstoi(st1);
	bin2 = bstoi(st2);

	printf("~%s = %s\n~%s = %s\n", st1 ,itobs(~bin1, temp1), st2, itobs(~bin2, temp1));
	printf(" %s & %s = %s\n",st1,st2, itobs((bin1 & bin2) ,temp1));
	printf(" %s | %s = %s\n",st1,st2, itobs((bin1 | bin2), temp1));
	printf(" %s ^ %s = %s\n",st1,st2,itobs((bin1 ^ bin2),temp1));
}

void test_open_bits(void)
{
	int num = 15;

	printf("Open bits = %d",open_bits(num));
}

int open_bits(int n)
{
	int i;
	int sum = 0;
	for (i = 0; i < CHAR_BIT * sizeof(int); i++, n >>= 1)
		if ((n & 01))
			sum += 1;

	return sum;
}

void test_find_bits(void)
{
	printf("bit is %d\n", find_bits(16, 5));
}

int find_bits(int n, int loc)
{
	if (01 & (n >> loc - 1))
		return 1;
	else
		return 0;
}

void test_totate_1(void)
{
	char bin_str[BINSIZE];
	int num = 127;
	itobs(num, bin_str);
	show_bstr(bin_str);
	putchar('\n');
	itobs(rotate_1(num, 26), bin_str);
	show_bstr(bin_str);
}

int rotate_1(unsigned int x, int n)
{
	static int size = CHAR_BIT * sizeof(int);
	int mask;
	mask = x >> size - n;
	return (x <<= n) | mask;
}

/*------------------6--------------------*/

void font(void)
{
	int ch;
	struct font word = { 1, 12, LEFT, OFF, OFF,OFF };

	show_info(&word);
	show_choice();
	while ((ch = getchoice()) != 'q')
	{
		switch (ch)
		{
		case 'f':
			puts("Enter font id(0-255):");
			word.id = getnum(ch);
			break;
		case 's':
			puts("Enter font size(0-127):");
			word.size = getnum(ch);
			break;
		case 'a':
			puts("Select alignment:");
			align(&word);
			break;
		case 'b':
			word.bold ^= 01;
			break;
		case 'i':
			word.italic ^= 01;
			break;
		case 'u':
			word.underline ^= 01;
			break;
		}
		show_info(&word);
		show_choice();
	}
	puts("Bye!");

}

void show_choice(void)
{
	puts("f) change font    s) change size    a)change alignment");
	puts("b) toggle bold    i) toggle italic  u)toggle underline");
	puts("q) quit");
}

char getchoice(void)
{
	char ch;
	char chioce[] = "fsabiuq";
	char * find;
	
	while (ch = getch())
	{
		find = strchr(chioce, ch);
		if (find)
			return ch;
		else
		{
			puts("Enter a valid choice in follow menu");
			continue;
		}
	}
}

int getnum(char ch)
{
	int val;
	while (scanf("%d", &val) == 1)
	{
		getchar();
		if (ch == 'f')
		{
			if (val < 0 || val > 255)
			{
				printf("Enter font id(0 - 255):");
				continue;
			}
			else
				return val;
		}
		else
		{
			if (val < 0 || val > 127)
			{
				printf("Enter font id(0 - 127):");
				continue;
			}
			else
				return val;
		}
	}

}

void align(struct font *st)
{
	char ch;
	char * find;
	char choice[] = "lcrq";
	puts("l)left   c)center   r)right");
	while ((ch = getch()) != 'q')
	{
		find = strchr(choice, ch);
		if (find)
		{
			switch (ch)
			{
			case 'l':
				st->align= LEFT;
				break;
			case 'c':
				st->align = MIDDLE;
				break;
			case 'r':
				st->align = RIGHT;
				break;
			}
		}
		else
		{
			puts("Select alignment int choice menu:");
			continue;
		}
		break;
	}
}

void show_info(struct font *st)
{
	putchar('\n');
	printf("ID SIZE ALIGNMENT     B   I   U\n");
	printf("%2d%4d",st->id,st->size);//% 5s % 2s % 2s
	switch (st->align)
	{
	case LEFT:
		printf("%7s","left");
		break;
	case MIDDLE:
		printf("%7s", "center");
		break;
	case RIGHT:
		printf("%7s", "right");
		break;
	default:
		printf("Unkonw");
	}
	printf("%10s", st->bold == ON ? "on" : "off");
	printf("%4s", st->italic == ON ? "on" : "off");
	printf("%4s", st->underline == ON ? "on" : "off");
	putchar('\n');
}


