#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

static char *mystr = "hello my world";
static int myfirst = 1;
static int myarr[3]={0,1,2};

static int __init helloworld(void)
{
    pr_info("hello my world\n");
    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("exit my world\n");
    return 0;
}
module_init(helloworld);
module_exit(hello_exit);
MODULE_AUTHOR("zhang peng");
MODULE_LICENSE("GPL");