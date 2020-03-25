---
title: Aviso do compilador (nível 1) C4291
ms.date: 11/04/2016
f1_keywords:
- C4291
helpviewer_keywords:
- C4291
ms.assetid: c2b95dea-38f2-4609-9104-707c30798da4
ms.openlocfilehash: cd161a37683703fd67b4c682558a51121c130816
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175708"
---
# <a name="compiler-warning-level-1-c4291"></a>Aviso do compilador (nível 1) C4291

' declaração ': nenhuma exclusão de operador correspondente encontrada; a memória não será liberada se a inicialização lançar uma exceção

Um [novo](../../cpp/new-operator-cpp.md) posicionamento é usado para o qual não há [exclusão](../../cpp/delete-operator-cpp.md)de posicionamento.

Quando a memória é alocada para um objeto com o operador **New**, o construtor do objeto é chamado. Se o Construtor lançar uma exceção, qualquer memória alocada para o objeto deverá ser desalocada. Isso não pode ocorrer a menos que exista uma função de **exclusão** de operador que corresponda ao operador **novo**.

Se você usar o operador **novo** sem argumentos extras e compilar com as opções [/GX](../../build/reference/gx-enable-exception-handling.md), [o/EHS](../../build/reference/eh-exception-handling-model.md)ou/EHa para habilitar o tratamento de exceções, o compilador gerará código para chamar o Operator **delete** se o Construtor lançar uma exceção.

Se você usar a forma de posicionamento do operador **New** (o formulário com argumentos, além do tamanho da alocação) e o construtor do objeto gerar uma exceção, o compilador ainda terá código para chamar Operator **delete**; Mas isso só fará isso se uma forma de posicionamento de operador **delete** existir corresponder à forma de posicionamento do operador **novo** que alocou a memória. Por exemplo:

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

O exemplo acima gera o aviso C4291 porque nenhum formulário de posicionamento da **exclusão** do operador foi definido e corresponde à forma de posicionamento do operador **novo**. Para resolver o problema, insira o código a seguir acima de **principal**. Observe que todos os parâmetros de função de **exclusão** de operador sobrecarregados correspondem aos do operador sobrecarregado **novo**, exceto para o primeiro parâmetro.

```
void operator delete(void* pMem, char* pszFilename, int nLine)
{
   free(pMem);
}
```
