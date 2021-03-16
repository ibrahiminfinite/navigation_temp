/**
 * Author : V Mohammed Ibrahim 
 * Based on the paper, " Approaches for Heuristically Biasiing RRT Growth" (Chris Urmson and Reid Simmons)
 * */

#include <ros/ros.h>
#include "sampler/sampler_node.h"
#include "kdtree/kdtree.h"
#include "graph/graph_node.h"

auto kd = kd_create(3);
auto g = graph::Graph();

namespace rrt
{
// Returns a random state x_rand
Vector3 random_state(Vector3 minvals, Vector3 maxvals);

// Returns the nearest node in tree (x_near) to sampled node 
Vector3 nearest_neighbour(Vector3 x_rand); 


Vector3Array select_node(Vector3 minvals, Vector3 maxvals);



// Generate and action u_new from x_near to x_rand to reach x_new, return false if u_new is not excecutable
Vector3 new_node(Vector3 x_rand, Vector3 x_near);


void extend(Vector3 x_rand, Vector3 x_near);

void clear_tree();

void init_rrt(Vector3 x_init);

void step_rrt(Vector3 mins, Vector3 maxs);
}