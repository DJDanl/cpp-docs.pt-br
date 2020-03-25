---
title: Aviso do compilador (nível 3) C4290
ms.date: 11/04/2016
f1_keywords:
- C4290
helpviewer_keywords:
- C4290
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
ms.openlocfilehash: 5970aa439a450bda4c1a2036da299d5c3cfbdb7a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198894"
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
