---
title: Erro do compilador C2768
ms.date: 11/04/2016
f1_keywords:
- C2768
helpviewer_keywords:
- C2768
ms.assetid: a7f6047a-6a80-4737-ad5c-c12868639fb5
ms.openlocfilehash: 9c0fb8fb0a98830aaf061ba980e7bdd7903f25e1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62257604"
---
# <a name="compiler-error-c2768"></a>Erro do compilador C2768

'function': uso inválido de argumentos de modelo explícitos

O compilador não pôde determinar se uma definição de função deveria para ser uma especialização explícita de um modelo de função ou se a definição da função deveria para ser para uma nova função.

Esse erro foi introduzido no Visual Studio .NET 2003, como parte dos aprimoramentos de conformidade do compilador.

O exemplo a seguir gera C2768:

```
// C2768.cpp
template<typename T>
void f(T) {}

void f<int>(int) {}   // C2768

// an explicit specialization
template<>
void f<int>(int) {}

// global nontemplate function overload
void f(int) {}
```