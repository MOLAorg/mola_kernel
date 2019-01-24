/* -------------------------------------------------------------------------
 *   A Modular Optimization framework for Localization and mApping  (MOLA)
 * Copyright (C) 2018-2019 Jose Luis Blanco, University of Almeria
 * See LICENSE for license information.
 * ------------------------------------------------------------------------- */
/**
 * @file   factors-common.h
 * @brief  Includes all headers for common types of world-model factors
 * @author Jose Luis Blanco Claraco
 * @date   Jan 08, 2019
 */
#pragma once

#include <memory>

#include <mola-kernel/factors/FactorRelativePose3.h>

namespace mola
{
/** Placeholder for generic entity of user-defined types */
using FactorOther = std::shared_ptr<FactorBase>;

}  // namespace mola