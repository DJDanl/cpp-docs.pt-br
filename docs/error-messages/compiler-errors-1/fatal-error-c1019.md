---
title: Erro fatal C1019 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1019
dev_langs:
- C++
helpviewer_keywords:
- C1019
ms.assetid: c4f8968b-bc62-4200-b3ca-69d06c163236
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b3aa7f73fb546e9c7ae8f64a0705a4af40bbc640
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46055865"
---
# <a name="fatal-error-c1019"></a>Erro fatal C1019

inesperado #else

O `#else` diretiva aparece fora de um `#if`, `#ifdef`, ou `#ifndef` construir. Use `#else` apenas dentro de uma dessas construções.

O exemplo a seguir gera C1019:

```
// C1019.cpp
#else   // C1019
#endif

int main() {}
```

Solução possível:

```
// C1019b.cpp
#if 1
#else
#endif

int main() {}
```