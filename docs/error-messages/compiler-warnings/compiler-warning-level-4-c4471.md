---
title: Compilador aviso (nível 4) C4471
ms.date: 04/24/2017
f1_keywords:
- C4471
helpviewer_keywords:
- C4471
ms.assetid: ccfd8bd5-bc1b-4be7-a6ea-0e3a7add6607
ms.openlocfilehash: 0345b730b8fc37329f632bb5d8486c67efd8e3b8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400780"
---
# <a name="compiler-warning-level-4-c4471"></a>Compilador aviso (nível 4) C4471

'*enumeração*': declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)

Uma declaração de encaminhamento de uma enumeração sem escopo foi encontrada sem um especificador de para o tipo subjacente. Por padrão, o Visual C++ pressupõe `int` é o tipo subjacente para uma enumeração. Isso pode causar problemas se um tipo diferente é usado na definição de enumeração, por exemplo, se um tipo explícito diferente for especificado, ou se um tipo diferente é definido implicitamente por um inicializador. Você também pode ter problemas de portabilidade de; outros compiladores não pressuponha que `int` é o tipo subjacente de uma enumeração.

Esse aviso é desativado por padrão. Você pode usar /Wall ou /w*N*4471 para habilitá-lo na linha de comando ou use #pragma [aviso](../../preprocessor/warning.md) no arquivo de origem.

Em alguns casos, esse aviso é falso. Se uma declaração de encaminhamento para uma enumeração é exibida após a definição, esse aviso pode ser acionado. Por exemplo, esse código é válido, mesmo que ele pode causar C4471:

```cpp
// C4471a.cpp
// Compile with: cl /c /w14471 C4471a.cpp
enum Example { item = 0x80000000UL };
enum Example;    // Spurious C4471
// ...
```

## <a name="example"></a>Exemplo

Em geral, é seguro usar a definição completa para uma enumeração sem escopo, em vez de uma declaração de encaminhamento. Você pode colocar a definição em um arquivo de cabeçalho e incluí-lo nos arquivos de origem que se referem a ele. Isso funciona em código escrito para c++98 e versões posteriores. Recomendamos essa solução para portabilidade e a facilidade de manutenção.

```cpp
// C4471b.cpp
// Compile with: cl /c /w14471 C4471b.cpp
enum Example;    // C4471
// To fix, replace the line above with the enumeration definition:
// enum Example { item = 0x80000000UL };
// ...
```

## <a name="example"></a>Exemplo

No C++ 11, você pode adicionar um tipo explícito para uma enumeração sem escopo e sua declaração de encaminhamento. Recomendamos essa solução somente se a lógica de inclusão do cabeçalho complexo impede o uso da definição em vez de uma declaração de encaminhamento. Essa solução pode levar a um problema de manutenção: se você alterar o tipo subjacente usado para a definição de enumeração, você também deve alterar todas as declarações de encaminhamento para corresponder ou você pode ter erros silenciosos em seu código. Você pode colocar a declaração de encaminhamento em um arquivo de cabeçalho para minimizar esse problema.

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

Se você especificar um tipo explícito para uma enumeração, recomendamos que você habilite o aviso também [C4369](compiler-warning-level-1-C4369.md), que é ativado por padrão. Isso identifica a casos em que um item de enumeração requer um tipo diferente do tipo especificado explicitamente.

## <a name="example"></a>Exemplo

Você pode alterar seu código para usar uma enumeração com escopo, um recurso que há de novo no c++11. A definição e qualquer código de cliente que usa o tipo de enumeração devem ser alterados para usar um enum de escopo. É recomendável que você use uma enumeração com escopo se você tiver problemas com a poluição de namespace, como os nomes dos itens de enumeração definido são limitados ao escopo do enum. Outro recurso de um enum de escopo é que seus membros não podem ser convertidos implicitamente em outro tipo integral ou de enumeração, que pode ser uma fonte de bugs sutis.

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

