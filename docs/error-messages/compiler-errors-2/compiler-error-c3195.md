---
title: Erro do compilador C3195
ms.date: 11/04/2016
f1_keywords:
- C3195
helpviewer_keywords:
- C3195
ms.assetid: 97e4f681-812b-49e8-ba57-24b7817e3cd8
ms.openlocfilehash: 4a54a9c629a1abaa4f1c5d15d06448e82cf25561
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50538843"
---
# <a name="compiler-error-c3195"></a>Erro do compilador C3195

'operator': é reservado e não pode ser usado como um membro de um tipo de valor ou classe ref. Operadores CLR ou WinRT devem ser definidos usando a palavra-chave 'operator'

O compilador detectou uma definição de operador, usando as extensões gerenciadas para a sintaxe de C++. Você deve usar a sintaxe do C++ para operadores.

O exemplo a seguir gera C3195 e mostra como corrigi-lo:

```
// C3195.cpp
// compile with: /clr /LD
#using <mscorlib.dll>
value struct V {
   static V op_Addition(V v, int i);   // C3195
   static V operator +(V v, char c);   // OK for new C++ syntax
};
```