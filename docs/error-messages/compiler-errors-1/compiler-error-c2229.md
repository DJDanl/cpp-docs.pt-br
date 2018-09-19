---
title: Erro do compilador C2229 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2229
dev_langs:
- C++
helpviewer_keywords:
- C2229
ms.assetid: 933c7cf2-a463-4e74-b0b4-59dedad987fb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b235b5fae84ba605ecec5419f9334ccfa0a4be6e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46035585"
---
# <a name="compiler-error-c2229"></a>Erro do compilador C2229

o tipo 'identifier' tem uma matriz de tamanho zero ilegal

Um membro de um campo de bits ou de estrutura contém uma matriz de tamanho zero não é o último membro.

Como você pode ter uma matriz de tamanho zero como o último membro de struct, você deve especificar seu tamanho ao alocar o struct.

Se a matriz de tamanho zero não é o último membro de struct, o compilador não pode calcular o deslocamento para os campos restantes.

O exemplo a seguir gera C2229:

```
// C2229.cpp
struct S {
   int a[0];  // C2229  zero-sized array
   int b[1];
};

struct S2 {
   int a;
   int b[0];
};

int main() {
   // allocate 7 elements for b field
   S2* s2 = (S2*)new int[sizeof(S2) + 7*sizeof(int)];
   s2->b[6] = 100;
}
```