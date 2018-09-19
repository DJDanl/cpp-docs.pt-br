---
title: Erro do compilador C2600 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2600
dev_langs:
- C++
helpviewer_keywords:
- C2600
ms.assetid: cce11943-ea01-4bee-a7b0-b67d24ec6493
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c1846cefa78c8df13e8ca3c1a7fbc142ba2bf6ad
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46022078"
---
# <a name="compiler-error-c2600"></a>Erro do compilador C2600

"função": não é possível definir uma função de membro especial gerado pelo compilador (deve ser declarado primeiro na classe)

Antes de funções de membro, como construtores ou destruidores, podem ser definidas para uma classe, devem ser declaradas na classe. O compilador pode gerar construtores e destruidores padrão (chamados de funções de membro especiais) se nenhum for declarado na classe. No entanto, se você definir uma dessas funções sem uma declaração correspondente na classe, o compilador detecta um conflito.

Para corrigir esse erro, na declaração da classe, declare cada função de membro definida por você fora da declaração de classe.

O seguinte exemplo gera C2600:

```
// C2600.cpp
// compile with: /c
class C {};
C::~C() {}   // C2600

class D {
   D::~D();
};

D::~D() {}
```