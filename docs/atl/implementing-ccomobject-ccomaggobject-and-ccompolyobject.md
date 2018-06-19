---
title: Implementação de CComObject, CComAggObject e CComPolyObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- CComPolyObject
- CComAggObject
- CComObject
dev_langs:
- C++
helpviewer_keywords:
- CComPolyObject class, implementing
- CreateInstance method
- CComAggObject class
- CComObject class, implementing
ms.assetid: 5aabe938-104d-492e-9c41-9f7fb1c62098
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5ac45a6edbe606ba445ed3ae58cfde348f83e4de
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356335"
---
# <a name="implementing-ccomobject-ccomaggobject-and-ccompolyobject"></a>Implementação de CComObject, CComAggObject e CComPolyObject
As classes de modelo [CComObject](../atl/reference/ccomobject-class.md), [CComAggObject](../atl/reference/ccomaggobject-class.md), e [CComPolyObject](../atl/reference/ccompolyobject-class.md) sempre são as classes derivadas mais na cadeia de herança. É sua responsabilidade de lidar com todos os métodos no **IUnknown**: `QueryInterface`, `AddRef`, e **versão**. Além disso, `CComAggObject` e `CComPolyObject` (quando usado para objetos agregados) fornece a contagem de referência especial e `QueryInterface` semântica necessária para o desconhecido interno.  
  
 Se `CComObject`, `CComAggObject`, ou `CComPolyObject` é usado depende se você declarar uma (ou nenhuma) de macros a seguir:  
  
|Macro|Efeito|  
|-----------|------------|  
|`DECLARE_NOT_AGGREGATABLE`|Sempre usa `CComObject`.|  
|`DECLARE_AGGREGATABLE`|Usa `CComAggObject` se o objeto é agregado e `CComObject` se não for. `CComCoClass` contém essa macro se nenhuma a **DECLARE_\*_AGGREGATABLE** macros são declarados em sua classe, esse será o padrão.|  
|`DECLARE_ONLY_AGGREGATABLE`|Sempre usa `CComAggObject`. Retorna um erro se o objeto não é agregado.|  
|`DECLARE_POLY_AGGREGATABLE`|ATL cria uma instância de **CComPolyObject\<CYourClass >** quando **IClassFactory** é chamado. Durante a criação, o valor do desconhecido externo é verificado. Se for **nulo**, **IUnknown** é implementada por um objeto agregado. Se o desconhecido externo não é **nulo**, **IUnknown** é implementada por um objeto agregado.|  
  
 A vantagem de usar `CComAggObject` e `CComObject` é que a implementação do **IUnknown** é otimizado para o tipo de objeto que está sendo criado. Por exemplo, um objeto agregado precisa apenas de uma contagem de referência, enquanto um objeto agregado precisa de uma contagem de referência interna desconhecido e um ponteiro para a externa desconhecida.  
  
 A vantagem de usar `CComPolyObject` é evitar ter dois `CComAggObject` e `CComObject` em seu módulo para lidar com casos agregados e agregados. Um único `CComPolyObject` objeto lida com ambos os casos. Isso significa que apenas uma cópia do vtable e uma cópia das funções existem em seu módulo. Se seu vtable for grande, isso pode diminuir significativamente o tamanho do módulo. No entanto, se seu vtable for pequeno, usando `CComPolyObject` pode resultar em um tamanho ligeiramente maior do módulo porque ele não é otimizado para um objeto agregado ou agregado, assim como `CComAggObject` e `CComObject`.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos básicos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)   
 [Macros de fábrica de classes e agregação](../atl/reference/aggregation-and-class-factory-macros.md)

