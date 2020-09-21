---
title: Executando NMAKE
description: Saiba mais sobre como executar o NMAKE.
ms.date: 02/09/2020
helpviewer_keywords:
- targets, building
- response files, NMAKE
- targets
- command files
- NMAKE program, targets
- NMAKE program, running
- command files, NMAKE
ms.assetid: 0421104d-8b7b-4bf3-86c1-928d9b7c1a8c
ms.openlocfilehash: c2327e13e59ebf9df1ecba6fa66c6354641768ee
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743133"
---
# <a name="running-nmake"></a>Executando NMAKE

## <a name="syntax"></a>Sintaxe

> **NMAKE** [*opção* ...] [*macros* ...] [*destinos* ...] [ **\@** _arquivo de comando_ ...]

## <a name="remarks"></a>Comentários

NMAKE cria apenas *destinos* especificados ou, quando nenhum é especificado, o primeiro destino no Makefile. O primeiro destino de makefile pode ser um [pseudotarget](description-blocks.md#pseudotargets) que cria outros destinos. NMAKE usa os makefiles especificados com **/f**, ou se **/f** não for especificado, o arquivo Makefile no diretório atual. Se nenhum makefile for especificado, ele usará regras de inferência para criar *destinos*de linha de comando.

O arquivo de texto do *arquivo de comando* (ou arquivo de resposta) contém a entrada da linha de comando. Outras entradas podem preceder ou seguir o \@ *arquivo de comando*. Um caminho é permitido. No *arquivo de comando*, as quebras de linha são tratadas como espaços. Coloque as definições de macro entre aspas se elas contiverem espaços.

## <a name="nmake-options"></a>Opções de NMAKE

As opções de NMAKE são descritas na tabela a seguir. As opções são precedidas por uma barra ( `/` ) ou um traço ( `-` ) e não diferenciam maiúsculas de minúsculas. Use [`!CMDSWITCHES`](makefile-preprocessing-directives.md) para alterar as configurações de opção em um makefile ou em Tools.ini.

| Opção | Finalidade |
| ------------ | ------------- |
| **SRDF** | Força a compilação de todos os destinos avaliados, mesmo que não esteja desatualizado em comparação com os dependentes. Não força compilações de destinos não relacionados. |
| **/B.** | Força a compilação mesmo se os carimbos de data/hora forem iguais. Recomendado apenas para sistemas rápidos (resolução de dois segundos ou menos). |
| **/C** | Suprime a saída padrão, incluindo erros ou avisos NMAKE não fatais, carimbos de data/hora e mensagem de direitos autorais do NMAKE. Suprime avisos emitidos por **/k**. |
| **/D** | Exibe os carimbos de data/hora de cada destino avaliado e dependente e uma mensagem quando um destino não existe. Útil com **/p** para depurar um makefile. Use `!CMDSWITCHES` para definir ou limpar **/d** para parte de um makefile. |
| **/E** | Faz com que as variáveis de ambiente substituam as definições de macro do makefile. |
| **/Errorreport** [ **nenhum** &#124; **solicitar** &#124; **fila** &#124; **Enviar** ] | Preterido. Relatórios [de controle de configurações do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) . |
| **/F** *nome do arquivo* | Especifica o *nome de arquivo* como um makefile. Espaços ou tabulações podem preceder *nome de arquivo*. Especifique **/f** uma vez para cada makefile. Para fornecer um makefile da entrada padrão, especifique um traço ( `-` ) para o *nome do arquivo*e a entrada do teclado final com **F6** ou **Ctrl + Z**. |
| **/G** | Exibe os makefiles incluídos com a `!INCLUDE` diretiva. Para obter mais informações, consulte [diretivas de pré-processamento do makefile](makefile-preprocessing-directives.md). |
| **/Help**, **/?** | Exibe um breve resumo da sintaxe de linha de comando NMAKE. |
| **/I** | Ignora os códigos de saída de todos os comandos. Para definir ou limpar **/i** para parte de um makefile, use `!CMDSWITCHES` . Para ignorar os códigos de saída de parte de um makefile, use um `-` modificador de comando Dash () ou [`.IGNORE`](dot-directives.md) . Substitui **/k** se ambos forem especificados. |
| **/K** | Continuará Criando dependências não relacionadas, se um comando retornar um erro. Também emite um aviso e retorna um código de saída de 1. Por padrão, NMAKE será interrompido se qualquer comando retornar um código de saída diferente de zero. Os avisos de **/k** são suprimidos por **/c**; **/I** substitui **/k** se ambos forem especificados. |
| **Opção** | Exibe, mas não executa comandos; comandos de pré-processamento são executados. Não exibe comandos em chamadas NMAKE recursivas. Útil para depurar makefiles e verificar carimbos de data/hora. Para definir ou limpar **/n** para parte de um makefile, use `!CMDSWITCHES` . |
| **/NOLOGO** | Suprime a mensagem de direitos autorais NMAKE. |
| **/P** | Exibe informações (definições de macro, regras de inferência, destinos, [`.SUFFIXES`](dot-directives.md) lista) para a saída padrão e, em seguida, executa a compilação. Se não existir nenhum destino de linha de comando ou Makefile, ele exibirá apenas informações. Use with **/d** para depurar um makefile. |
| **/Q** | Verifica os carimbos de data/hora dos destinos; não executa a compilação. Retornará um código de saída zero se todos os destinos estiverem atualizados e um código de saída diferente de zero se qualquer destino estiver desatualizado. Comandos de pré-processamento são executados. Útil ao executar NMAKE de um arquivo em lotes. |
| **/R** | Limpa a `.SUFFIXES` lista e ignora as regras de inferência e as macros definidas no arquivo Tools.ini ou que são predefinidas. |
| **/S** | Suprime a exibição de comandos executados. Para suprimir a exibição em parte de um makefile, use o **\@** modificador de comando ou [`.SILENT`](dot-directives.md) . Para definir ou limpar **/s** para parte de um makefile, use `!CMDSWITCHES` . |
| **/T** | Atualiza os carimbos de data/hora dos destinos de linha de comando (ou primeiro destino de makefile) e executa comandos de pré-processamento, mas não executa a compilação. |
| **/U** | Deve ser usado em conjunto com **/n**. Despeja arquivos NMAKE embutidos para que a saída **/n** possa ser usada como um arquivo em lotes. |
| **/X** *Nome do arquivo* /x | Envia a saída de erro NMAKE para *filename* em vez de erro padrão. Espaços ou tabulações podem preceder *nome de arquivo*. Para enviar a saída de erro para a saída padrão, especifique um traço ( `-` ) para *nome de arquivo*. Não afeta a saída de comandos para erro padrão. |
| **/Y** | Desabilita as regras de inferência em modo de lote. Quando essa opção é selecionada, todas as regras de inferência em modo de lote são tratadas como regras de inferência regular. |

## <a name="toolsini-and-nmake"></a>Tools.ini e NMAKE

NMAKE lê Tools.ini antes de ler os makefiles, a menos que **/r** seja usado. Ele procura Tools.ini primeiro no diretório atual e, em seguida, no diretório especificado pela variável de ambiente INIT. A seção para configurações de NMAKE no arquivo de inicialização começa com `[NMAKE]` e pode conter qualquer informação de makefile. Especifique um comentário em uma linha separada que comece com um sinal numérico ( `#` ).

## <a name="exit-codes-from-nmake"></a>Códigos de saída de NMAKE

NMAKE retorna os seguintes códigos de saída:

| Código | Significado |
| ---------- | ------------- |
| 0 | Nenhum erro (possivelmente um aviso) |
| 1 | Compilação incompleta (emitida somente quando **/k** é usado) |
| 2 | Erro do programa, possivelmente causado por um destes problemas:<br /> -Um erro de sintaxe no Makefile<br /> -Um erro ou código de saída de um comando<br /> -Uma interrupção pelo usuário |
| 4 | Erro do sistema – memória insuficiente |
| 255 | O destino não está atualizado (emitido somente quando **/q** é usado) |

## <a name="see-also"></a>Confira também

[Referência de NMAKE](nmake-reference.md)
