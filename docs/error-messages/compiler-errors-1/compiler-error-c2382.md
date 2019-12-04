---
title: Erro do compilador C2382
ms.date: 11/04/2016
f1_keywords:
- C2382
helpviewer_keywords:
- C2382
ms.assetid: 4d4436f9-d0d6-4bd0-b8ec-767b89adfb2f
ms.openlocfilehash: 8b623d292998960052ff5d6978d8c12ae7f3fb32
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745363"
---
# <a name="compiler-error-c2382"></a>Erro do compilador C2382

' função ': redefinição; especificações de exceção diferentes

Em [/za](../../build/reference/za-ze-disable-language-extensions.md), esse erro indica que uma sobrecarga de função foi tentada apenas na [especificação de exceção](../../cpp/exception-specifications-throw-cpp.md).

O exemplo a seguir gera C2382:

```cpp
// C2382.cpp
// compile with: /Za /c
void f1(void) throw(int) {}
void f1(void) throw(char) {}   // C2382
void f2(void) throw(char) {}   // OK
```
