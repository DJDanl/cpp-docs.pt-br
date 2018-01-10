---
title: "Referência BSCMAKE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- BSCMAKE, reference
- Microsoft Browse Information Maintenance Utility
- browse windows
- browse information files (.bsc), building
- .bsc files, building
- bsc files, building
- BSCMAKE
ms.assetid: b97ad994-1355-4809-98db-6abc12c6fb13
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0eeae72c2e7b3924c184f0e40e209986ad378809
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bscmake-reference"></a>Referência de BSCMAKE
> [!WARNING]
> Embora BSCMAKE ainda está instalado com o Visual Studio, ele não é usado pelo IDE. Desde o Visual Studio 2008, as informações de procura e símbolo são armazenadas automaticamente em um arquivo. sdf de SQL Server na pasta da solução.  
  
 O utilitário de manutenção de informações de procura da Microsoft (BSCMAKE. EXE) cria um arquivo de informações de procura (. bsc) de arquivos. SBR criados durante a compilação. Determinadas ferramentas de terceiros usam arquivos. BSC para análise de código. 
  
 Quando você compila seu programa, você pode criar um arquivo de informações de procura para seu programa automaticamente, usando BSCMAKE para compilar o arquivo. Você não precisa saber como executar BSCMAKE se você criar o arquivo de informações de procura no ambiente de desenvolvimento do Visual C++. No entanto, você talvez queira ler este tópico para entender as opções disponíveis.  
  
 Se você criar seu programa fora do ambiente de desenvolvimento, você ainda pode criar um. bsc personalizado que você pode examinar no ambiente. Execute BSCMAKE nos arquivos. SBR criada durante a compilação.  
  
> [!NOTE]
>  Você pode iniciar essa ferramenta apenas do prompt de comando do Visual Studio Developer. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.  
  
 Esta seção inclui os seguintes tópicos:  
  
-   [Compilando arquivos de informações de navegação: visão geral](../../build/reference/building-browse-information-files-overview.md)  
  
-   [Criando um arquivo. bsc](../../build/reference/building-a-dot-bsc-file.md)  
  
-   [Linha de comando BSCMAKE](../../build/reference/bscmake-command-line.md)  
  
-   [Arquivo de comando BSCMAKE](../../build/reference/bscmake-command-file-response-file.md)  
  
-   [Opções de BSCMAKE](../../build/reference/bscmake-options.md)  
  
-   [Códigos de saída BSCMAKE](../../build/reference/bscmake-exit-codes.md)  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)