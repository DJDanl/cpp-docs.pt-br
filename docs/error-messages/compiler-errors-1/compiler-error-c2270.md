---
title: Erro do compilador C2270
ms.date: 11/04/2016
f1_keywords:
- C2270
helpviewer_keywords:
- C2270
ms.assetid: b52c068e-0b61-42e7-b775-4d57b3ddcba0
ms.openlocfilehash: 67dc970ffb5dac218072ff98046f88c31a9c2db9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758717"
---
# <a name="compiler-error-c2270"></a>Erro do compilador C2270

' function ': modificadores não permitidos em funções não membro

Uma função não membro é declarada com [const](../../cpp/const-cpp.md), [volátil](../../cpp/volatile-cpp.md)ou outro modificador de modelo de memória.

O exemplo a seguir gera C2270:

```cpp
// C2270.cpp
// compile with: /c
void func1(void) const;   // C2270, nonmember function

void func2(void);

class CMyClass {
public:
   void func2(void) const;
};
```
