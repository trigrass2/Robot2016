#ifndef ROVERPATH_H
#define ROVERPATH_H

// pcl
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

// Eigen
#include <Eigen/Dense> 

// Costmap_2d
#include <costmap_2d/layer.h>
#include <costmap_2d/costmap_2d_ros.h>
using namespace Eigen;

struct PATH_COST{
	float Lethal_cost;
	float Travel_cost;
	float Inf_cost;
	bool collision;	
};
struct CELL{
	unsigned int x;
	unsigned int y;
	unsigned char c;
};

class RoverPathClass
{
	public:
		
	RoverPathClass(double b_,int sample_, costmap_2d::Costmap2D* grid_);
	
	void set_path_params(double Travel_cost_inc_,double Lethal_cost_inc_,double Inf_cost_inc_);
	
	void set_pso_params(double pso_inertia_in,double c_1_in,double c_2_in,double Goal_gain_in,double Cost_gain_in,double Speed_gain_in,int particle_no_,int iteration_);
	
	void set_pso_params_default();
	
	void update_costmap(costmap_2d::Costmap2D* grid_);
	
	void traj_to_cloud(MatrixXf tra);
	
	pcl::PointCloud<pcl::PointXYZ> get_path_trace_cloud();
	
	PATH_COST Cost_of_path(MatrixXf path, costmap_2d::Costmap2D* grid);
	
	MatrixXf Rover_vw(VectorXf V_input, VectorXf Omega_input, double b, double Ts,Vector3f x_0,Vector3f x_dot_0 , int sample, Vector3f x_dot_f);
	
	MatrixXf PSO_path_finder(Vector3f Goal,float D,Vector2f V_curr_c,VectorXf output, bool solution_found);
	
	protected:
	
	costmap_2d::Costmap2D* master_grid_;
	//RoverSim params
	double Rover_b;
	int sample;
	
	pcl::PointCloud<pcl::PointXYZ> path_trace_pcl;	
	
	//PSO params
	double pso_inertia;
	double c_1;
	double c_2;
	double Goal_gain;
	double Cost_gain;
	double Speed_gain;
	int particle_no;
  	int iteration;
  	double Travel_cost_inc;
	double Lethal_cost_inc;
	double Inf_cost_inc;
  	
  	
};
#endif
