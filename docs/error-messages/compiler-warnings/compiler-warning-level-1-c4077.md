---
title: Compilador aviso (nível 1) C4077 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4077
dev_langs:
- C++
helpviewer_keywords:
- C4077
ms.assetid: c2d28805-b33f-41ad-afba-33b3f788c649
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6bf2b8f6f70db3d9cf385c87d1c9e71b4df05920
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044815"
---
# <a name="compiler-warning-level-1-c4077"></a>Compilador aviso (nível 1) C4077

opção de check_stack desconhecida

A forma antiga de **check_stack** pragma é usado com um argumento desconhecido. O argumento deve ser `+`, `-`, `(on)`, `(off)`, ou está vazio.

O compilador ignora o pragma e deixa a verificação da pilha inalterado.

## <a name="example"></a>Exemplo

```
// C4077.cpp
// compile with: /W1 /LD
#pragma check_stack yes // C4077
#pragma check_stack +    // Correct old form
#pragma check_stack (on) // Correct new form
```