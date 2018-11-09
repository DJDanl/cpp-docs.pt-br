---
title: Propriedades de arquivo remoto (C++ Linux)
ms.date: 9/26/2017
ms.assetid: 5ee1e44c-8337-4c3a-b2f3-35e4be954f9f
f1_keywords: []
ms.openlocfilehash: bcd0e0eef16addc60743000b6ed8cba12276e29c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50439215"
---
# <a name="remote-archive-properties-c-linux"></a>Propriedades de arquivo remoto (C++ Linux)

Propriedade | Descrição
--- | ---
Criar um índice de arquivo morto | Crie um índice de arquivo morto (cf. ranlib).  Isso pode acelerar a vinculação e reduzir a dependência em sua própria biblioteca.
Criar Arquivo Morto Fino | Crie um arquivo morto fino.  Um arquivo morto fino contém caminhos relativos para os objetos em vez de inseri-los.  Alternar entre Fino e Normal requer excluir a biblioteca existente.
Nenhum Aviso ao Criar | Não avisar se a biblioteca for criada.
Truncar o Carimbo de Data/Hora | Use zero para os carimbos de data/hora e uids/gids.
Suprimir Faixa de Inicialização | Não mostre o número de versão.
Detalhado | Detalhado
Opções Adicionais | Opções adicionais.
Arquivo de Saída | A opção /OUT sobrescreve o nome e o local padrão do programa que a biblioteca cria.
Arquivador | Especifica o programa a ser invocado durante a vinculação de objetos estáticos ou o caminho para o arquivador no sistema remoto.
Tempo Limite do Arquivador | Tempo limite do arquivador remoto, em milissegundos.
Saída da Cópia | Especifica se é necessário copiar o arquivo de saída de build do sistema remoto para o computador local.
