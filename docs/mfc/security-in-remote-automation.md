---
title: "Segurança em automação remota | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- AllowRemoteActivation [MFC]
- Remote Automation [MFC], security
- activating objects [MFC]
- security [MFC]
- Automation objects [MFC], security options
- object activation [MFC]
- security [MFC], Remote Automation
ms.assetid: 276b300d-c0b5-4bd8-8bf5-0270994b9cfa
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e535fac6330d6268629e8e3681fec47c7b0d65d3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="security-in-remote-automation"></a>Segurança em automação remota
Automação remota oferece suporte a um nível básico de segurança para permitir que um gravador de aplicativos de servidor (ou, em vez disso, seu administrador) especificar como um objeto específico pode ser ativado remotamente. Todos os objetos de automação em um determinado sistema podem ser definidos globalmente para "não permitir a ativação remota" ou "permitir a ativação remota". Além disso e com mais frequência, objetos individuais podem receber esses recursos. Automação remota usa uma chave em configurações de registro de cada objeto, **AllowRemoteActivation**, para determinar se um determinado servidor pode ser ativado remotamente. Se as configurações de todo o sistema usam este modo, cada objeto no registro pode ser atribuído essa chave, e o status individual de cada um deles pode ser definido como "Sim" ou "não" conforme apropriado.  
  
 Se o sistema de servidor estiver executando o Windows NT ou Windows 2000, é permitida uma forma alternativa de segurança. Nesse caso, a automação remota usa a lista de controle de acesso (ACL) NT para especificar quais usuários ou grupo ou grupos de usuários podem ativar um determinado servidor remotamente.  
  
 Observe que as opções de segurança se aplicam a todo o objeto; não é possível definir atributos de uma interface específica, ou de métodos ou propriedades individuais nesse objeto.  
  
 Todas as opções de segurança podem ser definidas por meio do Gerenciador de Conexão de automação remota (RAC).  
  
## <a name="see-also"></a>Consulte também  
 [Automação remota](../mfc/remote-automation.md)

