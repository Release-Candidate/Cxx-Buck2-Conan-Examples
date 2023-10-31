// SPDX-FileCopyrightText:  Copyright 2023 Roland Csaszar
// SPDX-License-Identifier: MIT
//
// Project:  c++-test
// File:     lib.cpp
// Date:     31.Oct.2023
//
// ==============================================================================

#include <format>

#include "lib.hpp"

auto foo(int i) -> std::string {
  return std::format("{}", i);
}
