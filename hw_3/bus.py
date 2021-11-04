from vehicle import *


class Bus(Vehicle):
    def __init__(self):
        self.passenger_capacity = 0

    def read_str_array(self, str_array, i):
        if i >= len(str_array) - 2:
            return 0
        i = super(Bus, self).read_str_array(str_array, i)
        self.passenger_capacity = int(str_array[i])
        i += 1
        return i

    def fill_random(self):
        super(Bus, self).fill_random()
        self.passenger_capacity = random.randrange(1, 101)

    def write(self, ostream):
        ostream.write("Bus: passenger capacity = {}; ".format(self.passenger_capacity))
        super(Bus, self).write(ostream)
