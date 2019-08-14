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
ms.openlocfilehash: 4825ca180cb1b419a9ffa5232575ba1a24f8805d
ms.sourcegitcommit: db1ed91fa7451ade91c3fb76bc7a2b857f8a5eef
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2019
ms.locfileid: "68980518"
---
# <a name="makefile-preprocessing-directives"></a>Diretivas de pré-processamento de makefile

As diretivas de pré-processamento não diferenciam maiúsculas de minúsculas. O ponto de exclamação inicial (!) deve aparecer no início da linha. Zero ou mais espaços ou tabulações podem aparecer após o ponto de exclamação, para recuo.

- `!CMDSWITCHES``+` *opção* { &#124; }...`-`

   Ativa ou desativa cada *opção* listada. Espaços ou tabulações devem aparecer antes `+` do `-` operador OR; nenhum pode aparecer entre o operador e as [letras de opção](running-nmake.md#nmake-options). As letras não diferenciam maiúsculas de minúsculas e são`/`especificadas sem uma barra (). Para ativar algumas opções e desativar outras, use especificações separadas do `!CMDSWITCHES`.

   Somente/D,/I,/N e/S podem ser usados em um makefile. No Tools. ini, todas as opções são permitidas, exceto/F,/HELP,/NOLOGO,/X e/?. As alterações especificadas em um bloco de descrição não entram em vigor até o próximo bloco de descrição. Essa diretiva atualiza **MAKEFLAGS**; as alterações serão herdadas durante a recursão se **MAKEFLAGS** for especificado.

- `!ERROR`*texto* de

   Exibe o *texto* no erro U1050, em seguida, interrompe NMAKE, mesmo se/k, `.IGNORE`/i `!CMDSWITCHES`,, ou o modificador de comando Dash (`-`) for usado. Espaços ou tabulações antes de o *texto* ser ignorado.

- `!MESSAGE`*texto* de

   Exibe o *texto* para a saída padrão. Espaços ou tabulações antes de o *texto* ser ignorado.

- `!INCLUDE`[ `<` ] *nome* do `>` arquivo []

   Lê *filename* como um makefile e continua com o makefile atual. NMAKE pesquisa primeiro o *nome do arquivo* no diretório especificado ou atual e, em seguida, recursivamente por meio de diretórios de qualquer makefile pai, então, se o nome do`< >` *arquivo* estiver entre colchetes angulares (), em diretórios especificados pelo  **INCLUIR** macro, que é inicialmente definida como a variável de ambiente INCLUDE. Útil para passar `.SUFFIXES` configurações, `.PRECIOUS`e regras de inferência para makefiles recursivos.

- `!IF`*constant_expression*

   Processa as instruções `!IF` entre e a `!ELSE` próxima `!ENDIF` ou se *constant_expression* for avaliada como um valor diferente de zero.

- `!IFDEF`*nomedamacro*

   Processa as instruções `!IFDEF` entre e a `!ELSE` próxima `!ENDIF` ou se macroname for definido. Uma macro nula é considerada como definida.

- `!IFNDEF`*nomedamacro*

   Processa as instruções `!IFNDEF` entre e o `!ELSE` próximo `!ENDIF` ou se macroname não estiver definido.

- `!ELSE`[`IF` &#124; constant_expression &#124; macroname] `IFDEF` `IFNDEF`

   Processa instruções entre `!ELSE` e a próxima `!ENDIF` se a instrução `!IF`anterior `!IFDEF`, ou `!IFNDEF` for avaliada como zero. As palavras-chave opcionais oferecem controle adicional do pré-processamento.

- `!ELSEIF`

   Sinônimo para `!ELSE IF`.

- `!ELSEIFDEF`

   Sinônimo para `!ELSE IFDEF`.

- `!ELSEIFNDEF`

   Sinônimo para `!ELSE IFNDEF`.

- `!ENDIF`

   Marca o fim de um `!IF`bloco `!IFDEF`, ou `!IFNDEF` . Qualquer texto após `!ENDIF` a mesma linha é ignorado.

- `!UNDEF`*nomedamacro*

   Não define o *nomedamacro*.

## <a name="see-also"></a>Consulte também

- [Pré-processamento de makefile](makefile-preprocessing.md)