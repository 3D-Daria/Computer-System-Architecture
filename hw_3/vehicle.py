import random


class Vehicle:
    def __init__(self):
        self.tank_capacity = 0
        self.fuel_per_100km = 0.0

    def read_str_array(self, str_array, i):
        if i >= len(str_array) - 1:
            return 0
        self.tank_capacity = int(str_array[i])
        self.fuel_per_100km = float(str_array[i + 1])
        i += 2
        return i

    def fill_random(self):
        self.tank_capacity = random.randrange(1, 101)
        self.fuel_per_100km = random.randrange(1, 101) * 0.01 + random.randrange(1, 101)

    def write(self, ostream):
        ostream.write("tank capacity = {} litres; fuel per 100km = {}; max distance = {}"
                      .format(self.tank_capacity, self.fuel_per_100km, self.max_distance()))

    def max_distance(self):
        return self.tank_capacity * 100.0 / self.fuel_per_100km
