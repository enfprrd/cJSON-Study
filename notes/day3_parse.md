# Day3 - cJSON 解析主链路梳理

时间:2026-02-09
版本:v1.7.19

## 今日收获
- [ ] 读懂 `cJSON_Parse` / `cJSON_ParseWithOpts` 的差异与作用
- [ ] 读懂 `parse_value` 的分派逻辑（按首字符决定类型）
- [ ] 读懂 `parse_object` / `parse_array` 的循环解析与链表挂接（child/next/prev）
- [ ] 编写 demo 验证：成功解析 + 故意失败解析 + 错误指针定位

## 深度理解
1) `cJSON_ParseWithOpts` 初始化解析 buffer，跳过空白后调用 `parse_value`。
2) `parse_value` 根据当前字符分派到 object/array/string/number/true/false/null。
3) `parse_object`：循环解析 `"key" : value`(键值对)，把每个成员尾插到 `object->child` 链表。
4) `parse_array`：循环解析 `value`，把每个元素尾插到 `array->child` 链表。
5) 解析失败时记录错误位置，`cJSON_GetErrorPtr()` 可返回出错附近指针。

### ParseWithOpts 解释
1) 当参数 `require_null_terminated==1` 时，解析结束后若还有非空白字符则判失败。
2) `value`:输入json字符串
3) `return_parse_end`：输出参数，返回解析停止位置；不需要可传 `NULL`

### parse_value 分派规则
 - `{` -> parse_object
 - `[` -> parse_array
 - `"` -> parse_string
 - `数字或负号` -> parse_number
 - `t` -> true
 - `f` -> false
 - `n` -> null
## Git日志
1) notes/day3_parse.md 
2) examples/demo_parse_cases.c
