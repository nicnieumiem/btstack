/*
 * Copyright (C) 2018 BlueKitchen GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 4. Any redistribution, use, or modification is done solely for
 *    personal benefit and not for any commercial purpose or for
 *    monetary gain.
 *
 * THIS SOFTWARE IS PROVIDED BY BLUEKITCHEN GMBH AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MATTHIAS
 * RINGWALD OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Please inquire about commercial licensing options at 
 * contact@bluekitchen-gmbh.com
 *
 */

#ifndef __MESH_PROXY_H
#define __MESH_PROXY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    MESH_NODE_IDENTITY_STATE_ADVERTISING_STOPPED = 0,
    MESH_NODE_IDENTITY_STATE_ADVERTISING_RUNNING,
    MESH_NODE_IDENTITY_STATE_ADVERTISING_NOT_SUPPORTED
} mesh_node_identity_state_t;

/**
 * @brief Init Mesh Proxy
 */
void mesh_proxy_init(uint16_t primary_unicast_address, const uint8_t * identity_key);

/**
 * @brief Start Advertising with Node ID on given subnet
 * @param netkey_index of subnet
 * @note Node ID is only advertised on one subnet at a time and it is limited to 60 seconds
 */
void mesh_proxy_start_advertising_with_node_id(uint16_t netkey_index);

/**
 * @brief Stop Advertising with Node ID on given subnet
 * @param netkey_index of subnet
 */
void mesh_proxy_stop_advertising_with_node_id(uint16_t netkey_index);

/**
 * @brief Set Advertising with Node ID on given subnet
 * @param netkey_index of subnet
 * @returns MESH_FOUNDATION_STATUS_SUCCESS, MESH_FOUNDATION_STATUS_FEATURE_NOT_SUPPORTED, or MESH_FOUNDATION_STATUS_INVALID_NETKEY_INDEX
 */
uint8_t mesh_proxy_set_advertising_with_node_id(uint16_t netkey_index, mesh_node_identity_state_t state);

/**
 * @brief Check if Advertising with Node ID is active
 * @param netey_index of subnet
 * @param out_state current state
 * @returns MESH_FOUNDATION_STATUS_SUCCESS or MESH_FOUNDATION_STATUS_INVALID_NETKEY_INDEX
 */
uint8_t mesh_proxy_get_advertising_with_node_id_status(uint16_t netkey_index, mesh_node_identity_state_t * out_state );

/**
 * @brief Start Advertising with Network ID (on all subnets)
 */
void mesh_proxy_start_advertising_with_network_id(void);

/**
 * @brief Stop Advertising with Network ID (on all subnets)
 */
void mesh_proxy_stop_advertising_with_network_id(void);


#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif