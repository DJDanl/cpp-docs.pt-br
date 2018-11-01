---
title: Erro do compilador C2351
ms.date: 11/04/2016
f1_keywords:
- C2351
helpviewer_keywords:
- C2351
ms.assetid: 5439ccf6-66f6-4859-964c-c73f5eddfc1b
ms.openlocfilehash: 2d93902ee0008a54da1b2ecf165e0a829362511f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665485"
---
# <a name="compiler-error-c2351"></a>Erro do compilador C2351

sintaxe de inicialização do construtor de C++ obsoleta

Em uma lista de inicialização de novo estilo para um construtor, você deve nomear explicitamente cada classe base direta, mesmo se ele é a classe base somente.

O exemplo a seguir gera C2351:

```
// C2351.cpp
// compile with: /c
class B {
public:
   B() : () {}   // C2351
   B() {}   // OK
};
```