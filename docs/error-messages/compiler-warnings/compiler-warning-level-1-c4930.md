---
title: Aviso do compilador (nível 1) C4930
ms.date: 11/04/2016
f1_keywords:
- C4930
helpviewer_keywords:
- C4930
ms.assetid: 89a206c9-c536-4186-8e81-1cde3e7f4f5b
ms.openlocfilehash: 6c012e484bddeb204601265f9d56efb7bbee7e96
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199310"
---
# <a name="compiler-warning-level-1-c4930"></a>Aviso do compilador (nível 1) C4930

' Prototype ': função de protótipo não chamada (era uma definição de variável pretendida?)

O compilador detectou um protótipo de função não utilizado. Se o protótipo foi planejado como uma declaração de variável, remova os parênteses de abertura/fechamento.

O exemplo a seguir gera C4930:

```cpp
// C4930.cpp
// compile with: /W1
class Lock {
public:
   int i;
};

void f() {
   Lock theLock();   // C4930
   // try the following line instead
   // Lock theLock;
}

int main() {
}
```

C4930 também pode ocorrer quando o compilador não pode distinguir entre uma declaração de protótipo de função e uma chamada de função.

O exemplo a seguir gera C4930:

```cpp
// C4930b.cpp
// compile with: /EHsc /W1

class BooleanException
{
   bool _result;

public:
   BooleanException(bool result)
      : _result(result)
   {
   }

   bool GetResult() const
   {
      return _result;
   }
};

template<class T = BooleanException>
class IfFailedThrow
{
public:
   IfFailedThrow(bool result)
   {
      if (!result)
      {
         throw T(result);
      }
   }
};

class MyClass
{
public:
   bool MyFunc()
   {
      try
      {
         IfFailedThrow<>(MyMethod()); // C4930

         // try one of the following lines instead
         // IfFailedThrow<> ift(MyMethod());
         // IfFailedThrow<>(this->MyMethod());
         // IfFailedThrow<>((*this).MyMethod());

         return true;
      }
      catch (BooleanException e)
      {
         return e.GetResult();
      }
   }

private:
   bool MyMethod()
   {
      return true;
   }
};

int main()
{
   MyClass myClass;
   myClass.MyFunc();
}
```

No exemplo acima, o resultado de um método que usa zero argumentos é passado como um argumento para o construtor de uma variável de classe local sem nome. A chamada pode ser desambiguada, nomeando a variável local ou prefixando a chamada de método com uma instância de objeto junto com o operador ponteiro para membro apropriado.
