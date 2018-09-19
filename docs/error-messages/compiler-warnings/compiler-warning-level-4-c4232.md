---
title: Compilador aviso (nível 4) C4232 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4232
dev_langs:
- C++
helpviewer_keywords:
- C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 450c764cfc130acf28e3edfb40fcd17c8ac3b664
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118278"
---
# <a name="compiler-warning-level-4-c4232"></a>Compilador aviso (nível 4) C4232

extensão não padrão usada: 'identifier': endereço de dllimport 'dllimport' não é estático, identidade não garantida

Em extensões da Microsoft (/Ze), você pode fornecer um valor não estático como o endereço de uma função declarada com o **dllimport** modificador. Sob a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), isso faz com que um erro.

O exemplo a seguir gera C4232:

```
// C4232.c
// compile with: /W4 /Ze /c
int __declspec(dllimport) f();
int (*pfunc)() = &f;   // C4232
```