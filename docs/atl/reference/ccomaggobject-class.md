---
title: "Classe de CComAggObject | Microsoft Docs"
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
  - "ATL::CComAggObject<contained>"
  - "ATL.CComAggObject"
  - "ATL.CComAggObject<contained>"
  - "CComAggObject"
  - "ATL::CComAggObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos agregados [C++], em ATL"
  - "agregação [C++], objetos ATL"
  - "Classe de CComAggObject"
ms.assetid: 7aa90d69-d399-477b-880d-e2cdf0ef7881
caps.latest.revision: 29
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComAggObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa a interface de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para um objeto agregado.  Por definição, um objeto agregado estiver contido em um objeto externo.  A classe de `CComAggObject` é semelhante a [Classe de CComObject](../../atl/reference/ccomobject-class.md), exceto que expõe uma interface que seja acessível diretamente aos clientes externos.  
  
## Sintaxe  
  
```  
  
      template<  
   class contained  
>  
class CComAggObject :  
   public IUnknown, public CComObjectRootEx  
   < contained::_ThreadModel::ThreadModelNoCS >  
```  
  
#### Parâmetros  
 `contained`  
 Seus derivados da classe, [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como quaisquer outras interfaces você deseja oferecer suporte no objeto.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComAggObject::CComAggObject](../Topic/CComAggObject::CComAggObject.md)|o construtor.|  
|[CComAggObject::~CComAggObject](../Topic/CComAggObject::~CComAggObject.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComAggObject::AddRef](../Topic/CComAggObject::AddRef.md)|Sai contagem de referência no objeto agregado.|  
|[CComAggObject::CreateInstance](../Topic/CComAggObject::CreateInstance.md)|Essa função estática permite que você crie um novo objeto de **CComAggObject\<** `contained`**\>** sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).|  
|[CComAggObject::FinalConstruct](../Topic/CComAggObject::FinalConstruct.md)|Executa a inicialização final de `m_contained`.|  
|[CComAggObject::FinalRelease](../Topic/CComAggObject::FinalRelease.md)|Executa a destruição final de `m_contained`.|  
|[CComAggObject::QueryInterface](../Topic/CComAggObject::QueryInterface.md)|Recupera um ponteiro para a interface solicitada.|  
|[CComAggObject::Release](../Topic/CComAggObject::Release.md)|Diminui a contagem de referência no objeto agregado.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComAggObject::m\_contained](../Topic/CComAggObject::m_contained.md)|Chamadas de `IUnknown` dos representantes para desconhecido externo.|  
  
## Comentários  
 Implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) de`CComAggObject` para um objeto agregado.  `CComAggObject` tem sua própria interface de **IUnknown** , separado de interface de **IUnknown** do objeto externo, e mantém sua própria contagem de referência.  
  
 Para obter mais informações sobre a agregação, consulte o artigo [fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md).  
  
## Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IUnknown`  
  
 `CComAggObject`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe de CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [DECLARE\_AGGREGATABLE](../Topic/DECLARE_AGGREGATABLE.md)   
 [DECLARE\_ONLY\_AGGREGATABLE](../Topic/DECLARE_ONLY_AGGREGATABLE.md)   
 [DECLARE\_NOT\_AGGREGATABLE](../Topic/DECLARE_NOT_AGGREGATABLE.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)