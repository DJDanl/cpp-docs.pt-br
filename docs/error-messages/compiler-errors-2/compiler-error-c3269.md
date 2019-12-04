---
title: Erro do compilador C3269
ms.date: 11/04/2016
f1_keywords:
- C3269
helpviewer_keywords:
- C3269
ms.assetid: c575f067-244d-4dd5-bf58-9e7630ea58b7
ms.openlocfilehash: 95f71c9312faaf5c14bd8990898257002c528c0e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754011"
---
# <a name="compiler-error-c3269"></a>Erro do compilador C3269

' function ': uma função membro de um Managed ou WinRTtype não pode ser declarada com '... '

As funções de membro de classe gerenciada e WinRT não podem declarar listas de parâmetros de comprimento variável.

O exemplo a seguir gera C3269 e mostra como corrigi-lo:

```cpp
// C3269_2.cpp
// compile with: /clr

ref struct A
{
   void func(int i, ...)   // C3269
   // try the following line instead
   // void func(int i )
   {
   }
};

int main()
{
}
```
