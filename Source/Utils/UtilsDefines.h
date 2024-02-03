#define SIZE_OF_ARRAY(arr) sizeof(arr) / sizeof(*(arr))
#define stringify(name) #name

#ifdef _WIN32
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#elif __unix
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define UNUSED(x) (void)x;

#define NOTHING   \
    do            \
    { /*nothing*/ \
    } while (0);

#define BEGIN_NAMESPACE(N) \
    namespace N            \
    {
#define END_NAMESPACE }