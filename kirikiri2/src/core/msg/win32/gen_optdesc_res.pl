$copyright = <<EOF;
/*

	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000-2008 W.Dee <dee\@kikyou.info> and contributors

	See details of license at "license.txt"
*/
/* This file is always generated by gen_optdesc_res.pl and option_desc(_ja).txt . */
/* Modification by hand will be lost. */
EOF

#!perl

use Compress::Zlib;

undef $/;

if(!open FH, "option_desc_ja.txt")
{
	open FH, "option_desc.txt" or die;
}

$content = <FH>;

close FH;

$content_org_len = length($content);

$content = compress($content);

$content_comp_len = length($content);

$content =~ s/(.)/sprintf("0x%02x, ", ord $1)/seg;
$content =~ s/(.{96})/$1\n/g;
$content .= "\n";
$content =~ s/(.*?), \n/\t$1,\n/sg;

open FH, ">OptionsDesc.cpp";

print FH $copyright;

print FH <<EOF;

#include "tjsCommHead.h"

#include "MsgIntf.h"
#include <zlib/zlib.h>

/* option description string (compressed) */

static tjs_uint8 compressed_option_desc_string[] =
{
$content
};

EOF

print FH "static const unsigned long compressed_size = $content_comp_len;\n";
print FH "static const unsigned long decompressed_size = $content_org_len;\n";

print FH <<EOF;

ttstr TVPGetCommandDesc()
{
	unsigned char * dest = new unsigned char [decompressed_size + 1];

	ttstr ret;

	try
	{
		unsigned long dest_size = decompressed_size;

		int result = uncompress(dest, &dest_size,
			(unsigned char*)compressed_option_desc_string, compressed_size);
		if(result != Z_OK || dest_size != decompressed_size) { TVPThrowInternalError; }

		dest[decompressed_size] = 0;

		ret = (const char *)dest;

	}
	catch(...)
	{
		delete [] dest;
		throw;
	}
	delete [] dest;

	return ret;
}

EOF
