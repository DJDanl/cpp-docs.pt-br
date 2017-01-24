---
title: "Fun&#231;&#245;es de seguran&#231;a globais | Microsoft Docs"
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
  - "Funções globais do objeto ACL"
  - "IDs de segurança [C++]"
  - "SIDs [C++], objetos de SID"
ms.assetid: 6a584bfe-16b7-47f4-8439-9c789c41567a
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es de seguran&#231;a globais
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essas funções oferecem suporte para modificar objetos de SID e ACL.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlGetDacl](../Topic/AtlGetDacl.md)|Chamar essa função para recuperar informações de \(DACL\) da lista de controle de acesso discricionário de um objeto especificado.|  
|[AtlSetDacl](../Topic/AtlSetDacl.md)|Chamar essa função para definir informações de \(DACL\) da lista de controle de acesso discricionário de um objeto especificado.|  
|[AtlGetGroupSid](../Topic/AtlGetGroupSid.md)|Chamar essa função para obter o identificador de segurança \(SID\) do grupo de um objeto.|  
|[AtlSetGroupSid](../Topic/AtlSetGroupSid.md)|Chamar essa função para definir o identificador de segurança \(SID\) do grupo de um objeto.|  
|[AtlGetOwnerSid](../Topic/AtlGetOwnerSid.md)|Chamar essa função para obter o identificador de segurança \(SID\) do proprietário de um objeto.|  
|[AtlSetOwnerSid](../Topic/AtlSetOwnerSid.md)|Chamar essa função para definir o identificador de segurança \(SID\) do proprietário de um objeto.|  
|[AtlGetSacl](../Topic/AtlGetSacl.md)|Chamar essa função para recuperar informações de \(SACL\) da lista de controle de acesso do sistema de um objeto especificado.|  
|[AtlSetSacl](../Topic/AtlSetSacl.md)|Chamar essa função para definir informações de \(SACL\) da lista de controle de acesso do sistema de um objeto especificado.|  
|[AtlGetSecurityDescriptor](../Topic/AtlGetSecurityDescriptor.md)|Chamar essa função para recuperar o descritor de segurança de um determinado objeto.|  
  
## Consulte também  
 [Funções](../../atl/reference/atl-functions.md)