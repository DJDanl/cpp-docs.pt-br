---
title: "Classe de CAtlModuleT | Microsoft Docs"
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
  - "ATL::CAtlModuleT<T>"
  - "ATL.CAtlModuleT"
  - "ATL.CAtlModuleT<T>"
  - "ATL::CAtlModuleT"
  - "CAtlModuleT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlModuleT"
ms.assetid: 9b74d02f-9117-47b1-a05e-c5945f83dd2b
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlModuleT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa um módulo de ATL.  
  
## Sintaxe  
  
```  
  
      template <  
   class T   
>   
class ATL_NO_VTABLE CAtlModuleT :  
   public CAtlModule  
```  
  
#### Parâmetros  
 `T`  
 A classe derivada de `CAtlModuleT`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlModuleT::CAtlModuleT](../Topic/CAtlModuleT::CAtlModuleT.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlModuleT::InitLibId](../Topic/CAtlModuleT::InitLibId.md)|Inicializa o membro de dados que contém o módulo atual.|  
|[CAtlModuleT::RegisterAppId](../Topic/CAtlModuleT::RegisterAppId.md)|Adiciona EXE no Registro.|  
|[CAtlModuleT::RegisterServer](../Topic/CAtlModuleT::RegisterServer.md)|Adiciona o serviço para o Registro.|  
|[CAtlModuleT::UnregisterAppId](../Topic/CAtlModuleT::UnregisterAppId.md)|Remove EXE do Registro.|  
|[CAtlModuleT::UnregisterServer](../Topic/CAtlModuleT::UnregisterServer.md)|Remove o serviço do Registro.|  
|[CAtlModuleT::UpdateRegistryAppId](../Topic/CAtlModuleT::UpdateRegistryAppId.md)|Atualiza informações de EXE no Registro.|  
  
## Comentários  
 `CAtlModuleT`, derivado de [CAtlModule](../../atl/reference/catlmodule-class.md), implementa um arquivo executável \(EXE\) ou um módulo de serviço ATL \(EXE\).  Um módulo executável é um local, servidor fora de processo, enquanto um módulo de serviço é um aplicativo do Windows que é executado em segundo plano quando o início.  
  
 `CAtlModuleT` fornece suporte para inicializar, e unregistering registrar o módulo.  
  
## Hierarquia de herança  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 `CAtlModuleT`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de CAtlModule](../../atl/reference/catlmodule-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../Topic/ATL%20Module%20Classes.md)