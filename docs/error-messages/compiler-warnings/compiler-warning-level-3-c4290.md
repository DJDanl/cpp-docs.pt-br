---
title: Compilador aviso (nível 3) C4290 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4290
dev_langs:
- C++
helpviewer_keywords:
- C4290
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3a6f09d8f3396381f34a0fbe3c7150b5948cee01
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46015959"
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