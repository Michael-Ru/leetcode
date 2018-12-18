#include<stdio.h>
#include<malloc.h>

//ʹ�������˳��ж����,����ʧ�ܡ���Ϊһ�������޷���ʾ�����ŵ�λ�ã����޷����"[(])"��һ������
bool isValid1(char* s) {
	double map[256] = { 0 }, r = 1;
	map['('] = 3;
	map[')'] = 1.0 / 3;
	map['['] = 5;
	map[']'] = 1.0 / 5;
	map['{'] = 7;
	map['}'] = 1.0 / 7;

	do{
		r *= map[*s];
		if (r != (int)r) 
			return false;
	} while (*s++);
	return true;
}

// ʹ��һ���ַ���ģ��ջ�ṹ������ȳ�
// ����ͨ�����в�������������ע����������·����ڴ棬��������ַ����д���4096��δ��Ե������ţ�������ʵ�δ������ڴ档
bool isValid(char* s) {
	int N = 64;
	char* z = NULL;
	z =(char*)malloc(N*sizeof(char));
	// ջ�ĳ��ȣ�z[p]���ɷ���ջ����
	int p=-1;
	while (*s){
		if (*s == '(' || *s == '[' || *s == '{'){
			p++;
			// ���Խ���˾����·����ڴ�
			if (p > N - 1){
				N *= 2;
				z = (char*)realloc(z, N *sizeof(char));
			}
			z[p]=*s;
		}
		else{
			if (p < 0) 
				return false;
			if ((int)z[p] == *s - 1 || (int)z[p] == *s - 2){
				p--; 
			}
			else{
				return false;
			}
		}
		s++;
	}
	return p == -1;
}




int main(){
	bool r;
	r = isValid("[]()");
	return r;
}