from vehicle import *


class Motorcar(Vehicle):
    def __init__(self):
        self.max_speed = 0

    def read_str_array(self, str_array, i):
        if i >= len(str_array) - 2:
            return 0
        i = super(Motorcar, self).read_str_array(str_array, i)
        self.max_speed = int(str_array[i])
        i += 1
        return i

    def fill_random(self):
        super(Motorcar, self).fill_random()
        self.max_speed = random.randrange(1, 101)

    def write(self, ostream):
        ostream.write("Motorcar: max speed = {}; ".format(self.max_speed))
        super(Motorcar, self).write(ostream)
