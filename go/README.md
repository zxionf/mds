# go

## 语法

### 变量

```go
// 基础
// var identifier [type] = value
var name string = "Hi"
name := "Hi"
// 一次声明多个
var a, b int = 1, 2
```

### 常量

```go
// 常量
// const identifier [type] = value
const name string = "zx"
// 枚举
const (
    a = "abc"
    b = len(a)
    c = unsafe.Sizeof(a)
)
// 常量计数器 iota 从0开始
const (
    a = iota
    b
    c
)
```

### 数组

```go
// var arrayName [size]dataType
var balance [10]float32
var numbers = [5]int{1, 2, 3, 4, 5}
balance := [...]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
balance := [5]float32{1:2.0,3:7.0}
```

### 条件语句

```go
// if else
if Expression { }
if Expression { } else { }
// switch
switch var1 {
    case val1:
        ...
    case val2:
        ...
    default:
        ...
}
// type switch
switch x.(type){
    case type:
       statement(s);      
    case type:
       statement(s); 
    /* 你可以定义任意个数的case */
    default: /* 可选 */
       statement(s);
}
```

使用 `fallthrough` 会强制执行后面的 `case` 语句

### 循环

```go
// for
for init; condition; post { }
for condition { }
for { }
// range for
for key, value := range oldMap {
    newMap[key] = value
}
for key, _ := range oldMap { }
// goto
label: statement
goto label
```

### 函数

```go
//func name( [parameter list] ) [return_types] {
//    body
//}
func swap(x, y string) (string, string) {
   return y, x
}
```

### 结构体

```go
// type struct_variable_type struct {
//    member definition
//    member definition
//    ...
//    member definition
// }
type Books struct {
   title string
   author string
   subject string
   book_id int
}
// example
type Book struct {
    name string
}
var book Book
var ptr *Book
ptr = &book
fmt.Print(ptr)
```

### 切片 Slice

动态数组

```go
// var identifier []type
var a []int
slice1 := make([]T, length, capacity)
// 初始化
s :=[] int {1,2,3 }
```
