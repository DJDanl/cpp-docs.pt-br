---
title: Erro do compilador C2081
ms.date: 11/04/2016
f1_keywords:
- C2081
helpviewer_keywords:
- C2081
ms.assetid: 7db9892d-364d-4178-a49d-f8398ece09a0
ms.openlocfilehash: 2bccd15b8c2b6d1c5cd6c4b536bbdaf350eb0181
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408648"
---
# <a name="compiler-error-c2081"></a>Erro do compilador C2081

'identifier': nome ilegal da lista de parâmetros formais

O identificador causou um erro de sintaxe.

Esse erro pode ser causado por usando o estilo antigo para a lista de parâmetros formais. Você deve especificar o tipo dos parâmetros formais na lista de parâmetros formais.

O exemplo a seguir gera C2081:

```
// C2081.c
void func( int i, j ) {}  // C2081, no type specified for j
```

Solução possível:

```
// C2081b.c
// compile with: /c
void func( int i, int j ) {}
```