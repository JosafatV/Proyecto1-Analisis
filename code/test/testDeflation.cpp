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

BOOST_AUTO_TEST_SUITE( Deflation )

BOOST_AUTO_TEST_CASE ( DegreeOfPoly ) {
		//Basic Test
	bmt::polynomial<float> p0 = {{-189.f, -57.f, 5.f, 1.f}};
	int n = p0.size();
	
	BOOST_CHECK(n == 4);
}

BOOST_AUTO_TEST_CASE( BasicDeflation ) {
	
	//Basic Test <Float>
	bmt::polynomial<float> p0 = {{-189.f, -57.f, 5.f, 1.f}};
	bmt::polynomial<float> re = {{-21.f, -4.f, 1.f}};

	float root = -9;
	float resi = 0;
	float epsi = 0;
	int check = 0;
	
	bmt::polynomial<float> r0 = anpi::deflate<float>(p0, root, resi, epsi);

	for (int i = r0.size()-1; i>=0; --i) {
		if (re[i]==r0[i]) {
			check=1;
		}
	}

	BOOST_CHECK(check == 0);

	//Basic Test <Double>
	bmt::polynomial<double> p1 = {{-189.f, -57.f, 5.f, 1.f}};
	bmt::polynomial<double> re2 = {{-21.f, -4.f, 1.f}};

	double droot = -9;
	double dresi = 0;
	double depsi = 0;
	int check2 = 0;
	
	bmt::polynomial<double> r1 = anpi::deflate<double>(p1, droot, dresi, depsi);

	for (int i = r1.size()-1; i>=0; --i) {
		if (re2[i]==r1[i]) {
			check2=1;
		}
	}
	
	BOOST_CHECK(check2 == 0);
	
}

BOOST_AUTO_TEST_CASE( ComplexDeflation ) {
	
	//Basic Test <Float>
	//bmt::polynomial< dcomplex >: {{1., 0., dcomplex(-2,1), 0., 0., dcomplex(0,3.f)}};
	bmt::polynomial<fcomplex> p0 = {{10., 6., 1.}};
	bmt::polynomial<fcomplex> re = {{0.}};

	fcomplex root = (3,-1);
	bmt::polynomial<fcomplex> resi = {{0.}};
	fcomplex epsi = 0;
	int check = 0;
	
	bmt::polynomial<fcomplex> r0 = anpi::deflate2<fcomplex>(p0, root, resi, epsi);

	for (int i = r0.size()-1; i>=0; --i) {
		if (re[i]==r0[i]) {
			check=1;
		}
	}

	BOOST_CHECK(check == 0);
}
	
	/*
  bmt::polynomial<float> p1 = {{1.f, 0.f, -2.f, 0.f, 0.f, 3.f}};
  std::string pol1 = "3x^5 - 2x^2 + 1";
  std::string roo1 = "-0.61053545";
  BOOST_CHECK(anpi::Deflation.deflate(pol1, roo1, residuo, tolerancia));

  typedef std::complex<double> dcomplex;

  bmt::polynomial< dcomplex > p2 =
    {{1.,0.,dcomplex(-2,1),0.,0.,dcomplex(0,3.f)}};
  str = "(0,3)x^5 + (-2,1)x^2 + 1";
  BOOST_CHECK(anpi::polynomialFormulaFormat(p2)==str);
  */

  
BOOST_AUTO_TEST_SUITE_END()
