
## Simple Factory

The Simple Factory pattern centralizes the creation logic into a single class. This class is not abstract and typically includes a method that returns instances of different concrete products, often based on a parameter. Unlike the Factory Method, where the creation logic is deferred to subclasses, the Simple Factory directly handles the creation process in a single place.

Here¡¯s the modification to your explanation and code based on the Simple Factory pattern.

Simple Factory
Define a class with a method to create objects of various types. The Simple Factory pattern centralizes the creation of objects in one place, typically by using a static method. It does not defer instantiation to subclasses, and all products are created in a single factory class. This pattern simplifies the creation process by eliminating the need for multiple subclasses, unlike the Factory Method, where creation is delegated to subclasses.

### When to use

You want to encapsulate the logic of object creation in one location (the factory).
The client should not be concerned with the concrete class of objects it needs.
The set of product types is relatively stable and doesn¡¯t require frequent changes.