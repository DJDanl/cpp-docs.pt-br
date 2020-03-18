---
title: Visão geral de LIB
description: Visão geral do uso e das opções da ferramenta de biblioteca, lib. exe.
ms.date: 02/09/2020
helpviewer_keywords:
- LIB [C++], modes
ms.assetid: e997d423-f574-434f-8b56-25585d137ee0
ms.openlocfilehash: 4ed725f383d956adf7abcf1c68002dee51703013
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439007"
---
# <a name="overview-of-lib"></a>Visão geral de LIB

LIB (lib. exe) cria bibliotecas padrão, importa bibliotecas e exporta arquivos que você pode usar com o [link](linker-options.md) ao criar um programa. LIB é executado a partir de um prompt de comando.

Você pode usar a LIB nos seguintes modos:

- [Criando ou modificando uma biblioteca COFF](managing-a-library.md)

- [Extraindo um objeto de membro para um arquivo](extracting-a-library-member.md)

- [Criando um arquivo de exportação e uma biblioteca de importação](working-with-import-libraries-and-export-files.md)

Esses modos são mutuamente exclusivos; Você pode usar a LIB em apenas um modo por vez.

## <a name="lib-options"></a>Opções de LIB

A tabela a seguir lista as opções de lib. exe, com um link para mais informações.

|{1&gt;Opção&lt;1}|Descrição|
|-|-|
|**/DEF**|Crie uma biblioteca de importação e um arquivo de exportação.<br/><br/>Para obter mais informações, consulte [criando uma biblioteca de importação e um arquivo de exportação](building-an-import-library-and-export-file.md).|
|**/ERRORREPORT**| Preterido. Para obter mais informações, consulte [Executando LIB](running-lib.md).|
|**/EXPORT**|   Exporta uma função do seu programa.<br/><br/>Para obter mais informações, consulte [criando uma biblioteca de importação e um arquivo de exportação](building-an-import-library-and-export-file.md).|
|**/EXTRACT**|   Crie um arquivo de objeto (. obj) que contenha uma cópia de um membro de uma biblioteca existente.<br/><br/>Para obter mais informações, consulte [extraindo um membro da biblioteca](extracting-a-library-member.md).|
|**/INCLUDE**|   Adiciona um símbolo à tabela de símbolos.<br/><br/>Para obter mais informações, consulte [criando uma biblioteca de importação e um arquivo de exportação](building-an-import-library-and-export-file.md).|
|**/LIBPATH**|   Substitui o caminho da biblioteca de ambiente.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](managing-a-library.md).|
|**/LINKREPRO**|   Cria artefatos necessários para reproduzir uma falha de lib. exe ou um erro interno.<br/><br/>Para obter mais informações, consulte [Executando LIB](running-lib.md).|
|**/LINKREPROTARGET**|   Gera apenas os artefatos **/LINKREPRO** quando lib. exe é usado com um arquivo especificado.<br/><br/>Para obter mais informações, consulte [Executando LIB](running-lib.md).|
|**/LIST**|   Exibe informações sobre a biblioteca de saída para a saída padrão.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](managing-a-library.md).|
|**/LTCG**|   Faz com que a biblioteca seja criada usando a geração de código de tempo de vinculação.<br/><br/>Para obter mais informações, consulte [Executando LIB](running-lib.md).|
|**/MACHINE**|   Especifica a plataforma de destino para o programa.<br/><br/>Para obter mais informações, consulte [Executando LIB](running-lib.md).|
|**/NAME**|   Ao criar uma biblioteca de importação, especifica o nome da DLL para a qual a biblioteca de importação está sendo compilada.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](managing-a-library.md).|
|**/NODEFAULTLIB**|   Remove uma ou mais bibliotecas padrão da lista de bibliotecas que pesquisa ao resolver referências externas.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](managing-a-library.md).|
|**/NOLOGO**|   Suprime a exibição da mensagem de direitos autorais de LIB e o número de versão e impede o eco de arquivos de comando.<br/><br/>Para obter mais informações, consulte [Executando LIB](running-lib.md).|
|**/OUT**|   Substitui o nome de arquivo de saída padrão.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](managing-a-library.md).|
|**/REMOVE**|   Omite um objeto da biblioteca de saída.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](managing-a-library.md).|
|**/SUBSYSTEM**|   Informa ao sistema operacional como executar um programa criado vinculando-se à biblioteca de saída.<br/><br/>Para obter mais informações, consulte [Gerenciando uma biblioteca](managing-a-library.md).|
|**/VERBOSE**|   Exibe detalhes sobre o progresso da sessão, incluindo nomes dos arquivos. obj que estão sendo adicionados.<br/><br/>Para obter mais informações, consulte [Executando LIB](running-lib.md).|
|**/WX**|   Tratar avisos como erros.<br/><br/>Para obter mais informações, consulte [Executando LIB](running-lib.md).|

## <a name="see-also"></a>Consulte também

\ de [referência lib](lib-reference.md)
\ de [arquivos de entrada lib](lib-input-files.md)
[Arquivos de saída LIB](lib-output-files.md)\
[Outra](other-lib-output.md)\ de saída de lib
[Estrutura de uma biblioteca](structure-of-a-library.md)
