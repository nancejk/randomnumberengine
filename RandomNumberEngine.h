#ifndef BOOST_RANDOM_LIB
#define BOOST_RANDOM_LIB
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_on_sphere.hpp>
#include <vector>
#include <ctime>

class RandomNumberEngine
{
private:
	static boost::mt19937 fRNG;

public:
	//The arguments to the GaussianRandomReal method are the mean and variance of the sample you wish to draw from.
	const double GetGaussianRandomReal(double, double);
	//The arguments to the UniformRandomReal method are the min and max of the distribution.
	const double GetUniformRandomReal(double, double);
	//The argument to the SphericalSurfaceRandomReal method is the dimension (mathematically) of the sphere.  By default, it is two.
	const std::vector<double> GetSphericalSurfaceRandomReal(unsigned);
};

#endif