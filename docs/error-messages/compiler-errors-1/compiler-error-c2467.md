---
title: Erro do compilador C2467 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2467
dev_langs:
- C++
helpviewer_keywords:
- C2467
ms.assetid: f9ead270-5d0b-41cc-bdcd-586a647c67a7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8bab320bfdba9fcbd408771b7859a22fc85fa06e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46048767"
---
# <a name="compiler-error-c2467"></a>Erro do compilador C2467

declaração inválida de anônimo '-tipo definido pelo usuário '

Um tipo aninhado definido pelo usuário foi declarado. Este é um erro ao compilar o código-fonte com a opção de compatibilidade de ANSI C ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) habilitado.

O exemplo a seguir gera C2467:

```
//C2467.c
// compile with: /Za
int main() {
   struct X {
      union { int i; };   // C2467, nested declaration
   };
}
```