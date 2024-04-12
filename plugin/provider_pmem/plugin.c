/* Copyright (c) 2021, MariaDB Corporation

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1335  USA */

#include <mysql_version.h>
#include <mysql/plugin.h>
#include <libpmem.h>
#include <providers/libpmem.h>

static int init(void* h)
{
  provider_service_pmem->pmem_persist_ptr= pmem_persist;
  provider_service_pmem->pmem_errormsg_ptr= pmem_errormsg;
  provider_service_pmem->is_loaded = true;

  return 0;
}

static int deinit(void *h)
{
  return 1; /* don't unload me */
}

static struct st_mysql_daemon info= { MYSQL_DAEMON_INTERFACE_VERSION  };

maria_declare_plugin(provider_pmem)
{
  MYSQL_DAEMON_PLUGIN,
  &info,
  "provider_pmem",
  "Sergei Golubchik",
  "Persistent memory support provider",
  PLUGIN_LICENSE_GPL,
  init,
  deinit,
  0x0100,
  NULL,
  NULL,
  "1.0",
  MariaDB_PLUGIN_MATURITY_STABLE
}
maria_declare_plugin_end;
