---
title: "Classe de IServiceProviderImpl | Microsoft Docs"
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
  - "ATL::IServiceProviderImpl<T>"
  - "ATL.IServiceProviderImpl<T>"
  - "ATL.IServiceProviderImpl"
  - "ATL::IServiceProviderImpl"
  - "IServiceProviderImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de IServiceProvider, Implementação de ATL"
  - "Classe de IServiceProviderImpl"
ms.assetid: 251254d3-c4ce-40d7-aee0-3d676d1d72f2
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IServiceProviderImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece uma implementação padrão de interface de `IServiceProvider` .  
  
## Sintaxe  
  
```  
  
      template <  
   class T  
>   
class ATL_NO_VTABLE IServiceProviderImpl :  
   public IServiceProvider  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IServiceProviderImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IServiceProviderImpl::QueryService](../Topic/IServiceProviderImpl::QueryService.md)|Cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.|  
  
## Comentários  
 A interface de `IServiceProvider` localiza um serviço especificado pelo GUID e retorna o ponteiro de interface para a interface solicitada no serviço.  A classe `IServiceProviderImpl` fornece uma implementação padrão de esta interface.  
  
 **IServiceProviderImpl** especifica um método: [QueryService](../Topic/IServiceProviderImpl::QueryService.md), que cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.  
  
 `IServiceProviderImpl` usa um mapa de serviço, começando com [BEGIN\_SERVICE\_MAP](../Topic/BEGIN_SERVICE_MAP.md) e finalizando com [END\_SERVICE\_MAP](../Topic/END_SERVICE_MAP.md).  
  
 O mapeamento de serviço contém duas entradas: [SERVICE\_ENTRY](../Topic/SERVICE_ENTRY.md), que indica a identificação de serviço \(SID\) especificada suportado pelo objeto, e [SERVICE\_ENTRY\_CHAIN](../Topic/SERVICE_ENTRY_CHAIN.md), que chama `QueryService` encadear a outro objeto.  
  
## Hierarquia de herança  
 `IServiceProvider`  
  
 `IServiceProviderImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)