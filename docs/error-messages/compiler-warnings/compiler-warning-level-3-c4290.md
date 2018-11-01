---
title: Compilador aviso (nível 3) C4290
ms.date: 11/04/2016
f1_keywords:
- C4290
helpviewer_keywords:
- C4290
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
ms.openlocfilehash: c585294686298a1197d437d41a0d541f1268985f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50512730"
---
# <a name="compiler-warning-level-3-c4290"></a>Compilador aviso (nível 3) C4290

Especificação de exceção de C++ ignorada, exceto to indicam uma função não é __declspec(nothrow)

Uma função é declarada usando a especificação de exceção, o que o Visual C++ aceita, mas não implementa. Codifique com exceção de especificações que são ignoradas durante a compilação precisa ser recompilado e vinculado para ser reutilizado em futuras versões que dão suporte a especificações de exceção.

Para obter mais informações, consulte [especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md) .

Você pode evitar esse aviso usando o [aviso](../../preprocessor/warning.md) pragma:

```
#pragma warning( disable : 4290 )
```

O exemplo de código a seguir gera C4290:

```
// C4290.cpp
// compile with: /EHs /W3 /c
void f1(void) throw(int) {}   // C4290

// OK
void f2(void) throw() {}
void f3(void) throw(...) {}
```