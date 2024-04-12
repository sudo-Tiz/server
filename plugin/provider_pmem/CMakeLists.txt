FIND_PACKAGE(PMEM)

SET(CPACK_RPM_provider-pmem_PACKAGE_SUMMARY "persistent memory support in the server and storage engines" PARENT_SCOPE)
SET(CPACK_RPM_provider-pmem_PACKAGE_DESCRIPTION "persistent memory support in the server and storage engines" PARENT_SCOPE)

IF (PMEM_FOUND)
  GET_PROPERTY(dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
  LIST(REMOVE_ITEM dirs ${CMAKE_SOURCE_DIR}/include/providers)
  SET_PROPERTY(DIRECTORY PROPERTY INCLUDE_DIRECTORIES "${dirs}")

  INCLUDE_DIRECTORIES(${PMEM_INCLUDE_DIRS})

  MYSQL_ADD_PLUGIN(provider_pmem plugin.c COMPONENT provider-pmem
    LINK_LIBRARIES ${PMEM_LIBRARIES} CONFIG provider_pmem.cnf)
ENDIF()
