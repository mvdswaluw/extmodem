/*
 * Sound card modem for Amateur Radio AX25.
 *
 * Copyright (C) Alejandro Santos LU4EXT, 2013, alejolp@gmail.com.
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include "audiosource.h"
#include "extmodem.h"

#include "decoder_dtmf.h"
#include "decoder_af1200mm.h"
#include "decoder_af1200stj.h"


#include <boost/smart_ptr.hpp>


using namespace extmodem;

#define SAMPLE_RATE 22050

int main(int argc, char **argv) {
	int i;
	::extmodem::extmodem e;
	boost::shared_ptr<audiosource> as(new audiosource_portaudio(SAMPLE_RATE));

	e.set_audiosource(as);

	for (i = 0; i < 1 /* as->get_channel_count() */; ++i) {
		e.add_decoder(decoder_ptr(new decoder_dtmf()), i);
		e.add_decoder(decoder_ptr(new decoder_af1200mm()), i);
		e.add_decoder(decoder_ptr(new decoder_af1200stj()), i);
	}

	e.start();

	for (;;) {
		Pa_Sleep(1000);
	}

	return 0;
}

