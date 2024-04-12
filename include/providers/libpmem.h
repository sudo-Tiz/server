/**
  @file libpmem.h
  This service provides dynamic access to libpmem
*/

#ifndef PMEM_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef MYSQL_ABI_CHECK
#include <stdbool.h>
#include <stddef.h>
#endif

#ifndef MYSQL_DYNAMIC_PLUGIN
#define provider_service_pmem provider_service_pmem_static
#endif

#ifndef PMEM_MAJOR_VERSION
#define pmem_persist(A,L) provider_service_pmem->pmem_persist_ptr(A,L)
#define pmem_errormsg()   provider_service_pmem->pmem_errormsg_ptr()
#endif

#define DEFINE_pmem_persist(NAME)  NAME(const void *addr, size_t len)
#define DEFINE_pmem_errormsg(NAME) NAME(void)

struct provider_service_pmem_st
{
  void DEFINE_pmem_persist((*pmem_persist_ptr));
  const char *DEFINE_pmem_errormsg((*pmem_errormsg_ptr));

  bool is_loaded;
};

extern struct provider_service_pmem_st *provider_service_pmem;

#ifdef __cplusplus
}
#endif

#define PMEM_INCLUDED
#endif
