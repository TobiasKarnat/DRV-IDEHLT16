/************************************************************************\
**                                                                      **
**               OS/2(r) Physical Device Driver Libraries               **
**                         for Watcom C/C++ 10                          **
**                                                                      **
**  COPYRIGHT:                                                          **
**                                                                      **
**    (C) Copyright Advanced Gravis Computer Technology Ltd 1994.       **
**        All Rights Reserved.                                          **
**                                                                      **
**  DISCLAIMER OF WARRANTIES:                                           **
**                                                                      **
**    The following [enclosed] code is provided to you "AS IS",         **
**    without warranty of any kind.  You have a royalty-free right to   **
**    use, modify, reproduce and distribute the following code (and/or  **
**    any modified version) provided that you agree that Advanced       **
**    Gravis has no warranty obligations and shall not be liable for    **
**    any damages arising out of your use of this code, even if they    **
**    have been advised of the possibility of such damages.  This       **
**    Copyright statement and Disclaimer of Warranties may not be       **
**    removed.                                                          **
**                                                                      **
\************************************************************************/

/* header.c
 *
 * Device driver header
 *
 * History:
 *
 * Sep 30, 94  David Bollo    Initial version
 * Jul 02, 07  Mike Greene    Modified for Open Watcom
 * Sep 13, 11  Andy Willis    HLT version
 * Sep 21, 14  Tobias Karnat  HLT16 version
 */

#include <devhdr.h>
#include <devreqp.h>

// Ensure that the header is located at the beginning of the driver
#pragma data_seg ("_HEADER", "DATA");

// Declare the device driver header
extern void Strategy();

DEVHEADER DDHeader = {
    FENCE,                                     // Link to next header in chain
    DAW_CHARACTER|DAW_OPENCLOSE|DAW_LEVEL1,    // device attribute word
    Strategy,                                  // Entry point to strategy routine
    0,                                         // Entry point to IDC routine
    {"Idlehlt$"},                              // Device driver name
    0,0,0,0,                                   // Reserved
    CAP_NULL                                   // Capabilities bit strip (for level 3 DDs)
};
