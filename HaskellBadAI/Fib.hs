import Data.Map (Map)
import qualified Data.Map as Map

slow_fib :: Int -> Int 
slow_fib 0 = 0
slow_fib 1 = 1 
slow_fib n = (slow_fib (n-1)) + (slow_fib (n-2))

fast_fib :: Int -> Int 
fast_fib = (Map.fromList [(x, fib x) | x <- [0..]] Map.!)
        where   fib 0 = 0
                fib 1 = 1 
                fib n = (fast_fib (n-1)) + (fast_fib (n-2))
                
--pair_fib :: (Int, Int) -> (Int, Int)
--pair_fib (a,b) = (map fib [(x,y) | x <- [0..], y <- [0..]] !! )
--        where fib (x,y) = if x <= 1 && y <= 1
--                                then (x,y)
--                          else if x <= 1 
--                                then addPair (pair_fib (x, y-1)) (pair_fib (0, y-2))
--                          else if y <= 1 
--                                then addPair (pair_fib (x-1, y)) (pair_fib (x-2, 0))
--                          else 
--                                addPair (pair_fib (x-1, y-1)) (pair_fib (x-2, y-2))
--
--
--addPair :: (Int, Int) -> (Int, Int) -> (Int, Int)
--addPair (x,y) (a,b) = (x + a, y + b)
