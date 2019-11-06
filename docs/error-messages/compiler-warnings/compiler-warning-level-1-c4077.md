---
title: Aviso do compilador (nível 1) C4077
ms.date: 11/04/2016
f1_keywords:
- C4077
helpviewer_keywords:
- C4077
ms.assetid: c2d28805-b33f-41ad-afba-33b3f788c649
ms.openlocfilehash: fb9684b812e039bd37278f9f27db9225d0131f23
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626910"
---
# <a name="compiler-warning-level-1-c4077"></a>Aviso do compilador (nível 1) C4077

opção check_stack desconhecida

A forma antiga do pragma **check_stack** é usada com um argumento desconhecido. O argumento deve ser `+`, `-`, `(on)`, `(off)`ou vazio.

O compilador ignora o pragma e deixa a verificação de pilha inalterada.

## <a name="example"></a>Exemplo

```cpp
// C4077.cpp
// compile with: /W1 /LD
#pragma check_stack yes // C4077
#pragma check_stack +    // Correct old form
#pragma check_stack (on) // Correct new form
```