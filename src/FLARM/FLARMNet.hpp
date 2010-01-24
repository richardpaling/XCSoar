/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009

	M Roberts (original release)
	Robin Birch <robinb@ruffnready.co.uk>
	Samuel Gisiger <samuel.gisiger@triadis.ch>
	Jeff Goodenough <jeff@enborne.f2s.com>
	Alastair Harrison <aharrison@magic.force9.co.uk>
	Scott Penrose <scottp@dd.com.au>
	John Wharington <jwharington@gmail.com>
	Lars H <lars_hn@hotmail.com>
	Rob Dunning <rob@raspberryridgesheepfarm.com>
	Russell King <rmk@arm.linux.org.uk>
	Paolo Ventafridda <coolwind@email.it>
	Tobias Lohner <tobias@lohner-net.de>
	Mirek Jezek <mjezek@ipplc.cz>
	Max Kellermann <max@duempel.org>
	Tobias Bieniek <tobias.bieniek@gmx.de>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#ifndef XCSOAR_FLARM_NET_HPP
#define XCSOAR_FLARM_NET_HPP

#include <map>
#include <stdio.h>
#include <tchar.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/**
 * FLARMnet.org file entry
 */
class FLARMNetRecord
{
public:
  TCHAR id[7];          /**< FLARM id 6 bytes */
  TCHAR name[22];       /**< Name 15 bytes */
  TCHAR airfield[22];   /**< Airfield 4 bytes */
  TCHAR type[22];       /**< Aircraft type 1 byte */
  TCHAR reg[8];         /**< Registration 7 bytes */
  TCHAR cn[4];          /**< Callsign 3 bytes */
  TCHAR freq[8];        /**< Radio frequency 6 bytes */
  long GetId();
};

/**
 * Handles the FLARMnet.org file
 */
class FLARMNetDatabase : protected std::map<long, FLARMNetRecord*>
{
private:
  void GetAsString(HANDLE hFile, int charCount, TCHAR *res);
  void GetItem(HANDLE hFile, FLARMNetRecord *flarmId);
public:
  FLARMNetDatabase(void);
  FLARMNetRecord *Find(long id);
  FLARMNetRecord *Find(const TCHAR *cn);
};

#endif
