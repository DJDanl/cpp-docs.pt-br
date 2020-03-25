---
title: Diretivas de pré-processamento de makefile
ms.date: 08/11/2019
f1_keywords:
- '!UNDEF'
- '!INCLUDE'
- '!IFNDEF'
- '!MESSAGE'
helpviewer_keywords:
- ERROR directive
- '!MESSAGE directive'
- IF directive
- '!UNDEF directive'
- IFDEF directive
- '!ELSEIF directive'
- '!IFDEF directive'
- '!IF directive'
- UNDEF directive
- '!CMDSWITCHES directive'
- ENDIF directive
- directives, makefile preprocessing
- INCLUDE directive
- IFNDEF directive
- preprocessing directives, makefiles
- '!IFNDEF directive'
- ELSEIFNDEF directive
- NMAKE program, expressions
- ELSEIF directive
- '!ERROR directive'
- '!ENDIF directive'
- MESSAGE directive
- '!INCLUDE directive'
- '!ELSEIFNDEF directive'
- CMDSWITCHES directive
- '!ELSEIFDEF directive'
- '!ELSE directive'
- NMAKE program, preprocessor directives
- makefiles, preprocessing directives
- ELSE directive
- ELSEIFDEF directive
ms.assetid: bcedeccb-d981-469d-b9e8-ab5d097fd8c2
ms.openlocfilehash: 1dd30c8e338343626d8a8cc3157d118e44f0ea18
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170482"
---
# <a name="makefile-preprocessing-directives"></a>Diretivas de pré-processamento de makefile

As diretivas de pré-processamento não diferenciam maiúsculas de minúsculas. O ponto de exclamação inicial (!) deve aparecer no início da linha. Zero ou mais espaços ou tabulações podem aparecer após o ponto de exclamação, para recuo.

- opção `!CMDSWITCHES` { &#124;`+` `-`*option* }...

   Ativa ou desativa cada *opção* listada. Espaços ou tabulações devem aparecer antes do `+` ou operador de `-`; nenhum pode aparecer entre o operador e as [letras de opção](running-nmake.md#nmake-options). As letras não diferenciam maiúsculas de minúsculas e são especificadas sem uma barra (`/`). Para ativar algumas opções e desativar outras, use especificações separadas de `!CMDSWITCHES`.

   Somente/D,/I,/N e/S podem ser usados em um makefile. No Tools. ini, todas as opções são permitidas, exceto/F,/HELP,/NOLOGO,/X e/?. As alterações especificadas em um bloco de descrição não entram em vigor até o próximo bloco de descrição. Essa diretiva atualiza **MAKEFLAGS**; as alterações serão herdadas durante a recursão se **MAKEFLAGS** for especificado.

- `!ERROR` *texto*

   Exibe o *texto* no erro U1050, em seguida, interrompe NMAKE, mesmo se/K,/i, `.IGNORE`, `!CMDSWITCHES`ou o modificador de comando dash (`-`) for usado. Espaços ou tabulações antes de o *texto* ser ignorado.

- `!MESSAGE` *texto*

   Exibe o *texto* para a saída padrão. Espaços ou tabulações antes de o *texto* ser ignorado.

- `!INCLUDE` [`<`] *nome do arquivo* [`>`]

   Lê *filename* como um makefile e continua com o makefile atual. NMAKE pesquisa primeiro o *nome do arquivo* no diretório especificado ou atual e, em seguida, recursivamente por meio de diretórios de qualquer makefile pai, então, se o nome do *arquivo* estiver entre colchetes angulares (`< >`), em diretórios especificados pela macro **include** , que é inicialmente definida como a variável de ambiente INCLUDE. Útil para passar configurações de `.SUFFIXES`, `.PRECIOUS`e regras de inferência para makefiles recursivos.

- `!IF` *constant_expression*

   Processa instruções entre `!IF` e a próxima `!ELSE` ou `!ENDIF` se *constant_expression* for avaliada como um valor diferente de zero.

- `!IFDEF` *macroname*

   Processa instruções entre `!IFDEF` e a próxima `!ELSE` ou `!ENDIF` se *macroname* for definido. Uma macro nula é considerada como definida.

- `!IFNDEF` *macroname*

   Processa instruções entre `!IFNDEF` e a próxima `!ELSE` ou `!ENDIF` se *macroname* não estiver definida.

- `!ELSE` [`IF` *constant_expression* &#124; `IFDEF` *macroname* &#124; `IFNDEF` *nomedamacro*]

   Processa instruções entre `!ELSE` e a próxima `!ENDIF` se a instrução `!IF`, `!IFDEF`ou `!IFNDEF` anterior for avaliada como zero. As palavras-chave opcionais oferecem controle adicional do pré-processamento.

- `!ELSEIF`

   Sinônimo para `!ELSE IF`.

- `!ELSEIFDEF`

   Sinônimo para `!ELSE IFDEF`.

- `!ELSEIFNDEF`

   Sinônimo para `!ELSE IFNDEF`.

- `!ENDIF`

   Marca o final de um `!IF`, `!IFDEF`ou `!IFNDEF` bloco. Qualquer texto após `!ENDIF` na mesma linha é ignorado.

- `!UNDEF` *macroname*

   Não define o *nomedamacro*.

## <a name="see-also"></a>Confira também

- [Pré-processamento de makefile](makefile-preprocessing.md)
