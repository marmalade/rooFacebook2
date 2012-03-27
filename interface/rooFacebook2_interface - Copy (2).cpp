/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"

#include "rooFacebook2.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef rooFacebook_Session *(*rooFacebook_init_t)(const char* appId, rooFacebook_CallbackSpecific callback, void * userData);
typedef rooFacebook_Session *(*rooFacebook_initWithUrlSchemeSuffix_t)(const char* appId, const char * urlSchemeSuffix, rooFacebook_CallbackSpecific callback, void * userData);
typedef       void(*rooFacebook_authorize_t)(rooFacebook_Session * facebook, const char * permissions);
typedef const char *(*rooFacebook_getAccessToken_t)(rooFacebook_Session * facebook);
typedef      int(*rooFacebook_getAccessExpires_t)(rooFacebook_Session * facebook);
typedef       void(*rooFacebook_setAccessToken_t)(rooFacebook_Session * facebook, const char * access_token);
typedef       void(*rooFacebook_setAccessExpires_t)(rooFacebook_Session * facebook, int access_expires);
typedef       void(*rooFacebook_extendAccessToken_t)(rooFacebook_Session * facebook);
typedef       void(*rooFacebook_extendAccessTokenIfNeeded_t)(rooFacebook_Session * facebook);
typedef       void(*rooFacebook_logout_t)(rooFacebook_Session * facebook);
typedef       void(*rooFacebook_deleteSession_t)(rooFacebook_Session * facebook);
typedef        int(*rooFacebook_isSessionValid_t)(rooFacebook_Session * facebook);
typedef rooFacebook_Dialog *(*rooFacebook_dialog_t)(rooFacebook_Session * facebook, const char * action, rooFacebook_CallbackSpecific callback, void * userData);
typedef rooFacebook_Dialog *(*rooFacebook_dialogAndParams_t)(rooFacebook_Session * facebook, const char * action, const char * params, rooFacebook_CallbackSpecific callback, void * userData);
typedef       void(*rooFacebook_deleteDialog_t)(rooFacebook_Dialog * dialog);
typedef rooFacebook_Request *(*rooFacebook_requestWithParams_t)(rooFacebook_Session * facebook, const char * params, rooFacebook_CallbackSpecific callback, void * userData);
typedef rooFacebook_Request *(*rooFacebook_requestWithMethodName_t)(rooFacebook_Session * facebook, const char * methodName, const char * params, const char * httpMethod, rooFacebook_CallbackSpecific callback, void * userData);
typedef rooFacebook_Request *(*rooFacebook_requestWithGraphPath_t)(rooFacebook_Session * facebook, const char * graphPath, rooFacebook_CallbackSpecific callback, void * userData);
typedef rooFacebook_Request *(*rooFacebook_requestWithGraphPathAndParams_t)(rooFacebook_Session * facebook, const char * graphPath, const char * params, rooFacebook_CallbackSpecific callback, void * userData);
typedef rooFacebook_Request *(*rooFacebook_requestWithGraphPathAndParamsAndHttpMethod_t)(rooFacebook_Session * facebook, const char * graphPath, const char * params, const char * httpMethod, rooFacebook_CallbackSpecific callback, void * userData);
typedef       void(*rooFacebook_deleteRequest_t)(rooFacebook_Request * request);

/**
 * struct that gets filled in by rooFacebook2Register
 */
typedef struct rooFacebook2Funcs
{
    rooFacebook_init_t m_rooFacebook_init;
    rooFacebook_initWithUrlSchemeSuffix_t m_rooFacebook_initWithUrlSchemeSuffix;
    rooFacebook_authorize_t m_rooFacebook_authorize;
    rooFacebook_getAccessToken_t m_rooFacebook_getAccessToken;
    rooFacebook_getAccessExpires_t m_rooFacebook_getAccessExpires;
    rooFacebook_setAccessToken_t m_rooFacebook_setAccessToken;
    rooFacebook_setAccessExpires_t m_rooFacebook_setAccessExpires;
    rooFacebook_extendAccessToken_t m_rooFacebook_extendAccessToken;
    rooFacebook_extendAccessTokenIfNeeded_t m_rooFacebook_extendAccessTokenIfNeeded;
    rooFacebook_logout_t m_rooFacebook_logout;
    rooFacebook_deleteSession_t m_rooFacebook_deleteSession;
    rooFacebook_isSessionValid_t m_rooFacebook_isSessionValid;
    rooFacebook_dialog_t m_rooFacebook_dialog;
    rooFacebook_dialogAndParams_t m_rooFacebook_dialogAndParams;
    rooFacebook_deleteDialog_t m_rooFacebook_deleteDialog;
    rooFacebook_requestWithParams_t m_rooFacebook_requestWithParams;
    rooFacebook_requestWithMethodName_t m_rooFacebook_requestWithMethodName;
    rooFacebook_requestWithGraphPath_t m_rooFacebook_requestWithGraphPath;
    rooFacebook_requestWithGraphPathAndParams_t m_rooFacebook_requestWithGraphPathAndParams;
    rooFacebook_requestWithGraphPathAndParamsAndHttpMethod_t m_rooFacebook_requestWithGraphPathAndParamsAndHttpMethod;
    rooFacebook_deleteRequest_t m_rooFacebook_deleteRequest;
} rooFacebook2Funcs;

static rooFacebook2Funcs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x5edb39a1, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE, "error loading extension: rooFacebook2");
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x5edb39a1, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool rooFacebook2Available()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

rooFacebook_Session * rooFacebook_init(const char* appId, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[0] func: rooFacebook_init"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_init(appId, callback, userData);
}

rooFacebook_Session * rooFacebook_initWithUrlSchemeSuffix(const char* appId, const char * urlSchemeSuffix, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[1] func: rooFacebook_initWithUrlSchemeSuffix"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_initWithUrlSchemeSuffix(appId, urlSchemeSuffix, callback, userData);
}

void rooFacebook_authorize(rooFacebook_Session * facebook, const char * permissions)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[2] func: rooFacebook_authorize"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_authorize(facebook, permissions);
}

const char * rooFacebook_getAccessToken(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[3] func: rooFacebook_getAccessToken"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_getAccessToken(facebook);
}

int rooFacebook_getAccessExpires(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[4] func: rooFacebook_getAccessExpires"));

    if (!_extLoad())
        return 0;

    return g_Ext.m_rooFacebook_getAccessExpires(facebook);
}

void rooFacebook_setAccessToken(rooFacebook_Session * facebook, const char * access_token)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[5] func: rooFacebook_setAccessToken"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_setAccessToken(facebook, access_token);
}

void rooFacebook_setAccessExpires(rooFacebook_Session * facebook, int access_expires)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[6] func: rooFacebook_setAccessExpires"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_setAccessExpires(facebook, access_expires);
}

void rooFacebook_extendAccessToken(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[7] func: rooFacebook_extendAccessToken"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_extendAccessToken(facebook);
}

void rooFacebook_extendAccessTokenIfNeeded(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[8] func: rooFacebook_extendAccessTokenIfNeeded"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_extendAccessTokenIfNeeded(facebook);
}

void rooFacebook_logout(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[9] func: rooFacebook_logout"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_logout(facebook);
}

void rooFacebook_deleteSession(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[10] func: rooFacebook_deleteSession"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_deleteSession(facebook);
}

int rooFacebook_isSessionValid(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[11] func: rooFacebook_isSessionValid"));

    if (!_extLoad())
        return 0;

    return g_Ext.m_rooFacebook_isSessionValid(facebook);
}

rooFacebook_Dialog * rooFacebook_dialog(rooFacebook_Session * facebook, const char * action, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[12] func: rooFacebook_dialog"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_dialog(facebook, action, callback, userData);
}

rooFacebook_Dialog * rooFacebook_dialogAndParams(rooFacebook_Session * facebook, const char * action, const char * params, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[13] func: rooFacebook_dialogAndParams"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_dialogAndParams(facebook, action, params, callback, userData);
}

void rooFacebook_deleteDialog(rooFacebook_Dialog * dialog)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[14] func: rooFacebook_deleteDialog"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_deleteDialog(dialog);
}

rooFacebook_Request * rooFacebook_requestWithParams(rooFacebook_Session * facebook, const char * params, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[15] func: rooFacebook_requestWithParams"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_requestWithParams(facebook, params, callback, userData);
}

rooFacebook_Request * rooFacebook_requestWithMethodName(rooFacebook_Session * facebook, const char * methodName, const char * params, const char * httpMethod, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[16] func: rooFacebook_requestWithMethodName"));
	
    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_requestWithMethodName(facebook, methodName, params, httpMethod, callback, userData);
}

rooFacebook_Request * rooFacebook_requestWithGraphPath(rooFacebook_Session * facebook, const char * graphPath, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[17] func: rooFacebook_requestWithGraphPath"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_requestWithGraphPath(facebook, graphPath, callback, userData);
}

rooFacebook_Request * rooFacebook_requestWithGraphPathAndParams(rooFacebook_Session * facebook, const char * graphPath, const char * params, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[18] func: rooFacebook_requestWithGraphPathAndParams"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_requestWithGraphPathAndParams(facebook, graphPath, params, callback, userData);
}

rooFacebook_Request * rooFacebook_requestWithGraphPathAndParamsAndHttpMethod(rooFacebook_Session * facebook, const char * graphPath, const char * params, const char * httpMethod, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[19] func: rooFacebook_requestWithGraphPathAndParamsAndHttpMethod"));

    if (!_extLoad())
        return NULL;

    return g_Ext.m_rooFacebook_requestWithGraphPathAndParamsAndHttpMethod(facebook, graphPath, params, httpMethod, callback, userData);
}

void rooFacebook_deleteRequest(rooFacebook_Request * request)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2[20] func: rooFacebook_deleteRequest"));

    if (!_extLoad())
        return;

    g_Ext.m_rooFacebook_deleteRequest(request);
}
