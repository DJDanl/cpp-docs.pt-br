---
title: Aviso do compilador (nível 3) C4290
ms.date: 11/04/2016
f1_keywords:
- C4290
helpviewer_keywords:
- C4290
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
ms.openlocfilehash: 5ccacd7d5f4dfd2e9ad8de3958d7aa43571091fe
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051658"
---
# <a name="compiler-warning-level-3-c4290"></a>Aviso do compilador (nível 3) C4290

C++especificação de exceção ignorada, exceto para indicar que uma função não é __declspec (nothrow)

Uma função é declarada usando A especificação de C++ exceção, que o Visual aceita, mas não implementa. O código com especificações de exceção que são ignoradas durante a compilação pode precisar ser recompilado e vinculado para ser reutilizado em versões futuras que dão suporte a especificações de exceção.

Para obter mais informações, consulte [especificações de exceção (throw)](../../cpp/exception-specifications-throw-cpp.md) .

Você pode evitar esse aviso usando o pragma de [aviso](../../preprocessor/warning.md) :

```cpp
#pragma warning( disable : 4290 )
```

O exemplo de código a seguir gera C4290:

```cpp
// C4290.cpp
// compile with: /EHs /W3 /c
void f1(void) throw(int) {}   // C4290

// OK
void f2(void) throw() {}
void f3(void) throw(...) {}
```