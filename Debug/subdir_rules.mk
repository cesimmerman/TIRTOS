################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/kernel/tirtos/packages/ti/sysbios/family/arm/m3" --include_path="C:/Users/simmermance/Documents/2020 Q2/Adv. Embedded Systems/Libs/MSOE_LIB/MSOE_LIB" --include_path="C:/ti/ccs920/ccs/ccs_base/arm/include" --include_path="C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs" --include_path="C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source/ti/posix/ccs" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1039044321:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1039044321-inproc

build-1039044321-inproc: ../event.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/ccs920/xdctools_3_60_01_27_core/xs" --xdcpath="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source;C:/ti/simplelink_msp432p4_sdk_3_40_01_02/kernel/tirtos/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.msp432:MSP432P401R -r release -c "C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path=\"C:/ti/simplelink_msp432p4_sdk_3_40_01_02/kernel/tirtos/packages/ti/sysbios/family/arm/m3\" --include_path=\"C:/Users/simmermance/Documents/2020 Q2/Adv. Embedded Systems/Libs/MSOE_LIB/MSOE_LIB\" --include_path=\"C:/ti/ccs920/ccs/ccs_base/arm/include\" --include_path=\"C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs\" --include_path=\"C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs/Debug\" --include_path=\"C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source\" --include_path=\"C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include\" --include_path=\"C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source/ti/posix/ccs\" --include_path=\"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include\" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on  " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1039044321 ../event.cfg
configPkg/compiler.opt: build-1039044321
configPkg/: build-1039044321

build-392225425:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-392225425-inproc

build-392225425-inproc: ../event.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs920/ccs/utils/sysconfig/sysconfig_cli.bat" -s "C:/ti/simplelink_msp432p4_sdk_3_40_01_02/.metadata/product.json" -o "syscfg" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-392225425 ../event.syscfg
syscfg/ti_drivers_config.h: build-392225425
syscfg/syscfg_c.rov.xs: build-392225425
syscfg/: build-392225425

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/kernel/tirtos/packages/ti/sysbios/family/arm/m3" --include_path="C:/Users/simmermance/Documents/2020 Q2/Adv. Embedded Systems/Libs/MSOE_LIB/MSOE_LIB" --include_path="C:/ti/ccs920/ccs/ccs_base/arm/include" --include_path="C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs" --include_path="C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_01_02/source/ti/posix/ccs" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/simmermance/Documents/Repos/event_MSP_EXP432P401R_tirtos_ccs/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


