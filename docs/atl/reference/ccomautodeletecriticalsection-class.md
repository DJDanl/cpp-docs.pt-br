---
title: Classe CComAutoDeleteCriticalSection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComAutoDeleteCriticalSection
- atlcore/ATL::CComAutoDeleteCriticalSection
dev_langs: C++
helpviewer_keywords: CComAutoDeleteCriticalSection class
ms.assetid: 2396dbea-1c60-4841-b50e-c4e18af311a3
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d073e392030db72d6371a798875daf3d7a90e247
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ccomautodeletecriticalsection-class"></a>Classe CComAutoDeleteCriticalSection
Essa classe fornece métodos para a obtenção e liberar a propriedade de um objeto de seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComAutoDeleteCriticalSection : public CComSafeDeleteCriticalSection
```  
  
## <a name="remarks"></a>Comentários  
 `CComAutoDeleteCriticalSection`deriva da classe [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md). No entanto, `CComAutoDeleteCriticalSection` substitui o [termo](ccomsafedeletecriticalsection-class.md#term) método `private` acesso, o que força a limpeza de memória interna para ocorrer somente quando as instâncias dessa classe Ir fora do escopo ou são excluídas explicitamente da memória.  

  
 Essa classe não introduz nenhuma métodos adicionais em sua classe base. Consulte [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md) e [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) para obter mais informações sobre classes auxiliares de seção crítica.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)  
  
 [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md)  
  
 `CComAutoDeleteCriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md)   
 [Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
