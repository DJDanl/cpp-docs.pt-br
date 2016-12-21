---
title: "Componentes do usu&#225;rio de automa&#231;&#227;o remota | Microsoft Docs"
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
  - "DLLs [C++], Automação"
  - "Automação Remota [C++], componentes de usuário"
ms.assetid: 601591cc-a442-440a-988e-baf3284b0d46
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Componentes do usu&#225;rio de automa&#231;&#227;o remota
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você precisará garantir que cada máquina cliente contém seu programa cliente e todas as dlls de suporte necessária.  Você também precisará garantir que o aplicativo servidor e todas as dlls de suporte exigir presentes no computador do servidor.  Finalmente, você precisará garantir que seu programa de servidor está registrado em cada computador cliente antes que o gerenciador de RAC pode ser executado para configurar a conexão.  Se o programa do está registrando \(como a maioria é\), você só precisa executar o programa do servidor no computador cliente para fazer.  Falhando isso, você poderá ter que executar um arquivo de registro que você fornece, ou editar manualmente o Registro.  
  
## Consulte também  
 [Gerenciador de automação \(MFC\)](../mfc/automation-manager-mfc.md)   
 [Gerenciador de conexões de automação remota](../mfc/remote-automation-connection-manager.md)   
 [Instalação de automação remota](../Topic/Remote%20Automation%20Installation.md)