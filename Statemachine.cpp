//Generelt/State machine
//Åpne dør
void open_door(void) {
	elev_set_door_open_lamp(1); 
}

//Lukke dør
void close_door(void) {
	elev_set_door_open_lamp(0);
}

//Stopp heis
void stop_elev() {
	elev_set_motor_direction(DIRN_STOP);
}

//Nødknapp
void emergency_stop() {
	stop_elev();
	elev_set_stop_lamp(1);
	//SLETT ALLE BESTILLINGER
	if (!(elev_get_floor_sensor_signal(void)) == -1) { //in a floor
		while(elev_get_stop_signal(void)) {
			open_door();
		}
		//TIMER 3 SEK
		close_door();
	}
	else {
		while (elev_get_stop_signal(void)) {
			//IGNORER ALLE BESTILLINGER
		}
	}
}

//Status
typedef enum state_machine_type {
	MOVING,
	IDLE,
	STOP,
	EMERGENCY
} state_machine_type_t;

