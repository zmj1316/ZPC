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
static unsigned int ng1[] = {0U, 4294967295U};
static int ng2[] = {0, 0};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {0U, 0U};
static unsigned int ng5[] = {1U, 0U};



static void Cont_34_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 6208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7352);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t2, 8);
    xsi_driver_vfirst_trans(t3, 0, 31);

LAB1:    return;
}

static void Initial_88_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(88, ng0);

LAB2:    xsi_set_current_line(89, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 4168);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 4328);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 12);
    xsi_set_current_line(91, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 4488);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 12);
    xsi_set_current_line(92, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 4648);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(93, ng0);
    t1 = ((char*)((ng3)));
    memset(t3, 0, 8);
    xsi_vlog_signed_unary_minus(t3, 32, t1, 32);
    t2 = (t0 + 4808);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 12);
    xsi_set_current_line(94, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 4968);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(95, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 5128);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(96, ng0);
    t1 = ((char*)((ng4)));
    t2 = (t0 + 5288);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_99_2(char *t0)
{
    char t6[8];
    char t7[8];
    char t14[8];
    char t52[8];
    char t60[8];
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
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    unsigned int t39;
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
    char *t51;
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

LAB0:    t1 = (t0 + 6704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 7272);
    *((int *)t2) = 1;
    t3 = (t0 + 6736);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(99, ng0);

LAB5:    xsi_set_current_line(101, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 4968);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(102, ng0);
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
    t23 = (t0 + 4488);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 12);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
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
        goto LAB9;

LAB6:    if (t20 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    memset(t7, 0, 8);
    t16 = (t6 + 4);
    t24 = *((unsigned int *)t16);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t29 = (t7 + 4);
    t30 = *((unsigned int *)t7);
    t31 = *((unsigned int *)t29);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB14;

LAB15:    memcpy(t60, t7, 8);

LAB16:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(110, ng0);
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
        goto LAB35;

LAB32:    if (t20 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t6) = 1;

LAB35:    memset(t7, 0, 8);
    t16 = (t6 + 4);
    t24 = *((unsigned int *)t16);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t16) != 0)
        goto LAB38;

LAB39:    t29 = (t7 + 4);
    t30 = *((unsigned int *)t7);
    t31 = *((unsigned int *)t29);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB40;

LAB41:    memcpy(t60, t7, 8);

LAB42:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB54;

LAB55:    xsi_set_current_line(114, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4968);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB56:
LAB30:    goto LAB2;

LAB8:    t15 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t7) = 1;
    goto LAB13;

LAB12:    t23 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB13;

LAB14:    t33 = (t0 + 5288);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng4)));
    memset(t14, 0, 8);
    t37 = (t35 + 4);
    t38 = (t36 + 4);
    t39 = *((unsigned int *)t35);
    t40 = *((unsigned int *)t36);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t38);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB20;

LAB17:    if (t48 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t14) = 1;

LAB20:    memset(t52, 0, 8);
    t53 = (t14 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t14);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t53) != 0)
        goto LAB23;

LAB24:    t61 = *((unsigned int *)t7);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t7 + 4);
    t65 = (t52 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB19:    t51 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t52) = 1;
    goto LAB24;

LAB23:    t59 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB24;

LAB25:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t7 + 4);
    t75 = (t52 + 4);
    t76 = *((unsigned int *)t7);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
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
    goto LAB27;

LAB28:    xsi_set_current_line(104, ng0);

LAB31:    xsi_set_current_line(105, ng0);
    t98 = ((char*)((ng3)));
    t99 = (t0 + 5288);
    xsi_vlogvar_assign_value(t99, t98, 0, 0, 1);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = (t0 + 5128);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4968);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 4808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 12, t5, 32);
    t15 = (t0 + 4808);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 12);
    goto LAB30;

LAB34:    t15 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB35;

LAB36:    *((unsigned int *)t7) = 1;
    goto LAB39;

LAB38:    t23 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB39;

LAB40:    t33 = (t0 + 5288);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng5)));
    memset(t14, 0, 8);
    t37 = (t35 + 4);
    t38 = (t36 + 4);
    t39 = *((unsigned int *)t35);
    t40 = *((unsigned int *)t36);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t38);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB46;

LAB43:    if (t48 != 0)
        goto LAB45;

LAB44:    *((unsigned int *)t14) = 1;

LAB46:    memset(t52, 0, 8);
    t53 = (t14 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t14);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t53) != 0)
        goto LAB49;

LAB50:    t61 = *((unsigned int *)t7);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t7 + 4);
    t65 = (t52 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB51;

LAB52:
LAB53:    goto LAB42;

LAB45:    t51 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB46;

LAB47:    *((unsigned int *)t52) = 1;
    goto LAB50;

LAB49:    t59 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB50;

LAB51:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t7 + 4);
    t75 = (t52 + 4);
    t76 = *((unsigned int *)t7);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
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
    goto LAB53;

LAB54:    xsi_set_current_line(110, ng0);

LAB57:    xsi_set_current_line(111, ng0);
    t98 = ((char*)((ng2)));
    t99 = (t0 + 5288);
    xsi_vlogvar_assign_value(t99, t98, 0, 0, 1);
    goto LAB56;

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

LAB0:    t1 = (t0 + 6952U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng4)));
    t3 = (t0 + 7416);
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


extern void work_m_00000000001027408532_3566486687_init()
{
	static char *pe[] = {(void *)Cont_34_0,(void *)Initial_88_1,(void *)Always_99_2,(void *)implSig1_execute};
	xsi_register_didat("work_m_00000000001027408532_3566486687", "isim/t_vga_isim_beh.exe.sim/work/m_00000000001027408532_3566486687.didat");
	xsi_register_executes(pe);
}
