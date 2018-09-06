/**
 * Copyright (C) 2017-2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @author Pablo Alvarado
 * @date   18.08.2018
 */

#ifndef ANPI_DEFLATION_HPP
#define ANPI_DEFLATION_HPP

#include <vector>
#include <complex>
#include <type_traits>

#include <boost/type_traits/is_complex.hpp>
#include <boost/math/tools/polynomial.hpp>

namespace anpi {
  namespace bmt=boost::math::tools; // bmt as alias for boost::math::tools
  
  /**
   * Deflate polynomial
   *
   * @param[in] poly Input polynomial to be deflated with the provided root
   * @param[in] root Root of poly to be deflated with.
   * @param[out] residuo Residual of the polynomial deflation
   * @return deflated polynomial
   */
  template<class T>
  bmt::polynomial<T> deflate(const bmt::polynomial<T>& poly,
                             const T& root,
                             T& residuo,
                             T& tolerance=bmt::epsilon<T>())
  {
    int n = poly.size()-1; 	// get degree of poly
    residuo = poly[n];
    bmt::polynomial<T> a = poly;
    a[n] = 0; 			//set degree of a = n-1
    T s = T(0);
    //Horner's method for synthetic divition
    for (int i=n-1; i>=0; --i)
    {
      s = a[i];				//store to overwrite
      a[i] = residuo;		
      residuo = s + residuo * root;
    }
    return poly;
  }

  /**
   * Deflate polynomial with a second order polynomial.
   *
   * The second order polynomial equals x^2 -2 Re(root)x + |root|^2.
   *
   * @param[in] poly Input polynomial to be deflated with the provided root
   * @param[in] root Root of poly to be deflated with.
   * @param[out] residuo Residual of the polynomial deflation
   * @return deflated polynomial
   */
  template<class T>
  bmt::polynomial<T> deflate2(const bmt::polynomial<T>& poly,
                              const std::complex<T>& root,
                              bmt::polynomial<T>& residuo,
                              T& tolerance=bmt::epsilon<T>())
  {
    T real = std::real(root);
    T imag = std::imag(root);
    //get the quadratic divident from root
    T nDos = std::real(-2);
    const bmt::polynomial<T> rootDiv = {{real*real + imag*imag, nDos * real, 1}}; 
    int nv = rootDiv.size() -1 ;
    int n = poly.size() - 1;
    residuo = poly; 
    bmt::polynomial<T> quotient = poly;
    for (int i = 0; i < poly.size(); ++i){
      quotient[i] = 0.;
    }
    for (int k = n - nv ; k >=0; --k){
      //std::cout << "k: " << k << " nv: " << nv << std::endl;
      quotient[k] = residuo[nv+k];
      for (int j = nv + k - 1; j >= k; --j){
        //std::cout << "j: " << j << std::endl;
        residuo[j] -= quotient[k]*rootDiv[j-k];
      }
    }
    //add trailing zeros to residuo
    for (int j = nv; j <= n; ++j){
      residuo[nv] = T(0.0);
    }
    return quotient;
  }

  
}



#endif
