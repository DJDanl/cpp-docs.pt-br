---
title: Compilador aviso (nível 1) C4002 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4002
dev_langs:
- C++
helpviewer_keywords:
- C4002
ms.assetid: 6bda1dfe-e2e4-4771-9794-5a404c466dd5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a3b3d51b4408e79236993d49f7ceba5fc9537b6d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050132"
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