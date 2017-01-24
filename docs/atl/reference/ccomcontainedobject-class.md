---
title: "Classe de CComContainedObject | Microsoft Docs"
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
  - "CComContainedObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos agregados [C++], em ATL"
  - "agregação [C++], objetos ATL"
  - "Classe de CComContainedObject"
ms.assetid: e8616b41-c200-47b8-bf2c-fb9f713ebdad
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComContainedObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) delegando a **IUnknown**do objeto do proprietário.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
class Base   
>  
class CComContainedObject :  
public Base  
```  
  
#### Parâmetros  
 `Base`  
 Seus derivados da classe, [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md).  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComContainedObject::CComContainedObject](../Topic/CComContainedObject::CComContainedObject.md)|o construtor.  Inicializa o ponteiro do membro a `IUnknown`do objeto do proprietário.|  
|[CComContainedObject::~CComContainedObject](../Topic/CComContainedObject::~CComContainedObject.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComContainedObject::AddRef](../Topic/CComContainedObject::AddRef.md)|Sai contagem de referência no objeto do proprietário.|  
|[CComContainedObject::GetControllingUnknown](../Topic/CComContainedObject::GetControllingUnknown.md)|Recupera `IUnknown`do objeto do proprietário.|  
|[CComContainedObject::QueryInterface](../Topic/CComContainedObject::QueryInterface.md)|Recupera um ponteiro para a interface solicitada no objeto do proprietário.|  
|[CComContainedObject::Release](../Topic/CComContainedObject::Release.md)|Diminui a contagem de referência no objeto do proprietário.|  
  
## Comentários  
 ATL usa `CComContainedObject` em classes [CComAggObject](../../atl/reference/ccomaggobject-class.md), [CComPolyObject](../../atl/reference/ccompolyobject-class.md), e [CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md).  `CComContainedObject` implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) delegando a **IUnknown**do objeto do proprietário.  \(O proprietário é o objeto externo de uma agregação, ou o objeto para que uma interface de rasgo \- fora está sendo criado.\) `CComContainedObject` chama `OuterQueryInterface`, `OuterAddRef`, e `OuterRelease`de `CComObjectRootEx`, herdado com qualquer `Base`.  
  
## Hierarquia de herança  
 `Base`  
  
 `CComContainedObject`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)