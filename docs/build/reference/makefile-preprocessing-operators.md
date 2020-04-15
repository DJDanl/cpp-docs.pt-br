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
ms.openlocfilehash: 212f39ee62008b391977aaa91d5c8c4fadfd9730
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336467"
---
# <a name="makefile-preprocessing-operators"></a>Operadores de pré-processamento de makefile

As expressões de pré-processamento makefile podem usar operadores que agem em valores constantes, códigos de saída de comandos, cadeias de caracteres, macros e caminhos do sistema de arquivos. Para avaliar a expressão, o pré-processador primeiro expande macros, executa comandos para, então, realizar as operações. As operações são avaliadas na ordem do agrupamento explícito entre parênteses, em seguida, na ordem da precedência do operador. O resultado é um valor constante.

O operador **DEFINED** é um operador lógico que atua em um nome macro. A expressão DEFINED _(macronome)_**)** é verdadeira se *o macronome* for definido, mesmo que não tenha um valor atribuído. **DEFINED(** **DEFINIDO** em combinação com **! SE** **ou! ELSE IF** é equivalente a **! IFDEF** **ou! OUTRA IFDEF**. No entanto, ao contrário dessas diretivas, **DEFINED** pode ser usado em expressões complexas.

O operador **EXIST** é um operador lógico que atua em um caminho de sistema de arquivos. **EXISTE**_(caminho)_**)** é verdadeiro se *o caminho* existe. O resultado do **EXIST** pode ser usado em expressões binárias. Se *o caminho* contiver espaços, atenha-o entre aspas duplas.

Para comparar duas cordas, use**==** o operador de igualdade ( ) ou o operador da desigualdade **(!=**). Coloque as cadeias de caracteres entre aspas duplas.

As constantes inteiras podem usar os operadores unários**-** para negação**~** numérica ( ), complemento ( ) e negação lógica (**!**).

As expressões podem usar os operadores a seguir. Os operadores de precedência igual são agrupados, e os grupos são listados em ordem decrescente de precedência. Os operadores unários são associados ao operando à direita. Os operadores binários de precedência igual associam operandos da esquerda para a direita.

|Operador|Descrição|
|--------------|-----------------|
|**DEFINIDO** *(macronome)* **)**|Produz um valor lógico para o estado de definição atual de *macronome*.|
|**EXIST** *(caminho)* **)**|Produz um valor lógico para a existência de um arquivo no *caminho*.|
|||
|**!**|NOT lógico unário.|
|**~**|Um complemento unary.|
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
|**!=**|Desigualdade.|
|||
|**&**|AND bit a bit.|
|**^**|XOR bit a bit.|
|**&#124;**|OR bit a bit.|
|||
|**&&**|AND Lógico.|
|||
|**&#124;&#124;**|OR Lógico.|

> [!NOTE]
> O operador BitWISE**^** XOR ( ) é o mesmo que **^^** o caractere de fuga, e deve ser escapado (como ) quando é usado em uma expressão.

## <a name="see-also"></a>Confira também

- [Expressões no Pré-processamento makefile](expressions-in-makefile-preprocessing.md)
