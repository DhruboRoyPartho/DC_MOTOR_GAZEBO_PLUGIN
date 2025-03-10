#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <iostream>

namespace gazebo
{
    class DCMotorPlugin : public ModelPlugin
    {
    public:
        DCMotorPlugin() : ModelPlugin() {}

        void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
        {
            this->model = _model;
            this->joint = _model->GetJoint("motor_joint");

            if (!this->joint)
            {
                std::cerr << "Joint 'motor_joint' not found!" << std::endl;
                return;
            }

            this->updateConnection = event::Events::ConnectWorldUpdateBegin(
                std::bind(&DCMotorPlugin::OnUpdate, this));

            std::cout << "DC Motor Plugin Loaded!" << std::endl;
        }

        void OnUpdate()
        {
            double voltage = 12.0;  // Example voltage (V)
            double resistance = 1.0; // Resistance (Ohms)
            double torque_constant = 0.1; // Torque constant (Nm/A)

            double current = voltage / resistance; // Ohm’s law: I = V/R
            double torque = current * torque_constant; // Torque = I * Kt

            this->joint->SetForce(0, torque); // Apply torque to the joint
        }

    private:
        physics::ModelPtr model;
        physics::JointPtr joint;
        event::ConnectionPtr updateConnection;
    };

    GZ_REGISTER_MODEL_PLUGIN(DCMotorPlugin)
}
