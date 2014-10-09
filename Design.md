Design of Koala
===

## 0. 概况

  设计主体参考Lua,增加类型系统和其他一些特性,减少一些特性
  初步制定采用C++语言实现, 初期采用虚拟机实现,后期可能采用编译到机器码.
  除了具有Lua的基本特性外,主要还增加了类型系统等特性.

## 1. 基本数据类型和字面量
  * 基本类型也是对象,一切皆对象
  * 数字,Int类型,4字节有符号整数, Long类型,8字节有符号整数, 和Number类型,包括整数和浮点数,无限长度和精度, 字面量0开头的是8进制数,0x或0X开头的是16进制数, 数字后面直接带有L或者l的(无间隔)是Long类型整数.
  * nil, 有一个特殊的类Nil是所有类型的子类,有一个特殊的类Object是所有类型的父类,Nil类只有一个实例nil. nil的字面量是nil
  * 字符串, 字面量支持双引号,三引号,还有常见转义,unicode字符暂时不支持,后期再支持. 
  * 字符. 字面量类似C/JAVA语言
  * 布尔类型,字面量有true和false,都是Boolean类型的实例
  * table对象,具有强类型,比如 Table<键类型,值类型>. 列表是键类型为Int类型且带有插入函数的Table,即Table类有列表的插入函数,插入时自动索引+1,索引从0开始(和Lua这里不一样)
  * local a =1; local a, b = 1, 2; local a: String; local a: String = "abc"; val a = 100 (常数), 目前只需要支持这几种变量声明方式,不提供全局变量(和Lua不一样)
  * 支持a, b = b, a这种多赋值方式
  * 操作符支持和Python类似
  * 不支持自动类型转换,推荐强制类型转换
  * 支持
  * 变量,类名支持下划线或字母开头,后部跟着不超过1023个字符的下划线或字母或数字或横杠
  * 支持包,和模块机制,包机制类似Java,模块只可以import一次. 支持namespace, namespace的语法是在模块中写下namespace xxx后的所有, 所有模块都需要指定namespace,并且namespace需要和路径对应(有一个运行主目录,默认是启动运行所在当前目录)
  * 支持重复import或循环import namespace
  * 运行程序时从指定运行模块的main(Int, Table<Int, String>)方法开始运行
  * 只有false和nil的布尔假值,其他都是真值(在if, while时使用)
  * 没有public/private/protected之分
  * 支持Lua的metatable(自定义类型系统通过这种方式间接实现)
  * 暂时不支持类型定义(后期可能支持),通过Table和metatable来实现面向对象开发, 但是,支持类型typedef Person Table[String, Object]这种方式
  * 有简单自省机制,目前支持 `对象 instanceof 类型`这种方式
  
  

## 2. 控制流程
  * if a then b end, if a then b else c end. 没有的分支返回nil
  * 函数支持多返回值,比如local a, b = f()
  * while bool do .... end
  * for init, cond, post-for-loop do ... end
  * 布尔类型也没有自动转换,所以if, while需要传入正确的布尔类型值
  * case语句
  
```
case a 
  when b then c end 
  when d then e end 
  [default f then g end] 
end
```
  

## 3. 类型系统

  * 一切皆对象
  * 类型推倒,比如函数的参数类型推倒,推倒的不是具体某种类型,而且具有某些操作(方法,属性等)的泛型
  * 强类型系统,不支持自动类型转换
  * 函数也是对象,有一个复杂的Function<...很多泛型>的类型
  * 支持真泛型,运行时可以自省类型和泛型

## 4. 函数
  * function 可选的函数名 (参数列表, 变量名:类型,或者直接变量名,这种组合的列表,如果直接变量名,则) 函数体 end 函数的最后一个表达式的返回值就是函数的返回值. 函数体可以用若干个可选的花括号包围
  * 还支持这种
  
```
function ...
{
(参数签名1)
函数实现
}
{
(参数签名2)
函数实现
}
end
```

  * 支持闭包,高阶函数
  * 支持词法作用域
  * 支持函数多态,使用这种方法来支持多态. 在编译时,通过import namespace的关系来判断某个类型具有哪些方法,同一个类型不能重复定义同名方法
  
```
defmulti toString
  Int () ... end
end

extend-multi Person
  toString () ... end
end
```

## 5. 解释,虚拟机,和编译
  * 目前为了简单起见,先用虚拟机实现

## 6. code demo
  * TODO