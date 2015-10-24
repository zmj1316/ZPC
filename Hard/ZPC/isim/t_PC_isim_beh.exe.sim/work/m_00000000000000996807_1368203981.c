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
static const char *ng0 = "F:/Workspace/ASM/Hard/Mem/Mem.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 4294967295U};
static int ng3[] = {31, 0};
static int ng4[] = {1, 0};
static int ng5[] = {63, 0};
static int ng6[] = {32, 0};
static int ng7[] = {2, 0};
static int ng8[] = {3, 0};



static void Initial_31_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(31, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2408);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_32_1(char *t0)
{
    char t13[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;

LAB0:    t1 = (t0 + 4376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 5440);
    *((int *)t2) = 1;
    t3 = (t0 + 4408);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(32, ng0);

LAB5:    xsi_set_current_line(33, ng0);
    t4 = (t0 + 1848U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(37, ng0);

LAB10:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t13, 0, 8);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t5) == 0)
        goto LAB11;

LAB13:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;

LAB14:    t12 = (t13 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t13) = t16;
    *((unsigned int *)t12) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB16;

LAB15:    t21 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t21 & 1U);
    t22 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t22 & 1U);
    t23 = (t0 + 2408);
    xsi_vlogvar_assign_value(t23, t13, 0, 0, 1);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(33, ng0);

LAB9:    xsi_set_current_line(35, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2408);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    goto LAB8;

LAB11:    *((unsigned int *)t13) = 1;
    goto LAB14;

LAB16:    t17 = *((unsigned int *)t13);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t17 | t18);
    t19 = *((unsigned int *)t12);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t12) = (t19 | t20);
    goto LAB15;

}

static void Cont_49_2(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    t1 = (t0 + 4624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1368U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t19 = *((unsigned int *)t4);
    t20 = (~(t19));
    t21 = *((unsigned int *)t12);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t23, 8);

LAB16:    t24 = (t0 + 5568);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t3, 8);
    xsi_driver_vfirst_trans(t24, 0, 31);
    t29 = (t0 + 5456);
    *((int *)t29) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 3048);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    goto LAB9;

LAB10:    t23 = ((char*)((ng2)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t18, 32, t23, 32);
    goto LAB16;

LAB14:    memcpy(t3, t18, 8);
    goto LAB16;

}

static void Always_58_3(char *t0)
{
    char t14[8];
    char t18[8];
    char t19[8];
    char t40[8];
    char t59[8];
    char t60[8];
    char t61[8];
    char t62[8];
    char t71[8];
    char t84[16];
    char t85[16];
    char t86[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    char *t15;
    unsigned int t16;
    char *t17;
    char *t20;
    char *t21;
    int t22;
    int t23;
    char *t24;
    int t25;
    int t26;
    int t27;
    int t28;
    int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    char *t83;

LAB0:    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 5472);
    *((int *)t2) = 1;
    t3 = (t0 + 4904);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(58, ng0);

LAB5:    xsi_set_current_line(59, ng0);
    t4 = (t0 + 1848U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(63, ng0);

LAB10:    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB11:    t5 = ((char*)((ng1)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 1, t5, 32);
    if (t13 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 1, t2, 32);
    if (t13 == 1)
        goto LAB14;

LAB15:
LAB16:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);

LAB23:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 32);
    if (t13 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 32);
    if (t13 == 1)
        goto LAB26;

LAB27:
LAB28:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(59, ng0);

LAB9:    xsi_set_current_line(61, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3208);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    goto LAB8;

LAB12:    xsi_set_current_line(66, ng0);

LAB17:    xsi_set_current_line(67, ng0);
    t11 = (t0 + 1688U);
    t12 = *((char **)t11);
    memset(t14, 0, 8);
    t11 = (t14 + 4);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t12);
    t7 = (t6 >> 2);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t15);
    t9 = (t8 >> 2);
    *((unsigned int *)t11) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 1023U);
    t16 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t16 & 1023U);
    t17 = (t0 + 2728);
    xsi_vlogvar_assign_value(t17, t14, 0, 0, 12);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = (t0 + 2888);
    t5 = (t0 + 2888);
    t11 = (t5 + 72U);
    t12 = *((char **)t11);
    t15 = ((char*)((ng3)));
    t17 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t14, t18, t19, ((int*)(t12)), 2, t15, 32, 1, t17, 32, 1);
    t20 = (t14 + 4);
    t6 = *((unsigned int *)t20);
    t13 = (!(t6));
    t21 = (t18 + 4);
    t7 = *((unsigned int *)t21);
    t22 = (!(t7));
    t23 = (t13 && t22);
    t24 = (t19 + 4);
    t8 = *((unsigned int *)t24);
    t25 = (!(t8));
    t26 = (t23 && t25);
    if (t26 == 1)
        goto LAB18;

LAB19:    goto LAB16;

LAB14:    xsi_set_current_line(70, ng0);

LAB20:    xsi_set_current_line(71, ng0);
    t3 = (t0 + 1688U);
    t5 = *((char **)t3);
    memset(t14, 0, 8);
    t3 = (t14 + 4);
    t11 = (t5 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (t6 >> 2);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t11);
    t9 = (t8 >> 2);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 1023U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 1023U);
    t12 = ((char*)((ng4)));
    memset(t18, 0, 8);
    xsi_vlog_unsigned_add(t18, 32, t14, 32, t12, 32);
    t15 = (t0 + 2728);
    xsi_vlogvar_assign_value(t15, t18, 0, 0, 12);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = (t0 + 2888);
    t5 = (t0 + 2888);
    t11 = (t5 + 72U);
    t12 = *((char **)t11);
    t15 = ((char*)((ng5)));
    t17 = ((char*)((ng6)));
    xsi_vlog_convert_partindices(t14, t18, t19, ((int*)(t12)), 2, t15, 32, 1, t17, 32, 1);
    t20 = (t14 + 4);
    t6 = *((unsigned int *)t20);
    t13 = (!(t6));
    t21 = (t18 + 4);
    t7 = *((unsigned int *)t21);
    t22 = (!(t7));
    t23 = (t13 && t22);
    t24 = (t19 + 4);
    t8 = *((unsigned int *)t24);
    t25 = (!(t8));
    t26 = (t23 && t25);
    if (t26 == 1)
        goto LAB21;

LAB22:    goto LAB16;

LAB18:    t9 = *((unsigned int *)t19);
    t27 = (t9 + 0);
    t10 = *((unsigned int *)t14);
    t16 = *((unsigned int *)t18);
    t28 = (t10 - t16);
    t29 = (t28 + 1);
    xsi_vlogvar_assign_value(t2, t3, t27, *((unsigned int *)t18), t29);
    goto LAB19;

LAB21:    t9 = *((unsigned int *)t19);
    t27 = (t9 + 0);
    t10 = *((unsigned int *)t14);
    t16 = *((unsigned int *)t18);
    t28 = (t10 - t16);
    t29 = (t28 + 1);
    xsi_vlogvar_assign_value(t2, t3, t27, *((unsigned int *)t18), t29);
    goto LAB22;

LAB24:    xsi_set_current_line(76, ng0);

LAB29:    xsi_set_current_line(77, ng0);
    t5 = (t0 + 1688U);
    t11 = *((char **)t5);
    memset(t14, 0, 8);
    t5 = (t14 + 4);
    t12 = (t11 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (t6 >> 0);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t12);
    t9 = (t8 >> 0);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 3U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 3U);

LAB30:    t15 = ((char*)((ng1)));
    t22 = xsi_vlog_unsigned_case_compare(t14, 32, t15, 32);
    if (t22 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t14, 32, t2, 32);
    if (t13 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t14, 32, t2, 32);
    if (t13 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t14, 32, t2, 32);
    if (t13 == 1)
        goto LAB37;

LAB38:
LAB39:    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng4)));
    t5 = (t0 + 3208);
    xsi_vlogvar_assign_value(t5, t2, 0, 0, 1);
    goto LAB28;

LAB26:    xsi_set_current_line(85, ng0);

LAB92:    xsi_set_current_line(86, ng0);
    t5 = (t0 + 1688U);
    t11 = *((char **)t5);
    memset(t18, 0, 8);
    t5 = (t18 + 4);
    t12 = (t11 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (t6 >> 0);
    *((unsigned int *)t18) = t7;
    t8 = *((unsigned int *)t12);
    t9 = (t8 >> 0);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t10 & 3U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 3U);

LAB93:    t15 = ((char*)((ng1)));
    t22 = xsi_vlog_unsigned_case_compare(t18, 32, t15, 32);
    if (t22 == 1)
        goto LAB94;

LAB95:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 32, t2, 32);
    if (t13 == 1)
        goto LAB96;

LAB97:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 32, t2, 32);
    if (t13 == 1)
        goto LAB98;

LAB99:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 32, t2, 32);
    if (t13 == 1)
        goto LAB100;

LAB101:
LAB102:    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng4)));
    t5 = (t0 + 3208);
    xsi_vlogvar_assign_value(t5, t2, 0, 0, 1);
    goto LAB28;

LAB31:    xsi_set_current_line(78, ng0);
    t17 = (t0 + 2408);
    t20 = (t17 + 56U);
    t21 = *((char **)t20);
    memset(t19, 0, 8);
    t24 = (t21 + 4);
    t30 = *((unsigned int *)t24);
    t31 = (~(t30));
    t32 = *((unsigned int *)t21);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t24) != 0)
        goto LAB42;

LAB43:    t36 = (t19 + 4);
    t37 = *((unsigned int *)t19);
    t38 = *((unsigned int *)t36);
    t39 = (t37 || t38);
    if (t39 > 0)
        goto LAB44;

LAB45:    t53 = *((unsigned int *)t19);
    t54 = (~(t53));
    t55 = *((unsigned int *)t36);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t36) > 0)
        goto LAB48;

LAB49:    if (*((unsigned int *)t19) > 0)
        goto LAB50;

LAB51:    memcpy(t18, t58, 8);

LAB52:    t57 = (t0 + 2568);
    xsi_vlogvar_assign_value(t57, t18, 0, 0, 32);
    goto LAB39;

LAB33:    xsi_set_current_line(79, ng0);
    t5 = (t0 + 2408);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t19, 0, 8);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t12);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t15) != 0)
        goto LAB55;

LAB56:    t20 = (t19 + 4);
    t16 = *((unsigned int *)t19);
    t30 = *((unsigned int *)t20);
    t31 = (t16 || t30);
    if (t31 > 0)
        goto LAB57;

LAB58:    t53 = *((unsigned int *)t19);
    t54 = (~(t53));
    t55 = *((unsigned int *)t20);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB59;

LAB60:    if (*((unsigned int *)t20) > 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t19) > 0)
        goto LAB63;

LAB64:    memcpy(t18, t61, 8);

LAB65:    t81 = (t0 + 2568);
    xsi_vlogvar_assign_value(t81, t18, 0, 0, 32);
    goto LAB39;

LAB35:    xsi_set_current_line(80, ng0);
    t5 = (t0 + 2408);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t19, 0, 8);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t12);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t15) != 0)
        goto LAB68;

LAB69:    t20 = (t19 + 4);
    t16 = *((unsigned int *)t19);
    t30 = *((unsigned int *)t20);
    t31 = (t16 || t30);
    if (t31 > 0)
        goto LAB70;

LAB71:    t53 = *((unsigned int *)t19);
    t54 = (~(t53));
    t55 = *((unsigned int *)t20);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t20) > 0)
        goto LAB74;

LAB75:    if (*((unsigned int *)t19) > 0)
        goto LAB76;

LAB77:    memcpy(t18, t61, 8);

LAB78:    t81 = (t0 + 2568);
    xsi_vlogvar_assign_value(t81, t18, 0, 0, 32);
    goto LAB39;

LAB37:    xsi_set_current_line(81, ng0);
    t5 = (t0 + 2408);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t19, 0, 8);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t12);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB79;

LAB80:    if (*((unsigned int *)t15) != 0)
        goto LAB81;

LAB82:    t20 = (t19 + 4);
    t16 = *((unsigned int *)t19);
    t30 = *((unsigned int *)t20);
    t31 = (t16 || t30);
    if (t31 > 0)
        goto LAB83;

LAB84:    t53 = *((unsigned int *)t19);
    t54 = (~(t53));
    t55 = *((unsigned int *)t20);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB85;

LAB86:    if (*((unsigned int *)t20) > 0)
        goto LAB87;

LAB88:    if (*((unsigned int *)t19) > 0)
        goto LAB89;

LAB90:    memcpy(t18, t61, 8);

LAB91:    t81 = (t0 + 2568);
    xsi_vlogvar_assign_value(t81, t18, 0, 0, 32);
    goto LAB39;

LAB40:    *((unsigned int *)t19) = 1;
    goto LAB43;

LAB42:    t35 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB43;

LAB44:    t41 = (t0 + 2888);
    t42 = (t41 + 56U);
    t43 = *((char **)t42);
    memset(t40, 0, 8);
    t44 = (t40 + 4);
    t45 = (t43 + 8);
    t46 = (t43 + 12);
    t47 = *((unsigned int *)t45);
    t48 = (t47 >> 0);
    *((unsigned int *)t40) = t48;
    t49 = *((unsigned int *)t46);
    t50 = (t49 >> 0);
    *((unsigned int *)t44) = t50;
    t51 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t51 & 4294967295U);
    t52 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t52 & 4294967295U);
    goto LAB45;

LAB46:    t57 = (t0 + 1208U);
    t58 = *((char **)t57);
    goto LAB47;

LAB48:    xsi_vlog_unsigned_bit_combine(t18, 32, t40, 32, t58, 32);
    goto LAB52;

LAB50:    memcpy(t18, t40, 8);
    goto LAB52;

LAB53:    *((unsigned int *)t19) = 1;
    goto LAB56;

LAB55:    t17 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB56;

LAB57:    t21 = (t0 + 1208U);
    t24 = *((char **)t21);
    memset(t59, 0, 8);
    t21 = (t59 + 4);
    t35 = (t24 + 4);
    t32 = *((unsigned int *)t24);
    t33 = (t32 >> 24);
    *((unsigned int *)t59) = t33;
    t34 = *((unsigned int *)t35);
    t37 = (t34 >> 24);
    *((unsigned int *)t21) = t37;
    t38 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t38 & 255U);
    t39 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t39 & 255U);
    t36 = (t0 + 2888);
    t41 = (t36 + 56U);
    t42 = *((char **)t41);
    memset(t60, 0, 8);
    t43 = (t60 + 4);
    t44 = (t42 + 8);
    t45 = (t42 + 12);
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 8);
    *((unsigned int *)t60) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 >> 8);
    *((unsigned int *)t43) = t50;
    t51 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t51 & 16777215U);
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 & 16777215U);
    xsi_vlogtype_concat(t40, 32, 32, 2U, t60, 24, t59, 8);
    goto LAB58;

LAB59:    t46 = (t0 + 2888);
    t57 = (t46 + 56U);
    t58 = *((char **)t57);
    memset(t62, 0, 8);
    t63 = (t62 + 4);
    t64 = (t58 + 4);
    t65 = *((unsigned int *)t58);
    t66 = (t65 >> 0);
    *((unsigned int *)t62) = t66;
    t67 = *((unsigned int *)t64);
    t68 = (t67 >> 0);
    *((unsigned int *)t63) = t68;
    t69 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t69 & 255U);
    t70 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t70 & 255U);
    t72 = (t0 + 1208U);
    t73 = *((char **)t72);
    memset(t71, 0, 8);
    t72 = (t71 + 4);
    t74 = (t73 + 4);
    t75 = *((unsigned int *)t73);
    t76 = (t75 >> 0);
    *((unsigned int *)t71) = t76;
    t77 = *((unsigned int *)t74);
    t78 = (t77 >> 0);
    *((unsigned int *)t72) = t78;
    t79 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t79 & 16777215U);
    t80 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t80 & 16777215U);
    xsi_vlogtype_concat(t61, 32, 32, 2U, t71, 24, t62, 8);
    goto LAB60;

LAB61:    xsi_vlog_unsigned_bit_combine(t18, 32, t40, 32, t61, 32);
    goto LAB65;

LAB63:    memcpy(t18, t40, 8);
    goto LAB65;

LAB66:    *((unsigned int *)t19) = 1;
    goto LAB69;

LAB68:    t17 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB69;

LAB70:    t21 = (t0 + 1208U);
    t24 = *((char **)t21);
    memset(t59, 0, 8);
    t21 = (t59 + 4);
    t35 = (t24 + 4);
    t32 = *((unsigned int *)t24);
    t33 = (t32 >> 16);
    *((unsigned int *)t59) = t33;
    t34 = *((unsigned int *)t35);
    t37 = (t34 >> 16);
    *((unsigned int *)t21) = t37;
    t38 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t38 & 65535U);
    t39 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t39 & 65535U);
    t36 = (t0 + 2888);
    t41 = (t36 + 56U);
    t42 = *((char **)t41);
    memset(t60, 0, 8);
    t43 = (t60 + 4);
    t44 = (t42 + 8);
    t45 = (t42 + 12);
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 16);
    *((unsigned int *)t60) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 >> 16);
    *((unsigned int *)t43) = t50;
    t51 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t51 & 65535U);
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 & 65535U);
    xsi_vlogtype_concat(t40, 32, 32, 2U, t60, 16, t59, 16);
    goto LAB71;

LAB72:    t46 = (t0 + 2888);
    t57 = (t46 + 56U);
    t58 = *((char **)t57);
    memset(t62, 0, 8);
    t63 = (t62 + 4);
    t64 = (t58 + 4);
    t65 = *((unsigned int *)t58);
    t66 = (t65 >> 0);
    *((unsigned int *)t62) = t66;
    t67 = *((unsigned int *)t64);
    t68 = (t67 >> 0);
    *((unsigned int *)t63) = t68;
    t69 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t69 & 65535U);
    t70 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t70 & 65535U);
    t72 = (t0 + 1208U);
    t73 = *((char **)t72);
    memset(t71, 0, 8);
    t72 = (t71 + 4);
    t74 = (t73 + 4);
    t75 = *((unsigned int *)t73);
    t76 = (t75 >> 0);
    *((unsigned int *)t71) = t76;
    t77 = *((unsigned int *)t74);
    t78 = (t77 >> 0);
    *((unsigned int *)t72) = t78;
    t79 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t79 & 65535U);
    t80 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t80 & 65535U);
    xsi_vlogtype_concat(t61, 32, 32, 2U, t71, 16, t62, 16);
    goto LAB73;

LAB74:    xsi_vlog_unsigned_bit_combine(t18, 32, t40, 32, t61, 32);
    goto LAB78;

LAB76:    memcpy(t18, t40, 8);
    goto LAB78;

LAB79:    *((unsigned int *)t19) = 1;
    goto LAB82;

LAB81:    t17 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB82;

LAB83:    t21 = (t0 + 1208U);
    t24 = *((char **)t21);
    memset(t59, 0, 8);
    t21 = (t59 + 4);
    t35 = (t24 + 4);
    t32 = *((unsigned int *)t24);
    t33 = (t32 >> 8);
    *((unsigned int *)t59) = t33;
    t34 = *((unsigned int *)t35);
    t37 = (t34 >> 8);
    *((unsigned int *)t21) = t37;
    t38 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t38 & 16777215U);
    t39 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t39 & 16777215U);
    t36 = (t0 + 2888);
    t41 = (t36 + 56U);
    t42 = *((char **)t41);
    memset(t60, 0, 8);
    t43 = (t60 + 4);
    t44 = (t42 + 8);
    t45 = (t42 + 12);
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 24);
    *((unsigned int *)t60) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 >> 24);
    *((unsigned int *)t43) = t50;
    t51 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t51 & 255U);
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 & 255U);
    xsi_vlogtype_concat(t40, 32, 32, 2U, t60, 8, t59, 24);
    goto LAB84;

LAB85:    t46 = (t0 + 2888);
    t57 = (t46 + 56U);
    t58 = *((char **)t57);
    memset(t62, 0, 8);
    t63 = (t62 + 4);
    t64 = (t58 + 4);
    t65 = *((unsigned int *)t58);
    t66 = (t65 >> 0);
    *((unsigned int *)t62) = t66;
    t67 = *((unsigned int *)t64);
    t68 = (t67 >> 0);
    *((unsigned int *)t63) = t68;
    t69 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t69 & 16777215U);
    t70 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t70 & 16777215U);
    t72 = (t0 + 1208U);
    t73 = *((char **)t72);
    memset(t71, 0, 8);
    t72 = (t71 + 4);
    t74 = (t73 + 4);
    t75 = *((unsigned int *)t73);
    t76 = (t75 >> 0);
    *((unsigned int *)t71) = t76;
    t77 = *((unsigned int *)t74);
    t78 = (t77 >> 0);
    *((unsigned int *)t72) = t78;
    t79 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t79 & 255U);
    t80 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t80 & 255U);
    xsi_vlogtype_concat(t61, 32, 32, 2U, t71, 8, t62, 24);
    goto LAB86;

LAB87:    xsi_vlog_unsigned_bit_combine(t18, 32, t40, 32, t61, 32);
    goto LAB91;

LAB89:    memcpy(t18, t40, 8);
    goto LAB91;

LAB94:    xsi_set_current_line(87, ng0);
    t17 = (t0 + 2408);
    t20 = (t17 + 56U);
    t21 = *((char **)t20);
    memset(t40, 0, 8);
    t24 = (t21 + 4);
    t30 = *((unsigned int *)t24);
    t31 = (~(t30));
    t32 = *((unsigned int *)t21);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB103;

LAB104:    if (*((unsigned int *)t24) != 0)
        goto LAB105;

LAB106:    t36 = (t40 + 4);
    t37 = *((unsigned int *)t40);
    t38 = *((unsigned int *)t36);
    t39 = (t37 || t38);
    if (t39 > 0)
        goto LAB107;

LAB108:    t53 = *((unsigned int *)t40);
    t54 = (~(t53));
    t55 = *((unsigned int *)t36);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB109;

LAB110:    if (*((unsigned int *)t36) > 0)
        goto LAB111;

LAB112:    if (*((unsigned int *)t40) > 0)
        goto LAB113;

LAB114:    memcpy(t19, t60, 8);

LAB115:    t82 = (t0 + 2568);
    xsi_vlogvar_assign_value(t82, t19, 0, 0, 32);
    goto LAB102;

LAB96:    xsi_set_current_line(88, ng0);
    t5 = (t0 + 2408);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t40, 0, 8);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t12);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB116;

LAB117:    if (*((unsigned int *)t15) != 0)
        goto LAB118;

LAB119:    t20 = (t40 + 4);
    t16 = *((unsigned int *)t40);
    t30 = *((unsigned int *)t20);
    t31 = (t16 || t30);
    if (t31 > 0)
        goto LAB120;

LAB121:    t47 = *((unsigned int *)t40);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB122;

LAB123:    if (*((unsigned int *)t20) > 0)
        goto LAB124;

LAB125:    if (*((unsigned int *)t40) > 0)
        goto LAB126;

LAB127:    memcpy(t19, t60, 8);

LAB128:    t83 = (t0 + 2568);
    xsi_vlogvar_assign_value(t83, t19, 0, 0, 32);
    goto LAB102;

LAB98:    xsi_set_current_line(89, ng0);
    t5 = (t0 + 2408);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t40, 0, 8);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t12);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB129;

LAB130:    if (*((unsigned int *)t15) != 0)
        goto LAB131;

LAB132:    t20 = (t40 + 4);
    t16 = *((unsigned int *)t40);
    t30 = *((unsigned int *)t20);
    t31 = (t16 || t30);
    if (t31 > 0)
        goto LAB133;

LAB134:    t47 = *((unsigned int *)t40);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB135;

LAB136:    if (*((unsigned int *)t20) > 0)
        goto LAB137;

LAB138:    if (*((unsigned int *)t40) > 0)
        goto LAB139;

LAB140:    memcpy(t19, t60, 8);

LAB141:    t83 = (t0 + 2568);
    xsi_vlogvar_assign_value(t83, t19, 0, 0, 32);
    goto LAB102;

LAB100:    xsi_set_current_line(90, ng0);
    t5 = (t0 + 2408);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t19, 0, 8);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t12);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB142;

LAB143:    if (*((unsigned int *)t15) != 0)
        goto LAB144;

LAB145:    t20 = (t19 + 4);
    t16 = *((unsigned int *)t19);
    t30 = *((unsigned int *)t20);
    t31 = (t16 || t30);
    if (t31 > 0)
        goto LAB146;

LAB147:    t32 = *((unsigned int *)t19);
    t33 = (~(t32));
    t34 = *((unsigned int *)t20);
    t37 = (t33 || t34);
    if (t37 > 0)
        goto LAB148;

LAB149:    if (*((unsigned int *)t20) > 0)
        goto LAB150;

LAB151:    if (*((unsigned int *)t19) > 0)
        goto LAB152;

LAB153:    memcpy(t84, t86, 16);

LAB154:    t72 = (t0 + 2568);
    xsi_vlogvar_assign_value(t72, t84, 0, 0, 32);
    goto LAB102;

LAB103:    *((unsigned int *)t40) = 1;
    goto LAB106;

LAB105:    t35 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB106;

LAB107:    t41 = (t0 + 2888);
    t42 = (t41 + 56U);
    t43 = *((char **)t42);
    memset(t59, 0, 8);
    t44 = (t59 + 4);
    t45 = (t43 + 8);
    t46 = (t43 + 12);
    t47 = *((unsigned int *)t45);
    t48 = (t47 >> 0);
    *((unsigned int *)t59) = t48;
    t49 = *((unsigned int *)t46);
    t50 = (t49 >> 0);
    *((unsigned int *)t44) = t50;
    t51 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t51 & 4294967295U);
    t52 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t52 & 4294967295U);
    goto LAB108;

LAB109:    t57 = (t0 + 1208U);
    t58 = *((char **)t57);
    memset(t61, 0, 8);
    t57 = (t61 + 4);
    t63 = (t58 + 4);
    t65 = *((unsigned int *)t58);
    t66 = (t65 >> 0);
    *((unsigned int *)t61) = t66;
    t67 = *((unsigned int *)t63);
    t68 = (t67 >> 0);
    *((unsigned int *)t57) = t68;
    t69 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t69 & 255U);
    t70 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t70 & 255U);
    t64 = (t0 + 2888);
    t72 = (t64 + 56U);
    t73 = *((char **)t72);
    memset(t62, 0, 8);
    t74 = (t62 + 4);
    t81 = (t73 + 4);
    t75 = *((unsigned int *)t73);
    t76 = (t75 >> 8);
    *((unsigned int *)t62) = t76;
    t77 = *((unsigned int *)t81);
    t78 = (t77 >> 8);
    *((unsigned int *)t74) = t78;
    t79 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t79 & 16777215U);
    t80 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t80 & 16777215U);
    xsi_vlogtype_concat(t60, 32, 32, 2U, t62, 24, t61, 8);
    goto LAB110;

LAB111:    xsi_vlog_unsigned_bit_combine(t19, 32, t59, 32, t60, 32);
    goto LAB115;

LAB113:    memcpy(t19, t59, 8);
    goto LAB115;

LAB116:    *((unsigned int *)t40) = 1;
    goto LAB119;

LAB118:    t17 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB119;

LAB120:    t21 = (t0 + 2888);
    t24 = (t21 + 56U);
    t35 = *((char **)t24);
    memset(t59, 0, 8);
    t36 = (t59 + 4);
    t41 = (t35 + 8);
    t42 = (t35 + 12);
    t32 = *((unsigned int *)t41);
    t33 = (t32 >> 0);
    *((unsigned int *)t59) = t33;
    t34 = *((unsigned int *)t42);
    t37 = (t34 >> 0);
    *((unsigned int *)t36) = t37;
    t38 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t38 & 4294967295U);
    t39 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t39 & 4294967295U);
    goto LAB121;

LAB122:    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    memset(t61, 0, 8);
    t46 = (t61 + 4);
    t57 = (t45 + 4);
    t51 = *((unsigned int *)t45);
    t52 = (t51 >> 0);
    *((unsigned int *)t61) = t52;
    t53 = *((unsigned int *)t57);
    t54 = (t53 >> 0);
    *((unsigned int *)t46) = t54;
    t55 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t55 & 255U);
    t56 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t56 & 255U);
    t58 = (t0 + 1208U);
    t63 = *((char **)t58);
    memset(t62, 0, 8);
    t58 = (t62 + 4);
    t64 = (t63 + 4);
    t65 = *((unsigned int *)t63);
    t66 = (t65 >> 0);
    *((unsigned int *)t62) = t66;
    t67 = *((unsigned int *)t64);
    t68 = (t67 >> 0);
    *((unsigned int *)t58) = t68;
    t69 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t69 & 255U);
    t70 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t70 & 255U);
    t72 = (t0 + 2888);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    memset(t71, 0, 8);
    t81 = (t71 + 4);
    t82 = (t74 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (t75 >> 16);
    *((unsigned int *)t71) = t76;
    t77 = *((unsigned int *)t82);
    t78 = (t77 >> 16);
    *((unsigned int *)t81) = t78;
    t79 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t79 & 65535U);
    t80 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t80 & 65535U);
    xsi_vlogtype_concat(t60, 32, 32, 3U, t71, 16, t62, 8, t61, 8);
    goto LAB123;

LAB124:    xsi_vlog_unsigned_bit_combine(t19, 32, t59, 32, t60, 32);
    goto LAB128;

LAB126:    memcpy(t19, t59, 8);
    goto LAB128;

LAB129:    *((unsigned int *)t40) = 1;
    goto LAB132;

LAB131:    t17 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB132;

LAB133:    t21 = (t0 + 2888);
    t24 = (t21 + 56U);
    t35 = *((char **)t24);
    memset(t59, 0, 8);
    t36 = (t59 + 4);
    t41 = (t35 + 8);
    t42 = (t35 + 12);
    t32 = *((unsigned int *)t41);
    t33 = (t32 >> 0);
    *((unsigned int *)t59) = t33;
    t34 = *((unsigned int *)t42);
    t37 = (t34 >> 0);
    *((unsigned int *)t36) = t37;
    t38 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t38 & 4294967295U);
    t39 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t39 & 4294967295U);
    goto LAB134;

LAB135:    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    memset(t61, 0, 8);
    t46 = (t61 + 4);
    t57 = (t45 + 4);
    t51 = *((unsigned int *)t45);
    t52 = (t51 >> 0);
    *((unsigned int *)t61) = t52;
    t53 = *((unsigned int *)t57);
    t54 = (t53 >> 0);
    *((unsigned int *)t46) = t54;
    t55 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t55 & 65535U);
    t56 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t56 & 65535U);
    t58 = (t0 + 1208U);
    t63 = *((char **)t58);
    memset(t62, 0, 8);
    t58 = (t62 + 4);
    t64 = (t63 + 4);
    t65 = *((unsigned int *)t63);
    t66 = (t65 >> 0);
    *((unsigned int *)t62) = t66;
    t67 = *((unsigned int *)t64);
    t68 = (t67 >> 0);
    *((unsigned int *)t58) = t68;
    t69 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t69 & 255U);
    t70 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t70 & 255U);
    t72 = (t0 + 2888);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    memset(t71, 0, 8);
    t81 = (t71 + 4);
    t82 = (t74 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (t75 >> 24);
    *((unsigned int *)t71) = t76;
    t77 = *((unsigned int *)t82);
    t78 = (t77 >> 24);
    *((unsigned int *)t81) = t78;
    t79 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t79 & 255U);
    t80 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t80 & 255U);
    xsi_vlogtype_concat(t60, 32, 32, 3U, t71, 8, t62, 8, t61, 16);
    goto LAB136;

LAB137:    xsi_vlog_unsigned_bit_combine(t19, 32, t59, 32, t60, 32);
    goto LAB141;

LAB139:    memcpy(t19, t59, 8);
    goto LAB141;

LAB142:    *((unsigned int *)t19) = 1;
    goto LAB145;

LAB144:    t17 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB145;

LAB146:    t21 = (t0 + 2888);
    t24 = (t21 + 56U);
    t35 = *((char **)t24);
    xsi_vlog_get_part_select_value(t85, 40, t35, 63, 32);
    goto LAB147;

LAB148:    t36 = (t0 + 2888);
    t41 = (t36 + 56U);
    t42 = *((char **)t41);
    memset(t40, 0, 8);
    t43 = (t40 + 4);
    t44 = (t42 + 4);
    t38 = *((unsigned int *)t42);
    t39 = (t38 >> 0);
    *((unsigned int *)t40) = t39;
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 0);
    *((unsigned int *)t43) = t48;
    t49 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t49 & 16777215U);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t50 & 16777215U);
    t45 = (t0 + 1208U);
    t46 = *((char **)t45);
    memset(t59, 0, 8);
    t45 = (t59 + 4);
    t57 = (t46 + 4);
    t51 = *((unsigned int *)t46);
    t52 = (t51 >> 0);
    *((unsigned int *)t59) = t52;
    t53 = *((unsigned int *)t57);
    t54 = (t53 >> 0);
    *((unsigned int *)t45) = t54;
    t55 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t55 & 255U);
    t56 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t56 & 255U);
    t58 = (t0 + 1208U);
    t63 = *((char **)t58);
    memset(t60, 0, 8);
    t58 = (t60 + 4);
    t64 = (t63 + 4);
    t65 = *((unsigned int *)t63);
    t66 = (t65 >> 0);
    *((unsigned int *)t60) = t66;
    t67 = *((unsigned int *)t64);
    t68 = (t67 >> 0);
    *((unsigned int *)t58) = t68;
    t69 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t69 & 255U);
    t70 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t70 & 255U);
    xsi_vlogtype_concat(t86, 40, 40, 3U, t60, 8, t59, 8, t40, 24);
    goto LAB149;

LAB150:    xsi_vlog_unsigned_bit_combine(t84, 40, t85, 40, t86, 40);
    goto LAB154;

LAB152:    memcpy(t84, t85, 16);
    goto LAB154;

}

static void Always_97_4(char *t0)
{
    char t4[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    int t15;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;

LAB0:    t1 = (t0 + 5120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 5488);
    *((int *)t2) = 1;
    t3 = (t0 + 5152);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(97, ng0);

LAB5:    xsi_set_current_line(98, ng0);
    t5 = (t0 + 1688U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t4 + 4);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (t8 >> 0);
    *((unsigned int *)t4) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 3U);
    t13 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t13 & 3U);

LAB6:    t14 = ((char*)((ng1)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 32, t14, 32);
    if (t15 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 32, t2, 32);
    if (t15 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng7)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 32, t2, 32);
    if (t15 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng8)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 32, t2, 32);
    if (t15 == 1)
        goto LAB13;

LAB14:
LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(99, ng0);
    t17 = (t0 + 2888);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memset(t16, 0, 8);
    t20 = (t16 + 4);
    t21 = (t19 + 4);
    t22 = *((unsigned int *)t19);
    t23 = (t22 >> 0);
    *((unsigned int *)t16) = t23;
    t24 = *((unsigned int *)t21);
    t25 = (t24 >> 0);
    *((unsigned int *)t20) = t25;
    t26 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t26 & 4294967295U);
    t27 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t27 & 4294967295U);
    t28 = (t0 + 3048);
    xsi_vlogvar_assign_value(t28, t16, 0, 0, 32);
    goto LAB15;

LAB9:    xsi_set_current_line(100, ng0);
    t3 = (t0 + 2888);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    memset(t16, 0, 8);
    t7 = (t16 + 4);
    t14 = (t6 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (t8 >> 8);
    *((unsigned int *)t16) = t9;
    t10 = *((unsigned int *)t14);
    t11 = (t10 >> 8);
    *((unsigned int *)t7) = t11;
    t17 = (t6 + 8);
    t18 = (t6 + 12);
    t12 = *((unsigned int *)t17);
    t13 = (t12 << 24);
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t22 | t13);
    t23 = *((unsigned int *)t18);
    t24 = (t23 << 24);
    t25 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t25 | t24);
    t26 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t26 & 4294967295U);
    t27 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t27 & 4294967295U);
    t19 = (t0 + 3048);
    xsi_vlogvar_assign_value(t19, t16, 0, 0, 32);
    goto LAB15;

LAB11:    xsi_set_current_line(101, ng0);
    t3 = (t0 + 2888);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    memset(t16, 0, 8);
    t7 = (t16 + 4);
    t14 = (t6 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (t8 >> 16);
    *((unsigned int *)t16) = t9;
    t10 = *((unsigned int *)t14);
    t11 = (t10 >> 16);
    *((unsigned int *)t7) = t11;
    t17 = (t6 + 8);
    t18 = (t6 + 12);
    t12 = *((unsigned int *)t17);
    t13 = (t12 << 16);
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t22 | t13);
    t23 = *((unsigned int *)t18);
    t24 = (t23 << 16);
    t25 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t25 | t24);
    t26 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t26 & 4294967295U);
    t27 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t27 & 4294967295U);
    t19 = (t0 + 3048);
    xsi_vlogvar_assign_value(t19, t16, 0, 0, 32);
    goto LAB15;

LAB13:    xsi_set_current_line(102, ng0);
    t3 = (t0 + 2888);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    memset(t16, 0, 8);
    t7 = (t16 + 4);
    t14 = (t6 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (t8 >> 24);
    *((unsigned int *)t16) = t9;
    t10 = *((unsigned int *)t14);
    t11 = (t10 >> 24);
    *((unsigned int *)t7) = t11;
    t17 = (t6 + 8);
    t18 = (t6 + 12);
    t12 = *((unsigned int *)t17);
    t13 = (t12 << 8);
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t22 | t13);
    t23 = *((unsigned int *)t18);
    t24 = (t23 << 8);
    t25 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t25 | t24);
    t26 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t26 & 4294967295U);
    t27 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t27 & 4294967295U);
    t19 = (t0 + 3048);
    xsi_vlogvar_assign_value(t19, t16, 0, 0, 32);
    goto LAB15;

}


extern void work_m_00000000000000996807_1368203981_init()
{
	static char *pe[] = {(void *)Initial_31_0,(void *)Always_32_1,(void *)Cont_49_2,(void *)Always_58_3,(void *)Always_97_4};
	xsi_register_didat("work_m_00000000000000996807_1368203981", "isim/t_PC_isim_beh.exe.sim/work/m_00000000000000996807_1368203981.didat");
	xsi_register_executes(pe);
}
