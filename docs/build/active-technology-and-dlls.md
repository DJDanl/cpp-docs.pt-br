---
title: "Tecnologia ativa e DLLs | Microsoft Docs"
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
  - "Tecnologia ativa [C++]"
  - "Automação [C++], DLLs"
  - "DLLs [C++], Tecnologia ativa"
  - "DLLs de servidor no processo"
  - "DLLs MFC [C++], Tecnologia ativa"
ms.assetid: 3ed27f8d-164a-4562-ad61-9f2333404cc7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tecnologia ativa e DLLs
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tecnologia ativa permite que os servidores de objeto são implementados completamente dentro de uma DLL.  Este tipo de servidor é chamado um servidor em processo.  MFC O não oferece suporte a servidores em processo para todos os recursos de edição visual, especialmente como a tecnologia ativa não fornece uma maneira para um servidor para o gancho no loop principal da mensagem do contêiner.  MFC O requer acesso ao loop da mensagem de aplicativo de contêiner para as teclas de aceleração de identificador e o processamento de tempo ocioso.  
  
 Se você estiver escrevendo um servidor de automação e seu servidor não tem nenhuma interface do usuário, você pode fazer seu servidor a um servidor em processo e colocá\-lo completamente em uma DLL.  
  
## Que você deseja saber mais?  
  
-   [Servidores de automação](../mfc/automation-servers.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)