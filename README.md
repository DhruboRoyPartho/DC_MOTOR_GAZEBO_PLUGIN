# Gazebo DC Motor Plugin

This repository contains a **Gazebo Plugin** that simulates a **DC Motor** in the Gazebo 11.10.2 simulator. The plugin allows controlling a motor in a physics-based simulation.

## **Features**
- Simulates the electromechanical properties of a **DC motor**
- Uses **Gazebo Model Plugin API**
- Rotates a joint based on motor parameters

## **Installation & Compilation**

### **1. Install Dependencies**
Ensure you have **Gazebo 11.10.2** installed:
```bash
sudo apt update
sudo apt install gazebo11 libgazebo11-dev
```

### **2. Clone the Repository**
```bash
git clone https://github.com/your-username/gazebo_dc_motor_plugin.git
cd gazebo_dc_motor_plugin
```

### **3. Build the Plugin**
```bash
mkdir build && cd build
cmake ..
make
```
After successful compilation, a shared object file **`libdc_motor_plugin.so`** will be generated in the `build/` directory.

### **4. Set Plugin Path**
Ensure Gazebo can find the plugin by setting the environment variable:
```bash
export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)/build
```
To make this permanent:
```bash
echo 'export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)/build' >> ~/.bashrc
source ~/.bashrc
```

## **Usage**

### **1. Run Gazebo with the DC Motor Model**
```bash
gazebo src/dc_motor_model.sdf --verbose
```
If the plugin loads correctly, you should see:
```
[DEBUG] DC Motor Plugin Loaded Successfully!
```

### **2. Check Plugin Logs**
If you don't see the message above, check Gazebo logs:
```bash
cat ~/.gazebo/default.log | grep plugin
```

## **File Structure**
```
📂 gazebo_dc_motor_plugin/
├── 📂 src/                # Source files
│   ├── dc_motor_plugin.cpp  # Plugin implementation
│   ├── dc_motor_model.sdf   # SDF model for Gazebo
├── 📂 build/              # Compiled plugin (generated after make)
├── CMakeLists.txt        # Build configuration
└── README.md             # Project documentation
```

## **Troubleshooting**

### **1. Plugin Not Found**
If you get an error like:
```
[Err] [Plugin.hh:178] Failed to load plugin libdc_motor_plugin.so
```
Try:
```bash
export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)/build
```

### **2. Gazebo Fails to Start**
Check if another Gazebo instance is running:
```bash
ps aux | grep gazebo
```
If necessary, kill the process:
```bash
killall gazebo
```

## **Contributing**
Feel free to open issues and submit pull requests to improve the plugin!

## **License**
This project is released under the **Apache 2.0 License**.

---
### **Author:** Your Name

