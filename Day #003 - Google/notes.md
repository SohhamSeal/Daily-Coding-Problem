## Personal notes
It seems that the serialize() function can be created in any possible manner. In this case, I have though of using a simple pre-order of the tree traversal and replacing each Null value with an asterix('*'). 
This helps in determining the leaf nodes while we are deserializing.

Therefore, we can in general use any type of traversal method for the serialization of the tree and then accordingly use a proper deserialize() function. 
