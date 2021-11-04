from vehicle import *


class Lorry(Vehicle):
    def __init__(self):
        self.lift_capacity = 0

    def read_str_array(self, str_array, i):
        if i >= len(str_array) - 2:
            return 0
        i = super(Lorry, self).read_str_array(str_array, i)
        self.lift_capacity = int(str_array[i])
        i += 1
        return i

    def fill_random(self):
        super(Lorry, self).fill_random()
        self.lift_capacity = random.randrange(1, 101)

    def write(self, ostream):
        ostream.write("Lorry: lift capacity = {}; ".format(self.lift_capacity))
        super(Lorry, self).write(ostream)
