#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import Twist

def talker():
    pub = rospy.Publisher('/catvehicle/cmd_vel', Twist, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    vel, omega = 0, 0
    while not rospy.is_shutdown():
        vel += 0.1
        omega += 0.1
        cmd_vel = {}
        cmd_vel['linear'] = [vel, 0, 0]
        cmd_vel['angular'] = [0, 0, omega]

        # message = "hello world %s" % cmd_vel
        rospy.loginfo(cmd_vel)
        pub.publish(cmd_vel)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
