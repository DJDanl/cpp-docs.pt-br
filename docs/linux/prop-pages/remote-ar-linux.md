---
title: Propriedades de arquivo remoto (C++ Linux)
ms.date: 06/07/2019
ms.assetid: 5ee1e44c-8337-4c3a-b2f3-35e4be954f9f
f1_keywords: []
ms.openlocfilehash: 9e35c9cc0b8a99e87654f1052e8666c52e35a071
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924453"
---
# <a name="remote-archive-properties-c-linux"></a>Propriedades de arquivo remoto (C++ Linux)

::: moniker range="msvc-140"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=msvc-150"

| Propriedade | Descrição |
|--|--|
| Criar um índice de arquivo morto | Crie um índice de arquivo morto (conforme realizado pelo ranlib). Essa opção pode acelerar a vinculação e reduzir a dependência em sua própria biblioteca. |
| Criar Arquivo Morto Fino | Crie um arquivo morto fino.  Um arquivo morto fino contém caminhos relativos para os objetos, em vez de inserir os objetos.  Alternar entre Fino e Normal requer excluir a biblioteca existente. |
| Nenhum Aviso ao Criar | Não avisar se ou quando a biblioteca foi criada. |
| Truncar o Carimbo de Data/Hora | Use zero para os carimbos de data/hora e uids/gids. |
| Suprimir Faixa de Inicialização | Não mostra o número de versão. |
| Detalhado | Detalhado |
| Opções adicionais | Opções adicionais. |
| Arquivo de saída | A opção /OUT sobrescreve o nome e o local padrão do programa que a biblioteca cria. |
| Arquivador | Especifica o programa a ser invocado durante a vinculação de objetos estáticos ou o caminho para o arquivador no sistema remoto. |
| Tempo Limite do Arquivador | Tempo limite do arquivador remoto, em milissegundos. |
| Saída da Cópia | Especifica se é necessário copiar o arquivo de saída de build do sistema remoto para o computador local. |

::: moniker-end
