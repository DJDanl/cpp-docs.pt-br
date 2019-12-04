---
title: Erro do compilador C3195
ms.date: 11/04/2016
f1_keywords:
- C3195
helpviewer_keywords:
- C3195
ms.assetid: 97e4f681-812b-49e8-ba57-24b7817e3cd8
ms.openlocfilehash: c8274e121e953c3e51a0f2ff8c68c315759ce3e1
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760420"
---
# <a name="compiler-error-c3195"></a>Erro do compilador C3195

' operator ': é reservado e não pode ser usado como um membro de uma ref class ou de um tipo Value. Os operadores CLR ou WinRT devem ser definidos usando a palavra-chave ' operator '

O compilador detectou uma definição de operador usando as C++ extensões gerenciadas para sintaxe. Você deve usar a C++ sintaxe para operadores.

O exemplo a seguir gera C3195 e mostra como corrigi-lo:

```cpp
// C3195.cpp
// compile with: /clr /LD
#using <mscorlib.dll>
value struct V {
   static V op_Addition(V v, int i);   // C3195
   static V operator +(V v, char c);   // OK for new C++ syntax
};
```
