---
title: Erro do compilador C2534
ms.date: 11/04/2016
f1_keywords:
- C2534
helpviewer_keywords:
- C2534
ms.assetid: 481f9f54-5b51-4aa0-8eea-218f10807705
ms.openlocfilehash: 202e3bbe2238b4cc2a5233ac4e093717d623f099
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87207895"
---
# <a name="compiler-error-c2534"></a>Erro do compilador C2534

' identifier ': o construtor não pode retornar um valor

Um construtor não pode retornar um valor ou ter um tipo de retorno (nem mesmo um **`void`** tipo de retorno).

Esse erro pode ser corrigido removendo a **`return`** instrução da definição do construtor.

O exemplo a seguir gera C2534:

```cpp
// C2534.cpp
class A {
public:
   int i;
   A() { return i; }   // C2534
};
```
