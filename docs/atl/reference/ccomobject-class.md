---
title: "Classe de CComObject | Microsoft Docs"
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
  - "ATL.CComObject<Base>"
  - "ATL::CComObject"
  - "ATL::CComObject<Base>"
  - "ATL.CComObject"
  - "CComObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComObject"
ms.assetid: e2b6433b-6349-4749-b4bc-acbd7a22c8b0
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** para um objeto nonaggregated.  
  
## Sintaxe  
  
```  
  
      template<  
   class Base   
>  
class CComObject :  
   public Base  
```  
  
#### Parâmetros  
 `Base`  
 Seus derivados da classe, [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como quaisquer outras interfaces você deseja oferecer suporte no objeto.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComObject::CComObject](../Topic/CComObject::CComObject.md)|o construtor.|  
|[CComObject::~CComObject](../Topic/CComObject::~CComObject.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComObject::AddRef](../Topic/CComObject::AddRef.md)|Sai contagem de referência no objeto.|  
|[CComObject::CreateInstance](../Topic/CComObject::CreateInstance.md)|\(Static\) Cria um novo objeto de `CComObject` .|  
|[CComObject::QueryInterface](../Topic/CComObject::QueryInterface.md)|Recupera um ponteiro para a interface solicitada.|  
|[CComObject::Release](../Topic/CComObject::Release.md)|Diminui a contagem de referência no objeto.|  
  
## Comentários  
 Implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) de`CComObject` para um objeto nonaggregated.  Em o entanto, chamadas a `QueryInterface`, a `AddRef`, e a **Versão** delegados são a `CComObjectRootEx`.  
  
 Para obter mais informações sobre como usar `CComObject`, consulte o artigo [fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md).  
  
## Hierarquia de herança  
 `Base`  
  
 `CComObject`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe de CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [DECLARE\_AGGREGATABLE](../Topic/DECLARE_AGGREGATABLE.md)   
 [DECLARE\_NOT\_AGGREGATABLE](../Topic/DECLARE_NOT_AGGREGATABLE.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)