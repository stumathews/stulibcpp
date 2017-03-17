#ifdef _WIN32
#  ifdef DLL_EXPORT
#    define LIBRARY_API	__declspec(dllexport)
#  else
#    ifdef LIBSTU_DLL_IMPORT
#      define LIBRARY_API	extern __declspec(dllimport)
#    endif
#  endif
#else
# define LIBRARY_API	extern
#endif