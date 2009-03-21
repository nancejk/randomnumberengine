#include "RandomNumberEngine.h"

//Instantiate the random number generator with the current time as a seed.
boost::mt19937 RandomNumberEngine::fRNG(static_cast<unsigned> (std::time(0)) );

const double RandomNumberEngine::GetGaussianRandomReal(double mean, double variance)
{
	//Build a normal probability distribution.
	boost::normal_distribution<double> normal_curve(mean, variance);
	
	//Bind the random number generator to the distribution, which forms a functor.
	boost::variate_generator<boost::mt19937&, boost::normal_distribution<double> > rng_sampler(RandomNumberEngine::fRNG, normal_curve);
	
	return rng_sampler();
}
const double RandomNumberEngine::GetUniformRandomReal(double min, double max)
{
	//Build a uniform probability distribution.
	boost::uniform_real<double> uniform_dist( min, max );
	
	//Bind the random number generator to the distribution, which forms
	//a functor.
	boost::variate_generator<boost::mt19937&, boost::uniform_real<double> > rng_sampler(RandomNumberEngine::fRNG, uniform_dist);
	
	//Now sample.
	return rng_sampler();
}
const std::vector<double> RandomNumberEngine::GetSphericalSurfaceRandomReal(unsigned dimension=2)
{
	//Build the probability distribution on a sphere of dimension two.
	boost::uniform_on_sphere<double> sphere(dimension);
	
	//Now bind the random number generator to the distribution, which forms a functor.
	boost::variate_generator<boost::mt19937&, boost::uniform_on_sphere<double> > rng_sampler(RandomNumberEngine::fRNG, sphere);
	
	//Now sample.
	return rng_sampler();
}
