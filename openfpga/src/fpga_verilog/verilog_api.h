#ifndef VERILOG_API_H 
#define VERILOG_API_H 

/********************************************************************
 * Include header files that are required by function declaration
 *******************************************************************/

#include <string>
#include <vector>
#include "mux_library.h"
#include "decoder_library.h"
#include "circuit_library.h"
#include "config_protocol.h"
#include "vpr_context.h"
#include "vpr_device_annotation.h"
#include "device_rr_gsb.h"
#include "netlist_manager.h"
#include "module_manager.h"
#include "bitstream_manager.h"
#include "fabric_bitstream.h"
#include "simulation_setting.h"
#include "io_location_map.h"
#include "fabric_global_port_info.h"
#include "vpr_netlist_annotation.h"
#include "fabric_verilog_options.h"
#include "verilog_testbench_options.h"

/********************************************************************
 * Function declaration
 *******************************************************************/

/* begin namespace openfpga */
namespace openfpga {

void fpga_fabric_verilog(ModuleManager& module_manager,
                         NetlistManager& netlist_manager,
                         const CircuitLibrary& circuit_lib,
                         const MuxLibrary& mux_lib,
                         const DecoderLibrary& decoder_lib,
                         const DeviceContext& device_ctx, 
                         const VprDeviceAnnotation& device_annotation, 
                         const DeviceRRGSB& device_rr_gsb,
                         const FabricVerilogOption& options);

void fpga_verilog_testbench(const ModuleManager& module_manager,
                            const BitstreamManager& bitstream_manager, 
                            const FabricBitstream& fabric_bitstream, 
                            const AtomContext& atom_ctx, 
                            const PlacementContext& place_ctx, 
                            const IoLocationMap& io_location_map,
                            const FabricGlobalPortInfo &fabric_global_port_info,
                            const VprNetlistAnnotation& netlist_annotation, 
                            const CircuitLibrary& circuit_lib,
                            const SimulationSetting& simulation_parameters,
                            const ConfigProtocol& config_protocol,
                            const VerilogTestbenchOption& options);


} /* end namespace openfpga */

#endif
