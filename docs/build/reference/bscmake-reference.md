---
title: Referência de BSCMAKE
ms.date: 05/06/2019
helpviewer_keywords:
- BSCMAKE, reference
- Microsoft Browse Information Maintenance Utility
- browse windows
- browse information files (.bsc), building
- .bsc files, building
- bsc files, building
- BSCMAKE
ms.assetid: b97ad994-1355-4809-98db-6abc12c6fb13
ms.openlocfilehash: f95e34b9599de628463b9f92ebf8f01036237891
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320736"
---
# <a name="bscmake-reference"></a>Referência de BSCMAKE

> [!WARNING]
> Embora o BSCMAKE ainda esteja instalado no Visual Studio, ele não é mais usado pelo IDE. Desde o Visual Studio 2008, as informações de navegação e símbolo são armazenadas automaticamente em um arquivo SQL Server .sdf na pasta de solução.

O utilitário de manutenção de informações do Microsoft Browse (BSCMAKE. EXE) constrói um arquivo de informações de navegação (.bsc) a partir de arquivos .sbr criados durante a compilação. Certas ferramentas de terceiros usam arquivos .bsc para análise de código.

Ao criar seu programa, você pode criar um arquivo de informações de navegação para o seu programa automaticamente, usando o BSCMAKE para construir o arquivo. Você não precisa saber como executar o BSCMAKE se você criar seu arquivo de informações de navegação no ambiente de desenvolvimento do Visual Studio. No entanto, você pode querer ler este tópico para entender as opções disponíveis.

Se você construir seu programa fora do ambiente de desenvolvimento, você ainda pode criar um .bsc personalizado que você pode examinar no ambiente. Execute BSCMAKE nos arquivos .sbr que você criou durante a compilação.

> [!NOTE]
> Você só pode iniciar esta ferramenta a partir do prompt de comando Visual Studio Developer. Não é possível iniciá-lo a partir de um prompt de comando do sistema ou do Explorador de Arquivos.

Esta seção inclui os tópicos a seguir:

- [Compilando arquivos de informações de navegação: visão geral](building-browse-information-files-overview.md)

- [Construção de um arquivo .bsc](building-a-dot-bsc-file.md)

- [Linha de comando BSCMAKE](bscmake-command-line.md)

- [Arquivo de comando BSCMAKE](bscmake-command-file-response-file.md)

- [Opções bscmake](bscmake-options.md)

- [Códigos de saída BSCMAKE](bscmake-exit-codes.md)

## <a name="see-also"></a>Confira também

[Ferramentas adicionais de construção de MSVC](c-cpp-build-tools.md)
