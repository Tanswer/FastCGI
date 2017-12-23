/*
 * @filename:    main.c
 * @author:      Tanswer
 * @date:        2017年12月23日 01:44:32
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
#include "fcgi.h"

int main()
{
    FastCgi_t *c;
    c = (FastCgi_t *)malloc(sizeof(FastCgi_t));
    FastCgi_init(c);
    setRequestId(c,1);
    startConnect(c);
    sendStartRequestRecord(c);
    sendParams(c, "SCRIPT_FILENAME","/home/Tanswer/index.php");
    sendParams(c, "REQUEST_METHOD","GET");
    sendEndRequestRecord(c);
    readFromPhp(c);
    FastCgi_finit(c);
    return 0;
}
