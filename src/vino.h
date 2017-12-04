/*
 * Copyright (C) Chenyang Li
 * Copyright (C) Vino
 */
#ifndef VINO_VN_VINO_H
#define VINO_VN_VINO_H

#include "vn_request.h"

#define VINO_VERSION      "2.0"
#define VN_PORT           "8080"
#define VN_RUNNING        1
#define VN_ACCEPT         1
#define VN_KEEP_READING   1
#define VN_KEEP_PARSING   1

#define VN_HEADERS_SIZE              4096
#define VN_BODY_SIZE                 8192
#define VN_FILETYPE_SIZE             50
#define VN_PARENT_DIR                "../"
#define VN_DEFAULT_STATIC_RES_DIR    "html"
#define VN_DEFAULT_PAGE              "/index.html"

#define VN_CONN_KEEP_ALIVE           1
#define VN_CONN_CLOSE                0 

/*
 * Check whether the HTTP request message is fully buffered.
 * If true, call the corresponding method to deal with.
 */ 
void vn_handle_http_connection(vn_http_connection *conn);

/*
 * Handle HTTP GET request.
 */
void vn_handle_get_connection(vn_http_connection *conn);

/* 
 * Create HTTP response header and store it into `headers`.
 */ 
void vn_build_resp_headers(char *headers, 
                           int code, 
                           const char *reason, 
                           const char *content_type, 
                           unsigned int content_length, 
                           short keep_alive);

/* 
 * Create HTTP Not Found response body and store it into `body`.
 */ 
void vn_build_resp_404_body(char *body, const char *uri);

void vn_build_resp_403_body(char *body, const char *uri);

const char *vn_status_message(int code);

#endif /* VINO_VN_VINO_H */