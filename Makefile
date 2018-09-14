#
# Copyright (c) 2018, Valerio Bellizzomi
#
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the System Experiments Laboratory, Rome nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
# OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#


# Makefile for etherframe.c

CC=gcc
CFLAGS=
BUILDDIR=.

default: package

SOURCES=etherframe.c
TARGETS=etherframe

# Package version support
VERSION=0.5

package:
	$(CC) $(CFLAGS) -o $(TARGETS) $(BUILDDIR)/$(SOURCES)

install:
	if [ ! -d $(HOME)/bin ]; then \
	  echo "Creating ~/bin";
	  mkdir $(HOME)/bin;
	fi;
	cp $(TARGETS) $(HOME)/bin/$(TARGETS)

clean:
	rm -f $(TARGETS)
	rm -f $(BUILDDIR)/html/*
	rm -f $(TARGETS).tgz
	rm -f $(TARGETS)-$(VERSION).tgz

sanify:
	find $(BUILDDIR) -name '*~' -exec rm {} \;

docs:
	doxygen Doxyfile

tar:	clean sanify
	-rm -f $(TARGETS).tar $(TARGETS).tar.gz
	tar cvf $(TARGETS).tar $(BUILDDIR)/*
	gzip $(TARGETS).tar
	mv $(TARGETS).tar.gz $(TARGETS)-$(VERSION).tgz

# Internal-use target
pub:	tar docs
	cp $(TARGETS)-$(VERSION).tgz /home/test/$(TARGETS)/
	cp $(BUILDDIR)/ef.html /home/test/$(TARGETS)/ef.html
	cp $(BUILDDIR)/html/* /home/test/$(TARGETS)/html/

