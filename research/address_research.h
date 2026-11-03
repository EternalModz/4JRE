/*
 * Copyright (C) 2026 EternalModz
 * Copyright applies to original contributions by EternalModz.
 *
 * SPDX-License-Identifier: AGPL-3.0-only
 *
 * Licensed under the GNU Affero General Public License v3.0 only.
 * See LICENSE for the complete license terms.
 *
 * Additional terms permitted under AGPL-3.0 Section 7 apply.
 * See LICENSES/AGPL-ADDITIONAL-TERMS.txt.
 *
 * Third-party research, symbols, and contributions are credited in CREDITS.md.
 */

// NOTICE
// This file contains ongoing Minecraft reverse-engineering research and experimental work.
// Its contents may include original research by EternalModz as well as information derived
// from or informed by third-party research and reverse-engineering resources.
//
// Third-party research, symbols, and contributions are documented in the repository credits.
// Attribution for specific findings should be preserved in accordance with in accordance with the applicable source.
//
// This file is a work in progress and may contain incomplete, inaccurate, or non-functional
// information. Nothing should be considered final or verified unless explicitly stated otherwise.

#pragma once
#include <cstdint>

namespace address_research
{
    namespace voting
    {
        // ZTI31PercentagePlayersVotedCondition
        inline constexpr std::uintptr_t PercentagePlayersVotedCondition_RTTI = 0x00823554;
    }

    namespace anvil
    {
        // AnvilBlock::Anvil::Anvil(Level*, BlockPos const&)
        inline constexpr std::uintptr_t Constructor = 0x0001C5C8;
    }
}