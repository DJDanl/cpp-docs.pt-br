---
title: "Gerenciador de automa&#231;&#227;o (MFC) | Microsoft Docs"
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
  - "AUTMGR32.exe"
  - "Clientes de automação, Gerenciador de Automação"
  - "Gerenciador de Automação"
  - "Servidores de automação, Gerenciador de Automação"
  - "Automação, Gerenciador de Automação"
  - "Automação remota, Gerenciador de Automação"
ms.assetid: 6bf3429e-1946-41c5-86d0-ad7f5b8585b8
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciador de automa&#231;&#227;o (MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

AUTMGR32.EXE deve ser copiado para o diretório do sistema windows de cada computador que esteja pretendendo fornecer objetos remotos de automação.  Para o Windows 95 e Windows 98, esse diretório é normalmente C:\\WINDOWS\\SYSTEM.  Para o Windows NT e o Windows 2000, normalmente é C:\\WINNT\\SYSTEM32.  
  
 Se você deseja habilitar retornos de chamada do servidor para o cliente, esse arquivo executável também deve ser copiado para o diretório do sistema de cada computador cliente.  
  
 Quando o gerenciador de automação está em execução, exibe uma janela pequena no computador do servidor que contém a breve informações de status.  Se você desejar ocultar o, consulte o artigo Q138067 na Base de Dados de Conhecimento Microsoft.  
  
## Consulte também  
 [Gerenciador de conexões de automação remota](../mfc/remote-automation-connection-manager.md)   
 [Componentes do usuário de automação remota](../mfc/remote-automation-user-components.md)   
 [Instalação de automação remota](../Topic/Remote%20Automation%20Installation.md)