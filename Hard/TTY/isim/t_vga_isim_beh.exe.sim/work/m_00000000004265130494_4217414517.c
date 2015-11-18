/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "F:/Workspace/ASM/Hard/TTY/VGA.v";
static unsigned int ng1[] = {2097151U, 0U};
static unsigned int ng2[] = {262143U, 0U};
static int ng3[] = {1, 0};



static void Always_174_0(char *t0)
{
    char t8[8];
    char t30[8];
    char t52[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 3008);
    *((int *)t2) = 1;
    t3 = (t0 + 2720);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(174, ng0);

LAB5:    xsi_set_current_line(175, ng0);
    t4 = (t0 + 1768);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB9;

LAB6:    if (t20 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB9:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB10;

LAB11:
LAB12:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t5 = (t8 + 4);
    t6 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 0);
    *((unsigned int *)t5) = t14;
    t15 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t15 & 262143U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 262143U);
    t7 = ((char*)((ng2)));
    memset(t30, 0, 8);
    t9 = (t8 + 4);
    t10 = (t7 + 4);
    t17 = *((unsigned int *)t8);
    t18 = *((unsigned int *)t7);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t9);
    t21 = *((unsigned int *)t10);
    t22 = (t20 ^ t21);
    t25 = (t19 | t22);
    t26 = *((unsigned int *)t9);
    t27 = *((unsigned int *)t10);
    t28 = (t26 | t27);
    t29 = (~(t28));
    t35 = (t25 & t29);
    if (t35 != 0)
        goto LAB22;

LAB19:    if (t28 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t30) = 1;

LAB22:    t24 = (t30 + 4);
    t36 = *((unsigned int *)t24);
    t37 = (~(t36));
    t38 = *((unsigned int *)t30);
    t39 = (t38 & t37);
    t43 = (t39 != 0);
    if (t43 > 0)
        goto LAB23;

LAB24:
LAB25:    xsi_set_current_line(177, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t4, 21, t5, 32);
    t6 = (t0 + 1768);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 21, 0LL);
    goto LAB2;

LAB8:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(175, ng0);
    t31 = (t0 + 1448);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    memset(t30, 0, 8);
    t34 = (t33 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (~(t35));
    t37 = *((unsigned int *)t33);
    t38 = (t37 & t36);
    t39 = (t38 & 1U);
    if (t39 != 0)
        goto LAB16;

LAB14:    if (*((unsigned int *)t34) == 0)
        goto LAB13;

LAB15:    t40 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t40) = 1;

LAB16:    t41 = (t30 + 4);
    t42 = (t33 + 4);
    t43 = *((unsigned int *)t33);
    t44 = (~(t43));
    *((unsigned int *)t30) = t44;
    *((unsigned int *)t41) = 0;
    if (*((unsigned int *)t42) != 0)
        goto LAB18;

LAB17:    t49 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t49 & 1U);
    t50 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t50 & 1U);
    t51 = (t0 + 1448);
    xsi_vlogvar_wait_assign_value(t51, t30, 0, 0, 1, 0LL);
    goto LAB12;

LAB13:    *((unsigned int *)t30) = 1;
    goto LAB16;

LAB18:    t45 = *((unsigned int *)t30);
    t46 = *((unsigned int *)t42);
    *((unsigned int *)t30) = (t45 | t46);
    t47 = *((unsigned int *)t41);
    t48 = *((unsigned int *)t42);
    *((unsigned int *)t41) = (t47 | t48);
    goto LAB17;

LAB21:    t23 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(176, ng0);
    t31 = (t0 + 1608);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    memset(t52, 0, 8);
    t34 = (t33 + 4);
    t44 = *((unsigned int *)t34);
    t45 = (~(t44));
    t46 = *((unsigned int *)t33);
    t47 = (t46 & t45);
    t48 = (t47 & 1U);
    if (t48 != 0)
        goto LAB29;

LAB27:    if (*((unsigned int *)t34) == 0)
        goto LAB26;

LAB28:    t40 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t40) = 1;

LAB29:    t41 = (t52 + 4);
    t42 = (t33 + 4);
    t49 = *((unsigned int *)t33);
    t50 = (~(t49));
    *((unsigned int *)t52) = t50;
    *((unsigned int *)t41) = 0;
    if (*((unsigned int *)t42) != 0)
        goto LAB31;

LAB30:    t57 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t57 & 1U);
    t58 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t58 & 1U);
    t51 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t51, t52, 0, 0, 1, 0LL);
    goto LAB25;

LAB26:    *((unsigned int *)t52) = 1;
    goto LAB29;

LAB31:    t53 = *((unsigned int *)t52);
    t54 = *((unsigned int *)t42);
    *((unsigned int *)t52) = (t53 | t54);
    t55 = *((unsigned int *)t41);
    t56 = *((unsigned int *)t42);
    *((unsigned int *)t41) = (t55 | t56);
    goto LAB30;

}


extern void work_m_00000000004265130494_4217414517_init()
{
	static char *pe[] = {(void *)Always_174_0};
	xsi_register_didat("work_m_00000000004265130494_4217414517", "isim/t_vga_isim_beh.exe.sim/work/m_00000000004265130494_4217414517.didat");
	xsi_register_executes(pe);
}
