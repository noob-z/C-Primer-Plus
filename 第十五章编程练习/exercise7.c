#include "define_declaration_15e.h"

void font7(void)
{
	int ch;
	unsigned int word = 0xC01;

	show_info7(word);
	show_choice7();
	while ((ch = getchoice7()) != 'q')
	{
		switch (ch)
		{
		case 'f':
			puts("Enter font id(0-255):");
			word &= ~ID_MASK;
			word |= getnum7(ch);
			break;
		case 's':
			puts("Enter font size(0-127):");
			word &= ~SIZE_MASK;
			word |= getnum7(ch);
			break;
		case 'a':
			puts("Select alignment:");
			align7(&word);
			break;
		case 'b':
			word ^= BOLD_MASK;
			break;
		case 'i':
			word ^= ITALIC_MASK;
			break;
		case 'u':
			word ^= UNDERLINE_MASK;
			break;
		}
		show_info7(word);
		show_choice7();
	}
	puts("Bye!");

}

void show_choice7(void)
{
	puts("f) change font    s) change size    a)change alignment");
	puts("b) toggle bold    i) toggle italic  u)toggle underline");
	puts("q) quit");
}

char getchoice7(void)
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

int getnum7(char ch)
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
				return (val <<= 8);
		}
	}

}

void align7(unsigned int * st)
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
				*st &= ~ALIGN_MASK;
				*st |= ALIGNLEFT;
				break;
			case 'c':
				*st &= ~ALIGN_MASK;
				*st |= ALIGNMIDDLE;
				break;
			case 'r':
				*st &= ~ALIGN_MASK;
				*st |= ALIGNRIGHT;
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

void show_info7(const unsigned int st)
{
	putchar('\n');
	printf("ID SIZE ALIGNMENT     B   I   U\n");
	printf("%2d%4d", st & ID_MASK, (st & SIZE_MASK) >> 8);//% 5s % 2s % 2s
	switch (st & ALIGN_MASK)
	{
	case ALIGNLEFT:
		printf("%7s", "left");
		break;
	case ALIGNMIDDLE:
		printf("%7s", "center");
		break;
	case ALIGNRIGHT:
		printf("%7s", "right");
		break;
	default:
		printf("Unkonw");
	}
	printf("%10s", (st & BOLD_MASK) == BOLD_MASK ? "on" : "off");
	printf("%4s", (st & ITALIC_MASK) == ITALIC_MASK ? "on" : "off");
	printf("%4s", (st & UNDERLINE_MASK) == UNDERLINE_MASK ? "on" : "off");
	putchar('\n');
}