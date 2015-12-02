
# PlanAhead Launch Script for Post PAR Floorplanning, created by Project Navigator

create_project -name ZPC -dir "F:/Workspace/ASM/Hard/ZPC/planAhead_run_5" -part xc3s500efg320-4
set srcset [get_property srcset [current_run -impl]]
set_property design_mode GateLvl $srcset
set_property edif_top_file "F:/Workspace/ASM/Hard/ZPC/PC.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {F:/Workspace/ASM/Hard/ZPC} {ipcore_dir} }
add_files [list {ipcore_dir/BB.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/CM.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/halfWordBank.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/VM.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "F:/Workspace/ASM/Hard/VGA/ucf.ucf" [current_fileset -constrset]
add_files [list {F:/Workspace/ASM/Hard/VGA/ucf.ucf}] -fileset [get_property constrset [current_run]]
link_design
read_xdl -file "F:/Workspace/ASM/Hard/ZPC/PC.ncd"
if {[catch {read_twx -name results_1 -file "F:/Workspace/ASM/Hard/ZPC/PC.twx"} eInfo]} {
   puts "WARNING: there was a problem importing \"F:/Workspace/ASM/Hard/ZPC/PC.twx\": $eInfo"
}
