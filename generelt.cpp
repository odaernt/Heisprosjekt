//OPPSTART
int initializer() {
	int floor = elev_get_floor_sensor_signal();

	// If floor is -1 it is unknown and we need to move the elevator
	//Vet ikke hvilken etasje heisen er i
	if (floor == -1)
	{
		// kjør til første ?
		while (floor == -1) {
			elev_set_motor_direction(DIRN_DOWN);
			floor = elev_get_floor_sensor_signal(void);
		}

	}
	elev_set_floor_indicator(floor);
	return floor;
	
}

//HÅNDTERING AV BESTILLINGER
int queue[N_FLOORS][4] = {
	{0, 0, 0, 0} , //Floor 1
	{0, 0, 0, 0} , //Floor 2
	{0, 0, 0, 0} , //Floor 3
	{0, 0, 0, 0} , //Floor 4
};

int 

int getDirection(int )

//BESTILLINGSLYS OG ETASJELYS	
