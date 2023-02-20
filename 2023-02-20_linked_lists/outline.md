# Linked List
* Array lists take up **contiguous** memory
    * Sometimes we don't have that!
* How do we store a list of things in noncontiguous memory?
    * Each thing has a pointer to the "next" thing in the list
* A linked list!
* A `node`, which has a `payload` and `next` pointer (which is a pointer to a node)

## Pictures
* Whenever you work with a linked list, DRAW PICTURES

## Creating a linked list
1. Allocate space for a `struct implementation`
1. Set the `head` pointer to `NULL`
1. That's it!

## Appending to a linked list
1. Allocate a new `node`
1. Set the payload
1. Assign the previous end of the list's `next` pointer to this one
    * How to get "the previous end of the list"?

## Removing from the end of a linked list
1. Find the node at the end of the list
    * How to find "the node at the end of the list"?
1. Get its payload (to return later)
1. Deallocate that node
1. Set the second-to-last pointer's `next` to `NULL`

## Querying the length of a linked list
1. Traverse the list

## Printing a list
1. Print the head node
1. Print the rest of the list
    * How do we print "the rest of the list"?

## Can we make it better?
* Compute the length?
    * Traverse the list
* How to get to "the previous end of the list"?
    * Traverse the list
* How to get "the node at the end of the list"?
    * Traverse the list
* We've got a bunch of inelegant `if head is not null` things
* Random access?
    * Traverse the list

### Possibilities
1. Add a `end` pointer
    * OK, easy access to *both* ends of the list. But complicated appending/removing
1. Reverse the order
    * Now "the end of the list" is just head. Since that's all we're working with, this is a huge win. Appending/removing is super easy
1. To improve elegance: add a "dummy node" as head
1. To improve random access: ???
