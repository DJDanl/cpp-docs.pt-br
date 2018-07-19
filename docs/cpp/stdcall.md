---
title: stdcall | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __stdcall_cpp
dev_langs:
- C++
helpviewer_keywords:
- __stdcall keyword [C++]
ms.assetid: e212594b-1827-4d07-9527-7d412b300df8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 09efc905507d93bbb80b003f93b885d9d27fcb1d
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939839"
---
# <a name="stdcall"></a>__stdcall
**Seção específica da Microsoft**  
  
 O **stdcall** convenção de chamada é usada para chamar funções de API do Win32. O receptor limpa a pilha, então o compilador faz **vararg** funções **cdecl**. As funções que usam esta convenção de chamada exigem um protótipo de função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
return-type __stdcall function-name[(argument-list)]  
```  
  
## <a name="remarks"></a>Comentários  
 A lista a seguir mostra a implementação dessa convenção de chamada.  
  
|Elemento|Implementação|  
|-------------|--------------------|  
|Ordem de passagem de argumentos|Da direita para a esquerda.|  
|Convenção de passagem de argumentos|Por valor, a menos que um ponteiro ou um tipo de referência seja passado.|  
|Responsabilidade de manutenção de pilha|A função chamada remove seus próprios argumentos da pilha.|  
|Convenção de decoração de nome|Um sublinhado (_) é prefixado com o nome. O nome é seguido pela arroba (@) e pelo número de bytes (em decimal) na lista de argumentos. Portanto, a função declarada como `int func( int a, double b )` está decorada da seguinte maneira: `_func@12`|  
|Convenção de conversão de maiúsculas/minúsculas|Nenhum|  
  
 O [/Gz](../build/reference/gd-gr-gv-gz-calling-convention.md) opção de compilador especifica **stdcall** para todas as funções não declaradas explicitamente com outra convenção de chamada.  
  
 As funções declaradas usando o **stdcall** da mesma maneira que as funções declaradas usando valores de retorno de modificador [cdecl](../cpp/cdecl.md).  
  
 No ARM e x64 processadores **stdcall** é aceito e ignorado pelo compilador; no ARM e x64 arquiteturas, por convenção, os argumentos são passados em registros quando possível, e os argumentos subsequentes são passados na pilha.  
  
 Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição. Dada esta definição de classe,  
  
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
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, uso de _**stdcall** resulta em todos os `WINAPI` tipos de função que está sendo tratada como uma chamada padrão:  
  
```cpp  
// Example of the __stdcall keyword  
#define WINAPI __stdcall  
// Example of the __stdcall keyword on function pointer  
typedef BOOL (__stdcall *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)