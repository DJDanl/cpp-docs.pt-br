---
title: Compilador aviso (nível 4) C4234 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4234
dev_langs:
- C++
helpviewer_keywords:
- C4234
ms.assetid: f7fecd5c-8248-4fde-8446-502aedc357ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a6ce6ba622cb480096144706589a01dee7326f38
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118226"
---
# <a name="compiler-warning-level-4-c4234"></a>Compilador aviso (nível 4) C4234

extensão não padrão usada: palavra-chave de 'palavra-chave' reservada para uso futuro

O compilador ainda não implementa a palavra-chave que você usou.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar um problema de aviso de nível 4, C4234

```
#pragma warning(2:4234)
```

no arquivo de código fonte.