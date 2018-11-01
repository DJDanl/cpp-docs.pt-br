---
title: Compilador aviso (nível 1) C4716
ms.date: 11/04/2016
f1_keywords:
- C4716
helpviewer_keywords:
- C4716
ms.assetid: d95ecfe5-870f-461f-a746-7913af98414b
ms.openlocfilehash: 5ec0aea543053d699db7483df7dd7ea91b3af715
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594539"
---
# <a name="compiler-warning-level-1-c4716"></a>Compilador aviso (nível 1) C4716

'function' deve retornar um valor

A função fornecida não retornou um valor.

Somente funções com um tipo de retorno de void podem usam o comando de retorno sem um valor de retorno que acompanha este artigo.

Será retornado um valor indefinido quando essa função é chamada.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md).

O exemplo a seguir gera C4716:

```
// C4716.cpp
// compile with: /c /W1
// C4716 expected
#pragma warning(default:4716)
int test() {
   // uncomment the following line to resolve
   // return 0;
}
```