import socket
import pickle

# Object of frame
class Frame:
    def __init__(self, no, frame):
        self.sqnc_no = no
        self.frame = frame

    def byte_stuffing(self, flag, esc):
        x = self.frame.replace(esc, esc * 2)
        y = x.replace(flag, esc + flag)
        self.frame = flag + y + flag


# Create server socket
s = socket.socket()
print('Socket Created!')

# Bind host address and port together
host = socket.gethostname()
port = 5000
s.bind((host, port))

# maximum connections should wait in queue
s.listen(5)

while True:
    print('\nWaiting for connection...')
    # accept connection
    c, address = s.accept()
    print('\nConnected with', address)

    path = r"D:\Sem 5\CN\Textfile.txt"
    file = open(path, 'rb')

    # Read 1024 bytes from file
    frame = file.read(1024)
    frame_no = 1
    while frame:
        # create object of frame for 1024 bytes
        f = Frame(frame_no, frame.decode("utf-8"))
        # stuff those 1024 bytes
        f.byte_stuffing('x', 'y')
        # convert python object into character stream
        data = pickle.dumps(f)
        # send object to client
        c.send(data)
        # print stuffed frame
        print("-> Sending frame no", f.sqnc_no)
        print(f.frame)
        print("Frame sent!")
        # read next 1024 bytes from file
        frame = file.read(1024)
        # increment of frame number
        frame_no += 1
    # close connection with client
    c.close()

