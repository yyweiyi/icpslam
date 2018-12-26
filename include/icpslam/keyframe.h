#pragma once

#include <ros/ros.h>

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <slam_3d/pose_graph_g2o.hpp>
#include <g2o/types/slam3d/vertex_se3.h>

#include "utils/pose6DOF.h"

namespace g2o {
  class VertexSE3;
}

template <typename PointType>
class Keyframe {
 public:
  using Ptr = std::shared_ptr<Keyframe>;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  Keyframe(const unsigned long& id) : id_(id), point_cloud_(new pcl::PointCloud<PointType>()) {
    ROS_INFO("New keyframe");
  }

  Keyframe(
      const unsigned long& id, const ros::Time& stamp, const Pose6DOF& pose_in_odom, const typename pcl::PointCloud<PointType>::Ptr& point_cloud)
      : id_(id), stamp_(stamp), pose_in_odom_(pose_in_odom), point_cloud_(point_cloud) {
    ROS_INFO("New keyframe");
  }

//  protected:
  const unsigned long id_;
  ros::Time stamp_;
  Pose6DOF pose_in_odom_;
  g2o::VertexSE3* graph_node_;

  typename pcl::PointCloud<PointType>::Ptr point_cloud_;
};