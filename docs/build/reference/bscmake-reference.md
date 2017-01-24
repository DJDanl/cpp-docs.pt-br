---
title: "Refer&#234;ncia de BSCMAKE | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .bsc, compilando"
  - "arquivos de informações de pesquisa (.bsc), compilando"
  - "janelas de procura"
  - "arquivos bsc, compilando"
  - "BSCMAKE"
  - "BSCMAKE, referência"
  - "Utilitário de Manutenção de Informações de Procura da Microsoft"
ms.assetid: b97ad994-1355-4809-98db-6abc12c6fb13
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Refer&#234;ncia de BSCMAKE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

> [!WARNING]
>  Embora BSCMAKE ainda está instalado com o Visual Studio, ele não é usado pelo IDE.  Desde o Visual Studio 2008, as informações de procura e símbolo são armazenadas automaticamente em um arquivo sdf do SQL Server na pasta da solução.  
  
 O utilitário de manutenção de informações de procura da Microsoft \(BSCMAKE. EXE\) cria um arquivo de informações de procura \(. bsc\) de arquivos. SBR criados durante a compilação.  Você pode exibir um arquivo de informações de procura no Pesquisador de objetos.  Para obter informações sobre o Pesquisador de objetos, consulte [navegando no Pesquisador de objetos](http://msdn.microsoft.com/pt-br/53eb91aa-08c6-4299-8e3c-a877ae8d0c55).  
  
 Quando você compila seu programa, você pode criar um arquivo de informações de navegação para o seu programa automaticamente, usando BSCMAKE para criar o arquivo.  Você não precisa saber como executar BSCMAKE se você criar o arquivo de informações de procura no ambiente de desenvolvimento do Visual C\+\+.  No entanto, você talvez queira ler este tópico para entender as opções disponíveis.  
  
 Se você compilar seu programa fora do ambiente de desenvolvimento, você ainda pode criar um BSC personalizado que você pode examinar no ambiente.  Execute BSCMAKE nos arquivos. SBR criada durante a compilação.  
  
> [!NOTE]
>  Você pode iniciar essa ferramenta somente a partir de [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] prompt de comando.  Você não pode iniciá\-lo em um prompt de comando do sistema ou no Explorador de arquivos.  
  
 Esta seção inclui os seguintes tópicos:  
  
-   [Compilando arquivos de informações de navegação: visão geral](../../build/reference/building-browse-information-files-overview.md)  
  
-   [Criando um arquivo. bsc](../../build/reference/building-a-dot-bsc-file.md)  
  
-   [Linha de comando BSCMAKE](../../build/reference/bscmake-command-line.md)  
  
-   [Arquivo de comando BSCMAKE](../../build/reference/bscmake-command-file-response-file.md)  
  
-   [Opções de BSCMAKE](../Topic/BSCMAKE%20Options.md)  
  
-   [Códigos de saída BSCMAKE](../Topic/BSCMAKE%20Exit%20Codes.md)  
  
## Consulte também  
 [Ferramentas de compilação do C\/C\+\+](../Topic/C-C++%20Build%20Tools.md)