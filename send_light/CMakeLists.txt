#
# This file is part of HiKoB Openlab. 
# 
# HiKoB Openlab is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, version 3.
# 
# HiKoB Openlab is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with HiKoB Openlab. If not, see
# <http://www.gnu.org/licenses/>.
#
# Copyright (C) 2011 HiKoB.
#

if(${PLATFORM_HAS_PHY})

	
	add_executable(send_light1 send_light1)
	target_link_libraries(send_light1 platform)
	add_executable(send_light2 send_light2)
	target_link_libraries(send_light2 platform)
	add_executable(send_light3 send_light3)
	target_link_libraries(send_light3 platform)
 
 
endif(${PLATFORM_HAS_PHY})
