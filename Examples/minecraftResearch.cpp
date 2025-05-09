// NOTICE
// This file is dedicated to research and experimentation related to Minecraft.
// Please note that the contents of this file are a work in progress and may not function as intended. 
// It is intended solely for experimental purposes and research. 
// Nothing in this file should be considered final unless explicitly stated otherwise.
// Contributions are welcome, but please ensure proper credit is given if you use or reference any part of this work.

// New options (WIP)

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
