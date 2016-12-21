---
title: "Classe de CAtlAutoThreadModule | Microsoft Docs"
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
  - "ATL.CAtlAutoThreadModule"
  - "CAtlAutoThreadModule"
  - "ATL::CAtlAutoThreadModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlAutoThreadModule"
ms.assetid: 3be834aa-55ef-403e-94ae-41979691b15f
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlAutoThreadModule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa com agrupados, o servidor de apartamento\- COM o modelo.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      class CAtlAutoThreadModule :  
public CAtlAutoThreadModuleT< CAtlAutoThreadModule >  
```  
  
## Comentários  
 `CAtlAutoThreadModule` deriva de [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md) e implementa\-se com agrupados, o servidor de apartamento\- COM o modelo.  `CAtlAutoThreadModule` usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um compartimento para cada segmento no módulo.  
  
 Você deve usar a macro de [DECLARE\_CLASSFACTORY\_AUTO\_THREAD](../Topic/DECLARE_CLASSFACTORY_AUTO_THREAD.md) em sua definição de classe de objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como o factory da classe.  Você deve adicionar uma única instância de uma classe derivada de `CAtlAutoThreadModuleT` como `CAtlAutoThreadModule`.  Por exemplo:  
  
 `CAtlAutoThreadModule _AtlAutoModule; // name is immaterial.`  
  
> [!NOTE]
>  Esta classe substitui a classe obsoleta de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) .  
  
## Hierarquia de herança  
 `IAtlAutoThreadModule`  
  
 [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)  
  
 `CAtlAutoThreadModule`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)   
 [Classe de IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../Topic/ATL%20Module%20Classes.md)