---
title: Erro do compilador C2081
ms.date: 11/04/2016
f1_keywords:
- C2081
helpviewer_keywords:
- C2081
ms.assetid: 7db9892d-364d-4178-a49d-f8398ece09a0
ms.openlocfilehash: 2e8e813d8162b9a191b6760366b52783e7c8609f
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301984"
---
# <a name="compiler-error-c2081"></a>Erro do compilador C2081

' identifier ': nome inválido na lista de parâmetros formais

O identificador causou um erro de sintaxe.

Esse erro pode ser causado pelo uso do estilo antigo para a lista de parâmetros formais. Você deve especificar o tipo de parâmetros formais na lista de parâmetros formais.

O exemplo a seguir gera C2081:

```c
// C2081.c
void func( int i, j ) {}  // C2081, no type specified for j
```

Resolução possível:

```c
// C2081b.c
// compile with: /c
void func( int i, int j ) {}
```
