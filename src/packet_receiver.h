/*
 * packet_receiver.h
 *
 *  Created on: 05 ���� 2016 �.
 *      Author: Easy
 */

#ifndef PACKET_RECEIVER_H_
#define PACKET_RECEIVER_H_

void recive_packets_init();
void recive_packets_worker();
void recive_packets_print_stat();

void packet_send(const uint8_t code, const uint8_t *body, const uint32_t size);

#endif /* PACKET_RECEIVER_H_ */
