---
title: "Componentes de usuário de automação remota | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- DLLs [MFC], Automation
- Remote Automation [MFC], user components
ms.assetid: 601591cc-a442-440a-988e-baf3284b0d46
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3fa97dff482226c7a9e6554a0479eb76b25c47f1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="remote-automation-user-components"></a>Componentes do usuário de automação remota
Você precisará garantir que cada computador cliente contém o programa cliente e qualquer suporte DLLs que ele exige. Você também precisará garantir que o aplicativo de servidor e qualquer suporte DLLs requer estejam presentes no computador servidor. Por fim, você precisará garantir que o programa de servidor está registrado em cada computador cliente antes de Gerenciador de RAC pode ser executado para configurar a conexão. Se o programa é registro automático (como a maioria será), você só precisa executar o programa de servidor no computador cliente para registrá-lo. Caso de falha, você terá que executar um arquivo de registro que você fornecer, ou editar manualmente o registro.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciador de automação (MFC)](../mfc/automation-manager-mfc.md)   
 [Gerenciador de Conexão de automação remota](../mfc/remote-automation-connection-manager.md)   
 [Instalação de automação remota](../mfc/remote-automation-installation.md)

