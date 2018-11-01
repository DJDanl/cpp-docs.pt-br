---
title: Compilador aviso (nível 1) C4002
ms.date: 11/04/2016
f1_keywords:
- C4002
helpviewer_keywords:
- C4002
ms.assetid: 6bda1dfe-e2e4-4771-9794-5a404c466dd5
ms.openlocfilehash: f2d2166a1370c02cfbc2346a63a424239ccb2b92
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50463044"
---
# <a name="compiler-warning-level-1-c4002"></a>Compilador aviso (nível 1) C4002

Muitos parâmetros reais para 'identifier' macro

O número de parâmetros reais na macro excede o número de parâmetros formais na definição da macro. O pré-processador coleta os parâmetros extras, mas ignora durante a expansão de macro.

C4002 podem ocorrer ao usar incorretamente [Macros Variadic](../../preprocessor/variadic-macros.md).

O exemplo a seguir gera C4002:

```
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

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: vírgulas adicionais em macro não é mais aceito.

O compilador não aceitará mais vírgulas adicionais em uma macro. Para o código seja válido no Visual Studio .NET 2003 e versões do Visual Studio .NET do Visual C++, remova as vírgulas adicionais.

```
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