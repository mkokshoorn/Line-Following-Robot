#define LEFT 0
#define RIGHT 1

#define FWD 0
#define BK 1

#define ON 1 
#define OFF 0

#define RIGHT_FWD 0x04
#define LEFT_BK 0x01
#define RIGHT_BK 0x08
#define LEFT_FWD 0x02


void motor_init(void);

void motor_logic(int side,int dir,int val);


	
void motor_stop(void);
	
void motor_forward(void);

void motor_backward(void);
void motor_pivot_left(void);
	

void motor_pivot_right(void);
	
	
	
	