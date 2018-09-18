---
title: CXX0064 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0064
dev_langs:
- C++
helpviewer_keywords:
- CAN0064
- CXX0064
ms.assetid: aa509e71-0616-41ca-a94e-6c376b041e57
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b16133484af5a2225f79c5d293a2c8edd948bdb2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025887"
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