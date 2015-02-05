/******************************************************************
*
*	CyberLink for C
*
*	Copyright (C) Satoshi Konno 2005
*
*       Copyright (C) 2006 Nokia Corporation. All rights reserved.
*
*       This is licensed under BSD-style license,
*       see file COPYING.
*
*	File: cservice_list.c
*
*	Revision:
*
*	02/14/05
*		- first revision
*
******************************************************************/

#include <mupnp/service.h>
#include <mupnp/util/log.h>

/****************************************
* mupnp_upnp_servicelist_new
****************************************/

CgUpnpServiceList *mupnp_upnp_servicelist_new()
{
	CgUpnpServiceList *serviceList;

	mupnp_log_debug_l4("Entering...\n");

	serviceList = (CgUpnpServiceList *)malloc(sizeof(CgUpnpServiceList));

	if ( NULL != serviceList )
		mupnp_list_header_init((CgList *)serviceList);

	return serviceList;

	mupnp_log_debug_l4("Leaving...\n");
}

/****************************************
* mupnp_upnp_servicelist_delete
****************************************/

void mupnp_upnp_servicelist_delete(CgUpnpServiceList *serviceList)
{
	mupnp_log_debug_l4("Entering...\n");

	mupnp_upnp_servicelist_clear(serviceList);
	free(serviceList);

	mupnp_log_debug_l4("Leaving...\n");
}