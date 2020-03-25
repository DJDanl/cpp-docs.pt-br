---
title: Erro CXX0064 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0064
helpviewer_keywords:
- CAN0064
- CXX0064
ms.assetid: aa509e71-0616-41ca-a94e-6c376b041e57
ms.openlocfilehash: f763754299ed9257fb909b49a7a19c6f3ad58681
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80184457"
---
# <a name="expression-evaluator-error-cxx0064"></a>Erro CXX0064 (avaliador de expressão)

Não é possível definir o ponto de interrupção na função membro virtual associada

Um ponto de interrupção foi definido em uma função membro virtual por meio de um ponteiro para um objeto, como:

```
pClass->vfunc( int );
```

Um ponto de interrupção pode ser definido em uma função virtual inserindo a classe, como:

```
Class::vfunc( int );
```

Esse erro é idêntico a CAN0064.
