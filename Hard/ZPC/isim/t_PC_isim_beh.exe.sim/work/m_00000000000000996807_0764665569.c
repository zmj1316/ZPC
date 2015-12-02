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
static const char *ng0 = "F:/Workspace/ASM/Hard/Mem/Mem16.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 4294967295U};
static int ng3[] = {31, 0};
static int ng4[] = {1, 0};
static int ng5[] = {63, 0};
static int ng6[] = {32, 0};
static int ng7[] = {3, 0};



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
    char t36[8];
    char t55[8];
    char t56[8];
    char t63[8];
    char t64[8];
    char t71[8];
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
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t37;
    char *t38;
    char *t39;
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
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
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
    char *t84;

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

LAB25:    t2 = ((char*)((ng7)));
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
    t7 = (t6 >> 1);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t15);
    t9 = (t8 >> 1);
    *((unsigned int *)t11) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 2047U);
    t16 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t16 & 2047U);
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
    t7 = (t6 >> 1);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t11);
    t9 = (t8 >> 1);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 2047U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 2047U);
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
    t5 = (t0 + 1648U);
    t12 = (t5 + 72U);
    t15 = *((char **)t12);
    t17 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t14, 32, t11, t15, 2, t17, 32, 1);

LAB30:    t20 = ((char*)((ng1)));
    t22 = xsi_vlog_unsigned_case_compare(t14, 32, t20, 32);
    if (t22 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t14, 32, t2, 32);
    if (t13 == 1)
        goto LAB33;

LAB34:
LAB35:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng4)));
    t5 = (t0 + 3208);
    xsi_vlogvar_assign_value(t5, t2, 0, 0, 1);
    goto LAB28;

LAB26:    xsi_set_current_line(83, ng0);

LAB62:    xsi_set_current_line(84, ng0);
    t5 = (t0 + 1688U);
    t11 = *((char **)t5);
    t5 = (t0 + 1648U);
    t12 = (t5 + 72U);
    t15 = *((char **)t12);
    t17 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t18, 32, t11, t15, 2, t17, 32, 1);

LAB63:    t20 = ((char*)((ng1)));
    t22 = xsi_vlog_unsigned_case_compare(t18, 32, t20, 32);
    if (t22 == 1)
        goto LAB64;

LAB65:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t18, 32, t2, 32);
    if (t13 == 1)
        goto LAB66;

LAB67:
LAB68:    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng4)));
    t5 = (t0 + 3208);
    xsi_vlogvar_assign_value(t5, t2, 0, 0, 1);
    goto LAB28;

LAB31:    xsi_set_current_line(78, ng0);
    t21 = (t0 + 2408);
    t24 = (t21 + 56U);
    t30 = *((char **)t24);
    memset(t19, 0, 8);
    t31 = (t30 + 4);
    t6 = *((unsigned int *)t31);
    t7 = (~(t6));
    t8 = *((unsigned int *)t30);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t31) != 0)
        goto LAB38;

LAB39:    t33 = (t19 + 4);
    t16 = *((unsigned int *)t19);
    t34 = *((unsigned int *)t33);
    t35 = (t16 || t34);
    if (t35 > 0)
        goto LAB40;

LAB41:    t49 = *((unsigned int *)t19);
    t50 = (~(t49));
    t51 = *((unsigned int *)t33);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t33) > 0)
        goto LAB44;

LAB45:    if (*((unsigned int *)t19) > 0)
        goto LAB46;

LAB47:    memcpy(t18, t54, 8);

LAB48:    t53 = (t0 + 2568);
    xsi_vlogvar_assign_value(t53, t18, 0, 0, 32);
    goto LAB35;

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
        goto LAB49;

LAB50:    if (*((unsigned int *)t15) != 0)
        goto LAB51;

LAB52:    t20 = (t19 + 4);
    t16 = *((unsigned int *)t19);
    t34 = *((unsigned int *)t20);
    t35 = (t16 || t34);
    if (t35 > 0)
        goto LAB53;

LAB54:    t59 = *((unsigned int *)t19);
    t60 = (~(t59));
    t61 = *((unsigned int *)t20);
    t62 = (t60 || t61);
    if (t62 > 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t20) > 0)
        goto LAB57;

LAB58:    if (*((unsigned int *)t19) > 0)
        goto LAB59;

LAB60:    memcpy(t18, t63, 8);

LAB61:    t81 = (t0 + 2568);
    xsi_vlogvar_assign_value(t81, t18, 0, 0, 32);
    goto LAB35;

LAB36:    *((unsigned int *)t19) = 1;
    goto LAB39;

LAB38:    t32 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB39;

LAB40:    t37 = (t0 + 2888);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    memset(t36, 0, 8);
    t40 = (t36 + 4);
    t41 = (t39 + 8);
    t42 = (t39 + 12);
    t43 = *((unsigned int *)t41);
    t44 = (t43 >> 0);
    *((unsigned int *)t36) = t44;
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 0);
    *((unsigned int *)t40) = t46;
    t47 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t47 & 4294967295U);
    t48 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t48 & 4294967295U);
    goto LAB41;

LAB42:    t53 = (t0 + 1208U);
    t54 = *((char **)t53);
    goto LAB43;

LAB44:    xsi_vlog_unsigned_bit_combine(t18, 32, t36, 32, t54, 32);
    goto LAB48;

LAB46:    memcpy(t18, t36, 8);
    goto LAB48;

LAB49:    *((unsigned int *)t19) = 1;
    goto LAB52;

LAB51:    t17 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB52;

LAB53:    t21 = (t0 + 1208U);
    t24 = *((char **)t21);
    memset(t55, 0, 8);
    t21 = (t55 + 4);
    t30 = (t24 + 4);
    t43 = *((unsigned int *)t24);
    t44 = (t43 >> 16);
    *((unsigned int *)t55) = t44;
    t45 = *((unsigned int *)t30);
    t46 = (t45 >> 16);
    *((unsigned int *)t21) = t46;
    t47 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t47 & 65535U);
    t48 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t48 & 65535U);
    t31 = (t0 + 2888);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    memset(t56, 0, 8);
    t37 = (t56 + 4);
    t38 = (t33 + 8);
    t39 = (t33 + 12);
    t49 = *((unsigned int *)t38);
    t50 = (t49 >> 16);
    *((unsigned int *)t56) = t50;
    t51 = *((unsigned int *)t39);
    t52 = (t51 >> 16);
    *((unsigned int *)t37) = t52;
    t57 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t57 & 65535U);
    t58 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t58 & 65535U);
    xsi_vlogtype_concat(t36, 32, 32, 2U, t56, 16, t55, 16);
    goto LAB54;

LAB55:    t40 = (t0 + 2888);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memset(t64, 0, 8);
    t53 = (t64 + 4);
    t54 = (t42 + 4);
    t65 = *((unsigned int *)t42);
    t66 = (t65 >> 0);
    *((unsigned int *)t64) = t66;
    t67 = *((unsigned int *)t54);
    t68 = (t67 >> 0);
    *((unsigned int *)t53) = t68;
    t69 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t69 & 65535U);
    t70 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t70 & 65535U);
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
    xsi_vlogtype_concat(t63, 32, 32, 2U, t71, 16, t64, 16);
    goto LAB56;

LAB57:    xsi_vlog_unsigned_bit_combine(t18, 32, t36, 32, t63, 32);
    goto LAB61;

LAB59:    memcpy(t18, t36, 8);
    goto LAB61;

LAB64:    xsi_set_current_line(85, ng0);
    t21 = (t0 + 2408);
    t24 = (t21 + 56U);
    t30 = *((char **)t24);
    memset(t36, 0, 8);
    t31 = (t30 + 4);
    t6 = *((unsigned int *)t31);
    t7 = (~(t6));
    t8 = *((unsigned int *)t30);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB69;

LAB70:    if (*((unsigned int *)t31) != 0)
        goto LAB71;

LAB72:    t33 = (t36 + 4);
    t16 = *((unsigned int *)t36);
    t34 = *((unsigned int *)t33);
    t35 = (t16 || t34);
    if (t35 > 0)
        goto LAB73;

LAB74:    t49 = *((unsigned int *)t36);
    t50 = (~(t49));
    t51 = *((unsigned int *)t33);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB75;

LAB76:    if (*((unsigned int *)t33) > 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t36) > 0)
        goto LAB79;

LAB80:    memcpy(t19, t56, 8);

LAB81:    t84 = (t0 + 2568);
    xsi_vlogvar_assign_value(t84, t19, 0, 0, 32);
    goto LAB68;

LAB66:    xsi_set_current_line(86, ng0);
    t5 = (t0 + 2408);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    memset(t36, 0, 8);
    t15 = (t12 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t12);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB82;

LAB83:    if (*((unsigned int *)t15) != 0)
        goto LAB84;

LAB85:    t20 = (t36 + 4);
    t16 = *((unsigned int *)t36);
    t34 = *((unsigned int *)t20);
    t35 = (t16 || t34);
    if (t35 > 0)
        goto LAB86;

LAB87:    t49 = *((unsigned int *)t36);
    t50 = (~(t49));
    t51 = *((unsigned int *)t20);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB88;

LAB89:    if (*((unsigned int *)t20) > 0)
        goto LAB90;

LAB91:    if (*((unsigned int *)t36) > 0)
        goto LAB92;

LAB93:    memcpy(t19, t56, 8);

LAB94:    t72 = (t0 + 2568);
    xsi_vlogvar_assign_value(t72, t19, 0, 0, 32);
    goto LAB68;

LAB69:    *((unsigned int *)t36) = 1;
    goto LAB72;

LAB71:    t32 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB72;

LAB73:    t37 = (t0 + 2888);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    memset(t55, 0, 8);
    t40 = (t55 + 4);
    t41 = (t39 + 8);
    t42 = (t39 + 12);
    t43 = *((unsigned int *)t41);
    t44 = (t43 >> 0);
    *((unsigned int *)t55) = t44;
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 0);
    *((unsigned int *)t40) = t46;
    t47 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t47 & 4294967295U);
    t48 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t48 & 4294967295U);
    goto LAB74;

LAB75:    t53 = (t0 + 1208U);
    t54 = *((char **)t53);
    memset(t63, 0, 8);
    t53 = (t63 + 4);
    t72 = (t54 + 4);
    t57 = *((unsigned int *)t54);
    t58 = (t57 >> 0);
    *((unsigned int *)t63) = t58;
    t59 = *((unsigned int *)t72);
    t60 = (t59 >> 0);
    *((unsigned int *)t53) = t60;
    t61 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t61 & 65535U);
    t62 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t62 & 65535U);
    t73 = (t0 + 2888);
    t74 = (t73 + 56U);
    t81 = *((char **)t74);
    memset(t64, 0, 8);
    t82 = (t64 + 4);
    t83 = (t81 + 4);
    t65 = *((unsigned int *)t81);
    t66 = (t65 >> 16);
    *((unsigned int *)t64) = t66;
    t67 = *((unsigned int *)t83);
    t68 = (t67 >> 16);
    *((unsigned int *)t82) = t68;
    t69 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t69 & 65535U);
    t70 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t70 & 65535U);
    xsi_vlogtype_concat(t56, 32, 32, 2U, t64, 16, t63, 16);
    goto LAB76;

LAB77:    xsi_vlog_unsigned_bit_combine(t19, 32, t55, 32, t56, 32);
    goto LAB81;

LAB79:    memcpy(t19, t55, 8);
    goto LAB81;

LAB82:    *((unsigned int *)t36) = 1;
    goto LAB85;

LAB84:    t17 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB85;

LAB86:    t21 = (t0 + 2888);
    t24 = (t21 + 56U);
    t30 = *((char **)t24);
    memset(t55, 0, 8);
    t31 = (t55 + 4);
    t32 = (t30 + 8);
    t33 = (t30 + 12);
    t43 = *((unsigned int *)t32);
    t44 = (t43 >> 0);
    *((unsigned int *)t55) = t44;
    t45 = *((unsigned int *)t33);
    t46 = (t45 >> 0);
    *((unsigned int *)t31) = t46;
    t47 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t47 & 4294967295U);
    t48 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t48 & 4294967295U);
    goto LAB87;

LAB88:    t37 = (t0 + 2888);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    memset(t63, 0, 8);
    t40 = (t63 + 4);
    t41 = (t39 + 4);
    t57 = *((unsigned int *)t39);
    t58 = (t57 >> 0);
    *((unsigned int *)t63) = t58;
    t59 = *((unsigned int *)t41);
    t60 = (t59 >> 0);
    *((unsigned int *)t40) = t60;
    t61 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t61 & 65535U);
    t62 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t62 & 65535U);
    t42 = (t0 + 1208U);
    t53 = *((char **)t42);
    memset(t64, 0, 8);
    t42 = (t64 + 4);
    t54 = (t53 + 4);
    t65 = *((unsigned int *)t53);
    t66 = (t65 >> 0);
    *((unsigned int *)t64) = t66;
    t67 = *((unsigned int *)t54);
    t68 = (t67 >> 0);
    *((unsigned int *)t42) = t68;
    t69 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t69 & 65535U);
    t70 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t70 & 65535U);
    xsi_vlogtype_concat(t56, 32, 32, 2U, t64, 16, t63, 16);
    goto LAB89;

LAB90:    xsi_vlog_unsigned_bit_combine(t19, 32, t55, 32, t56, 32);
    goto LAB94;

LAB92:    memcpy(t19, t55, 8);
    goto LAB94;

}

static void Always_93_4(char *t0)
{
    char t6[8];
    char t12[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;

LAB0:    t1 = (t0 + 5120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 5488);
    *((int *)t2) = 1;
    t3 = (t0 + 5152);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(93, ng0);

LAB5:    xsi_set_current_line(94, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = (t0 + 1648U);
    t7 = (t4 + 72U);
    t8 = *((char **)t7);
    t9 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t6, 32, t5, t8, 2, t9, 32, 1);

LAB6:    t10 = ((char*)((ng1)));
    t11 = xsi_vlog_unsigned_case_compare(t6, 32, t10, 32);
    if (t11 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t11 = xsi_vlog_unsigned_case_compare(t6, 32, t2, 32);
    if (t11 == 1)
        goto LAB9;

LAB10:
LAB11:    goto LAB2;

LAB7:    xsi_set_current_line(95, ng0);
    t13 = (t0 + 2888);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t12, 0, 8);
    t16 = (t12 + 4);
    t17 = (t15 + 4);
    t18 = *((unsigned int *)t15);
    t19 = (t18 >> 0);
    *((unsigned int *)t12) = t19;
    t20 = *((unsigned int *)t17);
    t21 = (t20 >> 0);
    *((unsigned int *)t16) = t21;
    t22 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t22 & 4294967295U);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 & 4294967295U);
    t24 = (t0 + 3048);
    xsi_vlogvar_assign_value(t24, t12, 0, 0, 32);
    goto LAB11;

LAB9:    xsi_set_current_line(96, ng0);
    t3 = (t0 + 2888);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t12, 0, 8);
    t7 = (t12 + 4);
    t8 = (t5 + 4);
    t18 = *((unsigned int *)t5);
    t19 = (t18 >> 16);
    *((unsigned int *)t12) = t19;
    t20 = *((unsigned int *)t8);
    t21 = (t20 >> 16);
    *((unsigned int *)t7) = t21;
    t9 = (t5 + 8);
    t10 = (t5 + 12);
    t22 = *((unsigned int *)t9);
    t23 = (t22 << 16);
    t25 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t25 | t23);
    t26 = *((unsigned int *)t10);
    t27 = (t26 << 16);
    t28 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t28 | t27);
    t29 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t29 & 4294967295U);
    t30 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t30 & 4294967295U);
    t13 = (t0 + 3048);
    xsi_vlogvar_assign_value(t13, t12, 0, 0, 32);
    goto LAB11;

}


extern void work_m_00000000000000996807_0764665569_init()
{
	static char *pe[] = {(void *)Initial_31_0,(void *)Always_32_1,(void *)Cont_49_2,(void *)Always_58_3,(void *)Always_93_4};
	xsi_register_didat("work_m_00000000000000996807_0764665569", "isim/t_PC_isim_beh.exe.sim/work/m_00000000000000996807_0764665569.didat");
	xsi_register_executes(pe);
}
