/*
 * $Id: ESICustomParser.h,v 1.4 2003/08/04 22:14:40 robertc Exp $
 *
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
 */

#ifndef SQUID_ESICUSTOMPARSER_H
#define SQUID_ESICUSTOMPARSER_H

#include "ESIParser.h"

class Trie;

class ESICustomParser : public ESIParser
{

public:
    ESICustomParser(ESIParserClient *);
    ~ESICustomParser();
    /* true on success */
    bool parse(char const *dataToParse, size_t const lengthOfData, bool const endOfStream);
    size_t lineNumber() const;
    char const * errorString() const;

private:
    static Trie *SearchTrie;
    static Trie *GetTrie();
    enum ESITAG_t {
        ESITAG=1,
        ESIENDTAG=2,
        ESICOMMENT=3
    };

    char const *findTag(char const *a, size_t b);
    ESIParserClient *theClient;
    String error;
    /* cheap n dirty - buffer it all */
    String content;
    /* TODO: make a class of this type code */
    ESITAG_t lastTag;
};

#endif /* SQUID_ESICUSTOMPARSER_H */
