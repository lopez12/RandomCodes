#ifndef EXTERNALCLASSES 
#define EXTERNALCLASSES
#define ON 1
#define OFF 0
#define OPEN 1
#define CLOSE 0
	class valve
	{
		
		private:
			int open; // 1 = Open, 0 = Close
			int fault; // 1 = Fault, 0 = NO fault
		public:
			valve (int OpenStatus);		//Constructor
			int getOpenStatus(void); //Funcion para verificar el estado de la valvula (AKA sensor)
			int getFaultStatus(void);
			void setOpenStatus(int SettingOPEN);
	};
	
	valve::valve(int OpenStatus)
	{
		open = OpenStatus;
	}
	
	void valve :: setOpenStatus (int SettingOPEN)
	{
		open = SettingOPEN;
	}
	
	int valve:: getOpenStatus(void)
	{
		return open;
	}
	
	int valve:: getFaultStatus(void)
	{
		return fault;
	}
	
	
	class tank
	{
		private:
			int CurrentCapacity = 0;
		public:
			int MaxCapacity;
			tank (int MaxCapacityContructor); //Constructor para inicializar el valor maximo del tanque
			int getCurrentCapacity(void); //Funcion para verificar el nivel actual del tanque
			void addCapacity(int flow);
			void substractCapacity(int flow);
	};
	
	tank :: tank(int MaxCapacityContructor)
	{
		MaxCapacity = MaxCapacityContructor;
	}
	
	int tank :: getCurrentCapacity(void)
	{
		return CurrentCapacity;
	}
	
	void tank :: addCapacity(int flow)
	{
		CurrentCapacity = CurrentCapacity + flow;
	}
	
	void tank :: substractCapacity(int flow)
	{
		CurrentCapacity = CurrentCapacity - flow;
	}
	
	class pump
	{
		private:
			int On; //1 = On, 0 = Off
			int fault; // 1 = Fault, 0 = NO fault
		public:	
			pump (int OnConstructor);
			int getFaultStatus(void);	
			int getOnStatus(void);	
		
	};
	
	pump :: pump (int OnConstructor)
	{
		On = OnConstructor;
	}
	
	int pump:: getFaultStatus(void)
	{
		return fault;
	}
	
	int pump:: getOnStatus(void)
	{
		return On;
	}
	
	class mixer
	{
		private:
			int On;
		public:
			mixer(int OnConstructor);
			int getOnStatus(void);
	};
	
	mixer :: mixer(int OnConstructor)
	{
		On = OnConstructor;
	}
	
	int mixer:: getOnStatus(void)
	{
		return On;
	}
	
	
#endif
