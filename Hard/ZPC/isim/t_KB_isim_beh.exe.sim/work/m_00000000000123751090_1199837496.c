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
static const char *ng0 = "F:/Workspace/ASM/Hard/ZPC/PC.v";
static int ng1[] = {11, 0};
static int ng2[] = {24, 0};
static int ng3[] = {19, 0};
static int ng4[] = {1, 0};
static unsigned int ng5[] = {2U, 0U};
static int ng6[] = {2, 0};
static int ng7[] = {3, 0};
static unsigned int ng8[] = {8U, 0U};
static int ng9[] = {4, 0};
static unsigned int ng10[] = {0U, 0U};
static int ng11[] = {5, 0};
static unsigned int ng12[] = {12U, 0U};
static int ng13[] = {6, 0};
static int ng14[] = {7, 0};
static unsigned int ng15[] = {1U, 0U};
static int ng16[] = {8, 0};
static int ng17[] = {9, 0};
static unsigned int ng18[] = {6U, 0U};
static int ng19[] = {10, 0};
static int ng20[] = {0, 0};
static int ng21[] = {32, 0};
static int ng22[] = {33, 0};
static int ng23[] = {34, 0};



static void Cont_174_0(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;

LAB0:    t1 = (t0 + 4352U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 2952);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t4 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 14);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 14);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t13 & 15U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 15U);
    t15 = (t0 + 3432);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    xsi_vlogtype_concat(t3, 5, 5, 2U, t17, 1, t4, 4);
    t18 = (t0 + 5264);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memset(t22, 0, 8);
    t23 = 31U;
    t24 = t23;
    t25 = (t3 + 4);
    t26 = *((unsigned int *)t3);
    t23 = (t23 & t26);
    t27 = *((unsigned int *)t25);
    t24 = (t24 & t27);
    t28 = (t22 + 4);
    t29 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t29 | t23);
    t30 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t30 | t24);
    xsi_driver_vfirst_trans(t18, 0, 4);
    t31 = (t0 + 5168);
    *((int *)t31) = 1;

LAB1:    return;
}

static void Initial_176_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t5[8];
    char *t1;
    char *t2;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    int t13;
    char *t14;
    unsigned int t15;
    int t16;
    int t17;
    char *t18;
    unsigned int t19;
    int t20;
    int t21;
    unsigned int t22;
    int t23;
    unsigned int t24;
    unsigned int t25;
    int t26;
    int t27;

LAB0:    xsi_set_current_line(176, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2952);
    t6 = (t0 + 2952);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = ((char*)((ng2)));
    t10 = ((char*)((ng3)));
    xsi_vlog_convert_partindices(t3, t4, t5, ((int*)(t8)), 2, t9, 32, 1, t10, 32, 1);
    t11 = (t3 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (!(t12));
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (!(t15));
    t17 = (t13 && t16);
    t18 = (t5 + 4);
    t19 = *((unsigned int *)t18);
    t20 = (!(t19));
    t21 = (t17 && t20);
    if (t21 == 1)
        goto LAB2;

LAB3:
LAB1:    return;
LAB2:    t22 = *((unsigned int *)t5);
    t23 = (t22 + 0);
    t24 = *((unsigned int *)t3);
    t25 = *((unsigned int *)t4);
    t26 = (t24 - t25);
    t27 = (t26 + 1);
    xsi_vlogvar_assign_value(t2, t1, t23, *((unsigned int *)t4), t27);
    goto LAB3;

}

static void Always_178_2(char *t0)
{
    char t8[8];
    char t27[8];
    char t30[8];
    char t31[8];
    char t32[8];
    char t49[8];
    char t84[8];
    char t85[8];
    char t86[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    int t24;
    char *t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;

LAB0:    t1 = (t0 + 4848U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 5184);
    *((int *)t2) = 1;
    t3 = (t0 + 4880);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(178, ng0);

LAB5:    xsi_set_current_line(179, ng0);
    t4 = (t0 + 2952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t6, 25, t7, 32);
    t9 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 25, 0LL);
    xsi_set_current_line(180, ng0);
    t2 = (t0 + 3272);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t5);
    t11 = (~(t10));
    t12 = *((unsigned int *)t4);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(195, ng0);

LAB55:    xsi_set_current_line(196, ng0);
    t2 = (t0 + 2952);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t27, 0, 8);
    t5 = (t27 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 13);
    *((unsigned int *)t27) = t11;
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 13);
    *((unsigned int *)t5) = t13;
    t14 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t14 & 63U);
    t17 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t17 & 63U);

LAB56:    t7 = ((char*)((ng21)));
    t24 = xsi_vlog_unsigned_case_compare(t27, 32, t7, 32);
    if (t24 == 1)
        goto LAB57;

LAB58:    t2 = ((char*)((ng22)));
    t24 = xsi_vlog_unsigned_case_compare(t27, 32, t2, 32);
    if (t24 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng23)));
    t24 = xsi_vlog_unsigned_case_compare(t27, 32, t2, 32);
    if (t24 == 1)
        goto LAB61;

LAB62:
LAB64:
LAB63:    xsi_set_current_line(200, ng0);
    t2 = (t0 + 2952);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t84, 0, 8);
    t5 = (t84 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 13);
    t12 = (t11 & 1);
    *((unsigned int *)t84) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 13);
    t17 = (t14 & 1);
    *((unsigned int *)t5) = t17;
    memset(t49, 0, 8);
    t7 = (t84 + 4);
    t18 = *((unsigned int *)t7);
    t19 = (~(t18));
    t20 = *((unsigned int *)t84);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB82;

LAB80:    if (*((unsigned int *)t7) == 0)
        goto LAB79;

LAB81:    t9 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t9) = 1;

LAB82:    t15 = (t49 + 4);
    t16 = (t84 + 4);
    t28 = *((unsigned int *)t84);
    t29 = (~(t28));
    *((unsigned int *)t49) = t29;
    *((unsigned int *)t15) = 0;
    if (*((unsigned int *)t16) != 0)
        goto LAB84;

LAB83:    t42 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t42 & 1U);
    t43 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t43 & 1U);
    memset(t32, 0, 8);
    t23 = (t49 + 4);
    t44 = *((unsigned int *)t23);
    t45 = (~(t44));
    t46 = *((unsigned int *)t49);
    t47 = (t46 & t45);
    t48 = (t47 & 1U);
    if (t48 != 0)
        goto LAB85;

LAB86:    if (*((unsigned int *)t23) != 0)
        goto LAB87;

LAB88:    t26 = (t32 + 4);
    t50 = *((unsigned int *)t32);
    t51 = *((unsigned int *)t26);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB89;

LAB90:    t62 = *((unsigned int *)t32);
    t65 = (~(t62));
    t66 = *((unsigned int *)t26);
    t67 = (t65 || t66);
    if (t67 > 0)
        goto LAB91;

LAB92:    if (*((unsigned int *)t26) > 0)
        goto LAB93;

LAB94:    if (*((unsigned int *)t32) > 0)
        goto LAB95;

LAB96:    memcpy(t31, t86, 8);

LAB97:    t54 = ((char*)((ng5)));
    xsi_vlogtype_concat(t30, 6, 6, 2U, t54, 2, t31, 4);
    t55 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t55, t30, 0, 0, 6, 0LL);

LAB65:    xsi_set_current_line(203, ng0);
    t2 = (t0 + 3112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2952);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t32, 0, 8);
    t9 = (t32 + 4);
    t15 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 11);
    *((unsigned int *)t32) = t11;
    t12 = *((unsigned int *)t15);
    t13 = (t12 >> 11);
    *((unsigned int *)t9) = t13;
    t14 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t14 & 3U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 3U);
    memset(t31, 0, 8);
    t16 = (t32 + 4);
    t18 = *((unsigned int *)t32);
    t19 = *((unsigned int *)t32);
    t19 = (t19 & 1);
    if (*((unsigned int *)t16) != 0)
        goto LAB98;

LAB99:    t20 = 1;

LAB101:    t21 = (t20 <= 1);
    if (t21 == 1)
        goto LAB102;

LAB103:    *((unsigned int *)t31) = t19;

LAB100:    t25 = (t0 + 2472);
    t26 = (t25 + 56U);
    t33 = *((char **)t26);
    memset(t49, 0, 8);
    t34 = (t33 + 4);
    t28 = *((unsigned int *)t34);
    t29 = (~(t28));
    t35 = *((unsigned int *)t33);
    t36 = (t35 & t29);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB108;

LAB106:    if (*((unsigned int *)t34) == 0)
        goto LAB105;

LAB107:    t38 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t38) = 1;

LAB108:    t39 = (t49 + 4);
    t40 = (t33 + 4);
    t41 = *((unsigned int *)t33);
    t42 = (~(t41));
    *((unsigned int *)t49) = t42;
    *((unsigned int *)t39) = 0;
    if (*((unsigned int *)t40) != 0)
        goto LAB110;

LAB109:    t47 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t47 & 1U);
    t48 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t48 & 1U);
    t50 = *((unsigned int *)t31);
    t51 = *((unsigned int *)t49);
    t52 = (t50 & t51);
    *((unsigned int *)t84) = t52;
    t53 = (t31 + 4);
    t54 = (t49 + 4);
    t55 = (t84 + 4);
    t56 = *((unsigned int *)t53);
    t57 = *((unsigned int *)t54);
    t58 = (t56 | t57);
    *((unsigned int *)t55) = t58;
    t59 = *((unsigned int *)t55);
    t60 = (t59 != 0);
    if (t60 == 1)
        goto LAB111;

LAB112:
LAB113:    xsi_vlogtype_concat(t30, 7, 7, 2U, t84, 1, t4, 6);
    t80 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t80, t30, 0, 0, 4, 0LL);
    t81 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t81, t30, 4, 0, 1, 0LL);
    t82 = (t0 + 2312);
    xsi_vlogvar_wait_assign_value(t82, t30, 5, 0, 1, 0LL);
    t83 = (t0 + 2632);
    xsi_vlogvar_wait_assign_value(t83, t30, 6, 0, 1, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(180, ng0);

LAB9:    xsi_set_current_line(181, ng0);
    t6 = (t0 + 2952);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    memset(t8, 0, 8);
    t15 = (t8 + 4);
    t16 = (t9 + 4);
    t17 = *((unsigned int *)t9);
    t18 = (t17 >> 19);
    *((unsigned int *)t8) = t18;
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 19);
    *((unsigned int *)t15) = t20;
    t21 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t21 & 63U);
    t22 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t22 & 63U);

LAB10:    t23 = ((char*)((ng4)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t23, 32);
    if (t24 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng7)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng9)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng11)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng13)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng14)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng16)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng17)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng19)));
    t24 = xsi_vlog_unsigned_case_compare(t8, 32, t2, 32);
    if (t24 == 1)
        goto LAB29;

LAB30:
LAB31:    xsi_set_current_line(194, ng0);
    t2 = (t0 + 3112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2952);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t31, 0, 8);
    t9 = (t31 + 4);
    t15 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 17);
    *((unsigned int *)t31) = t11;
    t12 = *((unsigned int *)t15);
    t13 = (t12 >> 17);
    *((unsigned int *)t9) = t13;
    t14 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t14 & 3U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 3U);
    memset(t30, 0, 8);
    t16 = (t31 + 4);
    t18 = *((unsigned int *)t31);
    t19 = *((unsigned int *)t31);
    t19 = (t19 & 1);
    if (*((unsigned int *)t16) != 0)
        goto LAB39;

LAB40:    t20 = 1;

LAB42:    t21 = (t20 <= 1);
    if (t21 == 1)
        goto LAB43;

LAB44:    *((unsigned int *)t30) = t19;

LAB41:    t25 = (t0 + 2472);
    t26 = (t25 + 56U);
    t33 = *((char **)t26);
    memset(t32, 0, 8);
    t34 = (t33 + 4);
    t28 = *((unsigned int *)t34);
    t29 = (~(t28));
    t35 = *((unsigned int *)t33);
    t36 = (t35 & t29);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB49;

LAB47:    if (*((unsigned int *)t34) == 0)
        goto LAB46;

LAB48:    t38 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t38) = 1;

LAB49:    t39 = (t32 + 4);
    t40 = (t33 + 4);
    t41 = *((unsigned int *)t33);
    t42 = (~(t41));
    *((unsigned int *)t32) = t42;
    *((unsigned int *)t39) = 0;
    if (*((unsigned int *)t40) != 0)
        goto LAB51;

LAB50:    t47 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t47 & 1U);
    t48 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t48 & 1U);
    t50 = *((unsigned int *)t30);
    t51 = *((unsigned int *)t32);
    t52 = (t50 & t51);
    *((unsigned int *)t49) = t52;
    t53 = (t30 + 4);
    t54 = (t32 + 4);
    t55 = (t49 + 4);
    t56 = *((unsigned int *)t53);
    t57 = *((unsigned int *)t54);
    t58 = (t56 | t57);
    *((unsigned int *)t55) = t58;
    t59 = *((unsigned int *)t55);
    t60 = (t59 != 0);
    if (t60 == 1)
        goto LAB52;

LAB53:
LAB54:    xsi_vlogtype_concat(t27, 7, 7, 2U, t49, 1, t4, 6);
    t80 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t80, t27, 0, 0, 4, 0LL);
    t81 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t81, t27, 4, 0, 1, 0LL);
    t82 = (t0 + 2312);
    xsi_vlogvar_wait_assign_value(t82, t27, 5, 0, 1, 0LL);
    t83 = (t0 + 2632);
    xsi_vlogvar_wait_assign_value(t83, t27, 6, 0, 1, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(182, ng0);
    t25 = ((char*)((ng5)));
    t26 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t26, t25, 0, 0, 6, 0LL);
    goto LAB31;

LAB13:    xsi_set_current_line(183, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB15:    xsi_set_current_line(184, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB17:    xsi_set_current_line(185, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB19:    xsi_set_current_line(186, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB21:    xsi_set_current_line(187, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB23:    xsi_set_current_line(188, ng0);
    t3 = ((char*)((ng15)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB25:    xsi_set_current_line(189, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB27:    xsi_set_current_line(190, ng0);
    t3 = ((char*)((ng18)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB31;

LAB29:    xsi_set_current_line(191, ng0);

LAB32:    xsi_set_current_line(191, ng0);
    t3 = (t0 + 3272);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t27, 0, 8);
    t6 = (t5 + 4);
    t10 = *((unsigned int *)t6);
    t11 = (~(t10));
    t12 = *((unsigned int *)t5);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB36;

LAB34:    if (*((unsigned int *)t6) == 0)
        goto LAB33;

LAB35:    t7 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t7) = 1;

LAB36:    t9 = (t27 + 4);
    t15 = (t5 + 4);
    t17 = *((unsigned int *)t5);
    t18 = (~(t17));
    *((unsigned int *)t27) = t18;
    *((unsigned int *)t9) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB38;

LAB37:    t28 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t28 & 1U);
    t29 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t29 & 1U);
    t16 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t16, t27, 0, 0, 1, 0LL);
    xsi_set_current_line(191, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 25, 0LL);
    goto LAB31;

LAB33:    *((unsigned int *)t27) = 1;
    goto LAB36;

LAB38:    t19 = *((unsigned int *)t27);
    t20 = *((unsigned int *)t15);
    *((unsigned int *)t27) = (t19 | t20);
    t21 = *((unsigned int *)t9);
    t22 = *((unsigned int *)t15);
    *((unsigned int *)t9) = (t21 | t22);
    goto LAB37;

LAB39:    t23 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB41;

LAB43:    t18 = (t18 >> 1);
    t22 = (t18 & 1);
    t19 = (t19 ^ t22);

LAB45:    t20 = (t20 + 1);
    goto LAB42;

LAB46:    *((unsigned int *)t32) = 1;
    goto LAB49;

LAB51:    t43 = *((unsigned int *)t32);
    t44 = *((unsigned int *)t40);
    *((unsigned int *)t32) = (t43 | t44);
    t45 = *((unsigned int *)t39);
    t46 = *((unsigned int *)t40);
    *((unsigned int *)t39) = (t45 | t46);
    goto LAB50;

LAB52:    t61 = *((unsigned int *)t49);
    t62 = *((unsigned int *)t55);
    *((unsigned int *)t49) = (t61 | t62);
    t63 = (t30 + 4);
    t64 = (t32 + 4);
    t65 = *((unsigned int *)t30);
    t66 = (~(t65));
    t67 = *((unsigned int *)t63);
    t68 = (~(t67));
    t69 = *((unsigned int *)t32);
    t70 = (~(t69));
    t71 = *((unsigned int *)t64);
    t72 = (~(t71));
    t24 = (t66 & t68);
    t73 = (t70 & t72);
    t74 = (~(t24));
    t75 = (~(t73));
    t76 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t76 & t74);
    t77 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t77 & t75);
    t78 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t78 & t74);
    t79 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t79 & t75);
    goto LAB54;

LAB57:    xsi_set_current_line(197, ng0);
    t9 = ((char*)((ng10)));
    t15 = (t0 + 3432);
    t16 = (t15 + 56U);
    t23 = *((char **)t16);
    memset(t31, 0, 8);
    t25 = (t23 + 4);
    t18 = *((unsigned int *)t25);
    t19 = (~(t18));
    t20 = *((unsigned int *)t23);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB69;

LAB67:    if (*((unsigned int *)t25) == 0)
        goto LAB66;

LAB68:    t26 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t26) = 1;

LAB69:    t33 = (t31 + 4);
    t34 = (t23 + 4);
    t28 = *((unsigned int *)t23);
    t29 = (~(t28));
    *((unsigned int *)t31) = t29;
    *((unsigned int *)t33) = 0;
    if (*((unsigned int *)t34) != 0)
        goto LAB71;

LAB70:    t42 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t42 & 1U);
    t43 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t43 & 1U);
    t38 = ((char*)((ng15)));
    xsi_vlogtype_concat(t30, 6, 6, 3U, t38, 3, t31, 1, t9, 2);
    t39 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t39, t30, 0, 0, 6, 0LL);
    goto LAB65;

LAB59:    xsi_set_current_line(198, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 6, 0LL);
    goto LAB65;

LAB61:    xsi_set_current_line(199, ng0);

LAB72:    xsi_set_current_line(199, ng0);
    t3 = ((char*)((ng20)));
    t4 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 25, 0LL);
    xsi_set_current_line(199, ng0);
    t2 = (t0 + 3432);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t30, 0, 8);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t5);
    t11 = (~(t10));
    t12 = *((unsigned int *)t4);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB76;

LAB74:    if (*((unsigned int *)t5) == 0)
        goto LAB73;

LAB75:    t6 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t6) = 1;

LAB76:    t7 = (t30 + 4);
    t9 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = (~(t17));
    *((unsigned int *)t30) = t18;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t9) != 0)
        goto LAB78;

LAB77:    t28 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t28 & 1U);
    t29 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t29 & 1U);
    t15 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t15, t30, 0, 0, 1, 0LL);
    goto LAB65;

LAB66:    *((unsigned int *)t31) = 1;
    goto LAB69;

LAB71:    t35 = *((unsigned int *)t31);
    t36 = *((unsigned int *)t34);
    *((unsigned int *)t31) = (t35 | t36);
    t37 = *((unsigned int *)t33);
    t41 = *((unsigned int *)t34);
    *((unsigned int *)t33) = (t37 | t41);
    goto LAB70;

LAB73:    *((unsigned int *)t30) = 1;
    goto LAB76;

LAB78:    t19 = *((unsigned int *)t30);
    t20 = *((unsigned int *)t9);
    *((unsigned int *)t30) = (t19 | t20);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    *((unsigned int *)t7) = (t21 | t22);
    goto LAB77;

LAB79:    *((unsigned int *)t49) = 1;
    goto LAB82;

LAB84:    t35 = *((unsigned int *)t49);
    t36 = *((unsigned int *)t16);
    *((unsigned int *)t49) = (t35 | t36);
    t37 = *((unsigned int *)t15);
    t41 = *((unsigned int *)t16);
    *((unsigned int *)t15) = (t37 | t41);
    goto LAB83;

LAB85:    *((unsigned int *)t32) = 1;
    goto LAB88;

LAB87:    t25 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB88;

LAB89:    t33 = (t0 + 1912U);
    t34 = *((char **)t33);
    memset(t85, 0, 8);
    t33 = (t85 + 4);
    t38 = (t34 + 4);
    t56 = *((unsigned int *)t34);
    t57 = (t56 >> 4);
    *((unsigned int *)t85) = t57;
    t58 = *((unsigned int *)t38);
    t59 = (t58 >> 4);
    *((unsigned int *)t33) = t59;
    t60 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t60 & 15U);
    t61 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t61 & 15U);
    goto LAB90;

LAB91:    t39 = (t0 + 1912U);
    t40 = *((char **)t39);
    memset(t86, 0, 8);
    t39 = (t86 + 4);
    t53 = (t40 + 4);
    t68 = *((unsigned int *)t40);
    t69 = (t68 >> 0);
    *((unsigned int *)t86) = t69;
    t70 = *((unsigned int *)t53);
    t71 = (t70 >> 0);
    *((unsigned int *)t39) = t71;
    t72 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t72 & 15U);
    t74 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t74 & 15U);
    goto LAB92;

LAB93:    xsi_vlog_unsigned_bit_combine(t31, 4, t85, 4, t86, 4);
    goto LAB97;

LAB95:    memcpy(t31, t85, 8);
    goto LAB97;

LAB98:    t23 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB100;

LAB102:    t18 = (t18 >> 1);
    t22 = (t18 & 1);
    t19 = (t19 ^ t22);

LAB104:    t20 = (t20 + 1);
    goto LAB101;

LAB105:    *((unsigned int *)t49) = 1;
    goto LAB108;

LAB110:    t43 = *((unsigned int *)t49);
    t44 = *((unsigned int *)t40);
    *((unsigned int *)t49) = (t43 | t44);
    t45 = *((unsigned int *)t39);
    t46 = *((unsigned int *)t40);
    *((unsigned int *)t39) = (t45 | t46);
    goto LAB109;

LAB111:    t61 = *((unsigned int *)t84);
    t62 = *((unsigned int *)t55);
    *((unsigned int *)t84) = (t61 | t62);
    t63 = (t31 + 4);
    t64 = (t49 + 4);
    t65 = *((unsigned int *)t31);
    t66 = (~(t65));
    t67 = *((unsigned int *)t63);
    t68 = (~(t67));
    t69 = *((unsigned int *)t49);
    t70 = (~(t69));
    t71 = *((unsigned int *)t64);
    t72 = (~(t71));
    t24 = (t66 & t68);
    t73 = (t70 & t72);
    t74 = (~(t24));
    t75 = (~(t73));
    t76 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t76 & t74);
    t77 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t77 & t75);
    t78 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t78 & t74);
    t79 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t79 & t75);
    goto LAB113;

}


extern void work_m_00000000000123751090_1199837496_init()
{
	static char *pe[] = {(void *)Cont_174_0,(void *)Initial_176_1,(void *)Always_178_2};
	xsi_register_didat("work_m_00000000000123751090_1199837496", "isim/t_KB_isim_beh.exe.sim/work/m_00000000000123751090_1199837496.didat");
	xsi_register_executes(pe);
}
