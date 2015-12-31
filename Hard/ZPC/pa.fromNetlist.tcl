
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name ZPC -dir "F:/Workspace/ASM/Hard/ZPC/planAhead_run_1" -part xc3s500efg320-4
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "F:/Workspace/ASM/Hard/ZPC/PC.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {F:/Workspace/ASM/Hard/ZPC} {ipcore_dir} {../DISK/ipcore_dir} }
add_files [list {ipcore_dir/BB.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/CM.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/halfWordBank.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/LL.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/VM.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../DISK/ipcore_dir/DB.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "F:/Workspace/ASM/Hard/VGA/ucf.ucf" [current_fileset -constrset]
add_files [list {F:/Workspace/ASM/Hard/VGA/ucf.ucf}] -fileset [get_property constrset [current_run]]
link_design
