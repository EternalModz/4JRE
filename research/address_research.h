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

    namespace font
    {
        // sub_7100695888 -> Font::isCharacterSupported
        inline constexpr std::uintptr_t IsCharacterSupported = 0x00695888;

        // sub_71006958DC -> Font::mapCharacterToGlyphIndex
        inline constexpr std::uintptr_t MapCharacterToGlyphIndex = 0x006958DC;
    }

    namespace tooltips
    {
        // sub_710054E4A4 -> UIComponent_Tooltips::updateTooltipSlot
        inline constexpr std::uintptr_t UpdateTooltipSlot = 0x0054E4A4;

        // sub_710040CFE0 -> FJ_ToolTip::setControllerActions
        inline constexpr std::uintptr_t SetControllerActions = 0x0040CFE0;
    }
    
    namespace leaf_styles
    {
        // Leaf styles
        inline constexpr std::uintptr_t Styles = 0x00095770;
    }

    namespace main_menu
    {
        // Main menu buttons
        inline constexpr std::uintptr_t Buttons = 0x0089194C;

        // sub_F925F8
        inline constexpr std::uintptr_t Unknown_F925F8 = 0x00F925F8;
    }

    namespace ui_sizing
    {
        // UI sizing - potentially useful for Bedrock-style buttons, I gotta confirm what these do later.
        inline constexpr std::uintptr_t Sizing1 = 0x00890B14;
        inline constexpr std::uintptr_t Sizing2 = 0x00890B24;
        inline constexpr std::uintptr_t Sizing3 = 0x00890B1C;
        inline constexpr std::uintptr_t Sizing4 = 0x00890B2C;
    }
}