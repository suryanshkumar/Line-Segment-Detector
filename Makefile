# -----------------------------------------------------------------------------
#
# LSD - Line Segment Detector on digital images
#
# Copyright (c) 2007-2011 rafael grompone von gioi <grompone@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#
# -----------------------------------------------------------------------------

all: lsd detectLine

#CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --cflags --libs opencv`
 
lsd: lsd.c lsd.h lsd_cmd.c
	cc -O3 -o lsd lsd_cmd.c lsd.c -lm
	
detectLine: detectLine.cpp
	g++ $< -o $@ $(LIBS) 
	

doc: lsd.c lsd.h doxygen.config
	doxygen doxygen.config

clean:
	rm -f lsd detectLine

cleandoc:
	rm -rf doc

# -----------------------------------------------------------------------------
