---
title: "Operadores de pré-processamento de makefile | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- operators [C++], makefile preprocessing
- EXIST operator
- preprocessing NMAKE makefile operators
- NMAKE program, operators
- DEFINED operator
- makefiles, preprocessing operators
ms.assetid: a46e4d39-afdb-43c1-ac3b-025d33e6ebdb
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 59007bdabc81b5fe49aa4b5265dc0fc73ef4f0b3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="makefile-preprocessing-operators"></a>Operadores de pré-processamento de makefile
As expressões de pré-processamento makefile podem usar operadores que agem em valores constantes, códigos de saída de comandos, cadeias de caracteres, macros e caminhos do sistema de arquivos. Para avaliar a expressão, o pré-processador primeiro expande macros, executa comandos para, então, realizar as operações. As operações são avaliadas na ordem do agrupamento explícito entre parênteses, em seguida, na ordem da precedência do operador. O resultado é um valor constante.  
  
 O operador `DEFINED` é um operador lógico que age em um nome de macro. A expressão `DEFINED(` *nomedamacro* `)` é verdadeiro se *nomedamacro* é definida, mesmo se ele não tem um valor atribuído. `DEFINED`em combinação com `!IF` ou `!ELSE IF` é equivalente a `!IFDEF` ou `!ELSE IFDEF`. Porém, diferentemente dessas diretivas, o `DEFINED` pode ser usado em expressões complexas.  
  
 O operador `EXIST` é um operador lógico que age em um caminho do sistema de arquivos. `EXIST(`*caminho* `)` é verdadeiro se *caminho* existe. O resultado de `EXIST` pode ser usado em expressões binárias. Se *caminho* contiver espaços, coloque-o entre aspas duplas.  
  
 Para comparar duas cadeias de caracteres, use o operador de igualdade (`==`) ou de desigualdade (`!=`). Coloque as cadeias de caracteres entre aspas duplas.  
  
 As constantes de inteiro podem usar os operadores unários na negação numérica (`-`), no complemento de um (`~`) e na negação lógica (`!`).  
  
 As expressões podem usar os operadores a seguir. Os operadores de precedência igual são agrupados, e os grupos são listados em ordem decrescente de precedência. Os operadores unários são associados ao operando à direita. Os operadores binários de precedência igual associam operandos da esquerda para a direita.  
  
|Operador|Descrição|  
|--------------|-----------------|  
|`DEFINED(`*nomedamacro*`)`|Produz um valor lógico para o estado atual da definição de *nomedamacro*.|  
|`EXIST(`*caminho*`)`|Produz um valor lógico a existência de um arquivo em *caminho*.|  
|||  
|`!`|NOT lógico unário.|  
|`~`|Complemento de um unário.|  
|`-`|Negação unária.|  
|||  
|`*`|Multiplicação.|  
|`/`|Divisão.|  
|`%`|Módulo (pendências).|  
|||  
|`+`|Adição.|  
|`-`|Subtração.|  
|||  
|`<<`|Mudança bit a bit para esquerda.|  
|`>>`|Mudança bit a bit para direita.|  
|||  
|`<=`|Menor que ou igual a.|  
|`>=`|Maior que ou igual a.|  
|`<`|Menor que.|  
|`>`|Maior que.|  
|||  
|`==`|Igualdade.|  
|`!=`|Desigualdade.|  
|||  
|`&`|AND bit a bit.|  
|`^`|XOR bit a bit.|  
|`&#124;`|OR bit a bit.|  
|||  
|`&&`|AND lógico.|  
|||  
|`&#124;&#124;`|OR lógico.|  
  
> [!NOTE]
>  O operador XOR bit a bit (`^`) é igual ao caractere de escape, e o escape deverá ser feito (como `^^`) quando ele for usado em uma expressão.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões no pré-processamento de makefile](../build/expressions-in-makefile-preprocessing.md)