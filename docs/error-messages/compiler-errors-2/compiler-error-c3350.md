---
title: Erro do compilador C3350 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3350
dev_langs:
- C++
helpviewer_keywords:
- C3350
ms.assetid: cfbbc338-92b5-4f34-999e-aa2d2376bc70
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 809145755242146b1d047947df26551d005ea002
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46098453"
---
# <a name="compiler-error-c3350"></a>Erro do compilador C3350

'delegate': um construtor delegate espera um argumento de número (s)

Quando você cria uma instância de um delegado, você deve passar dois argumentos, uma instância do tipo que contém a função de delegação e a função.

O exemplo a seguir gera C3350:

```
// C3350.cpp
// compile with: /clr
delegate void SumDelegate();

public ref class X {
public:
   void F() {}
   static void F2() {}
};

int main() {
   X ^ MyX = gcnew X();
   SumDelegate ^ pSD = gcnew SumDelegate();   // C3350
   SumDelegate ^ pSD1 = gcnew SumDelegate(MyX, &X::F);
   SumDelegate ^ pSD2 = gcnew SumDelegate(&X::F2);
}
```
