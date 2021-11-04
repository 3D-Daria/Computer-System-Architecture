from vehicle import *
from bus import *
from lorry import *
from motorcar import *
from container import *


def read_str_array(container, str_array):
    array_len = len(str_array)
    i = 0
    vehicles_count = 0
    while i < array_len:
        key = int(str_array[i])
        if key == 1:
            vehicle = Lorry()
        elif key == 2:
            vehicle = Bus()
        elif key == 3:
            vehicle = Motorcar()
        else:
            return vehicles_count
        i = vehicle.read_str_array(str_array, i + 1)
        if i == 0:
            return vehicles_count
        vehicles_count += 1
        container.storage.append(vehicle)
    return vehicles_count


def fill_random(container, n):
    for i in range(0, n):
        key = random.randrange(1, 4)
        if key == 1:
            vehicle = Lorry()
        elif key == 2:
            vehicle = Bus()
        else:
            vehicle = Motorcar()
        vehicle.fill_random()
        container.storage.append(vehicle)
