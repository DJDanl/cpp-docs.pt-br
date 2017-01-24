---
title: "Registro e fun&#231;&#245;es globais de TypeLib | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função de RegistryDataExchange, funções globais"
ms.assetid: d58b8a4e-975c-4417-8b34-d3c847f679b3
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registro e fun&#231;&#245;es globais de TypeLib
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essas funções oferecem suporte para carregar e registrar uma biblioteca de tipo.  
  
> [!IMPORTANT]
>  As funções listadas nas tabelas não podem ser usadas em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlRegisterTypeLib](../Topic/AtlRegisterTypeLib.md)|Essa função é chamada para registrar uma biblioteca de tipo.|  
|[AtlUnRegisterTypeLib](../Topic/AtlUnRegisterTypeLib.md)|Essa função é chamada ao unregister uma biblioteca de tipo|  
|[AtlLoadTypeLib](../Topic/AtlLoadTypeLib.md)|Essa função é chamada para carregar uma biblioteca de tipo.|  
|[AtlUpdateRegistryFromResourceD](../Topic/AtlUpdateRegistryFromResourceD.md)|Essa função é chamada para atualizar o Registro de recurso fornecido.|  
|[RegistryDataExchange](../Topic/RegistryDataExchange.md)|Essa função é chamada de, para ler ou gravar em, o Registro do sistema.  Chamado por [Macros troca de dados do Registro](../../atl/reference/registry-data-exchange-macros.md).|  
  
 Controle de essas funções que o nó no Registro o programa usa para armazenar informações.  
  
|||  
|-|-|  
|[AtlGetPerUserRegistration](../Topic/AtlGetPerUserRegistration.md)|Retorna se o aplicativo redireciona o acesso ao Registro para o nó de **HKEY\_CURRENT\_USER** \(**HKCU**\).|  
|[AtlSetPerUserRegistration](../Topic/AtlSetPerUserRegistration.md)|Define se o aplicativo redireciona o acesso ao Registro para o nó **HKEY\_CURRENT\_USER** \(**HKCU**\).|  
  
## Consulte também  
 [Funções](../../atl/reference/atl-functions.md)