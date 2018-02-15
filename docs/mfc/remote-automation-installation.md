---
title: "Instalação de automação remota | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Remote Automation [MFC], installation
- installing Remote Automation [MFC]
ms.assetid: 9a02c9f6-dfc6-4489-b240-a1afe25fa0c5
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: acd8ee55261dfa03c68aef506dc90188d8d27d37
ms.sourcegitcommit: fa7a6dccddce3747389c91277a53e296f905305c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="remote-automation-installation"></a>Instalação de automação remota
Automação remota tem componentes relativamente poucas:  
  
-   O proxy de cliente automação remota, AUTPRX32. DLL.  
  
-   O automação remota componente do servidor, o Gerenciador de automação, AUTMGR32. EXE.  
  
-   O Gerenciador de RAC, RACMGR32. EXE, com seu RACREG32 correspondente. DLL.  
  
 Desses, Gerenciador de RAC é escrito em Visual Basic e, portanto, precisa de tempo de execução do Visual Basic oferecem suporte. Esses e outros arquivos de automação remota são instalados pela instalação quando você instala o Visual C++ Enterprise Edition.  
  
 Se você copiar os componentes de automação remota em um computador no qual versão do Visual C++, Enterprise Edition não está instalado, certifique-se de que Regsvr32. EXE está no caminho do computador e registrar RACREG32. DLL usando a seguinte linha de comando:  
  
 REGSRVR32 RACREG32.DLL  
  
> [!NOTE]
>  As versões do Gerenciador de RAC antes de Visual C++ 5.0 necessário GUAGE32. OCX e TABCTL32. OCX. Nenhum deles é necessário para a versão do Gerenciador de RAC fornecido com o Visual C++ Enterprise Edition, versão 5.0 ou posterior.  
  
## <a name="in-this-section"></a>Nesta seção  
 [O Gerenciador de automação](../mfc/automation-manager-mfc.md)  
  
 [O Gerenciador de Conexão de automação remota](../mfc/remote-automation-connection-manager.md)  
  
 [Componentes do usuário de automação remota](../mfc/remote-automation-user-components.md)  
  
## <a name="see-also"></a>Consulte também  
 [Automação remota](../mfc/remote-automation.md)

