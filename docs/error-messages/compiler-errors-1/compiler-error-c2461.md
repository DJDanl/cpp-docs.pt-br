---
title: Erro do compilador C2461
ms.date: 11/04/2016
f1_keywords:
- C2461
helpviewer_keywords:
- C2461
ms.assetid: e64ba651-f441-4fdb-b5cb-4209bbbe4db4
ms.openlocfilehash: 3d290bd2288f76d0ddefa2057e3e01c9edc3cbc7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205316"
---
# <a name="compiler-error-c2461"></a>Erro do compilador C2461

> '*Class*': parâmetros formais ausentes da sintaxe do Construtor

O construtor para a classe não especifica nenhum parâmetro formal. A declaração de um construtor deve especificar uma lista de parâmetros formais. A lista pode estar vazia.

Para corrigir esse problema, adicione um par de parênteses após a declaração da *classe*::**classe*.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como corrigir o C2461:

```cpp
// C2461.cpp
// compile with: /c
class C {
   C::C;     // C2461
   C::C();   // OK
};
```
