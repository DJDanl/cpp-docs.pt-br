---
title: Compilador aviso (nível 1) C4716 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4716
dev_langs:
- C++
helpviewer_keywords:
- C4716
ms.assetid: d95ecfe5-870f-461f-a746-7913af98414b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4f7a6fd31ecae4643e947cb4a56897e80010e350
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46093396"
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