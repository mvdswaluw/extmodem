/*
 * Sound card modem for Amateur Radio AX25.
 *
 * Copyright (C) Alejandro Santos, 2013, alejolp@gmail.com.
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


#ifndef HDLC_H_
#define HDLC_H_

#include <string>


namespace extmodem {

class hdlc {
public:
	hdlc();
	virtual ~hdlc();

	void rxbit(int bit);
	void ax25_disp_packet(unsigned char *bp, unsigned int len);

	std::string get_name() const { return name_; }
	void set_name(const std::string& s) { name_ = s; }

private:
	struct l2_state_hdlc {
		unsigned char rxbuf[1024];
		unsigned char *rxptr;
		unsigned int rxstate;
		unsigned int rxbitstream;
		unsigned int rxbitbuf;
	} hdlc_;

	void init();

	std::string name_;
};

} /* namespace extmodem */
#endif /* HDLC_H_ */