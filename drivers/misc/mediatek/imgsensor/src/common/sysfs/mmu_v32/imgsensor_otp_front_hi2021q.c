#include "imgsensor_otp_front_hi2021q.h"

#define FRONT_HI2021Q_MAX_CAL_SIZE (0xC7C)
#define FRONT_HI2021Q_HEADER_CHECKSUM_LEN (0x0057 + 0x1)
#define FRONT_HI2021Q_SENSOR_CHECKSUM_LEN (0x0467 - 0x005C + 0x1)
#define FRONT_HI2021Q_MODULE_DATA_CHECKSUM_LEN (0x0893 - 0x046C + 0x1)
#define FRONT_HI2021Q_CONVERTED_MAX_CAL_SIZE (0x0FD7)
#define FRONT_HI2021Q_CONVERTED_AWB_CHECKSUM_LEN (0x048F - 0x0484 + 0x1)
#define FRONT_HI2021Q_CONVERTED_LSC_CHECKSUM_LEN (0x0BEF - 0x0494 + 0x1)

const struct rom_converted_cal_addr front_hi2021q_converted_cal_addr = {
	.rom_awb_cal_data_start_addr     = 0x0484,
	.rom_awb_checksum_addr           = 0x0490,
	.rom_awb_checksum_len            = (FRONT_HI2021Q_CONVERTED_AWB_CHECKSUM_LEN),
	.rom_shading_cal_data_start_addr = 0x0494,
	.rom_shading_checksum_addr       = 0x0BF0,
	.rom_shading_checksum_len        = (FRONT_HI2021Q_CONVERTED_LSC_CHECKSUM_LEN),
};

const struct imgsensor_vendor_rom_addr front_hi2021q_cal_addr = {
	/* Set '-1' if not used */

	.camera_module_es_version               = 'A',
	.cal_map_es_version                     = '1',
	.rom_max_cal_size                       = FRONT_HI2021Q_MAX_CAL_SIZE,

	.rom_header_cal_data_start_addr         = 0x00,
	.rom_header_main_module_info_start_addr = 0x12,
	.rom_header_cal_map_ver_start_addr      = 0x1E,
	.rom_header_project_name_start_addr     = 0x26,
	.rom_header_module_id_addr              = 0x36,
	.rom_header_main_sensor_id_addr         = 0x40,

	.rom_header_sub_module_info_start_addr  = -1,
	.rom_header_sub_sensor_id_addr          = -1,

	.rom_header_main_header_start_addr      = -1,
	.rom_header_main_header_end_addr        = -1,
	.rom_header_main_oem_start_addr         = -1, /* AF start address */
	.rom_header_main_oem_end_addr           = -1, /* AF end address */
	.rom_header_main_awb_start_addr         = -1,
	.rom_header_main_awb_end_addr           = -1,
	.rom_header_main_shading_start_addr     = -1,
	.rom_header_main_shading_end_addr       = -1,
	.rom_header_main_sensor_cal_start_addr  = 0x00,
	.rom_header_main_sensor_cal_end_addr    = 0x04,
	.rom_header_dual_cal_start_addr         = -1,
	.rom_header_dual_cal_end_addr           = -1,
	.rom_header_pdaf_cal_start_addr         = -1,
	.rom_header_pdaf_cal_end_addr           = -1,
	.rom_header_ois_cal_start_addr          = -1,
	.rom_header_ois_cal_end_addr            = -1,

	.rom_header_sub_oem_start_addr          = -1,
	.rom_header_sub_oem_end_addr            = -1,
	.rom_header_sub_awb_start_addr          = -1,
	.rom_header_sub_awb_end_addr            = -1,
	.rom_header_sub_shading_start_addr      = -1,
	.rom_header_sub_shading_end_addr        = -1,

	.rom_header_main_mtf_data_addr          = -1,
	.rom_header_sub_mtf_data_addr           = -1,

	.rom_header_checksum_addr               = 0x0058,
	.rom_header_checksum_len                = (FRONT_HI2021Q_HEADER_CHECKSUM_LEN),

	.rom_module_cal_data_start_addr         = 0x046C,
	.rom_module_module_info_start_addr      = -1,
	.rom_module_checksum_addr               = 0x0894,
	.rom_module_checksum_len                = (FRONT_HI2021Q_MODULE_DATA_CHECKSUM_LEN),

	.rom_oem_af_inf_position_addr           = -1,
	.rom_oem_af_macro_position_addr         = -1,
	.rom_oem_module_info_start_addr         = -1,
	.rom_oem_checksum_addr                  = -1,
	.rom_oem_checksum_len                   = -1,

	.rom_awb_cal_data_start_addr            = 0x0484,
	.rom_awb_module_info_start_addr         = -1,
	.rom_awb_checksum_addr                  = -1,
	.rom_awb_checksum_len                   = -1,

	.rom_shading_cal_data_start_addr        = 0x048F,
	.rom_shading_module_info_start_addr     = -1,
	.rom_shading_checksum_addr              = -1,
	.rom_shading_checksum_len               = -1,

	.rom_sensor_cal_data_start_addr         = 0x005C,
	.rom_sensor_cal_module_info_start_addr  = -1,
	.rom_sensor_cal_checksum_addr           = 0x0468,
	.rom_sensor_cal_checksum_len            = FRONT_HI2021Q_SENSOR_CHECKSUM_LEN,

	.rom_dual_module_info_start_addr        = -1,
	.rom_dual_checksum_addr                 = -1,
	.rom_dual_checksum_len                  = -1,

	.rom_pdaf_module_info_start_addr        = -1,
	.rom_pdaf_checksum_addr                 = -1,
	.rom_pdaf_checksum_len                  = -1,

	.rom_ois_checksum_addr                  = -1,
	.rom_ois_checksum_len                   = -1,

	.rom_sub_oem_af_inf_position_addr       = -1,
	.rom_sub_oem_af_macro_position_addr     = -1,
	.rom_sub_oem_module_info_start_addr     = -1,
	.rom_sub_oem_checksum_addr              = -1,
	.rom_sub_oem_checksum_len               = -1,

	.rom_sub_awb_module_info_start_addr     = -1,
	.rom_sub_awb_checksum_addr              = -1,
	.rom_sub_awb_checksum_len               = -1,

	.rom_sub_shading_module_info_start_addr = -1,
	.rom_sub_shading_checksum_addr          = -1,
	.rom_sub_shading_checksum_len           = -1,

	.rom_dual_cal_data2_start_addr          = -1,
	.rom_dual_cal_data2_size                = -1,
	.rom_dual_tilt_x_addr                   = -1,
	.rom_dual_tilt_y_addr                   = -1,
	.rom_dual_tilt_z_addr                   = -1,
	.rom_dual_tilt_sx_addr                  = -1,
	.rom_dual_tilt_sy_addr                  = -1,
	.rom_dual_tilt_range_addr               = -1,
	.rom_dual_tilt_max_err_addr             = -1,
	.rom_dual_tilt_avg_err_addr             = -1,
	.rom_dual_tilt_dll_version_addr         = -1,
	.rom_dual_shift_x_addr                  = -1,
	.rom_dual_shift_y_addr                  = -1,

	.extend_cal_addr                        = NULL,

	.converted_cal_addr                     = &front_hi2021q_converted_cal_addr,
	.rom_converted_max_cal_size             = FRONT_HI2021Q_CONVERTED_MAX_CAL_SIZE,

	.sensor_maker                           = "HYNIX",
	.sensor_name                            = "HI2021Q",
	.sub_sensor_maker                       = "",
	.sub_sensor_name                        = "",

	.bayerformat                            = SENSOR_OUTPUT_FORMAT_RAW_Gr,
};
