
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name ZPC -dir "F:/Workspace/ASM/Hard/ZPC/planAhead_run_1" -part xc3s500efg320-4
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "F:/Workspace/ASM/Hard/VGA/ucf.ucf" [current_fileset -constrset]
add_files [list {ipcore_dir/CM.ngc}]
add_files [list {ipcore_dir/BB.ngc}]
add_files [list {ipcore_dir/VM.ngc}]
set hdlfile [add_files [list {ipcore_dir/CM.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {ipcore_dir/VM.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../VGA/char.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {ipcore_dir/BB.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../TTY/VGA.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../TTY/KB.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../CPU/Ctrl.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../TTY/tty.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Mem/Mem16.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../CPU/CPU.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {PC.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top PC $srcset
add_files [list {F:/Workspace/ASM/Hard/VGA/ucf.ucf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/BB.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/CM.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/halfWordBank.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/VM.ncf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s500efg320-4
