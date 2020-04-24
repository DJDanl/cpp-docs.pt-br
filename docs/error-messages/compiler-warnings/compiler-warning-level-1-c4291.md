---
title: Aviso do compilador (nível 1) C4291
ms.date: 11/04/2016
f1_keywords:
- C4291
helpviewer_keywords:
- C4291
ms.assetid: c2b95dea-38f2-4609-9104-707c30798da4
ms.openlocfilehash: c1972236e30be4e6ca738b606b00398f5c7860e0
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754859"
---
# <a name="compiler-warning-level-1-c4291"></a>Aviso do compilador (nível 1) C4291

'Declaração': não foi encontrada exclusão do operador correspondente; memória não será liberada se a inicialização lança uma exceção

Uma [nova](../../cpp/new-operator-cpp.md) colocação é usada para a qual não há [exclusão de](../../cpp/delete-operator-cpp.md)colocação .

Quando a memória é alocada para um objeto com **o novo**operador, o construtor do objeto é chamado. Se o construtor lançar uma exceção, qualquer memória que foi alocada para o objeto deve ser desalocada. Isso não pode ocorrer a menos que exista uma função **de exclusão** do operador que corresponda ao **novo**operador .

Se você usar o **operador novo** sem quaisquer argumentos extras e compilar com opções [/GX](../../build/reference/gx-enable-exception-handling.md), [/EHs](../../build/reference/eh-exception-handling-model.md)ou /EHa para permitir o manuseio de exceções, o compilador gerará código para excluir o **operador** de chamadas se o construtor lançar uma exceção.

Se você usar a forma de colocação do **novo** operador (o formulário com argumentos além do tamanho da alocação) e o construtor do objeto lançar uma exceção, o compilador ainda gerará código para excluir o **operador**de chamadas; mas só o fará se existir uma forma de colocação de exclusão do operador que **corresponda** à forma de colocação do **operador novo** que alocou a memória. Por exemplo:

```cpp
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

O exemplo acima gera aviso C4291 porque não foi definida uma forma de colocação de **exclusão** do operador que corresponda à forma de colocação do **operador novo**. Para resolver o problema, insira o seguinte código acima **principal**. Observe que todos os parâmetros de função de **exclusão** do operador sobrecarregado satismem com os do operador sobrecarregado **novo,** exceto o primeiro parâmetro.

```cpp
void operator delete(void* pMem, char* pszFilename, int nLine)
{
   free(pMem);
}
```
