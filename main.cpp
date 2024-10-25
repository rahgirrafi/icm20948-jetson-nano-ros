
#include "ICM20948.h"
// #include <ros/ros.h>
// #include <sensor_msgs/Imu.h>
// #include <sensor_msgs/MagneticField.h>
// #include <std_msgs/Float32.h>
// #include <std_msgs/Float64.h>

int main(int argc, char **argv)
{
	// ros::init(argc, argv, "icm20948_node");
	// ros::NodeHandle nh;

	// ros::Publisher imu_pub = nh.advertise<sensor_msgs::Imu>("imu", 20);
	// ros::Publisher mag_pub = nh.advertise<sensor_msgs::MagneticField>("magnetic_field", 1);
	
	IMU_EN_SENSOR_TYPE enMotionSensorType;
	IMU_ST_ANGLES_DATA stAngles;
	IMU_ST_SENSOR_DATA stGyroRawData;
	IMU_ST_SENSOR_DATA stAccelRawData;
	IMU_ST_SENSOR_DATA stMagnRawData;

	imuInit(&enMotionSensorType);
	if(IMU_EN_SENSOR_TYPE_ICM20948 == enMotionSensorType)
	{
		printf("Motion sensor is ICM-20948\n");
	}
	else
	{
		printf("Motion sensor NULL\n");
		return -1;
	}
	// ros::Rate loop_rate(20);

	while(1)
	{
		imuDataGet( &stAngles, &stGyroRawData, &stAccelRawData, &stMagnRawData);
		// sensor_msgs::Imu imu_msg;
		// imu_msg.header.stamp = ros::Time::now();
		// imu_msg.header.frame_id = "imu_link";

		//  // Fill orientation (angles)
        // imu_msg.orientation.x = stAngles.fRoll;
        // imu_msg.orientation.y = stAngles.fPitch;
        // imu_msg.orientation.z = stAngles.fYaw;

        // // Fill angular velocity (gyroscope)
        // imu_msg.angular_velocity.x = stGyroRawData.fX;
        // imu_msg.angular_velocity.y = stGyroRawData.fY;
        // imu_msg.angular_velocity.z = stGyroRawData.fZ;

        // // Fill linear acceleration (accelerometer)
        // imu_msg.linear_acceleration.x = stAccelRawData.fX;
        // imu_msg.linear_acceleration.y = stAccelRawData.fY;
        // imu_msg.linear_acceleration.z = stAccelRawData.fZ;

        // imu_pub.publish(imu_msg);

		//  // Create magnetic field message
        // sensor_msgs::MagneticField mag_msg;
        // mag_msg.header.stamp = ros::Time::now();
        // mag_msg.header.frame_id = "imu_link";

        // mag_msg.magnetic_field.x = stMagnRawData.fX;
        // mag_msg.magnetic_field.y = stMagnRawData.fY;
        // mag_msg.magnetic_field.z = stMagnRawData.fZ;

        // mag_pub.publish(mag_msg);

		// ros::spinOnce();
        // loop_rate.sleep();
		printf("\r\n /-------------------------------------------------------------/ \r\n");
		printf("\r\n Angle：Roll: %.2f     Pitch: %.2f     Yaw: %.2f \r\n",stAngles.fRoll, stAngles.fPitch, stAngles.fYaw);
		printf("\r\n Acceleration(g): X: %.3f     Y: %.3f     Z: %.3f \r\n",stAccelRawData.fX, stAccelRawData.fY, stAccelRawData.fZ);
		printf("\r\n Gyroscope(dps): X: %.3f     Y: %.3f     Z: %.3f \r\n",stGyroRawData.fX, stGyroRawData.fY, stGyroRawData.fZ);
		printf("\r\n Magnetic(uT): X: %.3f     Y: %.3f     Z: %.3f \r\n",stMagnRawData.fX, stMagnRawData.fY, stMagnRawData.fZ);
		usleep(100*1000);

	}
	return 0;
}
		
