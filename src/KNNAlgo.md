# KNN Algorithm

1. Load the data
2. Initialize K to some number For each row in the data
    3.1 Calculate the distance between query and the current example from the data
    3.2 Add the distance and the index of the example to an ordered collection
4. Sort the ordered collection from smallest to largest
5. Pick the first K entries from the collection
6. Get the labels of the selected K entries
7. If classification, return the mode of the K labels
