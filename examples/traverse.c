#include "cJSON.h"
#include <stdio.h>

static void indent(int n) {
    for (int i = 0; i < n; i++) putchar(' ');
}

static void printValue(cJSON *node, int level);

static void printObject(cJSON *node, int level) {
    printf("{\n");
    for (cJSON *child = node->child; child; child = child->next) {
        indent(level + 2);
        printf("\"%s\": ", child->string);
        printValue(child, level + 2);
        if (child->next) printf(",");
        printf("\n");
    }
    indent(level);
    printf("}");
}

static void printArray(cJSON *node, int level) {
    printf("[\n");
    for (cJSON *child = node->child; child; child = child->next) {
        indent(level + 2);
        printValue(child, level + 2);
        if (child->next) printf(",");
        printf("\n");
    }
    indent(level);
    printf("]");
}

static void printValue(cJSON *node, int level) {
    if (cJSON_IsObject(node)) { printObject(node, level); return; }
    if (cJSON_IsArray(node))  { printArray(node, level);  return; }

    if (cJSON_IsNumber(node)) { printf("%g", node->valuedouble); return; }
    if (cJSON_IsString(node)) { printf("\"%s\"", node->valuestring); return; }
    if (cJSON_IsTrue(node))   { printf("true"); return; }
    if (cJSON_IsFalse(node))  { printf("false"); return; }
    if (cJSON_IsNull(node))   { printf("null"); return; }

    printf("null");
}

int main(void){
    const char* test = "{\"a\":[1,\"b\"],\"v\":true}";
    cJSON* root = cJSON_Parse(test);
    printValue(root, 0);
    printf("\n");
    cJSON_Delete(root);
    return 0;
}
