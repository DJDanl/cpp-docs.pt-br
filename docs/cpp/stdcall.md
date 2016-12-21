---
title: "__stdcall | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__stdcall_cpp"
  - "__stdcall"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __stdcall [C++]"
ms.assetid: e212594b-1827-4d07-9527-7d412b300df8
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __stdcall
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A convenção de chamada `__stdcall` é usada para chamar funções da API do Win32.  O receptor limpa a pilha para que o compilador execute as funções **vararg**`__cdecl`.  As funções que usam esta convenção de chamada exigem um protótipo de função.  
  
## Sintaxe  
  
```  
  
return-type __stdcall function-name[(argument-list)]  
```  
  
## Comentários  
 A lista a seguir mostra a implementação dessa convenção de chamada.  
  
|Elemento|Implementação|  
|--------------|-------------------|  
|Ordem de passagem de argumentos|Da direita para a esquerda.|  
|Convenção de passagem de argumentos|Por valor, a menos que um ponteiro ou um tipo de referência seja passado.|  
|Responsabilidade de manutenção de pilha|A função chamada remove seus próprios argumentos da pilha.|  
|Convenção de decoração de nome|Um sublinhado \(\_\) é prefixado com o nome.  O nome é seguido pela arroba \(@\) e pelo número de bytes \(em decimal\) na lista de argumentos.  Portanto, a função declarada como `int func( int a, double b )` está decorada da seguinte maneira: `_func@12`|  
|Convenção de conversão de maiúsculas e minúsculas|Nenhum|  
  
 A opção de compilador [\/Gz](../build/reference/gd-gr-gv-gz-calling-convention.md) especifica `__stdcall` para todas as funções não declaradas explicitamente com outra convenção de chamada.  
  
 As funções declaradas usando o modificador `__stdcall` retornam os valores da mesma maneira que as funções declaradas usando [\_\_cdecl](../Topic/__cdecl.md).  
  
 Nos processadores ARM e x64, `__stdcall` é aceito e ignorado pelo compilador; nas arquiteturas ARM e x64, por convenção, os argumentos são passados em registros quando possível, e os argumentos subsequentes são passados na pilha.  
  
 Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisa ser especificado na definição fora da linha.  Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição.  Dada esta definição de classe,  
  
```cpp  
struct CMyClass {  
   void __stdcall mymethod();  
};  
```  
  
 this  
  
```cpp  
void CMyClass::mymethod() { return; }  
```  
  
 equivale a isso  
  
```cpp  
void __stdcall CMyClass::mymethod() { return; }  
```  
  
## Exemplo  
 No exemplo a seguir, o uso de \_\_**stdcall** resulta em todos os tipos de função `WINAPI` que sendo tratados como uma chamada padrão:  
  
```c  
// Example of the __stdcall keyword  
#define WINAPI __stdcall  
// Example of the __stdcall keyword on function pointer  
typedef BOOL (__stdcall *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);  
```  
  
## Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../Topic/Argument%20Passing%20and%20Naming%20Conventions.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)