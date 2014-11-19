-- :set et ts=4

-- "top-down" two-three-four tree stuff in Haskell
-- illustrates nice use of ADT which is hard to implement in C nicely

-- Here we have an (optionally) optimised version which has specialised leaf
-- nodes.  With red-black tree we have two pointers per key.  Here around
-- 70% of nodes are leaves (at a guess), with no pointers.  The remaining
-- nodes have 4/3 to 2/1 pointers per key, plus a tag word most likely,
-- so 5/3 to 3/1 words per key, say 2.75 words/key (at a guess) times 30%
-- is a bit over 0.8 words per key. To represent a set of ints using these
-- we get 3N words for RBT and around 1.8N words for O234T - not bad.
-- 
-- Actual data from tree with 296 keys (from test3 320):
--         2   3   4   tot
-- Leaf    36  39  27  102
-- Nonl    33  25  6   64
-- Total   69  64  33  166
-- 
-- Overheads for 296 keys
-- RBT 296*2=592 (assumes 1 bit available to programmer)
-- 234T 69*2+64*3+33*4=462 (assuming 2 bits available)
-- O234T 33*3+25*4+6*5=229 (assuming 2 bits available)
-- O234T 33*2+25*3+6*4=165 (assuming 3 bits available)
-- Best write some code to count different constructors and
-- use bigger example - done - 1M pseudo random keys gives:
-- *Main> sp1
-- (0.0,126487.0,85414.0,14752.0,111021.0,144245.0,86306.0)
-- (0,22,15,3,20,25,15)
-- RBT:   2000000.0
-- 234T:  1568225.0
-- O234T: 568224.0
-- *Main> sp2 -- 0.5M
-- (0.0,63649.0,42669.0,7462.0,57107.0,71281.0,42986.0)
-- (0,22,15,3,20,25,15)
-- RBT:   1000000.0
-- 234T:  785154.0
-- O234T: 285153.0
-- *Main> sp3 -- inserted in sorted order -> nearly all 2nodes
-- (0.0,249980.0,8.0,1.0,249999.0,1.0,0.0)
-- (0,50,0,0,50,0,0)
-- RBT:   1000000.0
-- 234T:  999989.0
-- O234T: 499988.0
-- Seems like random insertion gives .57 prts/key, worst = 1

-- Hmm, could do similar optimisation with other tree structure, eg
-- normal BST.  More messy since we have None, Left, Right, Both.  For
-- perfectly balanced tree we get 3N words -> 2N words.

-- two-three-four tree with keys and values
-- Hmm, maybe its better not to separate keys and values, and just
-- assume there is a key function to apply (could have type class for
-- this)
data Two34 k v =
    -- optimised cases for leaves (optional)
    -- Saves significant space (ptrs in leaves).  Best put these
    -- constructors before the general ones so the tag is optimised away
    -- for the most common nodes in the tree: ThreeLeaf, TwoLeaf(?) and
    -- FourLeaf (best for Empty to not be NULL if we have 2 tag bits!)
    TwoLeaf k v |
    ThreeLeaf k v k v |
    FourLeaf k v k v k v |
    --
    Empty |
    Two (Two34 k v) k v (Two34 k v) |
    Three (Two34 k v) k v (Two34 k v) k v (Two34 k v) |
    Four (Two34 k v) k v (Two34 k v) k v (Two34 k v) k v (Two34 k v)
    deriving Show

two34_to_list :: Two34 k v -> [(k, v)]
two34_to_list Empty = []
two34_to_list (Two l k1 v1 r) =
    (two34_to_list l) ++ [(k1,v1)] ++ (two34_to_list r)
two34_to_list (Three l k1 v1 m k2 v2 r) =
    (two34_to_list l) ++ [(k1,v1)] ++ (two34_to_list m) ++
        [(k2,v2)] ++ (two34_to_list r)
two34_to_list (Four ll k1 v1 lr k2 v2 rl k3 v3 rr) =
    (two34_to_list ll) ++ [(k1,v1)] ++ (two34_to_list lr) ++
        [(k2,v2)] ++ (two34_to_list rl) ++ [(k3,v3)] ++ (two34_to_list rr)
--
two34_to_list (TwoLeaf k1 v1) = [(k1,v1)]
two34_to_list (ThreeLeaf k1 v1 k2 v2) = [(k1,v1),(k2,v2)]
two34_to_list (FourLeaf k1 v1 k2 v2 k3 v3) = [(k1,v1),(k2,v2),(k3,v3)]

search :: Ord k => Two34 k v -> k -> Maybe v
search Empty k = Nothing
search (Two l k1 v1 r) k =
    if k == k1 then Just v1
    else if k < k1 then search l k
    else search r k
search (Three l k1 v1 m k2 v2 r) k =
    if k == k1 then Just v1
    else if k < k1 then search l k
    else if k == k2 then Just v2
    else if k < k1 then search m k
    else search r k
search (Four ll k1 v1 lr k2 v2 rl k3 v3 rr) k =
    if k == k2 then Just v2
    else if k < k2 then
            if k == k1 then Just v1
            else if k < k1 then search ll k
            else search lr k
    else
            if k == k3 then Just v3
            else if k < k3 then search rl k
            else search rr k
-- optimised cases
-- We test keys in same order as for non-leaves for consistency.
-- There could be repeated keys with different values.  Its not clear
-- which should be returned but best be consistent.
search (TwoLeaf k1 v1) k =
    if k == k1 then Just v1
    else Nothing
search (ThreeLeaf k1 v1 k2 v2) k =
    if k == k1 then Just v1
    else if k == k2 then Just v2
    else Nothing
search (FourLeaf k1 v1 k2 v2 k3 v3) k =
    if k == k2 then Just v2
    else if k == k1 then Just v1
    else if k == k3 then Just v3
    else Nothing

-- We have a separate is_empty fn because testing t == Empty
-- requires the tree type to be in Eq, which can be problematic
is_Empty :: Two34 k v -> Bool
is_Empty Empty = True
is_Empty _ = False

-- for insertion we return a single tree or two trees plus
-- an extra key and value which are promoted higher in tree
data Ins_res k v =
    Same (Two34 k v) |
    Promote (Two34 k v) k v (Two34 k v)

-- To insert, the top level fn has a base case for Empty trees.
-- The general case (but without empty trees) returns a tree of the
-- same height as the original, or a "promoted" key+value_ left and
-- right subtrees (this only happens for four-nodes - we always split
-- them and promote the middle key+value)
insert :: Ord k => k -> v -> Two34 k v -> Two34 k v
-- insert k v Empty = Two Empty k v Empty  -- unoptimised
insert k v Empty = TwoLeaf k v -- optimised version
insert k v t =
    case insertx k v t of
        Same t1 -> t1
        Promote lx kx vx rx -> Two lx kx vx rx

insertx :: Ord k => k -> v -> Two34 k v -> Ins_res k v
insertx k v (Two l k1 v1 r) =
    -- could swap order of tests here and for Three nodes
    -- Don't need is_Empty test for optimised version
--     if is_Empty l then -- also r == Empty
--         if k <= k1 then Same (Three Empty k v l k1 v1 r)
--         else Same (Three l k1 v1 Empty k v r)
--     else
    if k <= k1 then
        case insertx k v l of
            Same t -> Same (Two t k1 v1 r)
            Promote lx kx vx rx -> Same (Three lx kx vx rx k1 v1 r)
    else
        case insertx k v r of
            Same t -> Same (Two l k1 v1 t)
            Promote lx kx vx rx -> Same (Three l k1 v1 lx kx vx rx)
insertx k v (Three l k1 v1 m k2 v2 r) =
    -- see comment for Two case
--     if is_Empty l then -- also m == Empty && r == Empty
--         if k <= k1 then Same (Four Empty k v l k1 v1 m k2 v2 r)
--         else if k <= k2 then Same (Four l k1 v1 Empty k v m k2 v2 r)
--         else Same (Four l k1 v1 m k2 v2 Empty k v r)
--     else
    if k < k1 then
        case insertx k v l of
            Same t -> Same (Three t k1 v1 m k2 v2 r)
            Promote lx kx vx rx -> Same (Four lx kx vx rx k1 v1 m k2 v2 r)
    else if k < k2 then
        case insertx k v m of
            Same t -> Same (Three l k1 v1 t k2 v2 r)
            Promote lx kx vx rx -> Same (Four l k1 v1 lx kx vx rx k2 v2 r)
    else
        case insertx k v r of
            Same t -> Same (Three l k1 v1 m k2 v2 t)
            Promote lx kx vx rx -> Same (Four l k1 v1 m k2 v2 lx kx vx rx)
insertx k v (Four ll k1 v1 lr k2 v2 rl k3 v3 rr) =
    -- For optimised version we know this isn't a leaf so
    -- we don't need to split into two TwoLeaf nodes.
    -- Could inline calls to insertx and avoid case expression
    -- with a bit of code expansion.
    let
    twol = Two ll k1 v1 lr
    twor = Two rl k3 v3 rr
    in
    if k <= k2 then
        case insertx k v twol of
            Same t -> Promote t k2 v2 twor
            Promote _ _ _ _ -> error "promotion from two-node"
    else
        case insertx k v twor of
            Same t -> Promote twol k2 v2 t
            Promote _ _ _ _ -> error "promotion from two-node"
insertx k v Empty =
    error "insertx called with empty tree"
--
insertx k v (TwoLeaf k1 v1) =
    if k <= k1 then Same (ThreeLeaf k v k1 v1)
    else Same (ThreeLeaf k1 v1 k v)
insertx k v (ThreeLeaf k1 v1 k2 v2) =
    if k <= k1 then Same (FourLeaf k v k1 v1 k2 v2)
    else if k <= k2 then Same (FourLeaf k1 v1 k v k2 v2)
    else Same (FourLeaf k1 v1 k2 v2 k v)
insertx k v (FourLeaf k1 v1 k2 v2 k3 v3) =
    if k <= k2 then
        if k <= k1 then
            Promote (ThreeLeaf k v k1 v1) k2 v2 (TwoLeaf k3 v3)
        else
            Promote (ThreeLeaf k1 v1 k v) k2 v2 (TwoLeaf k3 v3)
    else
        if k <= k3 then
            Promote (TwoLeaf k1 v1) k2 v2 (ThreeLeaf k v k3 v3)
        else
            Promote (TwoLeaf k1 v1) k2 v2 (ThreeLeaf k3 v3 k v)


list_to_two34 :: Ord k => [(k,v)] -> Two34 k v
list_to_two34 = foldl (flip (uncurry insert)) Empty
-- R to L version (more confusing for testing)
-- list_to_two34 = foldr (uncurry insert) Empty

-- foldr for Two34
foldr234
  :: t2
     -> (t2 -> t -> t1 -> t2 -> t2)
     -> (t2 -> t -> t1 -> t2 -> t -> t1 -> t2 -> t2)
     -> (t2 -> t -> t1 -> t2 -> t -> t1 -> t2 -> t -> t1 -> t2 -> t2)
     -> (t -> t1 -> t2)
     -> (t -> t1 -> t -> t1 -> t2)
     -> (t -> t1 -> t -> t1 -> t -> t1 -> t2)
     -> Two34 t t1
     -> t2
foldr234 f0 f2 f3 f4 f2l f3l f4l Empty =
    f0
foldr234 f0 f2 f3 f4 f2l f3l f4l (Two l k1 v1 r) =
    f2 (foldr234 f0 f2 f3 f4 f2l f3l f4l l) k1 v1
        (foldr234 f0 f2 f3 f4 f2l f3l f4l r)
foldr234 f0 f2 f3 f4 f2l f3l f4l (Three l k1 v1 m k2 v2 r) =
    f3 (foldr234 f0 f2 f3 f4 f2l f3l f4l l) k1 v1
        (foldr234 f0 f2 f3 f4 f2l f3l f4l m) k2 v2
        (foldr234 f0 f2 f3 f4 f2l f3l f4l r)
foldr234 f0 f2 f3 f4 f2l f3l f4l (Four ll k1 v1 lr k2 v2 rl k3 v3 rr) =
    f4 (foldr234 f0 f2 f3 f4 f2l f3l f4l ll) k1 v1
        (foldr234 f0 f2 f3 f4 f2l f3l f4l lr) k2 v2
        (foldr234 f0 f2 f3 f4 f2l f3l f4l rl) k3 v3
        (foldr234 f0 f2 f3 f4 f2l f3l f4l rr)
foldr234 f0 f2 f3 f4 f2l f3l f4l (TwoLeaf k1 v1) =
    f2l k1 v1
foldr234 f0 f2 f3 f4 f2l f3l f4l (ThreeLeaf k1 v1 k2 v2) =
    f3l k1 v1 k2 v2
foldr234 f0 f2 f3 f4 f2l f3l f4l (FourLeaf k1 v1 k2 v2 k3 v3) =
    f4l k1 v1 k2 v2 k3 v3

-- returns count of all the kinds of nodes
count_nodes =
    foldr234
        (1,0,0,0,0,0,0)
        (\(a0,a2,a3,a4,a2l,a3l,a4l) k1 v1
            (b0,b2,b3,b4,b2l,b3l,b4l) ->
            (a0+b0,1+a2+b2,a3+b3,a4+b4,a2l+b2l,a3l+b3l,a4l+b4l))
        (\(a0,a2,a3,a4,a2l,a3l,a4l) k1 v1
            (b0,b2,b3,b4,b2l,b3l,b4l) k2 v2
            (c0,c2,c3,c4,c2l,c3l,c4l) ->
            (a0+b0+c0,a2+b2+c2,1+a3+b3+c3,a4+b4+c4,
                a2l+b2l+c2l,a3l+b3l+c3l,a4l+b4l+c4l))
        (\(a0,a2,a3,a4,a2l,a3l,a4l) k1 v1
            (b0,b2,b3,b4,b2l,b3l,b4l) k2 v2
            (c0,c2,c3,c4,c2l,c3l,c4l) k3 v3
            (d0,d2,d3,d4,d2l,d3l,d4l) ->
            (a0+b0+c0+d0,a2+b2+c2+d2,a3+b3+c3+d3,1+a4+b4+c4+d4,
                a2l+b2l+c2l+d2l,a3l+b3l+c3l+d3l,a4l+b4l+c4l+d4l))
        (\k1 v1 -> (0,0,0,0,1,0,0))
        (\k1 v1 k2 v2 -> (0,0,0,0,0,1,0))
        (\k1 v1 k2 v2 k3 v3 -> (0,0,0,0,0,0,1))

show_space (a0,a2,a3,a4,a2l,a3l,a4l) =
    let tot = a0+a2+a3+a4+a2l+a3l+a4l in
    show (a0,a2,a3,a4,a2l,a3l,a4l) ++ "\n" ++
    show (round (100*a0/tot),round (100*a2/tot),round (100*a3/tot),round (100*a4/tot),round (100*a2l/tot),round (100*a3l/tot),round (100*a4l/tot)) ++ "\n" ++
    "RBT:   " ++ (show ((a2+a3*2+a4*3+a2l+a3l*2+a4l*3)*2)) ++ "\n" ++
    "234T:  " ++ (show (a2*2+a3*3+a4*4+a2l*2+a3l*3+a4l*4)) ++ "\n" ++
    "O234T: " ++ (show (a2*2+a3*3+a4*4)) ++ "\n"

sp1 = putStr $
    show_space $
    count_nodes $
    list_to_two34 $
    [(i*i `mod` 9999997,0) | i <- [150000..1150000-1]]

sp2 = putStr $
    show_space $
    count_nodes $
    list_to_two34 $
    [(i*i `mod` 999999997,0) | i <- [150000..650000-1]]

sp3 = putStr $
    show_space $
    count_nodes $
    list_to_two34 $
    [(i,0) | i <- [150000..650000-1]]

test1 i = (list_to_two34 [(i*i `mod` 97,i)| i <- [20..i]])
test3 i = (list_to_two34 [(i*i `mod` 591,i)| i <- [25..i]])
test2 i =
    map fst (two34_to_list (list_to_two34 [(i*i `mod` 97,i)| i <- [20..i]]))

-- :l "two34"
-- [test1 i| i<-[20..25]]
-- [test1 i| i<-[25..30]]
