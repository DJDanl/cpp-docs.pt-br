---
title: Erro do compilador C2731
ms.date: 11/04/2016
f1_keywords:
- C2731
helpviewer_keywords:
- C2731
ms.assetid: 9b563999-febd-4582-9147-f355083c091e
ms.openlocfilehash: 4b73ee4ad205bfc2203423b5f413011ce090852f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755805"
---
# <a name="compiler-error-c2731"></a>Erro do compilador C2731

' identifier ': a função não pode ser sobrecarregada

As funções `main`, `WinMain`, `DllMain`e `LibMain` não podem ser sobrecarregadas.

O exemplo a seguir gera C2731:

```cpp
// C2731.cpp
extern "C" void WinMain(int, char *, char *);
void WinMain(int, short, char *, char*);   // C2731
```
