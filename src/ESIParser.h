/*
 * $Id: ESIParser.h,v 1.2 2003/08/04 22:14:40 robertc Exp $
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

#ifndef SQUID_ESIPARSER_H
#define SQUID_ESIPARSER_H

class ESIParserClient
{

public:
    virtual void start(const char *el, const char **attr, size_t attrCount) = 0;
    virtual void end(const char *el) = 0;
    virtual void parserDefault (const char *s, int len) =0;
    virtual void parserComment (const char *s) = 0;
};

class ESIParser : public RefCountable
{

public:
    typedef RefCount<ESIParser> Pointer;
    static Pointer NewParser(ESIParserClient *aClient);
    static char *Type;
    /* true on success */
    virtual bool parse(char const *dataToParse, size_t const lengthOfData, bool const endOfStream) = 0;
    virtual size_t lineNumber() const =0;
    virtual char const * errorString() const =0;

protected:
    ESIParser(){};

private:
};

#endif /* SQUID_ESIPARSER_H */
