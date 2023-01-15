syn keyword types       chan map bool string error int int8 int16 int32 int64 rune byte uint uint8 uint16 uint32 uint64 uintptr float32 float64 complex64 complex128
syn keyword builtIns    append cap close complex copy  delete imag len make new panic print println real recover 
syn match   ops         "[=:;\+=\*\|&!{},.]"

syn keyword consts       true false nil iota 
syn region  consts       start=+"+ skip=+\\\\\|\\"+ end=+"+
syn region  consts       start=+'+ end=+'+
syn match   consts       "\<-\=\(0\|[1-9]_\?\(\d\|\d\+_\?\d\+\)*\)\%([Ee][-+]\=\d\+\)\=\>"

syn region  comment     start="//" end="$"
syn region  comment     start="/\*" end="\*/"

syn keyword keywords    package import var const func
syn keyword keywords    defer go goto return break continue fallthrough  
syn keyword keywords    if else switch select case default for range 
syn keyword keywords    type struct interface 

syn match   function    "\w*("
syn match   function    ")"
