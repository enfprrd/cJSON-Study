#include <stdio.h>
#include "cJSON.h"
#include <string.h>
static const char *type_name(const cJSON *item);
static void test(const char* json){
	cJSON *root = cJSON_ParseWithOpts(json, 0, 0);
	if (!root) {
        	printf("  result: FAIL\n");
        	return;
	}
	printf("  json: %s\n", json);
	printf("  root type: %s\n", type_name(root));
	cJSON_Delete(root);
}
static const char *type_name(const cJSON *item) {
    if (item == NULL) return "NULL";
    if (cJSON_IsObject(item)) return "Object";
    if (cJSON_IsArray(item))  return "Array";
    if (cJSON_IsString(item)) return "String";
    if (cJSON_IsNumber(item)) return "Number";
    if (cJSON_IsBool(item))   return "Bool";
    if (cJSON_IsNull(item))   return "Null";
    return "Other";
}

int main(void){
	char* objectJson = "{\"a\":[1,2],\"b\":{\"c\":3}}";
	char* arrayJson = "[1,\"x\",null,true,false]";
	char* stringJson = "\"hi\"";
	char* numberJson = "3.14";
	test(objectJson);
	test(arrayJson);
	test(stringJson);
	test(numberJson);
	return 0;

}
