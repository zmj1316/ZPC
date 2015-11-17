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
static const char *ng0 = "F:/Workspace/ASM/Hard/VGA/VGA.v";
static unsigned int ng1[] = {0U, 4294967295U};
static int ng2[] = {1, 0};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {0U, 0U};



static void Cont_31_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 6048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7456);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t2, 8);
    xsi_driver_vfirst_trans(t3, 0, 31);

LAB1:    return;
}

static void Always_70_1(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;

LAB0:    t1 = (t0 + 6296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 7360);
    *((int *)t2) = 1;
    t3 = (t0 + 6328);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(70, ng0);

LAB5:    xsi_set_current_line(71, ng0);
    t4 = (t0 + 4328);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t7, t6, 8);
    t8 = (t0 + 4808);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 12);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = (t0 + 4648);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 4328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 32, t4, 8, t5, 32);
    t6 = (t0 + 4328);
    xsi_vlogvar_assign_value(t6, t7, 0, 0, 8);
    goto LAB2;

}

static void Initial_77_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(77, ng0);

LAB2:    xsi_set_current_line(78, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 4168);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 4808);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 12);
    xsi_set_current_line(80, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 4968);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 12);
    xsi_set_current_line(81, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 5128);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(82, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 4328);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(83, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 4488);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(84, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 4648);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);

LAB1:    return;
}

static void Always_86_3(char *t0)
{
    char t6[8];
    char t7[8];
    char t14[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 6792U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 7376);
    *((int *)t2) = 1;
    t3 = (t0 + 6824);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(86, ng0);

LAB5:    xsi_set_current_line(87, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 4168);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(88, ng0);

LAB6:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2488U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 4);
    *((unsigned int *)t7) = t9;
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 4);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t12 & 31U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 31U);
    t5 = (t0 + 2648U);
    t15 = *((char **)t5);
    memset(t14, 0, 8);
    t5 = (t14 + 4);
    t16 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 4);
    *((unsigned int *)t14) = t18;
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 4);
    *((unsigned int *)t5) = t20;
    t21 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t21 & 31U);
    t22 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t22 & 31U);
    xsi_vlogtype_concat(t6, 12, 10, 2U, t14, 5, t7, 5);
    t23 = (t0 + 4968);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 12);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t17 = (t10 | t13);
    t18 = *((unsigned int *)t4);
    t19 = *((unsigned int *)t5);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB10;

LAB7:    if (t20 != 0)
        goto LAB9;

LAB8:    *((unsigned int *)t6) = 1;

LAB10:    t16 = (t6 + 4);
    t24 = *((unsigned int *)t16);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB11;

LAB12:
LAB13:    goto LAB2;

LAB9:    t15 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(91, ng0);

LAB14:    xsi_set_current_line(92, ng0);
    t23 = ((char*)((ng2)));
    t29 = (t0 + 4168);
    xsi_vlogvar_assign_value(t29, t23, 0, 0, 1);
    goto LAB13;

}

static void implSig1_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 7040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng5)));
    t3 = (t0 + 7520);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}


extern void work_m_00000000003075918577_3566486687_init()
{
	static char *pe[] = {(void *)Cont_31_0,(void *)Always_70_1,(void *)Initial_77_2,(void *)Always_86_3,(void *)implSig1_execute};
	xsi_register_didat("work_m_00000000003075918577_3566486687", "isim/t_PC_isim_beh.exe.sim/work/m_00000000003075918577_3566486687.didat");
	xsi_register_executes(pe);
}
