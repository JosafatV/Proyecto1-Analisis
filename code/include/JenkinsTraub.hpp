/**
 * Copyright (C) 2017-2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @author Pablo Alvarado
 * @date   18.08.2018
 */

#ifndef ANPI_JENKINS_TRAUB_HPP
#define ANPI_JENKINS_TRAUB_HPP

#include <vector>
#include <type_traits>

#include <boost/type_traits/is_complex.hpp>
#include <boost/math/tools/polynomial.hpp>

namespace anpi {

  namespace bmt=boost::math::tools; // for polynomial
  
  /**
   * Compute the roots of the given polynomial using the Jenkins-Traub method.
   * @param[in] poly polynomial to be analyzed for roots
   * @param[out] roots all roots found
   * @param[in] start initial point for finding the roots
   * @param[in] polish indicate if polishing is needed or not.
   *
   * @return the number of roots found
   */
  template<class T,class U>
  void jenkinsTraub(const bmt::polynomial<T>& poly,
                    std::vector<U>& roots,
              const PolishEnum polish=DoNotPolish,
              const U start=U()) {
    
    static_assert(std::is_floating_point<T>::value ||
                  boost::is_complex<T>::value,
                  "T must be floating point or complex");
    static_assert(std::is_floating_point<U>::value ||
                  boost::is_complex<U>::value,
                  "U must be floating point or complex");

/*     int n = poly.size()-1; 	
    T p = 0;
    T df = 0;
    for(int k=n; n >= 0; n--){
      //df = df*U + p;
      //p = p*U + poly[k];
    } */

    //Etapa1
   /*  T H[n] = ;
    H[0] = df;
    n = poly.size(); 	
    for(int i = 0; i < 6; i++){//se recomienda iterar 5 veces minimo
      for(int j = 0; j < n; j++){
        H[j+1] = poly[j]-H[j]*(H[j])/poly[0]
      }
    } */
   /*  //Etapa2
    //T sk = 
    //Etapa3 */

    throw Exception("Not implemented yet!");
  }
}


#endif
