/*
 * This file is part of HiKoB Openlab.
 *
 * HiKoB Openlab is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, version 3.
 *
 * HiKoB Openlab is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with HiKoB Openlab. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2011,2012 HiKoB.
 */

/**
 * \example example_phy_tx_rx.c
 *
 * This example shows how to use the PHY library to send and receive packets
 * on a radio channel.
 *
 * \date Oct 3, 2012
 * \author Clément Burin des Roziers <clement.burin-des-roziers.at.hikob.com>
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "platform.h"
#include "phy.h"
#include "event.h"
#include "soft_timer.h"
#include "unique_id.h"

#define RADIO_CHANNEL 14
#define TX_PERIOD soft_timer_ms_to_ticks(1500)

/** Enter RX state */
static void enter_rx(handler_arg_t arg);
/** Handle end of RX */
static void rx_done(phy_status_t status);
/** Process received packet */
static void process_rx_packet(handler_arg_t arg);

/** Packet for receiving */
static phy_packet_t rx_packet;

int main()
{
    // Initialize the platform
    platform_init();

    event_init();
    soft_timer_init();

    // Begin with RX
    event_post(EVENT_QUEUE_APPLI, enter_rx, NULL);
 
    // Run
    platform_run();
    return 0;
}

static void enter_rx(handler_arg_t arg)
{
    // Set PHY IDLE, then enter RX
    phy_idle(platform_phy);
    phy_set_channel(platform_phy, RADIO_CHANNEL);
    // Prepare packet and start RX
    phy_prepare_packet(&rx_packet);
    phy_rx_now(platform_phy, &rx_packet, rx_done);

}

static void rx_done(phy_status_t status)
{
    switch (status)
    {
        case PHY_SUCCESS:
            event_post(EVENT_QUEUE_APPLI, process_rx_packet, NULL);
	
            break;
        default:
            // Bad packet
            event_post(EVENT_QUEUE_APPLI, enter_rx, NULL);
		
            break;
    }
}

static void process_rx_packet(handler_arg_t arg)
{

    // Make sure data is terminated with a \0
    rx_packet.data[rx_packet.length] = 0;
	if (

    // Print the data
    printf("%s\n",rx_packet.data);

    // Enter RX again
    enter_rx(NULL);
}

