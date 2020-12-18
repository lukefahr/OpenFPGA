#ifndef FABRIC_GLOBAL_PORT_INFO_UTILS_H
#define FABRIC_GLOBAL_PORT_INFO_UTILS_H

/********************************************************************
 * Include header files that are required by function declaration
 *******************************************************************/
#include <vector>
#include "fabric_global_port_info.h"

/********************************************************************
 * Function declaration
 *******************************************************************/

/* begin namespace openfpga */
namespace openfpga {

std::vector<FabricGlobalPortId> find_fabric_global_programming_reset_ports(const FabricGlobalPortInfo& fabric_global_port_info);

std::vector<FabricGlobalPortId> find_fabric_global_programming_set_ports(const FabricGlobalPortInfo& fabric_global_port_info);

} /* end namespace openfpga */

#endif
