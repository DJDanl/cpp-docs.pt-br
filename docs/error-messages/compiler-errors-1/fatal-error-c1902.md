---
title: Erro fatal C1902
ms.date: 11/04/2016
f1_keywords:
- C1902
helpviewer_keywords:
- C1902
ms.assetid: 2dc066cc-fcb1-4725-8bcb-9f44dd0905b7
ms.openlocfilehash: 10a411dfc942498a98959d9a23cb42dfb93cf2ae
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202820"
---
# <a name="fatal-error-c1902"></a>Erro fatal C1902

incompatibilidade do Gerenciador de banco de dados do programa; Verifique sua instalação

Um arquivo de banco de dados do programa (. pdb) foi criado usando uma versão mais recente do mspdb*xxx*. dll do que aquele que o compilador encontrou no seu sistema. Esse erro geralmente indica que MSPDBSRV. exe ou mspdbcore. dll estão ausentes ou têm versões diferentes do mspdb*xxx*. dll. (O espaço reservado *xxx* no nome do arquivo mspdb*xxx*. dll é alterado com cada versão do produto. Por exemplo, no Visual Studio 2015, o nome do arquivo é mspdb140. dll.)

Verifique se as versões correspondentes do MSPDBSRV. exe, mspdbcore. dll e mspdb*xxx*. dll estão instaladas no sistema. Verifique se as versões incompatíveis não foram copiadas para o diretório que contém o compilador e as ferramentas de link para a plataforma de destino. Por exemplo, você pode ter copiado os arquivos para que possa invocar o compilador ou a ferramenta de link do prompt de comando sem definir a variável de ambiente **path** de forma adequada.
