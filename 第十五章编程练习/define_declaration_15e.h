#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#define BINSIZE 33
#define OFF 0
#define ON 1
#define LEFT 0
#define MIDDLE 1
#define RIGHT 2

/**/

#define ALIGNLEFT 0
#define ALIGNMIDDLE 0x8000
#define ALIGNRIGHT 0x10000

#define ID_MASK 0xFF
#define SIZE_MASK 0x7F00
#define ALIGN_MASK 0x18000
#define BOLD_MASK 0x20000
#define ITALIC_MASK 0x40000
#define UNDERLINE_MASK 0x80000


struct font {
	unsigned int id : 8;
	unsigned int size : 7;
	unsigned int : 1;
	unsigned int align : 2;
	unsigned int bold : 1;
	unsigned int italic : 1;
	unsigned int underline : 1;
	unsigned int : 3;
};

char * itobs(int n, char *ps);
char * s_gets(char *st, int n);

int bstoi(char *str);
void test_bintoi(void);

void test_bin_str(void);
void operate_binstr(char * st1, char *st2);
void show_bstr(const char * str);

int open_bits(int n);
void test_open_bits(void);

int find_bits(int n, int loc);
void test_find_bits(void);
int rotate_1(unsigned int x, int n);
void test_totate_1(void);

void show_choice(void);
char getchoice(void);
int getnum(char ch);
void align(struct font * st);
void show_info(struct font *st);
void font(void);

void show_choice7(void);
char getchoice7(void);
int getnum7(char ch);
void align7(unsigned int *st);
void show_info7(unsigned int st);
void font7(void);
