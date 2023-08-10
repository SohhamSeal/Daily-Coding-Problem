## Personal notes

In my study of tree serialization techniques, I've realized that creating the `serialize()` function offers numerous options. To illustrate this, I've focused on a specific method that involves a simple way of visiting tree nodes, known as the **pre-order traversal**. This method is combined with a smart idea to handle branch endings, denoted by `Null` or `nullptr` values.

In this approach, the pre-order traversal becomes the core of the serialization process. This means we follow a specific order of visiting nodes in the tree, starting from the root and moving towards the leaves. By recording the values of nodes in this order, we lay the groundwork for representing the tree in a serialized form.

One unique aspect of my approach deals with how we handle Null values, which indicate that there are no child nodes during traversal. To tackle this, I've developed a plan where we replace Null values with an asterisk ('*') in the serialized sequence. This replacement not only keeps the serialization intact but also plays a vital role when we later reverse the process during deserialization. It helps us identify nodes that have no children, which aids in accurately rebuilding the tree's structure, without having to know the inorder of the tree, etc.

Interestingly, it's important to mention that we're not limited to just the pre-order traversal approach. There are various other ways to traverse the tree, such as in-order, post-order, and level-order traversals, which can also be adapted to create the `serialize()` function.

The significance of this exploration also extends to the reverse process, called deserialization. The method we choose for serialization greatly influences how we design the `deserialize()` function. By aligning the deserialization method with the serialization technique, we ensure a smooth process of accurately reconstructing the original tree structure from the serialized data.
