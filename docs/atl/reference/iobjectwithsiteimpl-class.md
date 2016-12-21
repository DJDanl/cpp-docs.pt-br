---
title: "Classe de IObjectWithSiteImpl | Microsoft Docs"
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
  - "ATL::IObjectWithSiteImpl"
  - "ATL.IObjectWithSiteImpl<T>"
  - "IObjectWithSiteImpl"
  - "ATL.IObjectWithSiteImpl"
  - "ATL::IObjectWithSiteImpl<T>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IObjectWithSiteImpl"
ms.assetid: 4e1f774f-bc3d-45ee-9a1c-c3533a511588
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IObjectWithSiteImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos permitindo que um objeto se comunicar com seu site.  
  
## Sintaxe  
  
```  
  
      template<  
   class T   
>  
class ATL_NO_VTABLE IObjectWithSiteImpl :  
   public IObjectWithSite  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IObjectWithSiteImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IObjectWithSiteImpl::GetSite](../Topic/IObjectWithSiteImpl::GetSite.md)|A consulta site para um ponteiro da interface.|  
|[IObjectWithSiteImpl::SetChildSite](../Topic/IObjectWithSiteImpl::SetChildSite.md)|Fornece o objeto com o ponteiro de **IUnknown** do site.|  
|[IObjectWithSiteImpl::SetSite](../Topic/IObjectWithSiteImpl::SetSite.md)|Fornece o objeto com o ponteiro de **IUnknown** do site.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[IObjectWithSiteImpl::m\_spUnkSite](../Topic/IObjectWithSiteImpl::m_spUnkSite.md)|Gerencia o ponteiro de **IUnknown** do site.|  
  
## Comentários  
 A interface de [IObjectWithSite](http://msdn.microsoft.com/library/windows/desktop/ms693765) permite que um objeto se comunicar com seu site.  A classe `IObjectWithSiteImpl` fornece uma implementação padrão de esta interface e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 `IObjectWithSiteImpl` especifica dois métodos.  Chamadas de cliente `SetSite`primeiro, passando o ponteiro de **IUnknown** do site.  Esse ponteiro é armazenado no objeto, e posteriormente pode ser recuperado com uma chamada a `GetSite`.  
  
 Normalmente, você derivado da classe de `IObjectWithSiteImpl` quando você estiver criando um objeto que não é um controle.  Para controles, derive da classe [IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md), que também fornece um ponteiro de site.  Não derivam da classe de `IObjectWithSiteImpl` e de `IOleObjectImpl`.  
  
## Hierarquia de herança  
 `IObjectWithSite`  
  
 `IObjectWithSiteImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)