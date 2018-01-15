---
title: "O Gerenciador de Conexão de automação remota | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Automation clients [MFC], configuring for Remote Automation
- registry [MFC], remote Automation
- Automation servers [MFC], configuring for Remote Automation
- Remote Automation Connection Manager [MFC]
- Remote Automation [MFC], configuring client and server machines
- RAC Manager tool [MFC]
ms.assetid: 562eb7bc-f95c-46ad-ac97-f0dfa98362af
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cf316653b2f968fd5373c6265bb4f3f3ef3b0ba4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="remote-automation-connection-manager"></a>Gerenciador de conexões de automação remota
Para configurar computadores cliente e servidor, você precisa fazer alterações no registro. Em vez de fazer isso manualmente, é muito mais fácil de usar a ferramenta Gerenciador de Conexão de automação remota (RAC). Essa ferramenta, RACMGR32. EXE, juntamente com RACREG32. DLL, precisam ser copiados para qualquer diretório que você escolher. Colocando-o no caminho, ele pode ser executado na barra de tarefas usando a execução. Como alternativa, você pode criar um atalho para ele ou colocar uma referência a ele no menu Iniciar.  
  
 RACMGR32 é escrito em Visual Basic e, portanto, precisa de alguns Visual Basic oferecem suporte a DLLs. Esses arquivos são colocados no mesmo diretório que RACMGR32. EXE do CD-ROM. As versões desses arquivos que são instalados pela instalação do Visual C++ Enterprise Edition são mais recentes do que aqueles que acompanha o Visual Basic Enterprise Edition 5.0 ou equivalente. A instalação do Visual C++ copia as novas versões de arquivos do Visual Basic para o diretório do sistema. Para Windows 9x, esse diretório é geralmente C:\Windows\System. Para Windows NT e o Windows 2000, é geralmente C:\WINNT\system32. A instalação também registra esses arquivos com o sistema operacional. Você pode removê-los de sua instalação do Visual Basic.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciador de automação (MFC)](../mfc/automation-manager-mfc.md)   
 [Componentes de usuário de automação remota](../mfc/remote-automation-user-components.md)   
 [Instalação de automação remota](../mfc/remote-automation-installation.md)

