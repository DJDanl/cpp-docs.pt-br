---
title: Erro do compilador C2461 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2461
dev_langs:
- C++
helpviewer_keywords:
- C2461
ms.assetid: e64ba651-f441-4fdb-b5cb-4209bbbe4db4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 39d58b315fdd7e3c4e1899041cebf8400813ed40
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46029293"
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