---
title: Erro do compilador C2765
ms.date: 11/04/2016
f1_keywords:
- C2765
helpviewer_keywords:
- C2765
ms.assetid: 47ad86f3-a7e0-47ad-85ff-0f5534458cb9
ms.openlocfilehash: 7b34bd8b352e8872722e9402d8d0113ae6157292
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50491631"
---
# <a name="compiler-error-c2765"></a>Erro do compilador C2765

'function': uma especialização explícita de um modelo de função não pode ter argumentos padrão

Argumentos padrão não são permitidos em uma especialização explícita de um modelo de função. Para obter mais informações, consulte [especialização explícita de modelos de função](../../cpp/explicit-specialization-of-function-templates.md).

O exemplo a seguir gera C2765:

```
// C2765.cpp
template<class T> void f(T t) {};

template<> void f<char>(char c = 'a') {}   // C2765
// try the following line instead
// template<> void f<char>(char c) {}
```