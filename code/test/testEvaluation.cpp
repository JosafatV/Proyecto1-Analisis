/**
 * Copyright (C) 2017-2018
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 */


#include <boost/test/unit_test.hpp>

#include <iostream>
#include <exception>
#include <cstdlib>
#include <complex>
#include <string>
#include <sstream>

#include <type_traits>

#include <boost/type_traits/is_complex.hpp>

#include <Deflation.hpp>


namespace bmt=boost::math::tools; // for polynomial

// normal allocator

typedef std::complex<double> dcomplex;
typedef std::complex<float>  fcomplex;

BOOST_AUTO_TEST_SUITE( Eval )

BOOST_AUTO_TEST_CASE ( Basic ) {
	
		//Real Case
	float x = 1;
	bmt::polynomial<float> p0 = {{-189.f, -57.f, 5.f, 1.f}};
	float r = p0.evaluate(x);
	
	BOOST_CHECK (-240.f == r);
	
		//Complex Case
	fcomplex c = (1,1);
	bmt::polynomial<fcomplex> p1 = {{-189.f, -57.f, 5.f, 1.f}};
	fcomplex r2 = p0.evaluate(x);
	fcomplex e2 = (-240, -240);
	
	BOOST_CHECK (e2 == r2);
	
}

  
BOOST_AUTO_TEST_SUITE_END()
