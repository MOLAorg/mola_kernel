/* -------------------------------------------------------------------------
 *   A Modular Optimization framework for Localization and mApping  (MOLA)
 * Copyright (C) 2018-2019 Jose Luis Blanco, University of Almeria
 * See LICENSE for license information.
 * ------------------------------------------------------------------------- */
/**
 * @file   RelDynPose3KF.h
 * @brief
 * @author Jose Luis Blanco Claraco
 * @date   Jan 08, 2019
 */
#pragma once

#include <mola-kernel/entities/EntityRelativeBase.h>
#include <mola-kernel/entities/KeyFrameBase.h>
#include <mrpt/math/lightweight_geom_data.h>

namespace mola
{
/** A relative "dynamic" pose: SE(3) pose + velocity vector.
 * Both the pose and the velocity vector are given in the frame of the base KF.
 * This entity is also a key-frame.
 * \ingroup mola_kernel_grp
 */
class RelDynPose3KF : public EntityRelativeBase, public KeyFrameBase
{
   public:
    /** The up-to-date value of this entity. */
    mrpt::math::TPose3D  relpose_value;
    mrpt::math::TTwist3D twist_value;
};

}  // namespace mola