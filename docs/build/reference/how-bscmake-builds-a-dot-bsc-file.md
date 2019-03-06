---
title: Como BSCMAKE compila um arquivo .Bsc
ms.date: 11/04/2016
helpviewer_keywords:
- browse information files (.bsc), building
ms.assetid: 8512b33e-c856-44a2-87bd-01ab10b52a95
ms.openlocfilehash: e691e6ee2dcda0fb04735705078f1ed2ff139301
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57425582"
---
# <a name="how-bscmake-builds-a-bsc-file"></a>Como BSCMAKE compila um arquivo .Bsc

BSCMAKE compila ou recompila um arquivo. bsc a maneira mais eficiente possível. Para evitar possíveis problemas, é importante entender o processo de compilação.

Quando o BSCMAKE compila um arquivo de informações de procura, ele trunca os arquivos. SBR para comprimento de zero. Durante um build posterior do mesmo arquivo, um arquivo. SBR de comprimento zero (ou vazio) informa ao BSCMAKE o arquivo. SBR não tem nenhuma contribuição de novo para fazer. Ele permite que o BSCMAKE que não é necessária uma atualização dessa parte do arquivo e uma compilação incremental será suficiente. Durante cada compilação (a menos que a opção /n for especificada), BSCMAKE primeiro tenta atualizar o arquivo de forma incremental, usando somente os arquivos. SBR foram alterados.

BSCMAKE procura um arquivo. bsc que tem o nome especificado com a opção /o. Se /o não for especificado, o BSCMAKE procurará um arquivo que tem o nome base do primeiro arquivo. SBR e uma extensão. bsc. Se o arquivo existir, BSCMAKE executa uma compilação incremental do arquivo de informações de procura usando somente os arquivos. SBR Colaborador. Se o arquivo não existir, BSCMAKE executa uma compilação completa, usando todos os arquivos. SBR. As regras para compilações são da seguinte maneira:

- Para uma compilação completa seja bem-sucedida, todos especificados de arquivos. SBR devem existir e não devem ser truncados. Se um arquivo. SBR está truncado, você deve recompilá-lo (por recompilar ou montar) antes de executar BSCMAKE.

- Para uma compilação incremental seja bem-sucedida, o arquivo. bsc deve existir. Todos os arquivos. SBR Colaborador, até mesmo arquivos vazios, deve existir e deve ser especificado na linha de comando BSCMAKE. Se você omitir um arquivo. SBR da linha de comando, BSCMAKE remove sua contribuição do arquivo.

## <a name="see-also"></a>Consulte também

[Compilando um arquivo .Bsc](../../build/reference/building-a-dot-bsc-file.md)
