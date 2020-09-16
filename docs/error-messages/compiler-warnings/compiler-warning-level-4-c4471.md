---
title: Aviso do compilador (nível 4) C4471
ms.date: 04/24/2017
f1_keywords:
- C4471
helpviewer_keywords:
- C4471
ms.assetid: ccfd8bd5-bc1b-4be7-a6ea-0e3a7add6607
ms.openlocfilehash: 5b8c3ef419a4c6eaf9a674827cd5545a1f1b2bfe
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90685496"
---
# <a name="compiler-warning-level-4-c4471"></a>Aviso do compilador (nível 4) C4471

'*Enumeration*': uma declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)

Foi encontrada uma declaração de encaminhamento de uma enumeração sem escopo com um especificador para o tipo subjacente. Por padrão, o Visual C++ pressupõe **`int`** que é o tipo subjacente para uma enumeração. Isso pode causar problemas se um tipo diferente for usado na definição de enumeração, por exemplo, se um tipo explícito diferente for especificado ou se um tipo diferente for definido implicitamente por um inicializador. Você também pode ter problemas de portabilidade; outros compiladores não pressupõem **`int`** o tipo subjacente de uma enumeração.

Esse aviso está desativado por padrão; Você pode usar/Wall ou/w*N*4471 para habilitá-lo na linha de comando ou usar #pragma [aviso](../../preprocessor/warning.md) no arquivo de origem.

## <a name="examples"></a>Exemplos

Em alguns casos, esse aviso é falso. Se uma declaração de encaminhamento para uma enumeração for exibida após a definição, esse aviso poderá ser acionado. Por exemplo, esse código é válido, embora possa causar C4471:

```cpp
// C4471a.cpp
// Compile with: cl /c /w14471 C4471a.cpp
enum Example { item = 0x80000000UL };
enum Example;    // Spurious C4471
// ...
```

Em geral, é seguro usar a definição completa para uma enumeração sem escopo em vez de uma declaração de encaminhamento. Você pode colocar a definição em um arquivo de cabeçalho e incluí-lo em arquivos de origem que se referem a ele. Isso funciona em código escrito para C++ 98 e posterior. Recomendamos essa solução para portabilidade e facilidade de manutenção.

```cpp
// C4471b.cpp
// Compile with: cl /c /w14471 C4471b.cpp
enum Example;    // C4471
// To fix, replace the line above with the enumeration definition:
// enum Example { item = 0x80000000UL };
// ...
```

No C++ 11, você pode adicionar um tipo explícito a uma enumeração sem escopo e à sua declaração de encaminhamento. Recomendamos essa solução somente se a lógica de inclusão de cabeçalho complexa impedir o uso da definição em vez de uma declaração de encaminhamento. Essa solução pode levar a um problema de manutenção: se você alterar o tipo subjacente usado para a definição de enumeração, também deverá alterar todas as declarações de encaminhamento para corresponder ou poderá ter erros silenciosos em seu código. Você pode colocar a declaração Forward em um arquivo de cabeçalho para minimizar esse problema.

```cpp
// C4471c.cpp
// Client code for enumeration defined in C4471d.cpp
// Compile with: cl /c /w14471 C4471c.cpp C4471d.cpp
enum Example;    // C4471, int assumed
// To fix, replace the lines above with the forward declarations:
// enum Example : unsigned;
// ...
```

```cpp
// C4471d.cpp
// Definition for enumeration used in C4471c.cpp
// Compile with: cl /c /w14471 C4471c.cpp C4471d.cpp
enum Example : unsigned { item = 0x80000000 }; // explicit type
// ...
```

Se você especificar um tipo explícito para uma enumeração, recomendamos que você também habilite o aviso [C4369](compiler-warning-level-1-C4369.md), que está ativado por padrão. Isso identifica casos em que um item de enumeração requer um tipo diferente do tipo especificado explicitamente.

Você pode alterar seu código para usar uma enumeração com escopo, um recurso novo no C++ 11. A definição e qualquer código de cliente que usa o tipo de enumeração devem ser alterados para usar uma enumeração com escopo. Recomendamos que você use uma enumeração com escopo se tiver problemas com a poluição do namespace, pois os nomes dos itens de enumeração definidos são limitados ao escopo da enumeração. Outro recurso de uma enumeração com escopo é que seus membros não podem ser convertidos implicitamente em outro tipo integral ou de enumeração, que pode ser uma fonte de Bugs sutis.

```cpp
// C4471e.cpp
// Client code for scoped enumeration defined in C4471f.cpp
// Compile with: cl /c /w14471 C4471e.cpp C4471f.cpp
enum Example;    // C4471
// To fix, replace the line above with the forward declaration:
// enum class Example;
// ...
```

```cpp
// C4471f.cpp
// Definition for scoped enumeration used in C4471e.cpp
// Compile with: cl /c /w14471 C4471e.cpp C4471f.cpp
enum class Example { item = 0 };
// ...
```
