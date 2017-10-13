#include  <linux/linkage.h>
#include  <linux/export.h>
#include  <linux/time.h>
#include  <asm/uaccess.h>
#include  <linux/printk.h>
#include  <linux/slab.h>

asmlinkage int sys_my_xtime(struct timespec *current_time)
{
	struct timespec t = current_kernel_time();
	if(!access_ok(VERIFY_WRITE, current_time, sizeof(current_time)))
	{
		return -EFAULT;
	}
	copy_to_user(current_time, &t, sizeof(t));
	printk(KERN_INFO "current time: %ld", t.tv_sec);
	printk(KERN_INFO "current time: %ld", t.tv_nsec);

	return 0;
}
