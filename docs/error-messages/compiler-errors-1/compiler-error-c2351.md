---
title: Erro do compilador C2351
ms.date: 11/04/2016
f1_keywords:
- C2351
helpviewer_keywords:
- C2351
ms.assetid: 5439ccf6-66f6-4859-964c-c73f5eddfc1b
ms.openlocfilehash: 6839d0c44efa10ba9507389fea35964fa748d646
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759965"
---
# <a name="compiler-error-c2351"></a>Erro do compilador C2351

sintaxe C++ de inicialização de Construtor obsoleto

Em uma lista de inicialização de novo estilo para um construtor, você deve nomear explicitamente cada classe base direta, mesmo que ela seja a única classe base.

O exemplo a seguir gera C2351:

```cpp
// C2351.cpp
// compile with: /c
class B {
public:
   B() : () {}   // C2351
   B() {}   // OK
};
```
