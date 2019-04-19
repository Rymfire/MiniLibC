/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** minilibc.so unit tests
*/

#include <criterion/criterion.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <dlfcn.h>

#define UNUSED(x)   (void)(x)

/*
to import from libasm.so
call strcmp wrt ..plt
*/

static void *handle;
const char *LIB_PATH = "../libasm.so";

Test(x86_64, strlen)
{
    char *str1 = "Epitech";
    char *str2 = "Epi\ntech";
    char *str3 = "Epi\0tech";
    char *str4 = "Epi\ttech";
    char *str5 = "\0";
    size_t (*my_strlen)(char *) = NULL;

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_strlen = dlsym(handle, "strlen");
    cr_assert_eq(strlen(str1), my_strlen(str1));
    cr_assert_eq(strlen(str2), my_strlen(str2));
    cr_assert_eq(strlen(str3), my_strlen(str3));
    cr_assert_eq(strlen(str4), my_strlen(str4));
    cr_assert_eq(strlen(str5), my_strlen(str5));
    dlclose(handle);
}

Test(x86_64, strchr)
{
    char *(*my_strchr)(const char *, int) = NULL;
    char *str1 = "BornToCode";
    char *str2 = "Born\nToCode";
    char *str3 = "Born\tToCode";
    char *str4 = "Born\0ToCode";
    char *str5 = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(my_strchr(str1, 'B'), strchr(str1, 'B'));
    cr_assert_neq(my_strchr(str1, 'B'), strchr(str1, 'T'));
    cr_assert_eq(my_strchr(str1, '\0'), strchr(str1, '\0'));
    cr_assert_eq(my_strchr(str2, '\n'), strchr(str2, '\n'));
    cr_assert_eq(my_strchr(str3, '\t'), strchr(str3, '\t'));
    cr_assert_eq(my_strchr(str4, '\0'), strchr(str4, '\0'));
    cr_assert_eq(my_strchr(str5, 'T'), strchr(str5, 'T'));
    cr_assert_eq(my_strchr(str5, 'T'), NULL);
    dlclose(handle);
}

Test(x86_64, memset)
{
    void *(*my_memset)(void *, int, size_t) = NULL;
    char str1[] = "Rymfire";
    char _str1[] = "Rymfire";
    char str2[] = "Rym\nfire";
    char _str2[] = "Rym\nfire";
    char str3[] = "Rym\0fire";
    char _str3[] = "Rym\0fire";
    char neq[] = "\n\0\n";
    char _neq[] = "\n\0\n";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_memset = dlsym(handle, "memset");
    cr_assert_str_neq(my_memset(neq, 'a', 1), memset(_neq, 'a', 3));
    cr_assert_str_eq(my_memset(str1, 'a', 3), memset(_str1, 'a', 3));
    cr_assert_str_eq(my_memset(str2, 'a', 4), memset(_str2, 'a', 4));
    cr_assert_str_eq(my_memset(str3, 'a', 4), memset(_str3, 'a', 4));
    dlclose(handle);
}

Test(x86_64, memcpy)
{
    void *(*my_memcpy)(void *, const void *, size_t) = NULL;
    char ex1[] = "Rymfire";
    char ex2[] = "Rym\nfire";
    char ex3[] = "Rym\0fire";
    char ex4[] = "";
    char fill[] = "________";
    char _fill[] = "________";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_memcpy = dlsym(handle, "memcpy");
    cr_assert_str_eq(my_memcpy(fill, ex1, 7), memcpy(_fill, ex1, 7));
    cr_assert_str_eq(my_memcpy(fill, ex2, 8), memcpy(_fill, ex2, 8));
    cr_assert_str_eq(my_memcpy(fill, ex3, 8), memcpy(_fill, ex3, 8));
    cr_assert_str_eq(my_memcpy(fill, ex4, 0), memcpy(_fill, ex4, 0));
    dlclose(handle);
}

Test(x86_64, strcmp)
{
    int(*my_strcmp)(const char *, const char *) = NULL;
    const char *str1 = "bbb";
    const char *str2 = "baa";
    const char *str3 = "c";
    const char *str4 = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_strcmp = dlsym(handle, "strcmp");
    cr_assert_eq(strcmp(str1, str1), my_strcmp(str1, str1));
    cr_assert_eq(strcmp(str1, str2), my_strcmp(str1, str2));
    cr_assert_eq(strcmp(str1, str3), my_strcmp(str1, str3));
    cr_assert_eq(strcmp(str2, str3), my_strcmp(str2, str3));
    cr_assert_eq(strcmp(str4, str4), my_strcmp(str4, str4));
    cr_assert_eq(strcmp(str1, str4), my_strcmp(str1, str4));
    cr_assert_neq(strcmp(str1, str2), my_strcmp(str1, str4));
    dlclose(handle);
}

Test(x86_64, memmove)
{
    void *(*my_memmove)(void *, const void *, size_t) = NULL;
    char ex1[] = "Rymfireee";
    char _ex1[] = "Rymfireee";
    char ex2[] = "Rym\nfireee";
    char ex3[] = "Rym\0fireee";
    char ex4[] = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_memmove = dlsym(handle, "memmove");
    cr_assert_str_eq(my_memmove(ex1, ex1 + 2, 7), memmove(_ex1, _ex1 + 2, 7));
    cr_assert_str_eq(my_memmove(ex1 + 2, ex1, 7), memmove(_ex1 + 2, _ex1, 7));
    cr_assert_str_neq(my_memmove(ex1 - 2, ex1, 7), memmove(_ex1 - 2, _ex1, 7));
    cr_assert_str_eq(my_memmove(ex2, ex2 + 2, 8), memmove(ex2, ex2 + 2, 8));
    cr_assert_str_eq(my_memmove(ex3, ex3 + 2, 8), memmove(ex3, ex3 + 2, 8));
    cr_assert_str_eq(my_memmove(ex4, ex4 + 2, 2), memmove(ex4, ex4 + 2, 2));
    dlclose(handle);
}

Test(x86_64, strncmp)
{
    int(*my_strncmp)(const char *, const char *, size_t) = NULL;
    const char *str1 = "bbb";
    const char *str2 = "baa";
    const char *str3 = "c";
    const char *str4 = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_strncmp = dlsym(handle, "strncmp");
    cr_assert_eq(strncmp(str1, str1, 3), my_strncmp(str1, str1, 3));
    cr_assert_eq(strncmp(str1, str2, 3), my_strncmp(str1, str2, 3));
    cr_assert_eq(strncmp(str1, str2, 1), my_strncmp(str1, str2, 1));
    cr_assert_eq(strncmp(str1, str3, 3), my_strncmp(str1, str3, 3));
    cr_assert_eq(strncmp(str1, str3, 1), my_strncmp(str1, str3, 1));
    cr_assert_eq(strncmp(str2, str3, 3), my_strncmp(str2, str3, 3));
    cr_assert_eq(strncmp(str2, str3, 1), my_strncmp(str2, str3, 1));
    cr_assert_eq(strncmp(str4, str4, 0), my_strncmp(str4, str4, 0));
    cr_assert_eq(strncmp(str1, str4, 1), my_strncmp(str1, str4, 1));
    dlclose(handle);
}

Test(x86_64, rindex)
{
    char *(*my_rindex)(const char *, int) = NULL;
    char *str = "ramremrym";
    char *_str = "ramremrym";
    char *tab = "ram\trem\trym";
    char *_tab = "ram\trem\trym";
    char *empty = "";
    char *_empty = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_rindex = dlsym(handle, "rindex");
    cr_assert_str_eq(my_rindex(str, 'r'), rindex(_str, 'r'));
    cr_assert_str_eq(my_rindex(str, '\0'), rindex(_str, '\0'));
    cr_assert_str_eq(my_rindex(tab, '\t'), rindex(_tab, '\t'));
    cr_assert_eq(my_rindex(empty, 'r'), rindex(_empty, 'r'));
    dlclose(handle);
}

Test(x86_64, strpbrk)
{
    char *(*my_strpbrk)(const char *, const char *) = NULL;
    char *str = "Rymfire";
    char *tab = "Rym\tfire";
    char *empty = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_strpbrk = dlsym(handle, "strpbrk");
    cr_assert_str_eq(my_strpbrk(str, "afi"), strpbrk(str, "afi"));
    cr_assert_eq(my_strpbrk(str, "azw"), strpbrk(str, "azw"));
    cr_assert_str_eq(my_strpbrk(tab, "a\t"), strpbrk(tab, "a\t"));
    cr_assert_eq(my_strpbrk(empty, "a\t"), strpbrk(empty, "a\t"));
    dlclose(handle);
}

Test(x86_64, strcspn)
{
    size_t (*my_strcspn)(const char *, const char *) = NULL;
    char *str = "Rymfire";
    char *tab = "Rym\tfire";
    char *empty = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_strcspn = dlsym(handle, "strcspn");
    printf("%li\n", my_strcspn(empty, "QwErTy"));
    printf("%li\n", strcspn(empty, "RfrQwErTye"));
    cr_assert_eq(my_strcspn(str, "Rfre"), strcspn(str, "Rfre"));
    cr_assert_eq(my_strcspn(tab, "R\t"), strcspn(tab, "R\t"));
    cr_assert_eq(my_strcspn(empty, "QwErTy"), strcspn(empty, "QwErTy"));
    dlclose(handle);
}

/*
Test(x86_64, strlwr)
{
    char *(*my_strlwr)(const char *) = NULL;
    char *str = "RyMfIrE";
    char *null = NULL;
    char *empty = "";

    if (handle == NULL) {
        handle = dlopen(LIB_PATH, RTLD_LAZY);
        if (handle == NULL) {
            cr_log_error("%s\n", dlerror());
            exit(84);
        }
    }
    my_strlwr = dlsym(handle, "strlwr");
    UNUSED(my_strlwr);
    cr_assert_str_eq(my_strlwr(str), "rymfire");
    UNUSED(str);
    UNUSED(null);
    UNUSED(empty);
    dlclose(handle);
}
*/
