#include <ctime>
#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>
#include <Eigen/Core>

#include "nanoflann_eigen/nanoflann_eigen.h"

using namespace std;
using namespace nanoflann;

TEST(KDTreeEigenInterface, KNNSearch)
{
	PointCloud<double> cloud;
	KDTree3d index(3, cloud, KDTreeSingleIndexAdaptorParams(10));

	cloud.pts.resize(6);
	cloud.pts[0] << 0.0, 0.0, 0.0;
	cloud.pts[1] << 0.0, 0.1, 0.1;
	cloud.pts[2] << 0.0, 0.2, 0.2;
	cloud.pts[3] << 0.0, 0.3, 0.3;
	cloud.pts[4] << 0.0, 0.4, 0.4;
	cloud.pts[5] << 0.0, 0.5, 0.5;

	Vector3d query_pt{ 0.5, 0.5, 0.5 };

	index.addPoints(0, 3);

	const size_t num_results = 1;
	size_t ret_index;
	double out_dist_sqr;
	nanoflann::KNNResultSet<double> resultSet(num_results);
	resultSet.init(&ret_index, &out_dist_sqr );
	index.findNeighbors(resultSet, query_pt.data(), nanoflann::SearchParams(10));
	EXPECT_EQ(ret_index, 3);

	index.addPoints(4, 5);
	index.findNeighbors(resultSet, query_pt.data(), nanoflann::SearchParams(10));
	EXPECT_EQ(ret_index, 5);

	cloud.pts.push_back(Vector3d{0.3, 0.5, 0.5});
	index.addPoints(6, 6);
	index.findNeighbors(resultSet, query_pt.data(), nanoflann::SearchParams(10));
	EXPECT_EQ(ret_index, 6);
}
