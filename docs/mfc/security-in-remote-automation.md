---
title: "Seguran&#231;a em automa&#231;&#227;o remota | Microsoft Docs"
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
  - "ativando objetos"
  - "AllowRemoteActivation"
  - "Objetos Automation, opções de segurança"
  - "ativação de objeto"
  - "Automação remota, segurança"
  - "segurança [MFC]"
  - "segurança [MFC], Automação remota"
ms.assetid: 276b300d-c0b5-4bd8-8bf5-0270994b9cfa
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Seguran&#231;a em automa&#231;&#227;o remota
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A automação remoto oferece suporte a um nível de segurança básico para permitir que um gravador do aplicativo de servidor \(ou, em vez disso, o administrador\) especifique como um objeto específico pode ser ativado remotamente.  Todos os objetos de automação em um sistema global determinado podem ser definidos “desautoriza a ativação remota” ou “permitir a ativação remota.”  Além disso, e mais frequentemente, os objetos individuais podem ser dados tais recursos.  A automação remoto usa uma chave em configurações do Registro de cada objeto, **AllowRemoteActivation**, para determinar se um determinado servidor pode ser ativado remotamente.  Se pelo sistema as configurações usam esse modo, cada objeto no Registro pode ser atribuído a esta chave, e o status individuais de cada um deless pode ser definido como “yes” ou “não” conforme apropriado.  
  
 Se o sistema do servidor está executando o Windows NT ou Windows 2000, então uma forma alternativa de segurança é permitido.  Nesse caso, a automação remoto utiliza a lista de controle de acesso \(ACL\) do NT para especificar que os usuários ou grupo ou grupos de usuários podem remotamente ativar um determinado servidor.  
  
 Observe que as opções de segurança se aplicam ao objeto inteiro; não é possível definir atributos de uma interface específica, ou de propriedades individuais ou de métodos desse objeto.  
  
 Todas as opções de segurança podem ser definidas por meio do gerenciador remoto de \(RAC\) de conexão de automação.  
  
## Consulte também  
 [Automação remota](../mfc/remote-automation.md)