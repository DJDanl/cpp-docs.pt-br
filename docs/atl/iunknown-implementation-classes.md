---
title: Classes de implementação de IUnknown (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- vc.atl.Iunknown
dev_langs:
- C++
helpviewer_keywords:
- IUnknown implementation classes
ms.assetid: 47b69bb5-69d8-4a9c-84a8-329bdde2bb3f
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 53d5363f6b11904e31ea0e9c6f452b2c8fa7e000
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="iunknown-implementation-classes"></a>Classes de implementação de IUnknown
As classes a seguir implementam **IUnknown** e métodos relacionados:  
  
-   [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) gerencia objetos agregados e agregados de contagem de referência. Permite que você especifique um modelo de threading.  
  
-   [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) gerencia objetos agregados e agregados de contagem de referência. Usa o padrão de threading de modelo do servidor.  
  
-   [CComAggObject](../atl/reference/ccomaggobject-class.md) implementa **IUnknown** para um objeto agregado.  
  
-   [CComObject](../atl/reference/ccomobject-class.md) implementa **IUnknown** para um objeto agregado.  
  
-   [CComPolyObject](../atl/reference/ccompolyobject-class.md) implementa **IUnknown** para objetos agregados e agregados. Usando `CComPolyObject` evita ter dois `CComAggObject` e `CComObject` em seu módulo. Um único `CComPolyObject` casos agregados e agregados alças do objeto.  
  
-   [CComObjectNoLock](../atl/reference/ccomobjectnolock-class.md) implementa **IUnknown** para um objeto agregado, sem modificar o número de bloqueios do módulo.  
  
-   [CComTearOffObject](../atl/reference/ccomtearoffobject-class.md) implementa **IUnknown** para uma interface destacável.  
  
-   [CComCachedTearOffObject](../atl/reference/ccomcachedtearoffobject-class.md) implementa **IUnknown** para uma interface destacável "cache".  
  
-   [CComContainedObject](../atl/reference/ccomcontainedobject-class.md) implementa **IUnknown** para o objeto interno de uma agregação ou uma interface destacável.  
  
-   [CComObjectGlobal](../atl/reference/ccomobjectglobal-class.md) gerencia uma contagem de referência no módulo para garantir que o objeto não será excluída.  
  
-   [CComObjectStack](../atl/reference/ccomobjectstack-class.md) cria um objeto COM temporária, usando uma implementação esqueleto de **IUnknown**.  
  
## <a name="related-articles"></a>Artigos relacionados  
 [Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../atl/atl-class-overview.md)   
 [Macros de fábrica de classe e de agregação](../atl/reference/aggregation-and-class-factory-macros.md)   
 [Macros de mapa COM](../atl/reference/com-map-macros.md)   
 [Funções globais de mapa COM](../atl/reference/com-map-global-functions.md)

