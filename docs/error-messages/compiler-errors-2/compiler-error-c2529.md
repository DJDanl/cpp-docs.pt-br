---
title: Erro do compilador C2529 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2529
dev_langs:
- C++
helpviewer_keywords:
- C2529
ms.assetid: 73a99e55-b91e-488d-9b72-cc80faaeb436
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9a6919c65dbe900cd4d6d4a60ef5370c6a683523
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46104277"
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