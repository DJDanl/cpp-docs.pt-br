---
title: "Compilador (nível 1) de aviso C4291 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4291
dev_langs: C++
helpviewer_keywords: C4291
ms.assetid: c2b95dea-38f2-4609-9104-707c30798da4
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2a1c03e12805c35ce04322a7ffb4d48499a9a9f3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4291"></a>Compilador C4291 de aviso (nível 1)
'declaração de ': Nenhum operador delete correspondente encontrado; memória não será liberada se inicialização lançar uma exceção  
  
 Uma colocação [novo](../../cpp/new-operator-cpp.md) é usado para a qual não há nenhum posicionamento [excluir](../../cpp/delete-operator-cpp.md).  
  
 Quando a memória é alocada para um objeto com o operador **novo**, o construtor do objeto é chamado. Se o construtor lançará uma exceção, nenhuma memória que foi alocada para o objeto deve ser desalocada. Isso não pode ocorrer, a menos que um operador **excluir** função existe que coincide com o operador **novo**.  
  
 Se você usar o operador **novo** sem argumentos extras e compile com [/GX](../../build/reference/gx-enable-exception-handling.md), [/EHs](../../build/reference/eh-exception-handling-model.md), ou opções de /EHa para habilitar a manipulação de exceção, o compilador gerará código para operador de chamada **excluir** se o construtor lançará uma exceção.  
  
 Se você usar o formato de posicionamento do **novo** operador (o formulário com argumentos além do tamanho da alocação) e o construtor do objeto gerou uma exceção, o compilador ainda irá gerar código para chamar o operador **excluir**; mas ele só fará isso se um formulário de posicionamento do operador **excluir** existe correspondência o formulário de posicionamento do operador **novo** que a memória alocada. Por exemplo:  
  
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
  
 O exemplo anterior gera o aviso C4291 porque nenhuma forma de posicionamento de operador **excluir** foi definido que corresponda a forma de posicionamento de operador **novo**. Para resolver o problema, insira o seguinte código acima **principal**. Observe que todos o operador sobrecarregado **excluir** parâmetros de função correspondem do operador sobrecarregado **novo**, exceto o primeiro parâmetro.  
  
```  
void operator delete(void* pMem, char* pszFilename, int nLine)  
{  
   free(pMem);  
}  
```