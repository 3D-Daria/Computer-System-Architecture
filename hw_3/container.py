import time


class Container:
    def __init__(self):
        self.storage = []

    def write(self, ostream):
        ostream.write("There are {} vehicles in the container\n".format(len(self.storage)))
        for vehicle in self.storage:
            vehicle.write(ostream)
            ostream.write("\n")
        timer_start = time.perf_counter()
        self.bubble_sort()
        timer_end = time.perf_counter()
        print(f"Sorting time: {timer_end - timer_start:0.6f} seconds")
        ostream.write("\n\n\nAfter Bubble sort:\n")
        for vehicle in self.storage:
            vehicle.write(ostream)
            ostream.write("\n")

    def bubble_sort(self):
        changed = True
        i = 0
        while (i < len(self.storage)) and changed:
            changed = False
            for j in range(0, len(self.storage) - i - 1):
                if self.storage[j].max_distance() > self.storage[j + 1].max_distance():
                    v = self.storage[j]
                    self.storage[j] = self.storage[j + 1]
                    self.storage[j + 1] = v
                    changed = True
