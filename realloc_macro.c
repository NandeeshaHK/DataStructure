

#define REALLOC(p,n,s) \
if(!((p)=realloc(n,s))) \
{ \
fprintf(stderr,"insufficient memory"); \
exit(EXIT_FAILURE); \
}