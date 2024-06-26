/** @file
  This file describes the contents of the ACPI Multiple APIC Description
  Table (MADT).
  To make changes to the MADT, it is necessary to update the count for the
  APIC structure being updated, and to modify table found in Madt.c.

  Copyright (c) 2024, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _MADT_H_
#define _MADT_H_


#include <IndustryStandard/Acpi.h>
#include "AcpiTablePlatform.h"


#define EFI_ACPI_OEM_MADT_REVISION 0x00000001


//
// Multiple APIC Flags are defined in AcpiX.0.h
//
#define EFI_ACPI_6_3_MULTIPLE_APIC_FLAGS (EFI_ACPI_6_3_PCAT_COMPAT)


#define EFI_ACPI_PROCESSOR_LOCAL_APIC_COUNT           48
#define EFI_ACPI_IO_APIC_COUNT                        1
#define EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT      2
#define EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT  0
#define EFI_ACPI_LOCAL_APIC_NMI_COUNT                 24
#define EFI_ACPI_LOCAL_APIC_ADDRESS_OVERRIDE_COUNT    0
#define EFI_ACPI_IO_SAPIC_COUNT                       0
#define EFI_ACPI_PROCESSOR_LOCAL_SAPIC_COUNT          0
#define EFI_ACPI_PLATFORM_INTERRUPT_SOURCES_COUNT     0
#define EFI_ACPI_PROCESSOR_LOCAL_X2APIC_COUNT         48
#define EFI_ACPI_LOCAL_X2APIC_NMI_COUNT               1


//
// Ensure proper structure formats
//
#pragma pack (1)

//
// ACPI 1.0 Table structure
//
typedef struct {
  EFI_ACPI_1_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER   Header;

#if EFI_ACPI_PROCESSOR_LOCAL_APIC_COUNT > 0
  EFI_ACPI_1_0_PROCESSOR_LOCAL_APIC_STRUCTURE           LocalApic[EFI_ACPI_PROCESSOR_LOCAL_APIC_COUNT];
#endif

#if EFI_ACPI_IO_APIC_COUNT > 0
  EFI_ACPI_1_0_IO_APIC_STRUCTURE                        IoApic[EFI_ACPI_IO_APIC_COUNT];
#endif

#if EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT > 0
  EFI_ACPI_1_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE      Iso[EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT];
#endif

#if EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT > 0
  EFI_ACPI_1_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE  NmiSource[EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT];
#endif

#if EFI_ACPI_LOCAL_APIC_NMI_COUNT > 0
  EFI_ACPI_1_0_LOCAL_APIC_NMI_STRUCTURE                 LocalApicNmi[EFI_ACPI_LOCAL_APIC_NMI_COUNT];
#endif

#if EFI_ACPI_LOCAL_APIC_ADDRESS_OVERRIDE_COUNT > 0
  EFI_ACPI_1_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE    LocalApicOverride[EFI_ACPI_LOCAL_APIC_OVERRIDE_COUNT];
#endif

} EFI_ACPI_1_0_MULTIPLE_APIC_DESCRIPTION_TABLE;

//
// ACPI 2.0 Table structure
//
typedef struct {
  EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER   Header;

#if EFI_ACPI_PROCESSOR_LOCAL_APIC_COUNT > 0
  EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE           LocalApic[EFI_ACPI_PROCESSOR_LOCAL_APIC_COUNT];
#endif

#if EFI_ACPI_IO_APIC_COUNT > 0
  EFI_ACPI_2_0_IO_APIC_STRUCTURE                        IoApic[EFI_ACPI_IO_APIC_COUNT];
#endif

#if EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT > 0
  EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE      Iso[EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT];
#endif

#if EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT > 0
  EFI_ACPI_2_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE  NmiSource[EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT];
#endif

#if EFI_ACPI_LOCAL_APIC_NMI_COUNT > 0
  EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE                 LocalApicNmi[EFI_ACPI_LOCAL_APIC_NMI_COUNT];
#endif

#if EFI_ACPI_LOCAL_APIC_ADDRESS_OVERRIDE_COUNT > 0
  EFI_ACPI_2_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE    LocalApicOverride[EFI_ACPI_LOCAL_APIC_OVERRIDE_COUNT];
#endif

#if EFI_ACPI_IO_SAPIC_COUNT > 0
  EFI_ACPI_2_0_IO_SAPIC_STRUCTURE                       IoSapic[EFI_ACPI_IO_SAPIC_COUNT];
#endif

#if EFI_ACPI_PROCESSOR_LOCAL_SAPIC_COUNT > 0
  EFI_ACPI_2_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE          LocalSapic[EFI_ACPI_PROCESSOR_LOCAL_SAPIC_COUNT];
#endif

#if EFI_ACPI_PLATFORM_INTERRUPT_SOURCES_COUNT > 0
  EFI_ACPI_2_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE     PlatformInterruptSources[EFI_ACPI_PLATFORM_INTERRUPT_SOURCES_COUNT];
#endif

} EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE;

//
// ACPI 6.3 APIC Table structure
//
typedef struct {
  EFI_ACPI_6_3_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER   Header;

#if EFI_ACPI_PROCESSOR_LOCAL_APIC_COUNT  > 0          // Type 0x09
  EFI_ACPI_6_3_PROCESSOR_LOCAL_APIC_STRUCTURE           LocalApic[EFI_ACPI_PROCESSOR_LOCAL_APIC_COUNT];
#endif

#if EFI_ACPI_IO_APIC_COUNT > 0                          // Type 0x01
  EFI_ACPI_6_3_IO_APIC_STRUCTURE                        IoApic[EFI_ACPI_IO_APIC_COUNT];
#endif

#if EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT > 0        // Type 0x02
  EFI_ACPI_6_3_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE      Iso[EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT];
#endif

#if EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT > 0    // Type 0x03
  EFI_ACPI_6_3_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE  NmiSource[EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT];
#endif

#if EFI_ACPI_LOCAL_APIC_NMI_COUNT > 0                 // Type 0x0A
  EFI_ACPI_6_3_LOCAL_APIC_NMI_STRUCTURE                 LocalApicNmi[EFI_ACPI_LOCAL_APIC_NMI_COUNT];
#endif

#if EFI_ACPI_LOCAL_APIC_ADDRESS_OVERRIDE_COUNT > 0      // Type 0x05
  EFI_ACPI_6_3_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE    LocalApicOverride[EFI_ACPI_LOCAL_APIC_OVERRIDE_COUNT];
#endif

#if EFI_ACPI_IO_SAPIC_COUNT > 0                         // Type 0x06
  EFI_ACPI_6_3_IO_SAPIC_STRUCTURE                       IoSapic[EFI_ACPI_IO_SAPIC_COUNT];
#endif

#if EFI_ACPI_PROCESSOR_LOCAL_SAPIC_COUNT > 0            // Type 0x07 : This table changes in madt 2.0
  EFI_ACPI_6_3_PROCESSOR_LOCAL_SAPIC_STRUCTURE          LocalSapic[EFI_ACPI_PROCESSOR_LOCAL_SAPIC_COUNT];
#endif

#if EFI_ACPI_PLATFORM_INTERRUPT_SOURCES_COUNT > 0       // Type 0x08
  EFI_ACPI_6_3_PLATFORM_INTERRUPT_SOURCES_STRUCTURE     PlatformInterruptSources[EFI_ACPI_PLATFORM_INTERRUPT_SOURCES_COUNT];
#endif

} EFI_ACPI_6_3_MULTIPLE_APIC_DESCRIPTION_TABLE;


//
// ACPI 6.3 X2APIC Table structure
//
typedef struct {
  EFI_ACPI_6_3_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER   Header;

#if EFI_ACPI_PROCESSOR_LOCAL_X2APIC_COUNT  > 0          // Type 0x09
  EFI_ACPI_6_3_PROCESSOR_LOCAL_X2APIC_STRUCTURE         LocalX2Apic[EFI_ACPI_PROCESSOR_LOCAL_X2APIC_COUNT];
#endif

#if EFI_ACPI_IO_APIC_COUNT > 0                          // Type 0x01
  EFI_ACPI_6_3_IO_APIC_STRUCTURE                        IoApic[EFI_ACPI_IO_APIC_COUNT];
#endif

#if EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT > 0        // Type 0x02
  EFI_ACPI_6_3_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE      Iso[EFI_ACPI_INTERRUPT_SOURCE_OVERRIDE_COUNT];
#endif

#if EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT > 0    // Type 0x03
  EFI_ACPI_6_3_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE  NmiSource[EFI_ACPI_NON_MASKABLE_INTERRUPT_SOURCE_COUNT];
#endif

#if EFI_ACPI_LOCAL_X2APIC_NMI_COUNT > 0                 // Type 0x0A
  EFI_ACPI_6_3_LOCAL_X2APIC_NMI_STRUCTURE               X2ApicNmi[EFI_ACPI_LOCAL_X2APIC_NMI_COUNT];
#endif

#if EFI_ACPI_LOCAL_APIC_ADDRESS_OVERRIDE_COUNT > 0      // Type 0x05
  EFI_ACPI_6_3_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE    LocalApicOverride[EFI_ACPI_LOCAL_APIC_OVERRIDE_COUNT];
#endif

#if EFI_ACPI_IO_SAPIC_COUNT > 0                         // Type 0x06
  EFI_ACPI_6_3_IO_SAPIC_STRUCTURE                       IoSapic[EFI_ACPI_IO_SAPIC_COUNT];
#endif

#if EFI_ACPI_PROCESSOR_LOCAL_SAPIC_COUNT > 0            // Type 0x07 : This table changes in madt 2.0
  EFI_ACPI_6_3_PROCESSOR_LOCAL_SAPIC_STRUCTURE          LocalSapic[EFI_ACPI_PROCESSOR_LOCAL_SAPIC_COUNT];
#endif

#if EFI_ACPI_PLATFORM_INTERRUPT_SOURCES_COUNT > 0       // Type 0x08
  EFI_ACPI_6_3_PLATFORM_INTERRUPT_SOURCES_STRUCTURE     PlatformInterruptSources[EFI_ACPI_PLATFORM_INTERRUPT_SOURCES_COUNT];
#endif

} EFI_ACPI_6_3_MULTIPLE_X2APIC_DESCRIPTION_TABLE;

#pragma pack ()

#endif
