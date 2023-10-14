class Person:
    def __init__(self, name):
        self.name = name

def greet(self):
    print(f"Hello, I'm {self.name}!")

minky = Person("Momo")
greet(minky)

Person.greet = greet
minky.greet()
