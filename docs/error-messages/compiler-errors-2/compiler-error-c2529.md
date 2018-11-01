---
title: Erro do compilador C2529
ms.date: 11/04/2016
f1_keywords:
- C2529
helpviewer_keywords:
- C2529
ms.assetid: 73a99e55-b91e-488d-9b72-cc80faaeb436
ms.openlocfilehash: b634f2369805114209860f5e304a7cd2cca2ec91
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50438773"
---
# <a name="compiler-error-c2529"></a>Erro do compilador C2529

'name': referência para referência é inválida

Esse erro pode ser corrigido usando a sintaxe de ponteiro e declarando uma referência a um ponteiro.

O exemplo a seguir gera C2529:

```
// C2529.cpp
// compile with: /c
int i;
int &ri = i;
int &(&rri) = ri;   // C2529
```