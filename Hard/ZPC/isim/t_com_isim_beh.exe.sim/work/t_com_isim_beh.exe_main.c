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
    xilinxcorelib_ver_m_00000000001358910285_3420851225_init();
    xilinxcorelib_ver_m_00000000001687936702_3869861341_init();
    xilinxcorelib_ver_m_00000000002621774987_1091970388_init();
    xilinxcorelib_ver_m_00000000001603977570_2464799163_init();
    work_m_00000000000403262735_1056032831_init();
    work_m_00000000003798952462_1274111026_init();
    work_m_00000000004244751496_1122008917_init();
    work_m_00000000003798952462_2950558994_init();
    work_m_00000000000564455498_3869746947_init();
    work_m_00000000001717073815_0039860855_init();
    work_m_00000000001226107883_3425421695_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001226107883_3425421695");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
