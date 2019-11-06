---
title: Aviso do compilador (nível 1) C4002
ms.date: 11/04/2016
f1_keywords:
- C4002
helpviewer_keywords:
- C4002
ms.assetid: 6bda1dfe-e2e4-4771-9794-5a404c466dd5
ms.openlocfilehash: 6aac8285e3935bb0fb910b52a7dd813d0a708732
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627402"
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