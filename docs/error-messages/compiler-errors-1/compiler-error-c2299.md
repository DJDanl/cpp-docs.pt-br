---
title: Erro do compilador C2299
ms.date: 11/04/2016
f1_keywords:
- C2299
helpviewer_keywords:
- C2299
ms.assetid: d001c2bc-f6fd-47aa-8e42-0eb824d6441d
ms.openlocfilehash: 009a441ec610053176e79126d9f2663f29b26bc6
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759042"
---
# <a name="compiler-error-c2299"></a>Erro do compilador C2299

' function ': alteração de comportamento: uma especialização explícita não pode ser um construtor de cópia ou um operador de atribuição de cópia

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: versões anteriores C++ do Visual permitiam especializações explícitas para um construtor de cópia ou um operador de atribuição de cópia.

Para resolver C2299, não torne o construtor de cópia ou o operador de atribuição uma função de modelo, mas sim uma função que não seja de modelo que usa um tipo de classe. Qualquer código que chama o construtor de cópia ou o operador de atribuição especificando explicitamente os argumentos do modelo precisa remover os argumentos do modelo.

O exemplo a seguir gera C2299:

```cpp
// C2299.cpp
// compile with: /c
class C {
   template <class T>
   C (T t);

   template <> C (const C&);   // C2299
   C (const C&);   // OK
};
```
