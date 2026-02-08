#include <stdio.h>
#include "cJSON.h"

int main(void){
	const char *jsonText = "{\"a\":[1,\"a\",3]}";
	cJSON *root = cJSON_Parse(jsonText);
	if (!root){
		printf("Parse Failed.\n");
		return 1;
	}
	cJSON *arr = cJSON_GetObjectItem(root, "a");
	if (!cJSON_IsArray(arr)) {
        	printf("Key 'a' is not an array.\n");
        	cJSON_Delete(root);
        	return 1;
    	}

    	cJSON *second = cJSON_GetArrayItem(arr, 1);
   	if (cJSON_IsString(second)) {
        	printf("Second element is string: %s\n", second->valuestring);
    	} else {
        	printf("Second element is not a string.\n");
    	}

    	cJSON_Delete(root);
    	return 0;
}
