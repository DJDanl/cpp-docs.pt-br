---
title: Erro do compilador C2652
ms.date: 11/04/2016
f1_keywords:
- C2652
helpviewer_keywords:
- C2652
ms.assetid: 6e3d1a90-a989-4088-8afd-dc82f6a2d66f
ms.openlocfilehash: 9c9772052b690ad87de1d408c06478d82d48e724
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62282101"
---
# <a name="compiler-error-c2652"></a>Erro do compilador C2652

'identifier': construtor de cópia inválido: primeiro parâmetro não deve ser um identificador

O primeiro parâmetro no construtor de cópia tem o mesmo tipo que a classe, estrutura ou união para o qual ele está definido. O primeiro parâmetro pode ser uma referência para o tipo, mas não o próprio tipo.

O exemplo a seguir gera C2651:

```
// C2652.cpp
// compile with: /c
class A {
   A( A );   // C2652 takes an A
};
class B {
   B( B& );   // OK, reference to B
};
```