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
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {40, 0};
static int ng4[] = {1, 0};
static int ng5[] = {39, 0};
static unsigned int ng6[] = {1U, 0U};
static unsigned int ng7[] = {13U, 0U};
static unsigned int ng8[] = {8U, 0U};
static unsigned int ng9[] = {27U, 0U};
static int ng10[] = {30, 0};
static unsigned int ng11[] = {7U, 0U};



static void Initial_96_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(96, ng0);

LAB2:    xsi_set_current_line(97, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 5768);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(98, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 5928);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 12);
    xsi_set_current_line(99, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 6088);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 12);
    xsi_set_current_line(100, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 6248);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(101, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 6728);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(102, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 6888);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(103, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 7048);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_106_1(char *t0)
{
    char t6[8];
    char t13[8];
    char t14[8];
    char t24[8];
    char t60[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    int t84;
    int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;
    char *t100;

LAB0:    t1 = (t0 + 8696U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 11248);
    *((int *)t2) = 1;
    t3 = (t0 + 8728);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(106, ng0);

LAB5:    xsi_set_current_line(108, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 6728);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 2648U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 4);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 4);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 31U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 31U);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_multiply(t13, 32, t6, 32, t5, 32);
    t15 = (t0 + 2488U);
    t16 = *((char **)t15);
    memset(t14, 0, 8);
    t15 = (t14 + 4);
    t17 = (t16 + 4);
    t18 = *((unsigned int *)t16);
    t19 = (t18 >> 4);
    *((unsigned int *)t14) = t19;
    t20 = *((unsigned int *)t17);
    t21 = (t20 >> 4);
    *((unsigned int *)t15) = t21;
    t22 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t22 & 63U);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t23 & 63U);
    memset(t24, 0, 8);
    xsi_vlog_unsigned_add(t24, 32, t13, 32, t14, 32);
    t25 = (t0 + 6088);
    xsi_vlogvar_wait_assign_value(t25, t24, 0, 0, 12, 0LL);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 7528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB6;

LAB7:
LAB8:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t5);
    t12 = (t10 ^ t11);
    t18 = (t9 | t12);
    t19 = *((unsigned int *)t4);
    t20 = *((unsigned int *)t5);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB17;

LAB14:    if (t21 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t6) = 1;

LAB17:    memset(t13, 0, 8);
    t16 = (t6 + 4);
    t26 = *((unsigned int *)t16);
    t27 = (~(t26));
    t28 = *((unsigned int *)t6);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t16) != 0)
        goto LAB20;

LAB21:    t25 = (t13 + 4);
    t31 = *((unsigned int *)t13);
    t32 = *((unsigned int *)t25);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB22;

LAB23:    memcpy(t60, t13, 8);

LAB24:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB36;

LAB37:    xsi_set_current_line(152, ng0);
    t2 = (t0 + 2168U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t15 = (t2 + 4);
    t7 = *((unsigned int *)t4);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t15);
    t12 = (t10 ^ t11);
    t18 = (t9 | t12);
    t19 = *((unsigned int *)t5);
    t20 = *((unsigned int *)t15);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB61;

LAB58:    if (t21 != 0)
        goto LAB60;

LAB59:    *((unsigned int *)t6) = 1;

LAB61:    memset(t13, 0, 8);
    t17 = (t6 + 4);
    t26 = *((unsigned int *)t17);
    t27 = (~(t26));
    t28 = *((unsigned int *)t6);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB62;

LAB63:    if (*((unsigned int *)t17) != 0)
        goto LAB64;

LAB65:    t34 = (t13 + 4);
    t31 = *((unsigned int *)t13);
    t32 = *((unsigned int *)t34);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB66;

LAB67:    memcpy(t60, t13, 8);

LAB68:    t98 = (t60 + 4);
    t93 = *((unsigned int *)t98);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB80;

LAB81:    xsi_set_current_line(156, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 6728);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);

LAB82:
LAB38:    xsi_set_current_line(157, ng0);
    t2 = (t0 + 6568);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng10)));
    memset(t6, 0, 8);
    t16 = (t5 + 4);
    t17 = (t15 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t15);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t16);
    t11 = *((unsigned int *)t17);
    t12 = (t10 ^ t11);
    t18 = (t9 | t12);
    t19 = *((unsigned int *)t16);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB87;

LAB84:    if (t21 != 0)
        goto LAB86;

LAB85:    *((unsigned int *)t6) = 1;

LAB87:    t34 = (t6 + 4);
    t26 = *((unsigned int *)t34);
    t27 = (~(t26));
    t28 = *((unsigned int *)t6);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB88;

LAB89:
LAB90:    goto LAB2;

LAB6:    xsi_set_current_line(111, ng0);

LAB9:    xsi_set_current_line(112, ng0);
    t15 = ((char*)((ng1)));
    t16 = (t0 + 7528);
    xsi_vlogvar_wait_assign_value(t16, t15, 0, 0, 1, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 6408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_minus(t6, 32, t4, 32, t5, 32);
    t15 = (t0 + 6408);
    xsi_vlogvar_wait_assign_value(t15, t6, 0, 0, 32, 0LL);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 6408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t15 = (t6 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB8;

LAB10:    xsi_set_current_line(114, ng0);

LAB13:    xsi_set_current_line(115, ng0);
    t16 = ((char*)((ng5)));
    t17 = (t0 + 6408);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 32, 0LL);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 6568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 32, t4, 6, t5, 32);
    t15 = (t0 + 6568);
    xsi_vlogvar_wait_assign_value(t15, t6, 0, 0, 6, 0LL);
    goto LAB12;

LAB16:    t15 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB17;

LAB18:    *((unsigned int *)t13) = 1;
    goto LAB21;

LAB20:    t17 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB21;

LAB22:    t34 = (t0 + 7048);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = ((char*)((ng2)));
    memset(t14, 0, 8);
    t38 = (t36 + 4);
    t39 = (t37 + 4);
    t40 = *((unsigned int *)t36);
    t41 = *((unsigned int *)t37);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t38);
    t44 = *((unsigned int *)t39);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t38);
    t48 = *((unsigned int *)t39);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t51 = (t46 & t50);
    if (t51 != 0)
        goto LAB28;

LAB25:    if (t49 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t14) = 1;

LAB28:    memset(t24, 0, 8);
    t53 = (t14 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t14);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t53) != 0)
        goto LAB31;

LAB32:    t61 = *((unsigned int *)t13);
    t62 = *((unsigned int *)t24);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t13 + 4);
    t65 = (t24 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB33;

LAB34:
LAB35:    goto LAB24;

LAB27:    t52 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB28;

LAB29:    *((unsigned int *)t24) = 1;
    goto LAB32;

LAB31:    t59 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB32;

LAB33:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t13 + 4);
    t75 = (t24 + 4);
    t76 = *((unsigned int *)t13);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t24);
    t81 = (~(t80));
    t82 = *((unsigned int *)t75);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t88 & t86);
    t89 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB35;

LAB36:    xsi_set_current_line(119, ng0);

LAB39:    xsi_set_current_line(121, ng0);
    t98 = ((char*)((ng4)));
    t99 = (t0 + 7048);
    xsi_vlogvar_wait_assign_value(t99, t98, 0, 0, 1, 0LL);
    xsi_set_current_line(122, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);

LAB40:    t2 = ((char*)((ng7)));
    t84 = xsi_vlog_unsigned_case_compare(t3, 32, t2, 32);
    if (t84 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng8)));
    t84 = xsi_vlog_unsigned_case_compare(t3, 32, t2, 32);
    if (t84 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng9)));
    t84 = xsi_vlog_unsigned_case_compare(t3, 32, t2, 32);
    if (t84 == 1)
        goto LAB45;

LAB46:
LAB48:
LAB47:    xsi_set_current_line(141, ng0);

LAB53:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 6408);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t5, 32, t15, 32);
    t16 = (t6 + 4);
    t7 = *((unsigned int *)t16);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB54;

LAB55:
LAB56:    xsi_set_current_line(146, ng0);
    t2 = (t0 + 2008U);
    t4 = *((char **)t2);
    t2 = (t0 + 6888);
    xsi_vlogvar_wait_assign_value(t2, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 6728);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 6408);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t5, 32, t15, 32);
    t16 = (t0 + 6408);
    xsi_vlogvar_wait_assign_value(t16, t6, 0, 0, 32, 0LL);

LAB49:    goto LAB38;

LAB41:    xsi_set_current_line(123, ng0);

LAB50:    xsi_set_current_line(124, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 6408);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 6568);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t5, 6, t15, 32);
    t16 = (t0 + 6568);
    xsi_vlogvar_wait_assign_value(t16, t6, 0, 0, 6, 0LL);
    goto LAB49;

LAB43:    xsi_set_current_line(127, ng0);

LAB51:    xsi_set_current_line(128, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 6888);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 6728);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(130, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 7528);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    goto LAB49;

LAB45:    xsi_set_current_line(138, ng0);

LAB52:    xsi_set_current_line(139, ng0);
    t4 = ((char*)((ng10)));
    t5 = (t0 + 6568);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 6, 0LL);
    goto LAB49;

LAB54:    xsi_set_current_line(142, ng0);

LAB57:    xsi_set_current_line(143, ng0);
    t17 = ((char*)((ng1)));
    t25 = (t0 + 6408);
    xsi_vlogvar_wait_assign_value(t25, t17, 0, 0, 32, 0LL);
    xsi_set_current_line(144, ng0);
    t2 = (t0 + 6568);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t15 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t5, 6, t15, 32);
    t16 = (t0 + 6568);
    xsi_vlogvar_wait_assign_value(t16, t6, 0, 0, 6, 0LL);
    goto LAB56;

LAB60:    t16 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB61;

LAB62:    *((unsigned int *)t13) = 1;
    goto LAB65;

LAB64:    t25 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB65;

LAB66:    t35 = (t0 + 7048);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = ((char*)((ng6)));
    memset(t14, 0, 8);
    t39 = (t37 + 4);
    t52 = (t38 + 4);
    t40 = *((unsigned int *)t37);
    t41 = *((unsigned int *)t38);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t39);
    t44 = *((unsigned int *)t52);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t39);
    t48 = *((unsigned int *)t52);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t51 = (t46 & t50);
    if (t51 != 0)
        goto LAB72;

LAB69:    if (t49 != 0)
        goto LAB71;

LAB70:    *((unsigned int *)t14) = 1;

LAB72:    memset(t24, 0, 8);
    t59 = (t14 + 4);
    t54 = *((unsigned int *)t59);
    t55 = (~(t54));
    t56 = *((unsigned int *)t14);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB73;

LAB74:    if (*((unsigned int *)t59) != 0)
        goto LAB75;

LAB76:    t61 = *((unsigned int *)t13);
    t62 = *((unsigned int *)t24);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t65 = (t13 + 4);
    t66 = (t24 + 4);
    t74 = (t60 + 4);
    t67 = *((unsigned int *)t65);
    t68 = *((unsigned int *)t66);
    t69 = (t67 | t68);
    *((unsigned int *)t74) = t69;
    t70 = *((unsigned int *)t74);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB77;

LAB78:
LAB79:    goto LAB68;

LAB71:    t53 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t53) = 1;
    goto LAB72;

LAB73:    *((unsigned int *)t24) = 1;
    goto LAB76;

LAB75:    t64 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB76;

LAB77:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t74);
    *((unsigned int *)t60) = (t72 | t73);
    t75 = (t13 + 4);
    t92 = (t24 + 4);
    t76 = *((unsigned int *)t13);
    t77 = (~(t76));
    t78 = *((unsigned int *)t75);
    t79 = (~(t78));
    t80 = *((unsigned int *)t24);
    t81 = (~(t80));
    t82 = *((unsigned int *)t92);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t88 & t86);
    t89 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB79;

LAB80:    xsi_set_current_line(152, ng0);

LAB83:    xsi_set_current_line(153, ng0);
    t99 = ((char*)((ng1)));
    t100 = (t0 + 7048);
    xsi_vlogvar_wait_assign_value(t100, t99, 0, 0, 1, 0LL);
    goto LAB82;

LAB86:    t25 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB87;

LAB88:    xsi_set_current_line(157, ng0);

LAB91:    xsi_set_current_line(158, ng0);
    t35 = ((char*)((ng1)));
    t36 = (t0 + 6568);
    xsi_vlogvar_wait_assign_value(t36, t35, 0, 0, 6, 0LL);
    xsi_set_current_line(159, ng0);
    t2 = (t0 + 7208);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t15 = (t5 + 4);
    t7 = *((unsigned int *)t15);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB95;

LAB93:    if (*((unsigned int *)t15) == 0)
        goto LAB92;

LAB94:    t16 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t16) = 1;

LAB95:    t17 = (t6 + 4);
    t25 = (t5 + 4);
    t12 = *((unsigned int *)t5);
    t18 = (~(t12));
    *((unsigned int *)t6) = t18;
    *((unsigned int *)t17) = 0;
    if (*((unsigned int *)t25) != 0)
        goto LAB97;

LAB96:    t23 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t23 & 1U);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t26 & 1U);
    t34 = (t0 + 7208);
    xsi_vlogvar_wait_assign_value(t34, t6, 0, 0, 1, 0LL);
    goto LAB90;

LAB92:    *((unsigned int *)t6) = 1;
    goto LAB95;

LAB97:    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t25);
    *((unsigned int *)t6) = (t19 | t20);
    t21 = *((unsigned int *)t17);
    t22 = *((unsigned int *)t25);
    *((unsigned int *)t17) = (t21 | t22);
    goto LAB96;

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

LAB0:    t1 = (t0 + 8944U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng2)));
    t3 = (t0 + 11456);
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

static void implSig2_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t22[8];
    char t41[8];
    char t42[8];
    char t46[8];
    char t62[8];
    char t70[8];
    char t113[8];
    char t114[8];
    char t115[8];
    char t126[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
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
    char *t21;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t43;
    char *t44;
    char *t45;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
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
    int t94;
    int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    char *t108;
    char *t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t116;
    char *t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    char *t127;
    char *t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    char *t148;
    char *t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    char *t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    char *t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    char *t163;
    char *t164;
    char *t165;
    char *t166;
    char *t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    char *t171;
    unsigned int t172;
    unsigned int t173;
    char *t174;
    unsigned int t175;
    unsigned int t176;
    char *t177;

LAB0:    t1 = (t0 + 9192U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3448U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t2 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB7:    memset(t22, 0, 8);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t23) != 0)
        goto LAB10;

LAB11:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB12;

LAB13:    memcpy(t70, t22, 8);

LAB14:    memset(t4, 0, 8);
    t102 = (t70 + 4);
    t103 = *((unsigned int *)t102);
    t104 = (~(t103));
    t105 = *((unsigned int *)t70);
    t106 = (t105 & t104);
    t107 = (t106 & 1U);
    if (t107 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t102) != 0)
        goto LAB28;

LAB29:    t109 = (t4 + 4);
    t110 = *((unsigned int *)t4);
    t111 = *((unsigned int *)t109);
    t112 = (t110 || t111);
    if (t112 > 0)
        goto LAB30;

LAB31:    t159 = *((unsigned int *)t4);
    t160 = (~(t159));
    t161 = *((unsigned int *)t109);
    t162 = (t160 || t161);
    if (t162 > 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t109) > 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t4) > 0)
        goto LAB36;

LAB37:    memcpy(t3, t164, 8);

LAB38:    t163 = (t0 + 11520);
    t165 = (t163 + 56U);
    t166 = *((char **)t165);
    t167 = (t166 + 56U);
    t168 = *((char **)t167);
    memset(t168, 0, 8);
    t169 = 7U;
    t170 = t169;
    t171 = (t3 + 4);
    t172 = *((unsigned int *)t3);
    t169 = (t169 & t172);
    t173 = *((unsigned int *)t171);
    t170 = (t170 & t173);
    t174 = (t168 + 4);
    t175 = *((unsigned int *)t168);
    *((unsigned int *)t168) = (t175 | t169);
    t176 = *((unsigned int *)t174);
    *((unsigned int *)t174) = (t176 | t170);
    xsi_driver_vfirst_trans(t163, 0, 2);
    t177 = (t0 + 11264);
    *((int *)t177) = 1;

LAB1:    return;
LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t22) = 1;
    goto LAB11;

LAB10:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB11;

LAB12:    t34 = (t0 + 6408);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = (t0 + 6568);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = ((char*)((ng3)));
    memset(t41, 0, 8);
    xsi_vlog_unsigned_multiply(t41, 32, t39, 6, t40, 32);
    memset(t42, 0, 8);
    xsi_vlog_unsigned_add(t42, 32, t36, 32, t41, 32);
    t43 = (t0 + 6088);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    memset(t46, 0, 8);
    t47 = (t42 + 4);
    t48 = (t45 + 4);
    t49 = *((unsigned int *)t42);
    t50 = *((unsigned int *)t45);
    t51 = (t49 ^ t50);
    t52 = *((unsigned int *)t47);
    t53 = *((unsigned int *)t48);
    t54 = (t52 ^ t53);
    t55 = (t51 | t54);
    t56 = *((unsigned int *)t47);
    t57 = *((unsigned int *)t48);
    t58 = (t56 | t57);
    t59 = (~(t58));
    t60 = (t55 & t59);
    if (t60 != 0)
        goto LAB18;

LAB15:    if (t58 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t46) = 1;

LAB18:    memset(t62, 0, 8);
    t63 = (t46 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t46);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t63) != 0)
        goto LAB21;

LAB22:    t71 = *((unsigned int *)t22);
    t72 = *((unsigned int *)t62);
    t73 = (t71 & t72);
    *((unsigned int *)t70) = t73;
    t74 = (t22 + 4);
    t75 = (t62 + 4);
    t76 = (t70 + 4);
    t77 = *((unsigned int *)t74);
    t78 = *((unsigned int *)t75);
    t79 = (t77 | t78);
    *((unsigned int *)t76) = t79;
    t80 = *((unsigned int *)t76);
    t81 = (t80 != 0);
    if (t81 == 1)
        goto LAB23;

LAB24:
LAB25:    goto LAB14;

LAB17:    t61 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t61) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t62) = 1;
    goto LAB22;

LAB21:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB22;

LAB23:    t82 = *((unsigned int *)t70);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t70) = (t82 | t83);
    t84 = (t22 + 4);
    t85 = (t62 + 4);
    t86 = *((unsigned int *)t22);
    t87 = (~(t86));
    t88 = *((unsigned int *)t84);
    t89 = (~(t88));
    t90 = *((unsigned int *)t62);
    t91 = (~(t90));
    t92 = *((unsigned int *)t85);
    t93 = (~(t92));
    t94 = (t87 & t89);
    t95 = (t91 & t93);
    t96 = (~(t94));
    t97 = (~(t95));
    t98 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t98 & t96);
    t99 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t99 & t97);
    t100 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t100 & t96);
    t101 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t101 & t97);
    goto LAB25;

LAB26:    *((unsigned int *)t4) = 1;
    goto LAB29;

LAB28:    t108 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t108) = 1;
    goto LAB29;

LAB30:    t116 = (t0 + 2488U);
    t117 = *((char **)t116);
    memset(t115, 0, 8);
    t116 = (t115 + 4);
    t118 = (t117 + 4);
    t119 = *((unsigned int *)t117);
    t120 = (t119 >> 0);
    *((unsigned int *)t115) = t120;
    t121 = *((unsigned int *)t118);
    t122 = (t121 >> 0);
    *((unsigned int *)t116) = t122;
    t123 = *((unsigned int *)t115);
    *((unsigned int *)t115) = (t123 & 15U);
    t124 = *((unsigned int *)t116);
    *((unsigned int *)t116) = (t124 & 15U);
    t125 = ((char*)((ng2)));
    memset(t126, 0, 8);
    t127 = (t115 + 4);
    t128 = (t125 + 4);
    t129 = *((unsigned int *)t115);
    t130 = *((unsigned int *)t125);
    t131 = (t129 ^ t130);
    t132 = *((unsigned int *)t127);
    t133 = *((unsigned int *)t128);
    t134 = (t132 ^ t133);
    t135 = (t131 | t134);
    t136 = *((unsigned int *)t127);
    t137 = *((unsigned int *)t128);
    t138 = (t136 | t137);
    t139 = (~(t138));
    t140 = (t135 & t139);
    if (t140 != 0)
        goto LAB42;

LAB39:    if (t138 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t126) = 1;

LAB42:    memset(t114, 0, 8);
    t142 = (t126 + 4);
    t143 = *((unsigned int *)t142);
    t144 = (~(t143));
    t145 = *((unsigned int *)t126);
    t146 = (t145 & t144);
    t147 = (t146 & 1U);
    if (t147 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t142) != 0)
        goto LAB45;

LAB46:    t149 = (t114 + 4);
    t150 = *((unsigned int *)t114);
    t151 = *((unsigned int *)t149);
    t152 = (t150 || t151);
    if (t152 > 0)
        goto LAB47;

LAB48:    t154 = *((unsigned int *)t114);
    t155 = (~(t154));
    t156 = *((unsigned int *)t149);
    t157 = (t155 || t156);
    if (t157 > 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t149) > 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t114) > 0)
        goto LAB53;

LAB54:    memcpy(t113, t158, 8);

LAB55:    goto LAB31;

LAB32:    t163 = (t0 + 2968U);
    t164 = *((char **)t163);
    goto LAB33;

LAB34:    xsi_vlog_unsigned_bit_combine(t3, 3, t113, 3, t164, 3);
    goto LAB38;

LAB36:    memcpy(t3, t113, 8);
    goto LAB38;

LAB41:    t141 = (t126 + 4);
    *((unsigned int *)t126) = 1;
    *((unsigned int *)t141) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t114) = 1;
    goto LAB46;

LAB45:    t148 = (t114 + 4);
    *((unsigned int *)t114) = 1;
    *((unsigned int *)t148) = 1;
    goto LAB46;

LAB47:    t153 = ((char*)((ng11)));
    goto LAB48;

LAB49:    t158 = ((char*)((ng2)));
    goto LAB50;

LAB51:    xsi_vlog_unsigned_bit_combine(t113, 3, t153, 3, t158, 3);
    goto LAB55;

LAB53:    memcpy(t113, t153, 8);
    goto LAB55;

}

static void implSig3_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char t26[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 9440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 7208);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t19 = *((unsigned int *)t4);
    t20 = (~(t19));
    t21 = *((unsigned int *)t14);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t26, 8);

LAB16:    t27 = (t0 + 11584);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memcpy(t31, t3, 8);
    xsi_driver_vfirst_trans(t27, 0, 31);
    t32 = (t0 + 11280);
    *((int *)t32) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = ((char*)((ng4)));
    goto LAB9;

LAB10:    t23 = (t0 + 6728);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t18, 32, t26, 32);
    goto LAB16;

LAB14:    memcpy(t3, t18, 8);
    goto LAB16;

}

static void implSig4_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char t21[8];
    char t33[8];
    char t34[8];
    char t36[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t35;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;

LAB0:    t1 = (t0 + 9688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 7208);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t22 = *((unsigned int *)t4);
    t23 = (~(t22));
    t24 = *((unsigned int *)t14);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t36, 8);

LAB16:    t37 = (t0 + 11648);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    memcpy(t41, t3, 8);
    xsi_driver_vfirst_trans(t37, 0, 31);
    t42 = (t0 + 11296);
    *((int *)t42) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 6088);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t21, t20, 8);
    goto LAB9;

LAB10:    t26 = (t0 + 6408);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t0 + 6568);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = ((char*)((ng3)));
    memset(t33, 0, 8);
    xsi_vlog_unsigned_multiply(t33, 32, t31, 6, t32, 32);
    memset(t34, 0, 8);
    xsi_vlog_unsigned_add(t34, 32, t28, 32, t33, 32);
    t35 = ((char*)((ng4)));
    memset(t36, 0, 8);
    xsi_vlog_unsigned_minus(t36, 32, t34, 32, t35, 32);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t21, 32, t36, 32);
    goto LAB16;

LAB14:    memcpy(t3, t21, 8);
    goto LAB16;

}

static void implSig5_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char t26[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 9936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 7208);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t19 = *((unsigned int *)t4);
    t20 = (~(t19));
    t21 = *((unsigned int *)t14);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t26, 8);

LAB16:    t27 = (t0 + 11712);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memcpy(t31, t3, 8);
    xsi_driver_vfirst_trans(t27, 0, 31);
    t32 = (t0 + 11312);
    *((int *)t32) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = ((char*)((ng1)));
    goto LAB9;

LAB10:    t23 = (t0 + 6888);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t18, 32, t26, 32);
    goto LAB16;

LAB14:    memcpy(t3, t18, 8);
    goto LAB16;

}

static void implSig6_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 10184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 7208);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t22 = *((unsigned int *)t4);
    t23 = (~(t22));
    t24 = *((unsigned int *)t14);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t26, 8);

LAB16:    t27 = (t0 + 11776);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memcpy(t31, t3, 8);
    xsi_driver_vfirst_trans(t27, 0, 31);
    t32 = (t0 + 11328);
    *((int *)t32) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 6728);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t21, t20, 8);
    goto LAB9;

LAB10:    t26 = ((char*)((ng4)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t21, 32, t26, 32);
    goto LAB16;

LAB14:    memcpy(t3, t21, 8);
    goto LAB16;

}

static void implSig7_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char t25[8];
    char t26[8];
    char t28[8];
    char t36[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t27;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;

LAB0:    t1 = (t0 + 10432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 7208);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t29 = *((unsigned int *)t4);
    t30 = (~(t29));
    t31 = *((unsigned int *)t14);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t36, 8);

LAB16:    t37 = (t0 + 11840);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    memcpy(t41, t3, 8);
    xsi_driver_vfirst_trans(t37, 0, 31);
    t42 = (t0 + 11344);
    *((int *)t42) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 6408);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t0 + 6568);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = ((char*)((ng3)));
    memset(t25, 0, 8);
    xsi_vlog_unsigned_multiply(t25, 32, t23, 6, t24, 32);
    memset(t26, 0, 8);
    xsi_vlog_unsigned_add(t26, 32, t20, 32, t25, 32);
    t27 = ((char*)((ng4)));
    memset(t28, 0, 8);
    xsi_vlog_unsigned_minus(t28, 32, t26, 32, t27, 32);
    goto LAB9;

LAB10:    t33 = (t0 + 6088);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t36, t35, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t28, 32, t36, 32);
    goto LAB16;

LAB14:    memcpy(t3, t28, 8);
    goto LAB16;

}

static void implSig8_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 10680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 7208);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t22 = *((unsigned int *)t4);
    t23 = (~(t22));
    t24 = *((unsigned int *)t14);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t26, 8);

LAB16:    t27 = (t0 + 11904);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memcpy(t31, t3, 8);
    xsi_driver_vfirst_trans(t27, 0, 31);
    t32 = (t0 + 11360);
    *((int *)t32) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 6888);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t21, t20, 8);
    goto LAB9;

LAB10:    t26 = ((char*)((ng1)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t21, 32, t26, 32);
    goto LAB16;

LAB14:    memcpy(t3, t21, 8);
    goto LAB16;

}

static void implSig9_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;

LAB0:    t1 = (t0 + 10928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 7208);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t20 = *((unsigned int *)t4);
    t21 = (~(t20));
    t22 = *((unsigned int *)t14);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t24, 8);

LAB16:    t18 = (t0 + 11968);
    t25 = (t18 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memset(t28, 0, 8);
    t29 = 255U;
    t30 = t29;
    t31 = (t3 + 4);
    t32 = *((unsigned int *)t3);
    t29 = (t29 & t32);
    t33 = *((unsigned int *)t31);
    t30 = (t30 & t33);
    t34 = (t28 + 4);
    t35 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t35 | t29);
    t36 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t36 | t30);
    xsi_driver_vfirst_trans(t18, 0, 7);
    t37 = (t0 + 11376);
    *((int *)t37) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 3768U);
    t19 = *((char **)t18);
    goto LAB9;

LAB10:    t18 = (t0 + 3608U);
    t24 = *((char **)t18);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 8, t19, 8, t24, 8);
    goto LAB16;

LAB14:    memcpy(t3, t19, 8);
    goto LAB16;

}


extern void work_m_00000000004106637142_3566486687_init()
{
	static char *pe[] = {(void *)Initial_96_0,(void *)Always_106_1,(void *)implSig1_execute,(void *)implSig2_execute,(void *)implSig3_execute,(void *)implSig4_execute,(void *)implSig5_execute,(void *)implSig6_execute,(void *)implSig7_execute,(void *)implSig8_execute,(void *)implSig9_execute};
	xsi_register_didat("work_m_00000000004106637142_3566486687", "isim/t_tty_isim_beh.exe.sim/work/m_00000000004106637142_3566486687.didat");
	xsi_register_executes(pe);
}
