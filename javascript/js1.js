function getdate(){
    return console.log(Date());
}
function displayDate(){
	document.getElementById("displaydate").innerHTML=Date();
}

//一种数组
var arrdemo = [9,0,"lk"];

//声明对象
var objdemo = {
    name:"zx",
    color:"White",
    //对象方法
    rename: function(newname){
        this.name = newname;
    },
    getname:function(){
        return this.name;
    }
};

//对变量的属性访问
objdemo.name;
objdemo["name"];

//调用对象的方法
console.log(objdemo.getname());

//浏览器弹窗提示
// alert("浏览器弹窗提示");

//全局变量
quanjubianliang ="全局变量";//可删除
delete quanjubianliang;

//var 修饰的变量
var varbianliang = "var变量";//无法删除

/*HTML 事件可以是浏览器行为，也可以是用户行为。
以下是 HTML 事件的实例：

HTML 页面完成加载
HTML input 字段改变时
HTML 按钮被点击*/

/*
事件	描述
onchange	HTML 元素改变
onclick	用户点击 HTML 元素
onmouseover	鼠标指针移动到指定的元素上时发生
onmouseout	用户从一个 HTML 元素上移开鼠标时发生
onkeydown	用户按下键盘按键
onload	浏览器已完成页面的加载*/

//更多事件
//https://www.runoob.com/jsref/dom-obj-event.html

//字符串属性
/*属性	描述
constructor	返回创建字符串属性的函数
length	返回字符串的长度
prototype	允许您向对象添加属性和方法*/

//字符串方法
/*方法	描述
charAt()	返回指定索引位置的字符
charCodeAt()	返回指定索引位置字符的 Unicode 值
concat()	连接两个或多个字符串，返回连接后的字符串
fromCharCode()	将 Unicode 转换为字符串
indexOf()	返回字符串中检索指定字符第一次出现的位置
lastIndexOf()	返回字符串中检索指定字符最后一次出现的位置
localeCompare()	用本地特定的顺序来比较两个字符串
match()	找到一个或多个正则表达式的匹配
replace()	替换与正则表达式匹配的子串
search()	检索与正则表达式相匹配的值
slice()	提取字符串的片断，并在新的字符串中返回被提取的部分
split()	把字符串分割为子字符串数组
substr()	从起始索引号提取字符串中指定数目的字符
substring()	提取字符串中两个指定的索引号之间的字符
toLocaleLowerCase()	根据主机的语言环境把字符串转换为小写，只有几种语言（如土耳其语）具有地方特有的大小写映射
toLocaleUpperCase()	根据主机的语言环境把字符串转换为大写，只有几种语言（如土耳其语）具有地方特有的大小写映射
toLowerCase()	把字符串转换为小写
toString()	返回字符串对象值
toUpperCase()	把字符串转换为大写
trim()	移除字符串首尾空白
valueOf()	返回某个字符串对象的原始值*/
//更多介绍
//https://www.runoob.com/jsref/jsref-obj-string.html

//模板字符串
/*
`string text`
`string text line 1string text line 2`
`string text ${expression} string text`
tagFunction`string text ${expression} string text`

`\`` === "`"; // true

const name = 'Runoob';
const age = 30;
const message = `My name is ${name} and I'm ${age} years old.`;
let header = "";
let tags = ["RUNOOB", "GOOGLE", "TAOBAO"];
*/

//模板字符串当作 HTML 模板使用
/*
let html = `<h2>${header}</h2><ul>`;
for (const x of tags) {
  html += `<li>${x}</li>`;
}
html += `</ul>`;
*/

//Date
/*方法	描述
getDate()	从 Date 对象返回一个月中的某一天 (1 ~ 31)。
getDay()	从 Date 对象返回一周中的某一天 (0 ~ 6)。
getFullYear()	从 Date 对象以四位数字返回年份。
getHours()	返回 Date 对象的小时 (0 ~ 23)。
getMilliseconds()	返回 Date 对象的毫秒(0 ~ 999)。
getMinutes()	返回 Date 对象的分钟 (0 ~ 59)。
getMonth()	从 Date 对象返回月份 (0 ~ 11)。
getSeconds()	返回 Date 对象的秒数 (0 ~ 59)。
getTime()	返回 1970 年 1 月 1 日至今的毫秒数*/

//自动转换类型
//当 JavaScript 尝试操作一个 "错误" 的数据类型时，会自动转换为 "正确" 的数据类型。

//以下输出结果不是你所期望的：
/*
5 + null    // 返回 5         null 转换为 0
"5" + null  // 返回"5null"   null 转换为 "null"
"5" + 1     // 返回 "51"      1 转换为 "1"
"5" - 1     // 返回 4         "5" 转换为 5
*/
//自动转换为字符串
//当你尝试输出一个对象或一个变量时 JavaScript 会自动调用变量的 toString() 方法：

//document.getElementById("demo").innerHTML = myVar;
/*
myVar = {name:"Fjohn"}  // toString 转换为 "[object Object]"
myVar = [1,2,3,4]       // toString 转换为 "1,2,3,4"
myVar = new Date()      // toString 转换为 "Fri Jul 18 2014 09:08:55 GMT+0200"
*/

//数字和布尔值也经常相互转换：
/*
myVar = 123             // toString 转换为 "123"
myVar = true            // toString 转换为 "true"
myVar = false           // toString 转换为 "false"
*/

//正则表达式
//语法
/*
/正则表达式主体/修饰符(可选)
*/


try{
    //异常的抛出
}catch(e){
    //异常的捕获与处理
}finally{
    //结束处理
}

//debugger关键字和断点效果是一样的
// debugger;

//异步编程
setTimeout(function(){
    // alert("异步");
    console.log("异步");
},2000);

//类
class ClassDemo{
    constructor(){
        //构造函数
    }
    sun(){
        //函数
    }
}
//类的继承
class Zileidemo extends ClassDemo{

}

//do
/*
document.write("djfshfjashdf\nsjdhfjkasdfjkashdfj\nsjdfjksfj\nskdhf\n\n\nn\n\n\nn\\n\nn\fgd\n\n\n\n\n\n\n\nsadfsafasdyf");
document.write("\f");
*/

//改变样式
//document.getElementById(id).style.property = 新样式

function sum(a,b){
    return a+b;
};

console.log(sum.toString());

//我调用我自己
/*(function (){
    var x = "Hello";
})();*/

//箭头函数
//(参数1,参数2,...) => {函数声明}
//(参数1,参数2,...) => 表达式
//(单一参数) => {}

//
function mover(obj){
    obj.innerHTML=Math.random();
}
function mout(obj){
    obj.innerHTML="Mouse Over Me";
}

//创建节点
function chuangjianjiedian(){
    var para = document.createElement("p");
    var node = document.createTextNode("这是一个新的段落");
    para.appendChild(node);
    document.getElementById("createNode").appendChild(para);
}
function chuangjianjiedian_obj(obj){
    var para = document.createElement("p");
    var node = document.createTextNode("这是一个新的段落");
    para.appendChild(node);
    obj.appendChild(para);
}

//windoow

// window.close();

//screen
console.log(screen.availWidth);

//location
console.log(location.href);
console.log(location.pathname);
// location.assign("h1.html");//载入新的页面
// window.history.back();//历史url

txtdemo = "<p>浏览器代号"+navigator.appCodeName+"</p>";
//弹窗
/*
var r=confirm("确认弹窗");
if(r==true){
    console.log("你点了确认");
}else{
    console.log("你点了取消");
}*/

//带输入框的弹窗
/*
var person = prompt("请输入你的名字","zxionf");
if(person!=null&&person!="")
    console.log("你好"+person+"！今天感觉如何？");
*/


//计时事件
//不停的执行指定的代码
var mm = setInterval(function(){console.log("每三秒一次hello")},3000);
clearInterval(mm);

//cookie

//$
// $("pos").insert("dfhdshfsdjfhdfg");

//canvas

// cns = document.getElementById("mycanvas").getContext("2d");
// // var ctx = cns.getContext("2d");
// cns.fillStyle = "#ffffff";
// cns.fillRect(0,0,150,75);

// ewquired

// document.addEventListener("DOMContentLoaded",function(){
//     var cnavas = document.getElementById("mycanvas").getContext("2d");
//     cnavas.fillRect(0,0,175,75);
// });

// window.onload = function(){
//     var cnavas = document.getElementById("mycanvas").getContext("2d");
//     cnavas.fillRect(0,0,175,75);
// }