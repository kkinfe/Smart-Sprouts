# Smart-Sprouts - Proteus Simulation

 **Smart-Sprouts.pdsprj** includes a detailed Proteus simulation for the Smart-Sprouts automated irrigation system. The simulation allows you to visualize and test the functionality of the system without the need for physical hardware. It provides a virtual environment where you can observe the behavior of the system and validate its performance.

## Simulation Components

The Proteus simulation consists of the following components:

1. **Arduino Mega Microcontroller:** The Arduino Mega microcontroller is the main control unit of the Smart-Sprouts system. It executes the code and interfaces with the simulated sensors and actuators.

2. **Soil Moisture Sensor:** The simulated soil moisture sensor measures the moisture content in the soil. It provides input to the Arduino Mega, allowing it to make decisions about watering.

3. **SIM900D GSM Module:** The SIM900D GSM module simulates the communication functionality of the Smart-Sprouts system. It enables the system to send notifications and receive commands remotely.

4. **LCD Display:** The LCD display simulates the user interface of the Smart-Sprouts system. It provides real-time information on soil moisture levels, watering schedules, and other relevant data.

5. **Water Level Sensor:** The water level sensor simulates the detection of water levels in the reservoir. It allows the system to monitor the availability of water for irrigation.

6. **Water Pump:** The water pump is responsible for delivering water to the plants. In the simulation, it can be controlled by the Arduino Mega based on the watering requirements determined by the soil moisture sensor and water level sensor.

7. **Reservoir:** The reservoir simulates the water source for the irrigation system. It provides the necessary water supply for the watering process.

## Running the Simulation

To run the Smart-Sprouts Proteus simulation, follow these steps:

1. Install Proteus: Ensure you have Proteus installed on your computer. If you don't have it, you can download it from the [Labcenter Electronics website](https://www.labcenter.com/).

2. Clone the Repository: Clone this repository to your local machine using the command:
   ```
   git clone https://github.com/KKinfe/Smart-Sprouts.git
   ```

3. Open the Simulation: Launch Proteus and navigate to the location where you cloned the repository. Open the Smart-Sprouts simulation file (`smart_sprouts.pdsprj`).

4. Start the Simulation: In Proteus, click on the "Play" button or use the appropriate menu option to start the simulation. This will initiate the execution of the Smart-Sprouts code and simulate the behavior of the system.

5. Observe the Results: As the simulation runs, you can observe the behavior of the system in the Proteus workspace. Monitor the sensor readings, check the control signals sent to the water pump, and observe how the system reacts to changes in moisture levels and water availability.

6. Customize and Experiment: You can modify the simulation to test different scenarios and parameters. Adjust the sensor readings, change the watering thresholds, or introduce variations in water levels to observe the system's response.

## Simulation Validation and Testing

The Proteus simulation provides an excellent platform for validating and testing the Smart-Sprouts system before deploying it on physical hardware. You can use the simulation to verify the correctness of the code, fine-tune the watering algorithms, and evaluate the system's performance under various conditions. Additionally, the simulation allows for easier debugging and troubleshooting, as you can observe the internal workings of the system in real-time.

## Contributing

Contributions to the Smart-Sprouts Proteus simulation are welcome! If you have ideas for improving the simulation or adding new features, feel free to fork the repository, make your changes, and submit a pull request. Your contributions will help enhance the simulation and make it even more useful for the Smart-Sprouts community.

## License

The Smart-Sprouts Proteus Simulation is licensed under the MIT License. You are free to use, modify, and distribute the simulation for personal or commercial purposes.
