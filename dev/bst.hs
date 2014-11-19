-- :set et ts=4
-- "standard" plus "leaf optimised" bst for comparison
-- Idea is to apply same idea used to optimise 234 trees and also
-- to redesign the data structure to replicate the coding style
-- where we check for NULL before recursive calls, reducing the
-- number of recursive calls at the cost of code complexity.

module BST where

data Tree k v = Leaf | Node k v (Tree k v) (Tree k v)
    deriving (Eq, Show)

countnodes :: Tree k v -> Int
countnodes Leaf = 0
countnodes (Node _ _ l r) = 1 + (countnodes l) + (countnodes r)

search_bst :: Ord k => Tree k v -> k -> Maybe v
search_bst Leaf _ = Nothing
search_bst (Node k v l r) sk =
    if k == sk then
        Just v
    else if sk < k then
        search_bst l sk
    else
        search_bst r sk

insert_bst :: Ord k => Tree k v -> k -> v -> Tree k v
insert_bst Leaf ik iv = Node ik iv Leaf Leaf
insert_bst (Node k v l r) ik iv =
    if k == ik then
        Node ik iv l r
    else if ik < k then
        Node k v (insert_bst l ik iv) r
    else
        Node k v l (insert_bst r ik iv)

assoc_list_to_bst :: Ord k => [(k, v)] -> Tree k v
assoc_list_to_bst [] = Leaf
assoc_list_to_bst ((hk, hv):kvs) =
    let t0 = assoc_list_to_bst kvs
    in insert_bst t0 hk hv

assoc_list_to_bst2 :: Ord k => [(k, v)] -> Tree k v
assoc_list_to_bst2 [] = Leaf
assoc_list_to_bst2 ((hk, hv):kvs) = insert_bst t0 hk hv
    where t0 = assoc_list_to_bst2 kvs

----------------------------------------------------------------------
-- here we avoid all empty trees except at the top level
-- Very messy:-(need 4 cases within tree + two at top level)
-- Is there a better way?  Maybe the test before recursive call
-- doesn't really correspond to data type in a nice way and we
-- can't nicely redesign binary trees.  Could try a version without
-- Justl and Justr, but then it seems we need a Leaf case with no data
-- for unbalanced trees (three cases within tree and no separate top
-- level- perhaps not too bad but not like programming style
-- particularly).  Should implement this. 234 trees seem extra nice
-- partly because they are perfectly balanced?


data LOTree k v = Empty | Full (Tree1 k v)
    deriving (Eq, Show)
data Tree1 k v = Leaf1 k v | Justl k v (Tree1 k v) | Justr k v (Tree1 k v)
    | Both k v (Tree1 k v) (Tree1 k v)
    deriving (Eq, Show)

countlonodes :: LOTree k v -> Int
countlonodes Empty = 0
countlonodes (Full t) = countlonodes1 t

countlonodes1 :: Tree1 k v -> Int
countlonodes1 (Leaf1 _ _) = 1
countlonodes1 (Justl _ _ t) = 1 + countlonodes1 t
countlonodes1 (Justr _ _ t) = 1 + countlonodes1 t
countlonodes1 (Both _ _ l r) = 1 + (countlonodes1 l) + (countlonodes1 r)

search_lobst :: Ord k => LOTree k v -> k -> Maybe v
search_lobst Empty _ = Nothing
search_lobst (Full t) sk = search_lobst1 t sk

search_lobst1 :: Ord k => Tree1 k v -> k -> Maybe v
search_lobst1 (Leaf1 k v) sk =
    if k == sk then
        Just v
    else
        Nothing
search_lobst1 (Justl k v t) sk =
    if k == sk then
        Just v
    else if sk < k then
        search_lobst1 t sk
    else
        Nothing
search_lobst1 (Justr k v t) sk =
    if k == sk then
        Just v
    else if sk < k then
        Nothing
    else
        search_lobst1 t sk
search_lobst1 (Both k v l r) sk =
    if k == sk then
        Just v
    else if sk < k then
        search_lobst1 l sk
    else
        search_lobst1 r sk

insert_lobst :: Ord k => LOTree k v -> k -> v -> LOTree k v
insert_lobst Empty ik iv = Full (Leaf1 ik iv)
insert_lobst (Full t) ik iv = Full (insert_lobst1 t ik iv)

insert_lobst1 :: Ord k => Tree1 k v -> k -> v -> Tree1 k v
insert_lobst1 (Leaf1 k v) ik iv =
    if k == ik then
        Leaf1 k v
    else if ik < k then
        (Justl k v (Leaf1 ik iv))
    else
        (Justr k v (Leaf1 ik iv))
insert_lobst1 (Justl k v t) ik iv =
    if k == ik then
        (Justl k v t)
    else if ik < k then
        Justl k v (insert_lobst1 t ik iv)
    else
        Both k v (Leaf1 ik iv) t
insert_lobst1 (Justr k v t) ik iv =
    if k == ik then
        (Justr k v t)
    else if ik < k then
        Both k v t (Leaf1 ik iv)
    else
        Justr k v (insert_lobst1 t ik iv)
insert_lobst1 (Both k v l r) ik iv =
    if k == ik then
        Both ik iv l r
    else if ik < k then
        Both k v (insert_lobst1 l ik iv) r
    else
        Both k v l (insert_lobst1 r ik iv)

assoc_list_to_lobst :: Ord k => [(k, v)] -> LOTree k v
assoc_list_to_lobst [] = Empty
assoc_list_to_lobst ((hk, hv):kvs) =
    let t0 = assoc_list_to_lobst kvs
    in insert_lobst t0 hk hv

assoc_list_to_lobst2 :: Ord k => [(k, v)] -> LOTree k v
assoc_list_to_lobst2 [] = Empty
assoc_list_to_lobst2 ((hk, hv):kvs) = insert_lobst t0 hk hv
    where t0 = assoc_list_to_lobst2 kvs

t1 :: LOTree Int String
t1 = assoc_list_to_lobst [(3,"a"), (10,"b"), (5,"c"), (4,"a"), (1,"b"), (15,"c")]

t2 = [search_lobst t1 4, search_lobst t1 42]


