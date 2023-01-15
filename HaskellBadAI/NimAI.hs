import Data.List
----------------------------------------

data Player = First | Second deriving (Show, Eq)

--type Black = First
--type White = Second

type Nim = [Int] 

----------------------------------------

dedupe :: Eq a => [a] -> [a]
dedupe [] = [] 
dedupe (x:xs) = x : (dedupe (remove x xs))

remove :: Eq a => a -> [a] -> [a]
remove _ [] = []
remove y (x:xs) = if y == x 
                        then remove y xs 
                        else x : (remove y xs)

contains :: Eq a => a -> [a] -> Bool
contains _ [] = False
contains y (x:xs) = if y == x
                        then True
                        else contains y xs 
----------------------------------------

pass :: Player -> Player
pass First = Second
pass Second = First

----------------------------------------

isWon :: Nim -> Bool
isWon [] = True
isWon _ = False

reduce :: Nim -> Nim  
reduce l = dedupe (l) 

getMoves :: Nim -> [Nim]
getMoves [] = [[]]
getMoves [x] = [[x'] | x' <- [0..(x-1)]]
getMoves (x:xs) = [x' : xs | x' <- [0..(x-1)]] ++ (map (x:) (getMoves xs))

reduceMoves :: Nim -> [Nim]
reduceMoves n = dedupe (map (sort.(remove 0)) (getMoves n))

solve :: Player -> Nim -> Player
solve p [] = pass p 
--solve p n  = if contains p (map (solve (pass p)) (reduceMoves n))
--                then p 
--                else pass p 
solve p n = solveRec p (reduceMoves n) 

solveRec :: Player -> [Nim] -> Player
solveRec p [] = pass p 
solveRec p (n:ns) = if p == (solve (pass p) n) 
                        then p 
                        else solveRec p ns

solve' = solve First
----------------------------------------

test1 :: IO() 
test1 = do
        print "Test 1"
        print ([[0,3],[1,3],[2,0],[2,1],[2,2],[2,3]] == (getMoves [2,3]))
        print ([[3],[1,3],[2],[1,2],[2,2],[2,3]] == reduceMoves [2,3] )
        print (getMoves [1])

test2 = do 
        print "Test 2"
        print (solve' [1])
        print (solve' [1,1])
        print (solve' [1,1,1])
        print (solve' [1,1,1,1])

main = do
        print "Running Test"
        --test1
        --test2
