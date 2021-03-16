/**
 * This header provides the functions for uniform sampling points in 3D space
 * Authored by : V Mohammed Ibrahim
 * Date : 15-03-2021
 * */

#ifndef SAMPLER_NODE_H
#define SAMPLER_NODE_H


#include <cmath>
#include <chrono>
#include <random>
#include <ros/ros.h>
#include <Eigen/Dense>
#include <boost/foreach.hpp>

typedef std::vector<Eigen::Vector3f> Vector3Array;
typedef Eigen::Vector3f Vector3;

namespace sampler
{

std::random_device device; // Random device for random generator
Vector3 sample;
Vector3 current_pos;
Vector3 bound_offsets;
std::mt19937 generator(device());
std::vector<std::uniform_real_distribution<float>> uniform_pds;

/**
 * Samples within the bounding box set in the config
 * To get samples from ground, the height(z) bounds are set to small values
 * */

Vector3 sample_state(Vector3 min_vals, Vector3 max_vals);

Vector3 sample_state_n(Vector3 min_vals, Vector3 max_vals, int num_samples);


}

#endif