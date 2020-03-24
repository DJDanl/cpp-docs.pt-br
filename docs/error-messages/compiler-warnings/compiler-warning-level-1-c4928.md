---
title: Aviso do compilador (nível 1) C4928
ms.date: 11/04/2016
f1_keywords:
- C4928
helpviewer_keywords:
- C4928
ms.assetid: 77235d7f-9360-45cb-8348-d148c605c4a3
ms.openlocfilehash: 54abb1072d8911fb7287b786f5a4254a710af815
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199323"
---
# <a name="compiler-warning-level-1-c4928"></a>Aviso do compilador (nível 1) C4928

inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada

Mais de uma rotina de conversão definida pelo usuário foi encontrada. O compilador executou o código em todas essas rotinas.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4928:

```cpp
// C4928.cpp
// compile with: /W1
#pragma warning(default: 4928)

struct I
{
};

struct I1 : I
{
};

struct I2 : I
{
};

template <class T>
struct Ptr
{
   operator T*()
   {
      return 0;
   }

   Ptr()
   {
   }

   Ptr(I*)
   {
   }
};

int main()
{
   Ptr<I1> p1;
   Ptr<I2> p2 = p1;   // C4928
   // try one of the following two lines to resolve this error
   // Ptr<I2> p2(p1);
   // Ptr<I2> p2 = (I1*) p1;
}
```
