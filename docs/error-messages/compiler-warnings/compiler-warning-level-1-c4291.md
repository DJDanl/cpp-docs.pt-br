---
title: "Compilador aviso (nível 1) C4291 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4291
dev_langs:
- C++
helpviewer_keywords:
- C4291
ms.assetid: c2b95dea-38f2-4609-9104-707c30798da4
caps.latest.revision: 7
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1409cbe955719322af4c93dd8d49850cc9cf3b98
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4291"></a>Compilador C4291 de aviso (nível 1)
'declaração de ': Nenhum operador delete correspondente encontrado; memória não será liberada se a inicialização lança uma exceção  
  
 Um posicionamento [novo](../../cpp/new-operator-cpp.md) é usado para a qual não há nenhum posicionamento [excluir](../../cpp/delete-operator-cpp.md).  
  
 Quando a memória é alocada para um objeto com o operador **nova**, o construtor do objeto é chamado. Se o construtor lançará uma exceção, nenhuma memória que foi alocada para o objeto deve ser desalocada. Isso não pode ocorrer a menos que um operador **excluir** função existe que coincide com o operador **novo**.  
  
 Se você usar o operador **novo** sem quaisquer argumentos extras e compilar com [/GX](../../build/reference/gx-enable-exception-handling.md), [/EHs](../../build/reference/eh-exception-handling-model.md), ou /EHa opções para habilitar o tratamento de exceção, o compilador irá gerar o código para chamar o operador **excluir** se o construtor lançará uma exceção.  
  
 Se você usar o formulário de posicionamento do **novo** operador (o formulário com argumentos além do tamanho da alocação) e o construtor do objeto lançará uma exceção, o compilador ainda irá gerar o código para chamar o operador **excluir**; mas ele fará somente se um formulário de posicionamento do operador **excluir** existe o formulário de posicionamento do operador de correspondência **novo** que a memória alocada. Por exemplo:  
  
```  
// C4291.cpp  
// compile with: /EHsc /W1  
#include <malloc.h>  
  
class CList  
{  
public:  
   CList(int)  
   {  
      throw "Fail!";  
   }  
};  
  
void* operator new(size_t size, char* pszFilename, int nLine)  
{  
   return malloc(size);  
}  
  
int main(void)  
{  
   try  
   {  
      // This will call ::operator new(unsigned int) to allocate heap  
      // memory. Heap memory pointed to by pList1 will automatically be  
      // deallocated by a call to ::operator delete(void*) when  
      // CList::CList(int) throws an exception.  
      CList* pList1 = new CList(10);  
   }  
   catch (...)  
   {  
   }  
  
   try  
   {  
      // This will call the overloaded ::operator new(size_t, char*, int)  
      // to allocate heap memory. When CList::CList(int) throws an  
      // exception, ::operator delete(void*, char*, int) should be called  
      // to deallocate the memory pointed to by pList2. Since  
      // ::operator delete(void*, char*, int) has not been implemented,  
      // memory will be leaked when the deallocation cannot occur.  
      CList* pList2 = new(__FILE__, __LINE__) CList(20);   // C4291  
   }  
   catch (...)  
   {  
   }  
}  
```  
  
 O exemplo anterior gera o aviso C4291 porque nenhuma forma de posicionamento de operador **excluir** foi definido que coincide com o formulário de posicionamento do operador **novo**. Para resolver o problema, insira o seguinte código acima **principal**. Observe que todos o operador sobrecarregado **excluir** parâmetros de função correspondem do operador sobrecarregado **nova**, exceto o primeiro parâmetro.  
  
```  
void operator delete(void* pMem, char* pszFilename, int nLine)  
{  
   free(pMem);  
}  
```
