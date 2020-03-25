---
title: Aviso do compilador (nível 1) C4002
ms.date: 11/04/2016
f1_keywords:
- C4002
helpviewer_keywords:
- C4002
ms.assetid: 6bda1dfe-e2e4-4771-9794-5a404c466dd5
ms.openlocfilehash: cb1e36a606f5c8bb0a1622260d64124264f0db32
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164762"
---
# <a name="compiler-warning-level-1-c4002"></a>Aviso do compilador (nível 1) C4002

muitos parâmetros reais para macro ' identifier '

O número de parâmetros reais na macro excede o número de parâmetros formais na definição de macro. O pré-processador coleta os parâmetros extras, mas os ignora durante a expansão da macro.

C4002 pode ocorrer ao usar [Macros Variadic](../../preprocessor/variadic-macros.md)incorretamente.

O exemplo a seguir gera C4002:

```cpp
// C4002.cpp
// compile with: /W1
#define test(a) (a)

int main() {
   int a = 1;
   int b = 2;
   a = test(a,b);   // C4002
   // try..
   a = test(a);
}
```

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: vírgulas extras em macro não são mais aceitas.

O compilador não aceitará mais vírgulas extras em uma macro. Para que o código seja válido nas versões do Visual Studio .NET 2003 e do Visual Studio .NET do C++Visual, remova as vírgulas extras.

```cpp
// C4002b.cpp
// compile with: /W1
#define F(x,y)
int main()
{
   F(2,,,,,,3,,,,,,)   // C4002
   // Try the following line instead:
   // F(2,3)
}
```
