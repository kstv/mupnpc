/******************************************************************
*
*	CyberUtil for C
*
*	Copyright (C) Satoshi Konno 2005
*
*       Copyright (C) 2006 Nokia Corporation. All rights reserved.
*
*       This is licensed under BSD-style license,
*       see file COPYING.
*
*	File: curl.h
*
*	Revision:
*
*	03/09/05
*		- first revision
*
******************************************************************/

#ifndef _CG_NET_CURI_H_
#define _CG_NET_CURI_H_

#include <mupnp/typedef.h>

#include <mupnp/util/string.h>
#include <mupnp/util/dictionary.h>

#ifdef  __cplusplus
extern "C" {
#endif

/****************************************
* Define
****************************************/

#define CG_NET_URI_KNKOWN_PORT (-1)
#define CG_NET_URI_DEFAULT_HTTP_PORT 80
#define CG_NET_URI_DEFAULT_FTP_PORT 21
#define CG_NET_URI_DEFAULT_PATH "/"
#define CG_NET_URI_MAXLEN 256

#define CG_NET_URI_PROTOCOL_DELIM "://"
#define CG_NET_URI_USER_DELIM "@"
#define CG_NET_URI_COLON_DELIM ":"
#define CG_NET_URI_SLASH_DELIM "/"
#define CG_NET_URI_SBLACET_DELIM "["
#define CG_NET_URI_EBLACET_DELIM "]"
#define CG_NET_URI_SHARP_DELIM "#"
#define CG_NET_URI_QUESTION_DELIM "?"
#define CG_NET_URI_ESCAPING_CHAR "%"
#define CG_NET_URI_AMP_DELIM "&"
#define CG_NET_URI_EQ_DELIM "="

#define CG_NET_URI_PROTOCOL_HTTP "http"
#define CG_NET_URI_PROTOCOL_FTP "ftp"

/****************************************
* Data Type
****************************************/

typedef struct _CgNetURI {
	CgString *uri;
	CgString *protocol;
	CgString *user;
	CgString *password;
	CgString *host;
	int port;
	CgString *path;
	CgString *query;
	CgString *fragment;
	CgString *request;
	CgDictionary *queryDictionary;
} CgNetURI;

/****************************************
* Function
****************************************/

CgNetURI *mupnp_net_uri_new();
void mupnp_net_uri_delete(CgNetURI *uri);
void mupnp_net_uri_clear(CgNetURI *uri);
void mupnp_net_uri_setvalue(CgNetURI *uri, const char *value);
void mupnp_net_uri_rebuild(CgNetURI *uri);
const char *mupnp_net_uri_getvalue(CgNetURI *uri);

#define mupnp_net_uri_set(urip, value) mupnp_net_uri_setvalue(urip, value)
	
#define mupnp_net_uri_seturi(urip, value) mupnp_string_setvalue(urip->uri, value)
#define mupnp_net_uri_setprotocol(urip, value) mupnp_string_setvalue(urip->protocol, value)
#define mupnp_net_uri_setuser(urip, value) mupnp_string_setvalue(urip->user, value)
#define mupnp_net_uri_setpassword(urip, value) mupnp_string_setvalue(urip->password, value)
#define mupnp_net_uri_sethost(urip, value) mupnp_string_setvalue(urip->host, value)
#define mupnp_net_uri_setport(urip, value) (urip->port = value)
#define mupnp_net_uri_setpath(urip, value) mupnp_string_setvalue(urip->path, value)
#define mupnp_net_uri_addpath(urip, value) mupnp_string_addvalue(urip->path, value)
#define mupnp_net_uri_setquery(urip, value) mupnp_string_setvalue(urip->query, value)
#define mupnp_net_uri_setfragment(urip, value) mupnp_string_setvalue(urip->fragment, value)
    
#define mupnp_net_uri_geturi(urip) mupnp_string_getvalue(urip->uri)
#define mupnp_net_uri_getprotocol(urip) mupnp_string_getvalue(urip->protocol)
#define mupnp_net_uri_getuser(urip) mupnp_string_getvalue(urip->user)
#define mupnp_net_uri_getpassword(urip) mupnp_string_getvalue(urip->password)
#define mupnp_net_uri_gethost(urip) mupnp_string_getvalue(urip->host)
#define mupnp_net_uri_getport(urip) (urip->port)
#define mupnp_net_uri_getpath(urip) mupnp_string_getvalue(urip->path)
#define mupnp_net_uri_getquery(urip) mupnp_string_getvalue(urip->query)
#define mupnp_net_uri_getfragment(urip) mupnp_string_getvalue(urip->fragment)

char *mupnp_net_uri_getrequest(CgNetURI *uri);
char *mupnp_net_uri_getupnpbasepath(CgNetURI *locationURL);

#define mupnp_net_uri_hasuri(urip) ((0 < mupnp_string_length(urip->uri)) ? TRUE : FALSE)
#define mupnp_net_uri_hasprotocol(urip) ((0 < mupnp_string_length(urip->protocol)) ? TRUE : FALSE)
#define mupnp_net_uri_hasuser(urip) ((0 < mupnp_string_length(urip->user)) ? TRUE : FALSE)
#define mupnp_net_uri_haspassword(urip) ((0 < mupnp_string_length(urip->password)) ? TRUE : FALSE)
#define mupnp_net_uri_hashost(urip) ((0 < mupnp_string_length(urip->host)) ? TRUE : FALSE)
#define mupnp_net_uri_hasport(urip) ((0 < urip->port) ? TRUE : FALSE)
#define mupnp_net_uri_haspath(urip) ((0 < mupnp_string_length(urip->path)) ? TRUE : FALSE)
#define mupnp_net_uri_hasquery(urip) ((0 < mupnp_string_length(urip->query)) ? TRUE : FALSE)
#define mupnp_net_uri_hasfragment(urip) ((0 < mupnp_string_length(urip->fragment)) ? TRUE : FALSE)
#define mupnp_net_uri_hasrequest(urip) mupnp_net_uri_haspath(urip)

#define mupnp_net_uri_ishttpprotocol(urip) mupnp_streq(mupnp_string_getvalue(urip->protocol), CG_NET_URI_PROTOCOL_HTTP)

#define mupnp_net_uri_isabsolute(urip) mupnp_net_uri_hasprotocol(urip)
#define mupnp_net_uri_isabsolutepath(uripath) (( *uripath == '/' ) ? TRUE : FALSE )
#define mupnp_net_uri_isrelative(urip) ((mupnp_net_uri_hasprotocol(urip) == TRUE) ? FALSE : TRUE)

BOOL mupnp_net_uri_isreservedchar(char c);
BOOL mupnp_net_uri_isunreservedchar(char c);
BOOL mupnp_net_uri_isescapechar(char c);
BOOL mupnp_net_uri_isalphanumchar(char c);

BOOL mupnp_net_uri_isescapedstring(char *buf, size_t bufSize);
char *mupnp_net_uri_escapestring(char *buf, size_t bufSize, CgString *retBuf);
char *mupnp_net_uri_unescapestring(char *buf, size_t bufSize, CgString *retBuf);
BOOL mupnp_net_uri_isequivalent(const char *url, const char *relative_url);

CgDictionary *mupnp_net_uri_getquerydictionary(CgNetURI *uri);

#ifdef  __cplusplus
}
#endif

#endif