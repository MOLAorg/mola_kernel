/* -------------------------------------------------------------------------
 *   A Modular Optimization framework for Localization and mApping  (MOLA)
 * Copyright (C) 2018-2019 Jose Luis Blanco, University of Almeria
 * See LICENSE for license information.
 * ------------------------------------------------------------------------- */
/**
 * @file   FactorRelativePose3.h
 * @brief
 * @author Jose Luis Blanco Claraco
 * @date   Jan 08, 2019
 */
#pragma once

#include <mola-kernel/factors/FactorBase.h>
#include <mrpt/math/lightweight_geom_data.h>
#include <optional>

// Eigen includes after mrpt's ones:
#include <Eigen/Dense>

namespace mola
{
/**
 *
 * \ingroup mola_kernel_grp
 */
class FactorRelativePose3 : public FactorBase
{
   public:
    /** Creates relative pose constraint of KF `to` as seem from `from`. */
    FactorRelativePose3(
        id_t kf_from, id_t kf_to, const mrpt::math::TPose3D& rel_pose)
        : from_kf_(kf_from), to_kf_{kf_to}, rel_pose_{rel_pose}
    {
    }

    id_t                from_kf_{INVALID_ID}, to_kf_{INVALID_ID};
    mrpt::math::TPose3D rel_pose_;

    /** If provided, it models the covariance of the observation. Order of
     * variables is: rotx roty rotz tx ty tz */
    std::optional<Eigen::Matrix<double, 6, 6>> noise_model_;

    /** Standard deviation of the measurement, in X Y Z. Ignored if noise_model_
     * is provided. */
    double noise_model_diag_xyz_{0.01};
    /** Standard deviation of the measurement, in each rotation angle. Ignored
     * if noise_model_ is provided. */
    double noise_model_diag_rot_{mrpt::DEG2RAD(0.5)};

    std::size_t edge_count() const override { return 2; }
    std::size_t edge_indices(const std::size_t i) const override
    {
        switch (i)
        {
            case 0:
                return from_kf_;
            case 1:
                return to_kf_;
            default:
                THROW_EXCEPTION("Out of bounds");
        }
    }
};

/** Like FactorRelativePose3, but used to impose a constant velocity model
 * between the two keyframes. Can be used for KFs which are very close in time
 * only. Obviously, do not use when adding constraints such as loop closures
 * (!).
 *
 * \ingroup mola_kernel_grp
 */
class FactorRelativePose3ConstVel : public FactorBase
{
   public:
    FactorRelativePose3 relPoseFactor_;

    /** Creates relative pose constraint of KF `to` as seem from `from`. */
    FactorRelativePose3ConstVel(
        id_t kf_from, id_t kf_to, const mrpt::math::TPose3D& rel_pose)
        : relPoseFactor_(kf_from, kf_to, rel_pose)
    {
    }

    std::size_t edge_count() const override
    {
        return relPoseFactor_.edge_count();
    }
    std::size_t edge_indices(const std::size_t i) const override
    {
        return relPoseFactor_.edge_indices(i);
    }
};

}  // namespace mola