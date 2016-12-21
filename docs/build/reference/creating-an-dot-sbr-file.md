---
title: "Criando um arquivo .Sbr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Arquivos .sbr"
  - "BSCMAKE, arquivos de entrada"
  - "símbolos locais nas informações de procura"
  - "arquivos SBR"
  - "arquivos de navegador de origem"
  - "símbolos"
ms.assetid: bdb4b93c-a88a-441a-84fd-01087d03be25
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Criando um arquivo .Sbr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os arquivos de entrada para BSCMAKE são arquivos de .sbr.  O compilador cria um arquivo de .sbr para cada arquivo de objeto \(.obj\) que cria o.  Quando você cria ou atualiza o procurará o arquivo de informações do, todos os arquivos de .sbr para seu projeto devem estar disponíveis em disco.  
  
 Para criar um arquivo de .sbr com todas as informações possível, especifique [\/FR](../../build/reference/fr-fr-create-dot-sbr-file.md).  
  
 Para criar um .sbr arquivo que não contém símbolos locais, especifique [\/Fr](../../build/reference/fr-fr-create-dot-sbr-file.md).  Se os arquivos de .sbr contêm símbolos locais, você ainda pode omiti\-los do arquivo de .bsc usando [opção \/El](../Topic/BSCMAKE%20Options.md)`.`de BSCMAKE  
  
 Você pode criar um arquivo de .sbr sem executar um backup completo compila.  Por exemplo, você pode especificar a opção \/Zs ao compilador executar uma verificação de sintaxe e ainda gerar um arquivo de .sbr se você especificar \/FR ou \/Fr.  
  
 O processo de compilação pode ser mais eficiente se os arquivos de .sbr empacotados são principalmente para remover as definições não referenciada.  O compilador pacotes automaticamente arquivos de .sbr.  
  
## Consulte também  
 [Compilando um arquivo .Bsc](../../build/reference/building-a-dot-bsc-file.md)