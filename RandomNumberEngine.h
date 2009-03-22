#ifndef BOOST_RANDOM_LIB
#define BOOST_RANDOM_LIB
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
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
	//The arguments to the UniformRandomInt method are the min and max of the distribution.
	const int GetUniformRandomInt(int, int);

	//Members for const correctness.
	const double GetGaussianRandomReal(double, double) const;
	const double GetUniformRandomReal(double, double) const;
	const int GetUniformRandomInt(int, int) const;
};

#endif