main = do
        print "Hello World"
        print "Are you still here?"
--        print White
--        print $ capture White
--        print board19


data Stone = White | Black | Empty
        deriving (Eq, Read)

instance Show Stone where
        show White = "W"
        show Black = "B"
        show Empty = "."


instance Show Row where 
         show (Row (x:xs)) = (show x) ++ " "
         show (Row [])     = "\n"

capture :: Stone -> Stone
capture _ = Empty

newtype Row = Row [Stone]
newtype Board = Board [Row]


buildRow :: Int -> Row 
buildRow n | n <= 0 = Row [] 
           | otherwise = Row ( Empty : (getRow (buildRow (n-1)))) 

getRow :: Row -> [Stone]
getRow (Row s) = s 
--
--BuildBoard :: Board 
--BuildBoard x y | x > 0  = ( buildRow y ) : ( buildBoard (x - 1) y )
--               | x <= 0 = [] 
--
--board9  = buildBoard 9  9 
--board13 = buildBoard 13 13 
--board19 = buildBoard 19 19 
