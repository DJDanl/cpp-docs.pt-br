---
title: "Compilador (nível 4) de aviso C4471 | Microsoft Docs"
ms.custom: 
ms.date: 04/24/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4471
dev_langs: C++
helpviewer_keywords: C4471
ms.assetid: ccfd8bd5-bc1b-4be7-a6ea-0e3a7add6607
caps.latest.revision: "1"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a1476beca6b34e8afb53058c7961822f0fb48109
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4471"></a>Compilador C4471 de aviso (nível 4)
'*enumeração*': declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)  
  
Declaração de encaminhamento de uma enumeração sem escopo foi encontrada sem um especificador para o tipo subjacente. Por padrão, o Visual C++ assume `int` é o tipo subjacente para uma enumeração. Isso pode causar problemas se um tipo diferente é usado na definição de enumeração, por exemplo, se um tipo diferente de explícito for especificado, ou se um tipo diferente é definido implicitamente por um inicializador. Você também poderá ter problemas de portabilidade; outros compiladores não supõem `int` é o tipo subjacente de uma enumeração.  
  
Esse aviso é desativado por padrão. Você pode usar /Wall ou /w*N*4471 para habilitá-lo na linha de comando ou use #pragma [aviso](../../preprocessor/warning.md) no arquivo de origem.  
  
Em alguns casos, esse aviso é falso. Se uma declaração de encaminhamento para uma enumeração aparece depois da definição, esse aviso pode ser acionado. Por exemplo, este código é válido, mesmo que isso pode causar C4471:  
  
```cpp  
// C4471a.cpp
// Compile with: cl /c /w14471 C4471a.cpp
enum Example { item = 0x80000000UL };
enum Example;    // Spurious C4471
// ...
```  
  
## <a name="example"></a>Exemplo  
Em geral, é seguro usar a definição completa para uma enumeração sem escopo, em vez de uma declaração de encaminhamento. Você pode colocar a definição em um arquivo de cabeçalho e incluí-lo nos arquivos de origem que fazem referência a ele. Isso funciona em código escrito para o C + + 98 e posterior. Recomendamos essa solução para a portabilidade e facilidade de manutenção.  
  
```cpp  
// C4471b.cpp
// Compile with: cl /c /w14471 C4471b.cpp
enum Example;    // C4471
// To fix, replace the line above with the enumeration definition:
// enum Example { item = 0x80000000UL };
// ...
```  
  
## <a name="example"></a>Exemplo  
No C++ 11, você pode adicionar um tipo explícito para uma enumeração sem escopo e sua declaração de encaminhamento. Recomendamos essa solução somente se a lógica de inclusão de cabeçalho complexo impede o uso da definição em vez de uma declaração de encaminhamento. Essa solução pode levar a um problema de manutenção: se você alterar o tipo subjacente usado para a definição de enumeração, você deve também alterar todas as declarações de encaminhamento para corresponder ou você pode ter erros silenciosos em seu código. Você pode colocar a declaração de encaminhamento em um arquivo de cabeçalho para minimizar esse problema.  
  
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
  
Se você especificar um tipo explícito para uma enumeração, recomendamos que você habilite o aviso também [C4369](compiler-warning-level-1-C4369.md), que é ativado por padrão. Isso identifica os casos em que um item de enumeração requer um tipo diferente do tipo especificado explicitamente.
  
## <a name="example"></a>Exemplo  
Você pode alterar o código para usar um enum de escopo, um recurso que é novo no C++ 11. A definição e qualquer código de cliente que usa o tipo de enumeração devem ser alterados para usar um enum de escopo. Recomendamos que você use uma enum com escopo se você tiver problemas com poluição de namespace, como os nomes dos itens de enumeração definido são limitados ao escopo do enum. Outro recurso de um enum de escopo é que seus membros não podem ser convertidos implicitamente em outro tipo integral ou de enumeração, que pode ser uma fonte de erros sutis.

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
  
