/*
 * Copyright (C) 2026 EternalModz
 *
 * SPDX-License-Identifier: AGPL-3.0-only
 *
 * Licensed under the GNU Affero General Public License v3.0 only.
 * See LICENSE for the complete license terms.
 *
 * Additional terms permitted under AGPL-3.0 Section 7 apply.
 * See LICENSES/AGPL-ADDITIONAL-TERMS.txt.
 */

// Toggle invis (this might be host-only)
void ToggleInvisibility(bool toggle) 
{
    if (toggle) {
        // Enable: Force setInvisible to always set status flag for invisibility (true)
        *(int*)0x00E22164 = 0x38600001; // li r3, 1 (return 1, making the player invisible) 
        *(int*)0x00E22168 = 0x4E800020; // blr (return)
    } 
    else {
        // Disable: Restore original function behavior (player visibility toggles normally)
        *(int*)0x00E22164 = 0x7C0802A6; // Original function prologue
        *(int*)0x00E22168 = 0x9381000C; // Original instruction
    }
}

// Disable glide damage
void ToggleGlideCollisionDamage(bool toggle) 
{
    if (toggle) {
        // Enable: Force SetGlideCollisionDamage to always set 0 (no damage)
        *(int*)0x00E22380 = 0x39800000; // li r12, 0 (force collision damage to always be 0)
        *(int*)0x00E22384 = 0x4E800020; // blr (return)
    } 
    else {
        // Disable: Restore original function behavior (damage works normally)
        *(int*)0x00E22380 = 0x98082011; // Original instruction (store a2 into result+2065)
        *(int*)0x00E22384 = 0x38600001; // Original return behavior
    }
}
