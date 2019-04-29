---
title: Erro do compilador C2461
ms.date: 11/04/2016
f1_keywords:
- C2461
helpviewer_keywords:
- C2461
ms.assetid: e64ba651-f441-4fdb-b5cb-4209bbbe4db4
ms.openlocfilehash: e8f82ed4ce8ad77a22961a42c8e9a256e6f647db
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62368026"
---
# <a name="compiler-error-c2461"></a>Erro do compilador C2461

> '*classe*': faltando parâmetros formais na sintaxe do construtor

O construtor da classe não especifica quaisquer parâmetros formais. A declaração de um construtor deve especificar uma lista de parâmetros formais. A lista pode estar vazia.

Para corrigir esse problema, adicione um par de parênteses após a declaração de *classe*:: **classe*.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como corrigir C2461:

```cpp
// C2461.cpp
// compile with: /c
class C {
   C::C;     // C2461
   C::C();   // OK
};
```