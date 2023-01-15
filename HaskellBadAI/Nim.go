package main

import (
        "fmt"
)

func main(){
        //fmt.Println(solve([1,2,3]))
        var list []int = []int{1,2,4,5,4}
        fmt.Println(remove(4,list))
}
func solve( list []int ){
        
}
func remove ( target int, list []int ) []int{
        out := []int{}
        for _, i := range list {
                if i != target {
                        out = append(out, i)
                }
        }       
        return out
}
func dedupe ( list []int) []int {
       
}
