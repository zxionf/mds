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
fmt.Print(&ptr)
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

```go
// 初始化切片s为数组arr的引用
s := arr[:]
// 将 arr 中从下标 startIndex 到 endIndex-1 下的元素创建为一个新的切片
s := arr[startIndex:]
```

### range

```go
// map
map_variable := make(map[KeyType]ValueType, initialCapacity)
map1 := map[string]int{ "apple":1 }
delete(map1, "apple")
// 通道
ch := make(chan int, 2)
ch <- 1
ch <- 2
close(ch)
for v := range ch {
    fmt.Println(v)
}
```

### 类型转换

```go
float32(n)
```

### 接口

```go
type interface_name interface {
   method_name1 [return_type]
   ...
}
func (struct_name_variable struct_name) method_name1() [return_type] {
   /* 方法实现 */
}

// 类型断言
value := i.(Type)
// 带检查的类型断言
value, ok := iface.(Type)
```

接口包含了连个部分：动态类型，动态值

```go
var i interface{} = 17
fmt.Printf("Dynamic type: %T, Dynamic value: %v\n", i, i)
```

### 泛型

```go
// 基本语法结构
func 函数名[T 约束](参数 T) 返回值类型 {
    // 函数体
}
type 类型名[T 约束] struct {
    // 结构体字段
}
```

T: 表示 Type(类型)  
K: 表示 Key(键)  
V: 表示 Value(值)  
E: 表示 Element(元素)  

#### 内置约束

- `any` 约束  
`any` 是空接口 `interface{}` 的别名  

- `comparable` 约束  
`comparable` 表示类型支持 `==` 和 `!=` 操作符  

- 联合约束(Union Constraints)  
使用 `|` 运算符组合多个类型  

    ```go
    type Number interface {
        int | int8 | int16 | int32 | int64 |
        uint | uint8 | uint16 | uint32 | uint64 |
        float32 | float64
    }
    ```

### 并发

```go
go fun()
```

```go
ch := make(chan int)
ch := make(chan int, 100)
```
