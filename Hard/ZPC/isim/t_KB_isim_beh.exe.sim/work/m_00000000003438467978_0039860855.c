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
static const char *ng0 = "F:/Workspace/ASM/Hard/DISK/Disk.v";
static unsigned int ng1[] = {0U, 4294967295U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {512U, 0U};
static int ng6[] = {1, 0};
static unsigned int ng7[] = {514U, 0U};
static unsigned int ng8[] = {513U, 0U};
static int ng9[] = {2, 0};
static unsigned int ng10[] = {753U, 0U};
static unsigned int ng11[] = {754U, 0U};
static unsigned int ng12[] = {755U, 0U};



static void Cont_50_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t19[8];
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
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    t1 = (t0 + 6048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1688U);
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

LAB9:    t20 = *((unsigned int *)t4);
    t21 = (~(t20));
    t22 = *((unsigned int *)t12);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t24, 8);

LAB16:    t25 = (t0 + 6712);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t3, 8);
    xsi_driver_vfirst_trans(t25, 0, 31);
    t30 = (t0 + 6616);
    *((int *)t30) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 3688);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t19, t18, 8);
    goto LAB9;

LAB10:    t24 = ((char*)((ng1)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t19, 32, t24, 32);
    goto LAB16;

LAB14:    memcpy(t3, t19, 8);
    goto LAB16;

}

static void Always_79_1(char *t0)
{
    char t16[8];
    char t18[8];
    char t52[8];
    char t62[8];
    char t70[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t17;
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
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    int t48;
    int t49;
    char *t50;
    char *t51;
    char *t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    char *t106;
    char *t107;

LAB0:    t1 = (t0 + 6296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 6632);
    *((int *)t2) = 1;
    t3 = (t0 + 6328);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(79, ng0);

LAB5:    xsi_set_current_line(80, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 4488);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 10, t5, 10);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 10, t2, 10);
    if (t6 == 1)
        goto LAB9;

LAB10:
LAB12:
LAB11:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 2328U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB18;

LAB19:
LAB20:
LAB13:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 2328U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1688U);
    t5 = *((char **)t2);
    t2 = (t5 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB45;

LAB46:
LAB47:
LAB28:
LAB24:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 3208);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);

LAB67:    t14 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t8, 10, t14, 10);
    if (t6 == 1)
        goto LAB68;

LAB69:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t8, 10, t2, 10);
    if (t6 == 1)
        goto LAB70;

LAB71:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t8, 10, t2, 10);
    if (t6 == 1)
        goto LAB72;

LAB73:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t8, 10, t2, 10);
    if (t6 == 1)
        goto LAB74;

LAB75:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t8, 10, t2, 10);
    if (t6 == 1)
        goto LAB76;

LAB77:
LAB79:
LAB78:    xsi_set_current_line(188, ng0);

LAB231:    xsi_set_current_line(189, ng0);
    t2 = (t0 + 3208);
    t7 = (t2 + 56U);
    t14 = *((char **)t7);
    t15 = ((char*)((ng6)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_minus(t16, 32, t14, 10, t15, 32);
    t24 = (t0 + 4648);
    xsi_vlogvar_assign_value(t24, t16, 0, 0, 9);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 2168U);
    t7 = *((char **)t2);
    memset(t16, 0, 8);
    t2 = (t7 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB235;

LAB233:    if (*((unsigned int *)t2) == 0)
        goto LAB232;

LAB234:    t14 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t14) = 1;

LAB235:    t15 = (t16 + 4);
    t24 = (t7 + 4);
    t17 = *((unsigned int *)t7);
    t19 = (~(t17));
    *((unsigned int *)t16) = t19;
    *((unsigned int *)t15) = 0;
    if (*((unsigned int *)t24) != 0)
        goto LAB237;

LAB236:    t25 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t25 & 1U);
    t26 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t26 & 1U);
    memset(t18, 0, 8);
    t37 = (t16 + 4);
    t27 = *((unsigned int *)t37);
    t28 = (~(t27));
    t29 = *((unsigned int *)t16);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB238;

LAB239:    if (*((unsigned int *)t37) != 0)
        goto LAB240;

LAB241:    t44 = (t18 + 4);
    t32 = *((unsigned int *)t18);
    t33 = *((unsigned int *)t44);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB242;

LAB243:    memcpy(t70, t18, 8);

LAB244:    t85 = (t70 + 4);
    t101 = *((unsigned int *)t85);
    t102 = (~(t101));
    t103 = *((unsigned int *)t70);
    t104 = (t103 & t102);
    t105 = (t104 != 0);
    if (t105 > 0)
        goto LAB258;

LAB259:    xsi_set_current_line(196, ng0);

LAB262:    xsi_set_current_line(197, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(198, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);

LAB260:
LAB80:    goto LAB2;

LAB7:    xsi_set_current_line(83, ng0);
    t7 = (t0 + 2328U);
    t8 = *((char **)t7);
    t7 = (t8 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t8);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB14;

LAB15:
LAB16:    goto LAB13;

LAB9:    xsi_set_current_line(84, ng0);

LAB17:    xsi_set_current_line(85, ng0);
    t3 = ((char*)((ng2)));
    t5 = (t0 + 4968);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    goto LAB13;

LAB14:    xsi_set_current_line(83, ng0);
    t14 = ((char*)((ng4)));
    t15 = (t0 + 3048);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 10);
    goto LAB16;

LAB18:    xsi_set_current_line(88, ng0);

LAB21:    xsi_set_current_line(89, ng0);
    t5 = (t0 + 3048);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t14 = ((char*)((ng6)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t8, 10, t14, 32);
    t15 = (t0 + 3048);
    xsi_vlogvar_assign_value(t15, t16, 0, 0, 10);
    goto LAB20;

LAB22:    xsi_set_current_line(93, ng0);

LAB25:    xsi_set_current_line(95, ng0);
    t5 = ((char*)((ng6)));
    t7 = (t0 + 4968);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 1);
    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 4488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t16, 0, 8);
    t7 = (t16 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t16) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t13 & 511U);
    t17 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t17 & 511U);
    t14 = ((char*)((ng6)));
    memset(t18, 0, 8);
    xsi_vlog_unsigned_minus(t18, 32, t16, 32, t14, 32);
    t15 = (t0 + 4648);
    xsi_vlogvar_assign_value(t15, t18, 0, 0, 9);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 2488U);
    t3 = *((char **)t2);
    t2 = (t0 + 4808);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    goto LAB24;

LAB26:    xsi_set_current_line(100, ng0);

LAB29:    xsi_set_current_line(101, ng0);
    t5 = (t0 + 2008U);
    t7 = *((char **)t5);
    memset(t16, 0, 8);
    t5 = (t16 + 4);
    t8 = (t7 + 4);
    t17 = *((unsigned int *)t7);
    t19 = (t17 >> 9);
    t20 = (t19 & 1);
    *((unsigned int *)t16) = t20;
    t21 = *((unsigned int *)t8);
    t22 = (t21 >> 9);
    t23 = (t22 & 1);
    *((unsigned int *)t5) = t23;
    t14 = ((char*)((ng3)));
    memset(t18, 0, 8);
    t15 = (t16 + 4);
    t24 = (t14 + 4);
    t25 = *((unsigned int *)t16);
    t26 = *((unsigned int *)t14);
    t27 = (t25 ^ t26);
    t28 = *((unsigned int *)t15);
    t29 = *((unsigned int *)t24);
    t30 = (t28 ^ t29);
    t31 = (t27 | t30);
    t32 = *((unsigned int *)t15);
    t33 = *((unsigned int *)t24);
    t34 = (t32 | t33);
    t35 = (~(t34));
    t36 = (t31 & t35);
    if (t36 != 0)
        goto LAB33;

LAB30:    if (t34 != 0)
        goto LAB32;

LAB31:    *((unsigned int *)t18) = 1;

LAB33:    t38 = (t18 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t18);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(106, ng0);

LAB38:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);

LAB39:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 10, t2, 10);
    if (t6 == 1)
        goto LAB40;

LAB41:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 10, t2, 10);
    if (t6 == 1)
        goto LAB42;

LAB43:
LAB44:
LAB36:    goto LAB28;

LAB32:    t37 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB33;

LAB34:    xsi_set_current_line(101, ng0);

LAB37:    xsi_set_current_line(102, ng0);
    t44 = (t0 + 2008U);
    t45 = *((char **)t44);
    t44 = (t0 + 4648);
    xsi_vlogvar_assign_value(t44, t45, 0, 0, 9);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t16, 0, 8);
    t2 = (t16 + 4);
    t5 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t16) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t13 & 255U);
    t17 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t17 & 255U);
    t7 = (t0 + 4808);
    xsi_vlogvar_assign_value(t7, t16, 0, 0, 8);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 4488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB36;

LAB40:    xsi_set_current_line(108, ng0);
    t5 = (t0 + 1528U);
    t7 = *((char **)t5);
    memset(t16, 0, 8);
    t5 = (t16 + 4);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    *((unsigned int *)t16) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t5) = t12;
    t13 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t13 & 65535U);
    t17 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t17 & 65535U);
    t14 = (t0 + 4328);
    xsi_vlogvar_assign_value(t14, t16, 0, 0, 16);
    goto LAB44;

LAB42:    xsi_set_current_line(109, ng0);
    t5 = ((char*)((ng6)));
    t7 = (t0 + 3368);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 2);
    goto LAB44;

LAB45:    xsi_set_current_line(113, ng0);

LAB48:    xsi_set_current_line(114, ng0);
    t7 = (t0 + 2008U);
    t8 = *((char **)t7);
    memset(t16, 0, 8);
    t7 = (t16 + 4);
    t14 = (t8 + 4);
    t17 = *((unsigned int *)t8);
    t19 = (t17 >> 9);
    t20 = (t19 & 1);
    *((unsigned int *)t16) = t20;
    t21 = *((unsigned int *)t14);
    t22 = (t21 >> 9);
    t23 = (t22 & 1);
    *((unsigned int *)t7) = t23;
    t15 = ((char*)((ng3)));
    memset(t18, 0, 8);
    t24 = (t16 + 4);
    t37 = (t15 + 4);
    t25 = *((unsigned int *)t16);
    t26 = *((unsigned int *)t15);
    t27 = (t25 ^ t26);
    t28 = *((unsigned int *)t24);
    t29 = *((unsigned int *)t37);
    t30 = (t28 ^ t29);
    t31 = (t27 | t30);
    t32 = *((unsigned int *)t24);
    t33 = *((unsigned int *)t37);
    t34 = (t32 | t33);
    t35 = (~(t34));
    t36 = (t31 & t35);
    if (t36 != 0)
        goto LAB52;

LAB49:    if (t34 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t18) = 1;

LAB52:    t44 = (t18 + 4);
    t39 = *((unsigned int *)t44);
    t40 = (~(t39));
    t41 = *((unsigned int *)t18);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(118, ng0);

LAB57:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 2008U);
    t5 = *((char **)t2);

LAB58:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 10, t2, 10);
    if (t6 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 10, t2, 10);
    if (t6 == 1)
        goto LAB61;

LAB62:
LAB63:
LAB55:    goto LAB47;

LAB51:    t38 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB52;

LAB53:    xsi_set_current_line(114, ng0);

LAB56:    xsi_set_current_line(115, ng0);
    t45 = (t0 + 2008U);
    t46 = *((char **)t45);
    t45 = (t0 + 4648);
    xsi_vlogvar_assign_value(t45, t46, 0, 0, 9);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 2648U);
    t5 = *((char **)t2);
    memcpy(t16, t5, 8);
    t2 = (t0 + 3688);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    goto LAB55;

LAB59:    xsi_set_current_line(120, ng0);
    t7 = (t0 + 5128);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = (t0 + 4968);
    t24 = (t15 + 56U);
    t37 = *((char **)t24);
    t9 = *((unsigned int *)t14);
    t10 = *((unsigned int *)t37);
    t11 = (t9 | t10);
    *((unsigned int *)t18) = t11;
    t38 = (t14 + 4);
    t44 = (t37 + 4);
    t45 = (t18 + 4);
    t12 = *((unsigned int *)t38);
    t13 = *((unsigned int *)t44);
    t17 = (t12 | t13);
    *((unsigned int *)t45) = t17;
    t19 = *((unsigned int *)t45);
    t20 = (t19 != 0);
    if (t20 == 1)
        goto LAB64;

LAB65:
LAB66:    t50 = ((char*)((ng3)));
    xsi_vlogtype_concat(t16, 16, 16, 2U, t50, 15, t18, 1);
    t51 = (t0 + 3688);
    xsi_vlogvar_assign_value(t51, t16, 0, 0, 16);
    goto LAB63;

LAB61:    xsi_set_current_line(121, ng0);
    t7 = ((char*)((ng9)));
    t8 = (t0 + 3368);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 2);
    goto LAB63;

LAB64:    t21 = *((unsigned int *)t18);
    t22 = *((unsigned int *)t45);
    *((unsigned int *)t18) = (t21 | t22);
    t46 = (t14 + 4);
    t47 = (t37 + 4);
    t23 = *((unsigned int *)t46);
    t25 = (~(t23));
    t26 = *((unsigned int *)t14);
    t48 = (t26 & t25);
    t27 = *((unsigned int *)t47);
    t28 = (~(t27));
    t29 = *((unsigned int *)t37);
    t49 = (t29 & t28);
    t30 = (~(t48));
    t31 = (~(t49));
    t32 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t32 & t30);
    t33 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t33 & t31);
    goto LAB66;

LAB68:    xsi_set_current_line(126, ng0);
    t15 = (t0 + 3368);
    t24 = (t15 + 56U);
    t37 = *((char **)t24);
    t38 = ((char*)((ng2)));
    memset(t16, 0, 8);
    t44 = (t37 + 4);
    t45 = (t38 + 4);
    t9 = *((unsigned int *)t37);
    t10 = *((unsigned int *)t38);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t44);
    t13 = *((unsigned int *)t45);
    t17 = (t12 ^ t13);
    t19 = (t11 | t17);
    t20 = *((unsigned int *)t44);
    t21 = *((unsigned int *)t45);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t25 = (t19 & t23);
    if (t25 != 0)
        goto LAB82;

LAB81:    if (t22 != 0)
        goto LAB83;

LAB84:    t47 = (t16 + 4);
    t26 = *((unsigned int *)t47);
    t27 = (~(t26));
    t28 = *((unsigned int *)t16);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB85;

LAB86:    xsi_set_current_line(133, ng0);

LAB89:    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 5128);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(135, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);

LAB87:    goto LAB80;

LAB70:    xsi_set_current_line(137, ng0);

LAB90:    xsi_set_current_line(138, ng0);
    t7 = (t0 + 2168U);
    t14 = *((char **)t7);
    memset(t16, 0, 8);
    t7 = (t14 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t14);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB94;

LAB92:    if (*((unsigned int *)t7) == 0)
        goto LAB91;

LAB93:    t15 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t15) = 1;

LAB94:    t24 = (t16 + 4);
    t37 = (t14 + 4);
    t17 = *((unsigned int *)t14);
    t19 = (~(t17));
    *((unsigned int *)t16) = t19;
    *((unsigned int *)t24) = 0;
    if (*((unsigned int *)t37) != 0)
        goto LAB96;

LAB95:    t25 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t25 & 1U);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 & 1U);
    memset(t18, 0, 8);
    t38 = (t16 + 4);
    t27 = *((unsigned int *)t38);
    t28 = (~(t27));
    t29 = *((unsigned int *)t16);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB97;

LAB98:    if (*((unsigned int *)t38) != 0)
        goto LAB99;

LAB100:    t45 = (t18 + 4);
    t32 = *((unsigned int *)t18);
    t33 = *((unsigned int *)t45);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB101;

LAB102:    memcpy(t70, t18, 8);

LAB103:    t100 = (t70 + 4);
    t101 = *((unsigned int *)t100);
    t102 = (~(t101));
    t103 = *((unsigned int *)t70);
    t104 = (t103 & t102);
    t105 = (t104 != 0);
    if (t105 > 0)
        goto LAB117;

LAB118:    xsi_set_current_line(144, ng0);

LAB121:    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(146, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);

LAB119:    goto LAB80;

LAB72:    xsi_set_current_line(149, ng0);

LAB122:    xsi_set_current_line(150, ng0);
    t7 = (t0 + 2168U);
    t14 = *((char **)t7);
    memset(t16, 0, 8);
    t7 = (t14 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t14);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB126;

LAB124:    if (*((unsigned int *)t7) == 0)
        goto LAB123;

LAB125:    t15 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t15) = 1;

LAB126:    t24 = (t16 + 4);
    t37 = (t14 + 4);
    t17 = *((unsigned int *)t14);
    t19 = (~(t17));
    *((unsigned int *)t16) = t19;
    *((unsigned int *)t24) = 0;
    if (*((unsigned int *)t37) != 0)
        goto LAB128;

LAB127:    t25 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t25 & 1U);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 & 1U);
    memset(t18, 0, 8);
    t38 = (t16 + 4);
    t27 = *((unsigned int *)t38);
    t28 = (~(t27));
    t29 = *((unsigned int *)t16);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB129;

LAB130:    if (*((unsigned int *)t38) != 0)
        goto LAB131;

LAB132:    t45 = (t18 + 4);
    t32 = *((unsigned int *)t18);
    t33 = *((unsigned int *)t45);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB133;

LAB134:    memcpy(t70, t18, 8);

LAB135:    t100 = (t70 + 4);
    t101 = *((unsigned int *)t100);
    t102 = (~(t101));
    t103 = *((unsigned int *)t70);
    t104 = (t103 & t102);
    t105 = (t104 != 0);
    if (t105 > 0)
        goto LAB149;

LAB150:    xsi_set_current_line(157, ng0);

LAB166:    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);

LAB151:    goto LAB80;

LAB74:    xsi_set_current_line(162, ng0);

LAB167:    xsi_set_current_line(163, ng0);
    t7 = (t0 + 2168U);
    t14 = *((char **)t7);
    memset(t16, 0, 8);
    t7 = (t14 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t14);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB171;

LAB169:    if (*((unsigned int *)t7) == 0)
        goto LAB168;

LAB170:    t15 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t15) = 1;

LAB171:    t24 = (t16 + 4);
    t37 = (t14 + 4);
    t17 = *((unsigned int *)t14);
    t19 = (~(t17));
    *((unsigned int *)t16) = t19;
    *((unsigned int *)t24) = 0;
    if (*((unsigned int *)t37) != 0)
        goto LAB173;

LAB172:    t25 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t25 & 1U);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 & 1U);
    memset(t18, 0, 8);
    t38 = (t16 + 4);
    t27 = *((unsigned int *)t38);
    t28 = (~(t27));
    t29 = *((unsigned int *)t16);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB174;

LAB175:    if (*((unsigned int *)t38) != 0)
        goto LAB176;

LAB177:    t45 = (t18 + 4);
    t32 = *((unsigned int *)t18);
    t33 = *((unsigned int *)t45);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB178;

LAB179:    memcpy(t70, t18, 8);

LAB180:    t100 = (t70 + 4);
    t101 = *((unsigned int *)t100);
    t102 = (~(t101));
    t103 = *((unsigned int *)t70);
    t104 = (t103 & t102);
    t105 = (t104 != 0);
    if (t105 > 0)
        goto LAB194;

LAB195:    xsi_set_current_line(169, ng0);

LAB198:    xsi_set_current_line(170, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(171, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);

LAB196:    goto LAB80;

LAB76:    xsi_set_current_line(174, ng0);

LAB199:    xsi_set_current_line(175, ng0);
    t7 = (t0 + 3208);
    t14 = (t7 + 56U);
    t15 = *((char **)t14);
    t24 = ((char*)((ng6)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_minus(t16, 32, t15, 10, t24, 32);
    t37 = (t0 + 4648);
    xsi_vlogvar_assign_value(t37, t16, 0, 0, 9);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 2168U);
    t7 = *((char **)t2);
    memset(t16, 0, 8);
    t2 = (t7 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB203;

LAB201:    if (*((unsigned int *)t2) == 0)
        goto LAB200;

LAB202:    t14 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t14) = 1;

LAB203:    t15 = (t16 + 4);
    t24 = (t7 + 4);
    t17 = *((unsigned int *)t7);
    t19 = (~(t17));
    *((unsigned int *)t16) = t19;
    *((unsigned int *)t15) = 0;
    if (*((unsigned int *)t24) != 0)
        goto LAB205;

LAB204:    t25 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t25 & 1U);
    t26 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t26 & 1U);
    memset(t18, 0, 8);
    t37 = (t16 + 4);
    t27 = *((unsigned int *)t37);
    t28 = (~(t27));
    t29 = *((unsigned int *)t16);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB206;

LAB207:    if (*((unsigned int *)t37) != 0)
        goto LAB208;

LAB209:    t44 = (t18 + 4);
    t32 = *((unsigned int *)t18);
    t33 = *((unsigned int *)t44);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB210;

LAB211:    memcpy(t70, t18, 8);

LAB212:    t85 = (t70 + 4);
    t101 = *((unsigned int *)t85);
    t102 = (~(t101));
    t103 = *((unsigned int *)t70);
    t104 = (t103 & t102);
    t105 = (t104 != 0);
    if (t105 > 0)
        goto LAB226;

LAB227:    xsi_set_current_line(183, ng0);

LAB230:    xsi_set_current_line(184, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(185, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);

LAB228:    goto LAB80;

LAB82:    *((unsigned int *)t16) = 1;
    goto LAB84;

LAB83:    t46 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t46) = 1;
    goto LAB84;

LAB85:    xsi_set_current_line(126, ng0);

LAB88:    xsi_set_current_line(127, ng0);
    t50 = ((char*)((ng6)));
    t51 = (t0 + 5128);
    xsi_vlogvar_assign_value(t51, t50, 0, 0, 1);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 3368);
    t7 = (t2 + 56U);
    t14 = *((char **)t7);
    memcpy(t16, t14, 8);
    t15 = (t0 + 3848);
    xsi_vlogvar_assign_value(t15, t16, 0, 0, 8);
    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng10)));
    t7 = (t0 + 3208);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 10);
    xsi_set_current_line(130, ng0);
    t2 = ((char*)((ng6)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng6)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    goto LAB87;

LAB91:    *((unsigned int *)t16) = 1;
    goto LAB94;

LAB96:    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t37);
    *((unsigned int *)t16) = (t20 | t21);
    t22 = *((unsigned int *)t24);
    t23 = *((unsigned int *)t37);
    *((unsigned int *)t24) = (t22 | t23);
    goto LAB95;

LAB97:    *((unsigned int *)t18) = 1;
    goto LAB100;

LAB99:    t44 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB100;

LAB101:    t46 = (t0 + 4008);
    t47 = (t46 + 56U);
    t50 = *((char **)t47);
    memset(t52, 0, 8);
    t51 = (t50 + 4);
    t35 = *((unsigned int *)t51);
    t36 = (~(t35));
    t39 = *((unsigned int *)t50);
    t40 = (t39 & t36);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB107;

LAB105:    if (*((unsigned int *)t51) == 0)
        goto LAB104;

LAB106:    t53 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t53) = 1;

LAB107:    t54 = (t52 + 4);
    t55 = (t50 + 4);
    t42 = *((unsigned int *)t50);
    t43 = (~(t42));
    *((unsigned int *)t52) = t43;
    *((unsigned int *)t54) = 0;
    if (*((unsigned int *)t55) != 0)
        goto LAB109;

LAB108:    t60 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t60 & 1U);
    t61 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t61 & 1U);
    memset(t62, 0, 8);
    t63 = (t52 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t52);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB110;

LAB111:    if (*((unsigned int *)t63) != 0)
        goto LAB112;

LAB113:    t71 = *((unsigned int *)t18);
    t72 = *((unsigned int *)t62);
    t73 = (t71 & t72);
    *((unsigned int *)t70) = t73;
    t74 = (t18 + 4);
    t75 = (t62 + 4);
    t76 = (t70 + 4);
    t77 = *((unsigned int *)t74);
    t78 = *((unsigned int *)t75);
    t79 = (t77 | t78);
    *((unsigned int *)t76) = t79;
    t80 = *((unsigned int *)t76);
    t81 = (t80 != 0);
    if (t81 == 1)
        goto LAB114;

LAB115:
LAB116:    goto LAB103;

LAB104:    *((unsigned int *)t52) = 1;
    goto LAB107;

LAB109:    t56 = *((unsigned int *)t52);
    t57 = *((unsigned int *)t55);
    *((unsigned int *)t52) = (t56 | t57);
    t58 = *((unsigned int *)t54);
    t59 = *((unsigned int *)t55);
    *((unsigned int *)t54) = (t58 | t59);
    goto LAB108;

LAB110:    *((unsigned int *)t62) = 1;
    goto LAB113;

LAB112:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB113;

LAB114:    t82 = *((unsigned int *)t70);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t70) = (t82 | t83);
    t84 = (t18 + 4);
    t85 = (t62 + 4);
    t86 = *((unsigned int *)t18);
    t87 = (~(t86));
    t88 = *((unsigned int *)t84);
    t89 = (~(t88));
    t90 = *((unsigned int *)t62);
    t91 = (~(t90));
    t92 = *((unsigned int *)t85);
    t93 = (~(t92));
    t48 = (t87 & t89);
    t49 = (t91 & t93);
    t94 = (~(t48));
    t95 = (~(t49));
    t96 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t96 & t94);
    t97 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t97 & t95);
    t98 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t98 & t94);
    t99 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t99 & t95);
    goto LAB116;

LAB117:    xsi_set_current_line(138, ng0);

LAB120:    xsi_set_current_line(139, ng0);
    t106 = ((char*)((ng6)));
    t107 = (t0 + 3528);
    xsi_vlogvar_assign_value(t107, t106, 0, 0, 1);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 4328);
    t7 = (t2 + 56U);
    t14 = *((char **)t7);
    memset(t16, 0, 8);
    t15 = (t16 + 4);
    t24 = (t14 + 4);
    t9 = *((unsigned int *)t14);
    t10 = (t9 >> 0);
    *((unsigned int *)t16) = t10;
    t11 = *((unsigned int *)t24);
    t12 = (t11 >> 0);
    *((unsigned int *)t15) = t12;
    t13 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t13 & 255U);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 & 255U);
    t37 = (t0 + 3848);
    xsi_vlogvar_assign_value(t37, t16, 0, 0, 8);
    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng11)));
    t7 = (t0 + 3208);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 10);
    xsi_set_current_line(142, ng0);
    t2 = ((char*)((ng6)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    goto LAB119;

LAB123:    *((unsigned int *)t16) = 1;
    goto LAB126;

LAB128:    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t37);
    *((unsigned int *)t16) = (t20 | t21);
    t22 = *((unsigned int *)t24);
    t23 = *((unsigned int *)t37);
    *((unsigned int *)t24) = (t22 | t23);
    goto LAB127;

LAB129:    *((unsigned int *)t18) = 1;
    goto LAB132;

LAB131:    t44 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB132;

LAB133:    t46 = (t0 + 4008);
    t47 = (t46 + 56U);
    t50 = *((char **)t47);
    memset(t52, 0, 8);
    t51 = (t50 + 4);
    t35 = *((unsigned int *)t51);
    t36 = (~(t35));
    t39 = *((unsigned int *)t50);
    t40 = (t39 & t36);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB139;

LAB137:    if (*((unsigned int *)t51) == 0)
        goto LAB136;

LAB138:    t53 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t53) = 1;

LAB139:    t54 = (t52 + 4);
    t55 = (t50 + 4);
    t42 = *((unsigned int *)t50);
    t43 = (~(t42));
    *((unsigned int *)t52) = t43;
    *((unsigned int *)t54) = 0;
    if (*((unsigned int *)t55) != 0)
        goto LAB141;

LAB140:    t60 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t60 & 1U);
    t61 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t61 & 1U);
    memset(t62, 0, 8);
    t63 = (t52 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t52);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB142;

LAB143:    if (*((unsigned int *)t63) != 0)
        goto LAB144;

LAB145:    t71 = *((unsigned int *)t18);
    t72 = *((unsigned int *)t62);
    t73 = (t71 & t72);
    *((unsigned int *)t70) = t73;
    t74 = (t18 + 4);
    t75 = (t62 + 4);
    t76 = (t70 + 4);
    t77 = *((unsigned int *)t74);
    t78 = *((unsigned int *)t75);
    t79 = (t77 | t78);
    *((unsigned int *)t76) = t79;
    t80 = *((unsigned int *)t76);
    t81 = (t80 != 0);
    if (t81 == 1)
        goto LAB146;

LAB147:
LAB148:    goto LAB135;

LAB136:    *((unsigned int *)t52) = 1;
    goto LAB139;

LAB141:    t56 = *((unsigned int *)t52);
    t57 = *((unsigned int *)t55);
    *((unsigned int *)t52) = (t56 | t57);
    t58 = *((unsigned int *)t54);
    t59 = *((unsigned int *)t55);
    *((unsigned int *)t54) = (t58 | t59);
    goto LAB140;

LAB142:    *((unsigned int *)t62) = 1;
    goto LAB145;

LAB144:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB145;

LAB146:    t82 = *((unsigned int *)t70);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t70) = (t82 | t83);
    t84 = (t18 + 4);
    t85 = (t62 + 4);
    t86 = *((unsigned int *)t18);
    t87 = (~(t86));
    t88 = *((unsigned int *)t84);
    t89 = (~(t88));
    t90 = *((unsigned int *)t62);
    t91 = (~(t90));
    t92 = *((unsigned int *)t85);
    t93 = (~(t92));
    t48 = (t87 & t89);
    t49 = (t91 & t93);
    t94 = (~(t48));
    t95 = (~(t49));
    t96 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t96 & t94);
    t97 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t97 & t95);
    t98 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t98 & t94);
    t99 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t99 & t95);
    goto LAB148;

LAB149:    xsi_set_current_line(150, ng0);

LAB152:    xsi_set_current_line(151, ng0);
    t106 = ((char*)((ng6)));
    t107 = (t0 + 3528);
    xsi_vlogvar_assign_value(t107, t106, 0, 0, 1);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 4328);
    t7 = (t2 + 56U);
    t14 = *((char **)t7);
    memset(t16, 0, 8);
    t15 = (t16 + 4);
    t24 = (t14 + 4);
    t9 = *((unsigned int *)t14);
    t10 = (t9 >> 8);
    *((unsigned int *)t16) = t10;
    t11 = *((unsigned int *)t24);
    t12 = (t11 >> 8);
    *((unsigned int *)t15) = t12;
    t13 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t13 & 255U);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 & 255U);
    t37 = (t0 + 3848);
    xsi_vlogvar_assign_value(t37, t16, 0, 0, 8);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 3368);
    t7 = (t2 + 56U);
    t14 = *((char **)t7);
    memset(t52, 0, 8);
    t15 = (t52 + 4);
    t24 = (t14 + 4);
    t9 = *((unsigned int *)t14);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t52) = t11;
    t12 = *((unsigned int *)t24);
    t13 = (t12 >> 0);
    t17 = (t13 & 1);
    *((unsigned int *)t15) = t17;
    memset(t18, 0, 8);
    t37 = (t52 + 4);
    t19 = *((unsigned int *)t37);
    t20 = (~(t19));
    t21 = *((unsigned int *)t52);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB153;

LAB154:    if (*((unsigned int *)t37) != 0)
        goto LAB155;

LAB156:    t44 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    t26 = *((unsigned int *)t44);
    t27 = (t25 || t26);
    if (t27 > 0)
        goto LAB157;

LAB158:    t28 = *((unsigned int *)t18);
    t29 = (~(t28));
    t30 = *((unsigned int *)t44);
    t31 = (t29 || t30);
    if (t31 > 0)
        goto LAB159;

LAB160:    if (*((unsigned int *)t44) > 0)
        goto LAB161;

LAB162:    if (*((unsigned int *)t18) > 0)
        goto LAB163;

LAB164:    memcpy(t16, t46, 8);

LAB165:    t47 = (t0 + 3208);
    xsi_vlogvar_assign_value(t47, t16, 0, 0, 10);
    xsi_set_current_line(154, ng0);
    t2 = ((char*)((ng6)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    xsi_set_current_line(155, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3368);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 2);
    goto LAB151;

LAB153:    *((unsigned int *)t18) = 1;
    goto LAB156;

LAB155:    t38 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB156;

LAB157:    t45 = ((char*)((ng4)));
    goto LAB158;

LAB159:    t46 = ((char*)((ng12)));
    goto LAB160;

LAB161:    xsi_vlog_unsigned_bit_combine(t16, 10, t45, 10, t46, 10);
    goto LAB165;

LAB163:    memcpy(t16, t45, 8);
    goto LAB165;

LAB168:    *((unsigned int *)t16) = 1;
    goto LAB171;

LAB173:    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t37);
    *((unsigned int *)t16) = (t20 | t21);
    t22 = *((unsigned int *)t24);
    t23 = *((unsigned int *)t37);
    *((unsigned int *)t24) = (t22 | t23);
    goto LAB172;

LAB174:    *((unsigned int *)t18) = 1;
    goto LAB177;

LAB176:    t44 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB177;

LAB178:    t46 = (t0 + 4008);
    t47 = (t46 + 56U);
    t50 = *((char **)t47);
    memset(t52, 0, 8);
    t51 = (t50 + 4);
    t35 = *((unsigned int *)t51);
    t36 = (~(t35));
    t39 = *((unsigned int *)t50);
    t40 = (t39 & t36);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB184;

LAB182:    if (*((unsigned int *)t51) == 0)
        goto LAB181;

LAB183:    t53 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t53) = 1;

LAB184:    t54 = (t52 + 4);
    t55 = (t50 + 4);
    t42 = *((unsigned int *)t50);
    t43 = (~(t42));
    *((unsigned int *)t52) = t43;
    *((unsigned int *)t54) = 0;
    if (*((unsigned int *)t55) != 0)
        goto LAB186;

LAB185:    t60 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t60 & 1U);
    t61 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t61 & 1U);
    memset(t62, 0, 8);
    t63 = (t52 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t52);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB187;

LAB188:    if (*((unsigned int *)t63) != 0)
        goto LAB189;

LAB190:    t71 = *((unsigned int *)t18);
    t72 = *((unsigned int *)t62);
    t73 = (t71 & t72);
    *((unsigned int *)t70) = t73;
    t74 = (t18 + 4);
    t75 = (t62 + 4);
    t76 = (t70 + 4);
    t77 = *((unsigned int *)t74);
    t78 = *((unsigned int *)t75);
    t79 = (t77 | t78);
    *((unsigned int *)t76) = t79;
    t80 = *((unsigned int *)t76);
    t81 = (t80 != 0);
    if (t81 == 1)
        goto LAB191;

LAB192:
LAB193:    goto LAB180;

LAB181:    *((unsigned int *)t52) = 1;
    goto LAB184;

LAB186:    t56 = *((unsigned int *)t52);
    t57 = *((unsigned int *)t55);
    *((unsigned int *)t52) = (t56 | t57);
    t58 = *((unsigned int *)t54);
    t59 = *((unsigned int *)t55);
    *((unsigned int *)t54) = (t58 | t59);
    goto LAB185;

LAB187:    *((unsigned int *)t62) = 1;
    goto LAB190;

LAB189:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB190;

LAB191:    t82 = *((unsigned int *)t70);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t70) = (t82 | t83);
    t84 = (t18 + 4);
    t85 = (t62 + 4);
    t86 = *((unsigned int *)t18);
    t87 = (~(t86));
    t88 = *((unsigned int *)t84);
    t89 = (~(t88));
    t90 = *((unsigned int *)t62);
    t91 = (~(t90));
    t92 = *((unsigned int *)t85);
    t93 = (~(t92));
    t48 = (t87 & t89);
    t49 = (t91 & t93);
    t94 = (~(t48));
    t95 = (~(t49));
    t96 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t96 & t94);
    t97 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t97 & t95);
    t98 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t98 & t94);
    t99 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t99 & t95);
    goto LAB193;

LAB194:    xsi_set_current_line(163, ng0);

LAB197:    xsi_set_current_line(164, ng0);
    t106 = ((char*)((ng6)));
    t107 = (t0 + 4968);
    xsi_vlogvar_assign_value(t107, t106, 0, 0, 1);
    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3368);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 2);
    xsi_set_current_line(166, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3208);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 10);
    xsi_set_current_line(167, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    goto LAB196;

LAB200:    *((unsigned int *)t16) = 1;
    goto LAB203;

LAB205:    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t24);
    *((unsigned int *)t16) = (t20 | t21);
    t22 = *((unsigned int *)t15);
    t23 = *((unsigned int *)t24);
    *((unsigned int *)t15) = (t22 | t23);
    goto LAB204;

LAB206:    *((unsigned int *)t18) = 1;
    goto LAB209;

LAB208:    t38 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB209;

LAB210:    t45 = (t0 + 4008);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    memset(t52, 0, 8);
    t50 = (t47 + 4);
    t35 = *((unsigned int *)t50);
    t36 = (~(t35));
    t39 = *((unsigned int *)t47);
    t40 = (t39 & t36);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB216;

LAB214:    if (*((unsigned int *)t50) == 0)
        goto LAB213;

LAB215:    t51 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t51) = 1;

LAB216:    t53 = (t52 + 4);
    t54 = (t47 + 4);
    t42 = *((unsigned int *)t47);
    t43 = (~(t42));
    *((unsigned int *)t52) = t43;
    *((unsigned int *)t53) = 0;
    if (*((unsigned int *)t54) != 0)
        goto LAB218;

LAB217:    t60 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t60 & 1U);
    t61 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t61 & 1U);
    memset(t62, 0, 8);
    t55 = (t52 + 4);
    t64 = *((unsigned int *)t55);
    t65 = (~(t64));
    t66 = *((unsigned int *)t52);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB219;

LAB220:    if (*((unsigned int *)t55) != 0)
        goto LAB221;

LAB222:    t71 = *((unsigned int *)t18);
    t72 = *((unsigned int *)t62);
    t73 = (t71 & t72);
    *((unsigned int *)t70) = t73;
    t69 = (t18 + 4);
    t74 = (t62 + 4);
    t75 = (t70 + 4);
    t77 = *((unsigned int *)t69);
    t78 = *((unsigned int *)t74);
    t79 = (t77 | t78);
    *((unsigned int *)t75) = t79;
    t80 = *((unsigned int *)t75);
    t81 = (t80 != 0);
    if (t81 == 1)
        goto LAB223;

LAB224:
LAB225:    goto LAB212;

LAB213:    *((unsigned int *)t52) = 1;
    goto LAB216;

LAB218:    t56 = *((unsigned int *)t52);
    t57 = *((unsigned int *)t54);
    *((unsigned int *)t52) = (t56 | t57);
    t58 = *((unsigned int *)t53);
    t59 = *((unsigned int *)t54);
    *((unsigned int *)t53) = (t58 | t59);
    goto LAB217;

LAB219:    *((unsigned int *)t62) = 1;
    goto LAB222;

LAB221:    t63 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB222;

LAB223:    t82 = *((unsigned int *)t70);
    t83 = *((unsigned int *)t75);
    *((unsigned int *)t70) = (t82 | t83);
    t76 = (t18 + 4);
    t84 = (t62 + 4);
    t86 = *((unsigned int *)t18);
    t87 = (~(t86));
    t88 = *((unsigned int *)t76);
    t89 = (~(t88));
    t90 = *((unsigned int *)t62);
    t91 = (~(t90));
    t92 = *((unsigned int *)t84);
    t93 = (~(t92));
    t6 = (t87 & t89);
    t48 = (t91 & t93);
    t94 = (~(t6));
    t95 = (~(t48));
    t96 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t96 & t94);
    t97 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t97 & t95);
    t98 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t98 & t94);
    t99 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t99 & t95);
    goto LAB225;

LAB226:    xsi_set_current_line(176, ng0);

LAB229:    xsi_set_current_line(177, ng0);
    t100 = ((char*)((ng6)));
    t106 = (t0 + 3528);
    xsi_vlogvar_assign_value(t106, t100, 0, 0, 1);
    xsi_set_current_line(178, ng0);
    t2 = (t0 + 2648U);
    t7 = *((char **)t2);
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t7, 0, 0, 8);
    xsi_set_current_line(179, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3368);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 2);
    xsi_set_current_line(180, ng0);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 3208);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 10);
    xsi_set_current_line(181, ng0);
    t2 = ((char*)((ng6)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    goto LAB228;

LAB232:    *((unsigned int *)t16) = 1;
    goto LAB235;

LAB237:    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t24);
    *((unsigned int *)t16) = (t20 | t21);
    t22 = *((unsigned int *)t15);
    t23 = *((unsigned int *)t24);
    *((unsigned int *)t15) = (t22 | t23);
    goto LAB236;

LAB238:    *((unsigned int *)t18) = 1;
    goto LAB241;

LAB240:    t38 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB241;

LAB242:    t45 = (t0 + 4008);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    memset(t52, 0, 8);
    t50 = (t47 + 4);
    t35 = *((unsigned int *)t50);
    t36 = (~(t35));
    t39 = *((unsigned int *)t47);
    t40 = (t39 & t36);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB248;

LAB246:    if (*((unsigned int *)t50) == 0)
        goto LAB245;

LAB247:    t51 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t51) = 1;

LAB248:    t53 = (t52 + 4);
    t54 = (t47 + 4);
    t42 = *((unsigned int *)t47);
    t43 = (~(t42));
    *((unsigned int *)t52) = t43;
    *((unsigned int *)t53) = 0;
    if (*((unsigned int *)t54) != 0)
        goto LAB250;

LAB249:    t60 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t60 & 1U);
    t61 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t61 & 1U);
    memset(t62, 0, 8);
    t55 = (t52 + 4);
    t64 = *((unsigned int *)t55);
    t65 = (~(t64));
    t66 = *((unsigned int *)t52);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB251;

LAB252:    if (*((unsigned int *)t55) != 0)
        goto LAB253;

LAB254:    t71 = *((unsigned int *)t18);
    t72 = *((unsigned int *)t62);
    t73 = (t71 & t72);
    *((unsigned int *)t70) = t73;
    t69 = (t18 + 4);
    t74 = (t62 + 4);
    t75 = (t70 + 4);
    t77 = *((unsigned int *)t69);
    t78 = *((unsigned int *)t74);
    t79 = (t77 | t78);
    *((unsigned int *)t75) = t79;
    t80 = *((unsigned int *)t75);
    t81 = (t80 != 0);
    if (t81 == 1)
        goto LAB255;

LAB256:
LAB257:    goto LAB244;

LAB245:    *((unsigned int *)t52) = 1;
    goto LAB248;

LAB250:    t56 = *((unsigned int *)t52);
    t57 = *((unsigned int *)t54);
    *((unsigned int *)t52) = (t56 | t57);
    t58 = *((unsigned int *)t53);
    t59 = *((unsigned int *)t54);
    *((unsigned int *)t53) = (t58 | t59);
    goto LAB249;

LAB251:    *((unsigned int *)t62) = 1;
    goto LAB254;

LAB253:    t63 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB254;

LAB255:    t82 = *((unsigned int *)t70);
    t83 = *((unsigned int *)t75);
    *((unsigned int *)t70) = (t82 | t83);
    t76 = (t18 + 4);
    t84 = (t62 + 4);
    t86 = *((unsigned int *)t18);
    t87 = (~(t86));
    t88 = *((unsigned int *)t76);
    t89 = (~(t88));
    t90 = *((unsigned int *)t62);
    t91 = (~(t90));
    t92 = *((unsigned int *)t84);
    t93 = (~(t92));
    t6 = (t87 & t89);
    t48 = (t91 & t93);
    t94 = (~(t6));
    t95 = (~(t48));
    t96 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t96 & t94);
    t97 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t97 & t95);
    t98 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t98 & t94);
    t99 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t99 & t95);
    goto LAB257;

LAB258:    xsi_set_current_line(190, ng0);

LAB261:    xsi_set_current_line(191, ng0);
    t100 = ((char*)((ng6)));
    t106 = (t0 + 3528);
    xsi_vlogvar_assign_value(t106, t100, 0, 0, 1);
    xsi_set_current_line(192, ng0);
    t2 = (t0 + 2648U);
    t7 = *((char **)t2);
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t7, 0, 0, 8);
    xsi_set_current_line(193, ng0);
    t2 = (t0 + 3208);
    t7 = (t2 + 56U);
    t14 = *((char **)t7);
    t15 = ((char*)((ng6)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t14, 10, t15, 32);
    t24 = (t0 + 3208);
    xsi_vlogvar_assign_value(t24, t16, 0, 0, 10);
    xsi_set_current_line(194, ng0);
    t2 = ((char*)((ng6)));
    t7 = (t0 + 4008);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 1);
    goto LAB260;

}


extern void work_m_00000000003438467978_0039860855_init()
{
	static char *pe[] = {(void *)Cont_50_0,(void *)Always_79_1};
	xsi_register_didat("work_m_00000000003438467978_0039860855", "isim/t_KB_isim_beh.exe.sim/work/m_00000000003438467978_0039860855.didat");
	xsi_register_executes(pe);
}
