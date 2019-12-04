---
title: Erro do compilador C2395
ms.date: 11/04/2016
f1_keywords:
- C2395
helpviewer_keywords:
- C2395
ms.assetid: 2d9e3b28-8c2c-4f41-a57f-61ef88fc2af0
ms.openlocfilehash: 2ac59856770b04dd3c4ea14360e0a83dd99f2150
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74744934"
---
# <a name="compiler-error-c2395"></a>Erro do compilador C2395

' your_type:: operator'op ' ': operador CLR ou WinRT não é válido. Pelo menos um parâmetro deve ser dos seguintes tipos: ' T', ' T' ', ' t & ', ' t ^ ', ' t ^% ', ' t ^ & ', em que T = ' your_type '

Um operador em um Windows Runtime ou tipo gerenciado não tinha pelo menos um parâmetro cujo tipo é o mesmo que o tipo do valor de retorno do operador.

O exemplo a seguir gera C2395 e mostra como corrigi-lo:

```cpp
// C2395.cpp
// compile with: /clr /c
value struct V {
   static V operator *(int i, char c);   // C2395

   // OK
   static V operator *(V v, char c);
   // or
   static V operator *(int i, V& rv);
};
```
