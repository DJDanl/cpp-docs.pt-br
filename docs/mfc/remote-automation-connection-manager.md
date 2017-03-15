---
title: "Gerenciador de conex&#245;es de automa&#231;&#227;o remota | Microsoft Docs"
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
  - "Clientes de automação, configurando para Automação Remota"
  - "Servidores de automação, configurando para Automação Remota"
  - "Ferramenta Gerenciador de RAC"
  - "registro, Automação remota"
  - "Gerenciador de conexões de automação remota"
  - "Automação remota, configurando máquinas cliente e servidor"
ms.assetid: 562eb7bc-f95c-46ad-ac97-f0dfa98362af
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciador de conex&#245;es de automa&#231;&#227;o remota
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para configurar computadores cliente e de servidor, você precisa fazer alterações no Registro.  Em vez disso, fazendo a mão é muito mais fácil usar a ferramenta remoto do gerenciador de \(RAC\) de conexão de automação.  Essa ferramenta, RACMGR32.EXE, junto com RACREG32.DLL, precisa ser copiada para o diretório que você escolha.  PATH colocando o no, pode ser executado do usando a barra de tarefas executada.  Como alternativa, você pode criar\-lhe um atalho ou coloque uma referência a ele no menu Iniciar.  
  
 RACMGR32 é gravado no Visual Basic e precisa como consequência alguns DLL do suporte do Visual Basic.  Esses arquivos são colocados no mesmo diretório que RACMGR32.EXE em CD\-ROM.  As versões desses arquivos que são instalados pela instalação do Visual C\+\+ Enterprise Edition são equivalentes ou mais recentes do que aqueles fornecidos com o Visual Basic 5,0 Enterprise Edition.  A configuração do Visual C\+\+ copia as novas versões dos arquivos do Visual Basic no diretório do sistema.  Para o windows 9x, esse diretório é normalmente C:\\Windows\\System.  Para o Windows NT e o Windows 2000, normalmente é C:\\WINNT\\system32.  A instalação também registra esses arquivos no sistema operacional.  Você pode removê\-las da instalação do Visual Basic.  
  
## Consulte também  
 [Gerenciador de automação \(MFC\)](../mfc/automation-manager-mfc.md)   
 [Componentes do usuário de automação remota](../mfc/remote-automation-user-components.md)   
 [Instalação de automação remota](../Topic/Remote%20Automation%20Installation.md)