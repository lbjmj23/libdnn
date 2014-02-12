#ifndef __TEMPLATE_FUNCTIONAL_H_
#define __TEMPLATE_FUNCTIONAL_H_

#ifndef __CUDACC__
#define __host__
#define __device__
#endif
// ===============================
// ===== Template Functional =====
// ===============================
namespace func {

  template <typename T>
  struct apx {
    const T a;
    apx(T _a) : a(_a) {}
    __host__ __device__ T operator() (const T& x) const { return a + x; }
  };

  template <typename T>
  struct amx {
    const T a;
    amx(T _a) : a(_a) {}
    __host__ __device__ T operator() (const T& x) const { return a - x; }
  };

  template <typename T>
  struct ax {
    const T a;
    ax(T _a) : a(_a) {}
    __host__ __device__ T operator() (const T& x) const { return a * x; }
  };

  template <typename T>
  struct adx {
    const T a;
    adx(T _a) : a(_a) {}
    __host__ __device__ T operator() (const T& x) const { return a / x; }
  };

  template <typename T>
  struct square {
    __host__ __device__ T operator() (const T& x) const { return x * x; }
  };

  template <typename T>
  struct sqrt {
    __host__ __device__ T operator() (const T& x) const { return sqrtf(x); }
  };

  template <typename T>
  struct to_zero_one {
    __host__ __device__ T operator() (const T& x) const { return x > 0.5 ? 1 : 0; }
  };
  
  template <typename T>
  struct min_threshold {
    const float _t;
    min_threshold(float t) : _t(t) {}
    __host__ __device__ T operator() (const T& x) const { return x <= _t ? _t : x; }
  };

  template <typename T>
  struct sigmoid {
#ifndef __CUDACC__
    __host__ __device__ T operator() (const T& x) { return 1.0 / ( 1.0 + exp(-x) ); }
#else
    __host__ __device__ T operator() (const T& x) { return 1.0 / ( 1.0 + expf(-x) ); }
#endif

  };

  template <typename T>
  struct dsigma {
    __host__ __device__ T operator() (const T& x) { return x * (1.0 - x); }
  };

  template <typename T>
  struct dcrossentropy {
    __host__ __device__ T operator() (const T& x, const T& y) { return -x / y; }
  };

  template <typename T>
  struct exp {
#ifndef __CUDACC__
    __host__ __device__ T operator() (const T& x) { return exp(x); }
#else
    __host__ __device__ T operator() (const T& x) { return expf(x); }
#endif
  };
};

#endif // __TEMPLATE_FUNCTIONAL_H_