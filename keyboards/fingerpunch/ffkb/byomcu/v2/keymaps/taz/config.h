/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define QUICK_TAP_TERM 120

/*
 * 5-col wrapper for the layout mechanism
 */
#define LAYOUT_ffkb_5col( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     K30, K31, K32, K33, K34,      K35, K36, K37, K38       \
) \
LAYOUT_ffkb( \
KC_NO, K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, KC_NO, \
KC_NO, K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, KC_NO, \
KC_NO, K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, KC_NO, \
          K30, K31, K32, K33,      K34, K35, K36, K37,               \
                              K38                                    \
)
