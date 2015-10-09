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
    work_m_00000000004265130494_4217414517_init();
    work_m_00000000004173762286_0365506110_init();
    work_m_00000000000596992369_1106866723_init();
    work_m_00000000003319913314_3887546801_init();
    xilinxcorelib_ver_m_00000000001358910285_2212199708_init();
    xilinxcorelib_ver_m_00000000001687936702_0020666995_init();
    xilinxcorelib_ver_m_00000000000277421008_3303619959_init();
    xilinxcorelib_ver_m_00000000001603977570_0713773647_init();
    work_m_00000000003617559063_3602556285_init();
    xilinxcorelib_ver_m_00000000001358910285_3299116533_init();
    xilinxcorelib_ver_m_00000000001687936702_2735655753_init();
    xilinxcorelib_ver_m_00000000000277421008_2710995104_init();
    xilinxcorelib_ver_m_00000000001603977570_2523779902_init();
    work_m_00000000002489990758_3775873897_init();
    work_m_00000000000544065368_0584589268_init();
    work_m_00000000001940457414_3566486687_init();
    work_m_00000000000147536186_0544179635_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000000147536186_0544179635");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
