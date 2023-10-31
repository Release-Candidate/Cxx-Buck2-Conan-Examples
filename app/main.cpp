// SPDX-FileCopyrightText:  Copyright 2023 Roland Csaszar
// SPDX-License-Identifier: AGPL-3.0-or-later
//
// Project:  c++-test
// File:     main.cpp
// Date:     30.Oct.2023
//
// ==============================================================================

#include <cstdlib>
#include <iostream>

auto main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) -> int {
  std::cout << "HI" << '\n';

  int* a = static_cast<int*>(malloc(5));

  return EXIT_SUCCESS;
}
