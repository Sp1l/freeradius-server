/*
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
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */
#ifndef _FR_RADIUS_H
#define _FR_RADIUS_H
/**
 * $Id$
 *
 * @file include/radius.h
 * @brief Constants for the RADIUS protocol.
 *
 * @copyright 2015  The FreeRADIUS server project
 */
RCSIDH(radius_h, "$Id$")

/** RADIUS packet codes
 *
 */
typedef enum {
	PW_CODE_UNDEFINED		= 0,	//!< Packet code has not been set
	PW_CODE_ACCESS_REQUEST		= 1,	//!< RFC2865 - Access-Request
	PW_CODE_ACCESS_ACCEPT		= 2,	//!< RFC2865 - Access-Accept
	PW_CODE_ACCESS_REJECT		= 3,	//!< RFC2865 - Access-Reject
	PW_CODE_ACCOUNTING_REQUEST	= 4,	//!< RFC2866 - Accounting-Request
	PW_CODE_ACCOUNTING_RESPONSE	= 5,	//!< RFC2866 - Accounting-Response
	PW_CODE_ACCOUNTING_STATUS	= 6,	//!< RFC3575 - Reserved
	PW_CODE_PASSWORD_REQUEST	= 7,	//!< RFC3575 - Reserved
	PW_CODE_PASSWORD_ACK		= 8,	//!< RFC3575 - Reserved
	PW_CODE_PASSWORD_REJECT		= 9,	//!< RFC3575 - Reserved
	PW_CODE_ACCOUNTING_MESSAGE	= 10,	//!< RFC3575 - Reserved
	PW_CODE_ACCESS_CHALLENGE	= 11,	//!< RFC2865 - Access-Challenge
	PW_CODE_STATUS_SERVER	 	= 12,	//!< RFC2865/RFC5997 - Status Server (request)
	PW_CODE_STATUS_CLIENT		= 13,	//!< RFC2865/RFC5997 - Status Server (response)
	PW_CODE_DISCONNECT_REQUEST	= 40,	//!< RFC3575/RFC5176 - Disconnect-Request
	PW_CODE_DISCONNECT_ACK		= 41,	//!< RFC3575/RFC5176 - Disconnect-Ack (positive)
	PW_CODE_DISCONNECT_NAK		= 42,	//!< RFC3575/RFC5176 - Disconnect-Nak (not willing to perform)
	PW_CODE_COA_REQUEST		= 43,	//!< RFC3575/RFC5176 - CoA-Request
	PW_CODE_COA_ACK			= 44,	//!< RFC3575/RFC5176 - CoA-Ack (positive)
	PW_CODE_COA_NAK			= 45,	//!< RFC3575/RFC5176 - CoA-Nak (not willing to perform)
	PW_CODE_MAX			= 255,	//!< Maximum possible code
} PW_CODE;

#define PW_AUTH_UDP_PORT		1812
#define PW_AUTH_UDP_PORT_ALT		1645
#define PW_ACCT_UDP_PORT		1813
#define PW_ACCT_UDP_PORT_ALT		1646
#define PW_POD_UDP_PORT			1700
#define PW_RADIUS_TLS_PORT	       	2083
#define PW_COA_UDP_PORT			3799

/*
 *  The RFC says 4096 octets max, and most packets are less than 256.
 */
#define MAX_PACKET_LEN 4096

#include <freeradius-devel/rfc2865.h>
#include <freeradius-devel/rfc2866.h>
#include <freeradius-devel/rfc2867.h>
#include <freeradius-devel/rfc2868.h>
#include <freeradius-devel/rfc2869.h>

#include <freeradius-devel/rfc3162.h>
#include <freeradius-devel/rfc3576.h>
#include <freeradius-devel/rfc3580.h>

#include <freeradius-devel/rfc4072.h>
#include <freeradius-devel/rfc4372.h>

#define PW_CUI	PW_CHARGEABLE_USER_IDENTITY

#include <freeradius-devel/rfc4675.h>
#include <freeradius-devel/rfc4818.h>
#include <freeradius-devel/rfc4849.h>

#include <freeradius-devel/rfc5580.h>
#include <freeradius-devel/rfc5607.h>
#include <freeradius-devel/rfc5904.h>

#include <freeradius-devel/rfc6572.h>
#include <freeradius-devel/rfc6677.h>
#include <freeradius-devel/rfc6911.h>
#include <freeradius-devel/rfc6929.h>
#include <freeradius-devel/rfc6930.h>

#include <freeradius-devel/rfc7055.h>
#include <freeradius-devel/rfc7155.h>
#include <freeradius-devel/rfc7268.h>

/*
 *	All internal attributes are now defined in this file.
 */
#include <freeradius-devel/attributes.h>

#include <freeradius-devel/freeradius.h>

#include <freeradius-devel/vqp.h>

#define PW_DIGEST_RESPONSE		206
#define PW_DIGEST_ATTRIBUTES		207

/*
 *	Integer Translations
 */

/*	User Types	*/

#define PW_LOGIN_USER			1
#define PW_FRAMED_USER			2
#define PW_CALLBACK_LOGIN_USER		3
#define PW_CALLBACK_FRAMED_USER		4
#define PW_OUTBOUND_USER		5
#define PW_ADMINISTRATIVE_USER		6
#define PW_NAS_PROMPT_USER		7
#define PW_AUTHENTICATE_ONLY		8
#define PW_CALLBACK_NAS_PROMPT		9
#define PW_AUTHORIZE_ONLY		17

/*	Framed Protocols	*/

#define PW_PPP				1
#define PW_SLIP				2

/*	Status Types	*/

#define PW_STATUS_START			1
#define PW_STATUS_STOP			2
#define PW_STATUS_ALIVE			3
#define PW_STATUS_ACCOUNTING_ON		7
#define PW_STATUS_ACCOUNTING_OFF	8

/*
 *	Vendor Private Enterprise Codes
 */
#define VENDORPEC_MICROSOFT		311
#define VENDORPEC_FREERADIUS		11344
#define VENDORPEC_WIMAX			24757
#define VENDORPEC_UKERNA		25622

/*
 *	Microsoft has vendor code 311.
 */
#define PW_MSCHAP_RESPONSE			1
#define PW_MSCHAP_ERROR				2
#define PW_MSCHAP_CPW_1				3
#define PW_MSCHAP_CPW_2				4
#define PW_MSCHAP_NT_ENC_PW			6
#define PW_MSCHAP_MPPE_ENCRYPTION_POLICY	7
#define PW_MSCHAP_MPPE_ENCRYPTION_TYPES		8
#define PW_MSCHAP_CHALLENGE			11
#define PW_MSCHAP_MPPE_SEND_KEY			16
#define PW_MSCHAP_MPPE_RECV_KEY			17
#define PW_MSCHAP2_RESPONSE			25
#define PW_MSCHAP2_SUCCESS			26
#define PW_MSCHAP2_CPW				27
#define PW_MS_QUARANTINE_SOH			55

/*
 * JANET's code for transporting eap channel binding data over ttls
 */

#define PW_UKERNA_CHBIND		135
#define PW_UKERNA_TR_COI		136
#endif	/* _FR_RADIUS_H */
