---
title: Erro do compilador C2688
ms.date: 11/04/2016
f1_keywords:
- C2688
helpviewer_keywords:
- C2688
ms.assetid: 168c9e9d-8f65-4664-af86-db71d3e6ee46
ms.openlocfilehash: 5355abc603726eb1bacb7a22fa1095bf2d81c538
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588544"
---
# <a name="compiler-error-c2688"></a>Erro do compilador C2688

'C2::fgrv': retornos covariantes com múltiplas heranças ou herança virtual não tem suportada para funções varargs

Não há suporte para tipos de retorno covariante no Visual C++ quando uma função contém argumentos variáveis.

Para resolver esse erro, defina suas funções para que eles não usam argumentos variáveis ou os valores de retorno de fazer o mesmo para todas as funções virtuais.

O exemplo a seguir gera C2688:

```
// C2688.cpp
struct G1 {};
struct G2 {};
struct G3 : G1, G2 {};
struct G4 {};
struct G5 {};
struct G6 : G4, G5 {};
struct G7 : G3, G6 {};

struct C1 {
   virtual G4& fgrv(int,...);
};

struct C2 : C1 {
   virtual G7& fgrv(int,...);   // C2688, does not return G4&
};
```