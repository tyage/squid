
/*
 * $Id: StoreSwapLogData.h,v 1.2 2003/08/04 22:14:41 robertc Exp $
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 * Copyright (c) 2003, Robert Collins <robertc@squid-cache.org>
 */

#ifndef SQUID_STORESWAPLOGDATA_H
#define SQUID_STORESWAPLOGDATA_H

#include "squid.h"

/*
 * Do we need to have the dirn in here? I don't think so, since we already
 * know the dirn .. 
 */
/* Binary format on disk.
 * DO NOT randomly alter.
 * DO NOT add ANY virtual's.
 */

class StoreSwapLogData
{

public:
    void *operator new (size_t byteCount);
    void operator delete (void *address);
    StoreSwapLogData();
    char op;
    sfileno swap_filen;
    time_t timestamp;
    time_t lastref;
    time_t expires;
    time_t lastmod;
    size_t swap_file_sz;
    u_short refcount;
    u_short flags;
    unsigned char key[MD5_DIGEST_CHARS];

private:
    static MemPool *Pool;
};

#endif /* SQUID_STORESWAPLOGDATA_H */
