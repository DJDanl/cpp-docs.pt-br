---
title: "Implementando CComObject, CComAggObject, e CComPolyObject | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CComPolyObject"
  - "CComAggObject"
  - "CComObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComAggObject"
  - "Classe de CComObject, implementando"
  - "Classe de CComPolyObject, implementando"
  - "Método de CreateInstance"
ms.assetid: 5aabe938-104d-492e-9c41-9f7fb1c62098
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando CComObject, CComAggObject, e CComPolyObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O modelo classe [CComObject](../atl/reference/ccomobject-class.md), [CComAggObject](../atl/reference/ccomaggobject-class.md), e [CComPolyObject](../atl/reference/ccompolyobject-class.md) sempre é a maioria das classes derivadas na cadeia de herança.  É de sua responsabilidade manipular todos os métodos em **IUnknown**: `QueryInterface`, `AddRef`, e **Versão**.  Além de isso, `CComAggObject` e `CComPolyObject` \(quando usado para objetos agregados\) fornecem contagem de referência e semântica especiais de `QueryInterface` necessárias para o desconhecido interno.  
  
 Se `CComObject`, `CComAggObject`, ou `CComPolyObject` são usados depende se você não declarar um \(ou qualquer macros\) dos seguintes:  
  
|Macro|Efeito|  
|-----------|------------|  
|`DECLARE_NOT_AGGREGATABLE`|Sempre use `CComObject`.|  
|`DECLARE_AGGREGATABLE`|Usa `CComAggObject` se o objeto é agregado e `CComObject` se não é.  `CComCoClass` contém esse macro se nenhum dos macros de **DECLARE\_\*\_AGGREGATABLE** são declarados em sua classe, isso será o padrão.|  
|`DECLARE_ONLY_AGGREGATABLE`|Sempre use `CComAggObject`.  Retorna um erro se o objeto não é agregado.|  
|`DECLARE_POLY_AGGREGATABLE`|ATL cria uma instância de **CComPolyObject\<CYourClass\>** quando **IClassFactory::CreateInstance** é chamado.  Durante a criação, o valor de desconhecido externo é verificado.  Se é **NULO**, **IUnknown** é implementado para um objeto nonaggregated.  Se o não externo não é **NULO**, **IUnknown** é implementado para um objeto agregado.|  
  
 A vantagem de usar `CComAggObject` e `CComObject` é a implementação de **IUnknown** é otimizado para o tipo de objeto que está sendo criado.  Por exemplo, um objeto nonaggregated precisa apenas uma contagem de referência, quando um objeto agregado necessário uma contagem de referência para o desconhecido interno e um ponteiro para o desconhecido externo.  
  
 A vantagem de usar `CComPolyObject` é que você evita ter `CComAggObject` e `CComObject` em seu módulo para manipular o caso agregados e nonaggregated.  Identificadores únicos de objeto de `CComPolyObject` ambos os casos.  Isso significa que apenas uma cópia de vtable e uma cópia das funções existem no seu módulo.  Se seu vtable é grande, isso pode reduzir significativamente o tamanho do módulo.  Em o entanto, se seu vtable é pequeno, usar `CComPolyObject` pode resultar em um tamanho maior um pouco de módulo porque não é otimizado para um objeto agregado ou nonaggregated, como é `CComAggObject` e `CComObject`.  
  
## Consulte também  
 [Fundamentos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)   
 [Macros de fábrica de distribuição e uma classe](../atl/reference/aggregation-and-class-factory-macros.md)