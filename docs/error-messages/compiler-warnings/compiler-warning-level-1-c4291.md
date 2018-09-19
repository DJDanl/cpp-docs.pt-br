---
title: Compilador aviso (nível 1) C4291 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4291
dev_langs:
- C++
helpviewer_keywords:
- C4291
ms.assetid: c2b95dea-38f2-4609-9104-707c30798da4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b8c5f2fe57d26de4b4b2f88a85f20b99344ac201
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038042"
---
# <a name="compiler-warning-level-1-c4291"></a>Compilador aviso (nível 1) C4291

'declaração de ': Nenhum operador delete encontrado; memória não será liberada se inicialização lançar uma exceção

Uma colocação [novos](../../cpp/new-operator-cpp.md) é usado para o qual não há nenhum posicionamento [excluir](../../cpp/delete-operator-cpp.md).

Quando a memória é alocada para um objeto com o operador **novo**, o construtor do objeto é chamado. Se o construtor gerará uma exceção, nenhuma memória que foi alocada para o objeto deve ser desalocada. Isso não pode ocorrer, a menos que um operador **exclua** a função existe que corresponde ao operador **novos**.

Se você usar o operador **novos** sem quaisquer argumentos extras e compilar com [/GX](../../build/reference/gx-enable-exception-handling.md), [/EHs](../../build/reference/eh-exception-handling-model.md), ou opções de /EHa para habilitar a manipulação de exceção, o compilador irá gerar o código para chamar o operador **excluir** se o construtor gerará uma exceção.

Se você usar o formulário de posicionamento do **novo** operador (o formulário com argumentos além do tamanho da alocação) e o construtor do objeto gerou uma exceção, o compilador ainda irá gerar o código para chamar o operador **excluir**; mas ele só fará isso se um formulário de posicionamento do operador **excluir** existe o formulário de posicionamento do operador de correspondência **nova** que a memória alocada. Por exemplo:

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

O exemplo acima gera o aviso C4291 porque nenhum formulário de posicionamento do operador **excluir** foi definida que coincide com o formulário de posicionamento do operador **novos**. Para resolver o problema, insira o seguinte código acima **principal**. Observe que todos o operador sobrecarregado **exclua** parâmetros de função correspondem do operador sobrecarregado **novos**, exceto o primeiro parâmetro.

```
void operator delete(void* pMem, char* pszFilename, int nLine)
{
   free(pMem);
}
```