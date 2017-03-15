---
title: "Estrutura CreatorMap | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::Details::CreatorMap"
  - "implements/Microsoft::WRL::Details::CreatorMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CreatorMap"
ms.assetid: 94e40927-90c3-4107-bca3-3ad2dc4beda9
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CreatorMap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
struct CreatorMap;  
```  
  
## Comentários  
 Contém informações sobre como inicializar, registrar objetos, e o registro.  
  
 CreatorMap contém as seguintes informações:  
  
-   Como inicializar, se o, e objetos do registro.  
  
-   Como comparar dados de ativação segundo COM o ou uma fábrica clássica de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .  
  
-   Informações sobre o nome do cache e do servidor da fábrica para uma interface.  
  
## Membros  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados CreatorMap::activationId](../windows/creatormap-activationid-data-member.md)|Representa uma ID de objeto que é identificado por um ID clássica de classe COM ou por um nome de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .|  
|[Membro de dados CreatorMap::factoryCache](../windows/creatormap-factorycache-data-member.md)|Armazena o ponteiro para o cache de fábrica do CreatorMap.|  
|[Membro de dados CreatorMap::factoryCreator](../Topic/CreatorMap::factoryCreator%20Data%20Member.md)|Cria uma fábrica do CreatorMap especificado.|  
|[Membro de dados CreatorMap::serverName](../windows/creatormap-servername-data-member.md)|Armazena o nome do CreatorMap.|  
  
## Hierarquia de Herança  
 `CreatorMap`  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)