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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    xilinxcorelib_ver_m_00000000001358910285_1290601285_init();
    xilinxcorelib_ver_m_00000000001687936702_0135474683_init();
    xilinxcorelib_ver_m_00000000002621774987_3467082781_init();
    xilinxcorelib_ver_m_00000000001603977570_0301627302_init();
    work_m_00000000000403262735_1756065721_init();
    work_m_00000000000000996807_1368203981_init();
    work_m_00000000001677347076_1012534527_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001677347076_1012534527");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
