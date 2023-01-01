import socket
import pickle

# Object of frame
class Frame:
    def __init__(self):
        self.sqnc_no = None
        self.frame = None

    def byte_unstuffing(self, flag, esc):
        x = str(self.frame).replace(esc*2, esc)
        y = str(x).replace(esc + flag, flag)
        self.frame = y[1:-1]


# create socket
c = socket.socket()
print('Socket Created!\n')

# connect with host
host = socket.gethostname()
port = 5000
c.connect((host, port))

while True:
    try:
        # receive object from server
        client_data = c.recv(4096)
        data = pickle.loads(client_data)

        if data.frame:
            # print sequence number of frame
            print("-> Receiving frame no", data.sqnc_no)
            # unstuffing of frame
            data.byte_unstuffing('x', 'y')
            # print frame after unstuffing
            print(data.frame)
            print("Frame received!")
    except EOFError:
        break
