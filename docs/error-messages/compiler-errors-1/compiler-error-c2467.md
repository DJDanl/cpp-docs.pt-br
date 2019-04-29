---
title: Erro do compilador C2467
ms.date: 11/04/2016
f1_keywords:
- C2467
helpviewer_keywords:
- C2467
ms.assetid: f9ead270-5d0b-41cc-bdcd-586a647c67a7
ms.openlocfilehash: aa45cbb19519dea7bd5c8fb96abd2c76ea30a786
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62302079"
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