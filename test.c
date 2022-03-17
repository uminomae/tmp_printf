#include "ft_printf.h"

// int main()
// {
//     char *s = "abcde";
//     char c ='!';
//     // int d = INT_MIN;
//     int d = 12345;
//     int i = INT_MAX;
//     // unsigned int u = UINT_MAX;
//     unsigned int u = 12345;

//     // printf("\x1b[38;5;198m""\n--- %s ---\n", __func__);

//     // ft_printf("---case of temp---\n");
    
//     ft_printf("%12.10d\n",d);
//        printf("%12.10d\n",d);
//     ft_printf("%x\n", 160);
//        printf("%x\n", 160);
// }

int main()
{
    char *s = "abcde";
    char c ='!';
    // int d = INT_MIN;
    int d = -12345;
    // int i = INT_MAX;
    int i = 12345;
    // unsigned int u = UINT_MAX;
    unsigned int u = 12345;
    int ret_st;
    int ret_ft;

    // printf("\x1b[38;5;198m""\n--- %s ---\n", __func__);

    // ft_printf("---case of temp---\n");
    // char *s2 = strdup("Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.");
    // ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
    //    printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
    // printf("%ld", LONG_MIN);

    // int ld = (int)LONG_MIN;
	// ft_printf("|%zu|longmin|%.11d|", malloc_size(ld), ld);
    //    printf("|%.11d|", ld);

    // ft_printf("---mandatry---\n");
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%%|", __LINE__));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%%|", __LINE__));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%5c|", __LINE__,  c));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%5c|", __LINE__,  c));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%s|", __LINE__,  s));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%s|", __LINE__,  s));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%d|", __LINE__,  d));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%d|", __LINE__,  d));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%i|", __LINE__,  INT_MAX));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%i|", __LINE__,  INT_MAX));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%u|", __LINE__,  u));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%u|", __LINE__,  u));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%p|", __LINE__,  s));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%p|", __LINE__,  s));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%x|", __LINE__,  u));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%x|", __LINE__,  u));
    // printf("(ret)|%d|\n",ft_printf("(line)%d|\tft(fmt)|%X|", __LINE__,  u));
    // printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%X|", __LINE__,  u));

    ft_printf("---bonus---\n");
    // ft_printf("(line)|%d|\t(ft)x:%#015x\n", __LINE__,  u);
    //    printf("(line)|%d|\t(st)x:%#015x\n", __LINE__,  u);
    // ft_printf("(line)|%d|\t(ft)x:%#010x\n", __LINE__,  u);
    //    printf("(line)|%d|\t(st)x:%#010x\n", __LINE__,  u);   
    // ft_printf("(line)|%d|\t(ft)X:%#016.12X\n", __LINE__,  u);
    //    printf("(line)|%d|\t(st)X:%#016.12X\n", __LINE__,  u);
    // ft_printf("(line)|%d|\t(ft)u:%015u\n",  __LINE__, u);
    //    printf("(line)|%d|\t(st)u:%015u\n",  __LINE__, u);
    // ft_printf("(line)|%d|\t(ft)u:%-15u\n",  __LINE__, u);
    //    printf("(line)|%d|\t(st)u:%-15u\n",  __LINE__, u);
    // ft_printf("(line)|%d|\t(ft)d:%015d\n",  __LINE__, d);
    //    printf("(line)|%d|\t(st)d:%015d\n",  __LINE__, d);
    // ft_printf("(line)|%d|\t(ft)d:%-15d\n",  __LINE__, d);
    //    printf("(line)|%d|\t(st)d:%-15d\n",  __LINE__, d);
    // ft_printf("(line)|%d|\t(ft)d:% 15d\n",  __LINE__, i);
    //    printf("(line)|%d|\t(st)d:% 15d\n",  __LINE__, i);
    // ft_printf("(line)|%d|\t(ft)d:%+15d\n",  __LINE__, i);
    //    printf("(line)|%d|\t(st)d:%+15d\n",  __LINE__, i);
    ft_printf("(line)|%d|\t(ft)d:% 012.13d\n",  __LINE__, i);
    //    printf("(line)|%d|\t(st)d:% 012.13d\n",  __LINE__, i);
    // ft_printf("(line)|%d|\tft(fmt)%-12.10s\n", __LINE__,  s);
    //    printf("(line)|%d|\tst(fmt)%-12.10s\n", __LINE__,  s);
    // ft_printf("(line)|%d|\t(ft)s:%10.8s\n", __LINE__,  s);
    //    printf("(line)|%d|\t(st)s:%10.8s\n", __LINE__,  s);
    // ft_printf("(line)|%d|\t(ft)s:%.8s\n", __LINE__,  s);
    //    printf("(line)|%d|\t(st)s:%.8s\n", __LINE__,  s);
    // ft_printf("(line)|%d|\tft(fmt)%-10p\n", __LINE__,  s);
    //    printf("(line)|%d|\tst(fmt)%-10p\n", __LINE__,  s);
    // ft_printf("(line)|%d|\tft(fmt)%.s\n", __LINE__,  "");
    //    printf("(line)|%d|\tst(fmt)%.s\n", __LINE__,  "");
    // printf( "%d\n",ft_printf("(line)|%d|\tft(fmt)%b\n", __LINE__,  "a"));
    // // printf( "%d\n",   printf("(line)|%d|\tft(fmt)%b\n", __LINE__,  "a"));
    // ft_printf("(line)|%d|\t(ft)s:%10p\n", __LINE__,  s);
    //    printf("(line)|%d|\t(st)s:%10p\n", __LINE__,  s);
    // ft_printf("(line)|%d|\t(st)d:%.8d\n", __LINE__,  d);
    //    printf("(line)|%d|\t(st)d:%.8d\n", __LINE__,  d);
    // ft_printf("(line)|%d|\t(st)d:% 7.8d\n", __LINE__,  d);
    //    printf("(line)|%d|\t(st)d:% 7.8d\n", __LINE__,  d);
    // ft_printf("(line)|%d|\t(st)d:% .8d\n", __LINE__,  d);
    //    printf("(line)|%d|\t(st)d:% .8d\n", __LINE__,  d);
    // ft_printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|% 010d|\n", __LINE__,  d));
    //    printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|% 010d|\n", __LINE__,  d));
    // ft_printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%-.10d|\n", __LINE__,  d));
    //    printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%-.10d|\n", __LINE__,  d));
    // ft_printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%0+10d|\n", __LINE__,  d));
    //    printf("(ret)|%d|\n",   printf("(line)%d|\tst(fmt)|%0+10d|\n", __LINE__,  d));
    
    // ret_ft = ft_printf(" %-5c %-2c %-3c \n", '0', 0, '1');
    // ret_st =    printf(" %-5c %-2c %-3c \n", '0', 0, '1');
    // printf("%d,%d\n", ret_st, ret_ft);
   	// ret_ft = ft_printf(" %c %-2c %-3c \n", 0, '1', '2');
   	// ret_st =    printf(" %c %-2c %-3c \n", 0, '1', '2');
    // printf("ret %d,%d\n", ret_st, ret_ft);

   	// ret_ft = ft_printf(" %-5c %-2c %-3c \n", 0, '1', '2');
   	// ret_st =    printf(" %-5c %-2c %-3c \n", 0, '1', '2');
    // printf("ret %d,%d\n", ret_st, ret_ft);
    // puts("---");
   	// ret_ft = ft_printf(" %5c %-2c %-3c \n", 0, '1', '2');
   	// ret_st =    printf(" %5c %-2c %-3c \n", 0, '1', '2');
    // printf("ret %d,%d\n", ret_st, ret_ft);

    ft_printf("---case corner---\n");
    size_t n = INT_MAX;
    n += 10;
    char *str = malloc(sizeof(char) * (n + 1));
    memset(str, 'a', n);
    str[n] = '\0';
    printf("(ret)|%d|\n",ft_printf("ft(fmt)|%s|", str));
    printf("(ret)|%d|\n",   printf("st(fmt)|%s|", str));

    // system("leaks -q a.out");
    // printf("\x1b[39;5;198m""\n--- end of %s ---\n", __func__);
}
