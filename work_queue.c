#include<linux/module.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/time.h>
#include<linux/delay.h>
#include<linux/workqueue.h>

static DECLARE_WAIT_QUEUE_HEAD(my_wq);
static int my_condition = 0;

static struct work_struct wrk;

static void work_handler(struct work_struct *work)
{
    printk("this module handler %s\n",__FUNCTION__);
    msleep(5000);
    printk("wake up the sleeping \n");
    my_condition = 1;
    wake_up_interruptible(&my_wq);
}
static int __init work_init(void)
{
    printk("wait queue example\n");
    INIT_WORK(&wrk,work_handler);
    schedule_work(&wrk);
    printk("going to sleep %s\n",__FUNCTION__);
    wait_event_interruptible(my_wq, my_condition!=0);
    pr_info("woken up by the work job \n");
    return 0;
}

static void __exit work_exit(void)
{
    printk("waitqueeue exit\n");
}
module_init(work_init);
module_exit(work_exit);
MODULE_AUTHOR("zhang peng");
MODULE_LICENSE("GPL");