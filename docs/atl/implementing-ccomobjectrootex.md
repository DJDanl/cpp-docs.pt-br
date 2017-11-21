---
title: Implementando CComObjectRootEx | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CComObjectRootEx
dev_langs: C++
helpviewer_keywords:
- CComObjectRoot class, implementing
- CComObjectRootEx class
ms.assetid: 79630c44-f2df-4e9e-b730-400a0ebfbd2b
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 960f7989d3891be4cf23ef75b0982a2577f5e95e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="implementing-ccomobjectrootex"></a>Implementando CComObjectRootEx
[CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) é essencial; todos os objetos ATL devem ter uma instância de `CComObjectRootEx` ou [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) em seu herança. `CComObjectRootEx` fornece o mecanismo padrão `QueryInterface` com base em entradas de mapa COM.  
  
 Por meio de seu mapa COM, interfaces de um objeto são expostas a um cliente quando o cliente consulta uma interface. A consulta é realizada pelo `CComObjectRootEx::InternalQueryInterface`. `InternalQueryInterface` somente lida com interfaces na tabela de mapa COM.  
  
 Você pode inserir interfaces na tabela de mapa COM o [COM_INTERFACE_ENTRY](reference/com-interface-entry-macros.md#com_interface_entry) macro ou uma de suas variantes. Por exemplo, o código a seguir insere as interfaces `IDispatch`, `IBeeper` e `ISupportErrorInfo` na tabela de mapa COM:  
  
 [!code-cpp[NVC_ATL_COM#1](../atl/codesnippet/cpp/implementing-ccomobjectrootex_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos básicos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)   
 [Macros de mapa COM](../atl/reference/com-map-macros.md)

