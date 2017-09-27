---
title: cdecl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __cdecl
- __cdecl_cpp
dev_langs:
- C++
helpviewer_keywords:
- __cdecl keyword [C++]
ms.assetid: 1ff1d03e-fb4e-4562-8be1-74f1ad6427f1
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 5216462ad00d332aec2d00eba78f5d84cdfd7c82
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="cdecl"></a>__cdecl
**Seção específica da Microsoft**  
  
 `__cdecl` é uma convenção de chamada padrão para programas em C e C++. Porque a pilha é limpos pelo chamador, ele pode fazer **vararg** funções. O `__cdecl` convenção de chamada cria executáveis maior que [stdcall](../cpp/stdcall.md), porque requer que cada chamada de função para incluir o código de limpeza de pilha. A lista a seguir mostra a implementação dessa convenção de chamada.  
  
|Elemento|Implementação|  
|-------------|--------------------|  
|Ordem de passagem de argumentos|Da direita para a esquerda.|  
|Responsabilidade de manutenção de pilha|A função de chamada remove os argumentos da pilha.|  
|Convenção de decoração de nome|O caractere de sublinhado (_) é antecedido pelos nomes, exceto quando \_cdecl funções que usam o vínculo a C são exportadas.|  
|Convenção de conversão de maiúsculas/minúsculas|Nenhuma conversão de maiúsculas/minúsculas é realizada.|  
  
> [!NOTE]
>  Para obter informações relacionadas, consulte [nomes decorados](../build/reference/decorated-names.md).  
  
 Coloque o modificador `__cdecl` antes do nome de uma variável ou função. Como o C, nomeação e convenções de chamada são o padrão, o único momento em que você deve usar `__cdecl` x86 código é quando você tiver especificado o **/Gv** (vectorcall) **/Gz** (stdcall), ou ** /GR** opção de compilador (fastcall). O [/Gd](../build/reference/gd-gr-gv-gz-calling-convention.md) força de opção de compilador o `__cdecl` convenção de chamada.  
  
 Em processadores ARM e x64, `__cdecl` é aceito, mas normalmente é ignorado pelo compilador. Por convenção no ARM e x64, os argumentos são passados nos registros quando possível, e os argumentos subsequentes são passados na pilha. Em x64 de código, use `__cdecl` para substituir o **/Gv** opção de compilador e use a convenção de chamada x64 padrão.  
  
 Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição. Dada esta definição de classe:  
  
```cpp  
struct CMyClass {  
   void __cdecl mymethod();  
};  
```  
  
 isto:  
  
```cpp  
void CMyClass::mymethod() { return; }  
```  
  
 equivale a isto:  
  
```cpp  
void __cdecl CMyClass::mymethod() { return; }  
```  
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, o compilador é instruído para usar convenções de nomenclatura e chamada em C para a função `system`.  
  
```cpp  
// Example of the __cdecl keyword on function  
int __cdecl system(const char *);  
// Example of the __cdecl keyword on function pointer  
typedef BOOL (__cdecl *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
