# <a name="compiler-warning-level-1-c4055"></a>Compilador C4055 de aviso (nível 1)  
  
'conversão de ': de ponteiro de dados 'type1' para o ponteiro de função 'type2'  
  
**Obsoleto:** esse aviso não é gerado pelo Visual Studio de 2017 e versões posteriores.

 Um ponteiro de dados é convertido (possivelmente incorretamente) para um ponteiro de função. Este é um aviso de nível 1 em /Za e um aviso de nível 4 em /Ze.  
  
 O exemplo a seguir gera C4055:  
  
```C  
// C4055.c  
// compile with: /Za /W1 /c  
typedef int (*PFUNC)();  
int *pi;  
PFUNC f() {  
   return (PFUNC)pi;   // C4055  
}  
```  
  
 Em /Ze, este é um aviso de nível 4.  
  
```C  
// C4055b.c  
// compile with: /W4 /c  
typedef int (*PFUNC)();  
int *pi;  
PFUNC f() {  
return (PFUNC)pi;   // C4055  
}  
```