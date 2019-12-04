---
title: Erro do compilador C2790
ms.date: 11/04/2016
f1_keywords:
- C2790
helpviewer_keywords:
- C2790
ms.assetid: 38d4fce1-ba00-413d-8bc1-e8aa43d7bc1f
ms.openlocfilehash: c63fe7bb3686692818337e890de7fe4c80a18158
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74739552"
---
# <a name="compiler-error-c2790"></a>Erro do compilador C2790

' super ': esta palavra-chave só pode ser usada dentro do corpo da função membro da classe

Essa mensagem de erro será exibida se o usuário tentar usar a palavra-chave [super](../../cpp/super.md) fora do contexto de uma função de membro.

O exemplo a seguir gera C2790:

```cpp
// C2790.cpp
void f() {
   __super::g();   // C2790
}
```
