/* Copyright 2022 W. Alex Ronke, a.k.a. NoPunIn10Did (w.alex.ronke@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define LAYOUT_any( \
	K0100  ,K0101  ,K0110  ,K0111  ,K0120  ,K0121  ,K0130  ,K0131  ,K0140  ,K0141  ,K0150  ,K0151  ,K0160  ,K0161  ,K0170  ,    K0171  ,  \
    K0202      ,K0203  ,K0212  ,K0213  ,K0222  ,K0223  ,K0232  ,K0233  ,K0242  ,K0243  ,K0252  ,K0253  ,K0262  ,K0272      ,    K0273  ,  \
    K0304        ,K0305  ,K0314  ,K0315  ,K0324  ,K0325  ,K0334  ,K0335  ,K0344  ,K0345  ,K0354  ,K0355  ,K0364  ,K0374    ,              \
    K0406    ,K0407  ,K0416  ,K0417  ,K0426  ,K0427  ,K0436  ,K0437  ,K0446  ,K0447  ,K0456  ,K0457  ,K0466  ,K0467    ,K0476  ,          \
    K0508    ,K0509    ,K0518    ,K0529  ,K0538                ,K0548            ,K0549    ,K0559    ,K0568    ,K0569  ,K0578  ,K0579     \
) \
{ \
	{ K0100, K0110, K0120, K0130, K0140, K0150, K0160, K0170 }, \
	{ K0101, K0111, K0121, K0131, K0141, K0151, K0161, K0171 }, \
	{ K0202, K0212, K0222, K0232, K0242, K0252, K0262, K0272 }, \
	{ K0203, K0213, K0223, K0233, K0243, K0253, KC_NO, K0273 }, \
	{ K0304, K0314, K0324, K0334, K0344, K0354, K0364, K0374 }, \
	{ K0305, K0315, K0325, K0335, K0345, K0355, KC_NO, KC_NO }, \
	{ K0406, K0416, K0426, K0436, K0446, K0456, K0466, K0476 }, \
	{ K0407, K0417, K0427, K0437, K0447, K0457, K0467, KC_NO }, \
	{ K0508, K0518, KC_NO, K0538, K0548, KC_NO, K0568, K0578 }, \
	{ K0509, KC_NO, K0529, KC_NO, K0549, K0559, K0569, K0579 }
}


