# Day2 cJSON数据结构理解与验证

时间:2026-02-08
分支:practice-rrd
版本:v1.7.19

## 今日收获
1) 阅读cjson.h中的struct cjson 定义
2) 阅读cjson.c中节点相关函数
3) 编写demo_traverse.c,打印节点信息
4) 提交日志

## 关键理解
1)每一个json的值对应一个cjson的节点,这个节点可以是新的键值对(object),可以是json数组(array),可以是字符串(string),也可以是数字(number),可以是布尔值(bool),也可以是空(null)
2)同一层子元素通过next和prev形成双向链表
3)object通过key(string)来定位,他的child指向第一个元素
4)array通过下标来定位,他的child指向第一个成员
### 举例
一个json:{a: [1,"a",3]},item->child->child->next对应的就是a.(item是root object)
5)cjson字段:
- `child`：指向第一个子节点（array/object的入口）
- `next/prev`：同层兄弟节点链表指针
- `type`：节点类型
- `string`：对象成员 key
- `valuestring`：字符串值
- `valuedouble`：数字值（主要）
- `valueint`：整数槽位
## Git记录
- 关键文件:
  - `notes/day2_struct.md`
  - `examples/demo_traverse.c`
  - `docs/struct_cjson.md`

