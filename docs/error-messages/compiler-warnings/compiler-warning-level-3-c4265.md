---
title: Aviso do compilador (nível 3) C4265
ms.date: 11/04/2016
f1_keywords:
- C4265
helpviewer_keywords:
- C4265
ms.assetid: 20547159-6f30-4cc4-83aa-927884c8bb4c
ms.openlocfilehash: 8ad07e2a920ed251467c9ffd1d0fb1765557aa7e
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051714"
---
# <a name="compiler-warning-level-3-c4265"></a>Aviso do compilador (nível 3) C4265

' class ': classe tem funções virtuais, mas destruidor não é virtual

Quando uma classe tem funções virtuais, mas um destruidor não virtual, os objetos do tipo podem não ser destruídos corretamente quando a classe é destruída por meio de um ponteiro de classe base.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4265:

```cpp
// C4265.cpp
// compile with: /W3 /c
#pragma warning(default : 4265)
class B
{
public:
   virtual void vmf();

   ~B();
   // try the following line instead
   // virtual ~B();
};   // C4265

int main()
{
   B b;
}
```