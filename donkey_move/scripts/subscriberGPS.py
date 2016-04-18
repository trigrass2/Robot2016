#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from custom_msgs.msg import gnssSample
#basta?


def callback(data):
    #rospy.loginfo(rospy.get_caller_id() + "latitude: %0.3f longitude: %0.3f", (data.latitude,data.longitude))
    print "latitude: %0.3f longitude: %0.3f\n" % (data.latitude,data.longitude)
    
   
       
def main():
   
    		rospy.init_node('donkeyGPSListener', anonymous=True)

    		rospy.Subscriber("mti/sensor/gnssPvt", gnssSample, callback)

    		rospy.spin()
    
    


if __name__ == '__main__':
    main()







