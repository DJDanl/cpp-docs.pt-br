---
title: Erro CXX0064 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0064
helpviewer_keywords:
- CAN0064
- CXX0064
ms.assetid: aa509e71-0616-41ca-a94e-6c376b041e57
ms.openlocfilehash: 71e4e3e87b33849e6b487b79268ebc9574c2e5a6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62299472"
---
# <a name="expression-evaluator-error-cxx0064"></a>Erro CXX0064 (avaliador de expressão)

não é possível definir o ponto de interrupção na função de membro virtual ligada

Um ponto de interrupção foi definido em uma função de membro virtual por meio de um ponteiro para um objeto, como:

```
pClass->vfunc( int );
```

Um ponto de interrupção pode ser definido em uma função virtual inserindo a classe, como:

```
Class::vfunc( int );
```

Esse erro é idêntico ao CAN0064.