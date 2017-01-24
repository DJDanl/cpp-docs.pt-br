---
title: "Classe de CAtlComModule | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL.CAtlComModule"
  - "CAtlComModule"
  - "ATL::CAtlComModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlComModule"
ms.assetid: af5dd71a-a0d1-4a2e-9a24-154a03381c75
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlComModule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa um módulo de servidor COM.  
  
## Sintaxe  
  
```  
  
   class CAtlComModule :  
public _ATL_COM_MODULE  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlComModule::CAtlComModule](../Topic/CAtlComModule::CAtlComModule.md)|o construtor.|  
|[CAtlComModule::~CAtlComModule](../Topic/CAtlComModule::~CAtlComModule.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlComModule::RegisterServer](../Topic/CAtlComModule::RegisterServer.md)|Chamar esse método para atualizar o Registro do sistema para cada objeto no mapa do objeto.|  
|[CAtlComModule::RegisterTypeLib](../Topic/CAtlComModule::RegisterTypeLib.md)|Chamar esse método para registrar uma biblioteca de tipo.|  
|[CAtlComModule::UnregisterServer](../Topic/CAtlComModule::UnregisterServer.md)|Chamar esse método para unregister cada objeto no mapa do objeto.|  
|[CAtlComModule::UnRegisterTypeLib](../Topic/CAtlComModule::UnRegisterTypeLib.md)|Chamar esse método para unregister uma biblioteca de tipo.|  
  
## Comentários  
 `CAtlComModule` implementa um módulo de servidor COM, permitindo que um cliente acessar os componentes do módulo.  
  
 Esta classe substitui a classe obsoleta de [CComModule](../../atl/reference/ccommodule-class.md) usado em versões anteriores de ATL.  Consulte [Classes de módulo de ATL](../Topic/ATL%20Module%20Classes.md) para obter mais detalhes.  
  
## Hierarquia de herança  
 [\_ATL\_COM\_MODULE](../Topic/_ATL_COM_MODULE.md)  
  
 `CAtlComModule`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [\_ATL\_COM\_MODULE](../Topic/_ATL_COM_MODULE.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)