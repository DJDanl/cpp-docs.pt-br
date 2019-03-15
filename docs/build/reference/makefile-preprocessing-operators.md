---
title: Operadores de pré-processamento de makefile
ms.date: 06/14/2018
helpviewer_keywords:
- operators [C++], makefile preprocessing
- EXIST operator
- preprocessing NMAKE makefile operators
- NMAKE program, operators
- DEFINED operator
- makefiles, preprocessing operators
ms.assetid: a46e4d39-afdb-43c1-ac3b-025d33e6ebdb
ms.openlocfilehash: 4101c2fe30bcba44e9b69ed4d6d022845e6e8904
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824341"
---
# <a name="makefile-preprocessing-operators"></a>Operadores de pré-processamento de makefile

As expressões de pré-processamento makefile podem usar operadores que agem em valores constantes, códigos de saída de comandos, cadeias de caracteres, macros e caminhos do sistema de arquivos. Para avaliar a expressão, o pré-processador primeiro expande macros, executa comandos para, então, realizar as operações. As operações são avaliadas na ordem do agrupamento explícito entre parênteses, em seguida, na ordem da precedência do operador. O resultado é um valor constante.

O **definido pelo** operador é um operador lógico que age em um nome de macro. A expressão **definidas (**_macroname_**)** é verdadeiro se *macroname* for definida, mesmo se ele não tem um valor atribuído. **Definido pelo** em combinação com **! IF** ou **! ELSE IF** é equivalente a **! IFDEF** ou **! ELSE IFDEF**. No entanto, diferentemente dessas diretivas, **definido pelo** pode ser usado em expressões complexas.

O **EXIST** operador é um operador lógico que age em um caminho de sistema de arquivos. **EXISTEM (**_caminho_**)** é verdadeiro se *caminho* existe. O resultado a partir **EXIST** pode ser usado em expressões binárias. Se *caminho* contiver espaços, coloque-o entre aspas duplas.

Para comparar duas cadeias de caracteres, use a igualdade (**==**) operador ou desigualdade (**! =**) operador. Coloque as cadeias de caracteres entre aspas duplas.

Constantes de inteiro podem usar os operadores unários negação numérica (**-**), um complemento (**~**) e na negação lógica (**!**).

As expressões podem usar os operadores a seguir. Os operadores de precedência igual são agrupados, e os grupos são listados em ordem decrescente de precedência. Os operadores unários são associados ao operando à direita. Os operadores binários de precedência igual associam operandos da esquerda para a direita.

|Operador|Descrição|
|--------------|-----------------|
|**DEFINED(** *macroname* **)**|Produz um valor lógico para o estado atual da definição de *macroname*.|
|**EXIST(** *path* **)**|Produz um valor lógico a existência de um arquivo no *caminho*.|
|||
|**\!**|NOT lógico unário.|
|**~**|Complemento de um unário.|
|**-**|Negação unária.|
|||
|**&#42;**|Multiplicação.|
|**/**|Divisão.|
|**%**|Módulo (pendências).|
|||
|**+**|Adição.|
|**-**|Subtração.|
|||
|**\<\<**|Mudança bit a bit para esquerda.|
|**>>**|Mudança bit a bit para direita.|
|||
|**\<=**|Menor que ou igual a.|
|**>=**|Maior que ou igual a.|
|**\<**|Menor que.|
|**>**|Maior que.|
|||
|**==**|Igualdade.|
|**\!=**|Desigualdade.|
|||
|**&**|AND bit a bit.|
|**^**|XOR bit a bit.|
|**&#124;**|OR bit a bit.|
|||
|**&&**|AND lógico.|
|||
|**&#124;&#124;**|OR lógico.|

> [!NOTE]
> O operador XOR bit a bit (**^**) é o mesmo que o caractere de escape e devem ser escapados (como **^^**) quando ele é usado em uma expressão.

## <a name="see-also"></a>Consulte também

- [Expressões no pré-processamento de makefile](expressions-in-makefile-preprocessing.md)