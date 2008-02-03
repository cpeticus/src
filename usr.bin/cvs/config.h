/*	$OpenBSD: config.h,v 1.4 2008/02/03 17:20:14 joris Exp $	*/
/*
 * Copyright (c) 2006 Joris Vink <joris@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef CONFIG_H
#define CONFIG_H

void cvs_read_config(char *name, void (*cb)(char *));

void cvs_parse_configfile(void);
void cvs_parse_modules(void);

void config_parse_line(char *);
void modules_parse_line(char *);

#include <sys/queue.h>

/* module stuff */

#define MODULE_ALIAS		0x01
#define MODULE_TARGETDIR	0x02
#define MODULE_NORECURSE	0x04

struct module_checkout {
	char			*mc_repo;
	char			*mc_wdir;
	int			 mc_flags;
};

struct module_info {
	char				*mi_name;
	char				*mi_repository;
	int				 mi_flags;

	TAILQ_ENTRY(module_info)	 m_list;
};

struct module_checkout *cvs_module_lookup(char *);
#endif
