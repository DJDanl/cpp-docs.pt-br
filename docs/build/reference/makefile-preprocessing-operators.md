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
ms.openlocfilehash: 2276f6a3c28c6f2fac509ef0e4bc14cce9932582
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170457"
---
# <a name="makefile-preprocessing-operators"></a>Operadores de pré-processamento de makefile

As expressões de pré-processamento makefile podem usar operadores que agem em valores constantes, códigos de saída de comandos, cadeias de caracteres, macros e caminhos do sistema de arquivos. Para avaliar a expressão, o pré-processador primeiro expande macros, executa comandos para, então, realizar as operações. As operações são avaliadas na ordem do agrupamento explícito entre parênteses, em seguida, na ordem da precedência do operador. O resultado é um valor constante.

O operador **definido** é um operador lógico que age em um nome de macro. A expressão **definida (** _macroname_ **)** será true se *macroname* for definida, mesmo que não tenha um valor atribuído. **Definido** em combinação com **! SE** ou **! Caso contrário, se** for equivalente a **! IFDEF** ou **! caso contrário, IFDEF**. No entanto, ao contrário dessas diretivas, **definidas** podem ser usadas em expressões complexas.

O operador **exist** é um operador lógico que age em um caminho de sistema de arquivos. **Exist (** _caminho_ **)** será true se o *caminho* existir. O resultado de **Exists** pode ser usado em expressões binárias. Se o *caminho* contiver espaços, coloque-o entre aspas duplas.

Para comparar duas cadeias de caracteres, use o operador de igualdade ( **==** ) ou o operador de desigualdade ( **! =** ). Coloque as cadeias de caracteres entre aspas duplas.

As constantes de inteiro podem usar os operadores unários para negação numérica ( **-** ), complemento de um ( **~** ) e negação lógica ( **!** ).

As expressões podem usar os operadores a seguir. Os operadores de precedência igual são agrupados, e os grupos são listados em ordem decrescente de precedência. Os operadores unários são associados ao operando à direita. Os operadores binários de precedência igual associam operandos da esquerda para a direita.

|Operador|DESCRIÇÃO|
|--------------|-----------------|
|**Definido (** *nomedamacro* **)**|Produz um valor lógico para o estado de definição atual de *macroname*.|
|**Existe (** *caminho* **)**|Produz um valor lógico para a existência de um arquivo no *caminho*.|
|||
|**!**|NOT lógico unário.|
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
> O operador ( **^** ) de XOR bits é o mesmo que o caractere de escape e deve ter escape (como **^^** ) quando ele é usado em uma expressão.

## <a name="see-also"></a>Confira também

- [Expressões no pré-processamento de makefile](expressions-in-makefile-preprocessing.md)
