
#ifndef STUCPP_EXPORT_H
#define STUCPP_EXPORT_H

#ifdef STUCPP_STATIC_DEFINE
#  define STUCPP_EXPORT
#  define STUCPP_NO_EXPORT
#else
#  ifndef STUCPP_EXPORT
#    ifdef stucpp_EXPORTS
        /* We are building this library */
#      define STUCPP_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define STUCPP_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef STUCPP_NO_EXPORT
#    define STUCPP_NO_EXPORT 
#  endif
#endif

#ifndef STUCPP_DEPRECATED
#  define STUCPP_DEPRECATED __declspec(deprecated)
#endif

#ifndef STUCPP_DEPRECATED_EXPORT
#  define STUCPP_DEPRECATED_EXPORT STUCPP_EXPORT STUCPP_DEPRECATED
#endif

#ifndef STUCPP_DEPRECATED_NO_EXPORT
#  define STUCPP_DEPRECATED_NO_EXPORT STUCPP_NO_EXPORT STUCPP_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef STUCPP_NO_DEPRECATED
#    define STUCPP_NO_DEPRECATED
#  endif
#endif

#endif /* STUCPP_EXPORT_H */
