---
title: Propriedades de arquivo remoto (C++ Linux) | Microsoft Docs
ms.custom: 
ms.date: 9/26/2017
ms.reviewer: 
ms.suite: 
ms.technology: vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 5ee1e44c-8337-4c3a-b2f3-35e4be954f9f
author: mikeblome
ms.author: mblome
manager: ghogen
f1_keywords:
- VC.Project.Ar.CreateIndex
- VC.Project.Ar.CreateThinArchive
- VC.Project.Ar.NoWarnOnCreate
- VC.Project.Ar.TruncateTimestamp
- VC.Project.Ar.SuppressStartupBanner
- VC.Project.Ar.Verbose
- vc.project.AdditionalOptionsPage
- VC.Project.Ar.OutputFile
- VC.Project.VCConfiguration.BuildLogFile
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: 83b69c8aea824f08f3db6aa5f5b7bf01cacb339e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="remote-archive-properties-c-linux"></a>Propriedades de arquivo remoto (C++ Linux)

propriedade | Descrição
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
