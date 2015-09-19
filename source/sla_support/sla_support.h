/*
 * =====================================================================================
 *
 *       Filename:  sla_support.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 19 September 2015 03:12:17  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rohit Kumar (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _sla_support_h
#define _sla_support_h

typedef enum _priority_e{
	low = 0;
	normal,
	high,
	urgent,
}priority_e;

typedef enum _cur_status_e{
	pending = 0;
	working,
	resolved,
}cur_status_e;

typedef struct _assigned_state_t{
	char status;
	int  assign_hr;
	struct date assign_dt;
}assign_state;

typedef struct _resolve_state_t{
	char status;
	int  resolve_hr;
	struct date resolv_dt;
}resolve_state;

typedef struct _ticket_attributes_t{
	int ticket_id;
	priority_e priority;
	struct assign_state;
	struct resolve_time;
	cur_status_e cur_status;
}ticket_state;

int get_ticket_status(ticket_state *tkt){
	
	int rval;
	ticket_state *ltkt;

	rval = get_ticket_info(&ltkt);
	if(SUCCESS != rval){
		printf("Unable to get ticket info\n");
		return GET_TICKET_STATUS_FAILED;
	}
	tkt = ltkt;		
	return SUCCESS;
}

int set_ticket_info(int ticket_id, priority_e priority, struct assign_state, struct resolve_state, cur_status_e cur_status){

	ticket_state *tkt;
	
	tkt = malloc(sizeof(ticket_state));
	memset(tkt, 0, sizeof(ticket_state));
	
	tkt->ticket_id = ticket_id;
	tkt->priority  = priority;
	tkt->assign_state = assign_state;
	tkt->resolve_state = resolve_state;
	tkt->cur_status = cur_status;	
}

#endif

