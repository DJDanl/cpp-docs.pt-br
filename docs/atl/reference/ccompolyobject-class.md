---
title: "Classe de CComPolyObject | Microsoft Docs"
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
  - "CComPolyObject"
  - "ATL.CComPolyObject<contained>"
  - "ATL::CComPolyObject"
  - "ATL::CComPolyObject<contained>"
  - "ATL.CComPolyObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos agregados [C++], em ATL"
  - "agregação [C++], objetos ATL"
  - "Classe de CComPolyObject"
ms.assetid: eaf67c18-e855-48ca-9b15-f1df3106121b
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComPolyObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** para um objeto agregado ou nonaggregated.  
  
## Sintaxe  
  
```  
  
      template<  
   class contained   
>  
class CComPolyObject : public IUnknown, public CComObjectRootEx  
   < contained::_ThreadModel::ThreadModelNoCS >  
```  
  
#### Parâmetros  
 `contained`  
 Seus derivados da classe, [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como quaisquer outras interfaces você deseja oferecer suporte no objeto.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPolyObject::CComPolyObject](../Topic/CComPolyObject::CComPolyObject.md)|o construtor.|  
|[CComPolyObject::~CComPolyObject](../Topic/CComPolyObject::~CComPolyObject.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPolyObject::AddRef](../Topic/CComPolyObject::AddRef.md)|Sai contagem de referência de objeto.|  
|[CComPolyObject::CreateInstance](../Topic/CComPolyObject::CreateInstance.md)|\(Static\) Permite que você crie um novo objeto de **CComPolyObject\<** `contained`**\>** sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).|  
|[CComPolyObject::FinalConstruct](../Topic/CComPolyObject::FinalConstruct.md)|Executa a inicialização final de `m_contained`.|  
|[CComPolyObject::FinalRelease](../Topic/CComPolyObject::FinalRelease.md)|Executa a destruição final de `m_contained`.|  
|[CComPolyObject::QueryInterface](../Topic/CComPolyObject::QueryInterface.md)|Recupera um ponteiro para a interface solicitada.|  
|[CComPolyObject::Release](../Topic/CComPolyObject::Release.md)|Diminui a contagem de referência de objeto.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPolyObject::m\_contained](../Topic/CComPolyObject::m_contained.md)|Chamadas de **IUnknown** dos representantes para desconhecido externo se o objeto é agregado ou a **IUnknown** de objeto se o objeto não é agregado.|  
  
## Comentários  
 Implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) de`CComPolyObject` para um objeto agregado ou nonaggregated.  
  
 Quando uma instância de `CComPolyObject` é criada, o valor de desconhecido externo é verificado.  Se é **NULO**, **IUnknown** é implementado para um objeto nonaggregated.  Se o não externo não é **NULO**, **IUnknown** é implementado para um objeto agregado.  
  
 A vantagem de usar `CComPolyObject` é que você evita ter [CComAggObject](../../atl/reference/ccomaggobject-class.md) e [CComObject](../../atl/reference/ccomobject-class.md) em seu módulo para manipular o caso agregados e nonaggregated.  Identificadores únicos de objeto de `CComPolyObject` ambos os casos.  Isso significa que apenas uma cópia de vtable e uma cópia das funções existem no seu módulo.  Se seu vtable é grande, isso pode reduzir significativamente o tamanho do módulo.  Em o entanto, se seu vtable é pequeno, usar `CComPolyObject` pode resultar em um tamanho maior um pouco de módulo porque não é otimizado para um objeto agregado ou nonaggregated, como é `CComAggObject` e `CComObject`.  
  
 Se a macro de `DECLARE_POLY_AGGREGATABLE` é especificado na definição de classe de objeto, `CComPolyObject` será usado para criar seu objeto.  `DECLARE_POLY_AGGREGATABLE` será declarado automaticamente se você usar o assistente de projeto de ATL para criar um controle total ou um controle da Internet Explorer.  
  
 Se agregado, o objeto de `CComPolyObject` tem seu próprio **IUnknown**, separado de **IUnknown**do objeto externo, e mantém sua própria contagem de referência.  `CComPolyObject` usa [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) para delegar ao desconhecido externo.  
  
 Para obter mais informações sobre a agregação, consulte o artigo [fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md).  
  
## Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IUnknown`  
  
 `CComPolyObject`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [DECLARE\_POLY\_AGGREGATABLE](../Topic/DECLARE_POLY_AGGREGATABLE.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)