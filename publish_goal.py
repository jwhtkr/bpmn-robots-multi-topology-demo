import rclpy
import zmq
from rclpy.node import Node
from std_msgs.msg import String

CONST_CONTEXT = zmq.Context()
CONST_SOCKET = CONST_CONTEXT.socket(zmq.REP)
CONST_SOCKET.bind("tcp://*:5555")

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.listener_callback()
        # self.subscription = self.create_subscription(
        #     String,
        #     'topic',
        #     self.listener_callback,
        #     10)
        # self.subscription  # prevent unused variable warning

    def listener_callback(self):
        while 1:
            message = CONST_SOCKET.recv()
            print(f"Received request: {message.decode('utf-8')}")
            CONST_SOCKET.send(b"butts")
        #self.get_logger().info('I heard: "%s"' % "test")


def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()